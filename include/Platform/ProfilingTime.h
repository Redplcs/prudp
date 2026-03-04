//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ProfilingTime_H_
#define _ProfilingTime_H_

#include <Platform/PlatformDecl.h>
#include <Platform/Time.h>

class ProfilingTime {
public:
	ProfilingTime(const ProfilingTime& oTime);
	ProfilingTime();
	~ProfilingTime();

	void SetUserTime(_ULONGLONG ullTime);
	void SetKernelTime(_ULONGLONG ullTime);
	void SetRealTime(_ULONGLONG ullTime);

	Time GetUserTime();
	Time GetKernelTime();
	Time GetTotalTime();
	Time GetRealTime();

    ProfilingTime operator+(ProfilingTime oTime) const;
    ProfilingTime operator-(ProfilingTime oTime) const;
	ProfilingTime& operator=(const ProfilingTime& oTime);

	void	Trace(unsigned long ulTraceFlags);

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif
private:
	_ULONGLONG				m_ullUserTime;
	_ULONGLONG				m_ullKernelTime;
	_ULONGLONG				m_ullRealTime;
};

#endif
