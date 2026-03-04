//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SpinTest_H_
#define _SpinTest_H_

#include <Platform/PlatformDecl.h>
#include <Platform/Time.h>

// Group=Utility Subsystem

#define INFINITE_SPIN	0xFFFFFFFF

class SpinTest {
	// Group=
	public:
		SpinTest(unsigned long ulSpinPeriod, unsigned long ulTimeout = INFINITE_SPIN);
		virtual ~SpinTest();

		void SetTrace(unsigned long ulSpinPeriod, unsigned long ulTraceFlag = D_TRACE_WAIT);
		unsigned long GetTraceFlag();

		bool SpinOnce(TCHAR *strFileName, unsigned long ulLine, TCHAR *strCondition);
		void AssertOnTimeout();
		void LeaveOnTimeout();

		unsigned long GetElapsed();
		unsigned long GetTimeout();

	private:
		unsigned short m_usTimeoutConsequence;
		unsigned long  m_ulTimeout;
		Time   		   m_tBegin;
		unsigned long  m_ulElapsed;
		unsigned long  m_ulSpinPeriod;
		unsigned long  m_ulTracePeriod;
		unsigned long  m_ulTraceFlag;
};

#define SpinOn(oSpinTest,Cond) \
	{ while ((Cond) && oSpinTest.SpinOnce(_T(__FILE__),__LINE__,_T(#Cond))); } 

#define SpinOnAction(oSpinTest,Cond,SpinAction) \
	{ \
		while (Cond) { \
			SpinAction; \
			if (!oSpinTest.SpinOnce(_T(__FILE__),__LINE__,_T(#Cond))) { \
				break; \
			}\
		} \
	} 

#endif
