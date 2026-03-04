#include <Platform/Trace.h>
#include <Plugins/Transport/Interface/StationURL.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef long long    longlong;
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

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct sockaddr sockaddr, *Psockaddr;

struct sockaddr { // PlaceHolder Structure
};

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct StationURL StationURL, *PStationURL;



undefined __imp__atoi;
TerminatedCString s_port;
TerminatedCString s_address;
TerminatedCString s_%d;
TerminatedCString s_%s;
undefined __imp__ntohs@4;
undefined __imp__sprintf;
undefined __imp__inet_ntoa@4;
undefined __imp__gethostbyname@4;
undefined __imp__inet_addr@4;
undefined __imp__htonl@4;
undefined __imp__ntohl@4;
undefined __imp__htons@4;
undefined LAB_00002b08;
undefined __except_list;
undefined LAB_00002b28;
TerminatedCString s_%s:%d;

// public: __thiscall PRUDPInetAddress::PRUDPInetAddress(void)

PRUDPInetAddress * __thiscall PRUDPInetAddress::PRUDPInetAddress(PRUDPInetAddress *this)

{
  undefined2 *puVar1;
  
  puVar1 = operator_new(0x10);
  *(undefined2 **)this = puVar1;
  *puVar1 = 2;
  *(undefined4 *)(*(int *)this + 4) = 0;
  *(undefined2 *)(*(int *)this + 2) = 0;
  return this;
}



// public: __thiscall PRUDPInetAddress::PRUDPInetAddress(class PRUDPInetAddress *)

PRUDPInetAddress * __thiscall
PRUDPInetAddress::PRUDPInetAddress(PRUDPInetAddress *this,PRUDPInetAddress *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = operator_new(0x10);
  *(undefined4 **)this = puVar2;
  puVar1 = *(undefined4 **)param_1;
  *puVar2 = *puVar1;
  puVar2[1] = puVar1[1];
  puVar2[2] = puVar1[2];
  puVar2[3] = puVar1[3];
  return this;
}



// public: __thiscall PRUDPInetAddress::PRUDPInetAddress(class PRUDPInetAddress &)

PRUDPInetAddress * __thiscall
PRUDPInetAddress::PRUDPInetAddress(PRUDPInetAddress *this,PRUDPInetAddress *param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x10);
  *(void **)this = pvVar1;
  operator=(this,param_1);
  return this;
}



// public: __thiscall PRUDPInetAddress::PRUDPInetAddress(unsigned long,unsigned short)

PRUDPInetAddress * __thiscall
PRUDPInetAddress::PRUDPInetAddress(PRUDPInetAddress *this,ulong param_1,ushort param_2)

{
  undefined2 *puVar1;
  
  puVar1 = operator_new(0x10);
  *(undefined2 **)this = puVar1;
  *puVar1 = 2;
  SetAddress(this,param_1);
  SetPortNumber(this,param_2);
  return this;
}



// public: __thiscall PRUDPInetAddress::~PRUDPInetAddress(void)

void __thiscall PRUDPInetAddress::~PRUDPInetAddress(PRUDPInetAddress *this)

{
  operator_delete(*(void **)this);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall PRUDPInetAddress::SetFromURL(class StationURL *,unsigned short)

bool __thiscall
PRUDPInetAddress::SetFromURL(PRUDPInetAddress *this,StationURL *param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  ulong uVar3;
  char local_90 [16];
  char local_80 [128];
  
  uVar3 = StationURL::GetParamValue(param_1,s_address,local_80,0x80,false);
  if (uVar3 != 0) {
    return false;
  }
  bVar1 = SetAddress(this,local_80);
  if (!bVar1) {
    return false;
  }
  uVar3 = StationURL::GetParamValue(param_1,s_port,local_90,0x10,false);
  if (uVar3 == 0) {
    uVar2 = (*___imp__atoi)(local_90);
    SetPortNumber(this,uVar2);
    return true;
  }
  SetPortNumber(this,param_2);
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall PRUDPInetAddress::GetURL(class StationURL *)

bool __thiscall PRUDPInetAddress::GetURL(PRUDPInetAddress *this,StationURL *param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  char *pcVar3;
  undefined2 extraout_var;
  StationURL *unaff_retaddr;
  char acStack_84 [132];
  
  pcVar3 = (char *)(*___imp__inet_ntoa_4)(*(undefined4 *)(*(int *)this + 4));
  StringConversion::A2T(pcVar3,acStack_84,0x80);
  pcVar1 = ___imp__sprintf;
  (*___imp__sprintf)(acStack_84,s__s,acStack_84);
  StationURL::AddParam(unaff_retaddr,s_address,acStack_84,false);
  uVar2 = (*___imp__ntohs_4)(CONCAT22(extraout_var,*(undefined2 *)(*(int *)this + 2)));
  (*pcVar1)(&stack0xffffff68,s__d,uVar2);
  StationURL::AddParam(unaff_retaddr,s_port,&stack0xffffff68,false);
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall PRUDPInetAddress::SetAddress(char *)

bool __thiscall PRUDPInetAddress::SetAddress(PRUDPInetAddress *this,char *param_1)

{
  int iVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  TraceOutput *this_01;
  TraceOutput *this_02;
  char *pcVar3;
  char local_100 [4];
  undefined1 auStack_fc [252];
  
  **(undefined2 **)this = 2;
  StringConversion::T2A(param_1,local_100,0x100);
  iVar1 = (*___imp__inet_addr_4)(local_100);
  if (iVar1 != -1) {
    pcVar3 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar3);
    *(int *)(*(int *)this + 4) = iVar1;
    return true;
  }
  pcVar3 = (char *)0x0;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
  pcVar3 = (char *)(*___imp__gethostbyname_4)(auStack_fc);
  if (pcVar3 == (char *)0x0) {
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar3);
    return false;
  }
  SetAddress(this,(void *)**(undefined4 **)(pcVar3 + 0xc));
  return true;
}



// public: struct sockaddr * __thiscall PRUDPInetAddress::GetSockAddr(void)

sockaddr * __thiscall PRUDPInetAddress::GetSockAddr(PRUDPInetAddress *this)

{
  return *(sockaddr **)this;
}



// private: void __thiscall PRUDPInetAddress::SetAddress(void *)

void __thiscall PRUDPInetAddress::SetAddress(PRUDPInetAddress *this,void *param_1)

{
  *(undefined4 *)(*(int *)this + 4) = *(undefined4 *)param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall PRUDPInetAddress::SetAddress(unsigned long)

void __thiscall PRUDPInetAddress::SetAddress(PRUDPInetAddress *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*___imp__htonl_4)(param_1);
  *(undefined4 *)(*(int *)this + 4) = uVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: unsigned long __thiscall PRUDPInetAddress::GetAddress(void)

ulong __thiscall PRUDPInetAddress::GetAddress(PRUDPInetAddress *this)

{
  ulong uVar1;
  
  uVar1 = (*___imp__ntohl_4)(*(undefined4 *)(*(int *)this + 4));
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall PRUDPInetAddress::SetPortNumber(unsigned short)

void __thiscall PRUDPInetAddress::SetPortNumber(PRUDPInetAddress *this,ushort param_1)

{
  undefined2 uVar1;
  undefined2 in_stack_00000006;
  
  uVar1 = (*___imp__htons_4)(_param_1);
  *(undefined2 *)(*(int *)this + 2) = uVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: unsigned short __thiscall PRUDPInetAddress::GetPort(void)

ushort __thiscall PRUDPInetAddress::GetPort(PRUDPInetAddress *this)

{
  ushort uVar1;
  
  uVar1 = (*___imp__ntohs_4)(*(undefined2 *)(*(int *)this + 2));
  return uVar1;
}



// public: __int64 __thiscall PRUDPInetAddress::GetKey(void)

__int64 __thiscall PRUDPInetAddress::GetKey(PRUDPInetAddress *this)

{
  return CONCAT44(*(undefined4 *)(*(int *)this + 4),(uint)*(ushort *)(*(int *)this + 2));
}



// public: bool __thiscall PRUDPInetAddress::operator<(class PRUDPInetAddress)const 

bool __thiscall
PRUDPInetAddress::operator<
          (PRUDPInetAddress *this,undefined4 param_2,undefined4 param_3,int param_4)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  bool bVar2;
  int unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  puStack_8 = &_L52962;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  bVar2 = false;
  pcVar3 = (char *)0x0;
  local_4 = 0;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,pcVar3);
  if ((*(uint *)(*(int *)this + 4) <= *(uint *)(param_4 + 4)) &&
     (*(ushort *)(*(int *)this + 2) < *(ushort *)(param_4 + 2))) {
    bVar2 = true;
  }
  ~PRUDPInetAddress((PRUDPInetAddress *)&param_4);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return bVar2;
}



// public: bool __thiscall PRUDPInetAddress::operator==(class PRUDPInetAddress)const 

bool __thiscall
PRUDPInetAddress::operator==
          (PRUDPInetAddress *this,undefined4 param_2,undefined4 param_3,int param_4)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  bool bVar2;
  int unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  puStack_8 = &_L52976;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  bVar2 = false;
  pcVar3 = (char *)0x0;
  local_4 = 0;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,pcVar3);
  if ((*(int *)(*(int *)this + 4) == *(int *)(param_4 + 4)) &&
     (*(short *)(*(int *)this + 2) == *(short *)(param_4 + 2))) {
    bVar2 = true;
  }
  ~PRUDPInetAddress((PRUDPInetAddress *)&param_4);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return bVar2;
}



// public: class PRUDPInetAddress & __thiscall PRUDPInetAddress::operator=(class PRUDPInetAddress &)

PRUDPInetAddress * __thiscall
PRUDPInetAddress::operator=(PRUDPInetAddress *this,PRUDPInetAddress *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  TraceOutput *pTVar3;
  TraceOutput *this_00;
  char *pcVar4;
  
  pcVar4 = (char *)0x0;
  pTVar3 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar3,pcVar4);
  puVar1 = *(undefined4 **)param_1;
  puVar2 = *(undefined4 **)this;
  *puVar2 = *puVar1;
  puVar2[1] = puVar1[1];
  puVar2[2] = puVar1[2];
  puVar2[3] = puVar1[3];
  return this;
}



// public: void __thiscall PRUDPInetAddress::Trace(unsigned long)

void __thiscall PRUDPInetAddress::Trace(PRUDPInetAddress *this,ulong param_1)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  char local_80 [128];
  
  ToStr(this,local_80);
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,(char *)param_1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall PRUDPInetAddress::ToStr(char *)

void __thiscall PRUDPInetAddress::ToStr(PRUDPInetAddress *this,char *param_1)

{
  undefined2 uVar1;
  char *pcVar2;
  undefined2 extraout_var;
  char *unaff_retaddr;
  
  pcVar2 = (char *)(*___imp__inet_ntoa_4)(*(undefined4 *)(*(int *)this + 4));
  StringConversion::A2T(pcVar2,unaff_retaddr,0x80);
  uVar1 = (*___imp__ntohs_4)(CONCAT22(extraout_var,*(undefined2 *)(*(int *)this + 2)));
  (*___imp__sprintf)(unaff_retaddr,s__s__d,unaff_retaddr,uVar1);
  return;
}


