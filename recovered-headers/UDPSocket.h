// Auto-generated from UDPSocket.obj.md
#ifndef _UDPSOCKET_H_
#define _UDPSOCKET_H_

#include <Platform/Event.h>
#include "PRUDPInetAddress.h"
#include "PRUDPTransport.h"
#include "PacketIn.h"
#include "PacketOut.h"




class UDPSocket {
public:
    UDPSocket(PRUDPTransport*);
    ~UDPSocket();
    void SetCompletionEvents(Event*,Event*);
    bool Bind(PRUDPInetAddress*,unsigned short*);
    void Queue(PacketOut*);
    bool Send(PacketOut*);
    unsigned long CompleteSend(void);
    void Listen(void);
    void TryIOCompletion(void);
    PacketIn*  Recv(void);
    unsigned long CompleteRecv(void);
    unsigned long QueueSize(void);
    bool InputFlooded(void);
    bool OutputFlooded(void);
};

#endif // _UDPSOCKET_H_
