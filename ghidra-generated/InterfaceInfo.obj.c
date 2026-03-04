#include <Platform/Trace.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
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

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct InterfaceInfo InterfaceInfo, *PInterfaceInfo;

struct InterfaceInfo { // PlaceHolder Structure
    ulong m_ulAddress;
    ulong m_ulBroadcastAddress;
    ulong m_ulMask;
    ulong m_ulFlags;
    char *m_szName;
};



TerminatedCString s_szName_!=_NULL;
TerminatedCString s_InterfaceInfo.cpp;
undefined __imp__inet_ntoa@4;
undefined __imp__strncpy;
undefined1 s_;
string s_BROADCAST_;
string s_LOOPBACK_;
string s_POINT2POINT;

// public: __thiscall InterfaceInfo::InterfaceInfo(void)

void __thiscall InterfaceInfo::InterfaceInfo(InterfaceInfo *this)

{
  this->m_ulAddress = 0;
  this->m_ulBroadcastAddress = 0;
  this->m_ulMask = 0;
  this->m_ulFlags = 0;
  this->m_szName = (char *)0x0;
  return;
}



// public: __thiscall InterfaceInfo::~InterfaceInfo(void)

void __thiscall InterfaceInfo::~InterfaceInfo(InterfaceInfo *this)

{
  if (this->m_szName != (char *)0x0) {
    operator_delete(this->m_szName);
    this->m_szName = (char *)0x0;
  }
  return;
}



// public: void __thiscall InterfaceInfo::SetAddress(unsigned long)

void __thiscall InterfaceInfo::SetAddress(InterfaceInfo *this,ulong ulValue)

{
  this->m_ulAddress = ulValue;
  return;
}



// public: void __thiscall InterfaceInfo::SetBroadcastAddress(unsigned long)

void __thiscall InterfaceInfo::SetBroadcastAddress(InterfaceInfo *this,ulong ulValue)

{
  this->m_ulBroadcastAddress = ulValue;
  return;
}



// public: void __thiscall InterfaceInfo::SetMask(unsigned long)

void __thiscall InterfaceInfo::SetMask(InterfaceInfo *this,ulong ulValue)

{
  this->m_ulMask = ulValue;
  return;
}



// public: void __thiscall InterfaceInfo::SetFlags(unsigned long)

void __thiscall InterfaceInfo::SetFlags(InterfaceInfo *this,ulong ulValue)

{
  this->m_ulFlags = ulValue;
  return;
}



// public: void __thiscall InterfaceInfo::SetName(char *)

void __thiscall InterfaceInfo::SetName(InterfaceInfo *this,char *szText)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  Platform::SystemCheck(szText != (char *)0x0,s_szName____NULL,s_InterfaceInfo_cpp,0x36);
  uVar3 = 0xffffffff;
  pcVar2 = szText;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = operator_new(~uVar3);
  uVar3 = 0xffffffff;
  this->m_szName = pcVar2;
  do {
    pcVar5 = szText;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = szText + 1;
    cVar1 = *szText;
    szText = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// private: bool __thiscall InterfaceInfo::Addr2Str(unsigned long,char *,unsigned long)

bool __thiscall
InterfaceInfo::Addr2Str(InterfaceInfo *this,ulong ulValue,char *szText,ulong ulValue2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  pcVar2 = (char *)(*___imp__inet_ntoa_4)(ulValue);
  uVar3 = 0xffffffff;
  pcVar4 = pcVar2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((char *)(~uVar3 - 1) < szText) {
    StringConversion::A2T(pcVar2,(char *)ulValue,(uint)szText);
    return true;
  }
  return false;
}



// public: bool __thiscall InterfaceInfo::GetAddress(char *,unsigned long)

bool __thiscall InterfaceInfo::GetAddress(InterfaceInfo *this,char *szText,ulong ulValue)

{
  bool bVar1;
  
  bVar1 = Addr2Str(this,this->m_ulAddress,szText,ulValue);
  return bVar1;
}



// public: bool __thiscall InterfaceInfo::GetBroadcastAddress(char *,unsigned long)

bool __thiscall InterfaceInfo::GetBroadcastAddress(InterfaceInfo *this,char *szText,ulong ulValue)

{
  bool bVar1;
  
  bVar1 = Addr2Str(this,this->m_ulBroadcastAddress,szText,ulValue);
  return bVar1;
}



// public: bool __thiscall InterfaceInfo::GetMask(char *,unsigned long)

bool __thiscall InterfaceInfo::GetMask(InterfaceInfo *this,char *szText,ulong ulValue)

{
  bool bVar1;
  
  bVar1 = Addr2Str(this,this->m_ulMask,szText,ulValue);
  return bVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall InterfaceInfo::GetName(char *,unsigned long)

bool __thiscall InterfaceInfo::GetName(InterfaceInfo *this,char *szText,ulong ulValue)

{
  if (this->m_szName == (char *)0x0) {
    return false;
  }
  (*___imp__strncpy)(szText,this->m_szName,ulValue);
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall InterfaceInfo::GetFlags(char *,unsigned long)

bool __thiscall InterfaceInfo::GetFlags(InterfaceInfo *this,char *szText,ulong ulValue)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  char local_200;
  undefined4 local_1ff;
  
  local_200 = s_;
  puVar7 = &local_1ff;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar5 = this->m_ulFlags;
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  if ((uVar5 & 1) != 0) {
    uVar3 = 0xffffffff;
    pcVar6 = s_POINT2POINT;
    do {
      pcVar9 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar6 = &local_200;
    do {
      pcVar8 = pcVar6;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uVar3;
    pcVar9 = pcVar8 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  if ((uVar5 & 4) != 0) {
    uVar3 = 0xffffffff;
    pcVar6 = s_LOOPBACK_;
    do {
      pcVar9 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar6 = &local_200;
    do {
      pcVar8 = pcVar6;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uVar3;
    pcVar9 = pcVar8 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  if ((uVar5 & 2) != 0) {
    uVar5 = 0xffffffff;
    pcVar6 = s_BROADCAST_;
    do {
      pcVar9 = pcVar6;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar2 = -1;
    pcVar6 = &local_200;
    do {
      pcVar8 = pcVar6;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uVar5;
    pcVar9 = pcVar8 + -1;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  (*___imp__strncpy)(szText,&local_200,ulValue);
  return true;
}



// public: unsigned long __thiscall InterfaceInfo::GetAddress(void)

ulong __thiscall InterfaceInfo::GetAddress(InterfaceInfo *this)

{
  return this->m_ulAddress;
}



// public: unsigned long __thiscall InterfaceInfo::GetBroadcastAddress(void)

ulong __thiscall InterfaceInfo::GetBroadcastAddress(InterfaceInfo *this)

{
  return this->m_ulBroadcastAddress;
}



// public: unsigned long __thiscall InterfaceInfo::GetMask(void)

ulong __thiscall InterfaceInfo::GetMask(InterfaceInfo *this)

{
  return this->m_ulMask;
}



// public: unsigned long __thiscall InterfaceInfo::GetFlags(void)

ulong __thiscall InterfaceInfo::GetFlags(InterfaceInfo *this)

{
  return this->m_ulFlags;
}



// public: char * __thiscall InterfaceInfo::GetName(void)

char * __thiscall InterfaceInfo::GetName(InterfaceInfo *this)

{
  return this->m_szName;
}



// public: void __thiscall InterfaceInfo::Trace(unsigned long)

void __thiscall InterfaceInfo::Trace(InterfaceInfo *this,ulong ulValue)

{
  bool bVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  TraceOutput *this_01;
  TraceOutput *this_02;
  TraceOutput *this_03;
  TraceOutput *this_04;
  TraceOutput *this_05;
  char *pcVar3;
  char local_78 [8];
  char local_70 [112];
  
  pcVar3 = (char *)ulValue;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
  bVar1 = GetName(this,local_78,0x80);
  if (bVar1) {
    pcVar3 = (char *)ulValue;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar3);
  }
  bVar1 = GetAddress(this,local_70,0x80);
  if (bVar1) {
    pcVar3 = (char *)ulValue;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar3);
  }
  bVar1 = GetBroadcastAddress(this,local_70,0x80);
  if (bVar1) {
    pcVar3 = (char *)ulValue;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_03,(ulong)pTVar2,pcVar3);
  }
  bVar1 = GetMask(this,local_70,0x80);
  if (bVar1) {
    pcVar3 = (char *)ulValue;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_04,(ulong)pTVar2,pcVar3);
  }
  bVar1 = GetFlags(this,local_70,0x80);
  if (bVar1) {
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_05,(ulong)pTVar2,(char *)ulValue);
  }
  return;
}


