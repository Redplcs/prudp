//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _MasterIDChangeOperation_H_
#define _MasterIDChangeOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOOperation.h>
#include <Utility/PseudoGlobalVariable.h>

//Group = System Operations

/*
Description:
This DOOperation occurs whenever a migration of the Duplication master of a duplicated object occurs.

Remarks:
A MasterID change will occur as a result of the migration of the Duplication master of a duplicated object. 
If the object on the local station is a Duplica and remains a Duplica, only a MasterIDChangeOperation is performed.  
If as a result of the migration the duplicated object changes its role on the local station, then a RoleChangeOperation 
will also occur.  When only a MasterIDChangeOperation occurs the following sequence of events occurs:

	o	The method DuplicatedObject::OperationBegin is called and the MasterIDChangeOperation begins,
	o	The MasterID is changed to that of the new Duplication master,
	o	The method DuplicatedObject::OperationEnd is called and the MasterIDChangeOperation ends.

When a RoleChangeOperation is encapsulated within a MasterIDChangeOperation the following sequence of events occurs:

	o	The method DuplicatedObject::OperationBegin is called and the MasterIDChangeOperation begins,
	o	The method DuplicatedObject::OperationBegin is called and the RoleChangeOperation begins,
	o	The role of the duplicated object changes from a Duplica to a Duplication master, or vice versa,
	o	The MasterID is changed to that of the new Duplication master,
	o	The method DuplicatedObject::OperationEnd is called and the RoleChangeOperation ends,
	o	The method DuplicatedObject::OperationEnd is called and the MasterIDChangeOperation ends.

*/
class MasterIDChangeOperation: public DOOperation {
	//Group=
	public:
		//{secret}
		MasterIDChangeOperation(DuplicatedObject* pDO, unsigned long ulOldID, unsigned long ulNewID);
		MasterIDChangeOperation(DuplicatedObject* pDO, DOHandle hOldMaster, DOHandle hNewMaster);
		
		//{secret}
		virtual ~MasterIDChangeOperation();
		
		//{secret}
		virtual void Trace(Event eEvent) const;
		
		//{secret}
		virtual Type GetType() const {return MasterIDChange;}
		
		/*
		Description:  Returns the StationID of the station that will give up the Duplication master role of
		an object with this operation.
		
		Returns:  The StationID of the station that gave up the Duplication master instance of a DuplicatedObject.
		*/
		unsigned long GetOldID() const;

		/*
		Description:  Returns the DOHandle of the station that will give up the Duplication master role of
		an object with this operation.

		Returns:  The DOHandle of the station that gave up the Duplication master instance of a DuplicatedObject.
		*/
		DOHandle GetOldStation() const;

		/*
		Description:  Returns the StationID of the station that will take over the Duplication master role of
		an object.
		
		Returns:  The StationID of the station that became the new Duplication master for a DuplicatedObject.
		*/
		unsigned long GetNewID() const;

				/*
		Description:  Returns the DOHandle of the station that will take over the Duplication master role of
		an object.

		Returns:  The DOHandle of the station that became the new Duplication master for a DuplicatedObject.
		*/
		DOHandle GetNewStation() const;

		/* 
		Description:  This static method returns the system OperationLock for the MasterIDChangeOperation.
		
		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
		
		Returns:  A ConcurrentDenialOperationLock that controls the MasterIDChangeOperation.
		*/
		static ConcurrentDenialOperationLock* GetOperationLock();
		
/*
Description:
Sets the tracing of the MasterIDChangeOperation to true.
			
Remarks:
To trace the MasterIDChangeOperation you must first set the TRACE_OPERATION flag with:
		          
        TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to MasterIDChangeOperation::ClearTraceFlag
was made then you can reenable the MasterIDChangeOperation trace viathis method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		
		/*
		Description: Disables the trace of the MasterIDChangeOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the MasterIDChangeOperation trace via this method.
					
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
		unsigned long m_ulOldID;
		
		//{secret}
		unsigned long m_ulNewID;
		
		//{secret}
		static ConcurrentDenialOperationLock s_lockMasterIDChange;
		
		//{secret}
		static bool s_bTraceFlag;

		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_Begin;

		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_End;

};

#endif
