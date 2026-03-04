//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _LocalClock_H_
#define _LocalClock_H_

#include <Platform/PlatformImpl.h>
#include <Platform/Time.h>

// Group=Time Management

/*
Summary:  The local clock provides the time, in milliseconds, on the local 
station since the creation of the process.

Remarks:  The time provided by the local clock is not synchronized across 
the stations that belong to the session. The clock is initialized to 
0 ms when the process starts.

See also: SessionClock, Time
*/
class LocalClock {
	// Group=
	public:
		// {Secret}
		static LocalClock* Instance();
		// {Secret}
		static void DeleteInstance();
		// {Secret}
		static void CreateInstance() {Instance();}
		
	#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
	#endif

	#ifdef WIN32
	private:
	#endif

		// {Secret}
		LocalClock();
		// {Secret}
		~LocalClock();

	public:

		//Summary: Returns the current local time in milliseconds.
		static Time GetTime();

		// {Secret}
		Time Now();

	private:
		static LocalClock* s_pInstance;

		#ifdef WIN32
		Time m_tiRatio;		
		#endif

		Time	m_oBaseClockTime;
};

#endif

