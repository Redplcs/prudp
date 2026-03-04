//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _RemoveFromStoreOperation_H_
#define _RemoveFromStoreOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOOperation.h>
#include <Utility/PseudoGlobalVariable.h>
//Group = System Operations

/*
Description:
This DOOperation is performed each time a duplicated object is deleted.

Remarks
As with all DOOperations there is one ConcurrentDenialOperationLock associated with this operation 
and therefore, a RemoveFromStoreOperation may be simultaneously denied by several threads. To lock this operation, 
use the OperationDenial or OperationLock class.  To get a reference to the system lock for
the RemoveFromStoreOperation use the static method RemoveFromStoreOperation::GetOperationLock.

The RemoveFromStoreOperation behaves differently depending on whether it is a Duplication master 
or a Duplica that is being deleted.  

A Duplication master instance is deleted as a result of one of these two possible sequences of events:
	
	o	A station that holds a Duplication master instance leaves the session 
	and the DuplicatedObject::ApproveEmigration or DuplicatedObject::ApproveFaultRecovery system callback returns false,
	o	A Duplication master instance of a duplicated object is deleted via the method DuplicatedObject::DeleteMainRef.
          
When an object is removed from the duplication master store the following sequence of events occurs:	
	o 	The method DuplicatedObject::OperationBegin is called and the RemoveFromStoreOperation begins,
	o	The duplicas of the Duplication master object are notified of the deletion via a multicasted message which results in duplica deletion operations (see below),
	o	The reference to the object in the duplication master store is deleted,
	o	The method DuplicatedObject::OperationEnd is called and the RemoveFromStoreOperation ends,
	o	When there are no more references to the object, created via the RefTemplate, the object destructor is called.
	
A Duplica instance is deleted as a result of a DuplicationSpace::CheckRelevance and DuplicationSpace::PSMatch 
virtual function returning false.

When an object is deleted from duplica store, the following sequence of events occurs:
	o 	The method DuplicatedObject::OperationBegin is called and the RemoveFromStoreOperation begins,
	o	The reference to the object in the duplica store is deleted,
	o	The method DuplicatedObject::OperationEnd is called and the RemoveFromStoreOperation ends,
	o	When there are no more references to the object, created via the RefTemplate, the object destructor is called.

See Also: DuplicatedObject::DeleteMainRef
*/
class RemoveFromStoreOperation: public DOOperation {

	public:
		//{secret}
		RemoveFromStoreOperation(DuplicatedObject* pDO, bool bDeleted);
		//{secret}
		virtual ~RemoveFromStoreOperation();

		//{secret}
		virtual void Trace(Event eEvent) const;
		//{secret}
		virtual Type GetType() const {return RemoveFromStore;}
//Group=Operations
		/* 
		Description:  This static method returns the system OperationLock for the RemoveFromStoreOperation.

		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
				
		Returns:  A ConcurrentDenialOperationLock that controls the RemoveFromStoreOperation.
		*/
		static ConcurrentDenialOperationLock* GetOperationLock();
		
/*
Description:
Sets the tracing of the RemoveFromStoreOperation to true.
			
Remarks:
To trace the RemoveFromStoreOperation you must first set the TRACE_OPERATION flag with:
		          
         TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to RemoveFromStoreOperation::ClearTraceFlag was
made then you can reenable the RemoveFromStoreOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		/*
		Description: Disables the trace of the RemoveFromStoreOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the RemoveFromStoreOperation trace via this method.
					
		See Also: SetTraceFlag, TRACE_OPERATION			
		*/
		static void ClearTraceFlag() {s_bTraceFlag=false;}
		/*
		Description: Returns whether or not the trace flag for this operation is set.

		Returns: true if the trace flag for this operation is set, false if otherwise.
				
		See Also: SetTraceFlag, TRACE_OPERATION, ClearTraceFlag
		*/
		static bool GetTraceFlag() {return s_bTraceFlag;}
		/*
		Description: Returns whether or not the RemoveFromStoreOperation was triggered by a duplicated object deletion.
				
		Remarks: Returns true if the RemoveFromStoreOperation is being performed as a result of a call to
		DuplicatedObject::DeleteMainRef or the disconnection from the session of a master 
		station for a non-fault-tolerant duplicated object. 
				
		Returns: true if the RemoveFromStoreOperation is being performed as a result of a call to
		DuplicatedObject::DeleteMainRef or the disconnection from the session of a master 
		station followed by a return of false for DuplicatedObject::ApproveEmigration or 
		DuplicatedObject::ApproveFaultRecovery.
		*/
		bool ObjectIsDeleted() {return m_bDeleted;}
		/*
		Description: Returns whether or not the RemoveFromStoreOperation was triggered by a relevance check in
		the DuplicationSpace.
				
		Remarks: This method can only return true if the RemoveFromStoreOperation is being performed on a Duplica,
		since only duplicas can become irrelevant.  If this method returns true, it implies that the 
		removal from the duplica store that is performed is a result of a DuplicationSpace::CheckRelevance
		call followed by the DuplicationSpace::PSMatch function returning false.
				
		Returns: true if the RemoveFromStoreOperation is being performed as a result of a 
		DuplicationSpace::CheckRelevance call followed by the DuplicationSpace::PSMatch function returning false.	
				
		See Also: DOOperation::GetAssociatedDO
		*/
		bool ObjectIsIrrelevant() {return !m_bDeleted;}

        //{secret}
        virtual CallbackList<DOOperation*>* GetCallbackList(Operation::Event operationEvent);

		//{secret}
        static void RegisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

		//{secret}
        static void UnregisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

	private:
		//{secret}
		static ConcurrentDenialOperationLock s_lockRemoveFromStore;		
		//{secret}
		static bool s_bTraceFlag;
		//{secret}
		bool m_bDeleted;

		//{secret}
		//static CallbackList<DOOperation*> s_oCallbackList_Begin;
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_Begin;

		//{secret}
		//static CallbackList<DOOperation*> s_oCallbackList_End;
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_End;

        CriticalSection *m_pCsStore;
};

#endif
