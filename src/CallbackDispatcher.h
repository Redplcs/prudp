#ifndef _CallbackDispatcher_H_
#define _CallbackDispatcher_H_

#include <Platform/ObjectThread.h>
#include <Platform/EventHandler.h>
#include <Platform/Event.h>
#include <Platform/CriticalSection.h>

class CallbackDispatcher : public ObjectThread<CallbackDispatcher, void*> {
public:
	typedef unsigned long (*Callback)(unsigned long, unsigned long);

	CallbackDispatcher(unsigned long ulContext);
	~CallbackDispatcher();

	void SetPriority(unsigned long ulPriority);
	void RegisterTimeSliceCallback(Callback pfCallback, unsigned long ulContext, long lTimeout);
	void UnregisterTimeSliceCallback();
	bool Stop(unsigned long ulTimeout);
	Event *CreateCallbackEvent(Callback pfCallback, unsigned long ulContext);
	void DeleteCallbackEvent(Event *pEvent);
	void CallInContext(Callback pfCallback, unsigned long ulContext);
	void DispatcherThread(void *pParam);

private:
	unsigned long m_ulContext;
	EventHandler *m_pEventHandler;
	Event *m_pWakeupEvent;
	Event *m_pCallbackEvent;
	EventHandler *m_pSyncEventHandler;
	Event *m_pSyncDoneEvent;
	CriticalSection m_cs;
	CallbackData *m_pTimeSliceCallback;
	long m_lTimeSliceTimeout;
	bool m_bStopRequested;
};

#endif
