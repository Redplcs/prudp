#include <Platform/CriticalSection.h>
#include <Platform/ScopedCS.h>
#include <Platform/Trace.h>
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

typedef struct CriticalSection CriticalSection, *PCriticalSection;

typedef struct SlidingWindow SlidingWindow, *PSlidingWindow;

struct SlidingWindow { // PlaceHolder Structure
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
};

typedef struct ScopedCS ScopedCS, *PScopedCS;

typedef struct pair<unsigned_long_const_,class_PacketOut*> pair<unsigned_long_const_,class_PacketOut*>, *Ppair<unsigned_long_const_,class_PacketOut*>;

struct pair<unsigned_long_const_,class_PacketOut*> { // PlaceHolder Structure
};

typedef struct map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_> map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>, *Pmap<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>;

struct map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_> { // PlaceHolder Structure
};

typedef struct pair<class_std::_Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::iterator,bool> pair<class_std::_Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::iterator,bool>, *Ppair<class_std::_Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::iterator,bool>;

struct pair<class_std::_Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::iterator,bool> { // PlaceHolder Structure
};

typedef struct _Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_> _Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>, *P_Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>;

struct _Tree<unsigned_long,struct_std::pair<unsigned_long_const_,class_PacketOut*>,struct_std::map<unsigned_long,class_PacketOut*,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_>::_Kfn,struct_std::less<unsigned_long>,class_std::allocator<class_PacketOut*>_> { // PlaceHolder Structure
};

typedef struct iterator iterator, *Piterator;

struct iterator { // PlaceHolder Structure
};

typedef struct const_iterator const_iterator, *Pconst_iterator;

struct const_iterator { // PlaceHolder Structure
};

typedef struct _Node _Node, *P_Node;

struct _Node { // PlaceHolder Structure
};



undefined LAB_00003f11;
undefined __except_list;
undefined __imp_??1_Lockit@std@@QAE@XZ;
undefined __imp_??0_Lockit@std@@QAE@XZ;
uint _Nilrefs;
_Node *_Nil;
undefined LAB_00003f3b;
TerminatedCString s_<unspecified>;
undefined LAB_00003f61;
TerminatedCString s_m_ulLeftEdge_<=_m_ulRightEdge;
undefined LAB_00003f78;
TerminatedCString s_SlidingWindow.cpp;
undefined LAB_00003fa1;
TerminatedCString s_(m_ulLeftEdge_==_m_ulRightEdge)_;
undefined LAB_00003fb8;
TerminatedCString s_(*it).second->Valid()==true;
undefined LAB_00003fd8;
TerminatedCString s_ulSeqId_==_(*it).second->GetSeqI;
undefined LAB_00003ff9;
undefined LAB_00004022;
undefined LAB_00004039;
undefined LAB_00004059;
undefined LAB_00004079;
undefined LAB_00004099;

// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall SlidingWindow::SlidingWindow(unsigned short)

SlidingWindow * __thiscall SlidingWindow::SlidingWindow(SlidingWindow *this,ushort param_1)

{
  _Node *p_Var1;
  void *pvVar2;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L5534;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  this[1] = param_1._0_1_;
  *this = param_1._0_1_;
  this[8] = (SlidingWindow)0x0;
  (*___imp___0_Lockit_std__QAE_XZ)();
  uStack_4 = 0;
  if (std::_Tree<>::_Nil == (_Node *)0x0) {
    std::_Tree<>::_Nil = operator_new(0x18);
    *(undefined4 *)(std::_Tree<>::_Nil + 4) = 0;
    *(undefined4 *)(std::_Tree<>::_Nil + 0x14) = 1;
    *(undefined4 *)std::_Tree<>::_Nil = 0;
    *(undefined4 *)(std::_Tree<>::_Nil + 8) = 0;
  }
  p_Var1 = std::_Tree<>::_Nil;
  std::_Tree<>::_Nilrefs = std::_Tree<>::_Nilrefs + 1;
  pvVar2 = operator_new(0x18);
  *(_Node **)((int)pvVar2 + 4) = p_Var1;
  *(undefined4 *)((int)pvVar2 + 0x14) = 0;
  *(void **)(this + 4) = pvVar2;
  *(undefined4 *)(this + 0xc) = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
  uStack_4 = 0xffffffff;
  (*___imp___1_Lockit_std__QAE_XZ)();
  uStack_4 = 1;
  CriticalSection::CriticalSection((CriticalSection *)(this + 0x24));
  *(ushort *)(this + 0x10) = param_1;
  *(undefined4 *)(this + 0x14) = 1;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined4 *)(this + 0x1c) = 1;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return this;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::~map<unsigned long,class PacketOut *,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >(void)

void __thiscall std::map<>::~map<>(map<> *this)

{
  map<> *local_4;
  
  local_4 = this;
  _Tree<>::erase((_Tree<> *)this,&local_4,**(undefined4 **)(this + 4),*(undefined4 **)(this + 4));
  operator_delete(*(void **)(this + 4));
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  (*___imp___0_Lockit_std__QAE_XZ)();
  _Tree<>::_Nilrefs = _Tree<>::_Nilrefs - 1;
  if (_Tree<>::_Nilrefs == 0) {
    operator_delete(_Tree<>::_Nil);
    _Tree<>::_Nil = (_Node *)0x0;
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall SlidingWindow::~SlidingWindow(void)

void __thiscall SlidingWindow::~SlidingWindow(SlidingWindow *this)

{
  int unaff_FS_OFFSET;
  ScopedCS local_18 [8];
  SlidingWindow *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &_L5811;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_4 = 1;
  local_10 = this;
  ScopedCS::ScopedCS(local_18,(CriticalSection *)(this + 0x24),s_<unspecified>);
  local_4._0_1_ = 2;
  Purge(this);
  local_4._0_1_ = 1;
  ScopedCS::~ScopedCS(local_18);
  local_4 = (uint)local_4._1_3_ << 8;
  CriticalSection::~CriticalSection((CriticalSection *)(this + 0x24));
  local_4 = 0xffffffff;
  std::_Tree<>::erase((_Tree<> *)this,&local_10,**(undefined4 **)(this + 4),
                      *(undefined4 **)(this + 4));
  operator_delete(*(void **)(this + 4));
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  (*___imp___0_Lockit_std__QAE_XZ)();
  std::_Tree<>::_Nilrefs = std::_Tree<>::_Nilrefs - 1;
  if (std::_Tree<>::_Nilrefs == 0) {
    operator_delete(std::_Tree<>::_Nil);
    std::_Tree<>::_Nil = (_Node *)0x0;
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall SlidingWindow::Purge(void)

void __thiscall SlidingWindow::Purge(SlidingWindow *this)

{
  code *pcVar1;
  _Node *p_Var2;
  TraceOutput *pTVar3;
  TraceOutput *this_00;
  _Node *p_Var4;
  _Node *p_Var5;
  int unaff_FS_OFFSET;
  char *pcVar6;
  ScopedCS local_14 [4];
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L6077;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)(this + 0x24),s_<unspecified>);
  pcVar1 = ___imp___0_Lockit_std__QAE_XZ;
  local_4 = 0;
  p_Var4 = *(_Node **)*(_Node **)(this + 4);
  if (p_Var4 != *(_Node **)(this + 4)) {
    do {
      (*pcVar1)();
      p_Var5 = *(_Node **)(p_Var4 + 8);
      local_4._0_1_ = 1;
      if (p_Var5 == std::_Tree<>::_Nil) {
        p_Var2 = *(_Node **)(p_Var4 + 4);
        p_Var5 = p_Var4;
        if (p_Var4 == *(_Node **)(p_Var2 + 8)) {
          do {
            p_Var5 = p_Var2;
            p_Var2 = *(_Node **)(p_Var5 + 4);
          } while (p_Var5 == *(_Node **)(p_Var2 + 8));
        }
        if (*(_Node **)(p_Var5 + 8) != p_Var2) {
          p_Var5 = p_Var2;
        }
      }
      else {
        (*pcVar1)();
        for (p_Var2 = *(_Node **)p_Var5; p_Var2 != std::_Tree<>::_Nil; p_Var2 = *(_Node **)p_Var2) {
          p_Var5 = p_Var2;
        }
        (*___imp___1_Lockit_std__QAE_XZ)();
      }
      local_4 = (uint)local_4._1_3_ << 8;
      (*___imp___1_Lockit_std__QAE_XZ)();
      Packet::GetSeqId(*(Packet **)(p_Var4 + 0x10));
      pcVar6 = (char *)0x0;
      pTVar3 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_00,(ulong)pTVar3,pcVar6);
      RefCountedObject::ReleaseRef(*(RefCountedObject **)(p_Var4 + 0x10));
      std::_Tree<>::erase((_Tree<> *)this,auStack_10,p_Var4);
      p_Var4 = p_Var5;
    } while (p_Var5 != *(_Node **)(this + 4));
  }
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(this + 0x20) = 0;
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// public: void __thiscall SlidingWindow::Push(class PacketOut *)

void __thiscall SlidingWindow::Push(SlidingWindow *this,PacketOut *param_1)

{
  uchar uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int unaff_FS_OFFSET;
  ScopedCS local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  pair<> local_24 [8];
  pair<> local_1c [12];
  int local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L6144;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_38,(CriticalSection *)(this + 0x24),s_<unspecified>);
  local_4 = 0;
  Platform::SystemCheck
            (*(uint *)(this + 0x1c) <= *(uint *)(this + 0x18),s_m_ulLeftEdge_<__m_ulRightEdge,
             s_SlidingWindow_cpp,0x30);
  RefCountedObject::AcquireRef((RefCountedObject *)param_1);
  uVar1 = Packet::GetType((Packet *)param_1);
  if (uVar1 == '\x01') {
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  }
  local_2c = *(undefined4 *)(this + 0x14);
  local_28 = 0;
  puVar2 = (undefined4 *)std::_Tree<>::insert((_Tree<> *)this,local_24);
  local_34 = *puVar2;
  local_30 = puVar2[1];
  piVar3 = (int *)std::pair<>::pair<>(local_1c,(iterator *)&local_34,(bool *)&local_30);
  local_10 = piVar3[1];
  *(PacketOut **)(*piVar3 + 0x10) = param_1;
  Packet::SetSeqId((Packet *)param_1,*(ulong *)(this + 0x14));
  local_4 = 0xffffffff;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  ScopedCS::~ScopedCS(local_38);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall SlidingWindow::Acknowledged(unsigned long)

void __thiscall SlidingWindow::Acknowledged(SlidingWindow *this,ulong param_1)

{
  _Node *p_Var1;
  Packet *this_00;
  byte bVar2;
  int *piVar3;
  _Node *p_Var4;
  _Node *p_Var5;
  int unaff_FS_OFFSET;
  ScopedCS local_14 [4];
  ulong local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L6351;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)(this + 0x24),s_<unspecified>);
  local_4 = 0;
  Platform::SystemCheck
            (*(uint *)(this + 0x1c) <= *(uint *)(this + 0x18),s_m_ulLeftEdge_<__m_ulRightEdge,
             s_SlidingWindow_cpp,0x40);
  piVar3 = (int *)std::_Tree<>::find((_Tree<> *)this,&local_10);
  p_Var1 = (_Node *)*piVar3;
  if (p_Var1 == *(_Node **)(this + 4)) goto LAB_00002aa1;
  this_00 = *(Packet **)(p_Var1 + 0x10);
  if (param_1 == *(ulong *)(this + 0x1c)) {
    (*___imp___0_Lockit_std__QAE_XZ)();
    local_4._0_1_ = 1;
    if (*(_Node **)(p_Var1 + 8) == std::_Tree<>::_Nil) {
      p_Var4 = *(_Node **)(p_Var1 + 4);
      p_Var5 = p_Var1;
      if (p_Var1 == *(_Node **)(p_Var4 + 8)) {
        do {
          p_Var5 = p_Var4;
          p_Var4 = *(_Node **)(p_Var5 + 4);
        } while (p_Var5 == *(_Node **)(p_Var4 + 8));
      }
      if (*(_Node **)(p_Var5 + 8) != p_Var4) goto LAB_00002a38;
    }
    else {
      p_Var4 = std::_Tree<>::_Min(*(_Node **)(p_Var1 + 8));
LAB_00002a38:
      p_Var5 = p_Var4;
    }
    local_4 = (uint)local_4._1_3_ << 8;
    (*___imp___1_Lockit_std__QAE_XZ)();
    if (p_Var5 == *(_Node **)(this + 4)) {
      *(int *)(this + 0x1c) = *(int *)(this + 0x14);
      Platform::SystemCheck
                (*(int *)(this + 0x14) == *(int *)(this + 0x18),s__m_ulLeftEdge____m_ulRightEdge__,
                 s_SlidingWindow_cpp,0x50);
    }
    else {
      *(undefined4 *)(this + 0x1c) = *(undefined4 *)(p_Var5 + 0xc);
    }
  }
  std::_Tree<>::erase((_Tree<> *)this,&local_10,p_Var1);
  bVar2 = Packet::GetType(this_00);
  if ((bVar2 & 1) != 0) {
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
  }
  RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
LAB_00002aa1:
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// public: class PacketOut * __thiscall SlidingWindow::GetNextToSend(void)

PacketOut * __thiscall SlidingWindow::GetNextToSend(SlidingWindow *this)

{
  SlidingWindow *pSVar1;
  _Node *p_Var2;
  _Node *p_Var3;
  PacketOut *pPVar4;
  bool bVar5;
  _Node **pp_Var6;
  int unaff_FS_OFFSET;
  char *pcVar7;
  char *pcVar8;
  ulong uVar9;
  ScopedCS local_18 [4];
  _Node *local_14;
  _Node *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L6605;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_18,(CriticalSection *)(this + 0x24),s_<unspecified>);
  pSVar1 = this + 0x18;
  local_4 = 0;
  Platform::SystemCheck
            (*(uint *)(this + 0x1c) <= *(uint *)(this + 0x18),s_m_ulLeftEdge_<__m_ulRightEdge,
             s_SlidingWindow_cpp,0x62);
  if (*(ulong *)pSVar1 - *(int *)(this + 0x1c) < (uint)*(ushort *)(this + 0x10)) {
    local_14 = std::_Tree<>::_Lbound((_Tree<> *)this,(ulong *)pSVar1);
    p_Var2 = *(_Node **)(this + 4);
    if ((local_14 == p_Var2) || (*(uint *)pSVar1 < *(uint *)(local_14 + 0xc))) {
      local_10 = p_Var2;
      pp_Var6 = &local_10;
    }
    else {
      pp_Var6 = &local_14;
    }
    p_Var3 = *pp_Var6;
    if (p_Var3 != p_Var2) {
      uVar9 = 0x69;
      pcVar8 = s_SlidingWindow_cpp;
      *(ulong *)pSVar1 = *(ulong *)pSVar1 + 1;
      pcVar7 = s___it__second_>Valid____true;
      bVar5 = Packet::Valid(*(Packet **)(p_Var3 + 0x10));
      Platform::SystemCheck(bVar5,pcVar7,pcVar8,uVar9);
      pPVar4 = *(PacketOut **)(p_Var3 + 0x10);
      local_4 = 0xffffffff;
      ScopedCS::~ScopedCS(local_18);
      *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
      return pPVar4;
    }
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_18);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return (PacketOut *)0x0;
}



// public: class PacketOut * __thiscall SlidingWindow::GetPacket(unsigned long)

PacketOut * __thiscall SlidingWindow::GetPacket(SlidingWindow *this,ulong param_1)

{
  _Node *p_Var1;
  _Node *p_Var2;
  PacketOut *pPVar3;
  bool bVar4;
  _Node **pp_Var5;
  ulong uVar6;
  int unaff_FS_OFFSET;
  char *pcVar7;
  char *pcVar8;
  ulong uVar9;
  ScopedCS local_18 [4];
  _Node *local_14;
  _Node *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L6864;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_18,(CriticalSection *)(this + 0x24),s_<unspecified>);
  local_4 = 0;
  Platform::SystemCheck
            (*(uint *)(this + 0x1c) <= *(uint *)(this + 0x18),s_m_ulLeftEdge_<__m_ulRightEdge,
             s_SlidingWindow_cpp,0x77);
  local_14 = std::_Tree<>::_Lbound((_Tree<> *)this,&param_1);
  p_Var1 = *(_Node **)(this + 4);
  if ((local_14 == p_Var1) || (param_1 < *(uint *)(local_14 + 0xc))) {
    local_10 = p_Var1;
    pp_Var5 = &local_10;
  }
  else {
    pp_Var5 = &local_14;
  }
  p_Var2 = *pp_Var5;
  if (p_Var2 != p_Var1) {
    uVar9 = 0x7c;
    pcVar8 = s_SlidingWindow_cpp;
    pcVar7 = s_ulSeqId______it__second_>GetSeqI;
    uVar6 = Packet::GetSeqId(*(Packet **)(p_Var2 + 0x10));
    Platform::SystemCheck(param_1 == uVar6,pcVar7,pcVar8,uVar9);
    uVar6 = 0x7d;
    pcVar8 = s_SlidingWindow_cpp;
    pcVar7 = s___it__second_>Valid____true;
    bVar4 = Packet::Valid(*(Packet **)(p_Var2 + 0x10));
    Platform::SystemCheck(bVar4,pcVar7,pcVar8,uVar6);
    pPVar3 = *(PacketOut **)(p_Var2 + 0x10);
    local_4 = 0xffffffff;
    ScopedCS::~ScopedCS(local_18);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return pPVar3;
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_18);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return (PacketOut *)0x0;
}



// public: bool __thiscall SlidingWindow::ReadyToSend(void)

bool __thiscall SlidingWindow::ReadyToSend(SlidingWindow *this)

{
  SlidingWindow *local_4;
  
  local_4 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_4,(CriticalSection *)(this + 0x24),s_<unspecified>);
  if (((uint)(*(int *)(this + 0x18) - *(int *)(this + 0x1c)) < (uint)*(ushort *)(this + 0x10)) &&
     (*(int *)(this + 0x18) != *(int *)(this + 0x14))) {
    ScopedCS::~ScopedCS((ScopedCS *)&local_4);
    return true;
  }
  ScopedCS::~ScopedCS((ScopedCS *)&local_4);
  return false;
}



// public: bool __thiscall SlidingWindow::Empty(void)

bool __thiscall SlidingWindow::Empty(SlidingWindow *this)

{
  int iVar1;
  int iVar2;
  SlidingWindow *local_4;
  
  local_4 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_4,(CriticalSection *)(this + 0x24),s_<unspecified>);
  iVar1 = *(int *)(this + 0x1c);
  iVar2 = *(int *)(this + 0x14);
  ScopedCS::~ScopedCS((ScopedCS *)&local_4);
  return iVar1 == iVar2;
}



// public: class std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut
// *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator __thiscall SlidingWindow::AcquireIterator(void)

void __thiscall SlidingWindow::AcquireIterator(SlidingWindow *this)

{
  undefined4 *in_stack_00000004;
  
  CriticalSection::Enter((CriticalSection *)(this + 0x24));
  *in_stack_00000004 = **(undefined4 **)(this + 4);
  return;
}



// public: class PacketOut * __thiscall SlidingWindow::GetPacket(class std::_Tree<unsigned
// long,struct std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class
// PacketOut *,struct std::less<unsigned long>,class std::allocator<class PacketOut *>
// >::_Kfn,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::iterator)

PacketOut * __thiscall SlidingWindow::GetPacket(SlidingWindow *this,int param_2)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  
  if (param_2 != *(int *)(this + 4)) {
    uVar4 = 0x99;
    pcVar3 = s_SlidingWindow_cpp;
    pcVar2 = s___it__second_>Valid____true;
    bVar1 = Packet::Valid(*(Packet **)(param_2 + 0x10));
    Platform::SystemCheck(bVar1,pcVar2,pcVar3,uVar4);
    return *(PacketOut **)(param_2 + 0x10);
  }
  return (PacketOut *)0x0;
}



// public: void __thiscall SlidingWindow::ReleaseIterator(void)

void __thiscall SlidingWindow::ReleaseIterator(SlidingWindow *this)

{
  CriticalSection::Leave((CriticalSection *)(this + 0x24));
  return;
}



// public: bool __thiscall SlidingWindow::DataPending(void)

bool __thiscall SlidingWindow::DataPending(SlidingWindow *this)

{
  int iVar1;
  SlidingWindow *local_4;
  
  local_4 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_4,(CriticalSection *)(this + 0x24),s_<unspecified>);
  iVar1 = *(int *)(this + 0x20);
  ScopedCS::~ScopedCS((ScopedCS *)&local_4);
  return iVar1 != 0;
}



// public: unsigned long __thiscall SlidingWindow::NbDataPending(void)

ulong __thiscall SlidingWindow::NbDataPending(SlidingWindow *this)

{
  ulong uVar1;
  SlidingWindow *local_4;
  
  local_4 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_4,(CriticalSection *)(this + 0x24),s_<unspecified>);
  uVar1 = *(ulong *)(this + 0x20);
  ScopedCS::~ScopedCS((ScopedCS *)&local_4);
  return uVar1;
}



// public: void __thiscall SlidingWindow::Trace(void)

void __thiscall SlidingWindow::Trace(SlidingWindow *this)

{
  int local_4;
  
  local_4 = **(int **)(this + 4);
  if ((int *)local_4 != *(int **)(this + 4)) {
    do {
      Packet::Trace(*(Packet **)(local_4 + 0x10));
      std::_Tree<>::const_iterator::_Inc((const_iterator *)&local_4);
    } while (local_4 != *(int *)(this + 4));
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: class std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut
// *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator __thiscall std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::erase(class
// std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut *>,struct
// std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator)

undefined4 * __thiscall std::_Tree<>::erase(_Tree<> *this,undefined4 *param_2,_Node *param_3)

{
  _Node *p_Var1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  _Node *p_Var6;
  _Node *p_Var7;
  code *pcVar8;
  _Node *p_Var9;
  _Node *p_Var10;
  int *piVar11;
  int unaff_FS_OFFSET;
  _Node *local_1c;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  p_Var7 = param_3;
  uStack_4 = 0xffffffff;
  puStack_8 = &_L8347;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  const_iterator::_Inc((const_iterator *)&param_3);
  pcVar8 = ___imp___0_Lockit_std__QAE_XZ;
  local_1c = p_Var7;
  (*___imp___0_Lockit_std__QAE_XZ)();
  p_Var10 = *(_Node **)p_Var7;
  uStack_4 = 0;
  if (p_Var10 == _Nil) {
    p_Var10 = *(_Node **)(p_Var7 + 8);
  }
  else {
    p_Var1 = *(_Node **)(p_Var7 + 8);
    if (p_Var1 != _Nil) {
      (*pcVar8)();
      for (p_Var10 = *(_Node **)p_Var1; p_Var10 != _Nil; p_Var10 = *(_Node **)p_Var10) {
        p_Var1 = p_Var10;
      }
      (*___imp___1_Lockit_std__QAE_XZ)();
      p_Var10 = *(_Node **)(p_Var1 + 8);
      local_1c = p_Var1;
      if (p_Var1 != p_Var7) {
        *(_Node **)(*(int *)p_Var7 + 4) = p_Var1;
        *(int *)p_Var1 = *(int *)p_Var7;
        if (p_Var1 == *(_Node **)(p_Var7 + 8)) {
          *(_Node **)(p_Var10 + 4) = p_Var1;
        }
        else {
          *(int *)(p_Var10 + 4) = *(int *)(p_Var1 + 4);
          **(int **)(p_Var1 + 4) = (int)p_Var10;
          *(int *)(p_Var1 + 8) = *(int *)(p_Var7 + 8);
          *(_Node **)(*(int *)(p_Var7 + 8) + 4) = p_Var1;
        }
        if (*(_Node **)(*(int *)(this + 4) + 4) == p_Var7) {
          *(_Node **)(*(int *)(this + 4) + 4) = p_Var1;
        }
        else {
          puVar2 = *(undefined4 **)(p_Var7 + 4);
          if ((_Node *)*puVar2 == p_Var7) {
            *puVar2 = p_Var1;
          }
          else {
            puVar2[2] = p_Var1;
          }
        }
        local_1c = p_Var7;
        *(int *)(p_Var1 + 4) = *(int *)(p_Var7 + 4);
        iVar3 = *(int *)(p_Var1 + 0x14);
        *(int *)(p_Var1 + 0x14) = *(int *)(p_Var7 + 0x14);
        *(int *)(p_Var7 + 0x14) = iVar3;
        goto LAB_0000306b;
      }
    }
  }
  *(int *)(p_Var10 + 4) = *(int *)(local_1c + 4);
  if (*(_Node **)(*(int *)(this + 4) + 4) == p_Var7) {
    *(_Node **)(*(int *)(this + 4) + 4) = p_Var10;
  }
  else {
    puVar2 = *(undefined4 **)(p_Var7 + 4);
    if ((_Node *)*puVar2 == p_Var7) {
      *puVar2 = p_Var10;
    }
    else {
      puVar2[2] = p_Var10;
    }
  }
  if ((_Node *)**(int **)(this + 4) == p_Var7) {
    if (*(_Node **)(p_Var7 + 8) == _Nil) {
      **(int **)(this + 4) = *(int *)(p_Var7 + 4);
    }
    else {
      (*pcVar8)();
      p_Var9 = *(_Node **)p_Var10;
      p_Var1 = p_Var10;
      while (p_Var6 = p_Var9, p_Var6 != _Nil) {
        p_Var1 = p_Var6;
        p_Var9 = *(_Node **)p_Var6;
      }
      (*___imp___1_Lockit_std__QAE_XZ)();
      **(undefined4 **)(this + 4) = p_Var1;
    }
  }
  if (*(_Node **)(*(int *)(this + 4) + 8) == p_Var7) {
    if (*(_Node **)p_Var7 == _Nil) {
      *(int *)(*(int *)(this + 4) + 8) = *(int *)(p_Var7 + 4);
    }
    else {
      (*pcVar8)();
      p_Var1 = *(_Node **)(p_Var10 + 8);
      p_Var7 = p_Var10;
      while (p_Var9 = p_Var1, p_Var9 != _Nil) {
        p_Var7 = p_Var9;
        p_Var1 = *(_Node **)(p_Var9 + 8);
      }
      (*___imp___1_Lockit_std__QAE_XZ)();
      *(_Node **)(*(int *)(this + 4) + 8) = p_Var7;
    }
  }
LAB_0000306b:
  if (*(int *)(local_1c + 0x14) == 1) {
    if (p_Var10 != *(_Node **)(*(int *)(this + 4) + 4)) {
      do {
        if (*(int *)(p_Var10 + 0x14) != 1) break;
        piVar11 = *(int **)(p_Var10 + 4);
        if (p_Var10 == (_Node *)*piVar11) {
          piVar11 = (int *)piVar11[2];
          if (piVar11[5] == 0) {
            piVar11[5] = 1;
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x14) = 0;
            iVar3 = *(int *)(p_Var10 + 4);
            (*pcVar8)();
            piVar11 = *(int **)(iVar3 + 8);
            *(int *)(iVar3 + 8) = *piVar11;
            if ((_Node *)*piVar11 != _Nil) {
              *(int *)((_Node *)*piVar11 + 4) = iVar3;
            }
            piVar11[1] = *(int *)(iVar3 + 4);
            if (iVar3 == *(int *)(*(int *)(this + 4) + 4)) {
              *(int **)(*(int *)(this + 4) + 4) = piVar11;
            }
            else {
              piVar4 = *(int **)(iVar3 + 4);
              if (iVar3 == *piVar4) {
                *piVar4 = (int)piVar11;
              }
              else {
                piVar4[2] = (int)piVar11;
              }
            }
            *piVar11 = iVar3;
            *(int **)(iVar3 + 4) = piVar11;
            (*___imp___1_Lockit_std__QAE_XZ)();
            piVar11 = *(int **)(*(int *)(p_Var10 + 4) + 8);
          }
          if ((*(int *)(*piVar11 + 0x14) != 1) || (*(int *)(piVar11[2] + 0x14) != 1)) {
            if (*(int *)(piVar11[2] + 0x14) == 1) {
              *(undefined4 *)(*piVar11 + 0x14) = 1;
              piVar11[5] = 0;
              (*pcVar8)();
              iVar3 = *piVar11;
              *piVar11 = *(int *)(iVar3 + 8);
              if (*(_Node **)(iVar3 + 8) != _Nil) {
                *(int **)(*(_Node **)(iVar3 + 8) + 4) = piVar11;
              }
              *(int *)(iVar3 + 4) = piVar11[1];
              if (piVar11 == *(int **)(*(int *)(this + 4) + 4)) {
                *(int *)(*(int *)(this + 4) + 4) = iVar3;
              }
              else {
                piVar4 = (int *)piVar11[1];
                if (piVar11 == (int *)piVar4[2]) {
                  piVar4[2] = iVar3;
                }
                else {
                  *piVar4 = iVar3;
                }
              }
              *(int **)(iVar3 + 8) = piVar11;
              piVar11[1] = iVar3;
              (*___imp___1_Lockit_std__QAE_XZ)();
              piVar11 = *(int **)(*(int *)(p_Var10 + 4) + 8);
            }
            piVar11[5] = *(int *)(*(int *)(p_Var10 + 4) + 0x14);
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x14) = 1;
            *(undefined4 *)(piVar11[2] + 0x14) = 1;
            iVar3 = *(int *)(p_Var10 + 4);
            (*pcVar8)();
            piVar11 = *(int **)(iVar3 + 8);
            *(int *)(iVar3 + 8) = *piVar11;
            if ((_Node *)*piVar11 != _Nil) {
              *(int *)((_Node *)*piVar11 + 4) = iVar3;
            }
            piVar11[1] = *(int *)(iVar3 + 4);
            if (iVar3 == *(int *)(*(int *)(this + 4) + 4)) {
              *(int **)(*(int *)(this + 4) + 4) = piVar11;
              *piVar11 = iVar3;
              *(int **)(iVar3 + 4) = piVar11;
            }
            else {
              piVar4 = *(int **)(iVar3 + 4);
              if (iVar3 == *piVar4) {
                *piVar4 = (int)piVar11;
                *piVar11 = iVar3;
                *(int **)(iVar3 + 4) = piVar11;
              }
              else {
                piVar4[2] = (int)piVar11;
                *piVar11 = iVar3;
                *(int **)(iVar3 + 4) = piVar11;
              }
            }
LAB_00003384:
            (*___imp___1_Lockit_std__QAE_XZ)();
            break;
          }
        }
        else {
          piVar11 = (int *)*piVar11;
          if (piVar11[5] == 0) {
            piVar11[5] = 1;
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x14) = 0;
            piVar11 = *(int **)(p_Var10 + 4);
            (*pcVar8)();
            iVar3 = *piVar11;
            *piVar11 = *(int *)(iVar3 + 8);
            if (*(_Node **)(iVar3 + 8) != _Nil) {
              *(int **)(*(_Node **)(iVar3 + 8) + 4) = piVar11;
            }
            *(int *)(iVar3 + 4) = piVar11[1];
            if (piVar11 == *(int **)(*(int *)(this + 4) + 4)) {
              *(int *)(*(int *)(this + 4) + 4) = iVar3;
            }
            else {
              piVar4 = (int *)piVar11[1];
              if (piVar11 == (int *)piVar4[2]) {
                piVar4[2] = iVar3;
              }
              else {
                *piVar4 = iVar3;
              }
            }
            *(int **)(iVar3 + 8) = piVar11;
            piVar11[1] = iVar3;
            (*___imp___1_Lockit_std__QAE_XZ)();
            piVar11 = (int *)**(undefined4 **)(p_Var10 + 4);
          }
          if ((*(int *)(piVar11[2] + 0x14) != 1) || (*(int *)(*piVar11 + 0x14) != 1)) {
            if (*(int *)(*piVar11 + 0x14) == 1) {
              *(undefined4 *)(piVar11[2] + 0x14) = 1;
              piVar11[5] = 0;
              (*pcVar8)();
              piVar4 = (int *)piVar11[2];
              piVar11[2] = *piVar4;
              if ((_Node *)*piVar4 != _Nil) {
                *(int **)((_Node *)*piVar4 + 4) = piVar11;
              }
              piVar4[1] = piVar11[1];
              if (piVar11 == *(int **)(*(int *)(this + 4) + 4)) {
                *(int **)(*(int *)(this + 4) + 4) = piVar4;
              }
              else {
                piVar5 = (int *)piVar11[1];
                if (piVar11 == (int *)*piVar5) {
                  *piVar5 = (int)piVar4;
                }
                else {
                  piVar5[2] = (int)piVar4;
                }
              }
              *piVar4 = (int)piVar11;
              piVar11[1] = (int)piVar4;
              (*___imp___1_Lockit_std__QAE_XZ)();
              piVar11 = (int *)**(undefined4 **)(p_Var10 + 4);
            }
            piVar11[5] = *(int *)(*(int *)(p_Var10 + 4) + 0x14);
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x14) = 1;
            *(undefined4 *)(*piVar11 + 0x14) = 1;
            piVar11 = *(int **)(p_Var10 + 4);
            (*pcVar8)();
            iVar3 = *piVar11;
            *piVar11 = *(int *)(iVar3 + 8);
            if (*(_Node **)(iVar3 + 8) != _Nil) {
              *(int **)(*(_Node **)(iVar3 + 8) + 4) = piVar11;
            }
            *(int *)(iVar3 + 4) = piVar11[1];
            if (piVar11 == *(int **)(*(int *)(this + 4) + 4)) {
              *(int *)(*(int *)(this + 4) + 4) = iVar3;
            }
            else {
              piVar4 = (int *)piVar11[1];
              if (piVar11 == (int *)piVar4[2]) {
                piVar4[2] = iVar3;
              }
              else {
                *piVar4 = iVar3;
              }
            }
            *(int **)(iVar3 + 8) = piVar11;
            piVar11[1] = iVar3;
            goto LAB_00003384;
          }
        }
        piVar11[5] = 0;
        p_Var10 = *(_Node **)(p_Var10 + 4);
      } while (p_Var10 != *(_Node **)(*(int *)(this + 4) + 4));
    }
    *(undefined4 *)(p_Var10 + 0x14) = 1;
  }
  operator_delete(local_1c);
  uStack_4 = 0xffffffff;
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + -1;
  *param_2 = param_3;
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return param_2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: class std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut
// *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator __thiscall std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::erase(class
// std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut *>,struct
// std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator,class std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::iterator)

undefined4 * __thiscall
std::_Tree<>::erase(_Tree<> *this,undefined4 *param_2,int *param_3,int *param_4)

{
  _Node *p_Var1;
  int *piVar2;
  code *pcVar3;
  int *piVar4;
  _Node *p_Var5;
  int unaff_FS_OFFSET;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  piVar4 = param_4;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  iStack_4 = 0xffffffff;
  puStack_8 = &_L8566;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  pcVar3 = ___imp___0_Lockit_std__QAE_XZ;
  piVar2 = param_3;
  if (((*(int *)(this + 0xc) == 0) || (param_3 != (int *)**(int **)(this + 4))) ||
     (param_4 != *(int **)(this + 4))) {
    while (piVar2 != piVar4) {
      param_3 = piVar2;
      const_iterator::_Inc((const_iterator *)&param_3);
      erase(this,local_10,piVar2);
      piVar2 = param_3;
    }
    *param_2 = piVar2;
  }
  else {
    (*___imp___0_Lockit_std__QAE_XZ)();
    iStack_4 = 0;
    p_Var5 = *(_Node **)(*(int *)(this + 4) + 4);
    (*pcVar3)();
    iStack_4._0_1_ = 1;
    if (p_Var5 != _Nil) {
      do {
        _Erase(this,*(_Node **)(p_Var5 + 8));
        p_Var1 = *(_Node **)p_Var5;
        operator_delete(p_Var5);
        p_Var5 = p_Var1;
      } while (p_Var1 != _Nil);
    }
    pcVar3 = ___imp___1_Lockit_std__QAE_XZ;
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    (*___imp___1_Lockit_std__QAE_XZ)();
    iStack_4 = 0xffffffff;
    *(_Node **)(*(int *)(this + 4) + 4) = _Nil;
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)(this + 4) = *(undefined4 *)(this + 4);
    *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
    *param_2 = **(undefined4 **)(this + 4);
    (*pcVar3)();
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return param_2;
}



// public: class std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut
// *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator __thiscall std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::find(unsigned long const &)

void __thiscall std::_Tree<>::find(_Tree<> *this,ulong *param_1)

{
  _Node *p_Var1;
  ulong *in_stack_00000008;
  
  p_Var1 = _Lbound(this,in_stack_00000008);
  if ((p_Var1 != *(_Node **)(this + 4)) && (*(uint *)(p_Var1 + 0xc) <= *in_stack_00000008)) {
    *param_1 = (ulong)p_Var1;
    return;
  }
  *param_1 = (ulong)*(_Node **)(this + 4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: struct std::pair<class std::_Tree<unsigned long,struct std::pair<unsigned long const
// ,class PacketOut *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned
// long>,class std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator,bool> __thiscall std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::insert(struct
// std::pair<unsigned long const ,class PacketOut *> const &)

void __thiscall std::_Tree<>::insert(_Tree<> *this,pair<> *param_1)

{
  undefined4 *puVar1;
  _Node *p_Var2;
  pair<> *ppVar3;
  bool bVar4;
  uint *in_stack_00000008;
  pair<> *appStack_c [2];
  uint uStack_4;
  
  ppVar3 = *(pair<> **)(this + 4);
  bVar4 = true;
  p_Var2 = *(_Node **)(ppVar3 + 4);
  (*___imp___0_Lockit_std__QAE_XZ)();
  if (p_Var2 != _Nil) {
    do {
      ppVar3 = (pair<> *)p_Var2;
      bVar4 = *in_stack_00000008 < *(uint *)((_Node *)ppVar3 + 0xc);
      if (bVar4) {
        p_Var2 = *(_Node **)ppVar3;
      }
      else {
        p_Var2 = *(_Node **)((_Node *)ppVar3 + 8);
      }
    } while (p_Var2 != _Nil);
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  if (this[8] != (_Tree<>)0x0) {
    puVar1 = (undefined4 *)_Insert(this,(_Node *)&stack0x00000008,p_Var2,ppVar3);
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    *(undefined4 *)param_1 = *puVar1;
    *(uint *)(param_1 + 4) = uStack_4;
    return;
  }
  appStack_c[0] = ppVar3;
  if (bVar4) {
    if (ppVar3 == (pair<> *)**(int **)(this + 4)) {
      puVar1 = (undefined4 *)_Insert(this,(_Node *)&stack0x00000008,p_Var2,ppVar3);
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      *(undefined4 *)param_1 = *puVar1;
      *(uint *)(param_1 + 4) = uStack_4;
      return;
    }
    const_iterator::_Dec((const_iterator *)appStack_c);
  }
  if (*(uint *)(appStack_c[0] + 0xc) < *in_stack_00000008) {
    puVar1 = (undefined4 *)_Insert(this,(_Node *)&stack0x00000008,p_Var2,ppVar3);
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    *(undefined4 *)param_1 = *puVar1;
    *(uint *)(param_1 + 4) = uStack_4;
    return;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  *(pair<> **)param_1 = appStack_c[0];
  *(uint *)(param_1 + 4) = uStack_4;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: void __thiscall std::_Tree<unsigned long,struct std::pair<unsigned long const ,class
// PacketOut *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned
// long>,class std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Erase(struct std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Node *)

void __thiscall std::_Tree<>::_Erase(_Tree<> *this,_Node *param_1)

{
  _Node *p_Var1;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L8833;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  (*___imp___0_Lockit_std__QAE_XZ)();
  uStack_4 = 0;
  if (param_1 != _Nil) {
    do {
      _Erase(this,*(_Node **)(param_1 + 8));
      p_Var1 = *(_Node **)param_1;
      operator_delete(param_1);
      param_1 = p_Var1;
    } while (p_Var1 != _Nil);
  }
  uStack_4 = 0xffffffff;
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: static struct std::_Tree<unsigned long,struct std::pair<unsigned long const ,class
// PacketOut *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned
// long>,class std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Node * __cdecl std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Min(struct
// std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut *>,struct
// std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Node *)

_Node * __cdecl std::_Tree<>::_Min(_Node *param_1)

{
  _Node *p_Var1;
  _Node *p_Var2;
  
  (*___imp___0_Lockit_std__QAE_XZ)();
  p_Var2 = *(_Node **)param_1;
  while (p_Var1 = p_Var2, p_Var1 != _Nil) {
    param_1 = p_Var1;
    p_Var2 = *(_Node **)p_Var1;
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  return param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall std::_Tree<unsigned long,struct std::pair<unsigned long const ,class
// PacketOut *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned
// long>,class std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::const_iterator::_Inc(void)

void __thiscall std::_Tree<>::const_iterator::_Inc(const_iterator *this)

{
  _Node *p_Var1;
  _Node *p_Var2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L8893;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  pcVar4 = ___imp___0_Lockit_std__QAE_XZ;
  (*___imp___0_Lockit_std__QAE_XZ)();
  pcVar3 = ___imp___1_Lockit_std__QAE_XZ;
  uStack_4 = 0;
  p_Var1 = *(_Node **)(*(int *)this + 8);
  if (p_Var1 == _Nil) {
    iVar5 = *(int *)(*(int *)this + 4);
    if (*(int *)this == *(int *)(iVar5 + 8)) {
      do {
        *(int *)this = iVar5;
        iVar5 = *(int *)(iVar5 + 4);
      } while (*(int *)this == *(int *)(iVar5 + 8));
    }
    if (*(int *)(*(int *)this + 8) != iVar5) {
      *(int *)this = iVar5;
    }
  }
  else {
    (*pcVar4)();
    for (p_Var2 = *(_Node **)p_Var1; p_Var2 != _Nil; p_Var2 = *(_Node **)p_Var2) {
      p_Var1 = p_Var2;
    }
    (*pcVar3)();
    *(_Node **)this = p_Var1;
  }
  uStack_4 = 0xffffffff;
  (*pcVar3)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// public: __thiscall std::pair<class std::_Tree<unsigned long,struct std::pair<unsigned long const
// ,class PacketOut *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned
// long>,class std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator,bool>::pair<class std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::iterator,bool>(class
// std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut *>,struct
// std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator const &,bool const &)

void __thiscall std::pair<>::pair<>(pair<> *this,iterator *param_1,bool *param_2)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  this[4] = (pair<>)*param_2;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: class std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut
// *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::iterator __thiscall std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Insert(struct
// std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut *>,struct
// std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Node *,struct std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Node *,struct
// std::pair<unsigned long const ,class PacketOut *> const &)

_Node * __thiscall
std::_Tree<>::_Insert(_Tree<> *this,_Node *param_1,_Node *param_2,pair<> *param_3)

{
  pair<> *ppVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int unaff_FS_OFFSET;
  pair<> *in_stack_00000010;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L9675;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  (*___imp___0_Lockit_std__QAE_XZ)();
  uStack_4 = 0;
  piVar5 = operator_new(0x18);
  piVar5[1] = (int)param_3;
  piVar5[5] = 0;
  *piVar5 = (int)_Nil;
  piVar5[2] = (int)_Nil;
  _Construct((pair<> *)(piVar5 + 3),in_stack_00000010);
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
  if (((param_3 == *(pair<> **)(this + 4)) || (param_2 != _Nil)) ||
     (*(uint *)in_stack_00000010 < *(uint *)(param_3 + 0xc))) {
    *(int **)param_3 = piVar5;
    ppVar1 = *(pair<> **)(this + 4);
    if (param_3 == ppVar1) {
      *(int **)(ppVar1 + 4) = piVar5;
      *(int **)(*(int *)(this + 4) + 8) = piVar5;
    }
    else if (param_3 == *(pair<> **)ppVar1) {
      *(int **)ppVar1 = piVar5;
    }
  }
  else {
    *(int **)(param_3 + 8) = piVar5;
    if (param_3 == *(pair<> **)(*(int *)(this + 4) + 8)) {
      *(int **)(*(int *)(this + 4) + 8) = piVar5;
    }
  }
  piVar6 = piVar5;
  if (piVar5 != *(int **)(*(int *)(this + 4) + 4)) {
    do {
      piVar2 = (int *)piVar6[1];
      if (piVar2[5] != 0) break;
      piVar3 = (int *)piVar2[1];
      if (piVar2 == (int *)*piVar3) {
        iVar4 = piVar3[2];
        if (*(int *)(iVar4 + 0x14) == 0) {
          piVar2[5] = 1;
          *(undefined4 *)(iVar4 + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
          piVar6 = *(int **)(piVar6[1] + 4);
        }
        else {
          if (piVar6 == (int *)piVar2[2]) {
            (*___imp___0_Lockit_std__QAE_XZ)();
            piVar6 = (int *)piVar2[2];
            piVar2[2] = *piVar6;
            if ((_Node *)*piVar6 != _Nil) {
              *(int **)((_Node *)*piVar6 + 4) = piVar2;
            }
            piVar6[1] = piVar2[1];
            if (piVar2 == *(int **)(*(int *)(this + 4) + 4)) {
              *(int **)(*(int *)(this + 4) + 4) = piVar6;
            }
            else {
              piVar3 = (int *)piVar2[1];
              if (piVar2 == (int *)*piVar3) {
                *piVar3 = (int)piVar6;
              }
              else {
                piVar3[2] = (int)piVar6;
              }
            }
            *piVar6 = (int)piVar2;
            piVar2[1] = (int)piVar6;
            (*___imp___1_Lockit_std__QAE_XZ)();
            piVar6 = piVar2;
          }
          *(undefined4 *)(piVar6[1] + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
          piVar2 = *(int **)(piVar6[1] + 4);
          (*___imp___0_Lockit_std__QAE_XZ)();
          iVar4 = *piVar2;
          *piVar2 = *(int *)(iVar4 + 8);
          if (*(_Node **)(iVar4 + 8) != _Nil) {
            *(int **)(*(_Node **)(iVar4 + 8) + 4) = piVar2;
          }
          *(int *)(iVar4 + 4) = piVar2[1];
          if (piVar2 == *(int **)(*(int *)(this + 4) + 4)) {
            *(int *)(*(int *)(this + 4) + 4) = iVar4;
            *(int **)(iVar4 + 8) = piVar2;
            piVar2[1] = iVar4;
          }
          else {
            piVar3 = (int *)piVar2[1];
            if (piVar2 == (int *)piVar3[2]) {
              piVar3[2] = iVar4;
              *(int **)(iVar4 + 8) = piVar2;
              piVar2[1] = iVar4;
            }
            else {
              *piVar3 = iVar4;
              *(int **)(iVar4 + 8) = piVar2;
              piVar2[1] = iVar4;
            }
          }
LAB_00003ad8:
          (*___imp___1_Lockit_std__QAE_XZ)();
        }
      }
      else {
        iVar4 = *piVar3;
        if (*(int *)(iVar4 + 0x14) != 0) {
          if (piVar6 == (int *)*piVar2) {
            (*___imp___0_Lockit_std__QAE_XZ)();
            iVar4 = *piVar2;
            *piVar2 = *(int *)(iVar4 + 8);
            if (*(_Node **)(iVar4 + 8) != _Nil) {
              *(int **)(*(_Node **)(iVar4 + 8) + 4) = piVar2;
            }
            *(int *)(iVar4 + 4) = piVar2[1];
            if (piVar2 == *(int **)(*(int *)(this + 4) + 4)) {
              *(int *)(*(int *)(this + 4) + 4) = iVar4;
            }
            else {
              piVar6 = (int *)piVar2[1];
              if (piVar2 == (int *)piVar6[2]) {
                piVar6[2] = iVar4;
              }
              else {
                *piVar6 = iVar4;
              }
            }
            *(int **)(iVar4 + 8) = piVar2;
            piVar2[1] = iVar4;
            (*___imp___1_Lockit_std__QAE_XZ)();
            piVar6 = piVar2;
          }
          *(undefined4 *)(piVar6[1] + 0x14) = 1;
          *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
          iVar4 = *(int *)(piVar6[1] + 4);
          (*___imp___0_Lockit_std__QAE_XZ)();
          piVar2 = *(int **)(iVar4 + 8);
          *(int *)(iVar4 + 8) = *piVar2;
          if ((_Node *)*piVar2 != _Nil) {
            *(int *)((_Node *)*piVar2 + 4) = iVar4;
          }
          piVar2[1] = *(int *)(iVar4 + 4);
          if (iVar4 == *(int *)(*(int *)(this + 4) + 4)) {
            *(int **)(*(int *)(this + 4) + 4) = piVar2;
          }
          else {
            piVar3 = *(int **)(iVar4 + 4);
            if (iVar4 == *piVar3) {
              *piVar3 = (int)piVar2;
            }
            else {
              piVar3[2] = (int)piVar2;
            }
          }
          *piVar2 = iVar4;
          *(int **)(iVar4 + 4) = piVar2;
          goto LAB_00003ad8;
        }
        piVar2[5] = 1;
        *(undefined4 *)(iVar4 + 0x14) = 1;
        *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;
        piVar6 = *(int **)(piVar6[1] + 4);
      }
    } while (piVar6 != *(int **)(*(int *)(this + 4) + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(*(int *)(this + 4) + 4) + 0x14) = 1;
  *(int **)param_1 = piVar5;
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: struct std::_Tree<unsigned long,struct std::pair<unsigned long const ,class PacketOut
// *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::_Node * __thiscall std::_Tree<unsigned long,struct
// std::pair<unsigned long const ,class PacketOut *>,struct std::map<unsigned long,class PacketOut
// *,struct std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Kfn,struct
// std::less<unsigned long>,class std::allocator<class PacketOut *> >::_Lbound(unsigned long const
// &)const 

_Node * __thiscall std::_Tree<>::_Lbound(_Tree<> *this,ulong *param_1)

{
  _Node *p_Var1;
  _Node *p_Var2;
  _Node *p_Var3;
  
  (*___imp___0_Lockit_std__QAE_XZ)();
  p_Var3 = *(_Node **)(this + 4);
  if (*(_Node **)(p_Var3 + 4) != _Nil) {
    p_Var1 = *(_Node **)(p_Var3 + 4);
    do {
      if (*(uint *)(p_Var1 + 0xc) < *param_1) {
        p_Var2 = *(_Node **)(p_Var1 + 8);
      }
      else {
        p_Var2 = *(_Node **)p_Var1;
        p_Var3 = p_Var1;
      }
      p_Var1 = p_Var2;
    } while (p_Var2 != _Nil);
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  return p_Var3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall std::_Tree<unsigned long,struct std::pair<unsigned long const ,class
// PacketOut *>,struct std::map<unsigned long,class PacketOut *,struct std::less<unsigned
// long>,class std::allocator<class PacketOut *> >::_Kfn,struct std::less<unsigned long>,class
// std::allocator<class PacketOut *> >::const_iterator::_Dec(void)

void __thiscall std::_Tree<>::const_iterator::_Dec(const_iterator *this)

{
  _Node *p_Var1;
  _Node *p_Var2;
  code *pcVar3;
  code *pcVar4;
  int *piVar5;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L9772;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  pcVar4 = ___imp___0_Lockit_std__QAE_XZ;
  (*___imp___0_Lockit_std__QAE_XZ)();
  pcVar3 = ___imp___1_Lockit_std__QAE_XZ;
  piVar5 = *(int **)this;
  uStack_4 = 0;
  if ((piVar5[5] == 0) && (*(int **)(piVar5[1] + 4) == piVar5)) {
    *(int *)this = piVar5[2];
  }
  else {
    p_Var1 = (_Node *)*piVar5;
    if (p_Var1 == _Nil) {
      piVar5 = (int *)piVar5[1];
      if (*(int *)this == *piVar5) {
        do {
          *(int **)this = piVar5;
          piVar5 = (int *)piVar5[1];
        } while (*(int *)this == *piVar5);
      }
      *(int **)this = piVar5;
    }
    else {
      (*pcVar4)();
      for (p_Var2 = *(_Node **)(p_Var1 + 8); p_Var2 != _Nil; p_Var2 = *(_Node **)(p_Var2 + 8)) {
        p_Var1 = p_Var2;
      }
      (*pcVar3)();
      *(_Node **)this = p_Var1;
    }
  }
  uStack_4 = 0xffffffff;
  (*pcVar3)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// void __cdecl std::_Construct(struct std::pair<unsigned long const ,class PacketOut *> *,struct
// std::pair<unsigned long const ,class PacketOut *> const &)

void __cdecl std::_Construct(pair<> *param_1,pair<> *param_2)

{
  if (param_1 != (pair<> *)0x0) {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  }
  return;
}


