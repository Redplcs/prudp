typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
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

typedef ulonglong __uint64;

typedef struct Buffer Buffer, *PBuffer;

struct Buffer { // PlaceHolder Structure
};

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

struct RefCountedObject { // PlaceHolder Structure
};

typedef struct Timeout Timeout, *PTimeout;

struct Timeout { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;

struct Time { // PlaceHolder Structure
};

typedef struct IORequestContext IORequestContext, *PIORequestContext;

struct IORequestContext { // PlaceHolder Structure
};

typedef struct PRUDPEndPoint PRUDPEndPoint, *PPRUDPEndPoint;

struct PRUDPEndPoint { // PlaceHolder Structure
};

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
};



undefined LAB_00002613;
undefined __imp__rand;
undefined __except_list;
pointer `vftable';
undefined LAB_00002628;

// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall PacketOut::PacketOut(class PRUDPEndPoint *,unsigned char,unsigned char,class
// Buffer *)

PacketOut * __thiscall
PacketOut::PacketOut
          (PacketOut *this,PRUDPEndPoint *param_1,uchar param_2,uchar param_3,Buffer *param_4)

{
  uchar uVar1;
  bool bVar2;
  RefCountedObject *pRVar3;
  Timeout *this_00;
  undefined4 uVar4;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L1886;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  Packet::Packet((Packet *)this);
  local_4 = 0;
  Time::Time((Time *)(this + 0x40));
  *(undefined ***)this = &_vftable_;
  Packet::SetType((Packet *)this,param_2);
  Packet::SetFlag((Packet *)this,param_3);
  *(undefined2 *)(this + 0x38) = 0;
  Time::operator=((Time *)(this + 0x40),0);
  *(undefined4 *)(this + 0x48) = 0;
  *(PRUDPEndPoint **)(this + 0x34) = param_1;
  uVar1 = (*___imp__rand)();
  Packet::SetContextInfo((Packet *)this,uVar1);
  if (param_4 != (Buffer *)0x0) {
    pRVar3 = RefCountedObject::AcquireRef((RefCountedObject *)param_4);
    Packet::SetPayload((Packet *)this,(Buffer *)pRVar3);
  }
  bVar2 = Packet::FlagSet((Packet *)this,' ');
  if (bVar2) {
    this_00 = operator_new(0x18);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (this_00 == (Timeout *)0x0) {
      *(undefined4 *)(this + 0x30) = 0;
    }
    else {
      uVar4 = Timeout::Timeout(this_00);
      *(undefined4 *)(this + 0x30) = uVar4;
    }
  }
  else {
    *(undefined4 *)(this + 0x30) = 0;
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return this;
}



// public: virtual void * __thiscall PacketOut::`scalar deleting destructor'(unsigned int)

void * __thiscall PacketOut::_scalar_deleting_destructor_(PacketOut *this,uint param_1)

{
  ~PacketOut(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// public: virtual __thiscall PacketOut::~PacketOut(void)

void __thiscall PacketOut::~PacketOut(PacketOut *this)

{
  Timeout *this_00;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &_L1910;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  *(undefined ***)this = &_vftable_;
  local_4 = 0;
  if (*(void **)(this + 0x48) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x48));
  }
  this_00 = *(Timeout **)(this + 0x30);
  if (this_00 != (Timeout *)0x0) {
    Timeout::~Timeout(this_00);
    operator_delete(this_00);
  }
  local_4 = 0xffffffff;
  Packet::~Packet((Packet *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: class Timeout * __thiscall PacketOut::GetTimeout(void)

Timeout * __thiscall PacketOut::GetTimeout(PacketOut *this)

{
  return *(Timeout **)(this + 0x30);
}



// public: void __thiscall PacketOut::IncNbTransmission(void)

void __thiscall PacketOut::IncNbTransmission(PacketOut *this)

{
  *(short *)(this + 0x38) = *(short *)(this + 0x38) + 1;
  return;
}



// public: unsigned short __thiscall PacketOut::GetNbTransmission(void)

ushort __thiscall PacketOut::GetNbTransmission(PacketOut *this)

{
  return *(ushort *)(this + 0x38);
}



// public: class PRUDPEndPoint * __thiscall PacketOut::GetEndPoint(void)

PRUDPEndPoint * __thiscall PacketOut::GetEndPoint(PacketOut *this)

{
  return *(PRUDPEndPoint **)(this + 0x34);
}



// public: void __thiscall PacketOut::SetIORequestContext(class IORequestContext *)

void __thiscall PacketOut::SetIORequestContext(PacketOut *this,IORequestContext *param_1)

{
  *(IORequestContext **)(this + 0x48) = param_1;
  *(PacketOut **)(param_1 + 8) = this;
  return;
}



// public: class IORequestContext * __thiscall PacketOut::GetIORequestContext(void)

IORequestContext * __thiscall PacketOut::GetIORequestContext(PacketOut *this)

{
  return *(IORequestContext **)(this + 0x48);
}



// public: bool __thiscall PacketOut::Pack(class Buffer *)

bool __thiscall PacketOut::Pack(PacketOut *this,Buffer *param_1)

{
  bool bVar1;
  Buffer *pBVar2;
  
  bVar1 = Buffer::AppendData(param_1,this + 0xc,8,0xffffffff);
  if (!bVar1) {
    return false;
  }
  pBVar2 = Packet::GetPayload((Packet *)this);
  if (pBVar2 != (Buffer *)0x0) {
    pBVar2 = Packet::GetPayload((Packet *)this);
    Buffer::operator+=(param_1,pBVar2);
  }
  Buffer::AppendCheckSum(param_1);
  return true;
}


