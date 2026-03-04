//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ProfilingUnit_H_
#define _ProfilingUnit_H_

// Group=Utility Subsystem
#include <Utility/UtilityDecl.h>
#include <Platform/ProfilingTime.h>
#include <Platform/CriticalSection.h>

class ProfilingUnit {
	// Group=
	public:
		ProfilingUnit(const TCHAR *szName);
		~ProfilingUnit();

		void IncTime(ProfilingTime oTimeIncrement);

		ProfilingTime GetTime();
		unsigned long GetOccurence();

		void Trace(unsigned long ulTraceFlags);
	private:
		TCHAR			*m_szName;
		ProfilingTime	m_oTime;
		unsigned long	m_ulNbOccurence;
		CriticalSection	m_oCriticalSection;
};

#endif
