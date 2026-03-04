//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _VirtualModem_H_
#define _VirtualModem_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Platform/Time.h>
class EmulationDevice;

class VirtualModem {

public:
	VirtualModem(EmulationDevice *pEmulationDevice);

	float 	GetIOTime(unsigned short usIOSize);
	Time 	GetNextIOTime(unsigned short usIOSize);

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif

protected:
	Time	m_oOutputTime;
	float	m_fRoundingError;
	EmulationDevice *m_pEmulationDevice;
};


#endif
