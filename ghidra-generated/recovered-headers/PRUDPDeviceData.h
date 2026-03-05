// Auto-generated from PRUDPDeviceData.obj.md
#ifndef _PRUDPDEVICEDATA_H_
#define _PRUDPDEVICEDATA_H_

#include <Plugins/Transport/Interface/DeviceData.h>
#include "Packet.h"
#include "UDPSocket.h"




class PRUDPDeviceData {
public:
    PRUDPDeviceData(Packet*,UDPSocket*,bool (__cdecl*)(DeviceData*));
    virtual ~PRUDPDeviceData();
};

#endif // _PRUDPDEVICEDATA_H_
