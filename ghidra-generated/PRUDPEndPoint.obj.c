#include <Platform/SpinTest.h>
#include <Platform/Time.h>
#include <Platform/Trace.h>
#include <Platform/UserContext.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Core/RefCountedObject.h>
#include <Plugins/Transport/Interface/EmulationDevice.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/EndPointEventHandler.h>
#include <Plugins/Transport/Interface/OutputEmulationDevice.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/Transport.h>
#include <Plugins/Transport/Interface/TransportPerfCounters.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
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

typedef ulonglong __uint64;

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

typedef struct PRUDPTransportSettings PRUDPTransportSettings, *PPRUDPTransportSettings;

struct PRUDPTransportSettings { // PlaceHolder Structure
};

typedef struct SpinTest SpinTest, *PSpinTest;

typedef struct PRUDPTransport PRUDPTransport, *PPRUDPTransport;

struct PRUDPTransport { // PlaceHolder Structure
};

typedef struct IORequestContext IORequestContext, *PIORequestContext;

struct IORequestContext { // PlaceHolder Structure
};

typedef struct TransportPerfCounters TransportPerfCounters, *PTransportPerfCounters;

typedef struct OutputEmulationDevice OutputEmulationDevice, *POutputEmulationDevice;

typedef struct EndPointEventHandler EndPointEventHandler, *PEndPointEventHandler;

typedef struct Buffer Buffer, *PBuffer;

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
};

typedef struct EmulationDevice EmulationDevice, *PEmulationDevice;

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct TimeoutManager TimeoutManager, *PTimeoutManager;

struct TimeoutManager { // PlaceHolder Structure
};

typedef struct Transport Transport, *PTransport;

typedef struct DispatchQueue DispatchQueue, *PDispatchQueue;

struct DispatchQueue { // PlaceHolder Structure
};

typedef struct UserContext UserContext, *PUserContext;

typedef struct StationURL StationURL, *PStationURL;

typedef struct EndPoint EndPoint, *PEndPoint;

typedef struct SlidingWindow SlidingWindow, *PSlidingWindow;

struct SlidingWindow { // PlaceHolder Structure
};

typedef struct RTT RTT, *PRTT;

struct RTT { // PlaceHolder Structure
};

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct PacketIn PacketIn, *PPacketIn;

struct PacketIn { // PlaceHolder Structure
};

typedef struct PRUDPEndPoint PRUDPEndPoint, *PPRUDPEndPoint;

struct PRUDPEndPoint { // PlaceHolder Structure
};

typedef struct Timeout Timeout, *PTimeout;

struct Timeout { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;

typedef struct iterator iterator, *Piterator;

struct iterator { // PlaceHolder Structure
};

typedef struct _Node _Node, *P_Node;

struct _Node { // PlaceHolder Structure
};

typedef enum _ConnectionState {
} _ConnectionState;



undefined LAB_00004834;
undefined __except_list;
undefined LAB_00004867;
undefined __imp_??0_Lockit@std@@QAE@XZ;
_Node *_Nil;
TerminatedCString s_ISGOODPTR(pPacket);
TerminatedCString s_PRUDPEndPoint.cpp;
undefined __imp_??1_Lockit@std@@QAE@XZ;
undefined LAB_0000489e;
TerminatedCString s_IsConnecting();
undefined LAB_000048c3;
TerminatedCString s_IsDisconnecting();
undefined LAB_000048f1;
TerminatedCString s_:/;
undefined LAB_0000490b;
undefined __imp__sprintf;
TerminatedCString s_%s%s;
TerminatedCString s_prudp;
undefined LAB_0000492b;
TerminatedCString s_(_LONGLONG)pPacket->GetIOTime()>;
TerminatedCString s_ISGOODPTR(pAckedPacket->GetTimeo;
TerminatedCString s_ISGOODPTR(pAckedPacket);
TerminatedCString s_pTimedOutPacket!=NULL;
undefined LAB_0000494b;
string s_Unknown;
string s_Faulty;
TerminatedCString s_Disconnected;
TerminatedCString s_Disconnecting;
TerminatedCString s_Connected;
TerminatedCString s_Connecting;
TerminatedCString s_NotConnected;

// public: __thiscall PRUDPEndPoint::PRUDPEndPoint(class Transport *,unsigned long)

PRUDPEndPoint * __thiscall
PRUDPEndPoint::PRUDPEndPoint(PRUDPEndPoint *this,Transport *pTransport,ulong ulValue)

{
  DispatchQueue *this_00;
  undefined4 uVar1;
  SlidingWindow *this_01;
  PRUDPTransport *this_02;
  PRUDPTransportSettings *this_03;
  ulong uVar2;
  TraceOutput *pTVar3;
  TraceOutput *this_04;
  int unaff_FS_OFFSET;
  char *pcVar4;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L13134;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  EndPoint::EndPoint((EndPoint *)this,pTransport);
  local_4 = 0;
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)(this + 0x18));
  local_4._0_1_ = 1;
  RTT::RTT((RTT *)(this + 0x28));
  local_4._0_1_ = 2;
  Time::Time((Time *)(this + 0x38));
  Time::Time((Time *)(this + 0x40));
  *(Transport **)this = pTransport;
  *(undefined4 *)(this + 0x10) = 0;
  *(ulong *)(this + 0x14) = ulValue;
  this_00 = operator_new(0x14);
  local_4._0_1_ = 3;
  if (this_00 == (DispatchQueue *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = DispatchQueue::DispatchQueue(this_00);
  }
  local_4._0_1_ = 2;
  *(undefined4 *)(this + 0x1c) = uVar1;
  this_01 = operator_new(0x28);
  local_4._0_1_ = 4;
  if (this_01 == (SlidingWindow *)0x0) {
    uVar1 = 0;
  }
  else {
    this_02 = GetTransport(this);
    this_03 = PRUDPTransport::GetSettings(this_02);
    uVar2 = PRUDPTransportSettings::GetWindowSize(this_03);
    uVar1 = SlidingWindow::SlidingWindow(this_01,(ushort)uVar2);
  }
  pcVar4 = (char *)0x0;
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  this[0x50] = (PRUDPEndPoint)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  this[0x58] = (PRUDPEndPoint)0x1;
  pTVar3 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_04,(ulong)pTVar3,pcVar4);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return this;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall PRUDPEndPoint::~PRUDPEndPoint(void)

void __thiscall PRUDPEndPoint::~PRUDPEndPoint(PRUDPEndPoint *this)

{
  DispatchQueue *this_00;
  SlidingWindow *this_01;
  code *pcVar1;
  TraceOutput *pTVar2;
  undefined4 *puVar3;
  RefCountedObject *this_02;
  _Node *p_Var4;
  TraceOutput *this_03;
  TraceOutput *this_04;
  _Node *p_Var5;
  int unaff_FS_OFFSET;
  char *pcVar6;
  undefined1 **ppuVar7;
  undefined4 uStack_c;
  undefined1 *local_8;
  int local_4;
  
  local_8 = &_L13317;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_4 = 2;
  StopPing(this);
  pcVar6 = (char *)0x0;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_03,(ulong)pTVar2,pcVar6);
  ppuVar7 = &local_8;
  puVar3 = (undefined4 *)SlidingWindow::AcquireIterator(*(SlidingWindow **)(this + 0x20));
  p_Var5 = (_Node *)*puVar3;
  this_02 = (RefCountedObject *)
            SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),p_Var5,ppuVar7);
  pcVar1 = ___imp___0_Lockit_std__QAE_XZ;
  while (this_02 != (RefCountedObject *)0x0) {
    Platform::SystemCheck(true,s_ISGOODPTR_pPacket_,s_PRUDPEndPoint_cpp,0x46);
    RefCountedObject::GetRefCount(this_02);
    pcVar6 = (char *)0x0;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_04,(ulong)pTVar2,pcVar6);
    CancelPacketTimeout(this,(PacketOut *)this_02);
    (*pcVar1)();
    p_Var4 = *(_Node **)(p_Var5 + 8);
    if (p_Var4 == std::_Tree<>::_Nil) {
      p_Var4 = *(_Node **)(p_Var5 + 4);
      if (p_Var5 == *(_Node **)(p_Var4 + 8)) {
        do {
          p_Var5 = p_Var4;
          p_Var4 = *(_Node **)(p_Var5 + 4);
        } while (p_Var5 == *(_Node **)(p_Var4 + 8));
      }
      if (*(_Node **)(p_Var5 + 8) != p_Var4) {
        p_Var5 = p_Var4;
      }
    }
    else {
      (*pcVar1)();
      for (p_Var5 = *(_Node **)p_Var4; p_Var5 != std::_Tree<>::_Nil; p_Var5 = *(_Node **)p_Var5) {
        p_Var4 = p_Var5;
      }
      (*___imp___1_Lockit_std__QAE_XZ)();
      p_Var5 = p_Var4;
    }
    (*___imp___1_Lockit_std__QAE_XZ)();
    this_02 = (RefCountedObject *)SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),p_Var5);
  }
  SlidingWindow::ReleaseIterator(*(SlidingWindow **)(this + 0x20));
  SlidingWindow::Purge(*(SlidingWindow **)(this + 0x20));
  DispatchQueue::Purge(*(DispatchQueue **)(this + 0x1c));
  this_00 = *(DispatchQueue **)(this + 0x1c);
  if (this_00 != (DispatchQueue *)0x0) {
    DispatchQueue::~DispatchQueue(this_00);
    operator_delete(this_00);
  }
  this_01 = *(SlidingWindow **)(this + 0x20);
  if (this_01 != (SlidingWindow *)0x0) {
    SlidingWindow::~SlidingWindow(this_01);
    operator_delete(this_01);
  }
  if (*(undefined4 **)(this + 0x54) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x54))(1);
  }
  local_4._0_1_ = 1;
  RTT::~RTT((RTT *)(this + 0x28));
  local_4 = (uint)local_4._1_3_ << 8;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)(this + 0x18));
  local_4 = 0xffffffff;
  EndPoint::~EndPoint((EndPoint *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// public: unsigned long __thiscall PRUDPEndPoint::Connect(class StationURL *,class Buffer *,void
// (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class
// UserContext const &,unsigned long)

ulong __thiscall
PRUDPEndPoint::Connect
          (PRUDPEndPoint *this,StationURL *pStationURL,Buffer *pBuffer,
          _func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,UserContext *pContext,
          ulong ulValue)

{
  PRUDPInetAddress *this_00;
  bool bVar1;
  ulong uVar2;
  PRUDPTransport *pPVar3;
  PRUDPTransportSettings *this_01;
  PacketOut *pPVar4;
  IORequestContext *pIVar5;
  Timeout *this_02;
  TraceOutput *pTVar6;
  TraceOutput *this_03;
  int unaff_FS_OFFSET;
  char *pcVar7;
  PRUDPEndPoint *pPVar8;
  SpinTest local_2c [32];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  local_4 = 0xffffffff;
  puStack_8 = &_L13348;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  if (*(int *)(this + 0x10) != 0) {
    uVar2 = 6;
    goto LAB_00002ec1;
  }
  this_00 = (PRUDPInetAddress *)(this + 0x18);
  pPVar3 = GetTransport(this);
  this_01 = PRUDPTransport::GetSettings(pPVar3);
  uVar2 = PRUDPTransportSettings::GetWellKnownPortNumber(this_01);
  bVar1 = PRUDPInetAddress::SetFromURL(this_00,pStationURL,(ushort)uVar2);
  if (!bVar1) {
    uVar2 = 0xc;
    goto LAB_00002ec1;
  }
  pPVar8 = this;
  pPVar3 = GetTransport(this);
  bVar1 = PRUDPTransport::RegisterEndPoint(pPVar3,pPVar8);
  if (!bVar1) {
    PRUDPInetAddress::SetAddress(this_00,0);
    PRUDPInetAddress::SetPortNumber(this_00,0);
    uVar2 = 0x17;
    goto LAB_00002ec1;
  }
  SetState(this,1);
  if (pBuffer == (Buffer *)0x0) {
    pPVar4 = operator_new(0x50);
    local_4 = 1;
    if (pPVar4 == (PacketOut *)0x0) goto LAB_00002dba;
    pPVar4 = (PacketOut *)PacketOut::PacketOut(pPVar4,this,'\0','0',(Buffer *)0x0);
  }
  else {
    pPVar4 = operator_new(0x50);
    local_4 = 0;
    if (pPVar4 == (PacketOut *)0x0) {
LAB_00002dba:
      pPVar4 = (PacketOut *)0x0;
    }
    else {
      pPVar4 = (PacketOut *)PacketOut::PacketOut(pPVar4,this,'\0','0',pBuffer);
    }
  }
  local_4 = 0xffffffff;
  pIVar5 = operator_new(0x10);
  if (pIVar5 == (IORequestContext *)0x0) {
    pIVar5 = (IORequestContext *)0x0;
  }
  else {
    *(_func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr **)pIVar5 = p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr;
    *(UserContext **)(pIVar5 + 4) = pContext;
    *(undefined4 *)(pIVar5 + 8) = 0;
  }
  PacketOut::SetIORequestContext(pPVar4,pIVar5);
  uVar2 = ulValue;
  this_02 = PacketOut::GetTimeout(pPVar4);
  Timeout::SetRelativeExpirationTime(this_02,uVar2);
  pcVar7 = (char *)0x0;
  pTVar6 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_03,(ulong)pTVar6,pcVar7);
  bVar1 = Send(this,pPVar4);
  if (bVar1) {
    RefCountedObject::ReleaseRef((RefCountedObject *)pPVar4);
    if (p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr == (_func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *)0x0) {
      SpinTest::SpinTest(local_2c,0x32,ulValue);
      SpinTest::LeaveOnTimeout(local_2c);
      bVar1 = IsConnecting(this);
      if (bVar1) {
        do {
          bVar1 = SpinTest::SpinOnce(local_2c,s_PRUDPEndPoint_cpp,0x85,s_IsConnecting__);
          if (!bVar1) break;
          bVar1 = IsConnecting(this);
        } while (bVar1);
      }
      bVar1 = IsConnected(this);
      if (!bVar1) {
        SpinTest::~SpinTest(local_2c);
        uVar2 = 0x11;
        goto LAB_00002ec1;
      }
      SpinTest::~SpinTest(local_2c);
    }
    uVar2 = 0;
  }
  else {
    RefCountedObject::ReleaseRef((RefCountedObject *)pPVar4);
    SetState(this,0);
    uVar2 = 3;
  }
LAB_00002ec1:
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return uVar2;
}



// public: unsigned long __thiscall PRUDPEndPoint::Disconnect(void (__cdecl*const)(class EndPoint
// *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)

ulong __thiscall
PRUDPEndPoint::Disconnect
          (PRUDPEndPoint *this,_func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,
          UserContext *pContext,ulong ulValue)

{
  bool bVar1;
  TraceOutput *pTVar2;
  ulong uVar3;
  PacketOut *pPVar4;
  IORequestContext *pIVar5;
  Timeout *pTVar6;
  TraceOutput *this_00;
  int unaff_FS_OFFSET;
  undefined4 in_stack_00000010;
  ulong in_stack_00000014;
  char *pcVar7;
  SpinTest local_2c [32];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  local_4 = 0xffffffff;
  puStack_8 = &_L13373;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  PRUDPInetAddress::GetPort((PRUDPInetAddress *)(this + 0x18));
  pcVar7 = (char *)0x0;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar7);
  bVar1 = IsConnected(this);
  if (bVar1) {
    SetState(this,3);
    pPVar4 = operator_new(0x50);
    if (pPVar4 == (PacketOut *)0x0) {
      pPVar4 = (PacketOut *)0x0;
    }
    else {
      pPVar4 = (PacketOut *)PacketOut::PacketOut(pPVar4,this,'\x02','0',(Buffer *)0x0);
    }
    pIVar5 = operator_new(0x10);
    if (pIVar5 == (IORequestContext *)0x0) {
      pIVar5 = (IORequestContext *)0x0;
    }
    else {
      *(ulong *)pIVar5 = ulValue;
      *(undefined4 *)(pIVar5 + 4) = in_stack_00000010;
      *(undefined4 *)(pIVar5 + 8) = 0;
    }
    PacketOut::SetIORequestContext(pPVar4,pIVar5);
    uVar3 = in_stack_00000014;
    pTVar6 = PacketOut::GetTimeout(pPVar4);
    Timeout::SetRelativeExpirationTime(pTVar6,uVar3);
    pTVar6 = PacketOut::GetTimeout(pPVar4);
    Timeout::SetRTO(pTVar6,500);
    bVar1 = Send(this,pPVar4);
    if (bVar1) {
      RefCountedObject::ReleaseRef((RefCountedObject *)pPVar4);
      if (ulValue == 0) {
        SpinTest::SpinTest(local_2c,0x32,in_stack_00000014);
        SpinTest::LeaveOnTimeout(local_2c);
        bVar1 = IsDisconnecting(this);
        if (bVar1) {
          do {
            bVar1 = SpinTest::SpinOnce(local_2c,s_PRUDPEndPoint_cpp,0xa9,s_IsDisconnecting__);
            if (!bVar1) break;
            bVar1 = IsDisconnecting(this);
          } while (bVar1);
        }
        bVar1 = IsDisconnected(this);
        if (!bVar1) {
          TraceState(this,0x6000000);
          SpinTest::~SpinTest(local_2c);
          uVar3 = 0x11;
          goto LAB_0000307c;
        }
        SpinTest::~SpinTest(local_2c);
      }
      uVar3 = 0;
    }
    else {
      RefCountedObject::ReleaseRef((RefCountedObject *)pPVar4);
      uVar3 = 3;
    }
  }
  else {
    uVar3 = 5;
  }
LAB_0000307c:
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return uVar3;
}



// public: unsigned long __thiscall PRUDPEndPoint::Send(class Buffer *,void (__cdecl*const)(class
// EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned
// long)

ulong __thiscall
PRUDPEndPoint::Send(PRUDPEndPoint *this,Buffer *pBuffer,
                   _func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,
                   UserContext *pContext,ulong ulValue)

{
  bool bVar1;
  byte bVar2;
  ulong uVar3;
  PRUDPTransport *pPVar4;
  PRUDPTransportSettings *pPVar5;
  ulong uVar6;
  Buffer *pBVar7;
  uchar *puVar8;
  PacketOut *pPVar9;
  IORequestContext *pIVar10;
  uint uVar11;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L13418;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  bVar1 = IsConnected(this);
  if (!bVar1) {
    uVar3 = 5;
    goto LAB_0000337c;
  }
  if ((ulValue & 1) == 0) {
LAB_000032bb:
    pPVar4 = GetTransport(this);
    pPVar5 = PRUDPTransport::GetSettings(pPVar4);
    uVar3 = PRUDPTransportSettings::GetMTU(pPVar5);
    uVar6 = Buffer::GetContentSize(pBuffer);
    if (uVar3 < uVar6) {
      uVar3 = 9;
      goto LAB_0000337c;
    }
    pPVar9 = operator_new(0x50);
    local_4 = 2;
    if (pPVar9 == (PacketOut *)0x0) {
      pPVar9 = (PacketOut *)0x0;
    }
    else {
      pPVar9 = (PacketOut *)
               PacketOut::PacketOut(pPVar9,this,'\x01',-((ulValue & 1) != 0) & 0x30,pBuffer);
    }
    local_4 = 0xffffffff;
    pIVar10 = operator_new(0x10);
    if (pIVar10 == (IORequestContext *)0x0) {
      pIVar10 = (IORequestContext *)0x0;
    }
    else {
      *(_func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr **)pIVar10 = p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr;
      *(UserContext **)(pIVar10 + 4) = pContext;
      *(undefined4 *)(pIVar10 + 8) = 0;
    }
    PacketOut::SetIORequestContext(pPVar9,pIVar10);
    Packet::SetContextInfo((Packet *)pPVar9,'\0');
    bVar1 = Send(this,pPVar9);
    if (!bVar1) {
      RefCountedObject::ReleaseRef((RefCountedObject *)pPVar9);
      uVar3 = 3;
      goto LAB_0000337c;
    }
    RefCountedObject::ReleaseRef((RefCountedObject *)pPVar9);
  }
  else {
    pPVar4 = GetTransport(this);
    pPVar5 = PRUDPTransport::GetSettings(pPVar4);
    uVar3 = PRUDPTransportSettings::GetMTU(pPVar5);
    uVar6 = Buffer::GetContentSize(pBuffer);
    if (uVar6 <= uVar3) goto LAB_000032bb;
    uVar11 = 0;
    ulValue = 1;
    uVar3 = Buffer::GetContentSize(pBuffer);
    if (uVar3 != 0) {
      do {
        pBVar7 = operator_new(0x20);
        local_4 = 0;
        if (pBVar7 == (Buffer *)0x0) {
          pBVar7 = (Buffer *)0x0;
        }
        else {
          pPVar4 = GetTransport(this);
          pPVar5 = PRUDPTransport::GetSettings(pPVar4);
          uVar3 = PRUDPTransportSettings::GetMTU(pPVar5);
          pBVar7 = (Buffer *)Buffer::Buffer(pBVar7,uVar3);
        }
        local_4 = 0xffffffff;
        uVar6 = Buffer::GetContentSize(pBuffer);
        uVar6 = uVar6 - uVar11;
        pPVar4 = GetTransport(this);
        pPVar5 = PRUDPTransport::GetSettings(pPVar4);
        uVar3 = PRUDPTransportSettings::GetMTU(pPVar5);
        if (uVar3 < uVar6) {
          pPVar4 = GetTransport(this);
          pPVar5 = PRUDPTransport::GetSettings(pPVar4);
          uVar6 = PRUDPTransportSettings::GetMTU(pPVar5);
        }
        uVar3 = 0xffffffff;
        puVar8 = Buffer::GetContentPtr(pBuffer);
        Buffer::AppendData(pBVar7,puVar8 + uVar11,uVar6,uVar3);
        pPVar9 = operator_new(0x50);
        local_4 = 1;
        if (pPVar9 == (PacketOut *)0x0) {
          pPVar9 = (PacketOut *)0x0;
        }
        else {
          pPVar9 = (PacketOut *)PacketOut::PacketOut(pPVar9,this,'\x01','0',pBVar7);
        }
        local_4 = 0xffffffff;
        pIVar10 = operator_new(0x10);
        if (pIVar10 == (IORequestContext *)0x0) {
          pIVar10 = (IORequestContext *)0x0;
        }
        else {
          *(_func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr **)pIVar10 = p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr;
          *(UserContext **)(pIVar10 + 4) = pContext;
          *(undefined4 *)(pIVar10 + 8) = 0;
        }
        PacketOut::SetIORequestContext(pPVar9,pIVar10);
        pPVar4 = GetTransport(this);
        pPVar5 = PRUDPTransport::GetSettings(pPVar4);
        uVar3 = PRUDPTransportSettings::GetMTU(pPVar5);
        uVar11 = uVar11 + uVar3;
        uVar3 = Buffer::GetContentSize(pBuffer);
        if (uVar11 < uVar3) {
          Packet::SetContextInfo((Packet *)pPVar9,(uchar)ulValue);
          bVar2 = (uchar)ulValue + 1;
          ulValue = (ulong)bVar2;
          if (bVar2 == 0) {
            ulValue = 1;
          }
        }
        else {
          Packet::SetContextInfo((Packet *)pPVar9,'\0');
        }
        bVar1 = Send(this,pPVar9);
        if (!bVar1) {
          RefCountedObject::ReleaseRef((RefCountedObject *)pPVar9);
          RefCountedObject::ReleaseRef((RefCountedObject *)pBVar7);
          uVar3 = 3;
          goto LAB_0000337c;
        }
        RefCountedObject::ReleaseRef((RefCountedObject *)pPVar9);
        RefCountedObject::ReleaseRef((RefCountedObject *)pBVar7);
        uVar3 = Buffer::GetContentSize(pBuffer);
      } while (uVar11 < uVar3);
    }
  }
  uVar3 = 0;
LAB_0000337c:
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return uVar3;
}



// public: bool __thiscall PRUDPEndPoint::IsConnected(void)

bool __thiscall PRUDPEndPoint::IsConnected(PRUDPEndPoint *this)

{
  return *(int *)(this + 0x10) == 2;
}



// public: bool __thiscall PRUDPEndPoint::IsDisconnected(void)

bool __thiscall PRUDPEndPoint::IsDisconnected(PRUDPEndPoint *this)

{
  return *(int *)(this + 0x10) == 4;
}



// public: unsigned long __thiscall PRUDPEndPoint::GetQueueSize(void)

ulong __thiscall PRUDPEndPoint::GetQueueSize(PRUDPEndPoint *this)

{
  PRUDPTransport *this_00;
  OutputEmulationDevice *this_01;
  ulong uVar1;
  
  this_00 = GetTransport(this);
  this_01 = Transport::GetOutputEmulationDevice((Transport *)this_00);
  uVar1 = EmulationDevice::GetQueueSize((EmulationDevice *)this_01);
  return uVar1;
}



// public: unsigned long __thiscall PRUDPEndPoint::GetNbReliablePending(void)

ulong __thiscall PRUDPEndPoint::GetNbReliablePending(PRUDPEndPoint *this)

{
  ulong uVar1;
  
  uVar1 = SlidingWindow::NbDataPending(*(SlidingWindow **)(this + 0x20));
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: class StationURL * __thiscall PRUDPEndPoint::GetStationURL(void)

StationURL * __thiscall PRUDPEndPoint::GetStationURL(PRUDPEndPoint *this)

{
  bool bVar1;
  StationURL *pSVar2;
  int unaff_FS_OFFSET;
  char local_4c [64];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L13447;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  (*___imp__sprintf)(local_4c,s__s_s,s_prudp,s___);
  pSVar2 = operator_new(4);
  uStack_4 = 0;
  if (pSVar2 == (StationURL *)0x0) {
    pSVar2 = (StationURL *)0x0;
  }
  else {
    pSVar2 = (StationURL *)StationURL::StationURL(pSVar2);
  }
  uStack_4 = 0xffffffff;
  StationURL::SetURL(pSVar2,local_4c);
  bVar1 = PRUDPInetAddress::GetURL((PRUDPInetAddress *)(this + 0x18),pSVar2);
  if (bVar1) {
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
    return pSVar2;
  }
  if (pSVar2 != (StationURL *)0x0) {
    StationURL::~StationURL(pSVar2);
    operator_delete(pSVar2);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return (StationURL *)0x0;
}



// private: bool __thiscall PRUDPEndPoint::Send(class PacketOut *)

bool __thiscall PRUDPEndPoint::Send(PRUDPEndPoint *this,PacketOut *pPacketOut)

{
  bool bVar1;
  uchar uVar2;
  ushort uVar3;
  PRUDPTransport *this_00;
  ulong uVar4;
  
  Packet::SetPeerAddress((Packet *)pPacketOut,(PRUDPInetAddress *)(this + 0x18));
  bVar1 = Packet::FlagSet((Packet *)pPacketOut,'\x10');
  if (bVar1) {
    uVar3 = PacketOut::GetNbTransmission(pPacketOut);
    if (uVar3 == 0) {
      SlidingWindow::Push(*(SlidingWindow **)(this + 0x20),pPacketOut);
    }
    SendNextReliable(this);
    return true;
  }
  bVar1 = Packet::FlagSet((Packet *)pPacketOut,'\b');
  if (!bVar1) {
    uVar2 = Packet::GetType((Packet *)pPacketOut);
    if (uVar2 == '\x01') {
      Packet::SetSeqId((Packet *)pPacketOut,*(ulong *)(this + 0x48));
      *(int *)(this + 0x48) = *(int *)(this + 0x48) + 1;
    }
  }
  uVar4 = *(ulong *)(this + 0x14);
  this_00 = GetTransport(this);
  PRUDPTransport::Send(this_00,uVar4,pPacketOut);
  return true;
}



// private: void __thiscall PRUDPEndPoint::SendNextReliable(void)

void __thiscall PRUDPEndPoint::SendNextReliable(PRUDPEndPoint *this)

{
  TraceOutput *pTVar1;
  PacketOut *pPVar2;
  Time *pTVar3;
  TraceOutput *this_00;
  char *pcVar4;
  
  pcVar4 = (char *)0x0;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,pcVar4);
  pPVar2 = SlidingWindow::GetNextToSend(*(SlidingWindow **)(this + 0x20));
  if (pPVar2 != (PacketOut *)0x0) {
    pTVar3 = (Time *)Time::GetTime();
    Time::operator=((Time *)(this + 0x38),pTVar3);
    SendReliable(this,pPVar2);
  }
  return;
}



// private: void __thiscall PRUDPEndPoint::SendReliable(class PacketOut *)

void __thiscall PRUDPEndPoint::SendReliable(PRUDPEndPoint *this,PacketOut *pPacketOut)

{
  uchar uVar1;
  bool bVar2;
  ushort uVar3;
  PRUDPTransport *pPVar4;
  TimeoutManager *pTVar5;
  TraceOutput *pTVar6;
  Timeout *this_00;
  ulong uVar7;
  TraceOutput *this_01;
  TraceOutput *this_02;
  uint uStack0000000c;
  char *pcVar8;
  PacketOut *pPVar9;
  
  uVar1 = Packet::GetType((Packet *)pPacketOut);
  if (uVar1 == '\x02') {
    bVar2 = ReadyToDisconnect(this);
    if (!bVar2) {
      pPVar4 = GetTransport(this);
      pTVar5 = PRUDPTransport::GetTimeoutManager(pPVar4);
      TimeoutManager::SchedulePacketTimeout(pTVar5,pPacketOut);
      return;
    }
  }
  PacketOut::IncNbTransmission(pPacketOut);
  PacketOut::GetNbTransmission(pPacketOut);
  RTT::GetRTO((RTT *)(this + 0x28));
  pcVar8 = (char *)0x0;
  pTVar6 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_01,(ulong)pTVar6,pcVar8);
  this_00 = PacketOut::GetTimeout(pPacketOut);
  uVar3 = PacketOut::GetNbTransmission(pPacketOut);
  uStack0000000c = (uint)uVar3;
  uVar7 = RTT::GetRTO((RTT *)(this + 0x28));
  Timeout::SetRTO(this_00,uStack0000000c * uVar7);
  Packet::GetSeqId((Packet *)pPacketOut);
  pcVar8 = (char *)0x0;
  pTVar6 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_02,(ulong)pTVar6,pcVar8);
  pPVar9 = pPacketOut;
  pPVar4 = GetTransport(this);
  pTVar5 = PRUDPTransport::GetTimeoutManager(pPVar4);
  TimeoutManager::SchedulePacketTimeout(pTVar5,pPVar9);
  uVar7 = *(ulong *)(this + 0x14);
  pPVar4 = GetTransport(this);
  PRUDPTransport::Send(pPVar4,uVar7,pPacketOut);
  return;
}



// private: class PacketIn * __thiscall PRUDPEndPoint::GetNextDispatchPacket(void)

PacketIn * __thiscall PRUDPEndPoint::GetNextDispatchPacket(PRUDPEndPoint *this)

{
  PacketIn *pPVar1;
  
  pPVar1 = DispatchQueue::GetNextToDispatch(*(DispatchQueue **)(this + 0x1c));
  return pPVar1;
}



// private: void __thiscall PRUDPEndPoint::Dispatch(class PacketIn *,class Time)

void __thiscall PRUDPEndPoint::Dispatch(PRUDPEndPoint *this,Packet *pPacket)

{
  uchar uVar1;
  PRUDPEndPoint PVar2;
  Buffer *pBVar3;
  TraceOutput *pTVar4;
  EndPointEventHandler *pEVar5;
  StationURL *this_00;
  TraceOutput *this_01;
  TraceOutput *this_02;
  TraceOutput *this_03;
  char *pcVar6;
  
  pBVar3 = Packet::GetPayload(pPacket);
  if (*(int *)(this + 0x54) == 0) {
    *(Buffer **)(this + 0x54) = pBVar3;
    pBVar3 = (Buffer *)0x0;
    RefCountedObject::AcquireRef(*(RefCountedObject **)(this + 0x54));
  }
  uVar1 = Packet::GetContextInfo(pPacket);
  if ((uVar1 != '\0') &&
     (PVar2 = (PRUDPEndPoint)Packet::GetContextInfo(pPacket), PVar2 != this[0x58])) {
    pcVar6 = (char *)0x1;
    pTVar4 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_01,(ulong)pTVar4,pcVar6);
    if (*(RefCountedObject **)(this + 0x54) == (RefCountedObject *)0x0) {
      return;
    }
    RefCountedObject::ReleaseRef(*(RefCountedObject **)(this + 0x54));
    *(undefined4 *)(this + 0x54) = 0;
    return;
  }
  if (pBVar3 != (Buffer *)0x0) {
    pBVar3 = Buffer::operator+(*(Buffer **)(this + 0x54),pBVar3);
    Buffer::operator=(*(Buffer **)(this + 0x54),pBVar3);
  }
  uVar1 = Packet::GetContextInfo(pPacket);
  if (uVar1 != '\0') {
    PVar2 = this[0x58];
    this[0x58] = (PRUDPEndPoint)((char)PVar2 + '\x01');
    if ((PRUDPEndPoint)((char)PVar2 + '\x01') == (PRUDPEndPoint)0x0) {
      this[0x58] = (PRUDPEndPoint)0x1;
    }
    return;
  }
  pEVar5 = EndPoint::GetEventHandler((EndPoint *)this);
  if (pEVar5 != (EndPointEventHandler *)0x0) {
    this_00 = GetStationURL(this);
    if (this_00 == (StationURL *)0x0) {
      Buffer::GetContentSize(*(Buffer **)(this + 0x54));
      pcVar6 = (char *)0x6000000;
      pTVar4 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_03,(ulong)pTVar4,pcVar6);
    }
    else {
      Buffer::GetContentSize(*(Buffer **)(this + 0x54));
      StationURL::GetURL(this_00);
      pcVar6 = (char *)0x6000000;
      pTVar4 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_02,(ulong)pTVar4,pcVar6);
      EndPoint::ReleaseURL((EndPoint *)this,this_00);
    }
    pEVar5 = EndPoint::GetEventHandler((EndPoint *)this);
    (**(code **)(*(int *)pEVar5 + 4))(this,*(undefined4 *)(this + 0x54));
  }
  this[0x58] = (PRUDPEndPoint)0x1;
  RefCountedObject::ReleaseRef(*(RefCountedObject **)(this + 0x54));
  *(undefined4 *)(this + 0x54) = 0;
  return;
}



// private: void __thiscall PRUDPEndPoint::SignalFaultEvent(unsigned long)

void __thiscall PRUDPEndPoint::SignalFaultEvent(PRUDPEndPoint *this,ulong ulValue)

{
  EndPointEventHandler *pEVar1;
  StationURL *this_00;
  TraceOutput *pTVar2;
  TraceOutput *this_01;
  TraceOutput *this_02;
  char *pcVar3;
  
  pEVar1 = EndPoint::GetEventHandler((EndPoint *)this);
  if ((pEVar1 != (EndPointEventHandler *)0x0) && (*(int *)(this + 0x10) != 6)) {
    this_00 = GetStationURL(this);
    if (this_00 == (StationURL *)0x0) {
      pcVar3 = (char *)0x6000000;
      pTVar2 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar3);
    }
    else {
      StationURL::GetURL(this_00);
      pcVar3 = (char *)0x6000000;
      pTVar2 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar3);
      EndPoint::ReleaseURL((EndPoint *)this,this_00);
    }
    if (*(int *)(this + 0x10) != 1) {
      SetState(this,6);
      StopPing(this);
      pEVar1 = EndPoint::GetEventHandler((EndPoint *)this);
      (**(code **)(*(int *)pEVar1 + 8))(this,ulValue);
      return;
    }
    SetState(this,6);
    StopPing(this);
  }
  return;
}



// private: void __thiscall PRUDPEndPoint::ServiceIncomingPacket(class PacketIn *)

void __thiscall PRUDPEndPoint::ServiceIncomingPacket(PRUDPEndPoint *this,PacketIn *pPacketIn)

{
  PacketIn *this_00;
  uchar uVar1;
  bool bVar2;
  uchar uVar3;
  TraceOutput *pTVar4;
  PacketOut *pPVar5;
  Packet *pPVar6;
  ulong uVar7;
  Time *pTVar8;
  PRUDPTransport *pPVar9;
  TransportPerfCounters *pTVar10;
  undefined4 *puVar11;
  EndPointEventHandler *pEVar12;
  StationURL *this_01;
  Time *this_02;
  IORequestContext *pIVar13;
  PRUDPEndPoint *pPVar14;
  TraceOutput *this_03;
  TraceOutput *this_04;
  TraceOutput *this_05;
  TraceOutput *this_06;
  TraceOutput *this_07;
  TraceOutput *this_08;
  TraceOutput *this_09;
  TraceOutput *this_10;
  int iVar15;
  int unaff_FS_OFFSET;
  __int64 _Var16;
  undefined1 in_stack_00000014;
  char *pcVar17;
  int iVar18;
  Buffer *pBVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  Time local_10 [4];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = pPacketIn;
  local_4 = 0xffffffff;
  puStack_8 = &_L13499;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  uVar1 = Packet::GetType((Packet *)pPacketIn);
  pcVar17 = (char *)0x0;
  pPacketIn = (PacketIn *)CONCAT31(pPacketIn._1_3_,uVar1);
  pTVar4 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_03,(ulong)pTVar4,pcVar17);
  bVar2 = Packet::FlagSet((Packet *)this_00,' ');
  if (bVar2) {
    pcVar17 = (char *)0x0;
    pTVar4 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_04,(ulong)pTVar4,pcVar17);
    pPVar5 = operator_new(0x50);
    if (pPVar5 == (PacketOut *)0x0) {
      pPVar6 = (Packet *)0x0;
    }
    else {
      pBVar19 = (Buffer *)0x0;
      uVar3 = '\0';
      uVar1 = Packet::GetType((Packet *)this_00);
      pPVar6 = (Packet *)PacketOut::PacketOut(pPVar5,this,uVar1,uVar3,pBVar19);
    }
    Packet::SetFlag(pPVar6,'\b');
    uVar7 = Packet::GetSeqId((Packet *)this_00);
    Packet::SetSeqId(pPVar6,uVar7);
    uVar1 = Packet::GetContextInfo((Packet *)this_00);
    Packet::SetContextInfo(pPVar6,uVar1);
    Send(this,(PacketOut *)pPVar6);
    RefCountedObject::ReleaseRef((RefCountedObject *)pPVar6);
  }
  pTVar8 = (Time *)Time::GetTime();
  Time::operator=((Time *)(this + 0x40),pTVar8);
  bVar2 = Packet::FlagSet((Packet *)this_00,0x80);
  SetPeerFlooded(this,bVar2);
  bVar2 = Packet::FlagSet((Packet *)this_00,'\x10');
  if (bVar2) {
    DispatchQueue::Queue(*(DispatchQueue **)(this + 0x1c),this_00);
  }
  switch(in_stack_00000014) {
  case 0:
    bVar2 = Packet::FlagSet((Packet *)this_00,'\b');
    if (bVar2) {
      uVar7 = Packet::GetSeqId((Packet *)this_00);
      pPVar5 = SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),uVar7);
      if ((pPVar5 != (PacketOut *)0x0) &&
         (pIVar13 = PacketOut::GetIORequestContext(pPVar5), pIVar13 != (IORequestContext *)0x0)) {
        pcVar17 = (char *)0x0;
        pTVar4 = TraceOutput::GetInstance();
        TraceOutput::Trace(this_09,(ulong)pTVar4,pcVar17);
        pIVar13 = PacketOut::GetIORequestContext(pPVar5);
        if (*(int *)pIVar13 != 0) {
          uVar22 = *(undefined4 *)(pIVar13 + 4);
          uVar20 = *(undefined4 *)(pIVar13 + 0xc);
          uVar21 = 0;
          pPVar14 = PacketOut::GetEndPoint(*(PacketOut **)(pIVar13 + 8));
          (**(code **)pIVar13)(pPVar14,uVar20,uVar21,uVar22);
        }
      }
      PacketAcknowledged(this,(Packet *)this_00);
    }
    SetState(this,2);
    SetPeerConnected(this,true);
    StartPing(this);
    break;
  case 1:
    bVar2 = Packet::FlagSet((Packet *)this_00,'\b');
    if (bVar2) {
      PacketAcknowledged(this,(Packet *)this_00);
    }
    else {
      bVar2 = Packet::FlagSet((Packet *)this_00,'\x10');
      if (!bVar2) {
        iVar15 = *(int *)(this + 0x4c);
        uVar7 = Packet::GetSeqId((Packet *)this_00);
        iVar15 = uVar7 - iVar15;
        if (iVar15 < 0) {
          iVar18 = -1;
          iVar15 = 4;
          pPVar9 = GetTransport(this);
          pTVar10 = Transport::GetPerfCounters((Transport *)pPVar9);
          TransportPerfCounters::Inc(pTVar10,iVar15,iVar18);
        }
        else {
          if (iVar15 != 0) {
            Packet::GetSeqId((Packet *)this_00);
            pcVar17 = (char *)0x0;
            pTVar4 = TraceOutput::GetInstance();
            TraceOutput::Trace(this_05,(ulong)pTVar4,pcVar17);
          }
          iVar18 = 4;
          pPVar9 = GetTransport(this);
          pTVar10 = Transport::GetPerfCounters((Transport *)pPVar9);
          TransportPerfCounters::Inc(pTVar10,iVar18,iVar15);
          uVar7 = Packet::GetSeqId((Packet *)this_00);
          *(ulong *)(this + 0x4c) = uVar7 + 1;
        }
      }
      bVar2 = Packet::FlagSet((Packet *)this_00,'\x10');
      if (!bVar2) {
        puVar11 = (undefined4 *)Packet::GetIOTime((Packet *)this_00);
        Dispatch(this,this_00,*puVar11,puVar11[1]);
      }
    }
    break;
  case 2:
    bVar2 = Packet::FlagSet((Packet *)this_00,'\b');
    if (bVar2) {
      uVar7 = Packet::GetSeqId((Packet *)this_00);
      pPVar5 = SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),uVar7);
      if ((pPVar5 != (PacketOut *)0x0) &&
         (pIVar13 = PacketOut::GetIORequestContext(pPVar5), pIVar13 != (IORequestContext *)0x0)) {
        pcVar17 = (char *)0x0;
        pTVar4 = TraceOutput::GetInstance();
        TraceOutput::Trace(this_06,(ulong)pTVar4,pcVar17);
        pIVar13 = PacketOut::GetIORequestContext(pPVar5);
        if (*(int *)pIVar13 != 0) {
          uVar22 = *(undefined4 *)(pIVar13 + 4);
          uVar20 = *(undefined4 *)(pIVar13 + 0xc);
          uVar21 = 0;
          pPVar14 = PacketOut::GetEndPoint(*(PacketOut **)(pIVar13 + 8));
          (**(code **)pIVar13)(pPVar14,uVar20,uVar21,uVar22);
        }
      }
      SetState(this,4);
      PacketAcknowledged(this,(Packet *)this_00);
    }
    else {
      SetPeerDisconnected(this,true);
      pEVar12 = EndPoint::GetEventHandler((EndPoint *)this);
      if (pEVar12 != (EndPointEventHandler *)0x0) {
        this_01 = GetStationURL(this);
        if (this_01 == (StationURL *)0x0) {
          pcVar17 = (char *)0x6000000;
          pTVar4 = TraceOutput::GetInstance();
          TraceOutput::Trace(this_08,(ulong)pTVar4,pcVar17);
          pEVar12 = EndPoint::GetEventHandler((EndPoint *)this);
          (**(code **)(*(int *)pEVar12 + 0x10))(this);
        }
        else {
          StationURL::GetURL(this_01);
          pcVar17 = (char *)0x6000000;
          pTVar4 = TraceOutput::GetInstance();
          TraceOutput::Trace(this_07,(ulong)pTVar4,pcVar17);
          EndPoint::ReleaseURL((EndPoint *)this,this_01);
          pEVar12 = EndPoint::GetEventHandler((EndPoint *)this);
          (**(code **)(*(int *)pEVar12 + 0x10))(this);
        }
      }
    }
    break;
  case 3:
    bVar2 = Packet::FlagSet((Packet *)this_00,'\b');
    if ((bVar2) && (pPVar6 = *(Packet **)(this + 0x24), pPVar6 != (Packet *)0x0)) {
      uVar1 = Packet::GetContextInfo((Packet *)this_00);
      uVar3 = Packet::GetContextInfo(pPVar6);
      if (uVar3 == uVar1) {
        Packet::GetIOTime(*(Packet **)(this + 0x24));
        pTVar8 = local_10;
        this_02 = (Time *)Packet::GetIOTime((Packet *)this_00);
        _Var16 = Time::operator-(this_02,pTVar8);
        RTT::Adjust((RTT *)(this + 0x28),(ulong)_Var16);
      }
    }
    break;
  case 6:
    bVar2 = IsConnecting(this);
    if (bVar2) {
      pPVar5 = SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),0);
      if ((pPVar5 != (PacketOut *)0x0) &&
         (pIVar13 = PacketOut::GetIORequestContext(pPVar5), pIVar13 != (IORequestContext *)0x0)) {
        pcVar17 = (char *)0x0;
        pTVar4 = TraceOutput::GetInstance();
        TraceOutput::Trace(this_10,(ulong)pTVar4,pcVar17);
        uVar7 = Packet::GetSeqId((Packet *)pPVar5);
        pPVar5 = SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),uVar7);
        pIVar13 = PacketOut::GetIORequestContext(pPVar5);
        if (*(int *)pIVar13 != 0) {
          uVar22 = *(undefined4 *)(pIVar13 + 4);
          uVar20 = *(undefined4 *)(pIVar13 + 0xc);
          uVar21 = 0x15;
          pPVar14 = PacketOut::GetEndPoint(*(PacketOut **)(pIVar13 + 8));
          (**(code **)pIVar13)(pPVar14,uVar20,uVar21,uVar22);
        }
      }
      SetState(this,5);
    }
    else {
      bVar2 = IsDisconnecting(this);
      if (bVar2) {
        SetState(this,4);
      }
      else {
        bVar2 = IsPeerDisconnected(this);
        if (!bVar2) {
          SignalFaultEvent(this,0x15);
        }
      }
    }
  }
  pPVar6 = (Packet *)GetNextDispatchPacket(this);
  while (pPVar6 != (Packet *)0x0) {
    uVar1 = Packet::GetType(pPVar6);
    if (uVar1 == '\x01') {
      puVar11 = (undefined4 *)Packet::GetIOTime((Packet *)this_00);
      Dispatch(this,pPVar6,*puVar11,puVar11[1]);
    }
    DispatchQueue::Dispatched(*(DispatchQueue **)(this + 0x1c),(PacketIn *)pPVar6);
    pPVar6 = (Packet *)GetNextDispatchPacket(this);
  }
  *(PacketIn **)(&__except_list + unaff_FS_OFFSET) = pPacketIn;
  return;
}



// private: void __thiscall PRUDPEndPoint::PacketAcknowledged(class Packet *)

void __thiscall PRUDPEndPoint::PacketAcknowledged(PRUDPEndPoint *this,Packet *pPacket)

{
  bool bVar1;
  ushort uVar2;
  ulong uVar3;
  PacketOut *this_00;
  Time *pTVar4;
  Time *this_01;
  int iVar5;
  int iVar6;
  uint unaff_ESI;
  __uint64 _Var7;
  __int64 _Var8;
  
  uVar3 = Packet::GetSeqId(pPacket);
  this_00 = SlidingWindow::GetPacket(*(SlidingWindow **)(this + 0x20),uVar3);
  if (this_00 != (PacketOut *)0x0) {
    Platform::SystemCheck(true,s_ISGOODPTR_pAckedPacket_,s_PRUDPEndPoint_cpp,0x22b);
    Platform::SystemCheck(true,s_ISGOODPTR_pAckedPacket_>GetTimeo,s_PRUDPEndPoint_cpp,0x22c);
    uVar2 = PacketOut::GetNbTransmission(this_00);
    if (uVar2 == 1) {
      pTVar4 = (Time *)Packet::GetIOTime((Packet *)this_00);
      _Var7 = Time::operator_unsigned___int64(pTVar4);
      iVar5 = (int)(_Var7 >> 0x20);
      pTVar4 = (Time *)Packet::GetIOTime(pPacket);
      _Var7 = Time::operator_unsigned___int64(pTVar4);
      iVar6 = (int)(_Var7 >> 0x20);
      if ((iVar6 < iVar5) || ((iVar6 <= iVar5 && ((uint)_Var7 < unaff_ESI)))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      Platform::SystemCheck(bVar1,s___LONGLONG_pPacket_>GetIOTime__>,s_PRUDPEndPoint_cpp,0x22e);
      Packet::GetIOTime((Packet *)this_00);
      pTVar4 = (Time *)&stack0xffffffe4;
      this_01 = (Time *)Packet::GetIOTime(pPacket);
      _Var8 = Time::operator-(this_01,pTVar4);
      RTT::Adjust((RTT *)(this + 0x28),(ulong)_Var8);
    }
    CancelPacketTimeout(this,this_00);
    uVar3 = Packet::GetSeqId(pPacket);
    SlidingWindow::Acknowledged(*(SlidingWindow **)(this + 0x20),uVar3);
    SendNextReliable(this);
  }
  return;
}



// private: void __thiscall PRUDPEndPoint::ServiceTimeout(class PacketOut *)

void __thiscall PRUDPEndPoint::ServiceTimeout(PRUDPEndPoint *this,PacketOut *pPacketOut)

{
  uchar uVar1;
  bool bVar2;
  ushort uVar3;
  TraceOutput *pTVar4;
  PRUDPTransport *this_00;
  PRUDPTransportSettings *this_01;
  ulong uVar5;
  Timeout *this_02;
  IORequestContext *pIVar6;
  PRUDPEndPoint *pPVar7;
  TraceOutput *this_03;
  Packet *in_stack_0000000c;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  pcVar8 = (char *)0x0;
  pTVar4 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_03,(ulong)pTVar4,pcVar8);
  Platform::SystemCheck
            (in_stack_0000000c != (Packet *)0x0,s_pTimedOutPacket__NULL,s_PRUDPEndPoint_cpp,0x23d);
  uVar1 = Packet::GetType(in_stack_0000000c);
  if (uVar1 == '\x03') {
    TimeToPing(this);
    return;
  }
  this_00 = GetTransport(this);
  this_01 = PRUDPTransport::GetSettings(this_00);
  uVar5 = PRUDPTransportSettings::GetMaxRetransmission(this_01);
  uVar3 = PacketOut::GetNbTransmission((PacketOut *)in_stack_0000000c);
  if (uVar3 != uVar5) {
    this_02 = PacketOut::GetTimeout((PacketOut *)in_stack_0000000c);
    bVar2 = Timeout::IsExpired(this_02);
    if (!bVar2) {
      SendReliable(this,(PacketOut *)in_stack_0000000c);
      return;
    }
  }
  pIVar6 = PacketOut::GetIORequestContext((PacketOut *)in_stack_0000000c);
  if (pIVar6 != (IORequestContext *)0x0) {
    pIVar6 = PacketOut::GetIORequestContext((PacketOut *)in_stack_0000000c);
    if (*(int *)pIVar6 != 0) {
      uVar11 = *(undefined4 *)(pIVar6 + 4);
      uVar9 = *(undefined4 *)(pIVar6 + 0xc);
      uVar10 = 0x11;
      pPVar7 = PacketOut::GetEndPoint(*(PacketOut **)(pIVar6 + 8));
      (**(code **)pIVar6)(pPVar7,uVar9,uVar10,uVar11);
    }
  }
  return;
}



// private: void __thiscall PRUDPEndPoint::CancelPacketTimeout(class PacketOut *)

void __thiscall PRUDPEndPoint::CancelPacketTimeout(PRUDPEndPoint *this,PacketOut *pPacketOut)

{
  TraceOutput *pTVar1;
  PRUDPTransport *this_00;
  TimeoutManager *this_01;
  TraceOutput *this_02;
  char *pcVar2;
  
  Packet::GetSeqId((Packet *)pPacketOut);
  pcVar2 = (char *)0x0;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_02,(ulong)pTVar1,pcVar2);
  Platform::SystemCheck(true,s_ISGOODPTR_pPacket_,s_PRUDPEndPoint_cpp,0x251);
  this_00 = GetTransport(this);
  this_01 = PRUDPTransport::GetTimeoutManager(this_00);
  TimeoutManager::CancelPacketTimeout(this_01,pPacketOut);
  return;
}



// private: void __thiscall PRUDPEndPoint::StartPing(void)

void __thiscall PRUDPEndPoint::StartPing(PRUDPEndPoint *this)

{
  PacketOut *pPVar1;
  undefined4 uVar2;
  PRUDPTransport *pPVar3;
  PRUDPTransportSettings *this_00;
  ulong uVar4;
  Timeout *this_01;
  TimeoutManager *this_02;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L13531;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  if (*(int *)(this + 0x24) == 0) {
    pPVar1 = operator_new(0x50);
    local_4 = 0;
    if (pPVar1 == (PacketOut *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = PacketOut::PacketOut(pPVar1,this,'\x03',' ',(Buffer *)0x0);
    }
    local_4 = 0xffffffff;
    *(undefined4 *)(this + 0x24) = uVar2;
    pPVar3 = GetTransport(this);
    this_00 = PRUDPTransport::GetSettings(pPVar3);
    uVar4 = PRUDPTransportSettings::GetKeepAliveTimeout(this_00);
    this_01 = PacketOut::GetTimeout(*(PacketOut **)(this + 0x24));
    Timeout::SetRTO(this_01,uVar4);
    pPVar1 = *(PacketOut **)(this + 0x24);
    pPVar3 = GetTransport(this);
    this_02 = PRUDPTransport::GetTimeoutManager(pPVar3);
    TimeoutManager::SchedulePacketTimeout(this_02,pPVar1);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// private: void __thiscall PRUDPEndPoint::StopPing(void)

void __thiscall PRUDPEndPoint::StopPing(PRUDPEndPoint *this)

{
  PRUDPTransport *this_00;
  TimeoutManager *this_01;
  PacketOut *pPVar1;
  
  pPVar1 = *(PacketOut **)(this + 0x24);
  if (pPVar1 != (PacketOut *)0x0) {
    this_00 = GetTransport(this);
    this_01 = PRUDPTransport::GetTimeoutManager(this_00);
    TimeoutManager::CancelPacketTimeout(this_01,pPVar1);
    RefCountedObject::ReleaseRef(*(RefCountedObject **)(this + 0x24));
    *(undefined4 *)(this + 0x24) = 0;
  }
  return;
}



// private: void __thiscall PRUDPEndPoint::TimeToPing(void)

void __thiscall PRUDPEndPoint::TimeToPing(PRUDPEndPoint *this)

{
  PacketOut *pPVar1;
  uchar uVar2;
  undefined4 *puVar3;
  PRUDPTransport *pPVar4;
  PRUDPTransportSettings *pPVar5;
  ulong uVar6;
  TraceOutput *pTVar7;
  TimeoutManager *this_00;
  TraceOutput *this_01;
  __int64 _Var8;
  char *pcVar9;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar3 = (undefined4 *)Time::GetTime();
  local_10 = *puVar3;
  local_c = puVar3[1];
  pPVar4 = GetTransport(this);
  pPVar5 = PRUDPTransport::GetSettings(pPVar4);
  uVar6 = PRUDPTransportSettings::GetMaxSilenceTime(pPVar5);
  _Var8 = Time::operator-((Time *)&local_10,(Time *)(this + 0x40));
  if ((-1 < _Var8) && ((0xffffffff < _Var8 || (uVar6 < (uint)_Var8)))) {
    Time::operator-((Time *)&local_10,(Time *)(this + 0x40));
    pcVar9 = (char *)0x20;
    pTVar7 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_01,(ulong)pTVar7,pcVar9);
    SignalFaultEvent(this,2);
    return;
  }
  pPVar4 = GetTransport(this);
  pPVar5 = PRUDPTransport::GetSettings(pPVar4);
  uVar6 = PRUDPTransportSettings::GetKeepAliveTimeout(pPVar5);
  _Var8 = Time::operator-((Time *)&local_10,(Time *)(this + 0x38));
  if ((-1 < _Var8) && ((0xffffffff < _Var8 || (uVar6 < (uint)_Var8)))) {
    uVar2 = Packet::GetContextInfo(*(Packet **)(this + 0x24));
    Packet::SetContextInfo(*(Packet **)(this + 0x24),uVar2 + '\x01');
    Send(this,*(PacketOut **)(this + 0x24));
  }
  pPVar1 = *(PacketOut **)(this + 0x24);
  pPVar4 = GetTransport(this);
  this_00 = PRUDPTransport::GetTimeoutManager(pPVar4);
  TimeoutManager::SchedulePacketTimeout(this_00,pPVar1);
  return;
}



// private: void __thiscall PRUDPEndPoint::SetState(enum PRUDPEndPoint::_ConnectionState)

void __thiscall PRUDPEndPoint::SetState(PRUDPEndPoint *this,_ConnectionState value)

{
  char local_40 [32];
  char local_20 [32];
  
  GetStringState(this,local_40);
  *(_ConnectionState *)(this + 0x10) = value;
  GetStringState(this,local_20);
  return;
}



// private: void __thiscall PRUDPEndPoint::GetStringState(char *)

void __thiscall PRUDPEndPoint::GetStringState(PRUDPEndPoint *this,char *szText)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  switch(*(undefined4 *)(this + 0x10)) {
  case 0:
    pcVar5 = s_NotConnected;
    break;
  case 1:
    pcVar5 = s_Connecting;
    goto LAB_00004249;
  case 2:
    pcVar5 = s_Connected;
    break;
  case 3:
    pcVar5 = s_Disconnecting;
    goto LAB_00004249;
  case 4:
    pcVar5 = s_Disconnected;
    break;
  default:
    pcVar5 = s_Unknown;
    break;
  case 6:
    pcVar5 = s_Faulty;
LAB_00004249:
    uVar2 = 0xffffffff;
    do {
      pcVar4 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar4 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar4;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar4 + -uVar2;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)szText = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      szText = szText + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *szText = *pcVar5;
      pcVar5 = pcVar5 + 1;
      szText = szText + 1;
    }
    return;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar5 = pcVar4 + -uVar2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)szText = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    szText = szText + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *szText = *pcVar5;
    pcVar5 = pcVar5 + 1;
    szText = szText + 1;
  }
  return;
}



// private: void __thiscall PRUDPEndPoint::TraceState(unsigned long)

void __thiscall PRUDPEndPoint::TraceState(PRUDPEndPoint *this,ulong ulValue)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  char local_80 [128];
  
  local_80[0] = '\0';
  GetStringState(this,local_80);
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,(char *)ulValue);
  return;
}



// private: bool __thiscall PRUDPEndPoint::ReadyToDisconnect(void)

bool __thiscall PRUDPEndPoint::ReadyToDisconnect(PRUDPEndPoint *this)

{
  bool bVar1;
  
  bVar1 = SlidingWindow::DataPending(*(SlidingWindow **)(this + 0x20));
  return (bool)('\x01' - bVar1);
}



// private: bool __thiscall PRUDPEndPoint::IsNotConnected(void)

bool __thiscall PRUDPEndPoint::IsNotConnected(PRUDPEndPoint *this)

{
  return *(int *)(this + 0x10) == 0;
}



// private: bool __thiscall PRUDPEndPoint::IsConnecting(void)

bool __thiscall PRUDPEndPoint::IsConnecting(PRUDPEndPoint *this)

{
  return *(int *)(this + 0x10) == 1;
}



// private: bool __thiscall PRUDPEndPoint::IsDisconnecting(void)

bool __thiscall PRUDPEndPoint::IsDisconnecting(PRUDPEndPoint *this)

{
  return *(int *)(this + 0x10) == 3;
}



// private: bool __thiscall PRUDPEndPoint::IsPeerFlooded(void)

bool __thiscall PRUDPEndPoint::IsPeerFlooded(PRUDPEndPoint *this)

{
  return this[0x50] != (PRUDPEndPoint)0x0;
}



// public: bool __thiscall PRUDPEndPoint::IsPeerConnected(void)

bool __thiscall PRUDPEndPoint::IsPeerConnected(PRUDPEndPoint *this)

{
  return this[0x50] != (PRUDPEndPoint)0x0;
}



// public: bool __thiscall PRUDPEndPoint::IsPeerDisconnected(void)

bool __thiscall PRUDPEndPoint::IsPeerDisconnected(PRUDPEndPoint *this)

{
  return this[0x50] != (PRUDPEndPoint)0x0;
}



// private: void __thiscall PRUDPEndPoint::SetPeerFlooded(bool)

void __thiscall PRUDPEndPoint::SetPeerFlooded(PRUDPEndPoint *this,bool bValue)

{
  if (bValue) {
    this[0x50] = (PRUDPEndPoint)((byte)this[0x50] | 1);
    return;
  }
  this[0x50] = (PRUDPEndPoint)((byte)this[0x50] & 0xfe);
  return;
}



// private: void __thiscall PRUDPEndPoint::SetPeerDisconnected(bool)

void __thiscall PRUDPEndPoint::SetPeerDisconnected(PRUDPEndPoint *this,bool bValue)

{
  if (bValue) {
    this[0x50] = (PRUDPEndPoint)((byte)this[0x50] | 3);
    SetPeerConnected(this,false);
    return;
  }
  this[0x50] = (PRUDPEndPoint)((byte)this[0x50] & 0xfc);
  return;
}



// private: void __thiscall PRUDPEndPoint::SetPeerConnected(bool)

void __thiscall PRUDPEndPoint::SetPeerConnected(PRUDPEndPoint *this,bool bValue)

{
  if (bValue) {
    this[0x50] = (PRUDPEndPoint)((byte)this[0x50] | 2);
    SetPeerDisconnected(this,false);
    return;
  }
  this[0x50] = (PRUDPEndPoint)((byte)this[0x50] & 0xfd);
  return;
}



// private: unsigned long __thiscall PRUDPEndPoint::GetAssociatedSocket(void)

ulong __thiscall PRUDPEndPoint::GetAssociatedSocket(PRUDPEndPoint *this)

{
  return *(ulong *)(this + 0x14);
}



// private: class RTT * __thiscall PRUDPEndPoint::GetRTT(void)

RTT * __thiscall PRUDPEndPoint::GetRTT(PRUDPEndPoint *this)

{
  return (RTT *)(this + 0x28);
}



// private: void __thiscall PRUDPEndPoint::SetSocket(unsigned long)

void __thiscall PRUDPEndPoint::SetSocket(PRUDPEndPoint *this,ulong ulValue)

{
  *(ulong *)(this + 0x14) = ulValue;
  return;
}



// private: bool __thiscall PRUDPEndPoint::IsIdle(void)

bool __thiscall PRUDPEndPoint::IsIdle(PRUDPEndPoint *this)

{
  bool bVar1;
  
  bVar1 = SlidingWindow::Empty(*(SlidingWindow **)(this + 0x20));
  return bVar1;
}



// private: void __thiscall PRUDPEndPoint::SetPRUDPInetAddress(class PRUDPInetAddress *)

void __thiscall PRUDPEndPoint::SetPRUDPInetAddress(PRUDPEndPoint *this,PRUDPInetAddress *pAddress)

{
  PRUDPInetAddress::operator=((PRUDPInetAddress *)(this + 0x18),pAddress);
  return;
}



// private: class PRUDPInetAddress * __thiscall PRUDPEndPoint::GetPRUDPInetAddress(void)

PRUDPInetAddress * __thiscall PRUDPEndPoint::GetPRUDPInetAddress(PRUDPEndPoint *this)

{
  return (PRUDPInetAddress *)(this + 0x18);
}



// private: bool __thiscall PRUDPEndPoint::IsFlooded(void)

bool __thiscall PRUDPEndPoint::IsFlooded(PRUDPEndPoint *this)

{
  return false;
}



// private: class PRUDPTransport * __thiscall PRUDPEndPoint::GetTransport(void)

PRUDPTransport * __thiscall PRUDPEndPoint::GetTransport(PRUDPEndPoint *this)

{
  return *(PRUDPTransport **)this;
}


