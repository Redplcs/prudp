//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ActiveObject_H_
#define _ActiveObject_H_

#include <Utility/UtilityDecl.h>
#include <Platform/ObjectThread.h>
#include <Platform/Time.h>

class Pacer;

class ActiveObject {
	public:
		ActiveObject(TCHAR* szName);
		virtual ~ActiveObject();

		bool Start() {return StartPeriodicAction(0);}
		bool StartPeriodicAction(double dFrequency);

		void Run(int iDummy);

		virtual void Action()=0;

		TCHAR* GetName() {return m_szName;}

		void GetStats(TimeInterval* ptiTotal,
					  TimeInterval* ptiTotalProcessing,
					  TimeInterval* ptiMinProcessing,
					  TimeInterval* ptiMaxProcessing,
					  unsigned long *pulLoops);

		bool Stop(unsigned long ulTimeout=WAIT_INFINITE);

#ifdef _TEST_ENABLED
		static bool Test();
#endif


	private:
		double m_dFrequency;
		ObjectThread<ActiveObject, int> *m_pThread;

		Pacer *m_poPacer;

	protected:

		bool m_bStop;
		bool m_bStopped;

	protected:
		TCHAR* m_szName;
};

//}

#endif
