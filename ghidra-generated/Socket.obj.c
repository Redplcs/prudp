#include <Platform/Trace.h>
#include <Plugins/Core/Buffer.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned char    uchar;
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

typedef struct Buffer Buffer, *PBuffer;

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

struct _OVERLAPPED { // PlaceHolder Structure
};

typedef struct sockaddr sockaddr, *Psockaddr;

struct sockaddr { // PlaceHolder Structure
};

typedef struct AsyncIOContext AsyncIOContext, *PAsyncIOContext;

struct AsyncIOContext { // PlaceHolder Structure
};

typedef struct Socket Socket, *PSocket;

struct Socket { // PlaceHolder Structure
};



undefined LAB_00002e0b;
undefined __except_list;
undefined LAB_00002e2b;
TerminatedCString s_m_eState_==_CLOSE;
TerminatedCString s_Socket.cpp;
undefined __imp__WSASocketA@24;
undefined __imp__getsockname@12;
undefined __imp__bind@12;
TerminatedCString s_m_eState_==_OPEN;
undefined __imp__shutdown@8;
undefined __imp__closesocket@4;
undefined __imp__WSASendTo@36;
undefined __imp__WSARecvFrom@36;
undefined __imp__WSAWaitForMultipleEvents@20;
undefined __imp__WSAGetOverlappedResult@20;
undefined __imp__ioctlsocket@12;
undefined __imp__setsockopt@20;
undefined __imp__GetLastError@0;

// public: __thiscall Socket::Socket(unsigned long)

Socket * __thiscall Socket::Socket(Socket *this,ulong ulValue)

{
  undefined4 *puVar1;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L43607;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)(this + 8));
  local_4 = 0;
  puVar1 = operator_new(0x24);
  *(undefined4 **)(this + 0x10) = puVar1;
  *puVar1 = 0xffffffff;
  *(ulong *)(this + 4) = ulValue;
  *(undefined4 *)this = 3;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: __thiscall Socket::~Socket(void)

void __thiscall Socket::~Socket(Socket *this)

{
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &_L43619;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_4 = 0;
  Close(this);
  operator_delete(*(void **)(this + 0x10));
  local_4 = 0xffffffff;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)(this + 8));
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::Open(void)

bool __thiscall Socket::Open(Socket *this)

{
  undefined4 uVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  char *pcVar3;
  
  Platform::SystemCheck(*(int *)this == 3,s_m_eState____CLOSE,s_Socket_cpp,0x2d);
  if (*(int *)(this + 4) == 1) {
    uVar1 = (*___imp__WSASocketA_24)(2,3,1,0,0,1);
    **(undefined4 **)(this + 0x10) = uVar1;
  }
  else if (*(int *)(this + 4) == 0x11) {
    uVar1 = (*___imp__WSASocketA_24)(2,2,0x11,0,0,1);
    **(undefined4 **)(this + 0x10) = uVar1;
  }
  if (**(int **)(this + 0x10) == -1) {
    GetLastSocketError();
    pcVar3 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
    return false;
  }
  SetBroadcastMode(this,true);
  *(undefined4 *)this = 0;
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::Bind(class PRUDPInetAddress *)

bool __thiscall Socket::Bind(Socket *this,PRUDPInetAddress *pAddress)

{
  sockaddr *psVar1;
  int iVar2;
  TraceOutput *pTVar3;
  TraceOutput *this_00;
  char *pcVar4;
  undefined1 *puVar5;
  
  Platform::SystemCheck(*(int *)this == 0,s_m_eState____OPEN,s_Socket_cpp,0x53);
  psVar1 = PRUDPInetAddress::GetSockAddr(pAddress);
  iVar2 = (*___imp__bind_12)(**(undefined4 **)(this + 0x10),psVar1);
  if (iVar2 == -1) {
    GetLastSocketError();
    pcVar4 = (char *)0x0;
    pTVar3 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar3,pcVar4);
    return false;
  }
  puVar5 = &stack0xfffffff0;
  *(undefined4 *)this = 1;
  psVar1 = PRUDPInetAddress::GetSockAddr((PRUDPInetAddress *)(this + 8));
  (*___imp__getsockname_12)(**(undefined4 **)(this + 0x10),psVar1,puVar5);
  PRUDPInetAddress::operator=(pAddress,(PRUDPInetAddress *)(this + 8));
  return true;
}



// public: class PRUDPInetAddress * __thiscall Socket::GetAddress(void)

PRUDPInetAddress * __thiscall Socket::GetAddress(Socket *this)

{
  return (PRUDPInetAddress *)(this + 8);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall Socket::Shutdown(unsigned long)

void __thiscall Socket::Shutdown(Socket *this,ulong ulValue)

{
  code *pcVar1;
  TraceOutput *pTVar2;
  int iVar3;
  ulong uVar4;
  TraceOutput *this_00;
  TraceOutput *this_01;
  undefined4 in_stack_0000000c;
  char *pcVar5;
  
  if (*(int *)this == 3) {
    pcVar5 = (char *)0x1;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar5);
  }
  pcVar1 = ___imp__shutdown_8;
  iVar3 = *(int *)this;
  while (iVar3 != 2) {
    iVar3 = (*pcVar1)(**(undefined4 **)(this + 0x10),in_stack_0000000c);
    if ((iVar3 == -1) && (uVar4 = GetLastSocketError(), uVar4 != 0x2749)) {
      pcVar5 = (char *)0x1;
      pTVar2 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar5);
      Platform::Sleep(10);
    }
    else {
      *(undefined4 *)this = 2;
    }
    iVar3 = *(int *)this;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall Socket::Close(void)

void __thiscall Socket::Close(Socket *this)

{
  if (*(int *)this != 3) {
    Shutdown(this,1);
    (*___imp__closesocket_4)(**(undefined4 **)(this + 0x10));
    *(undefined4 *)this = 3;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: int __thiscall Socket::Send(class Buffer *,class PRUDPInetAddress *,unsigned long *,class
// AsyncIOContext *)

int __thiscall
Socket::Send(Socket *this,Buffer *pBuffer,PRUDPInetAddress *pAddress,ulong *pulValue,
            AsyncIOContext *pAsyncIOContext)

{
  undefined4 *puVar1;
  uchar *puVar2;
  ulong uVar3;
  TraceOutput *pTVar4;
  _OVERLAPPED *p_Var5;
  sockaddr *psVar6;
  int iVar7;
  TraceOutput *this_00;
  TraceOutput *this_01;
  AsyncIOContext *in_stack_00000018;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char local_80 [128];
  
  *pulValue = 0;
  puVar2 = Buffer::GetContentPtr(pBuffer);
  *(uchar **)(*(int *)(this + 0x10) + 8) = puVar2;
  uVar3 = Buffer::GetContentSize(pBuffer);
  *(ulong *)(*(int *)(this + 0x10) + 4) = uVar3;
  PRUDPInetAddress::ToStr(pAddress,local_80);
  Buffer::GetContentPtr(pBuffer);
  Buffer::GetContentPtr(pBuffer);
  Buffer::GetContentSize(pBuffer);
  pcVar8 = (char *)0x0;
  pTVar4 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar4,pcVar8);
  puVar1 = *(undefined4 **)(this + 0x10);
  uVar10 = 0;
  p_Var5 = AsyncIOContext::GetOverlapped(in_stack_00000018);
  uVar9 = 0x10;
  psVar6 = PRUDPInetAddress::GetSockAddr(pAddress);
  iVar7 = (*___imp__WSASendTo_36)(*puVar1,puVar1 + 1,1,pulValue,0,psVar6,uVar9,p_Var5,uVar10);
  if (iVar7 == -1) {
    uVar3 = GetLastSocketError();
    if (uVar3 != 0x3e5) {
      GetLastSocketError();
      pcVar8 = (char *)0x1;
      pTVar4 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar4,pcVar8);
      uVar3 = GetLastSocketError();
      return uVar3;
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: int __thiscall Socket::Recv(class Buffer *,class PRUDPInetAddress *,unsigned long *,class
// AsyncIOContext *)

int __thiscall
Socket::Recv(Socket *this,Buffer *pBuffer,PRUDPInetAddress *pAddress,ulong *pulValue,
            AsyncIOContext *pAsyncIOContext)

{
  undefined4 *puVar1;
  uchar *puVar2;
  ulong uVar3;
  _OVERLAPPED *p_Var4;
  sockaddr *psVar5;
  int iVar6;
  TraceOutput *pTVar7;
  TraceOutput *this_00;
  AsyncIOContext *unaff_EDI;
  char *pcVar8;
  Socket *pSVar9;
  undefined4 uVar10;
  undefined4 local_4;
  
  pSVar9 = this + 0xc;
  local_4 = 0;
  *(undefined4 *)pSVar9 = 0x10;
  *pulValue = 0;
  puVar2 = Buffer::GetContentPtr(pBuffer);
  *(uchar **)(*(int *)(this + 0x10) + 0x18) = puVar2;
  uVar3 = Buffer::GetSize(pBuffer);
  uVar10 = 0;
  *(ulong *)(*(int *)(this + 0x10) + 0x14) = uVar3;
  puVar1 = *(undefined4 **)(this + 0x10);
  p_Var4 = AsyncIOContext::GetOverlapped(pAsyncIOContext);
  psVar5 = PRUDPInetAddress::GetSockAddr(pAddress);
  iVar6 = (*___imp__WSARecvFrom_36)
                    (*puVar1,puVar1 + 5,1,pulValue,&local_4,psVar5,pSVar9,p_Var4,uVar10);
  if (iVar6 == -1) {
    uVar3 = GetLastSocketError();
    if (uVar3 != 0x3e5) {
      GetLastSocketError();
      pcVar8 = (char *)0x6000000;
      pTVar7 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_00,(ulong)pTVar7,pcVar8);
      return -1;
    }
  }
  AsyncIOContext::SetIOSize(unaff_EDI,*pulValue);
  return 0;
}



// public: void __thiscall Socket::TryIOCompletion(class AsyncIOContext *)

void __thiscall Socket::TryIOCompletion(Socket *this,AsyncIOContext *pAsyncIOContext)

{
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::WaitForIOCompletion(class AsyncIOContext *,unsigned long,unsigned
// long *)

bool __thiscall
Socket::WaitForIOCompletion(Socket *this,AsyncIOContext *pAsyncIOContext,ulong ulValue,ulong *pulValue)

{
  _OVERLAPPED *p_Var1;
  int iVar2;
  ulong uVar3;
  ulong *unaff_EDI;
  undefined4 uVar4;
  ulong uStack_c;
  
  uStack_c = 0;
  uVar4 = 0;
  p_Var1 = AsyncIOContext::GetOverlapped(pAsyncIOContext);
  iVar2 = (*___imp__WSAWaitForMultipleEvents_20)(1,p_Var1 + 0x10,uVar4,ulValue);
  if (iVar2 == 0) {
    uVar3 = GetIOResult(this,pAsyncIOContext,&uStack_c);
    *unaff_EDI = uVar3;
    AsyncIOContext::SetIOSize(pAsyncIOContext,uStack_c);
    AsyncIOContext::SetReturnCode(pAsyncIOContext,*unaff_EDI);
    return true;
  }
  return false;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: unsigned long __thiscall Socket::GetIOResult(class AsyncIOContext *,unsigned long *)

ulong __thiscall Socket::GetIOResult(Socket *this,AsyncIOContext *pAsyncIOContext,ulong *pulValue)

{
  _OVERLAPPED *p_Var1;
  int iVar2;
  ulong uVar3;
  ulong *puVar4;
  undefined4 uVar5;
  ulong **ppuVar6;
  
  ppuVar6 = &pulValue;
  uVar5 = 0;
  puVar4 = pulValue;
  p_Var1 = AsyncIOContext::GetOverlapped(pAsyncIOContext);
  iVar2 = (*___imp__WSAGetOverlappedResult_20)
                    (**(undefined4 **)(this + 0x10),p_Var1,puVar4,uVar5,ppuVar6);
  if (iVar2 == 0) {
    uVar3 = GetLastSocketError();
    return uVar3;
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::SetAsync(bool)

bool __thiscall Socket::SetAsync(Socket *this,bool bValue)

{
  int iVar1;
  
  _param_1 = (uint)bValue;
  iVar1 = (*___imp__ioctlsocket_12)(**(undefined4 **)(this + 0x10),0x8004667e,&bValue);
  return (bool)('\x01' - (iVar1 != 0));
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::SetNoDelay(bool)

bool __thiscall Socket::SetNoDelay(Socket *this,bool bValue)

{
  int iVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  char *pcVar3;
  
  iVar1 = (*___imp__setsockopt_20)(**(undefined4 **)(this + 0x10),6,1,&bValue,1);
  if (iVar1 == -1) {
    GetLastSocketError();
    pcVar3 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
    return false;
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::SetBuffers(void)

bool __thiscall Socket::SetBuffers(Socket *this)

{
  int iVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  char *pcVar3;
  undefined4 local_4;
  
  local_4 = 0;
  iVar1 = (*___imp__setsockopt_20)(**(undefined4 **)(this + 0x10),0xffff,0x1001,&local_4,4);
  if (iVar1 == -1) {
    GetLastSocketError();
    pcVar3 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
    return false;
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::ReuseAddress(bool)

bool __thiscall Socket::ReuseAddress(Socket *this,bool bValue)

{
  int iVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  char *pcVar3;
  
  iVar1 = (*___imp__setsockopt_20)(**(undefined4 **)(this + 0x10),0xffff,4,&bValue,1);
  if (iVar1 == -1) {
    GetLastSocketError();
    pcVar3 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
    return false;
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::SetDebugMode(bool)

bool __thiscall Socket::SetDebugMode(Socket *this,bool bValue)

{
  int iVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  char *pcVar3;
  
  iVar1 = (*___imp__setsockopt_20)(**(undefined4 **)(this + 0x10),0xffff,1,&bValue,1);
  if (iVar1 == -1) {
    GetLastSocketError();
    pcVar3 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
    return false;
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall Socket::SetBroadcastMode(bool)

bool __thiscall Socket::SetBroadcastMode(Socket *this,bool bValue)

{
  int iVar1;
  
  _param_1 = (uint)bValue;
  iVar1 = (*___imp__setsockopt_20)(**(undefined4 **)(this + 0x10),0xffff,0x20,&bValue,4);
  return iVar1 != -1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: static unsigned long __cdecl Socket::GetLastSocketError(void)

ulong __cdecl Socket::GetLastSocketError(void)

{
  ulong uVar1;
  
                    // WARNING: Could not recover jumptable at 0x00002c00. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (*___imp__GetLastError_0)();
  return uVar1;
}



// public: unsigned short __thiscall Socket::GetBoundPort(void)

ushort __thiscall Socket::GetBoundPort(Socket *this)

{
  ushort uVar1;
  
  uVar1 = PRUDPInetAddress::GetPort((PRUDPInetAddress *)(this + 8));
  return uVar1;
}


