//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Time_H_
#define _Time_H_

#include <Platform/PlatformDecl.h>

// Group = Time Management

//Summary: This type is used to express a time interval in milliseconds.
typedef long TimeInterval;

// {Secret}
typedef _LONGLONG LargeTimeInterval;

// Group = Time Management

/*
Summary: An object of this class expresses a time in milliseconds.

The objects LocalClock or SessionClock can be used to set a value to a
Time object. The following example sets the value of the variable tNow to
the number of milliseconds elapsed since the session started.

		Time tNow=SessionClock::GetTime();

See also: LocalClock, SessionClock, TimeInterval
*/
class Time {
	public:
		Time();
		Time(const _ULONGLONG ui64Value);

		#ifdef linux
        
		// Remarks: The constructor Time(const Time& tTime) is not valid 
		// on Win32 platforms.
		Time(const Time& tTime);

		Time(const struct timeval oTimeval);
		Time(const struct timespec oTimeSpec);
		
		// {Secret}
		void GetTime(struct timespec &oTimeSpec);
		void GetTime(struct timeval &oTimevla);
		#endif

		static Time  GetTime();
		// {secret}
		static void  GetFrequency(Time* pliFrequency);

		#ifdef WIN32
		// {secret}
		static TimeInterval  InitRatio();
		#endif

		Time& operator=(const Time& tTime);
		Time& operator=(_ULONGLONG ui64Value);

		operator _ULONGLONG() const;
		operator _ULONGLONG();

		LargeTimeInterval operator-(const Time& tTime) const;

		Time operator-(TimeInterval tiTime) const;
		Time operator+(TimeInterval tiTime) const;

		Time operator-(LargeTimeInterval tiTime) const;
		Time operator+(LargeTimeInterval tiTime) const;

		bool operator==(const Time& tTime) const;
		bool operator!=(const Time& tTime) const;
		bool operator<(const Time& tTime) const;
		bool operator>(const Time& tTime) const;
		bool operator<=(const Time& tTime) const;
		bool operator>=(const Time& tTime) const;

		// {Secret}
		Time Scale(double dRatio) const;

		// {Secret}
		Time Multiply(double dFactor) const;
		// {Secret}
		Time Divide(double dDividend) const;

#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
#endif

	private:
		_ULONGLONG m_ui64Value;
};

#endif
