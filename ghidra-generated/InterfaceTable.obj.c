#include <Platform/Trace.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned long    ulong;
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

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct InterfaceTable InterfaceTable, *PInterfaceTable;

struct InterfaceTable { // PlaceHolder Structure
};

typedef struct InterfaceInfo InterfaceInfo, *PInterfaceInfo;

struct InterfaceInfo { // PlaceHolder Structure
};



undefined ~InterfaceInfo;
undefined LAB_0000280b;
undefined __imp__WSASocketA@24;
undefined InterfaceInfo;
undefined __except_list;
TerminatedCString s_Unknown;
undefined __imp__closesocket@4;
undefined __imp__WSAIoctl@36;
undefined __imp__WSAGetLastError@0;
TerminatedCString s_ulIndex_<_m_ulNbInterface;
TerminatedCString s_InterfaceTable.cpp;

// public: __thiscall InterfaceTable::InterfaceTable(void)

void __thiscall InterfaceTable::InterfaceTable(InterfaceTable *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}



// public: __thiscall InterfaceTable::~InterfaceTable(void)

void __thiscall InterfaceTable::~InterfaceTable(InterfaceTable *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 4);
  *(undefined4 *)this = 0;
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar1,0x14,*(int *)((int)pvVar1 + -4),InterfaceInfo::~InterfaceInfo);
    operator_delete((void *)((int)pvVar1 + -4));
  }
  return;
}



// public: void * __thiscall InterfaceInfo::`vector deleting destructor'(unsigned int)

void * __thiscall InterfaceInfo::_vector_deleting_destructor_(InterfaceInfo *this,uint param_1)

{
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0x14,*(int *)(this + -4),InterfaceInfo::~InterfaceInfo);
    if ((param_1 & 1) != 0) {
      operator_delete(this + -4);
    }
    return this + -4;
  }
  InterfaceInfo::~InterfaceInfo(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: bool __thiscall InterfaceTable::Query(void)

bool __thiscall InterfaceTable::Query(InterfaceTable *this)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  TraceOutput *pTVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  TraceOutput *this_00;
  uint *puVar10;
  int unaff_FS_OFFSET;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  char *pcVar14;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L43372;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  pvStack_2c = (void *)0x1;
  uStack_30 = 0;
  uStack_34 = 0;
  *(undefined4 *)this = 0;
  iVar2 = (*___imp__WSASocketA_24)(2,2,0x11);
  if (iVar2 == -1) {
    (*___imp__WSAGetLastError_0)();
  }
  else {
    uStack_34 = 0;
    pvVar3 = operator_new(0x2f8);
    puVar13 = &uStack_34;
    puVar12 = (uint *)0x2f8;
    uVar11 = 0;
    pvStack_2c = pvVar3;
    iVar4 = (*___imp__WSAIoctl_36)(iVar2,0x4004747f,0,0,pvVar3,0x2f8,puVar13,0,0);
    if (iVar4 != -1) {
      uVar11 = uVar11 / 0x4c;
      puVar6 = operator_new(uVar11 * 0x14 + 4);
      if (puVar6 == (uint *)0x0) {
        puVar10 = (uint *)0x0;
      }
      else {
        puVar10 = puVar6 + 1;
        *puVar6 = uVar11;
        _eh_vector_constructor_iterator_
                  (puVar10,0x14,uVar11,InterfaceInfo::InterfaceInfo,InterfaceInfo::~InterfaceInfo);
      }
      *(uint **)(this + 4) = puVar10;
      puVar6 = puVar12;
      for (; uVar11 != 0; uVar11 = uVar11 - 1) {
        if (puVar12[2] != 0) {
          InterfaceInfo::SetName
                    ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14),s_Unknown);
          InterfaceInfo::SetAddress
                    ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14),puVar12[2]);
          InterfaceInfo::SetMask
                    ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14),puVar12[0xe]);
          uVar7 = InterfaceInfo::GetMask
                            ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14));
          uVar8 = InterfaceInfo::GetAddress
                            ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14));
          uVar9 = InterfaceInfo::GetAddress
                            ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14));
          InterfaceInfo::SetBroadcastAddress
                    ((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14),
                     ~uVar7 & ~uVar8 | uVar9);
          uVar1 = *puVar12;
          uVar7 = 0;
          if ((uVar1 & 2) != 0) {
            uVar7 = 2;
          }
          if ((uVar1 & 4) != 0) {
            uVar7 = uVar7 | 4;
          }
          if ((uVar1 & 8) != 0) {
            uVar7 = uVar7 | 1;
          }
          InterfaceInfo::SetFlags((InterfaceInfo *)(*(int *)(this + 4) + *(int *)this * 0x14),uVar7)
          ;
          *(int *)this = *(int *)this + 1;
        }
        puVar12 = puVar12 + 0x13;
      }
      operator_delete(puVar6);
      (*___imp__closesocket_4)(puVar13);
      *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = puVar13;
      return true;
    }
    operator_delete(pvVar3);
    (*___imp__closesocket_4)(iVar2);
    (*___imp__WSAGetLastError_0)();
  }
  pcVar14 = (char *)0x10000;
  pTVar5 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar5,pcVar14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_1c;
  return false;
}



// public: unsigned long __thiscall InterfaceTable::GetNbInterface(void)

ulong __thiscall InterfaceTable::GetNbInterface(InterfaceTable *this)

{
  return *(ulong *)this;
}



// public: unsigned long __thiscall InterfaceTable::GetNbLoopbackInterface(void)

ulong __thiscall InterfaceTable::GetNbLoopbackInterface(InterfaceTable *this)

{
  InterfaceInfo *this_00;
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  if (*(int *)this != 0) {
    do {
      this_00 = operator[](this,uVar3);
      uVar1 = InterfaceInfo::GetFlags(this_00);
      if ((uVar1 & 4) != 0) {
        uVar2 = uVar2 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)this);
  }
  return uVar2;
}



// public: class InterfaceInfo & __thiscall InterfaceTable::operator[](unsigned long)

InterfaceInfo * __thiscall InterfaceTable::operator[](InterfaceTable *this,ulong param_1)

{
  Platform::SystemCheck
            (param_1 < *(uint *)this,s_ulIndex_<_m_ulNbInterface,s_InterfaceTable_cpp,0xbb);
  return (InterfaceInfo *)(*(int *)(this + 4) + param_1 * 0x14);
}



// public: void __thiscall InterfaceTable::Trace(unsigned long)

void __thiscall InterfaceTable::Trace(InterfaceTable *this,ulong param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = GetNbInterface(this);
  if (uVar1 != 0) {
    iVar2 = 0;
    do {
      InterfaceInfo::Trace((InterfaceInfo *)(*(int *)(this + 4) + iVar2),param_1);
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x14;
      uVar1 = GetNbInterface(this);
    } while (uVar3 < uVar1);
  }
  return;
}


