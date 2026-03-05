#ifndef _SlidingWindow_H_
#define _SlidingWindow_H_

#include <map>
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

};

#endif
