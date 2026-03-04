//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DuplicatedObjectStore_H_
#define _DuplicatedObjectStore_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/DOSBP.h>
#include <ObjDup/Observer.h>

#include <ObjDup/Store.h>
#include <Platform/PerfCounter.h>
#include <Utility/JobThreadPool.h>

class Channel;
class ObjDupProtocol;
class DOSBP;
class NetworkRef;

#define UPDATE_CHANNEL_NUMBER			0

#define NODE_ID_UNDEFINED 0

//group=System Traces


/*
Description:
The DuplicatedObjectStore is the class contains information about the local DuplicatedObject instances.

Remarks:
This class offers the following call which lists all of the duplicated object instances present
on the local station at the time of the call:

            DuplicatedObjectStore::GetInstance()->Trace(TRACE_ALWAYS);
            
See Also:
DuplicatedObject::Trace            
*/
class DuplicatedObjectStore: public Store {
	// Group=
	public:
		//{secret}
		DuplicatedObjectStore();
		//{secret}
		~DuplicatedObjectStore();
		
		/*
		Description: Returns a pointer to the DuplicatedObjectStore.
		Remarks: This method returns a pointer to the instance of DuplicatedObjectStore that can then
		be used to Trace the properties of all of the local duplicated objects.
        */
		static DuplicatedObjectStore* GetInstance();

		//{secret}
		// Redefine the store DeleteItem method, to call the appropriate destructor.
        virtual void DestroyItem(CollectionItem *pItem, DOHandle hDoHandle);

		//{secret}
		bool AddDuplicatedObject(DuplicatedObject* pDO);
	
		//{secret}
		void PrepareToLeave();

		/*
		Description: Call this method to trace the contents of the local DuplicatedObject store.
		Remarks: This method calls DuplicatedObject::Trace on all of the duplicated objects presently
		instantiated on a station.
		See Also: DuplicatedObject::Trace            
		*/
		void Trace(unsigned long ulTraceFlags=TRACE_ALWAYS, DOFilter* pFilter=NULL);

		//{secret}
		// Methods to control the job thread queue.  
		void StartJobQueueThread();
		
		//{secret}
		void StopJobQueueThread();
		// {secret}
		void TraceJobQueue(unsigned long ulTraceFlag=TRACE_ALWAYS);
		
		//{secret}
		bool QueueJob(JobRoot* pJobToQueue, TimeInterval tiWhenFromNow=0, bool bCritical=true);
		
		//{secret}
		void SetPseudoSingletonContext(int iDummy);

		//{secret}
		bool _ClearTheStore(DOFilter* pDOFilter);
		
		//{secret}
		bool ClearTheStore(DOFilter* pDOFilter);
		
		//{secret}
		bool IsLeaving();
		//{secret}
		bool IsClearingTheStore();
		
		//{secret}
		bool IsReady();

		//{secret}
		void WaitUntilReadyToLeave();
		
		//{secret}
		bool IsReadyToLeave();

		// Association to several Contextes? (ExtrapolatedUpdateContext, FilteringContext).

		// Association to a DOSFilter???
		//{secret}
		ObjDupProtocol* GetAssociatedProtocol();
		
		//{secret}
		UserDOCtrlInterface* GetAssociatedUserDOCtrlInterface();
		
		//{secret}
		void AssociateUserDOCtrlInterface(UserDOCtrlInterface* poAssociatedUserDOCtrlInterface);
		
		//{secret}
		DOSBP& GetDOSBP();
		
		//{secret}
		bool SetProperty(DOHandle id, PropertyCategory ulSBPType, unsigned long ulProperty);
		
		//{secret}
		bool ChangeProperty(DOHandle id, PropertyCategory ulSBPType, unsigned long ulOldProperty, unsigned long ulNewProperty);
		
		//{secret}
		void DeleteMarkedDOs(DOFilter* pDOFilter=NULL);
		
		//{secret}
        void RemoveObject(DOHandle hObjectToRemove, bool bMulticast);

		//{secret}
		PerfCounter* GetUpdateCounter() {return m_pUpdateCounter;}

		//{secret}
		ICContext FindInstanceContext();

	private:
		//{secret}
		ObjDupProtocol* m_poProtocol;
		
		// Association to several SelectionByProperty...
		//{secret}
		DOSBP* m_pdosbp;

		// Association to the DOCtrlInterface.
		//{secret}
		UserDOCtrlInterface* m_poAssociatedUserDOCtrlInterface;

		// This class is used to queue jobs.
		//{secret}
		JobThreadPool m_oJobQueue;
		//{secret}
		bool m_bClearingTheStore;
		bool m_bLeaving;
		//{secret}
		PerfCounter* m_pUpdateCounter;
		//{secret}
		PseudoSingleton m_psDOSInstanceControl;
};

#endif
