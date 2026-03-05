// Auto-generated from CallbackDispatcher.obj.md
#ifndef _CALLBACKDISPATCHER_H_
#define _CALLBACKDISPATCHER_H_

#include <Platform/Event.h>



class CallbackDispatcher {
public:
    CallbackDispatcher(unsigned long);
    ~CallbackDispatcher();
    void SetPriority(unsigned long);
    void RegisterTimeSliceCallback(unsigned long (__cdecl*)(unsigned long,unsigned long),unsigned long,long);
    void UnregisterTimeSliceCallback(void);
    bool Stop(unsigned long);
    Event*  CreateCallbackEvent(unsigned long (__cdecl*)(unsigned long,unsigned long),unsigned long);
    void DeleteCallbackEvent(Event*);
    void CallInContext(unsigned long (__cdecl*)(unsigned long,unsigned long),unsigned long);
    void DispatcherThread(void*);
};

#endif // _CALLBACKDISPATCHER_H_
