//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _VirtualRouter_H_
#define _VirtualRouter_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/VirtualQueuingDevice.h>
class InputEmulationDevice;

class VirtualRouter: public VirtualQueuingDevice {

public:
	VirtualRouter(InputEmulationDevice *pInputEmulationDevice);

	virtual bool	Queue(DeviceData *pDeviceData, Time oTime = Time::GetTime());
	virtual void 	Dequeue();

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif

protected:
	InputEmulationDevice	*m_pInputEmulationDevice;
};


#endif
