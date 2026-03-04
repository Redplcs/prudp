//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _EmulationDevice_H_
#define _EmulationDevice_H_

#include <Plugins/Transport/Interface/TransportDecl.h>

class VirtualModem;
class VirtualLatency;
class VirtualSocket;
class DeviceData;
class VirtualQueuingDevice;
class CriticalSection;

#define INFINITE_BANDWIDTH	0xFFFFFFFF

/* Group = Performance Fine Tuning

description: This class enables various network conditions to be
emulated. The two types of emulation devices InputEmulationDevice 
and OutputEmulationDevice both inherit from the class EmulationDevice.

Remarks: An emulation device is referenced via Transport::GetInputEmulationDevice 
or Transport::GetOutputEmulationDevice. It should be noted that some transport 
protocol plug-ins may not support all the functionality of the emulation device.
Enable must be called before an 
emulation device can be used.

See Also: InputEmulationDevice, OutputEmulationDevice
*/
class EmulationDevice {
public:

	//Group =

	//{secret}
	EmulationDevice();
	//{secret}
	~EmulationDevice();

	/*
	description: Sets the simulated latency in milliseconds.
	
	Parameters:
	usLatency: The latency you want to emulate, in milliseconds. The 
	default is 0.
	
	Remarks: Latency is the amount of time before a message sent from 
	one station is received by another station. Enable must 
	be called before this parameter is set. The only way to reference
	an emulation device is to use Transport::GetInputEmulationDevice or
	Transport::GetOutputEmulationDevice.

	See Also: GetLatency
	*/
	void		SetLatency(unsigned short usLatency);

	/*
	description: Sets the simulated network jitter, in milliseconds. 
	Jitter is the variation in latency.
	
	Parameters:
	usJitter: Set this value to increase the latency in a random way 
	in the range of 0 to usJitter milliseconds. The default value is 0.
	
	Remarks: Use this call to adjust the jitter. As a result, the latency 
	will be increased randomly by a value between 0 and usJitter.
	Enable must be called before this parameter is set. 
	The only way to reference an emulation device is to use 
	Transport::GetInputEmulationDevice or
	Transport::GetOutputEmulationDevice.

	See Also: GetJitter
	*/
	void		SetJitter(unsigned short usJitter);
	// {secret}
	void		SetProtocolHeaderSize(unsigned short ulHeaderSize);

	/*
	description: Sets the simulated modem bandwidth in bits per second.
	
	Parameters:
	ulBandwidth: The emulated bandwidth in bits per second. The default value 
	is INFINITE.
	
	Remarks:  Adjust the emulated bandwidth with this call. The default is 
	INFINITE and therefore, performance is limited only by the actual physical 
	bandwidth of the system. Change the emulated bandwidth to test the 
	performance of your $gameORapp$ at various conditions. Enable 
	must be called before this parameter is set. The only way to reference
	an emulation device is to use Transport::GetInputEmulationDevice or
	Transport::GetOutputEmulationDevice.

	See Also: GetBandwidth
	*/
	void		SetBandwidth(unsigned long ulBandwidth);

	// {secret}
	unsigned short		GetProtocolHeaderSize();


	//description: Returns the simulated latency in milliseconds.
	//Remarks:  You can set this value via SetLatency.
	//See Also: SetLatency
	unsigned short		GetLatency();

	//description: Returns the simulated jitter in milliseconds.
	//Remarks:  You can set this value via SetJitter.
	//See Also: SetJitter
	unsigned short		GetJitter();

	//description: Returns the simulated modem bandwidth in bits per second.
	//Remarks: You can set this value via SetBandwidth.
	//See Also: SetBandwidth
	unsigned long		GetBandwidth();

	// {secret}
	VirtualModem	*GetModem();
	
	//Description: Use this method to determine if an emulation device is enabled.
	//Returns: true if the either the input or output emulation device that the method is
	//called on is enabled, false if it is not.
	//See Also: Enable
	bool			IsEnabled() { return m_bEnabled; };

	//Description: Use this method to enable an emulation device.
	//Remarks: This method must be called before either the input or output emulation
	//devices are used.
	//See Also: IsEnabled
	virtual void	Enable() {};

	// {secret}
	virtual void	DeliverData();
	// {secret}
	virtual void	Queue(DeviceData *pDeviceData);

	// {secret}
	virtual VirtualQueuingDevice *GetDeviceInput();
	// {secret}
	virtual VirtualQueuingDevice *GetDeviceOutput();

	// Description: Returns the size of the data queue.
	unsigned long GetQueueSize();

	#ifdef _TEST_ENABLED
	// {secret}
	static bool 	Test();
	#endif

protected:
	unsigned short 			m_usLatency;
	unsigned short 			m_usJitter;
	unsigned short			m_usProtocolHeaderSize;
	unsigned long  			m_ulBandwidth;
	VirtualModem 			*m_pModem;
	VirtualLatency 			*m_pLatency;
	VirtualSocket 			*m_pSocket;
	VirtualQueuingDevice 	*m_pQueue;
	bool					m_bEnabled;
	CriticalSection			*m_csQueue;
};


#endif
