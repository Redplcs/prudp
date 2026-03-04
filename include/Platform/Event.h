//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Event_H_
#define _Event_H_

#include <Platform/PlatformImpl.h>

class Event {

	friend class EventHandler;

public:
	void	SetType(unsigned long ulType);
	unsigned long	GetType();

	void 	SetContext(unsigned long ulContext);
	unsigned long 	GetContext();

	void 	Set();
	void 	Reset();
	bool 	IsSet();

	unsigned long	GetRegistrationId();
	EventHandler *GetEventHandler();

	void			*GetPlatformSpecificEvent();

protected:
	Event(EventHandler *pEventHandler,unsigned long ulEventType,unsigned long ulContext);
	~Event();

	EventHandler	*m_pEventHandler;
	unsigned long	m_ulEventType;
	unsigned long	m_ulContext;
};


#endif
