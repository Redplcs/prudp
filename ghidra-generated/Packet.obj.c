#include <stdbool.h>

typedef unsigned char   undefined;

typedef unsigned int    undefined4;
typedef struct Buffer Buffer, *PBuffer;

struct Buffer { // PlaceHolder Structure
};

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

struct RefCountedObject { // PlaceHolder Structure
};

typedef struct TraceOutput TraceOutput, *PTraceOutput;

struct TraceOutput { // PlaceHolder Structure
};

typedef struct Time Time, *PTime;

struct Time { // PlaceHolder Structure
};



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
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)(this + 0x18));
  local_4 = CONCAT31(local_4._1_3_,1);
  Time::Time((Time *)(this + 0x20));
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)(this + 0xe) = 8;
  *(undefined4 *)(this + 0x10) = 0;
  this[0xc] = (Packet)0x0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: virtual void * __thiscall Packet::`scalar deleting destructor'(unsigned int)

void * __thiscall Packet::_scalar_deleting_destructor_(Packet *this,unsigned int param_1)

{
  ~Packet(this);
  if ((param_1 & 1) != 0) {
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
  unsigned int local_4;
  
  puStack_8 = &_L1233;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  *(undefined ***)this = &_vftable_;
  local_4 = 1;
  if (*(RefCountedObject **)(this + 0x14) != (RefCountedObject *)0x0) {
    RefCountedObject::ReleaseRef(*(RefCountedObject **)(this + 0x14));
  }
  local_4 = local_4 & 0xffffff00;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)(this + 0x18));
  local_4 = 0xffffffff;
  RefCountedObject::~RefCountedObject((RefCountedObject *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// protected: bool __thiscall Packet::SetPayload(class Buffer *)

bool __thiscall Packet::SetPayload(Packet *this,Buffer *param_1)

{
  unsigned long uVar1;
  
  *(Buffer **)(this + 0x14) = param_1;
  uVar1 = Buffer::GetContentSize(param_1);
  *(short *)(this + 0xe) = *(short *)(this + 0xe) + (short)uVar1;
  return *(unsigned short *)(this + 0xe) < 0x1001;
}



// public: class Buffer * __thiscall Packet::GetPayload(void)

Buffer * __thiscall Packet::GetPayload(Packet *this)

{
  return *(Buffer **)(this + 0x14);
}



// public: unsigned long __thiscall Packet::GetHeader(void * *)

unsigned long __thiscall Packet::GetHeader(Packet *this,void **param_1)

{
  *param_1 = this + 0xc;
  return 8;
}



// public: bool __thiscall Packet::Valid(void)

bool __thiscall Packet::Valid(Packet *this)

{
  return *(unsigned short *)(this + 0xe) < 0x1000;
}



// public: void __thiscall Packet::SetSeqId(unsigned long)

void __thiscall Packet::SetSeqId(Packet *this,unsigned long param_1)

{
  *(unsigned long *)(this + 0x10) = param_1;
  return;
}



// public: unsigned long __thiscall Packet::GetSeqId(void)

unsigned long __thiscall Packet::GetSeqId(Packet *this)

{
  return *(unsigned long *)(this + 0x10);
}



// public: class PRUDPInetAddress * __thiscall Packet::GetPeerAddress(void)

PRUDPInetAddress * __thiscall Packet::GetPeerAddress(Packet *this)

{
  return (PRUDPInetAddress *)(this + 0x18);
}



// public: void __thiscall Packet::SetPeerAddress(class PRUDPInetAddress *)

void __thiscall Packet::SetPeerAddress(Packet *this,PRUDPInetAddress *param_1)

{
  PRUDPInetAddress::operator=((PRUDPInetAddress *)(this + 0x18),param_1);
  return;
}



// public: void __thiscall Packet::SetType(unsigned char)

void __thiscall Packet::SetType(Packet *this,unsigned char param_1)

{
  this[0xc] = (Packet)(param_1 & 7);
  return;
}



// public: unsigned char __thiscall Packet::GetType(void)

unsigned char __thiscall Packet::GetType(Packet *this)

{
  return (unsigned char)this[0xc] & 7;
}



// public: void __thiscall Packet::SetContextInfo(unsigned char)

void __thiscall Packet::SetContextInfo(Packet *this,unsigned char param_1)

{
  this[0xd] = (Packet)param_1;
  return;
}



// public: unsigned char __thiscall Packet::GetContextInfo(void)

unsigned char __thiscall Packet::GetContextInfo(Packet *this)

{
  return (unsigned char)this[0xd];
}



// public: void __thiscall Packet::SetFlag(unsigned char)

void __thiscall Packet::SetFlag(Packet *this,unsigned char param_1)

{
  this[0xc] = (Packet)((unsigned char)this[0xc] | param_1 & 0xf8);
  return;
}



// public: void __thiscall Packet::ClearFlag(unsigned char)

void __thiscall Packet::ClearFlag(Packet *this,unsigned char param_1)

{
  this[0xc] = (Packet)((unsigned char)this[0xc] & ~(param_1 & 0xf8));
  return;
}



// public: bool __thiscall Packet::FlagSet(unsigned char)

bool __thiscall Packet::FlagSet(Packet *this,unsigned char param_1)

{
  return ((unsigned char)this[0xc] & param_1) != 0;
}



// public: unsigned short __thiscall Packet::GetSize(void)

unsigned short __thiscall Packet::GetSize(Packet *this)

{
  return *(unsigned short *)(this + 0xe);
}



// public: void __thiscall Packet::SetIOTime(class Time)

void __thiscall Packet::SetIOTime(Packet *this)

{
  Time::operator=((Time *)(this + 0x20),(Time *)&stack0x00000004);
  return;
}



// public: class Time __thiscall Packet::GetIOTime(void)

void __thiscall Packet::GetIOTime(Packet *this)

{
  undefined4 *in_stack_00000004;
  
  *in_stack_00000004 = *(undefined4 *)(this + 0x20);
  in_stack_00000004[1] = *(undefined4 *)(this + 0x24);
  return;
}



// public: void __thiscall Packet::SetIOResult(unsigned long)

void __thiscall Packet::SetIOResult(Packet *this,unsigned long param_1)

{
  *(unsigned long *)(this + 0x28) = param_1;
  return;
}



// public: unsigned long __thiscall Packet::GetIOResult(void)

unsigned long __thiscall Packet::GetIOResult(Packet *this)

{
  return *(unsigned long *)(this + 0x28);
}



// public: void __thiscall Packet::Trace(void)

void __thiscall Packet::Trace(Packet *this)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  char *pcVar2;
  
  pcVar2 = (char *)0x10000;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(unsigned long)pTVar1,pcVar2);
  return;
}


