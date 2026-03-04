#include <Platform/Event.h>
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

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct Buffer Buffer, *PBuffer;

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct ICMPSocket ICMPSocket, *PICMPSocket;

struct ICMPSocket { // PlaceHolder Structure
};

typedef struct Event Event, *PEvent;

typedef struct AsyncIOContext AsyncIOContext, *PAsyncIOContext;

struct AsyncIOContext { // PlaceHolder Structure
};

typedef struct Socket Socket, *PSocket;

struct Socket { // PlaceHolder Structure
};



undefined LAB_00002729;
undefined __except_list;
undefined LAB_0000275e;
undefined LAB_00002778;
undefined __imp__ntohl@4;
undefined __imp__ntohs@4;

// public: __thiscall ICMPSocket::ICMPSocket(void)

ICMPSocket * __thiscall ICMPSocket::ICMPSocket(ICMPSocket *this)

{
  AsyncIOContext *this_00;
  undefined4 uVar1;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L43840;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  Socket::Socket((Socket *)this,1);
  local_4 = 0;
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)(this + 0x14));
  local_4._0_1_ = 1;
  Buffer::Buffer((Buffer *)(this + 0x18),0x1000);
  local_4._0_1_ = 2;
  this[0x44] = (ICMPSocket)0x0;
  this_00 = operator_new(0x20);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (this_00 != (AsyncIOContext *)0x0) {
    uVar1 = AsyncIOContext::AsyncIOContext(this_00);
    *(undefined4 *)(this + 0x38) = uVar1;
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return this;
  }
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: __thiscall ICMPSocket::~ICMPSocket(void)

void __thiscall ICMPSocket::~ICMPSocket(ICMPSocket *this)

{
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &_L43855;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_4 = 2;
  Socket::Close((Socket *)this);
  operator_delete(*(void **)(this + 0x38));
  local_4._0_1_ = 1;
  Buffer::~Buffer((Buffer *)(this + 0x18));
  local_4 = (uint)local_4._1_3_ << 8;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)(this + 0x14));
  local_4 = 0xffffffff;
  Socket::~Socket((Socket *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall ICMPSocket::SetCompletionEvent(class Event *)

void __thiscall ICMPSocket::SetCompletionEvent(ICMPSocket *this,Event *param_1)

{
  AsyncIOContext::SetEvent(*(AsyncIOContext **)(this + 0x38),param_1);
  return;
}



// public: bool __thiscall ICMPSocket::Bind(class PRUDPInetAddress *)

bool __thiscall ICMPSocket::Bind(ICMPSocket *this,PRUDPInetAddress *param_1)

{
  bool bVar1;
  
  bVar1 = Socket::SetBuffers((Socket *)this);
  if (!bVar1) {
    return false;
  }
  Socket::SetAsync((Socket *)this,true);
  bVar1 = Socket::Bind((Socket *)this,param_1);
  return bVar1;
}



// public: void __thiscall ICMPSocket::QueueRecv(void)

void __thiscall ICMPSocket::QueueRecv(ICMPSocket *this)

{
  int iVar1;
  Event *this_00;
  
  this[0x44] = (ICMPSocket)0x1;
  iVar1 = Socket::Recv((Socket *)this,(Buffer *)(this + 0x18),(PRUDPInetAddress *)(this + 0x14),
                       (ulong *)(this + 0x3c),*(AsyncIOContext **)(this + 0x38));
  if (iVar1 == -1) {
    this_00 = AsyncIOContext::GetEvent(*(AsyncIOContext **)(this + 0x38));
    Event::Set(this_00);
  }
  return;
}



// public: void __thiscall ICMPSocket::TryIOCompletion(void)

void __thiscall ICMPSocket::TryIOCompletion(ICMPSocket *this)

{
  if (this[0x44] != (ICMPSocket)0x0) {
    Socket::TryIOCompletion((Socket *)this,*(AsyncIOContext **)(this + 0x38));
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: unsigned long __thiscall ICMPSocket::GetIOCompletionResult(class PRUDPInetAddress *)

ulong __thiscall ICMPSocket::GetIOCompletionResult(ICMPSocket *this,PRUDPInetAddress *param_1)

{
  ulong uVar1;
  uchar *puVar2;
  undefined4 uVar3;
  ulong uVar4;
  TraceOutput *pTVar5;
  TraceOutput *this_00;
  ushort unaff_SI;
  int unaff_FS_OFFSET;
  PRUDPInetAddress *in_stack_0000000c;
  char *pcVar6;
  ulong local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L43873;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_10 = 0;
  uVar1 = Socket::GetIOResult((Socket *)this,*(AsyncIOContext **)(this + 0x38),&local_10);
  if (uVar1 == 0) {
    Buffer::SetContentSize((Buffer *)(this + 0x18),local_10);
    puVar2 = Buffer::GetContentPtr((Buffer *)(this + 0x18));
    if (puVar2[0x15] == '\x03') {
      uVar3 = (*___imp__ntohs_4)(*(undefined2 *)(puVar2 + 0x32));
      uVar4 = (*___imp__ntohl_4)(*(undefined4 *)(puVar2 + 0x2c),uVar3);
      PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)&local_c,uVar4,unaff_SI);
      if (puVar2[0x14] == '\x03') {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 0x8000000;
      }
      TraceICMPErrorPacket(this,(PRUDPInetAddress *)&local_c,puVar2,uVar4);
      PRUDPInetAddress::operator=(in_stack_0000000c,(PRUDPInetAddress *)&local_c);
      PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&local_c);
    }
  }
  else {
    pcVar6 = (char *)0x1;
    pTVar5 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar5,pcVar6);
  }
  this[0x44] = (ICMPSocket)0x0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_4;
  return uVar1;
}



// private: void __thiscall ICMPSocket::TraceICMPErrorPacket(class PRUDPInetAddress *,void
// *,unsigned long)

void __thiscall
ICMPSocket::TraceICMPErrorPacket
          (ICMPSocket *this,PRUDPInetAddress *param_1,void *param_2,ulong param_3)

{
  return;
}


