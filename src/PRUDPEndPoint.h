#ifndef _PRUDPEndPoint_H_
#define _PRUDPEndPoint_H_

#include <Platform/Time.h>
#include <Platform/UserContext.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/Transport.h>
#include "PRUDPInetAddress.h"
#include "PRUDPTransport.h"
#include "Packet.h"
#include "PacketIn.h"
#include "PacketOut.h"
#include "RTT.h"
#include "SlidingWindow.h"
#include "TimeoutManager.h"

class DispatchQueue {
public:

	DispatchQueue();
	~DispatchQueue();

	void Purge();
	PacketIn *GetNextToDispatch();
	void Dispatched(PacketIn *pPacket);

};

class PRUDPEndPoint : public EndPoint {

	friend class PRUDPTransport;
	friend class TimeoutManager;

	enum ConnectionState {
		NotConnected = 0,
		Connecting = 1,
		Connected = 2,
		Disconnecting = 3,
		Disconnected = 4,
		Faulty = 6
	};

public:

	PRUDPEndPoint(Transport *pTransport, unsigned long ulIndex);
	~PRUDPEndPoint();

	unsigned long Connect(StationURL *pURL, Buffer *pBuffer, const Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout);
	unsigned long Disconnect(const Callback pfCallback, const UserContext &refContext, unsigned long ulTimeout);
	unsigned long Send(Buffer *pBuffer, const Callback pfCallback, const UserContext &refContext, unsigned long ulFlags);

	bool IsConnected();
	bool IsDisconnected();
	unsigned long GetQueueSize();
	unsigned long GetNbReliablePending();
	StationURL *GetStationURL();
	bool IsPeerConnected();
	bool IsPeerDisconnected();

private:

	bool Send(PacketOut *pPacket);
	void SendNextReliable();
	void SendReliable(PacketOut *pPacket);
	PacketIn *GetNextDispatchPacket();
	void Dispatch(PacketIn *pPacket, Time tTime);
	void SignalFaultEvent(unsigned long ulFault);
	void ServiceIncomingPacket(PacketIn *pPacket);
	void PacketAcknowledged(Packet *pPacket);
	void ServiceTimeout(PacketOut *pPacket);
	void CancelPacketTimeout(PacketOut *pPacket);
	void StartPing();
	void StopPing();
	void TimeToPing();
	void SetState(PRUDPEndPoint::ConnectionState eState);
	void GetStringState(TCHAR *szBuffer);
	void TraceState(unsigned long ulLevel);
	bool ReadyToDisconnect();
	bool IsNotConnected();
	bool IsConnecting();
	bool IsDisconnecting();
	bool IsPeerFlooded();
	void SetPeerFlooded(bool bFlooded);
	void SetPeerDisconnected(bool bDisconnected);
	void SetPeerConnected(bool bConnected);
	unsigned long GetAssociatedSocket();
	RTT *GetRTT();
	void SetSocket(unsigned long ulSocket);
	bool IsIdle();
	void SetPRUDPInetAddress(PRUDPInetAddress *pAddress);
	PRUDPInetAddress *GetPRUDPInetAddress();
	bool IsFlooded();
	PRUDPTransport *GetTransport();

	ConnectionState m_eState;
	unsigned long m_ulIndex;
	PRUDPInetAddress m_oAddress;
	DispatchQueue *m_pDispatchQueue;
	SlidingWindow *m_pSlidingWindow;
	PacketOut *m_pPingPacket;
	RTT m_oRTT;
	Time m_tLastSent;
	Time m_tLastReceived;
	unsigned long m_ulNextUnreliableSeqId;
	unsigned long m_ulExpectedSeqId;
	unsigned char m_ucPeerFlags;
	Buffer *m_pPendingBuffer;
	unsigned char m_ucExpectedContext;

};

#endif
