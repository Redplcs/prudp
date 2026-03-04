//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _VirtualQueuingDevice_H_
#define _VirtualQueuingDevice_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Platform/Time.h>
#include <Platform/Time.h>
#include <Plugins/Transport/Interface/DeviceData.h>
#include <Plugins/Transport/Interface/TimedQueue.h>
#include <list>

class VirtualQueuingDevice {

	typedef std::list<VirtualQueuingDevice*>	ConnectedDeviceList;

public:
	VirtualQueuingDevice();
	virtual ~VirtualQueuingDevice();

	virtual bool		Queue(DeviceData *pDeviceData, Time oTime = Time::GetTime());
	virtual bool        QueueHighPriority(DeviceData *pDeviceData, Time oTimeoTime = Time::GetTime());
	virtual DeviceData *Head(Time *pTime = NULL);
	virtual void		Dequeue();
	virtual void		Purge();

	void	ConnectOutputDevice(VirtualQueuingDevice *pDevice);
	void	DisconnectOutputDevice(VirtualQueuingDevice *pDevice);
	void	ConnectInputDevice(VirtualQueuingDevice *pDevice);
	void	DisconnectInputDevice(VirtualQueuingDevice *pDevice);

	unsigned long	GetQueueSize();
	Time 	HeadTime();

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif

protected:
	void AddDevice(ConnectedDeviceList *pDeviceList, VirtualQueuingDevice *pVirtualDevice);
	void RemoveDevice(ConnectedDeviceList *pDeviceList, VirtualQueuingDevice *pVirtualDevice);
	void Flush();
	void Drain();

	TimedQueue<DeviceData*>	m_oDeviceDataQueue;
	ConnectedDeviceList m_oConnectedInputDevice;
	ConnectedDeviceList m_oConnectedOutputDevice;
};


#endif
