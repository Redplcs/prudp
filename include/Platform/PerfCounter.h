//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PerfCounter_H_
#define _PerfCounter_H_


#include <Platform/PlatformDecl.h>
#include <Platform/Time.h>

/*
{group: Performance Fine Tuning}

description: The frequency of the counter observed during the last second.
*/
#define PERF_FREQUENCY_LAST			1

/*
{group: Performance Fine Tuning}

description: The average frequency of the counter observed since 
the creation of the counter or since the last time it was reset.
*/
#define PERF_FREQUENCY_AVERAGE		2

/*
{group: Performance Fine Tuning}

description: The minimum frequency of the counter observed since 
the creation of the counter or since the last time it was reset.
*/
#define PERF_FREQUENCY_MIN			3

/*
{group: Performance Fine Tuning}

description: The maximum frequency of the counter observed since 
the creation of the counter or since the last time it was reset.
*/
#define PERF_FREQUENCY_MAX			4

/*
{group: Performance Fine Tuning}

description: The total number of the counter since the creation of 
the counter or since the last time it was reset.
*/
#define PERF_COUNT_TOTAL			5

// {Secret}
class PerfCounter {
	// Group=
	public:
		PerfCounter(Time tNow = Time::GetTime());
		~PerfCounter();

		void Reset(Time tNow = Time::GetTime());
		void Inc(unsigned long ulValue = 1,Time tNow = Time::GetTime());
		void Dec(unsigned long ulValue = 1,Time tNow = Time::GetTime());
		void Trace(unsigned long ulTraceFlags,Time tNow = Time::GetTime());

		unsigned long GetAvg(Time tNow = Time::GetTime());
		unsigned long GetTotal(Time tNow = Time::GetTime());
		unsigned long GetMin(Time tNow = Time::GetTime());
		unsigned long GetMax(Time tNow = Time::GetTime());
		unsigned long GetLast(Time tNow = Time::GetTime());

		static bool ValidValueRange(int iValue);

		unsigned long GetValue(int iValue);

		#ifdef _TEST_ENABLED
		static bool Test();
		#endif

	private:
		void Update(Time tNow, int iValue=0);

	protected:
		unsigned long 		m_ulCurrent[10];
		unsigned long 		m_ulMin;
		unsigned long 		m_ulMax;
		unsigned long 		m_ulLast;
		unsigned long 		m_ulTotal;
		Time				m_tLastTime;
		Time				m_tStarted;
};
#endif
