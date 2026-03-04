//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DeviceData_H_
#define _DeviceData_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Core/RefCountedObject.h>

class DeviceData: public RefCountedObject {
public:	
	typedef bool (*DeliverCallback)(DeviceData *pDeviceData);

public:
	DeviceData(unsigned long ulDataSize, DeliverCallback pDeliverCallback = NULL);
	virtual	~DeviceData();

	unsigned long GetDataSize();
	bool Deliver();

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif

private:
	unsigned long	m_ulDataSize;	
	DeliverCallback	m_pDeliverCallback;
};


#endif
