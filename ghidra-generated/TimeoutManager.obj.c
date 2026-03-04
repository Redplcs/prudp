#include <stdbool.h>

typedef unsigned char   undefined;

typedef unsigned char    undefined1;
typedef unsigned int    undefined4;

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

struct RefCountedObject { // PlaceHolder Structure
};

typedef struct TraceOutput TraceOutput, *PTraceOutput;

struct TraceOutput { // PlaceHolder Structure
};

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct TimeoutManager TimeoutManager, *PTimeoutManager;

struct TimeoutManager { // PlaceHolder Structure
};

typedef struct Timeout Timeout, *PTimeout;

struct Timeout { // PlaceHolder Structure
};

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
};

typedef struct CriticalSection CriticalSection, *PCriticalSection;

struct CriticalSection { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;

struct Time { // PlaceHolder Structure
};

typedef struct ScopedCS ScopedCS, *PScopedCS;

struct ScopedCS { // PlaceHolder Structure
};

typedef struct PRUDPEndPoint PRUDPEndPoint, *PPRUDPEndPoint;

struct PRUDPEndPoint { // PlaceHolder Structure
};

typedef struct list<class_PacketOut*,class_std::allocator<class_PacketOut*>_> list<class_PacketOut*,class_std::allocator<class_PacketOut*>_>, *Plist<class_PacketOut*,class_std::allocator<class_PacketOut*>_>;

struct list<class_PacketOut*,class_std::allocator<class_PacketOut*>_> { // PlaceHolder Structure
};



undefined LAB_00002808;
undefined __except_list;
const char * s_<unspecified>;
undefined LAB_00002833;
undefined LAB_00002848;
const char * s_pPacket!=NULL;
const char * s_TimeoutManager.cpp;
undefined LAB_00002868;

// public: __thiscall TimeoutManager::TimeoutManager(void)

TimeoutManager * __thiscall TimeoutManager::TimeoutManager(TimeoutManager *this)

{
  void *pvVar1;
  int unaff_FS_OFFSET;
  TimeoutManager local_11;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L6813;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  *this = local_11;
  pvVar1 = operator_new(0xc);
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)(this + 4) = pvVar1;
  *(undefined4 *)(this + 8) = 0;
  local_4 = 0;
  CriticalSection::CriticalSection((CriticalSection *)(this + 0xc));
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: __thiscall TimeoutManager::~TimeoutManager(void)

void __thiscall TimeoutManager::~TimeoutManager(TimeoutManager *this)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int unaff_FS_OFFSET;
  ScopedCS local_14 [4];
  TimeoutManager *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  unsigned int local_4;
  
  puStack_8 = &_L7135;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_4 = 1;
  local_10 = this;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)(this + 0xc),s_<unspecified>);
  ScopedCS::~ScopedCS(local_14);
  local_4 = local_4 & 0xffffff00;
  CriticalSection::~CriticalSection((CriticalSection *)(this + 0xc));
  piVar1 = *(int **)(this + 4);
  piVar3 = (int *)*piVar1;
  while (piVar3 != piVar1) {
    piVar2 = (int *)*piVar3;
    *(int *)piVar3[1] = *piVar3;
    *(int *)(*piVar3 + 4) = piVar3[1];
    operator_delete(piVar3);
    *(int *)(this + 8) = *(int *)(this + 8) + -1;
    piVar3 = piVar2;
  }
  operator_delete(*(void **)(this + 4));
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall TimeoutManager::SchedulePacketTimeout(class PacketOut *)

void __thiscall TimeoutManager::SchedulePacketTimeout(TimeoutManager *this,PacketOut *param_1)

{
  bool bVar1;
  Timeout *pTVar2;
  Timeout *this_00;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int unaff_FS_OFFSET;
  TimeoutManager *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L7377;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_10 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_10,(CriticalSection *)(this + 0xc),s_<unspecified>);
  local_4 = 0;
  Platform::SystemCheck(param_1 != (PacketOut *)0x0,s_pPacket__NULL,s_TimeoutManager_cpp,0x1e);
  pTVar2 = PacketOut::GetTimeout(param_1);
  Timeout::Start(pTVar2);
  piVar6 = (int *)**(int **)(this + 4);
  if (piVar6 != *(int **)(this + 4)) {
    do {
      pTVar2 = PacketOut::GetTimeout(param_1);
      this_00 = PacketOut::GetTimeout((PacketOut *)piVar6[2]);
      bVar1 = Timeout::operator<(this_00,pTVar2);
      if (!bVar1) break;
      piVar6 = (int *)*piVar6;
    } while (piVar6 != (int *)*(int *)(this + 4));
  }
  RefCountedObject::AcquireRef((RefCountedObject *)param_1);
  piVar5 = (int *)piVar6[1];
  piVar3 = operator_new(0xc);
  piVar4 = piVar6;
  if (piVar6 == (int *)0x0) {
    piVar4 = piVar3;
  }
  *piVar3 = (int)piVar4;
  if (piVar5 == (int *)0x0) {
    piVar5 = piVar3;
  }
  piVar3[1] = (int)piVar5;
  piVar6[1] = (int)piVar3;
  *(int **)piVar3[1] = piVar3;
  if (piVar3 + 2 != (int *)0x0) {
    piVar3[2] = (int)param_1;
  }
  local_4 = 0xffffffff;
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  ScopedCS::~ScopedCS((ScopedCS *)&local_10);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall TimeoutManager::CancelPacketTimeout(class PacketOut *)

void __thiscall TimeoutManager::CancelPacketTimeout(TimeoutManager *this,PacketOut *param_1)

{
  int *piVar1;
  TraceOutput *pTVar2;
  int *piVar3;
  TraceOutput *this_00;
  TraceOutput *this_01;
  int unaff_FS_OFFSET;
  undefined4 uStack0000000c;
  char *pcVar4;
  TimeoutManager *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L7596;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_10 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_10,(CriticalSection *)(this + 0xc),s_<unspecified>);
  local_4 = 0;
  Packet::GetSeqId((Packet *)param_1);
  pcVar4 = (char *)0x0;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(unsigned long)pTVar2,pcVar4);
  piVar1 = *(int **)(this + 4);
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    do {
      if ((PacketOut *)piVar3[2] == param_1) break;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != piVar1);
    if (piVar3 != piVar1) {
      *(int *)piVar3[1] = *piVar3;
      *(int *)(*piVar3 + 4) = piVar3[1];
      operator_delete(piVar3);
      *(int *)(this + 8) = *(int *)(this + 8) + -1;
      RefCountedObject::ReleaseRef((RefCountedObject *)param_1);
      Packet::GetSeqId((Packet *)param_1);
      pcVar4 = (char *)0x0;
      pTVar2 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(unsigned long)pTVar2,pcVar4);
    }
  }
  uStack0000000c = 0xffffffff;
  uStack_c = 0x25d1;
  ScopedCS::~ScopedCS((ScopedCS *)&stack0x00000000);
  *(PacketOut **)(&__except_list + unaff_FS_OFFSET) = param_1;
  return;
}



// public: void __thiscall TimeoutManager::ServicePacketTimeouts(void)

void __thiscall TimeoutManager::ServicePacketTimeouts(TimeoutManager *this)

{
  int iVar1;
  PacketOut *this_00;
  int *piVar2;
  bool bVar3;
  Timeout *pTVar4;
  PRUDPEndPoint *this_01;
  Time *this_02;
  TraceOutput *pTVar5;
  TraceOutput *this_03;
  TraceOutput *this_04;
  char *pcVar6;
  
  CriticalSection::Enter((CriticalSection *)(this + 0xc));
  iVar1 = *(int *)(this + 8);
  while (iVar1 != 0) {
    this_00 = *(PacketOut **)(**(int **)(this + 4) + 8);
    pTVar4 = PacketOut::GetTimeout(this_00);
    bVar3 = Timeout::IsAwaited(pTVar4);
    if (!bVar3) {
      pTVar4 = PacketOut::GetTimeout(this_00);
      bVar3 = Timeout::IsExpired(pTVar4);
      if (!bVar3) break;
    }
    piVar2 = (int *)**(undefined4 **)(this + 4);
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    operator_delete(piVar2);
    *(int *)(this + 8) = *(int *)(this + 8) + -1;
    this_01 = PacketOut::GetEndPoint(this_00);
    Packet::GetSeqId((Packet *)this_00);
    this_02 = (Time *)Time::GetTime();
    Time::operator_unsigned___int64(this_02);
    pcVar6 = (char *)0x0;
    pTVar5 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_03,(unsigned long)pTVar5,pcVar6);
    PRUDPEndPoint::ServiceTimeout(this_01,this_00);
    RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
    Packet::GetSeqId((Packet *)this_00);
    pcVar6 = (char *)0x0;
    pTVar5 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_04,(unsigned long)pTVar5,pcVar6);
    iVar1 = *(int *)(this + 8);
  }
  CriticalSection::Leave((CriticalSection *)(this + 0xc));
  return;
}



// public: __thiscall std::list<class PacketOut *,class std::allocator<class PacketOut *>
// >::~list<class PacketOut *,class std::allocator<class PacketOut *> >(void)

void __thiscall std::list<>::~list<>(list<> *this)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = *(int **)(this + 4);
  piVar3 = (int *)*piVar1;
  while (piVar3 != piVar1) {
    piVar2 = (int *)*piVar3;
    *(int *)piVar3[1] = *piVar3;
    *(int *)(*piVar3 + 4) = piVar3[1];
    operator_delete(piVar3);
    *(int *)(this + 8) = *(int *)(this + 8) + -1;
    piVar3 = piVar2;
  }
  operator_delete(*(void **)(this + 4));
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}


