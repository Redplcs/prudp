# CallbackDispatcher.obj.c

Комментарии с восстановленными сигнатурами функций из Ghidra:

1. `public: __thiscall CallbackDispatcher::CallbackDispatcher(unsigned long)`
2. `public: __thiscall CallbackDispatcher::~CallbackDispatcher(void)`
3. `public: void __thiscall CallbackDispatcher::SetPriority(unsigned long)`
4. `public: void __thiscall CallbackDispatcher::RegisterTimeSliceCallback(unsigned long (__cdecl*)(unsigned long,unsigned long),unsigned long,long)`
5. `public: void __thiscall CallbackDispatcher::UnregisterTimeSliceCallback(void)`
6. `public: bool __thiscall CallbackDispatcher::Stop(unsigned long)`
7. `public: class Event * __thiscall CallbackDispatcher::CreateCallbackEvent(unsigned long (__cdecl*)(unsigned long,unsigned long),unsigned long)`
8. `public: void __thiscall CallbackDispatcher::DeleteCallbackEvent(class Event *)`
9. `public: void __thiscall CallbackDispatcher::CallInContext(unsigned long (__cdecl*)(unsigned long,unsigned long),unsigned long)`
10. `public: void __thiscall CallbackDispatcher::DispatcherThread(void *)`
11. `public: virtual __thiscall ObjectThread<class CallbackDispatcher,void *>::~ObjectThread<class CallbackDispatcher,void *>(void)`
12. `private: virtual void __thiscall ObjectThread<class CallbackDispatcher,void *>::CallObjectMethod(void)`
13. `public: virtual void * __thiscall ObjectThread<class CallbackDispatcher,void *>::`scalar deleting destructor'(unsigned int)`
