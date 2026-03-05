#ifndef _TimeoutManager_H_
#define _TimeoutManager_H_

#include "PacketOut.h"

class TimeoutManager {
public:

	TimeoutManager();
	~TimeoutManager();

	void SchedulePacketTimeout(PacketOut *pPacket);
	void CancelPacketTimeout(PacketOut *pPacket);
	void ServicePacketTimeouts();

};

#endif
