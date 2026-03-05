#ifndef _UDPSocket_H_
#define _UDPSocket_H_

#include <Platform/CriticalSection.h>
#include <Platform/Event.h>
#include "PRUDPInetAddress.h"
#include "PRUDPTransport.h"
#include "PacketIn.h"
#include "PacketOut.h"
#include "Socket.h"

class DeviceData;

class UDPSocket : public Socket {
	friend bool DeliverToApp(DeviceData *pDeviceData);

public:

	UDPSocket(PRUDPTransport *pTransport);
	~UDPSocket();

	void SetCompletionEvents(Event *pRecvEvent, Event *pSendEvent);
	bool Bind(PRUDPInetAddress *pAddress, unsigned short *pusPort);
	void Queue(PacketOut *pPacket);
	bool Send(PacketOut *pPacket);
	unsigned long CompleteSend();
	void Listen();
	void TryIOCompletion();
	PacketIn *Recv();
	unsigned long CompleteRecv();
	unsigned long QueueSize();
	bool InputFlooded();
	bool OutputFlooded();

private:

	struct IOContext;

	PRUDPTransport *m_pTransport;
	IOContext *m_pRecvIOContext;
	IOContext *m_pSendIOContext;
	bool m_bSendPending;
	bool m_bRecvPending;
	CriticalSection m_sendCS;
	CriticalSection m_recvCS;
	PacketIn *m_pRecvPacket;

};

#endif
