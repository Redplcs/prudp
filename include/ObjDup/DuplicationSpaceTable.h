//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DuplicationSpaceTable_H_
#define _DuplicationSpaceTable_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/PseudoSingleton.h>
#include <ObjDup/DupSpaceID.h>
#include <ObjDup/DOHandle.h>
#include <ObjDup/DuplicationSpace.h>
class DOOperation;
class RootDO;

class IteratorOverDOs;
class DuplicatedObject;
class JobThreadPool;
class MatchOperation;

class DuplicationSpaceTable: public PseudoSingleton {
	public:
		DuplicationSpaceTable();
		~DuplicationSpaceTable();

		static DuplicationSpaceTable* GetInstance();

		DuplicationSpace* FindDuplicationSpace(DupSpaceID idDS);

		bool DuplicatedInAnotherSpace(DuplicatedObject* pPublisher, DOHandle hLocation, DupSpaceID idSpaceToSkip);

		void RegisterDuplicationSpaces();
		void UnregisterDuplicationSpaces();

		void StartMatchThread();
		void StopMatchThread();

		void TraceMatchJobQueue(unsigned long ulTraceFlag=TRACE_ALWAYS);

		void CleanupTable();

		void OperationBeginMatchTrigger(DOOperation* pOperation);
		void OperationEndMatchTrigger(DOOperation* pOperation);

		void CheckRelevance(RootDO* pDuplicaToCheck);
		
		void CreateCells();

		// Create a broadcast iterator (to all neighbour stations).
		//IteratorOverDOs* CreateBroadcastIterator();

		// Create a multicast iterator (all stations that hold a
		// duplica of a DO).
		IteratorOverDOs* CreateMulticastIterator(DuplicatedObject* pDO, bool *pbUsesBroadcast, bool bReturnIterator = false);

		void ReleaseIterator(IteratorOverDOs* pIt);

		void FillDefaultCellDupSpaceInfo(DuplicationSpace::Role eRole, 
										 DupSpaceID* pArray, unsigned int *puiIndex);

		class AllocationContext {
			public:
				DupSpaceID* m_pDSArray;
				unsigned int m_uiArrayLength;				
		};

		void CheckPeriodicMatch(bool bSetThreadContext);
		void QueueMatchOperation(MatchOperation* pMatchOperation, TimeInterval tiWhenFromNow=0);

#ifdef _TEST_ENABLED
		static bool Test();
#endif

	private:
		void RegisterDuplicationSpace(DuplicationSpace* pDS);
		void UnregisterDuplicationSpace(DuplicationSpace* pDS);

		std::map<DupSpaceID, DuplicationSpace*> m_mapDS;

		JobThreadPool *m_pMatchOperationThreadPool;
		CriticalSection m_csJobQueue;
};

#endif


