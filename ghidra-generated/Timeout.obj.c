#include <Platform/Time.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
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

typedef ulonglong __uint64;

typedef struct Timeout Timeout, *PTimeout;

struct Timeout { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;



TerminatedCString s_(m_oRTO_>=_0)_&&_(m_oRTO_<_10000;
TerminatedCString s_Timeout.cpp;

// public: __thiscall Timeout::Timeout(void)

Timeout * __thiscall Timeout::Timeout(Timeout *this)

{
  Time::Time((Time *)(this + 8));
  Time::Time((Time *)(this + 0x10));
  Time::operator=((Time *)(this + 8),0);
  Time::operator=((Time *)(this + 0x10),0);
  *(undefined4 *)this = 0;
  return this;
}



// public: __thiscall Timeout::~Timeout(void)

void __thiscall Timeout::~Timeout(Timeout *this)

{
  return;
}



// public: void __thiscall Timeout::SetExpirationTime(class Time)

void __thiscall Timeout::SetExpirationTime(Timeout *this)

{
  Time::operator=((Time *)(this + 0x10),(Time *)&stack0x00000004);
  return;
}



// public: void __thiscall Timeout::SetRelativeExpirationTime(long)

void __thiscall Timeout::SetRelativeExpirationTime(Timeout *this,long value)

{
  Time *this_00;
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 local_10 [16];
  
  puVar2 = local_10;
  this_00 = (Time *)Time::GetTime();
  puVar1 = (undefined4 *)Time::operator+(this_00,(long)puVar2);
  SetExpirationTime(this,*puVar1,puVar1[1]);
  return;
}



// WARNING: Removing unreachable block (ram,0x000023e8)
// public: bool __thiscall Timeout::IsExpired(void)

bool __thiscall Timeout::IsExpired(Timeout *this)

{
  bool bVar1;
  Time *pTVar2;
  __uint64 _Var3;
  __uint64 _Var4;
  Time local_10 [16];
  
  pTVar2 = (Time *)Time::Time(local_10,0);
  bVar1 = Time::operator>((Time *)(this + 0x10),pTVar2);
  if (bVar1) {
    pTVar2 = (Time *)Time::GetTime();
    _Var3 = Time::operator_unsigned___int64(pTVar2);
    _Var4 = Time::operator_unsigned___int64((Time *)(this + 0x10));
    if ((longlong)_Var4 < (longlong)_Var3) {
      return true;
    }
  }
  return false;
}



// WARNING: Removing unreachable block (ram,0x0000242e)
// public: bool __thiscall Timeout::IsAwaited(void)

bool __thiscall Timeout::IsAwaited(Timeout *this)

{
  Time *this_00;
  __uint64 _Var1;
  __uint64 _Var2;
  
  this_00 = (Time *)Time::GetTime();
  _Var1 = Time::operator_unsigned___int64(this_00);
  _Var2 = Time::operator_unsigned___int64((Time *)(this + 8));
  if ((longlong)_Var1 <= (longlong)_Var2) {
    return false;
  }
  return true;
}



// public: void __thiscall Timeout::SetRTO(unsigned long)

void __thiscall Timeout::SetRTO(Timeout *this,ulong ulValue)

{
  bool bVar1;
  
  *(ulong *)this = ulValue;
  if (((int)ulValue < 0) || (99999 < (int)ulValue)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  Platform::SystemCheck(bVar1,s__m_oRTO_>__0______m_oRTO_<_10000,s_Timeout_cpp,0x2f);
  return;
}



// public: void __thiscall Timeout::Start(void)

void __thiscall Timeout::Start(Timeout *this)

{
  Time *pTVar1;
  undefined1 *puVar2;
  undefined1 local_10 [16];
  
  puVar2 = local_10;
  pTVar1 = (Time *)Time::GetTime();
  pTVar1 = (Time *)Time::operator+(pTVar1,(long)puVar2);
  Time::operator=((Time *)(this + 8),pTVar1);
  return;
}



// WARNING: Removing unreachable block (ram,0x000024e3)
// public: bool __thiscall Timeout::operator<(class Timeout &)

bool __thiscall Timeout::operator<(Timeout *this,Timeout *pTimeout)

{
  __uint64 _Var1;
  __uint64 _Var2;
  
  _Var1 = Time::operator_unsigned___int64((Time *)(pTimeout + 8));
  _Var2 = Time::operator_unsigned___int64((Time *)(this + 8));
  if ((longlong)_Var1 <= (longlong)_Var2) {
    return false;
  }
  return true;
}



// public: unsigned long __thiscall Timeout::GetRTO(void)

ulong __thiscall Timeout::GetRTO(Timeout *this)

{
  return *(ulong *)this;
}



// public: class Time __thiscall Timeout::GetAwaitedTime(void)

void __thiscall Timeout::GetAwaitedTime(Timeout *this)

{
  undefined4 *in_stack_00000004;
  
  *in_stack_00000004 = *(undefined4 *)(this + 8);
  in_stack_00000004[1] = *(undefined4 *)(this + 0xc);
  return;
}


