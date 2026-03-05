// Auto-generated from Socket.obj.md
#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <Plugins/Core/Buffer.h>
#include "AsyncIOContext.h"
#include "PRUDPInetAddress.h"




class Socket {
public:
    Socket(unsigned long);
    ~Socket();
    bool Open(void);
    bool Bind(PRUDPInetAddress*);
    PRUDPInetAddress*  GetAddress(void);
    void Shutdown(unsigned long);
    void Close(void);
    int Send(Buffer*,PRUDPInetAddress*,unsigned long*,AsyncIOContext*);
    int Recv(Buffer*,PRUDPInetAddress*,unsigned long*,AsyncIOContext*);
    void TryIOCompletion(AsyncIOContext*);
    bool WaitForIOCompletion(AsyncIOContext*,unsigned long,unsigned long*);
    unsigned long GetIOResult(AsyncIOContext*,unsigned long*);
    bool SetAsync(bool);
    bool SetNoDelay(bool);
    bool SetBuffers(void);
    bool ReuseAddress(bool);
    bool SetDebugMode(bool);
    bool SetBroadcastMode(bool);
    static unsigned long GetLastSocketError(void);
    unsigned short GetBoundPort(void);
};

#endif // _SOCKET_H_
