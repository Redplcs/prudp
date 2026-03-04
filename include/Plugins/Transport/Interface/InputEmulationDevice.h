//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InputEmulationDevice_H_
#define _InputEmulationDevice_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/EmulationDevice.h>
#include <Platform/CriticalSection.h>

class VirtualRouter;

//Group = Performance Fine Tuning

/*
description: Defines the maximum number of bytes the receiving queue 
can contain before dropping packets. This variable is used in the 
context of network pacing.
*/
#define ROUTER_BUFFER_SIZE_DEFAULT 	10000000

#define DROP_PROBABILITY_DEFAULT 		0.0

/*
Description: This class defines an input EmulationDevice.  

Remarks: An input emulation device is referenced via Transport::GetInputEmulationDevice.
Enable must be called before an emulation device can be used.

See Also: EmulationDevice, OutputEmulationDevice
*/
class InputEmulationDevice: public EmulationDevice {
public:
	//Group=
	//{secret}
	InputEmulationDevice();
	~InputEmulationDevice();

	//description: Returns the emulated buffer size, in bytes, which defines 
	//the value of the maximum number of packets the receiving queue 
	//can contain before dropping packets.  
	// See Also: SetRouterBufferSize
	unsigned long GetRouterBufferSize();
	
	/*
	description:  Sets the emulated buffer size, in bytes, which defines 
	the value of the maximum number of packets the receiving queue 
	can contain before dropping packets.  
	
	Parameters:
	usRouterBufferSize:  The input router buffer size, in bytes. If this buffer
	is overfilled, the router begins to simulate the dropping of packets. The 
	default value is 4000 bytes, as defined by ROUTER_BUFFER_SIZE_DEFAULT.
	
	See Also: GetRouterBufferSize
	*/
	void SetRouterBufferSize(unsigned long usRouterBufferSize);

	// {secret}
	bool IncCurrentRouterBufferSize(unsigned long ulSize);
	// {secret}
	void DecCurrentRouterBufferSize(unsigned long ulSize);

	/*
	description: Sets the packet drop probability to simulate poor network
	conditions where packets are dropped by routers on the way to their 
	destination.
	
	Parameters:
	dProbability: The probability that a packet will be dropped on the way to 
	its destination.
	
	Remarks: dProbability must be in the range 0-1 and the default value is 0. 
	 
	Returns: true if the call did not signal an error, false if otherwise. 
	SYSTEMERROR_GEN_OUT_OF_RANGE is signalled if the range given is not between 0-1.

	See Also: GetPacketDropProbability
	*/
	bool 	SetPacketDropProbability(double dProbability);

	//description: Returns the packet drop probability that was set with
	//SetPacketDropProbability.
	//See Also: SetPacketDropProbability
	double	GetPacketDropProbability();

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
	unsigned long 			m_ulRouterBufferSize;
	double					m_dPacketDropProbability;
	VirtualRouter			*m_pRouter;
	unsigned long			m_ulCurrentSize;
	CriticalSection	m_cs;
};


#endif
