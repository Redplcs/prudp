//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _OutputEmulationDevice_H_
#define _OutputEmulationDevice_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/EmulationDevice.h>


//Group = Performance Fine Tuning

/*
Summary: This class defines an output EmulationDevice.  

Remarks: An output emulation device is referenced via Transport::GetOutputEmulationDevice.
Enable must be called before an emulation device can be used.

The class OutputEmulationDevice has no specific methods of its own
but inherits all methods from the class EmulationDevice.

See Also: EmulationDevice, InputEmulationDevice
*/
class OutputEmulationDevice: public EmulationDevice {

public:
	// {secret}
	virtual void	Enable();

	// {secret}
	virtual VirtualQueuingDevice *GetDeviceInput();
	// {secret}
	virtual VirtualQueuingDevice *GetDeviceOutput();


	#ifdef _TEST_ENABLED
	// {secret}
	static bool 	Test();
	#endif
private:
};


#endif
