// Auto-generated from TimeoutManager.obj.md
#ifndef _TIMEOUTMANAGER_H_
#define _TIMEOUTMANAGER_H_

#include "PacketOut.h"



class TimeoutManager {
public:
    TimeoutManager(void);
    ~TimeoutManager();
    void SchedulePacketTimeout(PacketOut*);
    void CancelPacketTimeout(PacketOut*);
    void ServicePacketTimeouts(void);
};

#endif // _TIMEOUTMANAGER_H_
