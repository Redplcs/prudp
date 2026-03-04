//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _EventHandler_H_
#define _EventHandler_H_

#include <Platform/PlatformImpl.h>
#include <Platform/CriticalSection.h>
#include <Platform/Event.h>

class EventHandler {

	class Attributes;

public:
	EventHandler(unsigned short usMaxNbEvents);

	Event *CreateEventObject(unsigned long ulType, unsigned long ulContext);
	void DeleteEventObject(Event *pEvent);
	void ResetEvent(Event *pEvent);
	void SetEvent(Event *pEvent);
	bool EventSet(Event *pEvent);

	void *GetPlatformSpecificEvent(Event *pEvent);

	~EventHandler();

	bool WaitForEvent(unsigned long ulTimeout, Event** ppEvent);

	static 	bool Test();
	unsigned short	GetMaxEvents();

private:
	unsigned short	GetEventIndex(Event *pEvent);

	CriticalSection	m_csEventTable;
	#ifdef WIN32
	bool			WaitForWin32Event(unsigned long ulTimeout, Event** ppEvent);
	#else
	bool			WaitForLinuxEvent(unsigned long ulTimeout, Event** ppEvent);
	#endif
	Attributes		*m_pAttributes;

	unsigned short			GetSignaledEvent();

	Event					**m_apEvents;
	unsigned long			m_ulNbEventsCreated;
	unsigned short			m_usMaxNbEvents;
};


#endif
