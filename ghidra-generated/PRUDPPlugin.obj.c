#include <Platform/Trace.h>
#include <Plugins/Core/Plugin.h>
#include <Plugins/Core/PluginObject.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/TransportPlugin.h>
#include <Plugins/Transport/PRUDP/PRUDPPlugin.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
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

typedef struct PRUDPTransport PRUDPTransport, *PPRUDPTransport;

struct PRUDPTransport { // PlaceHolder Structure
};

typedef struct TraceOutput TraceOutput, *PTraceOutput;

typedef struct StationURL StationURL, *PStationURL;

typedef struct PluginObject PluginObject, *PPluginObject;

typedef struct TransportPlugin TransportPlugin, *PTransportPlugin;

typedef struct PRUDPPlugin PRUDPPlugin, *PPRUDPPlugin;

typedef struct Plugin Plugin, *PPlugin;



PRUDPPlugin s_oPlugin;
undefined LAB_00002730;
pointer `vftable';
TerminatedCString s_6A718E55-82A7-4c0c-A65B-38230C45;
TerminatedCString s_Quazal;
TerminatedCString s_Proksim_Reliable_UDP_Transport_P;
undefined s_prudp;
undefined LAB_00002b0b;
undefined __except_list;

// $E11

void __cdecl _E11(void)

{
  PRUDPPlugin::PRUDPPlugin(&PRUDPPlugin::s_oPlugin);
  return;
}



// $E14

void __cdecl _E14(void)

{
  _atexit((__func *)&__E12);
  return;
}



// public: __thiscall PRUDPPlugin::PRUDPPlugin(void)

PRUDPPlugin * __thiscall PRUDPPlugin::PRUDPPlugin(PRUDPPlugin *this)

{
  Plugin::Plugin((Plugin *)this);
  *(undefined ***)this = &_vftable_;
  return this;
}



// public: virtual unsigned long __thiscall TransportPlugin::GetInterfaceVersion(void)

ulong __thiscall TransportPlugin::GetInterfaceVersion(TransportPlugin *this)

{
  ulong uVar1;
  
  uVar1 = PluginManager::GetTransportInterfaceVersion();
  return uVar1;
}



// public: virtual unsigned long __thiscall TransportPlugin::GetType(void)

ulong __thiscall TransportPlugin::GetType(TransportPlugin *this)

{
  return 1;
}



// public: virtual void * __thiscall PRUDPPlugin::`scalar deleting destructor'(unsigned int)

void * __thiscall PRUDPPlugin::_scalar_deleting_destructor_(PRUDPPlugin *this,uint param_1)

{
  ~PRUDPPlugin(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// public: virtual __thiscall PRUDPPlugin::~PRUDPPlugin(void)

void __thiscall PRUDPPlugin::~PRUDPPlugin(PRUDPPlugin *this)

{
  *(undefined ***)this = &_vftable_;
  Plugin::~Plugin((Plugin *)this);
  return;
}



// public: virtual bool __thiscall PRUDPPlugin::Activate(void)

bool __thiscall PRUDPPlugin::Activate(PRUDPPlugin *this)

{
  return true;
}



// public: virtual void __thiscall PRUDPPlugin::Release(void)

void __thiscall PRUDPPlugin::Release(PRUDPPlugin *this)

{
  return;
}



// public: virtual char * __thiscall PRUDPPlugin::GetGUID(void)

char * __thiscall PRUDPPlugin::GetGUID(PRUDPPlugin *this)

{
  return s_6A718E55_82A7_4c0c_A65B_38230C45;
}



// public: virtual char * __thiscall PRUDPPlugin::GetAuthor(void)

char * __thiscall PRUDPPlugin::GetAuthor(PRUDPPlugin *this)

{
  return s_Quazal;
}



// public: virtual char * __thiscall PRUDPPlugin::GetName(void)

char * __thiscall PRUDPPlugin::GetName(PRUDPPlugin *this)

{
  return s_Proksim_Reliable_UDP_Transport_P;
}



// public: virtual unsigned long __thiscall PRUDPPlugin::GetVersion(void)

ulong __thiscall PRUDPPlugin::GetVersion(PRUDPPlugin *this)

{
  return 1;
}



// public: virtual bool __thiscall PRUDPPlugin::IsCertified(void)

bool __thiscall PRUDPPlugin::IsCertified(PRUDPPlugin *this)

{
  return true;
}



// public: virtual bool __thiscall PRUDPPlugin::ResponsibleForURL(class StationURL *)

bool __thiscall PRUDPPlugin::ResponsibleForURL(PRUDPPlugin *this,StationURL *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  byte local_80 [128];
  
  StationURL::GetTransportType(param_1,(char *)local_80,0x80);
  pbVar3 = &s_prudp;
  pbVar2 = local_80;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar4 == (uint)(bVar4 != 0);
}



// public: virtual class PluginObject * __thiscall PRUDPPlugin::CreatePluginObject(void)

PluginObject * __thiscall PRUDPPlugin::CreatePluginObject(PRUDPPlugin *this)

{
  PRUDPTransport *this_00;
  PluginObject *pPVar1;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L10979;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  this_00 = operator_new(0xb8);
  local_4 = 0;
  if (this_00 != (PRUDPTransport *)0x0) {
    pPVar1 = (PluginObject *)PRUDPTransport::PRUDPTransport(this_00,(Plugin *)this);
    *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
    return pPVar1;
  }
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return (PluginObject *)0x0;
}



// public: virtual void __thiscall PRUDPPlugin::DeletePluginObject(class PluginObject *)

void __thiscall PRUDPPlugin::DeletePluginObject(PRUDPPlugin *this,PluginObject *param_1)

{
  if (param_1 != (PluginObject *)0x0) {
    (*(code *)**(undefined4 **)param_1)(1);
  }
  return;
}



// public: virtual void __thiscall PRUDPPlugin::SetTraceOutput(class TraceOutput *)

void __thiscall PRUDPPlugin::SetTraceOutput(PRUDPPlugin *this,TraceOutput *param_1)

{
  TraceOutput *pTVar1;
  
  pTVar1 = TraceOutput::GetInstance();
  if (param_1 != pTVar1) {
    TraceOutput::SetTheTraceOutput(param_1);
  }
  return;
}



// public: static class PRUDPPlugin * __cdecl PRUDPPlugin::GetInstance(void)

PRUDPPlugin * __cdecl PRUDPPlugin::GetInstance(void)

{
  return &s_oPlugin;
}


