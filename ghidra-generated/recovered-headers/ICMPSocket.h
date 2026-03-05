// Auto-generated from ICMPSocket.obj.md
#ifndef _ICMPSOCKET_H_
#define _ICMPSOCKET_H_

#include <Platform/Event.h>
#include "PRUDPInetAddress.h"




class ICMPSocket {
public:
    ICMPSocket(void);
    ~ICMPSocket();
    void SetCompletionEvent(Event*);
    bool Bind(PRUDPInetAddress*);
    void QueueRecv(void);
    void TryIOCompletion(void);
    unsigned long GetIOCompletionResult(PRUDPInetAddress*);
private:
    void TraceICMPErrorPacket(PRUDPInetAddress*,void*,unsigned long);
};

#endif // _ICMPSOCKET_H_
