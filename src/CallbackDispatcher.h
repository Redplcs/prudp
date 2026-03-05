#ifndef _CallbackDispatcher_H_
#define _CallbackDispatcher_H_

#include <Platform/ObjectThread.h>
#include <Platform/Event.h>

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

};

#endif
