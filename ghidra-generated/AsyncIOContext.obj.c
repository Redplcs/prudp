#include <Platform/Event.h>

typedef unsigned char   undefined;

typedef unsigned int    dword;
typedef unsigned long    ulong;
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

typedef struct Event Event, *PEvent;

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

struct _OVERLAPPED { // PlaceHolder Structure
};

typedef struct AsyncIOContext AsyncIOContext, *PAsyncIOContext;

struct AsyncIOContext { // PlaceHolder Structure
    undefined m_abyOverlapped[0x10];
    void *m_pPlatformSpecificEvent;
    Event *m_pEvent;
    ulong m_ulIOSize;
    ulong m_ulReturnCode;
};




// public: __thiscall AsyncIOContext::AsyncIOContext(void)

void __thiscall AsyncIOContext::AsyncIOContext(AsyncIOContext *this)

{
  this->m_ulIOSize = 0;
  this->m_ulReturnCode = 0;
  this->m_pEvent = (Event *)0x0;
  return;
}



// public: void __thiscall AsyncIOContext::SetEvent(class Event *)

void __thiscall AsyncIOContext::SetEvent(AsyncIOContext *this,Event *pEvent)

{
  void *pvVar1;
  
  pvVar1 = Event::GetPlatformSpecificEvent(pEvent);
  this->m_pEvent = pEvent;
  this->m_pPlatformSpecificEvent = pvVar1;
  return;
}



// public: class Event * __thiscall AsyncIOContext::GetEvent(void)

Event * __thiscall AsyncIOContext::GetEvent(AsyncIOContext *this)

{
  return this->m_pEvent;
}



// public: void __thiscall AsyncIOContext::SignalEvent(void)

void __thiscall AsyncIOContext::SignalEvent(AsyncIOContext *this)

{
  if (this->m_pEvent != (Event *)0x0) {
    Event::Set(this->m_pEvent);
    return;
  }
  return;
}



// public: void __thiscall AsyncIOContext::ResetEvent(void)

void __thiscall AsyncIOContext::ResetEvent(AsyncIOContext *this)

{
  if (this->m_pEvent != (Event *)0x0) {
    Event::Reset(this->m_pEvent);
    return;
  }
  return;
}



// public: void __thiscall AsyncIOContext::SetIOSize(unsigned long)

void __thiscall AsyncIOContext::SetIOSize(AsyncIOContext *this,ulong ulValue)

{
  this->m_ulIOSize = ulValue;
  return;
}



// public: unsigned long __thiscall AsyncIOContext::GetIOSize(void)

ulong __thiscall AsyncIOContext::GetIOSize(AsyncIOContext *this)

{
  return this->m_ulIOSize;
}



// public: unsigned long __thiscall AsyncIOContext::GetReturnCode(void)

ulong __thiscall AsyncIOContext::GetReturnCode(AsyncIOContext *this)

{
  return this->m_ulReturnCode;
}



// public: void __thiscall AsyncIOContext::SetReturnCode(unsigned long)

void __thiscall AsyncIOContext::SetReturnCode(AsyncIOContext *this,ulong ulValue)

{
  this->m_ulReturnCode = ulValue;
  return;
}



// public: struct _OVERLAPPED * __thiscall AsyncIOContext::GetOverlapped(void)

_OVERLAPPED * __thiscall AsyncIOContext::GetOverlapped(AsyncIOContext *this)

{
  return (_OVERLAPPED *)this->m_abyOverlapped;
}


