#include <stdbool.h>

typedef unsigned char   undefined;

typedef unsigned int    undefined4;
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

typedef struct UserContext UserContext, *PUserContext;

struct UserContext { // PlaceHolder Structure
};



undefined DAT_0000238f;

// public: __thiscall PRUDPTransportSettings::PRUDPTransportSettings(void)

PRUDPTransportSettings * __thiscall
PRUDPTransportSettings::PRUDPTransportSettings(PRUDPTransportSettings *this)

{
  SetDefaults(this);
  return this;
}



// public: void __thiscall PRUDPTransportSettings::SetDefaults(void)

void __thiscall PRUDPTransportSettings::SetDefaults(PRUDPTransportSettings *this)

{
  this->field0_0x0 = &DAT_0000238f;
  this->field1_0x4 = 0x14;
  this->field_0x8 = 1;
  this->field7_0x10 = 5000;
  this->field6_0xc = 1000;
  this->field9_0x18 = 10;
  this->field10_0x1c = 8;
  this->field8_0x14 = 4000;
  return;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetWindowSize(unsigned long)

unsigned long __thiscall PRUDPTransportSettings::SetWindowSize(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field10_0x1c = param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetWindowSize(void)

unsigned long __thiscall PRUDPTransportSettings::GetWindowSize(PRUDPTransportSettings *this)

{
  return this->field10_0x1c;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetWellKnownPortNumber(unsigned long)

unsigned long __thiscall
PRUDPTransportSettings::SetWellKnownPortNumber(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field0_0x0 = (undefined *)param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetWellKnownPortNumber(void)

unsigned long __thiscall PRUDPTransportSettings::GetWellKnownPortNumber(PRUDPTransportSettings *this)

{
  return (unsigned long)this->field0_0x0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetMTU(unsigned long)

unsigned long __thiscall PRUDPTransportSettings::SetMTU(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field8_0x14 = param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetMTU(void)

unsigned long __thiscall PRUDPTransportSettings::GetMTU(PRUDPTransportSettings *this)

{
  return this->field8_0x14;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetMaxRetransmission(unsigned long)

unsigned long __thiscall
PRUDPTransportSettings::SetMaxRetransmission(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field1_0x4 = param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetMaxRetransmission(void)

unsigned long __thiscall PRUDPTransportSettings::GetMaxRetransmission(PRUDPTransportSettings *this)

{
  return this->field1_0x4;
}



// public: unsigned long __thiscall PRUDPTransportSettings::TrapICMP(bool)

unsigned long __thiscall PRUDPTransportSettings::TrapICMP(PRUDPTransportSettings *this,bool param_1)

{
  this->field_0x8 = param_1;
  return 0;
}



// public: bool __thiscall PRUDPTransportSettings::IsTrappingICMP(void)

bool __thiscall PRUDPTransportSettings::IsTrappingICMP(PRUDPTransportSettings *this)

{
  return (bool)this->field_0x8;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetKeepAliveTimeout(unsigned long)

unsigned long __thiscall
PRUDPTransportSettings::SetKeepAliveTimeout(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field6_0xc = param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetKeepAliveTimeout(void)

unsigned long __thiscall PRUDPTransportSettings::GetKeepAliveTimeout(PRUDPTransportSettings *this)

{
  return this->field6_0xc;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetMaxSilenceTime(unsigned long)

unsigned long __thiscall
PRUDPTransportSettings::SetMaxSilenceTime(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field7_0x10 = param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetMaxSilenceTime(void)

unsigned long __thiscall PRUDPTransportSettings::GetMaxSilenceTime(PRUDPTransportSettings *this)

{
  return this->field7_0x10;
}



// public: bool __thiscall PRUDPTransportSettings::IsBroadcastingEverywhere(void)

bool __thiscall PRUDPTransportSettings::IsBroadcastingEverywhere(PRUDPTransportSettings *this)

{
  return (bool)*(undefined1 *)&this[1].field0_0x0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::BroadcastEverywhere(bool)

unsigned long __thiscall
PRUDPTransportSettings::BroadcastEverywhere(PRUDPTransportSettings *this,bool param_1)

{
  *(undefined1 *)&this[1].field0_0x0 = 1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetTimeSlice(void)

unsigned long __thiscall PRUDPTransportSettings::GetTimeSlice(PRUDPTransportSettings *this)

{
  return this->field9_0x18;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetTimeSlice(unsigned long)

unsigned long __thiscall PRUDPTransportSettings::SetTimeSlice(PRUDPTransportSettings *this,unsigned long param_1)

{
  this->field9_0x18 = param_1;
  return 0;
}



// public: unsigned long __thiscall PRUDPTransportSettings::SetOption(unsigned long,class
// UserContext &)

unsigned long __thiscall
PRUDPTransportSettings::SetOption
          (PRUDPTransportSettings *this,unsigned long ulOption,UserContext *oOptionSetting)

{
  unsigned long uVar1;
  
  if (ulOption < 0x103) {
    if (ulOption == 0x102) {
      uVar1 = TrapICMP(this,(bool)*oOptionSetting);
      return uVar1;
    }
    if (ulOption < 0x101) {
      if (ulOption == 0x100) {
        uVar1 = BroadcastEverywhere(this,(bool)*oOptionSetting);
        return uVar1;
      }
      if (ulOption == 1) {
        uVar1 = SetMTU(this,*(unsigned long *)oOptionSetting);
        return uVar1;
      }
      if (ulOption == 2) {
        uVar1 = SetWellKnownPortNumber(this,*(unsigned long *)oOptionSetting);
        return uVar1;
      }
    }
    else if (ulOption == 0x101) {
      uVar1 = SetMaxRetransmission(this,*(unsigned long *)oOptionSetting);
      return uVar1;
    }
  }
  else {
    switch(ulOption) {
    case 0x103:
      uVar1 = SetMaxSilenceTime(this,*(unsigned long *)oOptionSetting);
      return uVar1;
    case 0x104:
      uVar1 = SetKeepAliveTimeout(this,*(unsigned long *)oOptionSetting);
      return uVar1;
    case 0x105:
      uVar1 = SetTimeSlice(this,*(unsigned long *)oOptionSetting);
      return uVar1;
    case 0x106:
      uVar1 = SetWindowSize(this,*(unsigned long *)oOptionSetting);
      return uVar1;
    }
  }
  return 1;
}



// public: unsigned long __thiscall PRUDPTransportSettings::GetOption(unsigned long,class
// UserContext &)

unsigned long __thiscall
PRUDPTransportSettings::GetOption(PRUDPTransportSettings *this,unsigned long param_1,UserContext *param_2)

{
  bool bVar1;
  unsigned long uVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 < 0x103) {
    if (param_1 == 0x102) {
      bVar1 = IsTrappingICMP(this);
      local_8 = CONCAT31(local_8._1_3_,bVar1);
      *(undefined4 *)param_2 = local_8;
      *(undefined4 *)(param_2 + 4) = local_4;
      return 0;
    }
    if (param_1 < 0x101) {
      if (param_1 == 0x100) {
        bVar1 = IsBroadcastingEverywhere(this);
        local_8 = CONCAT31(local_8._1_3_,bVar1);
        *(undefined4 *)param_2 = local_8;
        *(undefined4 *)(param_2 + 4) = local_4;
        return 0;
      }
      if (param_1 == 1) {
        uVar2 = GetMTU(this);
        *(unsigned long *)param_2 = uVar2;
        *(undefined4 *)(param_2 + 4) = local_4;
        return 0;
      }
      if (param_1 == 2) {
        uVar2 = GetWellKnownPortNumber(this);
        *(unsigned long *)param_2 = uVar2;
        *(undefined4 *)(param_2 + 4) = local_4;
        return 0;
      }
    }
    else if (param_1 == 0x101) {
      uVar2 = GetMaxRetransmission(this);
      *(unsigned long *)param_2 = uVar2;
      *(undefined4 *)(param_2 + 4) = local_4;
      return 0;
    }
  }
  else {
    switch(param_1) {
    case 0x103:
      uVar2 = GetMaxSilenceTime(this);
      *(unsigned long *)param_2 = uVar2;
      *(undefined4 *)(param_2 + 4) = local_4;
      return 0;
    case 0x104:
      uVar2 = GetKeepAliveTimeout(this);
      *(unsigned long *)param_2 = uVar2;
      *(undefined4 *)(param_2 + 4) = local_4;
      return 0;
    case 0x105:
      uVar2 = GetTimeSlice(this);
      *(unsigned long *)param_2 = uVar2;
      *(undefined4 *)(param_2 + 4) = local_4;
      return 0;
    case 0x106:
      uVar2 = GetWindowSize(this);
      *(unsigned long *)param_2 = uVar2;
      *(undefined4 *)(param_2 + 4) = local_4;
      return 0;
    }
  }
  return 1;
}


