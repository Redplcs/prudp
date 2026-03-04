#include <stdbool.h>

typedef unsigned char   undefined;

typedef unsigned int    undefined4;
typedef struct PRUDPDeviceData PRUDPDeviceData, *PPRUDPDeviceData;

struct PRUDPDeviceData { // PlaceHolder Structure
};

typedef struct Packet Packet, *PPacket;

struct Packet { // PlaceHolder Structure
};

typedef struct RefCountedObject RefCountedObject, *PRefCountedObject;

struct RefCountedObject { // PlaceHolder Structure
};

typedef struct UDPSocket UDPSocket, *PUDPSocket;

struct UDPSocket { // PlaceHolder Structure
};

typedef struct DeviceData DeviceData, *PDeviceData;

struct DeviceData { // PlaceHolder Structure
};



undefined LAB_00002508;
undefined __except_list;
pointer `vftable';
undefined LAB_00002528;

// public: __thiscall PRUDPDeviceData::PRUDPDeviceData(class Packet *,class UDPSocket *,bool
// (__cdecl*)(class DeviceData *))

PRUDPDeviceData * __thiscall
PRUDPDeviceData::PRUDPDeviceData
          (PRUDPDeviceData *this,Packet *param_1,UDPSocket *param_2,
          _func_bool_DeviceData_ptr *param_3)

{
  unsigned short uVar1;
  RefCountedObject *pRVar2;
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &_L1335;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  uVar1 = Packet::GetSize(param_1);
  DeviceData::DeviceData((DeviceData *)this,(unsigned int)uVar1,param_3);
  local_4 = 0;
  *(undefined ***)this = &_vftable_;
  pRVar2 = RefCountedObject::AcquireRef((RefCountedObject *)param_1);
  *(RefCountedObject **)(this + 0x14) = pRVar2;
  *(UDPSocket **)(this + 0x18) = param_2;
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return this;
}



// public: virtual void * __thiscall PRUDPDeviceData::`scalar deleting destructor'(unsigned int)

void * __thiscall PRUDPDeviceData::_scalar_deleting_destructor_(PRUDPDeviceData *this,unsigned int param_1)

{
  ~PRUDPDeviceData(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// public: virtual __thiscall PRUDPDeviceData::~PRUDPDeviceData(void)

void __thiscall PRUDPDeviceData::~PRUDPDeviceData(PRUDPDeviceData *this)

{
  int unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &_L1349;
  local_c = *(undefined4 *)(&__except_list + unaff_FS_OFFSET);
  *(undefined4 **)(&__except_list + unaff_FS_OFFSET) = &local_c;
  *(undefined ***)this = &_vftable_;
  local_4 = 0;
  RefCountedObject::ReleaseRef(*(RefCountedObject **)(this + 0x14));
  local_4 = 0xffffffff;
  DeviceData::~DeviceData((DeviceData *)this);
  *(undefined4 *)(&__except_list + unaff_FS_OFFSET) = local_c;
  return;
}


