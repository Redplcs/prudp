//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _FaultRecoveryOperation_H_
#define _FaultRecoveryOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOOperation.h>
#include <Utility/CREWLock.h>
#include <Utility/PseudoGlobalVariable.h>

//Group = System Operations

/*
Description:  
This DOOperation is performed every time a fault is detected on a station.

Remarks:
When a station fails, a FaultRecoveryOperation is performed on the session master for each duplicated object 
whose Duplication master resided on the failed station.

	o	The method DuplicatedObject::OperationBegin is called and the FaultRecoveryOperation starts,
	o	The method DuplicatedObject::ApproveFaultRecovery is called.

If DuplicatedObject::ApproveFaultRecovery returns true, the session master takes control of the duplicated 
object via the following sequence of events:

	o	The operations MasterIDChangeOperation and RoleChangeOperation are performed,
	o	The method DuplicatedObject::OperationEnd is called and the FaultRecoveryOperation ends.
	
If DuplicatedObject::ApproveFaultRecovery returns false the object is removed from the store via the following 
sequence of events:

	o	The RemoveFromStoreOperation is triggered,
	o	The method DuplicatedObject::OperationEnd is called and the FaultRecoveryOperation ends,
	o	The object destructor is called.

*/
class FaultRecoveryOperation: public DOOperation {
	//Group=
	public:
		//{secret}
		FaultRecoveryOperation(DuplicatedObject* pDO);
		//{secret}
		virtual ~FaultRecoveryOperation();
		//{secret}
		virtual void Trace(Event eEvent) const;
		//{secret}
		virtual Type GetType() const {return FaultRecovery;}

		/* 
		Description:  This static method returns the system OperationLock for the FaultRecoveryOperation.
		
		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
		
		Returns:  A ConcurrentDenialOperationLock that controls the FaultRecoveryOperation.
		*/
	   static ConcurrentDenialOperationLock* GetOperationLock();

/*
Description:
Sets the tracing of the FaultRecoveryOperation to true.
			
Remarks:
To trace the FaultRecoveryOperation you must first set the TRACE_OPERATION flag with:
	          
        TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags.  However, if the call to FaultRecoveryOperation::ClearTraceFlag 
was made then you can reenable the FaultRecoveryOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		/*
		Description: Disables the trace of the FaultRecoveryOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the FaultRecoveryOperation trace via this method.
					
		See Also: SetTraceFlag, TRACE_OPERATION			
		*/
		static void ClearTraceFlag() {s_bTraceFlag=false;}

		/*
		Description: Returns whether or not the trace flag for this operation is set.

		Returns: true if the trace flag for this operation is set, false if otherwise.
				
		See Also: SetTraceFlag, TRACE_OPERATION, ClearTraceFlag
		*/
		static bool GetTraceFlag() {return s_bTraceFlag;}

		//{secret}
        virtual CallbackList<DOOperation*>* GetCallbackList(Operation::Event operationEvent);

		//{secret}
        static void RegisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

		//{secret}
        static void UnregisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

	private:
		//{secret}
		static ConcurrentDenialOperationLock s_lockFaultRecovery;		
		//{secret}
		static bool s_bTraceFlag;

		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_Begin;

		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_End;

};

#endif
