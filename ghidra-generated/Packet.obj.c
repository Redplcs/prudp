#include <Platform/Time.h>
#include <Platform/Trace.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Core/RefCountedObject.h>

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

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
    undefined m_abyRefCountedObject[0xc];
    uchar m_ucTypeAndFlags;
    uchar m_ucContextInfo;
    ushort m_usSize;
    ulong m_ulSeqId;
    Buffer *m_pPayload;
    undefined m_abyPeerAddress[8];
    undefined4 m_auIOTime[2];
    ulong m_ulIOResult;
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct Time Time, *PTime;



undefined LAB_00002a13;
undefined __except_list;
pointer `vftable';
undefined LAB_00002a33;

// public: __thiscall Packet::Packet(void)

Packet * __thiscall Packet::Packet(Packet *this)

{
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L1218;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  RefCountedObject::RefCountedObject((RefCountedObject *)this);
  local_4 = 0;
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)this->m_abyPeerAddress);
  local_4 = CONCAT31(local_4._1_3_,1);
  Time::Time((Time *)this->m_auIOTime);
  *(undefined ***)this = &_vftable_;
  this->m_usSize = 8;
  this->m_ulSeqId = 0;
  this->m_ucTypeAndFlags = 0;
  this->m_pPayload = (Buffer *)0x0;
  this->m_ulIOResult = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: virtual void * __thiscall Packet::`scalar deleting destructor'(unsigned int)

void * __thiscall Packet::_scalar_deleting_destructor_(Packet *this,uint shouldDelete)

{
  ~Packet(this);
  if ((shouldDelete & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// public: virtual __thiscall Packet::~Packet(void)

void __thiscall Packet::~Packet(Packet *this)

{
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &_L1233;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  *(undefined ***)this = &_vftable_;
  local_4 = 1;
  if (this->m_pPayload != (Buffer *)0x0) {
    RefCountedObject::ReleaseRef((RefCountedObject *)this->m_pPayload);
  }
  local_4 = local_4 & 0xffffff00;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)this->m_abyPeerAddress);
  local_4 = 0xffffffff;
  RefCountedObject::~RefCountedObject((RefCountedObject *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// protected: bool __thiscall Packet::SetPayload(class Buffer *)

bool __thiscall Packet::SetPayload(Packet *this,Buffer *pBuffer)

{
  ulong uVar1;
  
  this->m_pPayload = pBuffer;
  uVar1 = Buffer::GetContentSize(pBuffer);
  this->m_usSize = this->m_usSize + (short)uVar1;
  return this->m_usSize < 0x1001;
}



// public: class Buffer * __thiscall Packet::GetPayload(void)

Buffer * __thiscall Packet::GetPayload(Packet *this)

{
  return this->m_pPayload;
}



// public: unsigned long __thiscall Packet::GetHeader(void * *)

ulong __thiscall Packet::GetHeader(Packet *this,void **pData)

{
  *pData = &this->m_ucTypeAndFlags;
  return 8;
}



// public: bool __thiscall Packet::Valid(void)

bool __thiscall Packet::Valid(Packet *this)

{
  return this->m_usSize < 0x1000;
}



// public: void __thiscall Packet::SetSeqId(unsigned long)

void __thiscall Packet::SetSeqId(Packet *this,ulong ulValue)

{
  this->m_ulSeqId = ulValue;
  return;
}



// public: unsigned long __thiscall Packet::GetSeqId(void)

ulong __thiscall Packet::GetSeqId(Packet *this)

{
  return this->m_ulSeqId;
}



// public: class PRUDPInetAddress * __thiscall Packet::GetPeerAddress(void)

PRUDPInetAddress * __thiscall Packet::GetPeerAddress(Packet *this)

{
  return (PRUDPInetAddress *)this->m_abyPeerAddress;
}



// public: void __thiscall Packet::SetPeerAddress(class PRUDPInetAddress *)

void __thiscall Packet::SetPeerAddress(Packet *this,PRUDPInetAddress *pAddress)

{
  PRUDPInetAddress::operator=((PRUDPInetAddress *)this->m_abyPeerAddress,pAddress);
  return;
}



// public: void __thiscall Packet::SetType(unsigned char)

void __thiscall Packet::SetType(Packet *this,uchar value)

{
  this->m_ucTypeAndFlags = value & 7;
  return;
}



// public: unsigned char __thiscall Packet::GetType(void)

uchar __thiscall Packet::GetType(Packet *this)

{
  return this->m_ucTypeAndFlags & 7;
}



// public: void __thiscall Packet::SetContextInfo(unsigned char)

void __thiscall Packet::SetContextInfo(Packet *this,uchar value)

{
  this->m_ucContextInfo = value;
  return;
}



// public: unsigned char __thiscall Packet::GetContextInfo(void)

uchar __thiscall Packet::GetContextInfo(Packet *this)

{
  return this->m_ucContextInfo;
}



// public: void __thiscall Packet::SetFlag(unsigned char)

void __thiscall Packet::SetFlag(Packet *this,uchar value)

{
  this->m_ucTypeAndFlags = this->m_ucTypeAndFlags | value & 0xf8;
  return;
}



// public: void __thiscall Packet::ClearFlag(unsigned char)

void __thiscall Packet::ClearFlag(Packet *this,uchar value)

{
  this->m_ucTypeAndFlags = this->m_ucTypeAndFlags & ~(value & 0xf8);
  return;
}



// public: bool __thiscall Packet::FlagSet(unsigned char)

bool __thiscall Packet::FlagSet(Packet *this,uchar value)

{
  return (this->m_ucTypeAndFlags & value) != 0;
}



// public: unsigned short __thiscall Packet::GetSize(void)

ushort __thiscall Packet::GetSize(Packet *this)

{
  return this->m_usSize;
}



// public: void __thiscall Packet::SetIOTime(class Time)

void __thiscall Packet::SetIOTime(Packet *this)

{
  Time::operator=((Time *)this->m_auIOTime,(Time *)&stack0x00000004);
  return;
}



// public: class Time __thiscall Packet::GetIOTime(void)

void __thiscall Packet::GetIOTime(Packet *this)

{
  undefined4 *in_stack_00000004;
  
  *in_stack_00000004 = this->m_auIOTime[0];
  in_stack_00000004[1] = this->m_auIOTime[1];
  return;
}



// public: void __thiscall Packet::SetIOResult(unsigned long)

void __thiscall Packet::SetIOResult(Packet *this,ulong ulValue)

{
  this->m_ulIOResult = ulValue;
  return;
}



// public: unsigned long __thiscall Packet::GetIOResult(void)

ulong __thiscall Packet::GetIOResult(Packet *this)

{
  return this->m_ulIOResult;
}



// public: void __thiscall Packet::Trace(void)

void __thiscall Packet::Trace(Packet *this)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  char *pcVar2;
  
  pcVar2 = (char *)0x10000;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,pcVar2);
  return;
}


