typedef unsigned char   undefined;

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

void __thiscall RTT::Adjust(RTT *this,unsigned long param_1)

{
  int iVar1;
  
  if (*(int *)(this + 8) == -1) {
    *(unsigned long *)(this + 8) = param_1;
    *(unsigned long *)this = param_1 * 8;
    return;
  }
  iVar1 = param_1 - (*(unsigned int *)this >> 3);
  *(unsigned int *)this = *(unsigned int *)this + iVar1;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  *(unsigned long *)(this + 8) = param_1;
  *(unsigned int *)(this + 4) = (*(unsigned int *)(this + 4) - (*(unsigned int *)(this + 4) >> 2)) + iVar1;
  return;
}



// public: unsigned long __thiscall RTT::GetRTO(void)

unsigned long __thiscall RTT::GetRTO(RTT *this)

{
  unsigned long uVar1;
  unsigned long uVar2;
  
  uVar1 = GetRTTSmoothedDev(this);
  uVar2 = GetRTTSmoothedAvg(this);
  return uVar2 + uVar1 * 4;
}



// public: unsigned long __thiscall RTT::GetRTTSmoothedAvg(void)

unsigned long __thiscall RTT::GetRTTSmoothedAvg(RTT *this)

{
  return *(unsigned int *)this >> 3;
}



// public: unsigned long __thiscall RTT::GetRTTSmoothedDev(void)

unsigned long __thiscall RTT::GetRTTSmoothedDev(RTT *this)

{
  return *(unsigned int *)(this + 4) >> 2;
}



// public: unsigned long __thiscall RTT::GetLastRTT(void)

unsigned long __thiscall RTT::GetLastRTT(RTT *this)

{
  unsigned long uVar1;
  
  uVar1 = *(unsigned long *)(this + 8);
  if (uVar1 == 0xffffffff) {
    uVar1 = 2000;
  }
  return uVar1;
}



// public: void __thiscall RTT::Trace(unsigned long)

void __thiscall RTT::Trace(RTT *this,unsigned long param_1)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(unsigned long)pTVar1,(char *)param_1);
  return;
}


