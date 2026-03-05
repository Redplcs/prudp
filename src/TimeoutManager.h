#ifndef _TimeoutManager_H_
#define _TimeoutManager_H_

#include <list>
#include <Platform/CriticalSection.h>
#include "PacketOut.h"

class TimeoutManager {
public:

	TimeoutManager();
	~TimeoutManager();

	void SchedulePacketTimeout(PacketOut *pPacket);
	void CancelPacketTimeout(PacketOut *pPacket);
	void ServicePacketTimeouts();

private:

	std::list<PacketOut *> m_lstPackets;
	CriticalSection m_oCS;

};

#endif
