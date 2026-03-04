//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ProfilingClocks_H_
#define _ProfilingClocks_H_

#include <Platform/PlatformDecl.h>
#include <Platform/ProfilingTime.h>

class ProfilingClocks {
public:
	ProfilingClocks();
	~ProfilingClocks();

	static ProfilingTime GetThreadProfilingTime();
	static ProfilingTime GetProcessProfilingTime();

	static _ULONGLONG GetFrequency();

	void	Trace(unsigned long ulTraceFlags);

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif
private:
	static ProfilingClocks	s_oInstance; 
};

#endif
