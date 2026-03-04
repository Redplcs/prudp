//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PHBDRTimeVector_H_
#define _PHBDRTimeVector_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/ContinuityBreak.h>
#include <Platform/Time.h>
#include <queue>

// Action
// These values cannot change.
#define DISCARD_VALUE				0x0
#define INSERT_VALUE_BEFORE_SECOND	0x1
#define INSERT_VALUE_BEFORE_THIRD	0x2
#define INSERT_VALUE_AT_THE_END		0x3
#define INSERT_VALUE_AT_THE_END_x2	0x4
#define INSERT_VALUE_AT_THE_END_x3	0x5

#define DELAY_VALUE					0x6

#define UNKNOWN_POSITION			0xFF


class PHBDRTimeVector {
	public:
		PHBDRTimeVector();
		PHBDRTimeVector(unsigned long ulTime);
		
		~PHBDRTimeVector();

		unsigned long NewValue(Time tValue=SessionClock::GetTime(), 
				ContinuityBreak oContinuityBreak=CONTINUITY_BREAK_NONE, bool bCanDelay=true);
		void Trace(unsigned long ulTraceFlag) const;

		void DelayValue(Time tValue, unsigned char byContinuityBreak);
		unsigned long UseDelayedValue(unsigned char* pbyDelayedCB);
		bool DelayedValueReadyToUse();
		bool ValueReadyToUse(Time tValue, ContinuityBreak oContinuityBreak);

		bool IsInTheFuture(Time tSomeTime);

		void Reset(unsigned char iNbValues);

		TimeInterval GetInterval(int i) const;

		unsigned char NbValues() const;

		TimeInterval ComputeInterval(Time tSomeFuture) const;
		Time T2() const {return m_t2;}
		Time T1() const;
		Time T0() const;


#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
#endif

	private:		
		// Time vector itself.
		TimeInterval m_tInterval[2];
		Time m_t2;

		typedef struct TimePoint {
			Time tValue;
			unsigned char byContinuityBreak;
		} TimePoint;

		
		std::queue<TimePoint>	m_queueDelayedValues;
};

#endif

