#include <Platform/CriticalSection.h>
#include <Platform/Event.h>
#include <Platform/ScopedCS.h>
#include <Platform/Trace.h>
#include <Platform/UserContext.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Core/RefCountedObject.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/EndPointEventHandler.h>
#include <Plugins/Transport/Interface/EndPointGroup.h>
#include <Plugins/Transport/Interface/InputEmulationDevice.h>
#include <Plugins/Transport/Interface/OutputEmulationDevice.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/Transport.h>
#include <Plugins/Transport/Interface/TransportEventHandler.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef long long    longlong;
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

typedef enum TRANSPORT_CAPS {
    IP_BASED	=1,
    BROADCAST=2,
    DEVICE_EMULATION	=3,
    PERF_COUNTERS=4,
    GROUPING=5,
    WELLKNOWN_LISTEN_SUPPORTED=6,
    ARBITRARY_LISTEN_SUPPORTED=7
} TRANSPORT_CAPS;

typedef struct InputEmulationDevice InputEmulationDevice, *PInputEmulationDevice;

typedef struct PRUDPTransportSettings PRUDPTransportSettings, *PPRUDPTransportSettings;

struct PRUDPTransportSettings { // PlaceHolder Structure
    undefined *field0_0x0;
    undefined4 field1_0x4;
    undefined field2_0x8;
    undefined field3_0x9;
    undefined field4_0xa;
    undefined field5_0xb;
    undefined4 field6_0xc;
    undefined4 field7_0x10;
    undefined4 field8_0x14;
    undefined4 field9_0x18;
    undefined4 field10_0x1c;
};

typedef struct TransportEventHandler TransportEventHandler, *PTransportEventHandler;

typedef struct PRUDPTransport PRUDPTransport, *PPRUDPTransport;

struct PRUDPTransport { // PlaceHolder Structure
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    undefined field96_0x60;
    undefined field97_0x61;
    undefined field98_0x62;
    undefined field99_0x63;
    undefined field100_0x64;
    undefined field101_0x65;
    undefined field102_0x66;
    undefined field103_0x67;
    undefined field104_0x68;
    undefined field105_0x69;
    undefined field106_0x6a;
    undefined field107_0x6b;
    undefined field108_0x6c;
    undefined field109_0x6d;
    undefined field110_0x6e;
    undefined field111_0x6f;
    undefined field112_0x70;
    undefined field113_0x71;
    undefined field114_0x72;
    undefined field115_0x73;
    undefined field116_0x74;
    undefined field117_0x75;
    undefined field118_0x76;
    undefined field119_0x77;
    undefined field120_0x78;
    undefined field121_0x79;
    undefined field122_0x7a;
    undefined field123_0x7b;
    undefined field124_0x7c;
    undefined field125_0x7d;
    undefined field126_0x7e;
    undefined field127_0x7f;
    undefined field128_0x80;
    undefined field129_0x81;
    undefined field130_0x82;
    undefined field131_0x83;
    undefined field132_0x84;
    undefined field133_0x85;
    undefined field134_0x86;
    undefined field135_0x87;
    undefined field136_0x88;
    undefined field137_0x89;
    undefined field138_0x8a;
    undefined field139_0x8b;
    undefined field140_0x8c;
    undefined field141_0x8d;
    undefined field142_0x8e;
    undefined field143_0x8f;
    undefined field144_0x90;
    undefined field145_0x91;
    undefined field146_0x92;
    undefined field147_0x93;
    struct PRUDPTransportSettings m_oTransportSettings;
};

typedef struct CriticalSection CriticalSection, *PCriticalSection;

typedef struct OutputEmulationDevice OutputEmulationDevice, *POutputEmulationDevice;

typedef struct EndPointEventHandler EndPointEventHandler, *PEndPointEventHandler;

typedef struct UDPSocket UDPSocket, *PUDPSocket;

struct UDPSocket { // PlaceHolder Structure
};

typedef struct EndPointGroup EndPointGroup, *PEndPointGroup;

typedef struct Buffer Buffer, *PBuffer;

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct PacketOut PacketOut, *PPacketOut;

struct PacketOut { // PlaceHolder Structure
};

typedef struct Event Event, *PEvent;

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct TimeoutManager TimeoutManager, *PTimeoutManager;

struct TimeoutManager { // PlaceHolder Structure
};

typedef struct InterfaceInfo InterfaceInfo, *PInterfaceInfo;

struct InterfaceInfo { // PlaceHolder Structure
};

typedef struct Transport Transport, *PTransport;

typedef struct UserContext UserContext, *PUserContext;

typedef struct StationURL StationURL, *PStationURL;

typedef struct EndPoint EndPoint, *PEndPoint;

typedef struct RTT RTT, *PRTT;

struct RTT { // PlaceHolder Structure
};

typedef struct PRUDPInetAddress PRUDPInetAddress, *PPRUDPInetAddress;

struct PRUDPInetAddress { // PlaceHolder Structure
};

typedef struct ICMPSocket ICMPSocket, *PICMPSocket;

struct ICMPSocket { // PlaceHolder Structure
};

typedef struct PacketIn PacketIn, *PPacketIn;

struct PacketIn { // PlaceHolder Structure
};

typedef struct Socket Socket, *PSocket;

struct Socket { // PlaceHolder Structure
};

typedef struct PRUDPEndPoint PRUDPEndPoint, *PPRUDPEndPoint;

struct PRUDPEndPoint { // PlaceHolder Structure
};

typedef struct InterfaceTable InterfaceTable, *PInterfaceTable;

struct InterfaceTable { // PlaceHolder Structure
};

typedef struct Plugin Plugin, *PPlugin;

struct Plugin { // PlaceHolder Structure
    void *m_hLibrary;
};

typedef struct PRUDPEndPointMap PRUDPEndPointMap, *PPRUDPEndPointMap;

struct PRUDPEndPointMap { // PlaceHolder Structure
};

typedef struct CallbackDispatcher CallbackDispatcher, *PCallbackDispatcher;

struct CallbackDispatcher { // PlaceHolder Structure
};

typedef struct ScopedCS ScopedCS, *PScopedCS;

typedef struct pair<__int64_const_,class_PRUDPEndPoint*> pair<__int64_const_,class_PRUDPEndPoint*>, *Ppair<__int64_const_,class_PRUDPEndPoint*>;

struct pair<__int64_const_,class_PRUDPEndPoint*> { // PlaceHolder Structure
};

typedef struct _Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_> _Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>, *P_Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>;

struct _Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_> { // PlaceHolder Structure
};

typedef struct pair<class_std::_Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::iterator,bool> pair<class_std::_Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::iterator,bool>, *Ppair<class_std::_Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::iterator,bool>;

struct pair<class_std::_Tree<__int64,struct_std::pair<__int64_const_,class_PRUDPEndPoint*>,struct_std::map<__int64,class_PRUDPEndPoint*,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::_Kfn,struct_std::less<__int64>,class_std::allocator<class_PRUDPEndPoint*>_>::iterator,bool> { // PlaceHolder Structure
};

typedef struct list<class_PRUDPEndPoint*,class_std::allocator<class_PRUDPEndPoint*>_> list<class_PRUDPEndPoint*,class_std::allocator<class_PRUDPEndPoint*>_>, *Plist<class_PRUDPEndPoint*,class_std::allocator<class_PRUDPEndPoint*>_>;

struct list<class_PRUDPEndPoint*,class_std::allocator<class_PRUDPEndPoint*>_> { // PlaceHolder Structure
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



undefined LAB_0000667a;
undefined __imp_??0_Lockit@std@@QAE@XZ;
undefined PRUDPInetAddress;
pointer `vftable';
undefined ~PRUDPInetAddress;
undefined __except_list;
undefined __imp_??1_Lockit@std@@QAE@XZ;
uint _Nilrefs;
_Node *_Nil;
TerminatedCString s_<unspecified>;
undefined LAB_00006709;
undefined __imp__WSACleanup@0;
TerminatedCString s_prudp;
undefined __imp___stricmp;
undefined __imp__WSAStartup@8;
undefined LAB_00006736;
undefined LAB_00006748;
undefined LAB_00006776;
undefined __imp__sprintf;
TerminatedCString s_%s%s;
TerminatedCString s_:/;
TerminatedCString s_PRUDPTransport::SendBroadcast(%d;
undefined LAB_00006793;
undefined LAB_000067d2;
undefined LAB_000067f3;
TerminatedCString s_prudp:/;
undefined LAB_00006813;
undefined LAB_00006828;
undefined LAB_0000684b;
undefined HandleTimeSliceWrap;
undefined LAB_00006873;
undefined HandleRecvCompletedWrap;
TerminatedCString s_m_apSocket[ulSocket]==NULL;
TerminatedCString s_PRUDPTransport.cpp;
undefined HandleSendCompletedWrap;
undefined LAB_0000689b;
undefined HandleICMPCompletedWrap;
undefined LAB_000068b8;
undefined LAB_000068d8;
undefined LAB_000068fb;
undefined LAB_00006933;
undefined LAB_00006948;
TerminatedCString s_<-;
undefined LAB_00006968;
TerminatedCString s_pPacket->Valid()==true;
TerminatedCString s_pPacket!=NULL;
undefined LAB_00006988;
undefined LAB_000069a9;
undefined LAB_000069d2;
undefined LAB_000069e9;
undefined LAB_00006a09;
undefined LAB_00006a29;
undefined LAB_00006a49;

// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall PRUDPTransport::PRUDPTransport(class Plugin *)

PRUDPTransport * __thiscall PRUDPTransport::PRUDPTransport(PRUDPTransport *this,Plugin *pPlugin)

{
  _Node *p_Var1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L55140;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  Transport::Transport((Transport *)this,pPlugin);
  local_4 = 0;
  _eh_vector_constructor_iterator_
            (&this->field_0x1c,4,2,PRUDPInetAddress::PRUDPInetAddress,
             PRUDPInetAddress::~PRUDPInetAddress);
  local_4._0_1_ = 1;
  TimeoutManager::TimeoutManager((TimeoutManager *)&this->field_0x50);
  local_4._0_1_ = 2;
  this->field_0x60 = pPlugin._0_1_;
  this->field_0x61 = pPlugin._0_1_;
  this->field_0x68 = 0;
  (*___imp___0_Lockit_std__QAE_XZ)();
  local_4._0_1_ = 3;
  if (std::_Tree<>::_Nil == (_Node *)0x0) {
    std::_Tree<>::_Nil = operator_new(0x28);
    *(undefined4 *)(std::_Tree<>::_Nil + 4) = 0;
    *(undefined4 *)(std::_Tree<>::_Nil + 0x20) = 1;
    *(undefined4 *)std::_Tree<>::_Nil = 0;
    *(undefined4 *)(std::_Tree<>::_Nil + 8) = 0;
  }
  p_Var1 = std::_Tree<>::_Nil;
  std::_Tree<>::_Nilrefs = std::_Tree<>::_Nilrefs + 1;
  pvVar2 = operator_new(0x28);
  *(_Node **)((int)pvVar2 + 4) = p_Var1;
  *(undefined4 *)((int)pvVar2 + 0x20) = 0;
  *(void **)&this->field_0x64 = pvVar2;
  *(undefined4 *)&this->field_0x6c = 0;
  *(void **)pvVar2 = pvVar2;
  *(int *)(*(int *)&this->field_0x64 + 8) = *(int *)&this->field_0x64;
  local_4._0_1_ = 2;
  (*___imp___1_Lockit_std__QAE_XZ)();
  local_4._0_1_ = 4;
  CriticalSection::CriticalSection((CriticalSection *)&this->field_0x70);
  local_4._0_1_ = 5;
  CriticalSection::CriticalSection((CriticalSection *)&this->field_0x78);
  local_4._0_1_ = 6;
  InterfaceTable::InterfaceTable((InterfaceTable *)&this->field_0x7c);
  local_4._0_1_ = 7;
  this->field_0x84 = pPlugin._0_1_;
  pvVar2 = operator_new(0xc);
  *(void **)pvVar2 = pvVar2;
  *(void **)((int)pvVar2 + 4) = pvVar2;
  *(void **)&this->field_0x88 = pvVar2;
  *(undefined4 *)&this->field_0x8c = 0;
  local_4._0_1_ = 8;
  CriticalSection::CriticalSection((CriticalSection *)&this->field_0x90);
  local_4 = CONCAT31(local_4._1_3_,9);
  PRUDPTransportSettings::PRUDPTransportSettings(&this->m_oTransportSettings);
  *(undefined ***)this = &_vftable_;
  this->field_0x18 = 0;
  puVar3 = (undefined4 *)&this->field_0x2c;
  iVar4 = 2;
  do {
    puVar3[-2] = 0;
    *puVar3 = 0;
    puVar3[2] = 0;
    puVar3[4] = 0;
    puVar3[6] = 0;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)&this->field_0x4c = 0;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return this;
}



// public: virtual void * __thiscall PRUDPTransport::`scalar deleting destructor'(unsigned int)

void * __thiscall PRUDPTransport::_scalar_deleting_destructor_(PRUDPTransport *this,uint shouldDelete)

{
  ~PRUDPTransport(this);
  if ((shouldDelete & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: __thiscall PRUDPEndPointMap::~PRUDPEndPointMap(void)

void __thiscall PRUDPEndPointMap::~PRUDPEndPointMap(PRUDPEndPointMap *this)

{
  PRUDPEndPointMap *local_4;
  
  local_4 = this;
  std::_Tree<>::erase((_Tree<> *)this,&local_4,**(undefined4 **)(this + 4),
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
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: virtual __thiscall PRUDPTransport::~PRUDPTransport(void)

void __thiscall PRUDPTransport::~PRUDPTransport(PRUDPTransport *this)

{
  PRUDPEndPoint *pPVar1;
  int *piVar2;
  CallbackDispatcher *this_00;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  TraceOutput *pTVar6;
  undefined4 *puVar7;
  TraceOutput *this_01;
  TraceOutput *this_02;
  int iVar8;
  int unaff_FS_OFFSET;
  undefined4 in_stack_00000004;
  char *pcVar9;
  int local_10;
  undefined4 local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &_L55980;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  *(undefined ***)this = &_vftable_;
  pcVar9 = (char *)0x0;
  local_4 = 8;
  pTVar6 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_01,(ulong)pTVar6,pcVar9);
  pcVar9 = (char *)0x0;
  pTVar6 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_02,(ulong)pTVar6,pcVar9);
  if ((*(CallbackDispatcher **)&this->field_0x4c != (CallbackDispatcher *)0x0) &&
     (bVar5 = CallbackDispatcher::Stop(*(CallbackDispatcher **)&this->field_0x4c,5000), !bVar5)) {
    SystemError::TraceLast(1);
  }
  StopICMPListen(this,0);
  StopICMPListen(this,1);
  StopUDPListen(this,0);
  StopUDPListen(this,1);
  local_10 = **(int **)&this->field_0x64;
  if ((int *)local_10 != *(int **)&this->field_0x64) {
    do {
      pPVar1 = *(PRUDPEndPoint **)(local_10 + 0x18);
      if (pPVar1 != (PRUDPEndPoint *)0x0) {
        PRUDPEndPoint::~PRUDPEndPoint(pPVar1);
        operator_delete(pPVar1);
      }
      std::_Tree<>::const_iterator::_Inc((const_iterator *)&local_10);
    } while (local_10 != *(int *)&this->field_0x64);
  }
  ScopedCS::ScopedCS((ScopedCS *)&local_8,(CriticalSection *)&this->field_0x90,s_<unspecified>);
  iVar8 = *(int *)&this->field_0x8c;
  while (iVar8 != 0) {
    pPVar1 = *(PRUDPEndPoint **)(**(int **)&this->field_0x88 + 8);
    if (pPVar1 != (PRUDPEndPoint *)0x0) {
      PRUDPEndPoint::~PRUDPEndPoint(pPVar1);
      operator_delete(pPVar1);
    }
    local_c = **(undefined4 **)&this->field_0x88;
    puVar7 = (undefined4 *)
             std::list<>::iterator::operator++((iterator *)&local_c,(int)&stack0x00000000);
    piVar2 = (int *)*puVar7;
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    operator_delete(piVar2);
    iVar8 = *(int *)&this->field_0x8c + -1;
    *(int *)&this->field_0x8c = iVar8;
  }
  ScopedCS::~ScopedCS((ScopedCS *)&local_8);
  this_00 = *(CallbackDispatcher **)&this->field_0x4c;
  if (this_00 != (CallbackDispatcher *)0x0) {
    CallbackDispatcher::~CallbackDispatcher(this_00);
    operator_delete(this_00);
  }
  (*___imp__WSACleanup_0)();
  CriticalSection::~CriticalSection((CriticalSection *)&this->field_0x90);
  puVar7 = *(undefined4 **)&this->field_0x88;
  puVar4 = (undefined4 *)*puVar7;
  while (puVar4 != puVar7) {
    puVar3 = (undefined4 *)*puVar4;
    std::list<>::erase((list<> *)&this->field_0x84,&stack0x00000000,puVar4);
    puVar4 = puVar3;
  }
  operator_delete(*(void **)&this->field_0x88);
  *(undefined4 *)&this->field_0x88 = 0;
  *(undefined4 *)&this->field_0x8c = 0;
  InterfaceTable::~InterfaceTable((InterfaceTable *)&this->field_0x7c);
  CriticalSection::~CriticalSection((CriticalSection *)&this->field_0x78);
  CriticalSection::~CriticalSection((CriticalSection *)&this->field_0x70);
  std::_Tree<>::erase((_Tree<> *)&this->field_0x60,&stack0x00000000,
                      **(undefined4 **)&this->field_0x64,*(undefined4 **)&this->field_0x64);
  operator_delete(*(void **)&this->field_0x64);
  *(undefined4 *)&this->field_0x64 = 0;
  *(undefined4 *)&this->field_0x6c = 0;
  (*___imp___0_Lockit_std__QAE_XZ)();
  std::_Tree<>::_Nilrefs = std::_Tree<>::_Nilrefs - 1;
  if (std::_Tree<>::_Nilrefs == 0) {
    operator_delete(std::_Tree<>::_Nil);
    std::_Tree<>::_Nil = (_Node *)0x0;
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  TimeoutManager::~TimeoutManager((TimeoutManager *)&this->field_0x50);
  _eh_vector_destructor_iterator_(&this->field_0x1c,4,2,PRUDPInetAddress::~PRUDPInetAddress);
  Transport::~Transport((Transport *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = in_stack_00000004;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: virtual bool __thiscall PRUDPTransport::ResponsibleForURL(class StationURL *)

bool __thiscall PRUDPTransport::ResponsibleForURL(PRUDPTransport *this,StationURL *pStationURL)

{
  int iVar1;
  char local_80 [128];
  
  StationURL::GetTransportType(pStationURL,local_80,0x80);
  iVar1 = (*___imp___stricmp)(local_80,s_prudp);
  return (bool)('\x01' - (iVar1 != 0));
}



// public: virtual char * __thiscall PRUDPTransport::GetType(void)

char * __thiscall PRUDPTransport::GetType(PRUDPTransport *this)

{
  return s_prudp;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: virtual unsigned long __thiscall PRUDPTransport::Initialize(void)

ulong __thiscall PRUDPTransport::Initialize(PRUDPTransport *this)

{
  bool bVar1;
  ulong result;
  int iVar2;
  TraceOutput *pTVar3;
  TraceOutput *this_00;
  char *pcVar4;
  undefined1 local_190 [400];
  
  result = Transport::Initialize((Transport *)this);
  if (result == 0) {
    iVar2 = (*___imp__WSAStartup_8)(0x202,(short)local_190);
    if (iVar2 == -1) {
      (*___imp__WSACleanup_0)();
      return 2;
    }
    pcVar4 = (char *)0x0;
    pTVar3 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_00,(ulong)pTVar3,pcVar4);
    bVar1 = InterfaceTable::Query((InterfaceTable *)&this->field_0x7c);
    result = (-(uint)bVar1 & 0xffffffea) + 0x16;
  }
  return result;
}



// WARNING: Removing unreachable block (ram,0x000033e5)
// public: virtual unsigned long __thiscall PRUDPTransport::ListenOnWellKnown(void)

ulong __thiscall PRUDPTransport::ListenOnWellKnown(PRUDPTransport *this)

{
  bool bVar1;
  TraceOutput *pTVar2;
  PRUDPTransportSettings *this_00;
  ulong uVar3;
  TraceOutput *this_01;
  TraceOutput *this_02;
  TraceOutput *this_03;
  char *pcVar4;
  
  pcVar4 = (char *)0x6000000;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar4);
  StartEventListener(this);
  this_00 = GetSettings(this);
  uVar3 = PRUDPTransportSettings::GetWellKnownPortNumber(this_00);
  bVar1 = UDPListen(this,0,(ushort)uVar3);
  if (bVar1) {
    PRUDPInetAddress::GetPort((PRUDPInetAddress *)&this->field_0x1c);
    pcVar4 = (char *)0x6000000;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_03,(ulong)pTVar2,pcVar4);
    return 0;
  }
  pcVar4 = (char *)0x6000000;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar4);
  return 3;
}



// WARNING: Removing unreachable block (ram,0x000034a5)
// public: virtual unsigned long __thiscall PRUDPTransport::ListenOnArbitrary(void)

ulong __thiscall PRUDPTransport::ListenOnArbitrary(PRUDPTransport *this)

{
  bool bVar1;
  TraceOutput *pTVar2;
  TraceOutput *this_00;
  TraceOutput *this_01;
  TraceOutput *this_02;
  char *pcVar3;
  
  pcVar3 = (char *)0x6000000;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar3);
  StartEventListener(this);
  bVar1 = UDPListen(this,1,0);
  if (bVar1) {
    PRUDPInetAddress::GetPort((PRUDPInetAddress *)&this->field_0x20);
    pcVar3 = (char *)0x6000000;
    pTVar2 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar3);
    return 0;
  }
  pcVar3 = (char *)0x6000000;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar3);
  return 3;
}



// public: virtual unsigned long __thiscall PRUDPTransport::StopListenOnWellKnown(void)

ulong __thiscall PRUDPTransport::StopListenOnWellKnown(PRUDPTransport *this)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  char *pcVar2;
  
  pcVar2 = (char *)0x6000000;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,pcVar2);
  return 0;
}



// public: virtual unsigned long __thiscall PRUDPTransport::StopListenOnArbitrary(void)

ulong __thiscall PRUDPTransport::StopListenOnArbitrary(PRUDPTransport *this)

{
  TraceOutput *pTVar1;
  TraceOutput *this_00;
  char *pcVar2;
  
  pcVar2 = (char *)0x6000000;
  pTVar1 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar1,pcVar2);
  return 0;
}



// public: virtual class EndPoint * __thiscall PRUDPTransport::CreateEndPoint(void)

EndPoint * __thiscall PRUDPTransport::CreateEndPoint(PRUDPTransport *this)

{
  PRUDPEndPoint *pPVar1;
  EndPoint *pEVar2;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56012;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  if (*(int *)&this->field_0x24 == 0) {
    if (*(int *)&this->field_0x28 != 0) {
      pPVar1 = operator_new(0x60);
      local_4 = 1;
      if (pPVar1 != (PRUDPEndPoint *)0x0) {
        pEVar2 = (EndPoint *)PRUDPEndPoint::PRUDPEndPoint(pPVar1,(Transport *)this,1);
        *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
        return pEVar2;
      }
    }
  }
  else {
    pPVar1 = operator_new(0x60);
    local_4 = 0;
    if (pPVar1 != (PRUDPEndPoint *)0x0) {
      pEVar2 = (EndPoint *)PRUDPEndPoint::PRUDPEndPoint(pPVar1,(Transport *)this,0);
      *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
      return pEVar2;
    }
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return (EndPoint *)0x0;
}



// public: virtual unsigned long __thiscall PRUDPTransport::DeleteEndPoint(class EndPoint *)

ulong __thiscall PRUDPTransport::DeleteEndPoint(PRUDPTransport *this,EndPoint *pEndPoint)

{
  int *piVar1;
  EndPoint *pEVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pEVar2 = pEndPoint;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  local_4 = 0xffffffff;
  puStack_8 = &_L56246;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  UnregisterEndPoint(this,(PRUDPEndPoint *)pEndPoint);
  ScopedCS::ScopedCS((ScopedCS *)&pEndPoint,(CriticalSection *)&this->field_0x90,s_<unspecified>);
  piVar1 = *(int **)&this->field_0x88;
  local_4 = 0;
  piVar5 = (int *)piVar1[1];
  piVar3 = operator_new(0xc);
  piVar4 = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar4 = piVar3;
  }
  *piVar3 = (int)piVar4;
  if (piVar5 == (int *)0x0) {
    piVar5 = piVar3;
  }
  piVar3[1] = (int)piVar5;
  piVar1[1] = (int)piVar3;
  *(int **)piVar3[1] = piVar3;
  if (piVar3 + 2 != (int *)0x0) {
    piVar3[2] = (int)pEVar2;
  }
  local_4 = 0xffffffff;
  *(int *)&this->field_0x8c = *(int *)&this->field_0x8c + 1;
  ScopedCS::~ScopedCS((ScopedCS *)&pEndPoint);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return 0;
}



// public: virtual unsigned long __thiscall PRUDPTransport::SendBroadcast(class Buffer *)

ulong __thiscall PRUDPTransport::SendBroadcast(PRUDPTransport *this,Buffer *pBuffer)

{
  ulong uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  uVar1 = (**(code **)(*(int *)this + 0x2c))(pBuffer,0,local_8);
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: virtual unsigned long __thiscall PRUDPTransport::SendBroadcast(class Buffer *,void
// (__cdecl*const)(class Transport *,class Buffer *,unsigned long,class UserContext *),class
// UserContext const &)

ulong __thiscall
PRUDPTransport::SendBroadcast
          (PRUDPTransport *this,Buffer *pBuffer,
          _func_void_Transport_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr,UserContext *pContext)

{
  undefined1 *this_00;
  ulong uVar1;
  TraceOutput *pTVar2;
  InterfaceInfo *pIVar3;
  PRUDPTransportSettings *this_01;
  TraceOutput *this_02;
  ulong uVar4;
  int unaff_FS_OFFSET;
  code *in_stack_00000010;
  undefined4 in_stack_00000014;
  char *pcVar5;
  char *pcVar6;
  PRUDPInetAddress aPStack_11c [4];
  StationURL aSStack_118 [4];
  char local_114 [16];
  char acStack_104 [248];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  uStack_4 = 0xffffffff;
  puStack_8 = &_L56265;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  uVar1 = Buffer::GetContentSize(pBuffer);
  pcVar6 = s_PRUDPTransport__SendBroadcast__d;
  pcVar5 = (char *)0x6000000;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar5);
  (*___imp__sprintf)(local_114,s__s_s,s_prudp,s___,pcVar6,uVar1);
  this_00 = &this->field_0x7c;
  uVar4 = 0;
  uVar1 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
  if (uVar1 != 0) {
    do {
      pIVar3 = InterfaceTable::operator[]((InterfaceTable *)this_00,uVar4);
      uVar1 = InterfaceInfo::GetFlags(pIVar3);
      if ((uVar1 & 4) == 0) {
LAB_00003799:
        pcVar5 = acStack_104;
        uVar1 = 0x100;
        pIVar3 = InterfaceTable::operator[]((InterfaceTable *)this_00,uVar4);
        InterfaceInfo::GetBroadcastAddress(pIVar3,pcVar5,uVar1);
        PRUDPInetAddress::PRUDPInetAddress(aPStack_11c);
        PRUDPInetAddress::SetAddress(aPStack_11c,acStack_104);
        this_01 = GetSettings(this);
        uVar1 = PRUDPTransportSettings::GetWellKnownPortNumber(this_01);
        PRUDPInetAddress::SetPortNumber(aPStack_11c,(ushort)uVar1);
        StationURL::StationURL(aSStack_118,local_114);
        PRUDPInetAddress::GetURL(aPStack_11c,aSStack_118);
        (**(code **)(*(int *)this + 0x38))(aSStack_118,pBuffer);
        StationURL::~StationURL(aSStack_118);
        PRUDPInetAddress::~PRUDPInetAddress(aPStack_11c);
      }
      else {
        uVar1 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
        if (uVar1 < 2) goto LAB_00003799;
      }
      uVar4 = uVar4 + 1;
      uVar1 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
    } while (uVar4 < uVar1);
  }
  if (in_stack_00000010 != (code *)0x0) {
    (*in_stack_00000010)(this,pBuffer,0,in_stack_00000014);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_4;
  return 0;
}



// public: virtual unsigned long __thiscall PRUDPTransport::Send(class StationURL *,class Buffer *)

ulong __thiscall PRUDPTransport::Send(PRUDPTransport *this,StationURL *pStationURL,Buffer *pBuffer)

{
  ulong uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  uVar1 = (**(code **)(*(int *)this + 0x34))(pStationURL,pBuffer,0,local_8);
  return uVar1;
}



// public: virtual unsigned long __thiscall PRUDPTransport::Send(class StationURL *,class Buffer
// *,void (__cdecl*const)(class Transport *,class Buffer *,unsigned long,class UserContext *),class
// UserContext const &)

ulong __thiscall
PRUDPTransport::Send
          (PRUDPTransport *this,StationURL *pStationURL,Buffer *pBuffer,
          _func_void_Transport_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr,UserContext *pContext)

{
  char cVar1;
  bool bVar2;
  TraceOutput *pTVar3;
  ulong uVar4;
  PRUDPTransportSettings *this_00;
  PacketOut *this_01;
  Packet *this_02;
  TraceOutput *this_03;
  int unaff_FS_OFFSET;
  undefined4 in_stack_00000014;
  char *pcVar5;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  uStack_4 = 0xffffffff;
  puStack_8 = &_L56290;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  Buffer::GetContentSize(pBuffer);
  StationURL::GetURL(pStationURL);
  pcVar5 = (char *)0x6000000;
  pTVar3 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_03,(ulong)pTVar3,pcVar5);
  cVar1 = (**(code **)(*(int *)this + 4))(pStationURL);
  if (cVar1 == '\0') {
    uVar4 = 0xf;
  }
  else {
    PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
    this_00 = GetSettings(this);
    uVar4 = PRUDPTransportSettings::GetWellKnownPortNumber(this_00);
    bVar2 = PRUDPInetAddress::SetFromURL((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr,pStationURL,(ushort)uVar4);
    if (bVar2) {
      if (pBuffer == (Buffer *)0x0) {
        PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
        uVar4 = 10;
      }
      else {
        this_01 = operator_new(0x50);
        if (this_01 == (PacketOut *)0x0) {
          this_02 = (Packet *)0x0;
        }
        else {
          this_02 = (Packet *)PacketOut::PacketOut(this_01,(PRUDPEndPoint *)0x0,'\x04','\0',pBuffer)
          ;
        }
        Packet::SetPeerAddress(this_02,(PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
        if (*(int *)&this->field_0x24 == 0) {
          if (*(int *)&this->field_0x28 == 0) {
            RefCountedObject::ReleaseRef((RefCountedObject *)this_02);
            PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
            uVar4 = 0x10;
            goto LAB_00003a50;
          }
          uVar4 = 1;
        }
        else {
          uVar4 = 0;
        }
        bVar2 = Send(this,uVar4,(PacketOut *)this_02);
        RefCountedObject::ReleaseRef((RefCountedObject *)this_02);
        if (bVar2) {
          if (pContext != (UserContext *)0x0) {
            (*(code *)pContext)(this,pBuffer,0,in_stack_00000014);
          }
          PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
          uVar4 = 0;
        }
        else {
          PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
          uVar4 = 3;
        }
      }
    }
    else {
      PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&p_func_void_transport_ptr_buffer_ptr_ulong_usercontext_ptr);
      uVar4 = 0xc;
    }
  }
LAB_00003a50:
  *(undefined1 **)(&__except_list + unaff_FS_OFFSET) = puStack_8;
  return uVar4;
}



// public: virtual unsigned long __thiscall PRUDPTransport::GetNbLocalURL(void)

ulong __thiscall PRUDPTransport::GetNbLocalURL(PRUDPTransport *this)

{
  undefined1 *this_00;
  ulong uVar1;
  ulong uVar2;
  
  this_00 = &this->field_0x7c;
  uVar1 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
  if (uVar1 == 0) {
    return 0;
  }
  uVar1 = InterfaceTable::GetNbLoopbackInterface((InterfaceTable *)this_00);
  uVar2 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
  if (uVar1 == uVar2) {
    return 1;
  }
  uVar1 = InterfaceTable::GetNbLoopbackInterface((InterfaceTable *)this_00);
  uVar2 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
  return uVar2 - uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: virtual class StationURL * __thiscall PRUDPTransport::GetLocalURL(unsigned long)

StationURL * __thiscall PRUDPTransport::GetLocalURL(PRUDPTransport *this,ulong ulValue)

{
  undefined1 *this_00;
  ushort uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  InterfaceInfo *pIVar5;
  StationURL *this_01;
  ulong uVar6;
  int unaff_FS_OFFSET;
  char *pcVar7;
  StationURL *pSStack_234;
  StationURL *pSStack_230;
  char acStack_22c [16];
  char acStack_21c [16];
  char acStack_20c [256];
  char acStack_10c [256];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  iStack_4 = 0xffffffff;
  puStack_8 = &_L56318;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  uVar2 = (**(code **)(*(int *)this + 0x5c))();
  if (ulValue < uVar2) {
    this_00 = &this->field_0x7c;
    uVar3 = InterfaceTable::GetNbLoopbackInterface((InterfaceTable *)this_00);
    uVar4 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
    if (uVar3 == uVar4) {
      (*___imp__sprintf)(acStack_22c,s__s_s,s_prudp,s___);
      pcVar7 = acStack_20c;
      uVar3 = 0x100;
      pIVar5 = InterfaceTable::operator[]((InterfaceTable *)this_00,0);
      InterfaceInfo::GetAddress(pIVar5,pcVar7,uVar3);
      PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)&pSStack_234);
      iStack_4 = 0;
      PRUDPInetAddress::SetAddress((PRUDPInetAddress *)&pSStack_234,acStack_20c);
      uVar1 = GetPortNumber(this,0);
      uVar1 = GetPortNumber(this,(uint)(uVar1 == 0));
      PRUDPInetAddress::SetPortNumber((PRUDPInetAddress *)&pSStack_234,uVar1);
      pSStack_230 = operator_new(4);
      iStack_4._0_1_ = 1;
      if (pSStack_230 == (StationURL *)0x0) {
        this_01 = (StationURL *)0x0;
      }
      else {
        this_01 = (StationURL *)StationURL::StationURL(pSStack_230);
      }
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      StationURL::SetURL(this_01,acStack_22c);
      PRUDPInetAddress::GetURL((PRUDPInetAddress *)&pSStack_234,this_01);
      iStack_4 = 0xffffffff;
      PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&pSStack_234);
      goto LAB_00003c24;
    }
    uVar4 = 0;
    uVar6 = 0;
    uVar3 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
    if (uVar3 != 0) {
      do {
        pIVar5 = InterfaceTable::operator[]((InterfaceTable *)this_00,uVar6);
        uVar3 = InterfaceInfo::GetFlags(pIVar5);
        if ((uVar3 & 4) == 0) {
          if (uVar4 == ulValue) {
            (*___imp__sprintf)(acStack_21c,s__s_s,s_prudp,s___);
            pcVar7 = acStack_10c;
            uVar3 = 0x100;
            pIVar5 = InterfaceTable::operator[]((InterfaceTable *)this_00,uVar6);
            InterfaceInfo::GetAddress(pIVar5,pcVar7,uVar3);
            PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)&pSStack_230);
            iStack_4 = 2;
            PRUDPInetAddress::SetAddress((PRUDPInetAddress *)&pSStack_230,acStack_10c);
            uVar1 = GetPortNumber(this,0);
            uVar1 = GetPortNumber(this,(uint)(uVar1 == 0));
            PRUDPInetAddress::SetPortNumber((PRUDPInetAddress *)&pSStack_230,uVar1);
            pSStack_234 = operator_new(4);
            iStack_4._0_1_ = 3;
            if (pSStack_234 == (StationURL *)0x0) {
              this_01 = (StationURL *)0x0;
            }
            else {
              this_01 = (StationURL *)StationURL::StationURL(pSStack_234);
            }
            iStack_4 = CONCAT31(iStack_4._1_3_,2);
            StationURL::SetURL(this_01,acStack_21c);
            PRUDPInetAddress::GetURL((PRUDPInetAddress *)&pSStack_230,this_01);
            iStack_4 = 0xffffffff;
            PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&pSStack_230);
            goto LAB_00003c24;
          }
          uVar4 = uVar4 + 1;
        }
        uVar6 = uVar6 + 1;
        uVar3 = InterfaceTable::GetNbInterface((InterfaceTable *)this_00);
      } while (uVar6 < uVar3);
    }
  }
  this_01 = (StationURL *)0x0;
LAB_00003c24:
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return this_01;
}



// public: virtual class StationURL * __thiscall PRUDPTransport::GetIPURL(unsigned long,unsigned
// short)

StationURL * __thiscall PRUDPTransport::GetIPURL(PRUDPTransport *this,ulong ulValue,ushort usValue)

{
  bool bVar1;
  StationURL *this_00;
  int unaff_FS_OFFSET;
  PRUDPInetAddress local_14 [4];
  StationURL *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56344;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_10 = operator_new(4);
  local_4 = 0;
  if (local_10 == (StationURL *)0x0) {
    this_00 = (StationURL *)0x0;
  }
  else {
    this_00 = (StationURL *)StationURL::StationURL(local_10);
  }
  local_4 = 0xffffffff;
  PRUDPInetAddress::PRUDPInetAddress(local_14);
  local_4 = 1;
  PRUDPInetAddress::SetAddress(local_14,ulValue);
  PRUDPInetAddress::SetPortNumber(local_14,usValue);
  StationURL::SetURL(this_00,s_prudp__);
  bVar1 = PRUDPInetAddress::GetURL(local_14,this_00);
  if (!bVar1) {
    if (this_00 != (StationURL *)0x0) {
      StationURL::~StationURL(this_00);
      operator_delete(this_00);
    }
    local_4 = 0xffffffff;
    PRUDPInetAddress::~PRUDPInetAddress(local_14);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return (StationURL *)0x0;
  }
  StationURL::Trace(this_00,1);
  local_4 = 0xffffffff;
  PRUDPInetAddress::~PRUDPInetAddress(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this_00;
}



// public: virtual class StationURL * __thiscall PRUDPTransport::GetIPURL(char *,unsigned short)

StationURL * __thiscall PRUDPTransport::GetIPURL(PRUDPTransport *this,char *szText,ushort usValue)

{
  bool bVar1;
  StationURL *this_00;
  int unaff_FS_OFFSET;
  PRUDPInetAddress local_14 [4];
  StationURL *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56377;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_10 = operator_new(4);
  local_4 = 0;
  if (local_10 == (StationURL *)0x0) {
    this_00 = (StationURL *)0x0;
  }
  else {
    this_00 = (StationURL *)StationURL::StationURL(local_10);
  }
  local_4 = 0xffffffff;
  PRUDPInetAddress::PRUDPInetAddress(local_14);
  local_4 = 1;
  bVar1 = PRUDPInetAddress::SetAddress(local_14,szText);
  if (!bVar1) {
    if (this_00 != (StationURL *)0x0) {
      StationURL::~StationURL(this_00);
      operator_delete(this_00);
    }
    local_4 = 0xffffffff;
    PRUDPInetAddress::~PRUDPInetAddress(local_14);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return (StationURL *)0x0;
  }
  PRUDPInetAddress::SetPortNumber(local_14,usValue);
  StationURL::SetURL(this_00,s_prudp__);
  bVar1 = PRUDPInetAddress::GetURL(local_14,this_00);
  if (!bVar1) {
    if (this_00 != (StationURL *)0x0) {
      StationURL::~StationURL(this_00);
      operator_delete(this_00);
    }
    local_4 = 0xffffffff;
    PRUDPInetAddress::~PRUDPInetAddress(local_14);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return (StationURL *)0x0;
  }
  StationURL::Trace(this_00,1);
  local_4 = 0xffffffff;
  PRUDPInetAddress::~PRUDPInetAddress(local_14);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this_00;
}



// public: virtual bool __thiscall PRUDPTransport::GetIPFromURL(class StationURL *,unsigned long
// *,unsigned short *)

bool __thiscall
PRUDPTransport::GetIPFromURL
          (PRUDPTransport *this,StationURL *pStationURL,ulong *pulValue,ushort *pUshort)

{
  bool bVar1;
  ushort uVar2;
  PRUDPTransportSettings *this_00;
  ulong uVar3;
  int unaff_FS_OFFSET;
  PRUDPTransport *local_10;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56390;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  local_10 = this;
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)&local_10);
  local_4 = 0;
  this_00 = GetSettings(this);
  uVar3 = PRUDPTransportSettings::GetWellKnownPortNumber(this_00);
  bVar1 = PRUDPInetAddress::SetFromURL((PRUDPInetAddress *)&local_10,pStationURL,(ushort)uVar3);
  if (((bVar1) && (pulValue != (ulong *)0x0)) && (pUshort != (ushort *)0x0)) {
    uVar3 = PRUDPInetAddress::GetAddress((PRUDPInetAddress *)&local_10);
    *pulValue = uVar3;
    uVar2 = PRUDPInetAddress::GetPort((PRUDPInetAddress *)&local_10);
    *pUshort = uVar2;
    local_4 = 0xffffffff;
    PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&local_10);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return true;
  }
  local_4 = 0xffffffff;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&local_10);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return false;
}



// public: virtual void __thiscall PRUDPTransport::ReleaseURL(class StationURL *)

void __thiscall PRUDPTransport::ReleaseURL(PRUDPTransport *this,StationURL *pStationURL)

{
  if (pStationURL != (StationURL *)0x0) {
    StationURL::~StationURL(pStationURL);
    operator_delete(pStationURL);
  }
  return;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::ConnectEndPoint(class EndPoint
// *,class StationURL *,class Buffer *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned
// long,class UserContext *),class UserContext const &,unsigned long)

ulong __thiscall
PRUDPTransport::ConnectEndPoint
          (PRUDPTransport *this,EndPoint *pEndPoint,StationURL *pStationURL,Buffer *pBuffer,
          _func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,UserContext *pContext,
          ulong ulValue)

{
  char cVar1;
  ulong uVar2;
  PRUDPEndPoint *unaff_retaddr;
  
  cVar1 = (**(code **)(*(int *)this + 4))(pStationURL);
  if (cVar1 == '\0') {
    return 0xf;
  }
  uVar2 = PRUDPEndPoint::Connect
                    (unaff_retaddr,pStationURL,(Buffer *)pStationURL,
                     (_func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *)pBuffer,
                     (UserContext *)p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,(ulong)pContext);
  return uVar2;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::DisconnectEndPoint(class EndPoint
// *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class
// UserContext const &,unsigned long)

ulong __thiscall
PRUDPTransport::DisconnectEndPoint
          (PRUDPTransport *this,EndPoint *pEndPoint,
          _func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,UserContext *pContext,
          ulong ulValue)

{
  ulong uVar1;
  
  uVar1 = PRUDPEndPoint::Disconnect((PRUDPEndPoint *)pEndPoint,p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,pContext,ulValue);
  return uVar1;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::SendToEndPoint(class EndPoint *,class
// Buffer *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext
// *),class UserContext const &,unsigned long)

ulong __thiscall
PRUDPTransport::SendToEndPoint
          (PRUDPTransport *this,EndPoint *pEndPoint,Buffer *pBuffer,
          _func_void_EndPoint_ptr_Buffer_ptr_ulong_UserContext_ptr *p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,UserContext *pContext,
          ulong ulValue)

{
  ulong uVar1;
  
  uVar1 = PRUDPEndPoint::Send((PRUDPEndPoint *)pEndPoint,pBuffer,p_func_void_endpoint_ptr_buffer_ptr_ulong_usercontext_ptr,pContext,ulValue);
  return uVar1;
}



// protected: virtual bool __thiscall PRUDPTransport::IsEndPointConnected(class EndPoint *)

bool __thiscall PRUDPTransport::IsEndPointConnected(PRUDPTransport *this,EndPoint *pEndPoint)

{
  bool bVar1;
  
  bVar1 = PRUDPEndPoint::IsConnected((PRUDPEndPoint *)pEndPoint);
  return bVar1;
}



// protected: virtual bool __thiscall PRUDPTransport::IsEndPointPeerConnected(class EndPoint *)

bool __thiscall PRUDPTransport::IsEndPointPeerConnected(PRUDPTransport *this,EndPoint *pEndPoint)

{
  bool bVar1;
  
  bVar1 = PRUDPEndPoint::IsPeerConnected((PRUDPEndPoint *)pEndPoint);
  return bVar1;
}



// protected: virtual bool __thiscall PRUDPTransport::IsEndPointDisconnected(class EndPoint *)

bool __thiscall PRUDPTransport::IsEndPointDisconnected(PRUDPTransport *this,EndPoint *pEndPoint)

{
  bool bVar1;
  
  bVar1 = PRUDPEndPoint::IsDisconnected((PRUDPEndPoint *)pEndPoint);
  return bVar1;
}



// protected: virtual bool __thiscall PRUDPTransport::IsEndPointPeerDisconnected(class EndPoint *)

bool __thiscall PRUDPTransport::IsEndPointPeerDisconnected(PRUDPTransport *this,EndPoint *pEndPoint)

{
  bool bVar1;
  
  bVar1 = PRUDPEndPoint::IsPeerDisconnected((PRUDPEndPoint *)pEndPoint);
  return bVar1;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::RegisterEndPointEventHandler(class
// EndPoint *,class EndPointEventHandler *)

ulong __thiscall
PRUDPTransport::RegisterEndPointEventHandler
          (PRUDPTransport *this,EndPoint *pEndPoint,EndPointEventHandler *pEndPointEventHandler)

{
  ulong uVar1;
  
  uVar1 = EndPoint::RegisterEventHandler(pEndPoint,pEndPointEventHandler);
  return uVar1;
}



// protected: virtual class StationURL * __thiscall PRUDPTransport::GetEndPointStationURL(class
// EndPoint *)

StationURL * __thiscall
PRUDPTransport::GetEndPointStationURL(PRUDPTransport *this,EndPoint *pEndPoint)

{
  StationURL *pSVar1;
  
  pSVar1 = PRUDPEndPoint::GetStationURL((PRUDPEndPoint *)pEndPoint);
  return pSVar1;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::GetEndPointQueueSize(class EndPoint
// *)

ulong __thiscall PRUDPTransport::GetEndPointQueueSize(PRUDPTransport *this,EndPoint *pEndPoint)

{
  ulong uVar1;
  
  uVar1 = PRUDPEndPoint::GetQueueSize((PRUDPEndPoint *)pEndPoint);
  return uVar1;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::GetEndPointRTT(class EndPoint *)

ulong __thiscall PRUDPTransport::GetEndPointRTT(PRUDPTransport *this,EndPoint *pEndPoint)

{
  RTT *this_00;
  ulong uVar1;
  
  this_00 = PRUDPEndPoint::GetRTT((PRUDPEndPoint *)pEndPoint);
  uVar1 = RTT::GetLastRTT(this_00);
  return uVar1;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::GetEndPointRTTAverage(class EndPoint
// *)

ulong __thiscall PRUDPTransport::GetEndPointRTTAverage(PRUDPTransport *this,EndPoint *pEndPoint)

{
  RTT *this_00;
  ulong uVar1;
  
  this_00 = PRUDPEndPoint::GetRTT((PRUDPEndPoint *)pEndPoint);
  uVar1 = RTT::GetRTTSmoothedAvg(this_00);
  return uVar1;
}



// protected: virtual unsigned long __thiscall PRUDPTransport::SendToEndPointGroup(class
// EndPointGroup *,class Buffer *,void (__cdecl*const *)(class EndPointGroup *,class Buffer *,class
// UserContext *),class UserContext const &,unsigned long)

ulong __thiscall
PRUDPTransport::SendToEndPointGroup
          (PRUDPTransport *this,EndPointGroup *pEndPointGroup,Buffer *pBuffer,
          _func_void_EndPointGroup_ptr_Buffer_ptr_UserContext_ptr **p_func_void_endpointgroup_ptr_buffer_ptr_usercontext_ptr,UserContext *pContext,
          ulong ulValue)

{
  return 1;
}



// public: virtual bool __thiscall PRUDPTransport::IsCapable(unsigned long)

bool __thiscall PRUDPTransport::IsCapable(PRUDPTransport *this,TRANSPORT_CAPS ulCapability)

{
  switch(ulCapability) {
  case IP_BASED	:
  case BROADCAST:
  case DEVICE_EMULATION	:
  case PERF_COUNTERS:
  case WELLKNOWN_LISTEN_SUPPORTED:
  case ARBITRARY_LISTEN_SUPPORTED:
    return true;
  default:
    return false;
  }
}



// public: virtual unsigned long __thiscall PRUDPTransport::SetOption(unsigned long,class
// UserContext &)

ulong __thiscall
PRUDPTransport::SetOption(PRUDPTransport *this,ulong ulOption,UserContext *oOptionSetting)

{
  ulong uVar1;
  
  uVar1 = PRUDPTransportSettings::SetOption(&this->m_oTransportSettings,ulOption,oOptionSetting);
  return uVar1;
}



// public: virtual unsigned long __thiscall PRUDPTransport::GetOption(unsigned long,class
// UserContext &)

ulong __thiscall PRUDPTransport::GetOption(PRUDPTransport *this,ulong ulValue,UserContext *pContext)

{
  ulong uVar1;
  
  uVar1 = PRUDPTransportSettings::GetOption(&this->m_oTransportSettings,ulValue,pContext);
  return uVar1;
}



// private: void __thiscall PRUDPTransport::StartEventListener(void)

void __thiscall PRUDPTransport::StartEventListener(PRUDPTransport *this)

{
  CallbackDispatcher *this_00;
  undefined4 uVar1;
  PRUDPTransportSettings *this_01;
  ulong uVar2;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56447;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  if (*(int *)&this->field_0x4c == 0) {
    this_00 = operator_new(0x4c);
    local_4 = 0;
    if (this_00 == (CallbackDispatcher *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = CallbackDispatcher::CallbackDispatcher(this_00,(ulong)this);
    }
    local_4 = 0xffffffff;
    *(undefined4 *)&this->field_0x4c = uVar1;
    this_01 = GetSettings(this);
    uVar2 = PRUDPTransportSettings::GetTimeSlice(this_01);
    CallbackDispatcher::RegisterTimeSliceCallback
              (*(CallbackDispatcher **)&this->field_0x4c,HandleTimeSliceWrap,0,uVar2);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// public: void __thiscall PRUDPTransport::SetHighPrio(void)

void __thiscall PRUDPTransport::SetHighPrio(PRUDPTransport *this)

{
  CallbackDispatcher::SetPriority(*(CallbackDispatcher **)&this->field_0x4c,2);
  return;
}



// private: bool __thiscall PRUDPTransport::UDPListen(unsigned long,unsigned short)

bool __thiscall PRUDPTransport::UDPListen(PRUDPTransport *this,ulong ulValue,ushort usValue)

{
  bool bVar1;
  UDPSocket *pUVar2;
  Socket *this_00;
  TraceOutput *pTVar3;
  Event *pEVar4;
  PRUDPTransportSettings *pPVar5;
  TraceOutput *this_01;
  TraceOutput *this_02;
  int unaff_FS_OFFSET;
  char *pcVar6;
  ScopedCS local_14 [4];
  ushort local_10 [2];
  undefined4 local_c;
  undefined1 *local_8;
  int local_4;
  
  local_4 = 0xffffffff;
  local_8 = &_L56475;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_14,(CriticalSection *)&this->field_0x78,s_<unspecified>);
  local_4 = 0;
  if (*(int *)(&this->field_0x24 + ulValue * 4) != 0) {
    local_4 = 0xffffffff;
    ScopedCS::~ScopedCS(local_14);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return true;
  }
  Platform::SystemCheck(true,s_m_apSocket_ulSocket___NULL,s_PRUDPTransport_cpp,0x23c);
  pUVar2 = operator_new(0x30);
  local_4._0_1_ = 1;
  if (pUVar2 == (UDPSocket *)0x0) {
    this_00 = (Socket *)0x0;
  }
  else {
    this_00 = (Socket *)UDPSocket::UDPSocket(pUVar2,this);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(Socket **)(&this->field_0x24 + ulValue * 4) = this_00;
  bVar1 = Socket::Open(this_00);
  if (bVar1) {
    PRUDPInetAddress::SetPortNumber((PRUDPInetAddress *)(&this->field_0x1c + ulValue * 4),usValue);
    bVar1 = UDPSocket::Bind(*(UDPSocket **)(&this->field_0x24 + ulValue * 4),
                            (PRUDPInetAddress *)(&this->field_0x1c + ulValue * 4),local_10);
    if (bVar1) {
      pcVar6 = (char *)0x0;
      pTVar3 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar3,pcVar6);
      pEVar4 = CallbackDispatcher::CreateCallbackEvent
                         (*(CallbackDispatcher **)&this->field_0x4c,HandleRecvCompletedWrap,ulValue)
      ;
      *(Event **)(&this->field_0x2c + ulValue * 4) = pEVar4;
      pEVar4 = CallbackDispatcher::CreateCallbackEvent
                         (*(CallbackDispatcher **)&this->field_0x4c,HandleSendCompletedWrap,ulValue)
      ;
      *(Event **)(&this->field_0x34 + ulValue * 4) = pEVar4;
      UDPSocket::SetCompletionEvents
                (*(UDPSocket **)(&this->field_0x24 + ulValue * 4),
                 *(Event **)(&this->field_0x2c + ulValue * 4),pEVar4);
      UDPSocket::Listen(*(UDPSocket **)(&this->field_0x24 + ulValue * 4));
      pPVar5 = GetSettings(this);
      bVar1 = PRUDPTransportSettings::IsTrappingICMP(pPVar5);
      if (bVar1) {
        bVar1 = ICMPListen(this,ulValue,(ushort)local_8);
        pPVar5 = GetSettings(this);
        PRUDPTransportSettings::TrapICMP(pPVar5,bVar1);
      }
      ScopedCS::~ScopedCS((ScopedCS *)&local_c);
      *(int *)(&__except_list + unaff_FS_OFFSET) = local_4;
      return true;
    }
    pcVar6 = (char *)0x0;
    pTVar3 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_02,(ulong)pTVar3,pcVar6);
    pUVar2 = *(UDPSocket **)(&this->field_0x24 + ulValue * 4);
    if (pUVar2 != (UDPSocket *)0x0) {
      UDPSocket::~UDPSocket(pUVar2);
      operator_delete(pUVar2);
    }
    *(undefined4 *)(&this->field_0x24 + ulValue * 4) = 0;
  }
  ScopedCS::~ScopedCS((ScopedCS *)&local_c);
  *(int *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return false;
}



// private: bool __thiscall PRUDPTransport::StopUDPListen(unsigned long)

bool __thiscall PRUDPTransport::StopUDPListen(PRUDPTransport *this,ulong ulValue)

{
  UDPSocket *this_00;
  
  if (*(Socket **)(&this->field_0x24 + ulValue * 4) != (Socket *)0x0) {
    Socket::Close(*(Socket **)(&this->field_0x24 + ulValue * 4));
    if (*(Event **)(&this->field_0x2c + ulValue * 4) != (Event *)0x0) {
      CallbackDispatcher::DeleteCallbackEvent
                (*(CallbackDispatcher **)&this->field_0x4c,
                 *(Event **)(&this->field_0x2c + ulValue * 4));
    }
    if (*(Event **)(&this->field_0x34 + ulValue * 4) != (Event *)0x0) {
      CallbackDispatcher::DeleteCallbackEvent
                (*(CallbackDispatcher **)&this->field_0x4c,
                 *(Event **)(&this->field_0x34 + ulValue * 4));
    }
    this_00 = *(UDPSocket **)(&this->field_0x24 + ulValue * 4);
    if (this_00 != (UDPSocket *)0x0) {
      UDPSocket::~UDPSocket(this_00);
      operator_delete(this_00);
    }
    *(undefined4 *)(&this->field_0x24 + ulValue * 4) = 0;
    return true;
  }
  return false;
}



// private: bool __thiscall PRUDPTransport::ICMPListen(unsigned long,unsigned short)

bool __thiscall PRUDPTransport::ICMPListen(PRUDPTransport *this,ulong ulValue,ushort usValue)

{
  bool bVar1;
  TraceOutput *pTVar2;
  ICMPSocket *pIVar3;
  undefined4 uVar4;
  Event *pEVar5;
  TraceOutput *this_00;
  TraceOutput *this_01;
  TraceOutput *this_02;
  int unaff_FS_OFFSET;
  int in_stack_0000000c;
  char *pcVar6;
  PRUDPTransport *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56511;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_10 = this;
  ScopedCS::ScopedCS((ScopedCS *)&local_10,(CriticalSection *)&this->field_0x78,s_<unspecified>);
  local_4 = 0;
  pcVar6 = (char *)0x0;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_00,(ulong)pTVar2,pcVar6);
  if (*(int *)(&this->field_0x3c + in_stack_0000000c * 4) != 0) {
LAB_00004619:
    local_10 = (PRUDPTransport *)0x462a;
    ScopedCS::~ScopedCS((ScopedCS *)&stack0x00000000);
    *(ulong *)(&__except_list + unaff_FS_OFFSET) = ulValue;
    return true;
  }
  pIVar3 = operator_new(0x48);
  if (pIVar3 == (ICMPSocket *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = ICMPSocket::ICMPSocket(pIVar3);
  }
  *(undefined4 *)(&this->field_0x3c + in_stack_0000000c * 4) = uVar4;
  PRUDPInetAddress::PRUDPInetAddress((PRUDPInetAddress *)&stack0x00000010);
  ulValue = CONCAT31(ulValue._1_3_,2);
  bVar1 = Socket::Open(*(Socket **)(&this->field_0x3c + in_stack_0000000c * 4));
  if (bVar1) {
    bVar1 = ICMPSocket::Bind(*(ICMPSocket **)(&this->field_0x3c + in_stack_0000000c * 4),
                             (PRUDPInetAddress *)&stack0x00000010);
    if (bVar1) {
      pEVar5 = CallbackDispatcher::CreateCallbackEvent
                         (*(CallbackDispatcher **)&this->field_0x4c,HandleICMPCompletedWrap,
                          *(ulong *)(&this->field_0x3c + in_stack_0000000c * 4));
      *(Event **)(&this->field_0x44 + in_stack_0000000c * 4) = pEVar5;
      ICMPSocket::SetCompletionEvent
                (*(ICMPSocket **)(&this->field_0x3c + in_stack_0000000c * 4),pEVar5);
      ICMPSocket::QueueRecv(*(ICMPSocket **)(&this->field_0x3c + in_stack_0000000c * 4));
      pcVar6 = (char *)0x6000000;
      pTVar2 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar2,pcVar6);
      local_10 = (PRUDPTransport *)0x4619;
      PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&stack0x00000018);
      goto LAB_00004619;
    }
  }
  pcVar6 = (char *)0x0;
  pTVar2 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_02,(ulong)pTVar2,pcVar6);
  SystemError::TraceLast(0);
  Socket::Close(*(Socket **)(&this->field_0x3c + in_stack_0000000c * 4));
  pIVar3 = *(ICMPSocket **)(&this->field_0x3c + in_stack_0000000c * 4);
  if (pIVar3 != (ICMPSocket *)0x0) {
    ICMPSocket::~ICMPSocket(pIVar3);
    operator_delete(pIVar3);
  }
  *(undefined4 *)(&this->field_0x3c + in_stack_0000000c * 4) = 0;
  PRUDPInetAddress::~PRUDPInetAddress((PRUDPInetAddress *)&stack0x00000018);
  ScopedCS::~ScopedCS((ScopedCS *)&stack0x00000000);
  *(ulong *)(&__except_list + unaff_FS_OFFSET) = ulValue;
  return false;
}



// private: bool __thiscall PRUDPTransport::StopICMPListen(unsigned long)

bool __thiscall PRUDPTransport::StopICMPListen(PRUDPTransport *this,ulong ulValue)

{
  ICMPSocket *this_00;
  
  if (*(Socket **)(&this->field_0x3c + ulValue * 4) != (Socket *)0x0) {
    Socket::Close(*(Socket **)(&this->field_0x3c + ulValue * 4));
    this_00 = *(ICMPSocket **)(&this->field_0x3c + ulValue * 4);
    if (this_00 != (ICMPSocket *)0x0) {
      ICMPSocket::~ICMPSocket(this_00);
      operator_delete(this_00);
    }
    *(undefined4 *)(&this->field_0x3c + ulValue * 4) = 0;
    if (*(Event **)(&this->field_0x44 + ulValue * 4) != (Event *)0x0) {
      CallbackDispatcher::DeleteCallbackEvent
                (*(CallbackDispatcher **)&this->field_0x4c,
                 *(Event **)(&this->field_0x44 + ulValue * 4));
    }
    return true;
  }
  return false;
}



// private: bool __thiscall PRUDPTransport::RegisterEndPoint(class PRUDPEndPoint *)

bool __thiscall PRUDPTransport::RegisterEndPoint(PRUDPTransport *this,PRUDPEndPoint *pPRUDPEndPoint)

{
  PRUDPEndPoint *this_00;
  PRUDPInetAddress *pPVar1;
  int *piVar2;
  TraceOutput *pTVar3;
  TraceOutput *this_01;
  TraceOutput *this_02;
  int unaff_FS_OFFSET;
  char *pcVar4;
  ulong uVar5;
  ScopedCS local_30 [4];
  undefined8 local_2c;
  pair<> local_24 [12];
  int local_18;
  __int64 local_14;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56671;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_30,(CriticalSection *)&this->field_0x70,s_<unspecified>);
  this_00 = pPRUDPEndPoint;
  local_4 = 0;
  pPVar1 = PRUDPEndPoint::GetPRUDPInetAddress(pPRUDPEndPoint);
  local_2c = PRUDPInetAddress::GetKey(pPVar1);
  piVar2 = (int *)std::_Tree<>::find((_Tree<> *)&this->field_0x60,(__int64 *)&pPRUDPEndPoint);
  if ((*piVar2 != *(int *)&this->field_0x64) && (*(int *)(*piVar2 + 0x18) != 0)) {
    pcVar4 = (char *)0x6000000;
    pTVar3 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_02,(ulong)pTVar3,pcVar4);
    pPRUDPEndPoint = (PRUDPEndPoint *)0xffffffff;
    ScopedCS::~ScopedCS((ScopedCS *)((int)&local_2c + 4));
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
    return false;
  }
  pcVar4 = (char *)0x0;
  pTVar3 = TraceOutput::GetInstance();
  TraceOutput::Trace(this_01,(ulong)pTVar3,pcVar4);
  uVar5 = 0;
  pPVar1 = PRUDPEndPoint::GetPRUDPInetAddress(this_00);
  PRUDPInetAddress::Trace(pPVar1,uVar5);
  pPVar1 = PRUDPEndPoint::GetPRUDPInetAddress(this_00);
  local_14 = PRUDPInetAddress::GetKey(pPVar1);
  local_c = 0;
  piVar2 = (int *)std::_Tree<>::insert((_Tree<> *)&this->field_0x60,local_24);
  pPRUDPEndPoint = (PRUDPEndPoint *)0xffffffff;
  local_18 = piVar2[1];
  *(PRUDPEndPoint **)(*piVar2 + 0x18) = this_00;
  ScopedCS::~ScopedCS((ScopedCS *)((int)&local_2c + 4));
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_4;
  return true;
}



// private: void __thiscall PRUDPTransport::UnregisterEndPoint(class PRUDPEndPoint *)

void __thiscall PRUDPTransport::UnregisterEndPoint(PRUDPTransport *this,PRUDPEndPoint *pPRUDPEndPoint)

{
  _Node *p_Var1;
  PRUDPInetAddress *this_00;
  PRUDPEndPoint **ppPVar2;
  int unaff_FS_OFFSET;
  _Node *local_1c;
  ScopedCS local_18 [4];
  undefined8 local_14;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L56994;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  ScopedCS::ScopedCS(local_18,(CriticalSection *)&this->field_0x70,s_<unspecified>);
  local_4 = 0;
  this_00 = PRUDPEndPoint::GetPRUDPInetAddress(pPRUDPEndPoint);
  local_14 = PRUDPInetAddress::GetKey(this_00);
  pPRUDPEndPoint = (PRUDPEndPoint *)std::_Tree<>::_Lbound((_Tree<> *)&this->field_0x60,&local_14);
  p_Var1 = *(_Node **)&this->field_0x64;
  if (pPRUDPEndPoint != (PRUDPEndPoint *)p_Var1) {
    if ((*(int *)((_Node *)pPRUDPEndPoint + 0x14) <= local_14._4_4_) &&
       ((*(int *)((_Node *)pPRUDPEndPoint + 0x14) < local_14._4_4_ ||
        (*(uint *)((_Node *)pPRUDPEndPoint + 0x10) <= (uint)local_14)))) {
      ppPVar2 = &pPRUDPEndPoint;
      goto LAB_000048f0;
    }
  }
  local_1c = p_Var1;
  ppPVar2 = (PRUDPEndPoint **)&local_1c;
LAB_000048f0:
  if ((_Node *)*ppPVar2 != p_Var1) {
    std::_Tree<>::erase((_Tree<> *)&this->field_0x60,&pPRUDPEndPoint,(_Node *)*ppPVar2);
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_18);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// private: void __thiscall PRUDPTransport::SendReset(unsigned long,class PRUDPInetAddress *)

void __thiscall
PRUDPTransport::SendReset(PRUDPTransport *this,ulong ulValue,PRUDPInetAddress *pAddress)

{
  PacketOut *this_00;
  Packet *this_01;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L57007;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  this_00 = operator_new(0x50);
  this_01 = (Packet *)0x0;
  local_4 = 0;
  if (this_00 != (PacketOut *)0x0) {
    this_01 = (Packet *)PacketOut::PacketOut(this_00,(PRUDPEndPoint *)0x0,'\x06','\0',(Buffer *)0x0)
    ;
  }
  local_4 = 0xffffffff;
  Packet::SetType(this_01,'\x06');
  Packet::SetPeerAddress(this_01,pAddress);
  Send(this,ulValue,(PacketOut *)this_01);
  RefCountedObject::ReleaseRef((RefCountedObject *)this_01);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// private: class PRUDPEndPoint * __thiscall PRUDPTransport::ServiceConnectionRequest(class
// PRUDPInetAddress *,class Buffer *,unsigned long)

PRUDPEndPoint * __thiscall
PRUDPTransport::ServiceConnectionRequest
          (PRUDPTransport *this,PRUDPInetAddress *pAddress,Buffer *pBuffer,ulong ulValue)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  PRUDPEndPoint *this_00;
  TransportEventHandler *pTVar4;
  ulong uVar5;
  TraceOutput *pTVar6;
  TraceOutput *this_01;
  TraceOutput *this_02;
  TraceOutput *this_03;
  TraceOutput *this_04;
  int iVar7;
  int unaff_FS_OFFSET;
  Buffer *unaff_retaddr;
  char *pcVar8;
  int local_2c;
  int local_28;
  ScopedCS local_24 [4];
  PRUDPEndPoint *local_20;
  undefined8 local_1c;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L57311;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  bVar1 = false;
  ScopedCS::ScopedCS(local_24,(CriticalSection *)&this->field_0x70,s_<unspecified>);
  local_4 = 0;
  local_1c = PRUDPInetAddress::GetKey(pAddress);
  piVar3 = (int *)std::_Tree<>::lower_bound((_Tree<> *)&this->field_0x60,(__int64 *)&local_20);
  local_2c = *piVar3;
  iVar7 = *(int *)&this->field_0x64;
  if (local_2c == iVar7) {
LAB_00004a4e:
    local_28 = iVar7;
    piVar3 = &local_28;
  }
  else {
    if ((local_1c._4_4_ < *(int *)(local_2c + 0x14)) ||
       ((local_1c._4_4_ <= *(int *)(local_2c + 0x14) &&
        ((uint)local_1c < *(uint *)(local_2c + 0x10))))) goto LAB_00004a4e;
    piVar3 = &local_2c;
  }
  if ((*piVar3 == iVar7) ||
     (this_00 = *(PRUDPEndPoint **)(*piVar3 + 0x18), this_00 == (PRUDPEndPoint *)0x0)) {
    local_20 = operator_new(0x60);
    bVar1 = true;
    local_4 = CONCAT31(local_4._1_3_,1);
    if (local_20 == (PRUDPEndPoint *)0x0) {
      this_00 = (PRUDPEndPoint *)0x0;
    }
    else {
      this_00 = (PRUDPEndPoint *)PRUDPEndPoint::PRUDPEndPoint(local_20,(Transport *)this,ulValue);
    }
  }
  local_4 = 0xffffffff;
  ScopedCS::~ScopedCS(local_24);
  if (!bVar1) goto LAB_00004c2d;
  (*___imp__sprintf)(&local_1c,s__s_s,s_prudp,s___);
  StationURL::StationURL((StationURL *)&stack0xffffffcc,(char *)local_24);
  local_c = 2;
  PRUDPInetAddress::GetURL(pAddress,(StationURL *)&stack0xffffffcc);
  PRUDPEndPoint::SetPRUDPInetAddress(this_00,pAddress);
  pTVar4 = Transport::GetEventHandler((Transport *)this);
  if (pTVar4 == (TransportEventHandler *)0x0) {
LAB_00004b83:
    ScopedCS::ScopedCS((ScopedCS *)&local_4,(CriticalSection *)&this->field_0x70,s_<unspecified>);
    local_c._0_1_ = 3;
    RegisterEndPoint(this,this_00);
    local_c = CONCAT31(local_c._1_3_,2);
    ScopedCS::~ScopedCS((ScopedCS *)&local_4);
    StationURL::GetURL((StationURL *)&stack0xffffffcc);
    pcVar8 = (char *)0x6000000;
    pTVar6 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_03,(ulong)pTVar6,pcVar8);
  }
  else {
    uVar5 = Buffer::GetContentSize(unaff_retaddr);
    if (uVar5 == 0) {
      StationURL::GetURL((StationURL *)&stack0xffffffcc);
      pcVar8 = (char *)0x6000000;
      pTVar6 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_02,(ulong)pTVar6,pcVar8);
      pTVar4 = Transport::GetEventHandler((Transport *)this);
      iVar7 = *(int *)pTVar4;
      unaff_retaddr = (Buffer *)0x0;
    }
    else {
      Buffer::GetContentSize(unaff_retaddr);
      StationURL::GetURL((StationURL *)&stack0xffffffcc);
      pcVar8 = (char *)0x6000000;
      pTVar6 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar6,pcVar8);
      pTVar4 = Transport::GetEventHandler((Transport *)this);
      iVar7 = *(int *)pTVar4;
    }
    cVar2 = (**(code **)(iVar7 + 0x10))(this,&local_2c,unaff_retaddr,this_00);
    if (cVar2 != '\0') goto LAB_00004b83;
    StationURL::GetURL((StationURL *)&stack0xffffffcc);
    pcVar8 = (char *)0x6000000;
    pTVar6 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_04,(ulong)pTVar6,pcVar8);
    SendReset(this,ulValue,pAddress);
    if (this_00 != (PRUDPEndPoint *)0x0) {
      PRUDPEndPoint::~PRUDPEndPoint(this_00);
      operator_delete(this_00);
    }
    this_00 = (PRUDPEndPoint *)0x0;
  }
  local_4 = 0xffffffff;
  StationURL::~StationURL((StationURL *)&local_2c);
LAB_00004c2d:
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this_00;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// private: void __thiscall PRUDPTransport::ServiceUserMsg(class PRUDPInetAddress *,class Buffer *)

void __thiscall
PRUDPTransport::ServiceUserMsg(PRUDPTransport *this,PRUDPInetAddress *pAddress,Buffer *pBuffer)

{
  TransportEventHandler *pTVar1;
  ulong uVar2;
  TraceOutput *pTVar3;
  TraceOutput *this_00;
  TraceOutput *this_01;
  int iVar4;
  int unaff_FS_OFFSET;
  char *pcVar5;
  StationURL aSStack_20 [4];
  char local_1c [4];
  undefined1 auStack_18 [12];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  uStack_4 = 0xffffffff;
  puStack_8 = &_L57321;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  pTVar1 = Transport::GetEventHandler((Transport *)this);
  if (pTVar1 != (TransportEventHandler *)0x0) {
    (*___imp__sprintf)(local_1c,s__s_s,s_prudp,s___);
    StationURL::StationURL(aSStack_20,local_1c);
    uStack_4 = 0;
    PRUDPInetAddress::GetURL(pAddress,aSStack_20);
    uVar2 = Buffer::GetContentSize(pBuffer);
    if (uVar2 == 0) {
      StationURL::GetURL(aSStack_20);
      pcVar5 = (char *)0x6000000;
      pTVar3 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_01,(ulong)pTVar3,pcVar5);
      pTVar1 = Transport::GetEventHandler((Transport *)this);
      iVar4 = *(int *)pTVar1;
      pBuffer = (Buffer *)0x0;
    }
    else {
      Buffer::GetContentSize(pBuffer);
      StationURL::GetURL(aSStack_20);
      pcVar5 = (char *)0x6000000;
      pTVar3 = TraceOutput::GetInstance();
      TraceOutput::Trace(this_00,(ulong)pTVar3,pcVar5);
      pTVar1 = Transport::GetEventHandler((Transport *)this);
      iVar4 = *(int *)pTVar1;
    }
    (**(code **)(iVar4 + 4))(this,pBuffer,auStack_18);
    uStack_4 = 0xffffffff;
    StationURL::~StationURL(aSStack_20);
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// private: void __thiscall PRUDPTransport::DemuxIncomingPacket(unsigned long)

void __thiscall PRUDPTransport::DemuxIncomingPacket(PRUDPTransport *this,ulong ulValue)

{
  _Node *p_Var1;
  bool bVar2;
  uchar uVar3;
  PacketIn *this_00;
  PRUDPInetAddress *this_01;
  ulong uVar4;
  TraceOutput *pTVar5;
  PRUDPTransportSettings *this_02;
  PRUDPInetAddress *pPVar6;
  int *piVar7;
  _Node **pp_Var8;
  Buffer *pBVar9;
  PRUDPEndPoint *pPVar10;
  TraceOutput *this_03;
  TraceOutput *this_04;
  TraceOutput *this_05;
  int iVar11;
  __int64 _Var12;
  ulong in_stack_00000014;
  char *pcVar13;
  PRUDPInetAddress *pPVar14;
  _Node *local_8;
  _Node *local_4;
  
  this_00 = UDPSocket::Recv(*(UDPSocket **)(&this->field_0x24 + ulValue * 4));
  if (this_00 == (PacketIn *)0x0) {
    return;
  }
  this_01 = Packet::GetPeerAddress((Packet *)this_00);
  uVar4 = Packet::GetIOResult((Packet *)this_00);
  if (uVar4 != 0) {
    Packet::GetIOResult((Packet *)this_00);
    pcVar13 = (char *)0x0;
    pTVar5 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_03,(ulong)pTVar5,pcVar13);
    this_02 = GetSettings(this);
    bVar2 = PRUDPTransportSettings::IsTrappingICMP(this_02);
    if (bVar2) {
      uVar4 = 0x20;
      pPVar14 = this_01;
      pPVar6 = Socket::GetAddress(*(Socket **)(&this->field_0x24 + ulValue * 4));
      TraceProto(this,s_<_,(Packet *)0x0,pPVar6,pPVar14,uVar4);
      PRUDPInetAddress::GetKey(this_01);
      piVar7 = (int *)std::_Tree<>::find((_Tree<> *)&this->field_0x60,(__int64 *)&stack0x0000000c);
      if ((*piVar7 != *(int *)&this->field_0x64) &&
         (pPVar10 = *(PRUDPEndPoint **)(*piVar7 + 0x18), pPVar10 != (PRUDPEndPoint *)0x0)) {
        uVar4 = Packet::GetIOResult((Packet *)this_00);
        PRUDPEndPoint::SignalFaultEvent(pPVar10,uVar4);
        RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
        return;
      }
      Socket::Close(*(Socket **)(&this->field_0x24 + ulValue * 4));
      RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
      return;
    }
    goto LAB_00004f6b;
  }
  uVar3 = Packet::GetType((Packet *)this_00);
  if (uVar3 == '\0') {
    pBVar9 = Packet::GetPayload((Packet *)this_00);
    pPVar10 = ServiceConnectionRequest(this,this_01,pBVar9,ulValue);
    if (pPVar10 == (PRUDPEndPoint *)0x0) goto LAB_00004f6b;
  }
  else {
    if (uVar3 == '\x04') {
      pBVar9 = Packet::GetPayload((Packet *)this_00);
      ServiceUserMsg(this,this_01,pBVar9);
      RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
      return;
    }
    Packet::GetType((Packet *)this_00);
    pcVar13 = (char *)0x0;
    pTVar5 = TraceOutput::GetInstance();
    TraceOutput::Trace(this_04,(ulong)pTVar5,pcVar13);
    PRUDPInetAddress::Trace(this_01,0);
    _Var12 = PRUDPInetAddress::GetKey(this_01);
    iVar11 = (int)((ulonglong)_Var12 >> 0x20);
    local_8 = std::_Tree<>::_Lbound((_Tree<> *)&this->field_0x60,(__int64 *)&stack0x00000000);
    p_Var1 = *(_Node **)&this->field_0x64;
    if (local_8 == p_Var1) {
LAB_00004edc:
      local_4 = p_Var1;
      pp_Var8 = &local_4;
    }
    else {
      if ((iVar11 < *(int *)(local_8 + 0x14)) ||
         ((iVar11 <= *(int *)(local_8 + 0x14) && ((uint)_Var12 < *(uint *)(local_8 + 0x10)))))
      goto LAB_00004edc;
      pp_Var8 = &local_8;
    }
    if ((*pp_Var8 == p_Var1) ||
       (pPVar10 = *(PRUDPEndPoint **)(*pp_Var8 + 0x18), pPVar10 == (PRUDPEndPoint *)0x0)) {
      uVar3 = Packet::GetType((Packet *)this_00);
      if (uVar3 != '\x06') {
        pcVar13 = (char *)0x0;
        pTVar5 = TraceOutput::GetInstance();
        TraceOutput::Trace(this_05,(ulong)pTVar5,pcVar13);
        SendReset(this,in_stack_00000014,this_01);
        RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
        return;
      }
      goto LAB_00004f6b;
    }
  }
  PRUDPEndPoint::ServiceIncomingPacket(pPVar10,this_00);
LAB_00004f6b:
  RefCountedObject::ReleaseRef((RefCountedObject *)this_00);
  return;
}



// private: void __thiscall PRUDPTransport::CompleteICMP(class ICMPSocket *)

void __thiscall PRUDPTransport::CompleteICMP(PRUDPTransport *this,ICMPSocket *pICMPSocket)

{
  _Node *p_Var1;
  PRUDPEndPoint *this_00;
  ICMPSocket *this_01;
  ulong uVar2;
  ICMPSocket **ppIVar3;
  int unaff_FS_OFFSET;
  PRUDPInetAddress local_1c [4];
  _Node *local_18;
  undefined8 local_14;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L58054;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  PRUDPInetAddress::PRUDPInetAddress(local_1c);
  this_01 = pICMPSocket;
  local_4 = 0;
  uVar2 = ICMPSocket::GetIOCompletionResult(pICMPSocket,local_1c);
  if (uVar2 != 0) goto LAB_0000502a;
  local_14 = PRUDPInetAddress::GetKey(local_1c);
  pICMPSocket = (ICMPSocket *)std::_Tree<>::_Lbound((_Tree<> *)&this->field_0x60,&local_14);
  p_Var1 = *(_Node **)&this->field_0x64;
  if (pICMPSocket == (ICMPSocket *)p_Var1) {
LAB_0000500c:
    local_18 = p_Var1;
    ppIVar3 = (ICMPSocket **)&local_18;
  }
  else {
    if ((local_14._4_4_ < *(int *)((_Node *)pICMPSocket + 0x14)) ||
       ((local_14._4_4_ <= *(int *)((_Node *)pICMPSocket + 0x14) &&
        ((uint)local_14 < *(uint *)((_Node *)pICMPSocket + 0x10))))) goto LAB_0000500c;
    ppIVar3 = &pICMPSocket;
  }
  if (((_Node *)*ppIVar3 != p_Var1) &&
     (this_00 = *(PRUDPEndPoint **)((_Node *)*ppIVar3 + 0x18), this_00 != (PRUDPEndPoint *)0x0)) {
    PRUDPEndPoint::SignalFaultEvent(this_00,3);
  }
LAB_0000502a:
  ICMPSocket::QueueRecv(this_01);
  local_4 = 0xffffffff;
  PRUDPInetAddress::~PRUDPInetAddress(local_1c);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}



// private: bool __thiscall PRUDPTransport::Send(unsigned long,class PacketOut *)

bool __thiscall PRUDPTransport::Send(PRUDPTransport *this,ulong ulValue,PacketOut *pPacketOut)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  
  Platform::SystemCheck(pPacketOut != (PacketOut *)0x0,s_pPacket__NULL,s_PRUDPTransport_cpp,0x363);
  uVar4 = 0x364;
  pcVar3 = s_PRUDPTransport_cpp;
  pcVar2 = s_pPacket_>Valid____true;
  bVar1 = Packet::Valid((Packet *)pPacketOut);
  Platform::SystemCheck(bVar1,pcVar2,pcVar3,uVar4);
  UDPSocket::Queue(*(UDPSocket **)(&this->field_0x24 + ulValue * 4),pPacketOut);
  return true;
}



// private: class TimeoutManager * __thiscall PRUDPTransport::GetTimeoutManager(void)

TimeoutManager * __thiscall PRUDPTransport::GetTimeoutManager(PRUDPTransport *this)

{
  return (TimeoutManager *)&this->field_0x50;
}



// private: void __thiscall PRUDPTransport::TimeSliceHandler(void)

void __thiscall PRUDPTransport::TimeSliceHandler(PRUDPTransport *this)

{
  PRUDPEndPoint *this_00;
  int *piVar1;
  OutputEmulationDevice *pOVar2;
  InputEmulationDevice *pIVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int unaff_FS_OFFSET;
  PRUDPTransport *local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L58312;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  local_10 = this;
  TimeoutManager::ServicePacketTimeouts((TimeoutManager *)&this->field_0x50);
  bVar5 = 0;
  local_10 = (PRUDPTransport *)((uint)local_10 & 0xffffff00);
  if (this->field_0x18 != '\0') {
    do {
      uVar6 = (uint)local_10 & 0xff;
      if (*(UDPSocket **)(&this->field_0x24 + uVar6 * 4) != (UDPSocket *)0x0) {
        UDPSocket::TryIOCompletion(*(UDPSocket **)(&this->field_0x24 + uVar6 * 4));
      }
      if (this != (PRUDPTransport *)0xffffffc4) {
        ICMPSocket::TryIOCompletion(*(ICMPSocket **)(&this->field_0x3c + uVar6 * 4));
      }
      bVar5 = bVar5 + 1;
      local_10 = (PRUDPTransport *)CONCAT31(local_10._1_3_,bVar5);
    } while (bVar5 < (byte)this->field_0x18);
  }
  pOVar2 = Transport::GetOutputEmulationDevice((Transport *)this);
  if (pOVar2[0x20] != (OutputEmulationDevice)0x0) {
    pOVar2 = Transport::GetOutputEmulationDevice((Transport *)this);
    (**(code **)(*(int *)pOVar2 + 4))();
  }
  pIVar3 = Transport::GetInputEmulationDevice((Transport *)this);
  if (pIVar3[0x20] != (InputEmulationDevice)0x0) {
    pIVar3 = Transport::GetInputEmulationDevice((Transport *)this);
    (**(code **)(*(int *)pIVar3 + 4))();
  }
  ScopedCS::ScopedCS((ScopedCS *)&local_10,(CriticalSection *)&this->field_0x90,s_<unspecified>);
  iVar4 = *(int *)&this->field_0x8c;
  uStack_4 = 0;
  while (iVar4 != 0) {
    this_00 = *(PRUDPEndPoint **)(**(int **)&this->field_0x88 + 8);
    if (this_00 != (PRUDPEndPoint *)0x0) {
      PRUDPEndPoint::~PRUDPEndPoint(this_00);
      operator_delete(this_00);
    }
    piVar1 = (int *)**(undefined4 **)&this->field_0x88;
    *(int *)piVar1[1] = *piVar1;
    *(int *)(*piVar1 + 4) = piVar1[1];
    operator_delete(piVar1);
    iVar4 = *(int *)&this->field_0x8c + -1;
    *(int *)&this->field_0x8c = iVar4;
  }
  uStack_4 = 0xffffffff;
  ScopedCS::~ScopedCS((ScopedCS *)&local_10);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// private: class UDPSocket * __thiscall PRUDPTransport::GetSocket(unsigned char)

UDPSocket * __thiscall PRUDPTransport::GetSocket(PRUDPTransport *this,uchar value)

{
  return *(UDPSocket **)(&this->field_0x24 + (uint)value * 4);
}



// private: unsigned short __thiscall PRUDPTransport::GetPortNumber(unsigned long)

ushort __thiscall PRUDPTransport::GetPortNumber(PRUDPTransport *this,ulong ulValue)

{
  ushort uVar1;
  
  if (*(Socket **)(&this->field_0x24 + ulValue * 4) != (Socket *)0x0) {
    uVar1 = Socket::GetBoundPort(*(Socket **)(&this->field_0x24 + ulValue * 4));
    return uVar1;
  }
  return 0;
}



// private: class PRUDPTransportSettings * __thiscall PRUDPTransport::GetSettings(void)

PRUDPTransportSettings * __thiscall PRUDPTransport::GetSettings(PRUDPTransport *this)

{
  return &this->m_oTransportSettings;
}



// public: void __thiscall PRUDPTransport::TraceProto(char *,class Packet *,class PRUDPInetAddress
// *,class PRUDPInetAddress *,unsigned long)

void __thiscall
PRUDPTransport::TraceProto
          (PRUDPTransport *this,char *szText,Packet *pPacket,PRUDPInetAddress *pAddress,
          PRUDPInetAddress *pAddress2,ulong ulValue)

{
  return;
}



// unsigned long __cdecl HandleTimeSliceWrap(unsigned long,unsigned long)

ulong __cdecl HandleTimeSliceWrap(ulong ulValue,ulong ulValue2)

{
  PRUDPTransport::TimeSliceHandler((PRUDPTransport *)ulValue);
  return 0;
}



// unsigned long __cdecl HandleRecvCompletedWrap(unsigned long,unsigned long)

ulong __cdecl HandleRecvCompletedWrap(ulong ulValue,ulong ulValue2)

{
  UDPSocket::CompleteRecv(*(UDPSocket **)(ulValue + 0x24 + ulValue2 * 4));
  PRUDPTransport::DemuxIncomingPacket((PRUDPTransport *)ulValue,ulValue2 & 0xff);
  return 0;
}



// unsigned long __cdecl HandleSendCompletedWrap(unsigned long,unsigned long)

ulong __cdecl HandleSendCompletedWrap(ulong ulValue,ulong ulValue2)

{
  UDPSocket::CompleteSend(*(UDPSocket **)(ulValue + 0x24 + ulValue2 * 4));
  return 0;
}



// unsigned long __cdecl HandleICMPCompletedWrap(unsigned long,unsigned long)

ulong __cdecl HandleICMPCompletedWrap(ulong ulValue,ulong ulValue2)

{
  PRUDPTransport::CompleteICMP((PRUDPTransport *)ulValue,(ICMPSocket *)ulValue2);
  return 0;
}



// public: __thiscall std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *>
// >::~list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >(void)

void __thiscall std::list<>::~list<>(list<> *this)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = *(int **)(this + 4);
  piVar3 = (int *)*piVar1;
  while (piVar3 != piVar1) {
    piVar2 = (int *)*piVar3;
    *(int *)piVar3[1] = *piVar3;
    *(int *)(*piVar3 + 4) = piVar3[1];
    operator_delete(piVar3);
    *(int *)(this + 8) = *(int *)(this + 8) + -1;
    piVar3 = piVar2;
  }
  operator_delete(*(void **)(this + 4));
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::erase(class std::_Tree<__int64,struct std::pair<__int64
// const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator)

undefined4 * __thiscall std::_Tree<>::erase(_Tree<> *this,undefined4 *pUndefined4,_Node *p_node)

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
  
  p_Var7 = p_node;
  uStack_4 = 0xffffffff;
  puStack_8 = &_L59800;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  const_iterator::_Inc((const_iterator *)&p_node);
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
        iVar3 = *(int *)(p_Var1 + 0x20);
        *(int *)(p_Var1 + 0x20) = *(int *)(p_Var7 + 0x20);
        *(int *)(p_Var7 + 0x20) = iVar3;
        goto LAB_000054eb;
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
LAB_000054eb:
  if (*(int *)(local_1c + 0x20) == 1) {
    if (p_Var10 != *(_Node **)(*(int *)(this + 4) + 4)) {
      do {
        if (*(int *)(p_Var10 + 0x20) != 1) break;
        piVar11 = *(int **)(p_Var10 + 4);
        if (p_Var10 == (_Node *)*piVar11) {
          piVar11 = (int *)piVar11[2];
          if (piVar11[8] == 0) {
            piVar11[8] = 1;
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x20) = 0;
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
          if ((*(int *)(*piVar11 + 0x20) != 1) || (*(int *)(piVar11[2] + 0x20) != 1)) {
            if (*(int *)(piVar11[2] + 0x20) == 1) {
              *(undefined4 *)(*piVar11 + 0x20) = 1;
              piVar11[8] = 0;
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
            piVar11[8] = *(int *)(*(int *)(p_Var10 + 4) + 0x20);
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x20) = 1;
            *(undefined4 *)(piVar11[2] + 0x20) = 1;
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
LAB_00005804:
            (*___imp___1_Lockit_std__QAE_XZ)();
            break;
          }
        }
        else {
          piVar11 = (int *)*piVar11;
          if (piVar11[8] == 0) {
            piVar11[8] = 1;
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x20) = 0;
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
          if ((*(int *)(piVar11[2] + 0x20) != 1) || (*(int *)(*piVar11 + 0x20) != 1)) {
            if (*(int *)(*piVar11 + 0x20) == 1) {
              *(undefined4 *)(piVar11[2] + 0x20) = 1;
              piVar11[8] = 0;
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
            piVar11[8] = *(int *)(*(int *)(p_Var10 + 4) + 0x20);
            *(undefined4 *)(*(int *)(p_Var10 + 4) + 0x20) = 1;
            *(undefined4 *)(*piVar11 + 0x20) = 1;
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
            goto LAB_00005804;
          }
        }
        piVar11[8] = 0;
        p_Var10 = *(_Node **)(p_Var10 + 4);
      } while (p_Var10 != *(_Node **)(*(int *)(this + 4) + 4));
    }
    *(undefined4 *)(p_Var10 + 0x20) = 1;
  }
  operator_delete(local_1c);
  uStack_4 = 0xffffffff;
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + -1;
  *pUndefined4 = p_node;
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return pUndefined4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::erase(class std::_Tree<__int64,struct std::pair<__int64
// const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator,class
// std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::iterator)

undefined4 * __thiscall
std::_Tree<>::erase(_Tree<> *this,undefined4 *pUndefined4,int *piValue,int *piValue2)

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
  
  piVar4 = piValue2;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  iStack_4 = 0xffffffff;
  puStack_8 = &_L60019;
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  pcVar3 = ___imp___0_Lockit_std__QAE_XZ;
  piVar2 = piValue;
  if (((*(int *)(this + 0xc) == 0) || (piValue != (int *)**(int **)(this + 4))) ||
     (piValue2 != *(int **)(this + 4))) {
    while (piVar2 != piVar4) {
      piValue = piVar2;
      const_iterator::_Inc((const_iterator *)&piValue);
      erase(this,local_10,piVar2);
      piVar2 = piValue;
    }
    *pUndefined4 = piVar2;
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
    *pUndefined4 = **(undefined4 **)(this + 4);
    (*pcVar3)();
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return pUndefined4;
}



// public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::find(__int64 const &)

void __thiscall std::_Tree<>::find(_Tree<> *this,__int64 *p__int64)

{
  _Node *p_Var1;
  uint *in_stack_00000008;
  
  p_Var1 = _Lbound(this,(__int64 *)in_stack_00000008);
  if (p_Var1 != *(_Node **)(this + 4)) {
    if ((*(int *)(p_Var1 + 0x14) <= (int)in_stack_00000008[1]) &&
       ((*(int *)(p_Var1 + 0x14) < (int)in_stack_00000008[1] ||
        (*(uint *)(p_Var1 + 0x10) <= *in_stack_00000008)))) {
      *(_Node **)p__int64 = p_Var1;
      return;
    }
  }
  *(_Node **)p__int64 = *(_Node **)(this + 4);
  return;
}



// public: class std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint
// *> >::erase(class std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *>
// >::iterator)

void __thiscall std::list<>::erase(list<> *this,int *piValue,int *piValue2)

{
  int iVar1;
  
  iVar1 = *piValue2;
  *(int *)piValue2[1] = *piValue2;
  *(int *)(*piValue2 + 4) = piValue2[1];
  operator_delete(piValue2);
  *(int *)(this + 8) = *(int *)(this + 8) + -1;
  *piValue = iVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: struct std::pair<class std::_Tree<__int64,struct std::pair<__int64 const ,class
// PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::iterator,bool> __thiscall std::_Tree<__int64,struct
// std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint
// *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::insert(struct std::pair<__int64
// const ,class PRUDPEndPoint *> const &)

void __thiscall std::_Tree<>::insert(_Tree<> *this,pair<> *pPair<>)

{
  bool bVar1;
  undefined4 *puVar2;
  _Node *p_Var3;
  pair<> *ppVar4;
  uint *in_stack_00000008;
  pair<> *appStack_c [2];
  uint uStack_4;
  
  ppVar4 = *(pair<> **)(this + 4);
  bVar1 = true;
  p_Var3 = *(_Node **)(ppVar4 + 4);
  (*___imp___0_Lockit_std__QAE_XZ)();
  if (p_Var3 != _Nil) {
    do {
      ppVar4 = (pair<> *)p_Var3;
      if ((*(int *)((_Node *)ppVar4 + 0x14) < (int)in_stack_00000008[1]) ||
         ((*(int *)((_Node *)ppVar4 + 0x14) <= (int)in_stack_00000008[1] &&
          (*(uint *)((_Node *)ppVar4 + 0x10) <= *in_stack_00000008)))) {
        p_Var3 = *(_Node **)((_Node *)ppVar4 + 8);
        bVar1 = false;
      }
      else {
        p_Var3 = *(_Node **)ppVar4;
        bVar1 = true;
      }
    } while (p_Var3 != _Nil);
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  if (this[8] != (_Tree<>)0x0) {
    puVar2 = (undefined4 *)_Insert(this,(_Node *)&stack0x00000008,p_Var3,ppVar4);
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    *(undefined4 *)pPair<> = *puVar2;
    *(uint *)(pPair<> + 4) = uStack_4;
    return;
  }
  appStack_c[0] = ppVar4;
  if (bVar1) {
    if (ppVar4 == (pair<> *)**(int **)(this + 4)) {
      puVar2 = (undefined4 *)_Insert(this,(_Node *)&stack0x00000008,p_Var3,ppVar4);
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      *(undefined4 *)pPair<> = *puVar2;
      *(uint *)(pPair<> + 4) = uStack_4;
      return;
    }
    const_iterator::_Dec((const_iterator *)appStack_c);
  }
  if ((*(int *)(appStack_c[0] + 0x14) <= (int)in_stack_00000008[1]) &&
     ((*(int *)(appStack_c[0] + 0x14) < (int)in_stack_00000008[1] ||
      (*(uint *)(appStack_c[0] + 0x10) < *in_stack_00000008)))) {
    puVar2 = (undefined4 *)_Insert(this,(_Node *)&stack0x00000008,p_Var3,ppVar4);
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    *(undefined4 *)pPair<> = *puVar2;
    *(uint *)(pPair<> + 4) = uStack_4;
    return;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  *(pair<> **)pPair<> = appStack_c[0];
  *(uint *)(pPair<> + 4) = uStack_4;
  return;
}



// public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::lower_bound(__int64 const &)

__int64 * __thiscall std::_Tree<>::lower_bound(_Tree<> *this,__int64 *p__int64)

{
  _Node *p_Var1;
  __int64 *in_stack_00000008;
  
  p_Var1 = _Lbound(this,in_stack_00000008);
  *(_Node **)p__int64 = p_Var1;
  return p__int64;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: void __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Erase(struct std::_Tree<__int64,struct
// std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint
// *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Node *)

void __thiscall std::_Tree<>::_Erase(_Tree<> *this,_Node *p_node)

{
  _Node *p_Var1;
  int unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &_L60376;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  (*___imp___0_Lockit_std__QAE_XZ)();
  uStack_4 = 0;
  if (p_node != _Nil) {
    do {
      _Erase(this,*(_Node **)(p_node + 8));
      p_Var1 = *(_Node **)p_node;
      operator_delete(p_node);
      p_node = p_Var1;
    } while (p_Var1 != _Nil);
  }
  uStack_4 = 0xffffffff;
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::const_iterator::_Inc(void)

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
  puStack_8 = &_L60424;
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



// public: class std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint
// *> >::iterator::operator++(int)

void __thiscall std::list<>::iterator::operator++(iterator *this,int iValue)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)this;
  *(undefined4 *)this = *puVar1;
  *(undefined4 **)iValue = puVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Insert(struct std::_Tree<__int64,struct
// std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint
// *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Node *,struct
// std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct
// std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class
// PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *>
// >::_Node *,struct std::pair<__int64 const ,class PRUDPEndPoint *> const &)

_Node * __thiscall
std::_Tree<>::_Insert(_Tree<> *this,_Node *p_node,_Node *p_node2,pair<> *pPair<>)

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
  puStack_8 = &_L61221;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  (*___imp___0_Lockit_std__QAE_XZ)();
  uStack_4 = 0;
  piVar5 = operator_new(0x28);
  piVar5[1] = (int)pPair<>;
  piVar5[8] = 0;
  *piVar5 = (int)_Nil;
  piVar5[2] = (int)_Nil;
  _Construct((pair<> *)(piVar5 + 4),in_stack_00000010);
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
  if ((pPair<> != *(pair<> **)(this + 4)) && (p_node2 == _Nil)) {
    if ((*(int *)(pPair<> + 0x14) <= *(int *)(in_stack_00000010 + 4)) &&
       ((*(int *)(pPair<> + 0x14) < *(int *)(in_stack_00000010 + 4) ||
        (*(uint *)(pPair<> + 0x10) <= *(uint *)in_stack_00000010)))) {
      *(int **)(pPair<> + 8) = piVar5;
      if (pPair<> == *(pair<> **)(*(int *)(this + 4) + 8)) {
        *(int **)(*(int *)(this + 4) + 8) = piVar5;
      }
      goto LAB_00005d8e;
    }
  }
  *(int **)pPair<> = piVar5;
  ppVar1 = *(pair<> **)(this + 4);
  if (pPair<> == ppVar1) {
    *(int **)(ppVar1 + 4) = piVar5;
    *(int **)(*(int *)(this + 4) + 8) = piVar5;
  }
  else if (pPair<> == *(pair<> **)ppVar1) {
    *(int **)ppVar1 = piVar5;
  }
LAB_00005d8e:
  piVar6 = piVar5;
  if (piVar5 != *(int **)(*(int *)(this + 4) + 4)) {
    do {
      piVar2 = (int *)piVar6[1];
      if (piVar2[8] != 0) break;
      piVar3 = (int *)piVar2[1];
      if (piVar2 == (int *)*piVar3) {
        iVar4 = piVar3[2];
        if (*(int *)(iVar4 + 0x20) == 0) {
          piVar2[8] = 1;
          *(undefined4 *)(iVar4 + 0x20) = 1;
          *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
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
          *(undefined4 *)(piVar6[1] + 0x20) = 1;
          *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
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
LAB_00005f94:
          (*___imp___1_Lockit_std__QAE_XZ)();
        }
      }
      else {
        iVar4 = *piVar3;
        if (*(int *)(iVar4 + 0x20) != 0) {
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
          *(undefined4 *)(piVar6[1] + 0x20) = 1;
          *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
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
          goto LAB_00005f94;
        }
        piVar2[8] = 1;
        *(undefined4 *)(iVar4 + 0x20) = 1;
        *(undefined4 *)(*(int *)(piVar6[1] + 4) + 0x20) = 0;
        piVar6 = *(int **)(piVar6[1] + 4);
      }
    } while (piVar6 != *(int **)(*(int *)(this + 4) + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(*(int *)(this + 4) + 4) + 0x20) = 1;
  *(int **)p_node = piVar5;
  (*___imp___1_Lockit_std__QAE_XZ)();
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = uStack_c;
  return p_node;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// protected: struct std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Node * __thiscall std::_Tree<__int64,struct
// std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint
// *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct
// std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Lbound(__int64 const &)const 

_Node * __thiscall std::_Tree<>::_Lbound(_Tree<> *this,__int64 *p__int64)

{
  _Node *p_Var1;
  _Node *p_Var2;
  _Node *p_Var3;
  
  (*___imp___0_Lockit_std__QAE_XZ)();
  p_Var3 = *(_Node **)(this + 4);
  if (*(_Node **)(p_Var3 + 4) != _Nil) {
    p_Var1 = *(_Node **)(p_Var3 + 4);
    do {
      if ((*(int *)((int)p__int64 + 4) < *(int *)(p_Var1 + 0x14)) ||
         ((*(int *)((int)p__int64 + 4) <= *(int *)(p_Var1 + 0x14) &&
          ((uint)*p__int64 <= *(uint *)(p_Var1 + 0x10))))) {
        p_Var2 = *(_Node **)p_Var1;
        p_Var3 = p_Var1;
      }
      else {
        p_Var2 = *(_Node **)(p_Var1 + 8);
      }
      p_Var1 = p_Var2;
    } while (p_Var2 != _Nil);
  }
  (*___imp___1_Lockit_std__QAE_XZ)();
  return p_Var3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// public: void __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint
// *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class
// std::allocator<class PRUDPEndPoint *> >::const_iterator::_Dec(void)

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
  puStack_8 = &_L61324;
  uStack_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &uStack_c;
  pcVar4 = ___imp___0_Lockit_std__QAE_XZ;
  (*___imp___0_Lockit_std__QAE_XZ)();
  pcVar3 = ___imp___1_Lockit_std__QAE_XZ;
  piVar5 = *(int **)this;
  uStack_4 = 0;
  if ((piVar5[8] == 0) && (*(int **)(piVar5[1] + 4) == piVar5)) {
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



// void __cdecl std::_Construct(struct std::pair<__int64 const ,class PRUDPEndPoint *> *,struct
// std::pair<__int64 const ,class PRUDPEndPoint *> const &)

void __cdecl std::_Construct(pair<> *pPair<>,pair<> *pPair<>2)

{
  if (pPair<> != (pair<> *)0x0) {
    *(undefined4 *)pPair<> = *(undefined4 *)pPair<>2;
    *(undefined4 *)(pPair<> + 4) = *(undefined4 *)(pPair<>2 + 4);
    *(undefined4 *)(pPair<> + 8) = *(undefined4 *)(pPair<>2 + 8);
    *(undefined4 *)(pPair<> + 0xc) = *(undefined4 *)(pPair<>2 + 0xc);
  }
  return;
}


