//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _RoleChangeOperation_H_
#define _RoleChangeOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOOperation.h>
#include <Utility/PseudoGlobalVariable.h>

//Group = System Operations

/*
Description:
It is via this operation that the PropertyCategory of a duplicated object changes either from a Duplication master 
to a Duplica or vice versa.

Remarks:
The role of a duplicated object may be either a Duplication master or a Duplica and may change during a session 
via a RoleChangeOperation, as detailed below. A RoleChangeOperation is always encapsulated within a 
MasterIDChangeOperation.  

	o	The method DuplicatedObject::OperationBegin is called and the RoleChangeOperation begins,
	o	The role of the duplicated object changes from a Duplica to a Duplication master, or vice versa,
	o	The MasterID is changed to that of the new Duplication master,
	o	The method DuplicatedObject::OperationEnd is called and the RoleChangeOperation ends.

*/
class RoleChangeOperation: public DOOperation {
	//Group=
	public:
		//{secret}
		RoleChangeOperation(DuplicatedObject* pDO, bool bPromotion);
		
		//{secret}
		virtual ~RoleChangeOperation();
		
		//{secret}
		virtual void Trace(Event eEvent) const;
		
		//{secret}
		virtual Type GetType() const {
			return RoleChange;
		}

		/*
		Description:  Returns whether or not the RoleChangeOperation is that of a local Duplica changing 
		into a Duplication master.
		Returns:  true if the RoleChangeOperation is that of a Duplica changing into a Duplication master, 
		false if otherwise.
		*/
		bool IsAPromotion() const {return m_bPromotion;}

		/* 
		Description:  This static method returns the system OperationLock for the RoleChangeOperation.
		
		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
		
		Returns:  A ConcurrentDenialOperationLock that can be used to 
		control the RoleChangeOperation.
		*/
   static ConcurrentDenialOperationLock* GetOperationLock();
		
/*
Description:
Sets the tracing of the RoleChangeOperation to true.
			
Remarks:
To trace the RoleChangeOperation you must first set the TRACE_OPERATION flag with:
		          
       TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to RoleChangeOperation::ClearTraceFlag was
made then you can reenable the RoleChangeOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		
		/*
		Description: Disables the trace of the RoleChangeOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the RoleChangeOperation trace via this method.
					
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

    public:
		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_Begin;

		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_End;

	private:
		//{secret}
		bool m_bPromotion;
		
		//{secret}
		static ConcurrentDenialOperationLock s_lockRoleChange;		
		
		//{secret}
		static bool s_bTraceFlag;

};

#endif
