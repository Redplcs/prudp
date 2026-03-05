#ifndef _UDPSocket_H_
#define _UDPSocket_H_

#include <Platform/Event.h>
#include "PRUDPInetAddress.h"
#include "PRUDPTransport.h"
#include "PacketIn.h"
#include "PacketOut.h"

class UDPSocket : public Socket {
public:

	UDPSocket(PRUDPTransport *pTransport);
	~UDPSocket();

	void SetCompletionEvents(Event *pSendEvent, Event *pRecvEvent);
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

};

#endif
