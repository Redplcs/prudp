#ifndef _SlidingWindow_H_
#define _SlidingWindow_H_

#include <map>
#include <Platform/CriticalSection.h>
#include "PacketOut.h"

class SlidingWindow {
public:

	SlidingWindow(unsigned short usWindowSize);
	~SlidingWindow();

	void Purge();
	void Push(PacketOut *pPacket);
	void Acknowledged(unsigned long ulSeqId);
	PacketOut *GetNextToSend();
	PacketOut *GetPacket(unsigned long ulSeqId);
	bool ReadyToSend();
	bool Empty();
	std::map<unsigned long, PacketOut*>::iterator AcquireIterator();
	PacketOut *GetPacket(std::map<unsigned long, PacketOut*>::iterator it);
	void ReleaseIterator();
	bool DataPending();
	unsigned long NbDataPending();
	void Trace();

private:

	std::map<unsigned long, PacketOut*> m_mapPackets;
	unsigned short m_usWindowSize;
	unsigned long m_ulNextSeqId;
	unsigned long m_ulRightEdge;
	unsigned long m_ulLeftEdge;
	unsigned long m_ulDataPending;
	CriticalSection m_oCS;

};

#endif
