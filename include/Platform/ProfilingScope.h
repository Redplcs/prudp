//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProfilingScope_H
#define _ProfilingScope_H_

#include <Utility/UtilityDecl.h>
#include <Platform/ProfilingUnit.h>

// Group=Utility Subsystem

class ProfilingScope {
	// Group=
	public:
		ProfilingScope(ProfilingUnit &pPU);
		~ProfilingScope();
	private:
		ProfilingUnit   *m_pPU;
        ProfilingTime   m_oStartTime;
};

#endif
