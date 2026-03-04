typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
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

typedef struct PRUDPDeviceData PRUDPDeviceData, *PPRUDPDeviceData;

struct PRUDPDeviceData { // PlaceHolder Structure
};

typedef struct InputEmulationDevice InputEmulationDevice, *PInputEmulationDevice;

struct InputEmulationDevice { // PlaceHolder Structure
};

typedef struct CriticalSection CriticalSection, *PCriticalSection;

struct CriticalSection { // PlaceHolder Structure
};

typedef struct PRUDPTransport PRUDPTransport, *PPRUDPTransport;

struct PRUDPTransport { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;

struct Time { // PlaceHolder Structure
};

typedef struct Buffer Buffer, *PBuffer;

struct Buffer { // PlaceHolder Structure
};

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct UDPSocket UDPSocket, *PUDPSocket;

struct UDPSocket { // PlaceHolder Structure
};

typedef struct AsyncIOContext AsyncIOContext, *PAsyncIOContext;

struct AsyncIOContext { // PlaceHolder Structure
};

typedef struct TransportPerfCounters TransportPerfCounters, *PTransportPerfCounters;

struct TransportPerfCounters { // PlaceHolder Structure
};

typedef struct OutputEmulationDevice OutputEmulationDevice, *POutputEmulationDevice;

struct OutputEmulationDevice { // PlaceHolder Structure
};

typedef struct DeviceData DeviceData, *PDeviceData;

struct DeviceData { // PlaceHolder Structure
};

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
};

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

struct RefCountedObject { // PlaceHolder Structure
};

typedef struct Event Event, *PEvent;

struct Event { // PlaceHolder Structure
};

typedef struct ScopedCS ScopedCS, *PScopedCS;

struct ScopedCS { // PlaceHolder Structure
};

typedef struct PacketIn PacketIn, *PPacketIn;

struct PacketIn { // PlaceHolder Structure
};

typedef struct Transport Transport, *PTransport;

struct Transport { // PlaceHolder Structure
};

typedef struct Socket Socket, *PSocket;

struct Socket { // PlaceHolder Structure
};



undefined LAB_00002e4a;
undefined __except_list;
undefined LAB_00002e7e;
undefined LAB_00002e9b;
undefined DeliverToSend;
undefined LAB_00002ec3;
TerminatedCString s_->;
TerminatedCString s_<unspecified>;
TerminatedCString s_ulTransferred_==_pBuffer->GetCon;
TerminatedCString s_UDPSocket.cpp;
undefined LAB_00002ee3;
TerminatedCString s_!m_bRecvPending;
TerminatedCString s_m_pRecvIOContext->m_oAsyncIOCont;
undefined LAB_00002ef8;
TerminatedCString s_<-;
undefined LAB_00002f18;
undefined LAB_00002f4e;
undefined DeliverToApp;

// public: __thiscall UDPSocket::UDPSocket(class PRUDPTransport *)

UDPSocket * __thiscall UDPSocket::UDPSocket(UDPSocket *this,PRUDPTransport *param_1)

{
  undefined4 *puVar1;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L53458;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  Socket::Socket((Socket *)this,0x11);
  local_4 = 0;
  CriticalSection::CriticalSection((CriticalSection *)(this + 0x24));
  local_4._0_1_ = 1;
  CriticalSection::CriticalSection((CriticalSection *)(this + 0x28));
  local_4._0_1_ = 2;
  puVar1 = operator_new(0x30);
  local_4._0_1_ = 3;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)(puVar1 + 3));
    local_4._0_1_ = 4;
    AsyncIOContext::AsyncIOContext((AsyncIOContext *)(puVar1 + 4));
    *puVar1 = this;
    puVar1[2] = 0;
    puVar1[1] = 0;
  }
  local_4._0_1_ = 2;
  *(undefined4 **)(this + 0x18) = puVar1;
  puVar1 = operator_new(0x30);
  local_4._0_1_ = 5;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)(puVar1 + 3));
    local_4 = CONCAT31(local_4._1_3_,6);
    AsyncIOContext::AsyncIOContext((AsyncIOContext *)(puVar1 + 4));
    *puVar1 = this;
    puVar1[2] = 0;
    puVar1[1] = 0;
  }
  *(undefined4 **)(this + 0x1c) = puVar1;
  *(PRUDPTransport **)(this + 0x14) = param_1;
  this[0x20] = (UDPSocket)0x0;
  this[0x21] = (UDPSocket)0x0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: __thiscall UDPSocket::~UDPSocket(void)

void __thiscall UDPSocket::~UDPSocket(UDPSocket *this)

{
  void *pvVar1;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &_L53499;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_4 = 2;
  Socket::Close((Socket *)this);
  CompleteRecv(this);
  CompleteSend(this);
  pvVar1 = *(void **)(this + 0x18);
  if (pvVar1 != (void *)0x0) {
    PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)((int)pvVar1 + 0xc));
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(this + 0x1c);
  if (pvVar1 != (void *)0x0) {
    PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)((int)pvVar1 + 0xc));
    operator_delete(pvVar1);
  }
  if (*(RefCountedObject **)(this + 0x2c) != (RefCountedObject *)0x0) {
    RefCountedObject::ReleaseRef(*(RefCountedObject **)(this + 0x2c));
  }
  local_4._0_1_ = 1;
  CriticalSection::~CriticalSection((CriticalSection *)(this + 0x28));
  local_4 = (uint)local_4._1_3_ << 8;
  CriticalSection::~CriticalSection((CriticalSection *)(this + 0x24));
  local_4 = 0xffffffff;
  Socket::~Socket((Socket *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall UDPSocket::SetCompletionEvents(class Event *,class Event *)

void __thiscall UDPSocket::SetCompletionEvents(UDPSocket *this,Event *param_1,Event *param_2)

{
  AsyncIOContext::SetEvent((AsyncIOContext *)(*(int *)(this + 0x18) + 0x10),param_1);
  AsyncIOContext::SetEvent((AsyncIOContext *)(*(int *)(this + 0x1c) + 0x10),param_2);
  return;
}



// public: bool __thiscall UDPSocket::Bind(class PRUDPInetAddress *,unsigned short *)

bool __thiscall UDPSocket::Bind(UDPSocket *this,PRUDPInetAddress *param_1,ushort *param_2)

{
  bool bVar1;
  ushort uVar2;
  
  bVar1 = Socket::SetBuffers((Socket *)this);
  if (!bVar1) {
    return false;
  }
  Socket::SetAsync((Socket *)this,true);
  bVar1 = Socket::Bind((Socket *)this,param_1);
  if (!bVar1) {
    return false;
  }
  uVar2 = PRUDPInetAddress::GetPort(param_1);
  *param_2 = uVar2;
  return true;
}



// public: void __thiscall UDPSocket::Queue(class PacketOut *)

void __thiscall UDPSocket::Queue(UDPSocket *this,PacketOut *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  OutputEmulationDevice *pOVar3;
  RefCountedObject *this_00;
  int unaff_FS_OFFSET;
  undefined4 local_14;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  PRUDPDeviceData *pPStack_4;
  
  pPStack_4 = (PRUDPDeviceData *)0xffffffff;
  puStack_8 = &_L53517;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  puVar2 = (undefined4 *)Time::GetTime();
  Packet::SetIOTime((Packet *)param_1,*puVar2,puVar2[1]);
  pPStack_4 = operator_new(0x1c);
  this_00 = (RefCountedObject *)0x0;
  uStack_c = 0;
  if (pPStack_4 != (PRUDPDeviceData *)0x0) {
    this_00 = (RefCountedObject *)
              PRUDPDeviceData::PRUDPDeviceData(pPStack_4,(Packet *)param_1,this,DeliverToSend);
  }
  uStack_c = 0xffffffff;
  bVar1 = Packet::FlagSet((Packet *)param_1,0x80);
  if (!bVar1) {
    pOVar3 = Transport::GetOutputEmulationDevice(*(Transport **)(this + 0x14));
    (**(code **)(*(int *)pOVar3 + 8))(this_00);
    pOVar3 = Transport::GetOutputEmulationDevice(*(Transport **)(this + 0x14));
    (**(code **)(*(int *)pOVar3 + 4))();
    RefCountedObject::ReleaseRef(this_00);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_14;
  return;
}



// bool __cdecl DeliverToSend(class DeviceData *)

bool __cdecl DeliverToSend(DeviceData *param_1)

{
  bool bVar1;
  
  bVar1 = UDPSocket::Send(*(UDPSocket **)(param_1 + 0x18),*(PacketOut **)(param_1 + 0x14));
  return bVar1;
}



// public: bool __thiscall UDPSocket::Send(class PacketOut *)

bool __thiscall UDPSocket::Send(UDPSocket *this,PacketOut *param_1)

{
  undefined4 uVar1;
  PRUDPInetAddress *pPVar2;
  Event *pEVar3;
  int iVar4;
  int unaff_FS_OFFSET;
  ulong uVar5;
  ScopedCS local_14 [4];
  Buffer *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  local_4 = 0xffffffff;
  puStack_8 = &_L53542;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)(this + 0x24),s_<unspecified>);
  if (this[0x20] == (UDPSocket)0x0) {
    this[0x20] = (UDPSocket)0x1;
    local_4 = 0xffffffff;
    ScopedCS::~ScopedCS(local_14);
    local_10 = operator_new(0x20);
    local_4 = 1;
    if (local_10 == (Buffer *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = Buffer::Buffer(local_10,0x1000);
    }
    local_4 = 0xffffffff;
    *(undefined4 *)(*(int *)(this + 0x1c) + 4) = uVar1;
    PacketOut::Pack(param_1,*(Buffer **)(*(int *)(this + 0x1c) + 4));
    pPVar2 = Packet::GetPeerAddress((Packet *)param_1);
    PRUDPInetAddress::operator=((PRUDPInetAddress *)(*(int *)(this + 0x1c) + 0xc),pPVar2);
    *(undefined4 *)(*(int *)(this + 0x1c) + 8) = 0;
    pEVar3 = AsyncIOContext::GetEvent((AsyncIOContext *)(*(int *)(this + 0x1c) + 0x10));
    Event::Reset(pEVar3);
    uVar5 = 0x8000000;
    pPVar2 = Packet::GetPeerAddress((Packet *)param_1);
    PRUDPTransport::TraceProto
              (*(PRUDPTransport **)(this + 0x14),s__>,(Packet *)param_1,
               (PRUDPInetAddress *)(this + 8),pPVar2,uVar5);
    iVar4 = *(int *)(this + 0x1c);
    iVar4 = Socket::Send((Socket *)this,*(Buffer **)(iVar4 + 4),(PRUDPInetAddress *)(iVar4 + 0xc),
                         (ulong *)(iVar4 + 8),(AsyncIOContext *)(iVar4 + 0x10));
    if (iVar4 == -1) {
      pEVar3 = AsyncIOContext::GetEvent((AsyncIOContext *)(*(int *)(this + 0x1c) + 0x10));
      Event::Set(pEVar3);
    }
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return true;
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return false;
}



// public: unsigned long __thiscall UDPSocket::CompleteSend(void)

ulong __thiscall UDPSocket::CompleteSend(UDPSocket *this)

{
  Buffer *this_00;
  ulong uVar1;
  TransportPerfCounters *pTVar2;
  OutputEmulationDevice *pOVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  ulong local_4;
  
  local_4 = 0;
  this_00 = *(Buffer **)(*(int *)(this + 0x1c) + 4);
  *(undefined4 *)(*(int *)(this + 0x1c) + 4) = 0;
  if (this_00 != (Buffer *)0x0) {
    uVar1 = Socket::GetIOResult((Socket *)this,(AsyncIOContext *)(*(int *)(this + 0x1c) + 0x10),
                                &local_4);
    if (uVar1 == 0) {
      uVar8 = 0xa6;
      pcVar5 = s_UDPSocket_cpp;
      pcVar4 = s_ulTransferred____pBuffer_>GetCon;
      uVar1 = Buffer::GetContentSize(this_00);
      Platform::SystemCheck(local_4 == uVar1,pcVar4,pcVar5,uVar8);
    }
    iVar7 = local_4 * 8;
    iVar6 = 0;
    pTVar2 = Transport::GetPerfCounters(*(Transport **)(this + 0x14));
    TransportPerfCounters::Inc(pTVar2,iVar6,iVar7);
    iVar6 = 1;
    iVar7 = 2;
    pTVar2 = Transport::GetPerfCounters(*(Transport **)(this + 0x14));
    TransportPerfCounters::Inc(pTVar2,iVar7,iVar6);
    RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
    this[0x20] = (UDPSocket)0x0;
    if ((*(int *)this == 0) || (*(int *)this == 1)) {
      pOVar3 = Transport::GetOutputEmulationDevice(*(Transport **)(this + 0x14));
      (**(code **)(*(int *)pOVar3 + 4))();
    }
  }
  return local_4;
}



// public: void __thiscall UDPSocket::Listen(void)

void __thiscall UDPSocket::Listen(UDPSocket *this)

{
  Event *pEVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_FS_OFFSET;
  char *pcVar4;
  char *pcVar5;
  ulong uVar6;
  ScopedCS local_14 [4];
  Buffer *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L53560;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)(this + 0x28),s_<unspecified>);
  uVar6 = 0xbc;
  pcVar5 = s_UDPSocket_cpp;
  pcVar4 = s_m_pRecvIOContext_>m_oAsyncIOCont;
  local_4 = 0;
  pEVar1 = AsyncIOContext::GetEvent((AsyncIOContext *)(*(int *)(this + 0x18) + 0x10));
  Platform::SystemCheck(pEVar1 != (Event *)0x0,pcVar4,pcVar5,uVar6);
  Platform::SystemCheck(this[0x21] == (UDPSocket)0x0,s__m_bRecvPending,s_UDPSocket_cpp,0xbd);
  this[0x21] = (UDPSocket)0x1;
  local_10 = operator_new(0x20);
  local_4._0_1_ = 1;
  if (local_10 == (Buffer *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Buffer::Buffer(local_10,0x1000);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*(int *)(this + 0x18) + 4) = uVar2;
  *(undefined4 *)(*(int *)(this + 0x18) + 8) = 0;
  pEVar1 = AsyncIOContext::GetEvent((AsyncIOContext *)(*(int *)(this + 0x18) + 0x10));
  Event::Reset(pEVar1);
  iVar3 = *(int *)(this + 0x18);
  iVar3 = Socket::Recv((Socket *)this,*(Buffer **)(iVar3 + 4),(PRUDPInetAddress *)(iVar3 + 0xc),
                       (ulong *)(iVar3 + 8),(AsyncIOContext *)(iVar3 + 0x10));
  if (iVar3 == -1) {
    pEVar1 = AsyncIOContext::GetEvent((AsyncIOContext *)(*(int *)(this + 0x18) + 0x10));
    Event::Set(pEVar1);
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall UDPSocket::TryIOCompletion(void)

void __thiscall UDPSocket::TryIOCompletion(UDPSocket *this)

{
  if (this[0x20] != (UDPSocket)0x0) {
    Socket::TryIOCompletion((Socket *)this,(AsyncIOContext *)(*(int *)(this + 0x1c) + 0x10));
  }
  if (this[0x21] != (UDPSocket)0x0) {
    Socket::TryIOCompletion((Socket *)this,(AsyncIOContext *)(*(int *)(this + 0x18) + 0x10));
  }
  return;
}



// bool __cdecl DeliverToApp(class DeviceData *)

bool __cdecl DeliverToApp(DeviceData *param_1)

{
  int iVar1;
  DeviceData *pDVar2;
  ushort uVar3;
  undefined4 *puVar4;
  int iVar5;
  TransportPerfCounters *pTVar6;
  PRUDPInetAddress *pPVar7;
  int unaff_FS_OFFSET;
  int iVar8;
  ulong uVar9;
  undefined4 local_14;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pDVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &_L53581;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  iVar1 = *(int *)(param_1 + 0x18);
  ScopedCS::ScopedCS((ScopedCS *)&param_1,(CriticalSection *)(iVar1 + 0x28),s_<unspecified>);
  local_4 = 0;
  if (*(int *)(iVar1 + 0x2c) == 0) {
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(pDVar2 + 0x14);
    puVar4 = (undefined4 *)Time::GetTime();
    Packet::SetIOTime(*(Packet **)(iVar1 + 0x2c),*puVar4,puVar4[1]);
    uVar3 = Packet::GetSize(*(Packet **)(iVar1 + 0x2c));
    iVar5 = (uint)uVar3 << 3;
    iVar8 = 1;
    pTVar6 = Transport::GetPerfCounters(*(Transport **)(iVar1 + 0x14));
    TransportPerfCounters::Inc(pTVar6,iVar8,iVar5);
    iVar8 = 1;
    iVar5 = 3;
    pTVar6 = Transport::GetPerfCounters(*(Transport **)(iVar1 + 0x14));
    TransportPerfCounters::Inc(pTVar6,iVar5,iVar8);
    uVar9 = 0x8000000;
    pPVar7 = Packet::GetPeerAddress(*(Packet **)(iVar1 + 0x2c));
    PRUDPTransport::TraceProto
              (*(PRUDPTransport **)(iVar1 + 0x14),s_<_,*(Packet **)(iVar1 + 0x2c),
               (PRUDPInetAddress *)(iVar1 + 8),pPVar7,uVar9);
    local_c = 0xffffffff;
    ScopedCS::~ScopedCS((ScopedCS *)&local_4);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_14;
    return true;
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS((ScopedCS *)&param_1);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return false;
}



// public: class PacketIn * __thiscall UDPSocket::Recv(void)

PacketIn * __thiscall UDPSocket::Recv(UDPSocket *this)

{
  PacketIn *pPVar1;
  InputEmulationDevice *pIVar2;
  int unaff_FS_OFFSET;
  UDPSocket *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L53591;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_10 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_10,(CriticalSection *)(this + 0x28),s_<unspecified>);
  local_4 = 0;
  pIVar2 = Transport::GetInputEmulationDevice(*(Transport **)(this + 0x14));
  (**(code **)(*(int *)pIVar2 + 4))();
  pPVar1 = *(PacketIn **)(this + 0x2c);
  *(undefined4 *)(this + 0x2c) = 0;
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS((ScopedCS *)&local_10);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return pPVar1;
}



// public: unsigned long __thiscall UDPSocket::CompleteRecv(void)

ulong __thiscall UDPSocket::CompleteRecv(UDPSocket *this)

{
  Buffer *this_00;
  bool bVar1;
  ulong uVar2;
  PacketIn *this_01;
  RefCountedObject *this_02;
  InputEmulationDevice *pIVar3;
  int unaff_FS_OFFSET;
  ulong local_18;
  ScopedCS local_14 [4];
  PacketIn *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L53611;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)(this + 0x28),s_<unspecified>);
  local_18 = 0;
  local_4._0_1_ = 0;
  local_4._1_3_ = 0;
  this_00 = *(Buffer **)(*(int *)(this + 0x18) + 4);
  *(undefined4 *)(*(int *)(this + 0x18) + 4) = 0;
  if (this_00 != (Buffer *)0x0) {
    uVar2 = Socket::GetIOResult((Socket *)this,(AsyncIOContext *)(*(int *)(this + 0x18) + 0x10),
                                &local_18);
    if (uVar2 == 0) {
      Buffer::SetContentSize(this_00,local_18);
    }
    this[0x21] = (UDPSocket)0x0;
    if ((*(int *)this == 0) || (*(int *)this == 1)) {
      if ((uVar2 == 0) && (local_18 != 0)) {
        local_10 = operator_new(0x30);
        local_4._0_1_ = 1;
        if (local_10 == (PacketIn *)0x0) {
          this_01 = (PacketIn *)0x0;
        }
        else {
          this_01 = (PacketIn *)PacketIn::PacketIn(local_10);
        }
        local_4._0_1_ = 0;
        bVar1 = PacketIn::Unpack(this_01,this_00);
        if (bVar1) {
          Packet::SetPeerAddress
                    ((Packet *)this_01,(PRUDPInetAddress *)(*(int *)(this + 0x18) + 0xc));
          local_10 = operator_new(0x1c);
          local_4._0_1_ = 2;
          if (local_10 == (PacketIn *)0x0) {
            this_02 = (RefCountedObject *)0x0;
          }
          else {
            this_02 = (RefCountedObject *)
                      PRUDPDeviceData::PRUDPDeviceData
                                ((PRUDPDeviceData *)local_10,(Packet *)this_01,this,DeliverToApp);
          }
          local_4._0_1_ = 0;
          pIVar3 = Transport::GetInputEmulationDevice(*(Transport **)(this + 0x14));
          (**(code **)(*(int *)pIVar3 + 8))(this_02);
          pIVar3 = Transport::GetInputEmulationDevice(*(Transport **)(this + 0x14));
          (**(code **)(*(int *)pIVar3 + 4))();
          RefCountedObject::ReleaseRef(this_02);
        }
        else {
          RefCountedObject::ReleaseRef((RefCountedObject *)this_01);
          SystemError::TraceLast(0);
        }
      }
      Listen(this);
    }
    RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
  }
  uVar2 = local_18;
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return uVar2;
}



// public: unsigned long __thiscall UDPSocket::QueueSize(void)

ulong __thiscall UDPSocket::QueueSize(UDPSocket *this)

{
  return 0;
}



// public: bool __thiscall UDPSocket::InputFlooded(void)

bool __thiscall UDPSocket::InputFlooded(UDPSocket *this)

{
  return false;
}



// public: bool __thiscall UDPSocket::OutputFlooded(void)

bool __thiscall UDPSocket::OutputFlooded(UDPSocket *this)

{
  return false;
}


