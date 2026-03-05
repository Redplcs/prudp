#ifndef _AsyncIOContext_H_
#define _AsyncIOContext_H_

#include <Platform/Event.h>
#include <Win32.h>

class AsyncIOContext {
public:

	AsyncIOContext();

	void SetEvent(Event *pEvent);
	Event *GetEvent();

	void SignalEvent();
	void ResetEvent();
	void SetIOSize(unsigned long ulSize);
	unsigned long GetIOSize();
	unsigned long GetReturnCode();
	void SetReturnCode(unsigned long ulReturnCode);
	OVERLAPPED *GetOverlapped();

};


#endif
