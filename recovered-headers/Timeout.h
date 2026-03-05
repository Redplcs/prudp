// Auto-generated from Timeout.obj.md
#ifndef _TIMEOUT_H_
#define _TIMEOUT_H_

#include <Platform/Time.h>



class Timeout {
public:
    Timeout(void);
    ~Timeout();
    void SetExpirationTime(Time);
    void SetRelativeExpirationTime(long);
    bool IsExpired(void);
    bool IsAwaited(void);
    void SetRTO(unsigned long);
    void Start(void);
    bool operator<(Timeout&);
    unsigned long GetRTO(void);
    Time GetAwaitedTime(void);
};

#endif // _TIMEOUT_H_
