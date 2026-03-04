typedef unsigned char   undefined;

typedef struct Event Event, *PEvent;

struct Event { // PlaceHolder Structure
};

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

struct _OVERLAPPED { // PlaceHolder Structure
};

typedef struct AsyncIOContext AsyncIOContext, *PAsyncIOContext;

struct AsyncIOContext { // PlaceHolder Structure
};




// public: __thiscall AsyncIOContext::AsyncIOContext(void)

void __thiscall AsyncIOContext::AsyncIOContext(AsyncIOContext *this)

{
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}



// public: void __thiscall AsyncIOContext::SetEvent(class Event *)

void __thiscall AsyncIOContext::SetEvent(AsyncIOContext *this,Event *param_1)

{
  void *pvVar1;
  
  pvVar1 = Event::GetPlatformSpecificEvent(param_1);
  *(Event **)(this + 0x14) = param_1;
  *(void **)(this + 0x10) = pvVar1;
  return;
}



// public: class Event * __thiscall AsyncIOContext::GetEvent(void)

Event * __thiscall AsyncIOContext::GetEvent(AsyncIOContext *this)

{
  return *(Event **)(this + 0x14);
}



// public: void __thiscall AsyncIOContext::SignalEvent(void)

void __thiscall AsyncIOContext::SignalEvent(AsyncIOContext *this)

{
  if (*(Event **)(this + 0x14) != (Event *)0x0) {
    Event::Set(*(Event **)(this + 0x14));
    return;
  }
  return;
}



// public: void __thiscall AsyncIOContext::ResetEvent(void)

void __thiscall AsyncIOContext::ResetEvent(AsyncIOContext *this)

{
  if (*(Event **)(this + 0x14) != (Event *)0x0) {
    Event::Reset(*(Event **)(this + 0x14));
    return;
  }
  return;
}



// public: void __thiscall AsyncIOContext::SetIOSize(unsigned long)

void __thiscall AsyncIOContext::SetIOSize(AsyncIOContext *this,unsigned long param_1)

{
  *(unsigned long *)(this + 0x18) = param_1;
  return;
}



// public: unsigned long __thiscall AsyncIOContext::GetIOSize(void)

unsigned long __thiscall AsyncIOContext::GetIOSize(AsyncIOContext *this)

{
  return *(unsigned long *)(this + 0x18);
}



// public: unsigned long __thiscall AsyncIOContext::GetReturnCode(void)

unsigned long __thiscall AsyncIOContext::GetReturnCode(AsyncIOContext *this)

{
  return *(unsigned long *)(this + 0x1c);
}



// public: void __thiscall AsyncIOContext::SetReturnCode(unsigned long)

void __thiscall AsyncIOContext::SetReturnCode(AsyncIOContext *this,unsigned long param_1)

{
  *(unsigned long *)(this + 0x1c) = param_1;
  return;
}



// public: struct _OVERLAPPED * __thiscall AsyncIOContext::GetOverlapped(void)

_OVERLAPPED * __thiscall AsyncIOContext::GetOverlapped(AsyncIOContext *this)

{
  return (_OVERLAPPED *)this;
}


