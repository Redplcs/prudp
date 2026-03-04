#include <Platform/Time.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Core/RefCountedObject.h>

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

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

typedef struct Timeout Timeout, *PTimeout;

struct Timeout { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;

typedef struct IORequestContext IORequestContext, *PIORequestContext;

struct IORequestContext { // PlaceHolder Structure
};

typedef struct PRUDPEndPoint PRUDPEndPoint, *PPRUDPEndPoint;

struct PRUDPEndPoint { // PlaceHolder Structure
};

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
    undefined m_abyPacketBase[0x30];
    Timeout *m_pTimeout;
    PRUDPEndPoint *m_pEndPoint;
    ushort m_usNbTransmission;
    ushort m_usPadding;
    undefined4 m_auRetryTime[2];
    IORequestContext *m_pIORequestContext;
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
          (PacketOut *this,PRUDPEndPoint *pPRUDPEndPoint,uchar value,uchar value2,Buffer *pBuffer)

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
  Time::Time((Time *)this->m_auRetryTime);
  *(undefined ***)this = &_vftable_;
  Packet::SetType((Packet *)this,value);
  Packet::SetFlag((Packet *)this,value2);
  this->m_usNbTransmission = 0;
  Time::operator=((Time *)this->m_auRetryTime,0);
  this->m_pIORequestContext = (IORequestContext *)0x0;
  this->m_pEndPoint = pPRUDPEndPoint;
  uVar1 = (*___imp__rand)();
  Packet::SetContextInfo((Packet *)this,uVar1);
  if (pBuffer != (Buffer *)0x0) {
    pRVar3 = RefCountedObject::AcquireRef((RefCountedObject *)pBuffer);
    Packet::SetPayload((Packet *)this,(Buffer *)pRVar3);
  }
  bVar2 = Packet::FlagSet((Packet *)this,' ');
  if (bVar2) {
    this_00 = operator_new(0x18);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (this_00 == (Timeout *)0x0) {
      this->m_pTimeout = (Timeout *)0x0;
    }
    else {
      uVar4 = Timeout::Timeout(this_00);
      this->m_pTimeout = (Timeout *)uVar4;
    }
  }
  else {
    this->m_pTimeout = (Timeout *)0x0;
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return this;
}



// public: virtual void * __thiscall PacketOut::`scalar deleting destructor'(unsigned int)

void * __thiscall PacketOut::_scalar_deleting_destructor_(PacketOut *this,uint shouldDelete)

{
  ~PacketOut(this);
  if ((shouldDelete & 1) != 0) {
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
  if (this->m_pIORequestContext != (IORequestContext *)0x0) {
    operator_delete(this->m_pIORequestContext);
  }
  this_00 = this->m_pTimeout;
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
  return this->m_pTimeout;
}



// public: void __thiscall PacketOut::IncNbTransmission(void)

void __thiscall PacketOut::IncNbTransmission(PacketOut *this)

{
  this->m_usNbTransmission = this->m_usNbTransmission + 1;
  return;
}



// public: unsigned short __thiscall PacketOut::GetNbTransmission(void)

ushort __thiscall PacketOut::GetNbTransmission(PacketOut *this)

{
  return this->m_usNbTransmission;
}



// public: class PRUDPEndPoint * __thiscall PacketOut::GetEndPoint(void)

PRUDPEndPoint * __thiscall PacketOut::GetEndPoint(PacketOut *this)

{
  return this->m_pEndPoint;
}



// public: void __thiscall PacketOut::SetIORequestContext(class IORequestContext *)

void __thiscall PacketOut::SetIORequestContext(PacketOut *this,IORequestContext *pIORequestContext)

{
  this->m_pIORequestContext = pIORequestContext;
  *(PacketOut **)(pIORequestContext + 8) = this;
  return;
}



// public: class IORequestContext * __thiscall PacketOut::GetIORequestContext(void)

IORequestContext * __thiscall PacketOut::GetIORequestContext(PacketOut *this)

{
  return this->m_pIORequestContext;
}



// public: bool __thiscall PacketOut::Pack(class Buffer *)

bool __thiscall PacketOut::Pack(PacketOut *this,Buffer *pBuffer)

{
  bool bVar1;
  Buffer *pBVar2;
  
  bVar1 = Buffer::AppendData(pBuffer,&this->m_abyPacketBase[0xc],8,0xffffffff);
  if (!bVar1) {
    return false;
  }
  pBVar2 = Packet::GetPayload((Packet *)this);
  if (pBVar2 != (Buffer *)0x0) {
    pBVar2 = Packet::GetPayload((Packet *)this);
    Buffer::operator+=(pBuffer,pBVar2);
  }
  Buffer::AppendCheckSum(pBuffer);
  return true;
}


