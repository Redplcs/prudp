//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _JobThreadPool_H_
#define _JobThreadPool_H_

#include <Utility/UtilityDecl.h>
#include <Platform/ObjectThread.h>
#include <Utility/JobQueue.h>

class JobThreadPool {

public:
	JobThreadPool();
	~JobThreadPool();

	bool Start(unsigned int uiNbThreads);
	bool Stop(bool bWaitForEmptyQueue=false);

	void AcceptNewJobs();
	void RefuseNewJobs();

	typedef enum _State {Running, Stopping, Stopped} State;
	CriticalSection& StateCS() {return m_csState;}
	State GetState();

	bool Queue(JobRoot* pJob, TimeInterval tiWhenFromNow=0, bool bCritical=true);
	bool QueueHighPrio(JobRoot* pJob);

	JobQueue *GetJobQueue();
	void RunJobs(JobThreadPool *pThisPool);

	void Trace(unsigned long ulFlags);

	void PurgeNonCritical() {m_oJobQueue.PurgeNonCritical();}

#ifdef _TEST_ENABLED
	static bool Test();
#endif
private:
	CriticalSection m_csState;
	bool m_bAcceptNewJobs;
	State m_eState;
	ObjectThread<JobThreadPool,JobThreadPool*>	**m_pThreadPool;
	JobQueue									m_oJobQueue;
	unsigned int								m_uiNbThreads;
	bool										m_bDeleting;
};

#endif
