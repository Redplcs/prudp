//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _VirtualSocket_H_
#define _VirtualSocket_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/VirtualQueuingDevice.h>
class EmulationDevice;

class VirtualSocket: public VirtualQueuingDevice {

public:
	VirtualSocket(EmulationDevice *pEmulationDevice);

	virtual bool		Queue(DeviceData *pDeviceData, Time oTime = Time::GetTime());
	virtual DeviceData 	*Head(Time *pTime = NULL);

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif

protected:
	EmulationDevice	*m_pEmulationDevice;
};


#endif
