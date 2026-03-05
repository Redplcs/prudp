// Auto-generated from AsyncIOContext.obj.md
#ifndef _ASYNCIOCONTEXT_H_
#define _ASYNCIOCONTEXT_H_

#include <Platform/Event.h>



struct OVERLAPPED;

class AsyncIOContext {
public:
    AsyncIOContext(void);
    void SetEvent(Event*);
    Event*  GetEvent(void);
    void SignalEvent(void);
    void ResetEvent(void);
    void SetIOSize(unsigned long);
    unsigned long GetIOSize(void);
    unsigned long GetReturnCode(void);
    void SetReturnCode(unsigned long);
    OVERLAPPED*  GetOverlapped(void);
};

#endif // _ASYNCIOCONTEXT_H_
