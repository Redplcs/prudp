#include <winsock2.h>
#include <stdio.h>
#include <tchar.h>
#include <Platform/ScopedCS.h>
#include <Platform/SystemCheck.h>
#include <Platform/SystemError.h>
#include <Plugins/Transport/Interface/OutputEmulationDevice.h>
#include <Plugins/Transport/Interface/InputEmulationDevice.h>
#include <Plugins/Transport/Interface/TransportEventHandler.h>
#include "PRUDPTransport.h"
#include "PacketIn.h"
#include "RTT.h"

static unsigned long HandleTimeSliceWrap(unsigned long ulParam1, unsigned long ulParam2)
{
	((PRUDPTransport *)ulParam1)->TimeSliceHandler();
	return 0;
}

static unsigned long HandleRecvCompletedWrap(unsigned long ulParam1, unsigned long ulParam2)
{
	PRUDPTransport *pTransport = (PRUDPTransport *)ulParam1;
	pTransport->GetSocket((unsigned char)ulParam2)->CompleteRecv();
	pTransport->DemuxIncomingPacket(ulParam2 & 0xFF);
	return 0;
}

static unsigned long HandleSendCompletedWrap(unsigned long ulParam1, unsigned long ulParam2)
{
	((PRUDPTransport *)ulParam1)->GetSocket((unsigned char)ulParam2)->CompleteSend();
	return 0;
}

static unsigned long HandleICMPCompletedWrap(unsigned long ulParam1, unsigned long ulParam2)
{
	((PRUDPTransport *)ulParam1)->CompleteICMP((ICMPSocket *)ulParam2);
	return 0;
}

PRUDPTransport::PRUDPTransport(Plugin *pPlugin) :
	Transport(pPlugin),
	m_oTimeoutManager(),
	m_csEndPoints(),
	m_csSocket(),
	m_oInterfaceTable(),
	m_csIdleEndPoints(),
	m_oSettings()
{
	m_bInitialized = false;

	for (int i = 0; i < 2; i++)
	{
		m_apSocket[i] = NULL;
		m_apRecvEvent[i] = NULL;
		m_apSendEvent[i] = NULL;
		m_apICMPSocket[i] = NULL;
		m_apICMPEvent[i] = NULL;
	}

	m_pCallbackDispatcher = NULL;
}

PRUDPTransport::~PRUDPTransport()
{
	TRACE(0, _T("Deleting PRUDPTransport %x"), this);
	TRACE(0, _T("Stopping CallbackDispatcher in ~PRUDPTransport %x"), this);

	if (m_pCallbackDispatcher != NULL)
	{
		if (!m_pCallbackDispatcher->Stop(5000))
			SystemError::TraceLast(1);
	}

	StopICMPListen(0);
	StopICMPListen(1);
	StopUDPListen(0);
	StopUDPListen(1);

	std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.begin();
	while (it != m_mapEndPoints.end())
	{
		PRUDPEndPoint *pEndPoint = it->second;
		if (pEndPoint != NULL)
		{
			delete pEndPoint;
		}
		++it;
	}

	{
		ScopedCS lock(m_csIdleEndPoints);

		while (m_lstIdleEndPoints.size() != 0)
		{
			PRUDPEndPoint *pEndPoint = m_lstIdleEndPoints.front();
			if (pEndPoint != NULL)
			{
				delete pEndPoint;
			}
			m_lstIdleEndPoints.pop_front();
		}
	}

	if (m_pCallbackDispatcher != NULL)
	{
		delete m_pCallbackDispatcher;
	}

	WSACleanup();
}

bool PRUDPTransport::ResponsibleForURL(StationURL *pURL)
{
	TCHAR szType[0x80];
	pURL->GetTransportType(szType, 0x80);
	return _tcsicmp(szType, _T("prudp")) == 0;
}

TCHAR *PRUDPTransport::GetType()
{
	return _T("prudp");
}

unsigned long PRUDPTransport::Initialize()
{
	WSADATA wsaData;

	unsigned long ulResult = Transport::Initialize();
	if (ulResult != 0)
		return ulResult;

	if (WSAStartup(0x0202, &wsaData) == -1)
	{
		WSACleanup();
		return 2;
	}

	TRACE(0, _T("RUNNING WITH WINSOCK %x,%x, MaxSockets=%x"), wsaData.wVersion & 0xFFFF, wsaData.wHighVersion & 0xFFFF, wsaData.iMaxSockets & 0xFFFF);

	if (m_oInterfaceTable.Query())
		return 0;

	return 0x16;
}

unsigned long PRUDPTransport::ListenOnWellKnown()
{
	TRACE(0x6000000, _T("PRUDPTransport::ListenOnWellKnown(%x)"), this);

	if (m_oInterfaceTable.GetNbInterface() == 0)
	{
		TRACE(0x6000000, _T("PRUDPTransport::ListenOnWellKnown() not initialized"));
		return 0x16;
	}

	StartEventListener();

	unsigned short usPort = (unsigned short)GetSettings()->GetWellKnownPortNumber();
	if (!UDPListen(0, usPort))
	{
		TRACE(0x6000000, _T("PRUDPTransport::ListenOnWellKnown() failed"));
		return 3;
	}

	TRACE(0x6000000, _T("PRUDPTransport Listening on static port %d"), m_apAddress[0].GetPort() & 0xFFFF);

	return 0;
}

unsigned long PRUDPTransport::ListenOnArbitrary()
{
	TRACE(0x6000000, _T("PRUDPTransport::ListenOnArbitrary(%x)"), this);

	if (m_oInterfaceTable.GetNbInterface() == 0)
	{
		TRACE(0x6000000, _T("PRUDPTransport::ListenOnWellKnown() not initialized"));
		return 0x16;
	}

	StartEventListener();

	if (!UDPListen(1, 0))
	{
		TRACE(0x6000000, _T("PRUDPTransport::ListenOnWellKnown() failed"));
		return 3;
	}

	TRACE(0x6000000, _T("PRUDPTransport %x Listening on port %d"), this, m_apAddress[1].GetPort() & 0xFFFF);

	return 0;
}

unsigned long PRUDPTransport::StopListenOnWellKnown()
{
	TRACE(0x6000000, _T("PRUDPTransport::StopListenOnWellKnown(%x)"), this);
	return 0;
}

unsigned long PRUDPTransport::StopListenOnArbitrary()
{
	TRACE(0x6000000, _T("PRUDPTransport::StopListenOnArbitrary(%x)"), this);
	return 0;
}

EndPoint *PRUDPTransport::CreateEndPoint()
{
	if (m_apSocket[0] != NULL)
	{
		return new PRUDPEndPoint(this, 0);
	}

	if (m_apSocket[1] != NULL)
	{
		return new PRUDPEndPoint(this, 1);
	}

	return NULL;
}

unsigned long PRUDPTransport::DeleteEndPoint(EndPoint *pEndPoint)
{
	UnregisterEndPoint((PRUDPEndPoint *)pEndPoint);

	{
		ScopedCS lock(m_csIdleEndPoints);
		m_lstIdleEndPoints.push_back((PRUDPEndPoint *)pEndPoint);
	}

	return 0;
}

unsigned long PRUDPTransport::SendBroadcast(Buffer *pBuffer)
{
	UserContext oContext;
	oContext = (unsigned long)0;
	return SendBroadcast(pBuffer, NULL, oContext);
}

unsigned long PRUDPTransport::SendBroadcast(Buffer *pBuffer, const Transport::Callback pfCallback, const UserContext &refContext)
{
	TCHAR szURL[0x100];

	TRACE(0x6000000, _T("PRUDPTransport::SendBroadcast(%d)"), pBuffer->GetContentSize());

	_stprintf(szURL, _T("%s%s"), _T("prudp"), _T(":/"));

	for (unsigned long i = 0; i < m_oInterfaceTable.GetNbInterface(); i++)
	{
		if ((m_oInterfaceTable[i].GetFlags() & 0x4) && m_oInterfaceTable.GetNbInterface() > 1)
			continue;

		TCHAR szAddr[0x100];
		m_oInterfaceTable[i].GetBroadcastAddress(szAddr, 0x100);

		PRUDPInetAddress oAddr;
		oAddr.SetAddress(szAddr);
		oAddr.SetPortNumber(GetSettings()->GetWellKnownPortNumber());

		StationURL oURL(szURL);
		oAddr.GetURL(&oURL);

		Send(&oURL, pBuffer);
	}

	if (pfCallback != NULL)
	{
		pfCallback(this, pBuffer, 0, (UserContext *)&refContext);
	}

	return 0;
}

unsigned long PRUDPTransport::Send(StationURL *pURL, Buffer *pBuffer)
{
	UserContext oContext;
	oContext = (unsigned long)0;
	return Send(pURL, pBuffer, NULL, oContext);
}

unsigned long PRUDPTransport::Send(StationURL *pURL, Buffer *pBuffer, const Transport::Callback pfCallback, const UserContext &refContext)
{
	TRACE(0x6000000, _T("PRUDPTransport::Send(%s,%d)"), pURL->GetURL(), pBuffer->GetContentSize());

	if (!ResponsibleForURL(pURL))
		return 0xF;

	PRUDPInetAddress oAddress;

	if (!oAddress.SetFromURL(pURL, GetSettings()->GetWellKnownPortNumber()))
		return 0xC;

	if (pBuffer == NULL)
		return 0xA;

	PacketOut *pPacket = new PacketOut(NULL, 4, 0, pBuffer);
	pPacket->SetPeerAddress(&oAddress);

	if (m_apSocket[0] != NULL)
	{
		if (!Send(0, pPacket))
		{
			pPacket->ReleaseRef();
			return 3;
		}
	}
	else if (m_apSocket[1] != NULL)
	{
		if (!Send(1, pPacket))
		{
			pPacket->ReleaseRef();
			return 3;
		}
	}
	else
	{
		pPacket->ReleaseRef();
		return 0x10;
	}

	if (pfCallback != NULL)
	{
		pfCallback(this, pBuffer, 0, (UserContext *)&refContext);
	}

	return 0;
}

unsigned long PRUDPTransport::GetNbLocalURL()
{
	if (m_oInterfaceTable.GetNbInterface() == 0)
		return 0;

	unsigned long ulNbLoopback = m_oInterfaceTable.GetNbLoopbackInterface();
	if (ulNbLoopback == m_oInterfaceTable.GetNbInterface())
		return 1;

	return m_oInterfaceTable.GetNbInterface() - m_oInterfaceTable.GetNbLoopbackInterface();
}

StationURL *PRUDPTransport::GetLocalURL(unsigned long ulIndex)
{
	if (ulIndex >= GetNbLocalURL())
		return NULL;

	TCHAR szURL[0x100];
	TCHAR szAddr[0x100];

	unsigned long ulNbLoopback = m_oInterfaceTable.GetNbLoopbackInterface();
	if (ulNbLoopback == m_oInterfaceTable.GetNbInterface())
	{
		_stprintf(szURL, _T("%s%s"), _T("prudp"), _T(":/"));
		m_oInterfaceTable[0].GetAddress(szAddr, 0x100);
	}
	else
	{
		unsigned long ulActualIndex = ulIndex;
		for (unsigned long i = 0; i < m_oInterfaceTable.GetNbInterface(); i++)
		{
			if (m_oInterfaceTable[i].GetFlags() & 0x4)
				continue;

			if (ulActualIndex == 0)
			{
				_stprintf(szURL, _T("%s%s"), _T("prudp"), _T(":/"));
				m_oInterfaceTable[i].GetAddress(szAddr, 0x100);
				break;
			}
			ulActualIndex--;
		}
	}

	StationURL *pURL = new StationURL(szURL);

	PRUDPInetAddress oAddr;
	oAddr.SetAddress(szAddr);

	if (GetPortNumber(0) != 0)
		oAddr.SetPortNumber(GetPortNumber(0));
	else
		oAddr.SetPortNumber(GetPortNumber(1));

	oAddr.GetURL(pURL);
	pURL->Trace(1);

	return pURL;
}

StationURL *PRUDPTransport::GetIPURL(unsigned long ulAddress, unsigned short usPort)
{
	StationURL *pURL = new StationURL();

	PRUDPInetAddress oAddr;
	oAddr.SetAddress(ulAddress);
	oAddr.SetPortNumber(usPort);
	pURL->SetURL(_T("prudp:/"));

	if (!oAddr.GetURL(pURL))
	{
		delete pURL;
		return NULL;
	}

	pURL->Trace(1);
	return pURL;
}

StationURL *PRUDPTransport::GetIPURL(TCHAR *szAddress, unsigned short usPort)
{
	StationURL *pURL = new StationURL();

	PRUDPInetAddress oAddr;
	if (!oAddr.SetAddress(szAddress))
	{
		delete pURL;
		return NULL;
	}

	oAddr.SetPortNumber(usPort);
	pURL->SetURL(_T("prudp:/"));

	if (!oAddr.GetURL(pURL))
	{
		delete pURL;
		return NULL;
	}

	pURL->Trace(1);
	return pURL;
}

bool PRUDPTransport::GetIPFromURL(StationURL *pURL, unsigned long *pulAddress, unsigned short *pusPort)
{
	PRUDPInetAddress oAddr;

	if (!oAddr.SetFromURL(pURL, GetSettings()->GetWellKnownPortNumber()))
		return false;

	if (pulAddress == NULL)
		return false;

	if (pusPort == NULL)
		return false;

	*pulAddress = oAddr.GetAddress();
	*pusPort = oAddr.GetPort();

	return true;
}

void PRUDPTransport::ReleaseURL(StationURL *pURL)
{
	if (pURL != NULL)
	{
		delete pURL;
	}
}

bool PRUDPTransport::IsCapable(unsigned long ulCapability)
{
	switch (ulCapability)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 6:
	case 7:
		return true;
	default:
		return false;
	}
}

unsigned long PRUDPTransport::SetOption(unsigned long ulOption, UserContext &refContext)
{
	return m_oSettings.SetOption(ulOption, refContext);
}

unsigned long PRUDPTransport::GetOption(unsigned long ulOption, UserContext &refContext)
{
	return m_oSettings.GetOption(ulOption, refContext);
}

void PRUDPTransport::SetHighPrio()
{
	m_pCallbackDispatcher->SetPriority(2);
}

void PRUDPTransport::TraceProto(TCHAR *szLabel, Packet *pPacket, PRUDPInetAddress *pSrcAddress, PRUDPInetAddress *pDstAddress, unsigned long ulSocket)
{
}

unsigned long PRUDPTransport::ConnectEndPoint(EndPoint *pEndPoint, StationURL *pURL, Buffer *pBuffer, const EndPoint::Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout)
{
	if (!ResponsibleForURL(pURL))
		return 0xF;

	return ((PRUDPEndPoint *)pEndPoint)->Connect(pURL, pBuffer, pfCallback, refContext, ulTimeout);
}

unsigned long PRUDPTransport::DisconnectEndPoint(EndPoint *pEndPoint, const EndPoint::Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout)
{
	return ((PRUDPEndPoint *)pEndPoint)->Disconnect(pfCallback, refContext, ulTimeout);
}

unsigned long PRUDPTransport::SendToEndPoint(EndPoint *pEndPoint, Buffer *pBuffer, const EndPoint::Callback pfCallback, const UserContext &refContext, unsigned long ulFlags)
{
	return ((PRUDPEndPoint *)pEndPoint)->Send(pBuffer, pfCallback, refContext, ulFlags);
}

bool PRUDPTransport::IsEndPointConnected(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->IsConnected();
}

bool PRUDPTransport::IsEndPointPeerConnected(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->IsPeerConnected();
}

bool PRUDPTransport::IsEndPointDisconnected(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->IsDisconnected();
}

bool PRUDPTransport::IsEndPointPeerDisconnected(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->IsPeerDisconnected();
}

unsigned long PRUDPTransport::RegisterEndPointEventHandler(EndPoint *pEndPoint, EndPointEventHandler *pHandler)
{
	return pEndPoint->RegisterEventHandler(pHandler);
}

StationURL *PRUDPTransport::GetEndPointStationURL(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->GetStationURL();
}

unsigned long PRUDPTransport::GetEndPointQueueSize(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->GetQueueSize();
}

unsigned long PRUDPTransport::GetEndPointRTT(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->GetRTT()->GetLastRTT();
}

unsigned long PRUDPTransport::GetEndPointRTTAverage(EndPoint *pEndPoint)
{
	return ((PRUDPEndPoint *)pEndPoint)->GetRTT()->GetRTTSmoothedAvg();
}

unsigned long PRUDPTransport::SendToEndPointGroup(EndPointGroup *pGroup, Buffer *pBuffer, const EndPointGroup::Callback *pfCallback, const UserContext &refContext, unsigned long ulFlags)
{
	return 1;
}

void PRUDPTransport::StartEventListener()
{
	if (m_pCallbackDispatcher != NULL)
		return;

	m_pCallbackDispatcher = new CallbackDispatcher((unsigned long)this);

	unsigned long ulTimeSlice = GetSettings()->GetTimeSlice();
	m_pCallbackDispatcher->RegisterTimeSliceCallback(HandleTimeSliceWrap, 0, ulTimeSlice);
}

bool PRUDPTransport::UDPListen(unsigned long ulSocket, unsigned short usPort)
{
	ScopedCS lock(m_csSocket);

	if (m_apSocket[ulSocket] != NULL)
		return true;

	SYSTEMCHECK(m_apSocket[ulSocket] == NULL);

	m_apSocket[ulSocket] = new UDPSocket(this);
	if (!m_apSocket[ulSocket]->Open())
		goto fail;

	m_apAddress[ulSocket].SetPortNumber(usPort);

	{
		unsigned short usBoundPort;
		if (!m_apSocket[ulSocket]->Bind(&m_apAddress[ulSocket], &usBoundPort))
			goto fail;

		if (usBoundPort != 0)
		{
			TRACE(0, _T("Listening on port %d"), usBoundPort & 0xFFFF);

			m_apRecvEvent[ulSocket] = m_pCallbackDispatcher->CreateCallbackEvent(HandleRecvCompletedWrap, ulSocket);
			m_apSendEvent[ulSocket] = m_pCallbackDispatcher->CreateCallbackEvent(HandleSendCompletedWrap, ulSocket);

			m_apSocket[ulSocket]->SetCompletionEvents(m_apRecvEvent[ulSocket], m_apSendEvent[ulSocket]);
			m_apSocket[ulSocket]->Listen();

			if (GetSettings()->IsTrappingICMP())
			{
				GetSettings()->TrapICMP(ICMPListen(ulSocket, usBoundPort));
			}

			return true;
		}

		TRACE(0, _T("Failed Listening on port %d"), usBoundPort & 0xFFFF);
	}

	if (m_apSocket[ulSocket] != NULL)
	{
		delete m_apSocket[ulSocket];
	}
	m_apSocket[ulSocket] = NULL;

fail:
	return false;
}

bool PRUDPTransport::StopUDPListen(unsigned long ulSocket)
{
	if (m_apSocket[ulSocket] == NULL)
		return false;

	m_apSocket[ulSocket]->Close();

	if (m_apRecvEvent[ulSocket] != NULL)
		m_pCallbackDispatcher->DeleteCallbackEvent(m_apRecvEvent[ulSocket]);

	if (m_apSendEvent[ulSocket] != NULL)
		m_pCallbackDispatcher->DeleteCallbackEvent(m_apSendEvent[ulSocket]);

	if (m_apSocket[ulSocket] != NULL)
	{
		delete m_apSocket[ulSocket];
	}
	m_apSocket[ulSocket] = NULL;

	return true;
}

bool PRUDPTransport::ICMPListen(unsigned long ulSocket, unsigned short usPort)
{
	ScopedCS lock(m_csSocket);

	TRACE(0, _T("Trying to listen on port %d"), usPort & 0xFFFF);

	if (m_apICMPSocket[ulSocket] != NULL)
		return true;

	m_apICMPSocket[ulSocket] = new ICMPSocket();

	PRUDPInetAddress oAddr;

	if (!m_apICMPSocket[ulSocket]->Open())
		goto fail;

	if (!m_apICMPSocket[ulSocket]->Bind(&oAddr))
		goto fail;

	m_apICMPEvent[ulSocket] = m_pCallbackDispatcher->CreateCallbackEvent(HandleICMPCompletedWrap, (unsigned long)m_apICMPSocket[ulSocket]);
	m_apICMPSocket[ulSocket]->SetCompletionEvent(m_apICMPEvent[ulSocket]);
	m_apICMPSocket[ulSocket]->QueueRecv();

	TRACE(0x6000000, _T("Listening on ICMP"));

	return true;

fail:
	TRACE(0, _T("Exception raised on creation of ICMP socket"));
	SystemError::TraceLast(0);

	m_apICMPSocket[ulSocket]->Close();

	if (m_apICMPSocket[ulSocket] != NULL)
	{
		delete m_apICMPSocket[ulSocket];
	}
	m_apICMPSocket[ulSocket] = NULL;

	return false;
}

bool PRUDPTransport::StopICMPListen(unsigned long ulSocket)
{
	if (m_apICMPSocket[ulSocket] == NULL)
		return false;

	m_apICMPSocket[ulSocket]->Close();

	if (m_apICMPSocket[ulSocket] != NULL)
	{
		delete m_apICMPSocket[ulSocket];
	}
	m_apICMPSocket[ulSocket] = NULL;

	Event *pEvent = m_apICMPEvent[ulSocket];
	if (pEvent != NULL)
		m_pCallbackDispatcher->DeleteCallbackEvent(pEvent);

	return true;
}

bool PRUDPTransport::RegisterEndPoint(PRUDPEndPoint *pEndPoint)
{
	ScopedCS lock(m_csEndPoints);

	__int64 llKey = pEndPoint->GetPRUDPInetAddress()->GetKey();

	std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.find(llKey);
	if (it != m_mapEndPoints.end() && it->second != NULL)
	{
		TRACE(0x6000000, _T("PRUDPTransport::RegisterEndPoint found existing"));
		return false;
	}

	TRACE(0, _T("The following EndPoint has been added:"));
	pEndPoint->GetPRUDPInetAddress()->Trace(0);

	m_mapEndPoints[pEndPoint->GetPRUDPInetAddress()->GetKey()] = pEndPoint;

	return true;
}

void PRUDPTransport::UnregisterEndPoint(PRUDPEndPoint *pEndPoint)
{
	ScopedCS lock(m_csEndPoints);

	__int64 llKey = pEndPoint->GetPRUDPInetAddress()->GetKey();

	std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.lower_bound(llKey);
	if (it != m_mapEndPoints.end() && !(llKey < it->first))
	{
		m_mapEndPoints.erase(it);
	}
}

void PRUDPTransport::SendReset(unsigned long ulSocket, PRUDPInetAddress *pAddress)
{
	PacketOut *pPacket = new PacketOut(NULL, 6, 0, NULL);
	pPacket->SetType(6);
	pPacket->SetPeerAddress(pAddress);
	Send(ulSocket, pPacket);
	pPacket->ReleaseRef();
}

PRUDPEndPoint *PRUDPTransport::ServiceConnectionRequest(PRUDPInetAddress *pAddress, Buffer *pBuffer, unsigned long ulSocket)
{
	PRUDPEndPoint *pEndPoint = NULL;
	bool bNewEndPoint = false;

	{
		ScopedCS lock(m_csEndPoints);

		__int64 llKey = pAddress->GetKey();

		std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.lower_bound(llKey);
		if (it != m_mapEndPoints.end() && !(llKey < it->first))
		{
			pEndPoint = it->second;
		}

		if (pEndPoint == NULL)
		{
			pEndPoint = new PRUDPEndPoint(this, ulSocket);
			bNewEndPoint = true;
		}
	}

	if (!bNewEndPoint)
		return pEndPoint;

	TCHAR szURL[0x100];
	_stprintf(szURL, _T("%s%s"), _T("prudp"), _T(":/"));

	StationURL oURL(szURL);
	pAddress->GetURL(&oURL);

	pEndPoint->SetPRUDPInetAddress(pAddress);

	TransportEventHandler *pHandler = GetEventHandler();
	if (pHandler == NULL)
		goto accept;

	if (pBuffer->GetContentSize() != 0)
	{
		TRACE(0x6000000, _T("Calling EndPointEventHandler::ConnectionRequest(%s, %d)"), oURL.GetURL(), pBuffer->GetContentSize());
		if (!pHandler->ConnectionRequest(this, &oURL, pBuffer, pEndPoint))
			goto reject;
	}
	else
	{
		TRACE(0x6000000, _T("Calling EndPointEventHandler::ConnectionRequest(%s, 0)"), oURL.GetURL());
		if (!pHandler->ConnectionRequest(this, &oURL, NULL, pEndPoint))
			goto reject;
	}

accept:
	{
		ScopedCS lock2(m_csEndPoints);
		RegisterEndPoint(pEndPoint);
	}

	TRACE(0x6000000, _T("EndPointEventHandler::ConnectionRequest accepted from %s"), oURL.GetURL());
	return pEndPoint;

reject:
	TRACE(0x6000000, _T("EndPointEventHandler::ConnectionRequest refused from %s"), oURL.GetURL());
	SendReset(ulSocket, pAddress);

	if (pEndPoint != NULL)
	{
		delete pEndPoint;
	}

	return NULL;
}

void PRUDPTransport::ServiceUserMsg(PRUDPInetAddress *pAddress, Buffer *pBuffer)
{
	TransportEventHandler *pHandler = GetEventHandler();
	if (pHandler == NULL)
		return;

	TCHAR szURL[0x100];
	_stprintf(szURL, _T("%s%s"), _T("prudp"), _T(":/"));

	StationURL oURL(szURL);
	pAddress->GetURL(&oURL);

	if (pBuffer->GetContentSize() != 0)
	{
		TRACE(0x6000000, _T("Calling TransportEventHandler::Receive(%s, %d)"), oURL.GetURL(), pBuffer->GetContentSize());
		pHandler->Receive(this, pBuffer, &oURL);
	}
	else
	{
		TRACE(0x6000000, _T("Calling TransportEventHandler::Receive(%s, 0)"), oURL.GetURL());
		pHandler->Receive(this, NULL, &oURL);
	}
}

void PRUDPTransport::DemuxIncomingPacket(unsigned long ulSocket)
{
	PacketIn *pPacket = m_apSocket[ulSocket]->Recv();
	if (pPacket == NULL)
		return;

	PRUDPInetAddress *pAddress = pPacket->GetPeerAddress();

	if (pPacket->GetIOResult() != 0)
	{
		TRACE(0, _T("Received a packet with error = %x"), pPacket->GetIOResult());

		if (!GetSettings()->IsTrappingICMP())
		{
			pPacket->ReleaseRef();
			return;
		}

		TraceProto(_T("<-"), NULL, pAddress, m_apSocket[ulSocket]->GetAddress(), 0x20);

		__int64 llKey = pAddress->GetKey();

		std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.find(llKey);
		PRUDPEndPoint *pEndPoint = NULL;

		if (it != m_mapEndPoints.end())
			pEndPoint = it->second;

		if (pEndPoint != NULL)
		{
			pEndPoint->SignalFaultEvent(pPacket->GetIOResult());
			pPacket->ReleaseRef();
			return;
		}

		m_apSocket[ulSocket]->Close();
		pPacket->ReleaseRef();
		return;
	}

	unsigned char ucType = pPacket->GetType();

	if (ucType == 0)
	{
		PRUDPEndPoint *pEndPoint = ServiceConnectionRequest(pAddress, pPacket->GetPayload(), ulSocket);
		if (pEndPoint != NULL)
			pEndPoint->ServiceIncomingPacket(pPacket);

		pPacket->ReleaseRef();
		return;
	}

	if (ucType == 4)
	{
		ServiceUserMsg(pAddress, pPacket->GetPayload());
		pPacket->ReleaseRef();
		return;
	}

	TRACE(0, _T("Got a msg of type %d from:"), pPacket->GetType() & 0xFF);
	pAddress->Trace(0);

	__int64 llKey = pAddress->GetKey();

	std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.lower_bound(llKey);
	PRUDPEndPoint *pEndPoint = NULL;

	if (it != m_mapEndPoints.end() && !(llKey < it->first))
		pEndPoint = it->second;

	if (pEndPoint != NULL)
	{
		pEndPoint->ServiceIncomingPacket(pPacket);
		pPacket->ReleaseRef();
		return;
	}

	if (pPacket->GetType() == 6)
	{
		pPacket->ReleaseRef();
		return;
	}

	TRACE(0, _T("Found no EndPoint"));
	SendReset(ulSocket, pAddress);
	pPacket->ReleaseRef();
}

void PRUDPTransport::CompleteICMP(ICMPSocket *pSocket)
{
	PRUDPInetAddress oAddr;
	unsigned long ulResult = pSocket->GetIOCompletionResult(&oAddr);

	if (ulResult == 0)
	{
		__int64 llKey = oAddr.GetKey();

		std::map<__int64, PRUDPEndPoint *>::iterator it = m_mapEndPoints.lower_bound(llKey);
		PRUDPEndPoint *pEndPoint = NULL;

		if (it != m_mapEndPoints.end() && !(llKey < it->first))
			pEndPoint = it->second;

		if (pEndPoint != NULL)
			pEndPoint->SignalFaultEvent(NET_FAULT_UNREACHABLE);
	}

	pSocket->QueueRecv();
}

bool PRUDPTransport::Send(unsigned long ulSocket, PacketOut *pPacket)
{
	SYSTEMCHECK(pPacket != NULL);
	SYSTEMCHECK(pPacket->Valid() == true);

	m_apSocket[ulSocket]->Queue(pPacket);
	return true;
}

TimeoutManager *PRUDPTransport::GetTimeoutManager()
{
	return &m_oTimeoutManager;
}

void PRUDPTransport::TimeSliceHandler()
{
	m_oTimeoutManager.ServicePacketTimeouts();

	for (unsigned char i = 0; i < m_bInitialized; i++)
	{
		if (m_apSocket[i & 0xFF] != NULL)
			m_apSocket[i & 0xFF]->TryIOCompletion();

		if (m_apICMPSocket[i & 0xFF] != NULL)
			m_apICMPSocket[i & 0xFF]->TryIOCompletion();
	}

	if (GetOutputEmulationDevice()->IsEnabled())
	{
		GetOutputEmulationDevice()->DeliverData();
	}

	if (GetInputEmulationDevice()->IsEnabled())
	{
		GetInputEmulationDevice()->DeliverData();
	}

	{
		ScopedCS lock(m_csIdleEndPoints);

		while (m_lstIdleEndPoints.size() != 0)
		{
			PRUDPEndPoint *pEndPoint = m_lstIdleEndPoints.front();
			if (pEndPoint != NULL)
			{
				delete pEndPoint;
			}
			m_lstIdleEndPoints.pop_front();
		}
	}
}

UDPSocket *PRUDPTransport::GetSocket(unsigned char ucIndex)
{
	return m_apSocket[ucIndex & 0xFF];
}

unsigned short PRUDPTransport::GetPortNumber(unsigned long ulSocket)
{
	if (m_apSocket[ulSocket] != NULL)
		return m_apSocket[ulSocket]->GetBoundPort();

	return 0;
}

PRUDPTransportSettings *PRUDPTransport::GetSettings()
{
	return &m_oSettings;
}
