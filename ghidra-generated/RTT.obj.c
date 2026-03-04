typedef unsigned char   undefined;

typedef unsigned int    dword;
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

struct TraceOutput { // PlaceHolder Structure
};

typedef struct RTT RTT, *PRTT;

struct RTT { // PlaceHolder Structure
};




// public: __thiscall RTT::RTT(void)

void __thiscall RTT::RTT(RTT *this)

{
  *(undefined4 *)this = 2000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0xfa;
  return;
}



// public: __thiscall RTT::~RTT(void)

void __thiscall RTT::~RTT(RTT *this)

{
  return;
}



// public: void __thiscall RTT::Adjust(unsigned long)

void __thiscall RTT::Adjust(RTT *this,ulong param_1)

{
  int iVar1;
  
  if (*(int *)(this + 8) == -1) {
    *(ulong *)(this + 8) = param_1;
    *(ulong *)this = param_1 * 8;
    return;
  }
  iVar1 = param_1 - (*(uint *)this >> 3);
  *(uint *)this = *(uint *)this + iVar1;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  *(ulong *)(this + 8) = param_1;
  *(uint *)(this + 4) = (*(uint *)(this + 4) - (*(uint *)(this + 4) >> 2)) + iVar1;
  return;
}



// public: unsigned long __thiscall RTT::GetRTO(void)

ulong __thiscall RTT::GetRTO(RTT *this)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = GetRTTSmoothedDev(this);
  uVar2 = GetRTTSmoothedAvg(this);
  return uVar2 + uVar1 * 4;
}



// public: unsigned long __thiscall RTT::GetRTTSmoothedAvg(void)

ulong __thiscall RTT::GetRTTSmoothedAvg(RTT *this)

{
  return *(uint *)this >> 3;
}



// public: unsigned long __thiscall RTT::GetRTTSmoothedDev(void)

ulong __thiscall RTT::GetRTTSmoothedDev(RTT *this)

{
  return *(uint *)(this + 4) >> 2;
}



// public: unsigned long __thiscall RTT::GetLastRTT(void)

ulong __thiscall RTT::GetLastRTT(RTT *this)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(this + 8);
  if (uVar1 == 0xffffffff) {
    uVar1 = 2000;
  }
  return uVar1;
}



// public: void __thiscall RTT::Trace(unsigned long)

void __thiscall RTT::Trace(RTT *this,ulong param_1)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,(char *)param_1);
  return;
}


