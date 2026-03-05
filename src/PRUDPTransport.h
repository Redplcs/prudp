#ifndef _PRUDPTransport_H_
#define _PRUDPTransport_H_

#include <map>
#include <Platform/Event.h>
#include <Platform/UserContext.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Core/Plugin.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/EndPointEventHandler.h>
#include <Plugins/Transport/Interface/EndPointGroup.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/Transport.h>
#include "CallbackDispatcher.h"
#include "ICMPSocket.h"
#include "InterfaceTable.h"
#include "PRUDPEndPoint.h"
#include "PRUDPInetAddress.h"
#include "PRUDPTransportSettings.h"
#include "Packet.h"
#include "PacketOut.h"
#include "TimeoutManager.h"
#include "UDPSocket.h"

class PRUDPTransport : public Transport {

	friend unsigned long HandleTimeSliceWrap(unsigned long, unsigned long);
	friend unsigned long HandleRecvCompletedWrap(unsigned long, unsigned long);
	friend unsigned long HandleSendCompletedWrap(unsigned long, unsigned long);
	friend unsigned long HandleICMPCompletedWrap(unsigned long, unsigned long);

public:

	PRUDPTransport(Plugin *pPlugin);
	virtual ~PRUDPTransport();

	virtual bool ResponsibleForURL(StationURL *pURL);
	virtual TCHAR *GetType();
	virtual unsigned long Initialize();
	virtual unsigned long ListenOnWellKnown();
	virtual unsigned long ListenOnArbitrary();
	virtual unsigned long StopListenOnWellKnown();
	virtual unsigned long StopListenOnArbitrary();
	virtual EndPoint *CreateEndPoint();
	virtual unsigned long DeleteEndPoint(EndPoint *pEndPoint);
	virtual unsigned long SendBroadcast(Buffer *pBuffer);
	virtual unsigned long SendBroadcast(Buffer *pBuffer, const Transport::Callback pfCallback, const UserContext &refContext);
	virtual unsigned long Send(StationURL *pURL, Buffer *pBuffer);
	virtual unsigned long Send(StationURL *pURL, Buffer *pBuffer, const Transport::Callback pfCallback, const UserContext &refContext);
	virtual unsigned long GetNbLocalURL();
	virtual StationURL *GetLocalURL(unsigned long ulIndex);
	virtual StationURL *GetIPURL(unsigned long ulAddress, unsigned short usPort);
	virtual StationURL *GetIPURL(TCHAR *szAddress, unsigned short usPort);
	virtual bool GetIPFromURL(StationURL *pURL, unsigned long *pulAddress, unsigned short *pusPort);
	virtual void ReleaseURL(StationURL *pURL);
	virtual bool IsCapable(unsigned long ulCapability);
	virtual unsigned long SetOption(unsigned long ulOption, UserContext &refContext);
	virtual unsigned long GetOption(unsigned long ulOption, UserContext &refContext);

	void SetHighPrio();
	void TraceProto(TCHAR *szLabel, Packet *pPacket, PRUDPInetAddress *pSrcAddress, PRUDPInetAddress *pDstAddress, unsigned long ulSocket);

protected:

	virtual unsigned long ConnectEndPoint(EndPoint *pEndPoint, StationURL *pURL, Buffer *pBuffer, const EndPoint::Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout);
	virtual unsigned long DisconnectEndPoint(EndPoint *pEndPoint, const EndPoint::Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout);
	virtual unsigned long SendToEndPoint(EndPoint *pEndPoint, Buffer *pBuffer, const EndPoint::Callback pfCallback, const UserContext &refContext, unsigned long ulFlags);
	virtual bool IsEndPointConnected(EndPoint *pEndPoint);
	virtual bool IsEndPointPeerConnected(EndPoint *pEndPoint);
	virtual bool IsEndPointDisconnected(EndPoint *pEndPoint);
	virtual bool IsEndPointPeerDisconnected(EndPoint *pEndPoint);
	virtual unsigned long RegisterEndPointEventHandler(EndPoint *pEndPoint, EndPointEventHandler *pHandler);
	virtual StationURL *GetEndPointStationURL(EndPoint *pEndPoint);
	virtual unsigned long GetEndPointQueueSize(EndPoint *pEndPoint);
	virtual unsigned long GetEndPointRTT(EndPoint *pEndPoint);
	virtual unsigned long GetEndPointRTTAverage(EndPoint *pEndPoint);
	virtual unsigned long SendToEndPointGroup(EndPointGroup *pGroup, Buffer *pBuffer, const EndPointGroup::Callback *pfCallback, const UserContext &refContext, unsigned long ulFlags);

private:

	void StartEventListener();
	bool UDPListen(unsigned long ulSocket, unsigned short usPort);
	bool StopUDPListen(unsigned long ulSocket);
	bool ICMPListen(unsigned long ulSocket, unsigned short usPort);
	bool StopICMPListen(unsigned long ulSocket);
	bool RegisterEndPoint(PRUDPEndPoint *pEndPoint);
	void UnregisterEndPoint(PRUDPEndPoint *pEndPoint);
	void SendReset(unsigned long ulSocket, PRUDPInetAddress *pAddress);
	PRUDPEndPoint *ServiceConnectionRequest(PRUDPInetAddress *pAddress, Buffer *pBuffer, unsigned long ulSocket);
	void ServiceUserMsg(PRUDPInetAddress *pAddress, Buffer *pBuffer);
	void DemuxIncomingPacket(unsigned long ulSocket);
	void CompleteICMP(ICMPSocket *pSocket);
	bool Send(unsigned long ulSocket, PacketOut *pPacket);
	TimeoutManager *GetTimeoutManager();
	void TimeSliceHandler();
	UDPSocket *GetSocket(unsigned char ucIndex);
	unsigned short GetPortNumber(unsigned long ulSocket);
	PRUDPTransportSettings *GetSettings();

	bool m_bInitialized;
	PRUDPInetAddress m_apAddress[2];
	UDPSocket *m_apSocket[2];
	Event *m_apRecvEvent[2];
	Event *m_apSendEvent[2];
	ICMPSocket *m_apICMPSocket[2];
	Event *m_apICMPEvent[2];
	CallbackDispatcher *m_pCallbackDispatcher;
	TimeoutManager m_oTimeoutManager;
	std::map<__int64, PRUDPEndPoint *> m_mapEndPoints;
	CriticalSection m_csEndPoints;
	CriticalSection m_csSocket;
	InterfaceTable m_oInterfaceTable;
	std::list<PRUDPEndPoint *> m_lstIdleEndPoints;
	CriticalSection m_csIdleEndPoints;
	PRUDPTransportSettings m_oSettings;

};

#endif
