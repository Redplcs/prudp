//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SystemInfo_H_
#define _SystemInfo_H_

#include <Platform/PlatformDecl.h>

class SystemInfo {
public:
	SystemInfo();
	~SystemInfo();
	static bool IsRunningNT(unsigned long *pulVersion = NULL);
	static bool IsRunning95();
	static bool IsRunning98();
	static bool IsRunningLinux();
	static unsigned long GetMachineUID();
};

#endif
