//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _AddToStoreOperation_H_
#define _AddToStoreOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOOperation.h>
#include <Utility/PseudoGlobalVariable.h>

//Group = System Operations

/*
Description:
This DOOperation is performed every time a duplicated object is published or discovered.

Remarks
An object can be added to the duplicated object store as either a Duplication master or a Duplica. 
When an object is published on a station, either by the user or by $PRODUCTNAME$, the object is always added 
as a Duplication master. On the other hand, when an object is discovered it is added as a Duplica.  

As with all DOOperations there is one ConcurrentDenialOperationLock associated with this operation 
and therefore, an AddToStoreOperation may be simultaneously denied by several threads. To lock this operation, 
use the OperationDenial or OperationLock class.  To get a reference to the system lock for
the AddToStoreOperation use the static method AddToStoreOperation::GetOperationLock.

When an object is added to the duplication master store the following sequence of events occurs:
	o	The user calls DuplicatedObject::Create which causes $PRODUCTNAME$ to call the object constructor,
	o	A DOHandle and MasterID are assigned to the object. The methods DuplicatedObject::IsADuplica, DuplicatedObject::IsADuplicationMaster and DuplicatedObject::GetMasterID are now valid,
	o	The user calls DuplicatedObject::Publish,
	o 	The method DuplicatedObject::OperationBegin is called and the AddToStoreOperation begins,
	o	The method DuplicatedObject::InitDO is called,
	o	The duplicated object is added to the duplication master store,
	o	The method DuplicatedObject::OperationEnd is called and the AddToStoreOperation ends.

When an object is added to the duplica store the following sequence of events occurs:
	o	The object constructor is called,
	o	A DOHandle and MasterID are assigned to the object. The methods DuplicatedObject::IsADuplica and DuplicatedObject::IsADuplicationMaster are now valid,
	o	The method DuplicatedObject::OperationBegin is called and the AddToStoreOperation begins,
	o	The datasets of the object are initialized,
	o	The method DuplicatedObject::InitDO is called,
	o	The duplicated object is added to the duplica store,
	o	The method DuplicatedObject::OperationEnd is called and the AddToStoreOperation ends.


*/
class AddToStoreOperation: public DOOperation {
	//Group=
	public:
		//{secret}
		AddToStoreOperation(DuplicatedObject* pDO, bool bDuplicationMasterSelection);
		//{secret}
		virtual ~AddToStoreOperation();

		/*
		Description:  Returns whether or not the AddToStoreOperation is an addition to the
		duplication master store.
		
		Returns:  true if the AddToStoreOperation is a result of a local DuplicatedObject::Publish call, in which 
		case the duplicated object is added to the duplication master store, false if otherwise.
		*/
		bool AddToDuplicationMasterSelection() const {return m_bDuplicationMasterSelection;}
		
		/*
		Description:  Returns whether or not the AddToStoreOperation is an addition to the
		duplica store.
		
		Returns:  true if the AddToStoreOperation is a result of a local discovery of a duplicated object, in which 
		case the duplicated object is added to the duplica store, false if otherwise.
		*/
		bool AddToDuplicaSelection() const {return !m_bDuplicationMasterSelection;}
		//{secret}
		virtual void Trace(Event eEvent) const;
		//{secret}
		virtual Type GetType() const {return AddToStore;}

		/* 
		Description:  This static method returns the system OperationLock for the AddToStoreOperation.
		
		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
		
		Returns:  A ConcurrentDenialOperationLock that controls the AddToStoreOperation.
		*/
		static ConcurrentDenialOperationLock* GetOperationLock();
		
/*
Description: Sets the tracing of the AddToStoreOperation to true.
			
Remarks:
To trace the AddToStoreOperation you must first set the TRACE_OPERATION flag with:
          
          TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to AddToStoreOperation::ClearTraceFlag 
was made then you can reenable the AddToStoreOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		/*
		Description: Disables the trace of the AddToStoreOperation.
					
		Remarks: Use this method to reset a trace flag to inactive. To trace 
		operations you must set the TRACE_OPERATION flag. You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the AddToStoreOperation trace via this method.
					
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
        static void RegisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

		//{secret}
        static void UnregisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

		//{secret}
        virtual CallbackList<DOOperation*>* GetCallbackList(Operation::Event operationEvent);

		//{secret}
		bool Execute(Message* pMessageToInitializeFrom=NULL);

	private:
		//{secret}
		bool m_bDuplicationMasterSelection;
		//{secret}
		static ConcurrentDenialOperationLock s_lockAddToStore;		
		//{secret}
		static bool s_bTraceFlag;		

        //typename CallbackList<DOOperation*>;
		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_Begin;
          
        //{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_End;

};

#endif
