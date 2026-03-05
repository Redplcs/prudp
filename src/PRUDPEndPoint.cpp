#include "PRUDPEndPoint.h"

#include <Platform/LeakTracker.h>
#include <Platform/SpinTest.h>
#include <Platform/SystemCheck.h>
#include <Platform/Trace.h>
#include <Plugins/Transport/Interface/EmulationDevice.h>
#include <Plugins/Transport/Interface/EndPointEventHandler.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/TransportPerfCounters.h>

PRUDPEndPoint::PRUDPEndPoint(Transport *pTransport, unsigned long ulIndex)
	: EndPoint(pTransport)
{
	m_eState = NotConnected;
	m_ulIndex = ulIndex;
	m_pDispatchQueue = new DispatchQueue();
	m_pSlidingWindow = new SlidingWindow((unsigned short)GetTransport()->GetSettings()->GetWindowSize());
	m_ulNextUnreliableSeqId = 0;
	m_ulExpectedSeqId = 0;
	m_ucPeerFlags = 0;
	m_pPingPacket = NULL;
	m_pPendingBuffer = NULL;
	m_ucExpectedContext = 1;

	TRACE(0, _T("Created EndPoint %x"), this);
}

PRUDPEndPoint::~PRUDPEndPoint()
{
	StopPing();

	TRACE(0, _T("Clearing Queues"));

	std::map<unsigned long, PacketOut*>::iterator it = m_pSlidingWindow->AcquireIterator();
	PacketOut *pPacket = m_pSlidingWindow->GetPacket(it);

	while (pPacket != NULL) {
		SYSTEMCHECK(ISGOODPTR(pPacket));
		TRACE(0, _T("Refcount = %d"), pPacket->GetRefCount());
		CancelPacketTimeout(pPacket);
		++it;
		pPacket = m_pSlidingWindow->GetPacket(it);
	}

	m_pSlidingWindow->ReleaseIterator();
	m_pSlidingWindow->Purge();
	m_pDispatchQueue->Purge();

	delete m_pDispatchQueue;
	delete m_pSlidingWindow;
}

unsigned long PRUDPEndPoint::Connect(StationURL *pURL, Buffer *pBuffer, const Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout)
{
	if (m_eState != NotConnected) {
		return 6;
	}

	if (!m_oAddress.SetFromURL(pURL, GetTransport()->GetSettings()->GetWellKnownPortNumber())) {
		return 0xc;
	}

	if (!GetTransport()->RegisterEndPoint(this)) {
		m_oAddress.SetAddress(0);
		m_oAddress.SetPortNumber(0);
		return 0x17;
	}

	SetState(Connecting);

	PacketOut *pPacket;
	if (pBuffer != NULL) {
		pPacket = new PacketOut(this, 0, 0x30, pBuffer);
	} else {
		pPacket = new PacketOut(this, 0, 0x30, NULL);
	}

	IORequestContext *pIOContext = new IORequestContext;
	pIOContext->m_pfCallback = pfCallback;
	pIOContext->m_pContext = (UserContext *)&refContext;
	pIOContext->m_pPacket = NULL;

	pPacket->SetIORequestContext(pIOContext);
	pPacket->GetTimeout()->SetRelativeExpirationTime(ulTimeout);

	TRACE(0, _T("%x Connecting"), this);

	if (!Send(pPacket)) {
		pPacket->ReleaseRef();
		SetState(NotConnected);
		return 3;
	}

	pPacket->ReleaseRef();

	if (pfCallback != NULL) {
		return 0;
	}

	SpinTest oSpinTest(0x32, ulTimeout);
	oSpinTest.LeaveOnTimeout();
	SpinOn(oSpinTest, IsConnecting());

	if (IsConnected()) {
		return 0;
	}

	return 0x11;
}

unsigned long PRUDPEndPoint::Disconnect(const Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout)
{
	TRACE(0, _T("Disconnecting %d"), m_oAddress.GetPort());

	if (!IsConnected()) {
		return 5;
	}

	SetState(Disconnecting);

	PacketOut *pPacket = new PacketOut(this, 2, 0x30, NULL);

	IORequestContext *pIOContext = new IORequestContext;
	pIOContext->m_pfCallback = pfCallback;
	pIOContext->m_pContext = (UserContext *)&refContext;
	pIOContext->m_pPacket = NULL;

	pPacket->SetIORequestContext(pIOContext);
	pPacket->GetTimeout()->SetRelativeExpirationTime(ulTimeout);
	pPacket->GetTimeout()->SetRTO(0x1f4);

	if (!Send(pPacket)) {
		pPacket->ReleaseRef();
		return 3;
	}

	pPacket->ReleaseRef();

	if (pfCallback != NULL) {
		return 0;
	}

	SpinTest oSpinTest(0x32, ulTimeout);
	oSpinTest.LeaveOnTimeout();
	SpinOn(oSpinTest, IsDisconnecting());

	if (IsDisconnected()) {
		return 0;
	}

	TraceState(0x6000000);
	return 0x11;
}

unsigned long PRUDPEndPoint::Send(Buffer *pBuffer, const Callback pfCallback, const UserContext &refContext, unsigned long ulFlags)
{
	if (!IsConnected()) {
		return 5;
	}

	unsigned long ulMTU;

	if ((ulFlags & 1) && pBuffer->GetContentSize() > GetTransport()->GetSettings()->GetMTU()) {
		unsigned long ulOffset = 0;
		unsigned char ucContextInfo = 1;

		while (pBuffer->GetContentSize() > ulOffset) {
			ulMTU = GetTransport()->GetSettings()->GetMTU();
			Buffer *pFragBuffer = new Buffer(ulMTU);

			unsigned long ulRemaining = pBuffer->GetContentSize() - ulOffset;
			unsigned long ulChunkSize;
			if (ulRemaining > GetTransport()->GetSettings()->GetMTU()) {
				ulChunkSize = GetTransport()->GetSettings()->GetMTU();
			} else {
				ulChunkSize = ulRemaining;
			}

			pFragBuffer->AppendData(pBuffer->GetContentPtr() + ulOffset, ulChunkSize, -1);

			PacketOut *pPacket = new PacketOut(this, 1, 0x30, pFragBuffer);

			IORequestContext *pIOContext = new IORequestContext;
			pIOContext->m_pfCallback = pfCallback;
			pIOContext->m_pContext = (UserContext *)&refContext;
			pIOContext->m_pPacket = NULL;

			pPacket->SetIORequestContext(pIOContext);

			ulOffset += GetTransport()->GetSettings()->GetMTU();

			if (pBuffer->GetContentSize() <= ulOffset) {
				pPacket->SetContextInfo(0);
			} else {
				pPacket->SetContextInfo(ucContextInfo);
				ucContextInfo++;
				if (ucContextInfo == 0) {
					ucContextInfo = 1;
				}
			}

			if (!Send(pPacket)) {
				pPacket->ReleaseRef();
				pFragBuffer->ReleaseRef();
				return 3;
			}

			pPacket->ReleaseRef();
			pFragBuffer->ReleaseRef();
		}

		return 0;
	}

	ulMTU = GetTransport()->GetSettings()->GetMTU();

	if (pBuffer->GetContentSize() > ulMTU) {
		return 9;
	}

	unsigned char ucFlags;
	if (ulFlags & 1) {
		ucFlags = 0x30;
	} else {
		ucFlags = 0;
	}

	PacketOut *pPacket = new PacketOut(this, 1, ucFlags, pBuffer);

	IORequestContext *pIOContext = new IORequestContext;
	pIOContext->m_pfCallback = pfCallback;
	pIOContext->m_pContext = (UserContext *)&refContext;
	pIOContext->m_pPacket = NULL;

	pPacket->SetIORequestContext(pIOContext);
	pPacket->SetContextInfo(0);

	if (!Send(pPacket)) {
		pPacket->ReleaseRef();
		return 3;
	}

	pPacket->ReleaseRef();
	return 0;
}

bool PRUDPEndPoint::IsConnected()
{
	return m_eState == Connected;
}

bool PRUDPEndPoint::IsDisconnected()
{
	return m_eState == Disconnected;
}

unsigned long PRUDPEndPoint::GetQueueSize()
{
	return GetTransport()->GetOutputEmulationDevice()->GetQueueSize();
}

unsigned long PRUDPEndPoint::GetNbReliablePending()
{
	return m_pSlidingWindow->NbDataPending();
}

StationURL *PRUDPEndPoint::GetStationURL()
{
	TCHAR szBuffer[0x44];
	sprintf(szBuffer, _T("%s%s"), _T("prudp"), _T(":/"));

	StationURL *pURL = new StationURL();
	pURL->SetURL(szBuffer);

	if (m_oAddress.GetURL(pURL)) {
		return pURL;
	}

	delete pURL;
	return NULL;
}

bool PRUDPEndPoint::IsPeerConnected()
{
	return m_ucPeerFlags != 0;
}

bool PRUDPEndPoint::IsPeerDisconnected()
{
	return m_ucPeerFlags != 0;
}

bool PRUDPEndPoint::Send(PacketOut *pPacket)
{
	pPacket->SetPeerAddress(&m_oAddress);

	if (pPacket->FlagSet(0x10)) {
		if (pPacket->GetNbTransmission() == 0) {
			m_pSlidingWindow->Push(pPacket);
		}
		SendNextReliable();
		return true;
	}

	if (!pPacket->FlagSet(0x08)) {
		if (pPacket->GetType() == 1) {
			pPacket->SetSeqId(m_ulNextUnreliableSeqId);
			m_ulNextUnreliableSeqId++;
		}
	}

	GetTransport()->Send(m_ulIndex, pPacket);
	return true;
}

void PRUDPEndPoint::SendNextReliable()
{
	TRACE(0, _T("Sending next reliable"));

	PacketOut *pPacket = m_pSlidingWindow->GetNextToSend();

	if (pPacket != NULL) {
		m_tLastSent = Time::GetTime();
		SendReliable(pPacket);
	}
}

void PRUDPEndPoint::SendReliable(PacketOut *pPacket)
{
	if (pPacket->GetType() == 2 && !ReadyToDisconnect()) {
		GetTransport()->GetTimeoutManager()->SchedulePacketTimeout(pPacket);
		return;
	}

	pPacket->IncNbTransmission();

	TRACE(0, _T("RTO is now %d, NbRetransmit is %d"), m_oRTT.GetRTO((unsigned long)pPacket->GetNbTransmission()), (unsigned long)pPacket->GetNbTransmission());

	pPacket->GetTimeout()->SetRTO((unsigned long)pPacket->GetNbTransmission() * m_oRTT.GetRTO((unsigned long)pPacket->GetNbTransmission()));

	TRACE(0, _T("Timeout for id %d"), pPacket->GetSeqId());

	GetTransport()->GetTimeoutManager()->SchedulePacketTimeout(pPacket);
	GetTransport()->Send(m_ulIndex, pPacket);
}

PacketIn *PRUDPEndPoint::GetNextDispatchPacket()
{
	return m_pDispatchQueue->GetNextToDispatch();
}

void PRUDPEndPoint::Dispatch(PacketIn *pPacket, Time tTime)
{
	Buffer *pPayload = pPacket->GetPayload();

	if (m_pPendingBuffer == NULL) {
		m_pPendingBuffer = pPayload;
		m_pPendingBuffer->AcquireRef();
		pPayload = NULL;
	}

	if (pPacket->GetContextInfo() != 0 && pPacket->GetContextInfo() != m_ucExpectedContext) {
		TRACE(1, _T("Received a bad packet"));
		if (m_pPendingBuffer != NULL) {
			m_pPendingBuffer->ReleaseRef();
			m_pPendingBuffer = NULL;
		}
		return;
	}

	if (pPayload != NULL) {
		*m_pPendingBuffer = *m_pPendingBuffer + *pPayload;
	}

	if (pPacket->GetContextInfo() != 0) {
		m_ucExpectedContext++;
		if (m_ucExpectedContext == 0) {
			m_ucExpectedContext = 1;
		}
		return;
	}

	EndPointEventHandler *pHandler = GetEventHandler();
	if (pHandler != NULL) {
		StationURL *pURL = GetStationURL();
		if (pURL != NULL) {
			TRACE(0x6000000, _T("Calling EndPointEventHandler::Receive(URL=%s, size=%d)"), pURL->GetURL(), m_pPendingBuffer->GetContentSize());
			ReleaseURL(pURL);
		} else {
			TRACE(0x6000000, _T("Calling EndPointEventHandler::Receive(size=%d)"), m_pPendingBuffer->GetContentSize());
		}

		GetEventHandler()->Receive(this, m_pPendingBuffer);
	}

	m_ucExpectedContext = 1;
	m_pPendingBuffer->ReleaseRef();
	m_pPendingBuffer = NULL;
}

void PRUDPEndPoint::SignalFaultEvent(unsigned long ulFault)
{
	if (GetEventHandler() == NULL) {
		return;
	}

	if (m_eState == Faulty) {
		return;
	}

	StationURL *pURL = GetStationURL();

	if (pURL != NULL) {
		TRACE(0x6000000, _T("Calling EndPointEventHandler::FaultDetection(URL=%s, fault=%d)"), pURL->GetURL(), ulFault);
		ReleaseURL(pURL);
	} else {
		TRACE(0x6000000, _T("Calling EndPointEventHandler::FaultDetection(fault=%d)"), ulFault);
	}

	if (m_eState == Connecting) {
		SetState(Faulty);
		StopPing();
		return;
	}

	SetState(Faulty);
	StopPing();
	GetEventHandler()->FaultDetection(this, ulFault);
}

void PRUDPEndPoint::ServiceIncomingPacket(PacketIn *pPacket)
{
	unsigned char ucType = pPacket->GetType();

	TRACE(0, _T("%x Receiving packet"), this);

	if (pPacket->FlagSet(0x20)) {
		TRACE(0, _T("Sending ack"));

		PacketOut *pAck = new PacketOut(this, pPacket->GetType(), 0, NULL);
		pAck->SetFlag(0x08);
		pAck->SetSeqId(pPacket->GetSeqId());
		pAck->SetContextInfo(pPacket->GetContextInfo());
		Send(pAck);
		pAck->ReleaseRef();
	}

	m_tLastReceived = Time::GetTime();
	SetPeerFlooded(pPacket->FlagSet(0x80));

	if (pPacket->FlagSet(0x10)) {
		m_pDispatchQueue->Dispatched(pPacket);
	}

	switch (ucType) {
	case 1: {
		if (pPacket->FlagSet(0x08)) {
			PacketAcknowledged(pPacket);
			break;
		}

		if (!pPacket->FlagSet(0x10)) {
			unsigned long ulExpected = m_ulExpectedSeqId;
			unsigned long ulSeqId = pPacket->GetSeqId();
			long lDiff = (long)(ulSeqId - ulExpected);

			if (lDiff < 0) {
				GetTransport()->GetPerfCounters()->Inc(4, -1);
				break;
			}

			if (lDiff != 0) {
				TRACE(0, _T("LOST = %d,%d"), pPacket->GetSeqId(), ulExpected);
			}

			GetTransport()->GetPerfCounters()->Inc(4, lDiff);
			m_ulExpectedSeqId = pPacket->GetSeqId() + 1;
		}

		if (pPacket->FlagSet(0x10)) {
			break;
		}

		Dispatch(pPacket, pPacket->GetIOTime());
		break;
	}
	case 2: {
		if (pPacket->FlagSet(0x08)) {
			PacketOut *pAckedPacket = m_pSlidingWindow->GetPacket(pPacket->GetSeqId());
			if (pAckedPacket != NULL) {
				IORequestContext *pIOContext = pAckedPacket->GetIORequestContext();
				if (pIOContext != NULL) {
					TRACE(0, _T("Completing request"));
					pIOContext = pAckedPacket->GetIORequestContext();
					if (pIOContext->m_pfCallback != NULL) {
						pIOContext->m_pfCallback(pAckedPacket->GetEndPoint(), pIOContext->m_pBuffer, 0, pIOContext->m_pContext);
					}
				}
			}

			SetState(Disconnected);
			PacketAcknowledged(pPacket);
			break;
		}

		SetPeerDisconnected(true);

		if (GetEventHandler() != NULL) {
			StationURL *pURL = GetStationURL();
			if (pURL != NULL) {
				TRACE(0x6000000, _T("Calling EndPointEventHandler::PeerDisconnected(URL=%s)"), pURL->GetURL());
				ReleaseURL(pURL);
				GetEventHandler()->PeerDisconnected(this);
			} else {
				TRACE(0x6000000, _T("Calling EndPointEventHandler::PeerDisconnected()"));
				GetEventHandler()->PeerDisconnected(this);
			}
		}
		break;
	}
	case 0: {
		if (pPacket->FlagSet(0x08)) {
			PacketOut *pAckedPacket = m_pSlidingWindow->GetPacket(pPacket->GetSeqId());
			if (pAckedPacket != NULL) {
				IORequestContext *pIOContext = pAckedPacket->GetIORequestContext();
				if (pIOContext != NULL) {
					TRACE(0, _T("Completing Connection request"));
					pIOContext = pAckedPacket->GetIORequestContext();
					if (pIOContext->m_pfCallback != NULL) {
						pIOContext->m_pfCallback(pAckedPacket->GetEndPoint(), pIOContext->m_pBuffer, 0, pIOContext->m_pContext);
					}
				}
			}
			PacketAcknowledged(pPacket);
		}

		SetState(Connected);
		SetPeerConnected(true);
		StartPing();
		break;
	}
	case 3: {
		if (!pPacket->FlagSet(0x08)) {
			break;
		}

		if (m_pPingPacket == NULL) {
			break;
		}

		unsigned char ucContext = pPacket->GetContextInfo();
		if (ucContext != m_pPingPacket->GetContextInfo()) {
			break;
		}

		m_oRTT.Adjust((unsigned long)(pPacket->GetIOTime() - m_pPingPacket->GetIOTime()));
		break;
	}
	case 6: {
		if (IsConnecting()) {
			PacketOut *pConnPacket = m_pSlidingWindow->GetPacket(0);
			if (pConnPacket != NULL) {
				IORequestContext *pIOContext = pConnPacket->GetIORequestContext();
				if (pIOContext != NULL) {
					TRACE(0, _T("Completing Connection request"));
					IORequestContext *pCtx = m_pSlidingWindow->GetPacket(pConnPacket->GetSeqId())->GetIORequestContext();
					if (pCtx->m_pfCallback != NULL) {
						pCtx->m_pfCallback(pCtx->m_pPacket->GetEndPoint(), pCtx->m_pBuffer, 0x15, pCtx->m_pContext);
					}
				}
			}
			SetState((ConnectionState)5);
			break;
		}

		if (IsDisconnecting()) {
			SetState(Disconnected);
			break;
		}

		if (!IsPeerDisconnected()) {
			SignalFaultEvent(0x15);
		}
		break;
	}
	default:
		break;
	}

	PacketIn *pDispatch = GetNextDispatchPacket();
	while (pDispatch != NULL) {
		if (pDispatch->GetType() == 1) {
			Dispatch(pDispatch, pPacket->GetIOTime());
		}
		m_pDispatchQueue->Dispatched(pDispatch);
		pDispatch = GetNextDispatchPacket();
	}
}

void PRUDPEndPoint::PacketAcknowledged(Packet *pPacket)
{
	PacketOut *pAckedPacket = m_pSlidingWindow->GetPacket(pPacket->GetSeqId());

	if (pAckedPacket == NULL) {
		return;
	}

	SYSTEMCHECK(ISGOODPTR(pAckedPacket));
	SYSTEMCHECK(ISGOODPTR(pAckedPacket->GetTimeout()));

	if (pAckedPacket->GetNbTransmission() == 1) {
		SYSTEMCHECK((_LONGLONG)pPacket->GetIOTime() >= (_LONGLONG)pAckedPacket->GetIOTime());
		m_oRTT.Adjust((unsigned long)(pPacket->GetIOTime() - pAckedPacket->GetIOTime()));
	}

	CancelPacketTimeout(pAckedPacket);
	m_pSlidingWindow->Acknowledged(pPacket->GetSeqId());
	SendNextReliable();
}

void PRUDPEndPoint::ServiceTimeout(PacketOut *pTimedOutPacket)
{
	TRACE(0, _T("Servicing timeout"));
	SYSTEMCHECK(pTimedOutPacket != NULL);

	if (pTimedOutPacket->GetType() == 3) {
		TimeToPing();
		return;
	}

	if ((unsigned long)pTimedOutPacket->GetNbTransmission() != GetTransport()->GetSettings()->GetMaxRetransmission()) {
		if (!pTimedOutPacket->GetTimeout()->IsExpired()) {
			SendReliable(pTimedOutPacket);
			return;
		}
	}

	IORequestContext *pIOContext = pTimedOutPacket->GetIORequestContext();
	if (pIOContext != NULL) {
		pIOContext = pTimedOutPacket->GetIORequestContext();
		if (pIOContext->m_pfCallback != NULL) {
			pIOContext->m_pfCallback(pTimedOutPacket->GetEndPoint(), pIOContext->m_pBuffer, 0x11, pIOContext->m_pContext);
		}
	}
}

void PRUDPEndPoint::CancelPacketTimeout(PacketOut *pPacket)
{
	TRACE(0, _T("Cancelling Timeout of %d"), pPacket->GetSeqId());
	SYSTEMCHECK(ISGOODPTR(pPacket));
	GetTransport()->GetTimeoutManager()->CancelPacketTimeout(pPacket);
}

void PRUDPEndPoint::StartPing()
{
	if (m_pPingPacket != NULL) {
		return;
	}

	m_pPingPacket = new PacketOut(this, 3, 0x20, NULL);
	m_pPingPacket->GetTimeout()->SetRTO(GetTransport()->GetSettings()->GetKeepAliveTimeout());
	GetTransport()->GetTimeoutManager()->SchedulePacketTimeout(m_pPingPacket);
}

void PRUDPEndPoint::StopPing()
{
	if (m_pPingPacket != NULL) {
		GetTransport()->GetTimeoutManager()->CancelPacketTimeout(m_pPingPacket);
		m_pPingPacket->ReleaseRef();
		m_pPingPacket = NULL;
	}
}

void PRUDPEndPoint::TimeToPing()
{
	Time tNow = Time::GetTime();

	unsigned long ulMaxSilenceTime = GetTransport()->GetSettings()->GetMaxSilenceTime();

	if ((_LONGLONG)(tNow - m_tLastReceived) > (long)ulMaxSilenceTime) {
		TRACE(0x20, _T("NET_FAULT: Silent for the past %dms"), tNow - m_tLastReceived);
		SignalFaultEvent(NET_FAULT_TIMEOUT);
		return;
	}

	unsigned long ulKeepAliveTimeout = GetTransport()->GetSettings()->GetKeepAliveTimeout();

	if ((_LONGLONG)(tNow - m_tLastSent) > (long)ulKeepAliveTimeout) {
		m_pPingPacket->SetContextInfo(m_pPingPacket->GetContextInfo() + 1);
		Send(m_pPingPacket);
	}

	GetTransport()->GetTimeoutManager()->SchedulePacketTimeout(m_pPingPacket);
}

void PRUDPEndPoint::SetState(PRUDPEndPoint::ConnectionState eState)
{
	TCHAR szBefore[0x20];
	GetStringState(szBefore);
	m_eState = eState;
	TCHAR szAfter[0x20];
	GetStringState(szAfter);
}

void PRUDPEndPoint::GetStringState(TCHAR *szBuffer)
{
	switch (m_eState) {
	case NotConnected:
		_tcscpy(szBuffer, _T("NotConnected"));
		break;
	case Connecting:
		_tcscpy(szBuffer, _T("Connecting"));
		break;
	case Connected:
		_tcscpy(szBuffer, _T("Connected"));
		break;
	case Disconnecting:
		_tcscpy(szBuffer, _T("Disconnecting"));
		break;
	case Disconnected:
		_tcscpy(szBuffer, _T("Disconnected"));
		break;
	case Faulty:
		_tcscpy(szBuffer, _T("Faulty"));
		break;
	default:
		_tcscpy(szBuffer, _T("Unknown"));
		break;
	}
}

void PRUDPEndPoint::TraceState(unsigned long ulLevel)
{
	TCHAR szBuffer[0x80];
	szBuffer[0] = 0;
	GetStringState(szBuffer);
	TRACE(ulLevel, _T("Endpoint %x state is %s"), this, szBuffer);
}

bool PRUDPEndPoint::ReadyToDisconnect()
{
	return !m_pSlidingWindow->DataPending();
}

bool PRUDPEndPoint::IsNotConnected()
{
	return m_eState == NotConnected;
}

bool PRUDPEndPoint::IsConnecting()
{
	return m_eState == Connecting;
}

bool PRUDPEndPoint::IsDisconnecting()
{
	return m_eState == Disconnecting;
}

bool PRUDPEndPoint::IsPeerFlooded()
{
	return m_ucPeerFlags != 0;
}

void PRUDPEndPoint::SetPeerFlooded(bool bFlooded)
{
	if (bFlooded) {
		m_ucPeerFlags |= 0x01;
	} else {
		m_ucPeerFlags &= 0xfe;
	}
}

void PRUDPEndPoint::SetPeerDisconnected(bool bDisconnected)
{
	if (bDisconnected) {
		m_ucPeerFlags |= 0x03;
		SetPeerConnected(false);
	} else {
		m_ucPeerFlags &= 0xfc;
	}
}

void PRUDPEndPoint::SetPeerConnected(bool bConnected)
{
	if (bConnected) {
		m_ucPeerFlags |= 0x02;
		SetPeerDisconnected(false);
	} else {
		m_ucPeerFlags &= 0xfd;
	}
}

unsigned long PRUDPEndPoint::GetAssociatedSocket()
{
	return m_ulIndex;
}

RTT *PRUDPEndPoint::GetRTT()
{
	return &m_oRTT;
}

void PRUDPEndPoint::SetSocket(unsigned long ulSocket)
{
	m_ulIndex = ulSocket;
}

bool PRUDPEndPoint::IsIdle()
{
	return m_pSlidingWindow->Empty();
}

void PRUDPEndPoint::SetPRUDPInetAddress(PRUDPInetAddress *pAddress)
{
	m_oAddress = *pAddress;
}

PRUDPInetAddress *PRUDPEndPoint::GetPRUDPInetAddress()
{
	return &m_oAddress;
}

bool PRUDPEndPoint::IsFlooded()
{
	return false;
}

PRUDPTransport *PRUDPEndPoint::GetTransport()
{
	return (PRUDPTransport *)m_pTransport;
}
