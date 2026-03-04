typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct CoffFileHeader CoffFileHeader, *PCoffFileHeader;

struct CoffFileHeader {
    word f_magic;
    word f_nscns;
    dword f_timdat;
    dword f_symptr;
    dword f_nsyms;
    word f_opthdr;
    word f_flags;
};

typedef struct CoffSectionHeader CoffSectionHeader, *PCoffSectionHeader;

struct CoffSectionHeader {
    char s_name[8];
    dword s_paddr;
    dword s_vaddr;
    dword s_size;
    dword s_scnptr;
    dword s_relptr;
    dword s_lnnoptr;
    word s_nreloc;
    word s_nlnno;
    dword s_flags;
};

typedef struct CriticalSection CriticalSection, *PCriticalSection;

struct CriticalSection { // PlaceHolder Structure
};

typedef struct CallbackDispatcher CallbackDispatcher, *PCallbackDispatcher;

struct CallbackDispatcher { // PlaceHolder Structure
};

typedef struct Event Event, *PEvent;

struct Event { // PlaceHolder Structure
};

typedef struct ObjectThreadRoot ObjectThreadRoot, *PObjectThreadRoot;

struct ObjectThreadRoot { // PlaceHolder Structure
};

typedef struct EventHandler EventHandler, *PEventHandler;

struct EventHandler { // PlaceHolder Structure
};

typedef struct ObjectThread<class_CallbackDispatcher,void*> ObjectThread<class_CallbackDispatcher,void*>, *PObjectThread<class_CallbackDispatcher,void*>;

struct ObjectThread<class_CallbackDispatcher,void*> { // PlaceHolder Structure
};

typedef struct ScopedCS ScopedCS, *PScopedCS;

struct ScopedCS { // PlaceHolder Structure
};



undefined LAB_00002c29;
TerminatedCString s_false;
TerminatedCString s_CallbackDispatcher.cpp;
TerminatedCString s_CallbackDispatcher;
undefined DispatcherThread;
pointer `vftable';
undefined __except_list;
undefined LAB_00002c53;
TerminatedCString s_pCallback!=NULL;
TerminatedCString s_pEvent!=NULL;
undefined LAB_00002c68;
TerminatedCString s_m_pfCallback!=NULL;
TerminatedCString s_<unspecified>;
TerminatedCString s_ISGOODPTR(pCallback);
ulong ulNbCallbackCalled;

// public: __thiscall CallbackDispatcher::CallbackDispatcher(unsigned long)

CallbackDispatcher * __thiscall
CallbackDispatcher::CallbackDispatcher(CallbackDispatcher *this,ulong param_1)

{
  bool bVar1;
  EventHandler *pEVar2;
  Event *pEVar3;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L1481;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ObjectThreadRoot::ObjectThreadRoot((ObjectThreadRoot *)this,s_CallbackDispatcher);
  *(undefined ***)this = &ObjectThread<>::_vftable_;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  local_4 = 0;
  CriticalSection::CriticalSection((CriticalSection *)(this + 0x3c));
  local_4._0_1_ = 1;
  this[0x48] = (CallbackDispatcher)0x0;
  *(ulong *)(this + 0x24) = param_1;
  pEVar2 = operator_new(0x14);
  local_4._0_1_ = 2;
  if (pEVar2 == (EventHandler *)0x0) {
    pEVar2 = (EventHandler *)0x0;
  }
  else {
    pEVar2 = (EventHandler *)EventHandler::EventHandler(pEVar2,10);
  }
  local_4._0_1_ = 1;
  *(EventHandler **)(this + 0x28) = pEVar2;
  pEVar3 = EventHandler::CreateEventObject(pEVar2,0,0);
  *(Event **)(this + 0x2c) = pEVar3;
  pEVar3 = EventHandler::CreateEventObject(*(EventHandler **)(this + 0x28),1,0);
  *(Event **)(this + 0x30) = pEVar3;
  pEVar2 = operator_new(0x14);
  local_4._0_1_ = 3;
  if (pEVar2 == (EventHandler *)0x0) {
    pEVar2 = (EventHandler *)0x0;
  }
  else {
    pEVar2 = (EventHandler *)EventHandler::EventHandler(pEVar2,1);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  *(EventHandler **)(this + 0x34) = pEVar2;
  pEVar3 = EventHandler::CreateEventObject(pEVar2,2,0);
  *(Event **)(this + 0x38) = pEVar3;
  *(undefined4 *)(this + 0x40) = 0;
  *(CallbackDispatcher **)(this + 0x14) = this;
  *(code **)(this + 0x18) = DispatcherThread;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0x20] = (CallbackDispatcher)0x1;
  bVar1 = ObjectThreadRoot::Launch((ObjectThreadRoot *)this);
  if (!bVar1) {
    Platform::SystemCheck(false,s_false,s_CallbackDispatcher_cpp,0x3b);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: __thiscall CallbackDispatcher::~CallbackDispatcher(void)

void __thiscall CallbackDispatcher::~CallbackDispatcher(CallbackDispatcher *this)

{
  EventHandler *pEVar1;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &_L1513;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_4 = 1;
  UnregisterTimeSliceCallback(this);
  Stop(this,5000);
  EventHandler::DeleteEventObject(*(EventHandler **)(this + 0x28),*(Event **)(this + 0x30));
  EventHandler::DeleteEventObject(*(EventHandler **)(this + 0x28),*(Event **)(this + 0x2c));
  EventHandler::DeleteEventObject(*(EventHandler **)(this + 0x34),*(Event **)(this + 0x38));
  pEVar1 = *(EventHandler **)(this + 0x28);
  if (pEVar1 != (EventHandler *)0x0) {
    EventHandler::~EventHandler(pEVar1);
    operator_delete(pEVar1);
  }
  pEVar1 = *(EventHandler **)(this + 0x34);
  if (pEVar1 != (EventHandler *)0x0) {
    EventHandler::~EventHandler(pEVar1);
    operator_delete(pEVar1);
  }
  local_4 = local_4 & 0xffffff00;
  CriticalSection::~CriticalSection((CriticalSection *)(this + 0x3c));
  local_4 = 0xffffffff;
  *(undefined ***)this = &ObjectThread<>::_vftable_;
  ObjectThreadRoot::~ObjectThreadRoot((ObjectThreadRoot *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall CallbackDispatcher::SetPriority(unsigned long)

void __thiscall CallbackDispatcher::SetPriority(CallbackDispatcher *this,ulong param_1)

{
  ObjectThreadRoot::SetPriority((ObjectThreadRoot *)this,param_1);
  return;
}



// public: void __thiscall CallbackDispatcher::RegisterTimeSliceCallback(unsigned long
// (__cdecl*)(unsigned long,unsigned long),unsigned long,long)

void __thiscall
CallbackDispatcher::RegisterTimeSliceCallback
          (CallbackDispatcher *this,_func_ulong_ulong_ulong *param_1,ulong param_2,long param_3)

{
  ulong *puVar1;
  
  if (*(void **)(this + 0x40) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x40));
    *(undefined4 *)(this + 0x40) = 0;
  }
  puVar1 = operator_new(8);
  if (puVar1 == (ulong *)0x0) {
    puVar1 = (ulong *)0x0;
  }
  else {
    puVar1[1] = (ulong)param_1;
    *puVar1 = param_2;
  }
  *(ulong **)(this + 0x40) = puVar1;
  *(long *)(this + 0x44) = param_3;
  Event::Set(*(Event **)(this + 0x2c));
  return;
}



// public: void __thiscall CallbackDispatcher::UnregisterTimeSliceCallback(void)

void __thiscall CallbackDispatcher::UnregisterTimeSliceCallback(CallbackDispatcher *this)

{
  if (*(void **)(this + 0x40) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x40));
    *(undefined4 *)(this + 0x40) = 0;
  }
  return;
}



// public: bool __thiscall CallbackDispatcher::Stop(unsigned long)

bool __thiscall CallbackDispatcher::Stop(CallbackDispatcher *this,ulong param_1)

{
  bool bVar1;
  
  if (this[0x10] != (CallbackDispatcher)0x0) {
    this[0x48] = (CallbackDispatcher)0x1;
    Event::Set(*(Event **)(this + 0x2c));
    bVar1 = ObjectThreadRoot::Wait((ObjectThreadRoot *)this,param_1);
    return bVar1;
  }
  return true;
}



// public: class Event * __thiscall CallbackDispatcher::CreateCallbackEvent(unsigned long
// (__cdecl*)(unsigned long,unsigned long),unsigned long)

Event * __thiscall
CallbackDispatcher::CreateCallbackEvent
          (CallbackDispatcher *this,_func_ulong_ulong_ulong *param_1,ulong param_2)

{
  ulong *puVar1;
  Event *pEVar2;
  
  puVar1 = operator_new(8);
  if (puVar1 != (ulong *)0x0) {
    puVar1[1] = (ulong)param_1;
    *puVar1 = param_2;
    pEVar2 = EventHandler::CreateEventObject(*(EventHandler **)(this + 0x28),1,(ulong)puVar1);
    return pEVar2;
  }
  pEVar2 = EventHandler::CreateEventObject(*(EventHandler **)(this + 0x28),1,0);
  return pEVar2;
}



// public: void __thiscall CallbackDispatcher::DeleteCallbackEvent(class Event *)

void __thiscall CallbackDispatcher::DeleteCallbackEvent(CallbackDispatcher *this,Event *param_1)

{
  void *pvVar1;
  
  Platform::SystemCheck(param_1 != (Event *)0x0,s_pEvent__NULL,s_CallbackDispatcher_cpp,0x7c);
  pvVar1 = (void *)Event::GetContext(param_1);
  EventHandler::DeleteEventObject(*(EventHandler **)(this + 0x28),param_1);
  Platform::SystemCheck(pvVar1 != (void *)0x0,s_pCallback__NULL,s_CallbackDispatcher_cpp,0x7f);
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  return;
}



// public: void __thiscall CallbackDispatcher::CallInContext(unsigned long (__cdecl*)(unsigned
// long,unsigned long),unsigned long)

void __thiscall
CallbackDispatcher::CallInContext
          (CallbackDispatcher *this,_func_ulong_ulong_ulong *param_1,ulong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong *puVar3;
  uint uVar4;
  int unaff_FS_OFFSET;
  CallbackDispatcher *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L1622;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_10 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_10,(CriticalSection *)(this + 0x3c),s_<unspecified>);
  local_4 = 0;
  puVar3 = operator_new(8);
  if (puVar3 == (ulong *)0x0) {
    puVar3 = (ulong *)0x0;
  }
  else {
    puVar3[1] = (ulong)param_1;
    *puVar3 = param_2;
  }
  uVar1 = *(uint *)(this + 0xc);
  uVar4 = ObjectThreadRoot::GetCurrentThreadID();
  if (uVar4 == uVar1) {
    uVar2 = *(undefined4 *)(this + 0x24);
    Platform::SystemCheck(puVar3[1] != 0,s_m_pfCallback__NULL,s_CallbackDispatcher_cpp,0x22);
    (*(code *)puVar3[1])(uVar2,*puVar3);
  }
  else {
    Event::Reset(*(Event **)(this + 0x38));
    Event::SetContext(*(Event **)(this + 0x30),(ulong)puVar3);
    Event::Set(*(Event **)(this + 0x30));
    param_1 = (_func_ulong_ulong_ulong *)0x0;
    EventHandler::WaitForEvent(*(EventHandler **)(this + 0x34),0xffffffff,(Event **)&param_1);
  }
  if (puVar3 != (ulong *)0x0) {
    operator_delete(puVar3);
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS((ScopedCS *)&local_10);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// public: void __thiscall CallbackDispatcher::DispatcherThread(void *)

void __thiscall CallbackDispatcher::DispatcherThread(CallbackDispatcher *this,void *param_1)

{
  CallbackDispatcher CVar1;
  undefined4 uVar2;
  bool bVar3;
  ulong uVar4;
  undefined4 *puVar5;
  Event *local_4;
  
  local_4 = (Event *)0x0;
  CVar1 = this[0x48];
  do {
    if (CVar1 != (CallbackDispatcher)0x0) {
      Event::Set(*(Event **)(this + 0x38));
      return;
    }
    local_4 = (Event *)0x0;
    if (*(int *)(this + 0x40) == 0) {
      bVar3 = EventHandler::WaitForEvent(*(EventHandler **)(this + 0x28),0xffffffff,&local_4);
      if (bVar3) {
LAB_000029b5:
        SystemError::TraceLast(1);
      }
    }
    else {
      bVar3 = EventHandler::WaitForEvent
                        (*(EventHandler **)(this + 0x28),*(ulong *)(this + 0x44),&local_4);
      if (!bVar3) {
        uVar4 = SystemError::GetLast();
        if (uVar4 == 0) goto LAB_000029b5;
        puVar5 = *(undefined4 **)(this + 0x40);
        uVar2 = *(undefined4 *)(this + 0x24);
        Platform::SystemCheck(puVar5[1] != 0,s_m_pfCallback__NULL,s_CallbackDispatcher_cpp,0x22);
        (*(code *)puVar5[1])(uVar2,*puVar5);
      }
    }
    if (local_4 != (Event *)0x0) {
      Event::Reset(local_4);
      uVar4 = Event::GetType(local_4);
      if (uVar4 != 0) {
        if (uVar4 == 1) {
          puVar5 = (undefined4 *)Event::GetContext(local_4);
          Platform::SystemCheck(true,s_ISGOODPTR_pCallback_,s_CallbackDispatcher_cpp,0xb1);
          uVar2 = *(undefined4 *)(this + 0x24);
          Platform::SystemCheck(puVar5[1] != 0,s_m_pfCallback__NULL,s_CallbackDispatcher_cpp,0x22);
          (*(code *)puVar5[1])(uVar2,*puVar5);
          if (local_4 == *(Event **)(this + 0x30)) {
            Event::Set(*(Event **)(this + 0x38));
          }
        }
        else {
          Platform::SystemCheck(false,s_false,s_CallbackDispatcher_cpp,0xbb);
        }
      }
    }
    CVar1 = this[0x48];
  } while( true );
}



// unsigned long __cdecl CallbackDispatcherTest::Callback1(unsigned long,unsigned long)

ulong __cdecl CallbackDispatcherTest::Callback1(ulong param_1,ulong param_2)

{
  ulNbCallbackCalled = ulNbCallbackCalled + 1;
  return 0;
}



// unsigned long __cdecl CallbackDispatcherTest::Callback2(unsigned long,unsigned long)

ulong __cdecl CallbackDispatcherTest::Callback2(ulong param_1,ulong param_2)

{
  ulNbCallbackCalled = ulNbCallbackCalled + 1;
  return 0;
}



// public: virtual __thiscall ObjectThread<class CallbackDispatcher,void *>::~ObjectThread<class
// CallbackDispatcher,void *>(void)

void __thiscall ObjectThread<>::~ObjectThread<>(ObjectThread<> *this)

{
  *(undefined ***)this = &_vftable_;
  ObjectThreadRoot::~ObjectThreadRoot((ObjectThreadRoot *)this);
  return;
}



// private: virtual void __thiscall ObjectThread<class CallbackDispatcher,void
// *>::CallObjectMethod(void)

void __thiscall ObjectThread<>::CallObjectMethod(ObjectThread<> *this)

{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = *(undefined4 *)(this + 0x1c);
  pcVar2 = *(code **)(this + 0x18);
  ObjectThreadRoot::ReadyToRun((ObjectThreadRoot *)this);
  (*pcVar2)(uVar1);
  return;
}



// public: virtual void * __thiscall ObjectThread<class CallbackDispatcher,void *>::`scalar deleting
// destructor'(unsigned int)

void * __thiscall ObjectThread<>::_scalar_deleting_destructor_(ObjectThread<> *this,uint param_1)

{
  ~ObjectThread<>(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}


