//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _JobQueue_H_
#define _JobQueue_H_

#include <Utility/UtilityDecl.h>
#include <Utility/Job.h>
#include <Platform/Time.h>
#include <Platform/CriticalSection.h>
#include <list>

class JobQueue {

class TimedJob;

public:
	JobQueue();
	~JobQueue();
	void PurgeNonCritical();

	void Queue(JobRoot* pJob, TimeInterval oWhenFromNow = 0, bool bCritical=true);
	void QueueHighPrio(JobRoot* pJob);

	JobRoot *GetNextReady();
	int GetSize();

#ifdef _TEST_ENABLED
	static bool Test();
#endif


	void Trace(unsigned long ulFlags=TRACE_ALWAYS);


private:
	std::list<TimedJob*>	m_oJobQueue;
	CriticalSection		m_csQueue;
};

#endif
