//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _ConnectOperation_H_
#define _ConnectOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/StationOperation.h>
#include <Utility/PseudoGlobalVariable.h>

//Group = System Operations

/*
Description:
This DOOperation is performed every time a duplicated object is published or discovered.

Remarks
An object can be added to the duplicated object store as either a duplication master or a duplica. 
When an object is published on a station, either by the user or by $PRODUCTNAME$, the object is always added 
as a duplication master. On the other hand, when an object is discovered it is added as a duplica.  

As with all DOOperations there is one ConcurrentDenialOperationLock associated with this operation 
and therefore, an ConnectOperation may be simultaneously denied by several threads. To lock this operation, 
use the OperationDenial or OperationLock class.  To get a reference to the system lock for
the ConnectOperation use the static method ConnectOperation::GetOperationLock.

When an object is added to the duplication master store the following sequence of events occurs:
	o	The user calls DuplicatedObject::Create which causes $PRODUCTNAME$ to call the object constructor.
	o	A DOHandle and MasterID are assigned to the object. The methods DuplicatedObject::IsADuplica, DuplicatedObject::IsADuplicationMaster and DuplicatedObject::GetMasterID are now valid.
	o	The user calls DuplicatedObject::Publish.
	o 	The method DuplicatedObject::OperationBegin is called and the ConnectOperation begins
	o	The method DuplicatedObject::InitDO is called
	o	The duplicated object is added to the duplication master store
	o	The method DuplicatedObject::OperationEnd is called and the ConnectOperation ends

When an object is added to the duplica store the following sequence of events occurs:
	o	The object constructor is called
	o	A DOHandle and MasterID are assigned to the object. The methods DuplicatedObject::IsADuplica and DuplicatedObject::IsADuplicationMaster are now valid
	o	The method DuplicatedObject::OperationBegin is called and the ConnectOperation begins
	o	The datasets of the object are initialized
	o	The method DuplicatedObject::InitDO is called
	o	The duplicated object is added to the duplica store
	o	The method DOCtrlInterface::DiscoveryEvent is called
	o	The method DuplicatedObject::OperationEnd is called and the ConnectOperation ends


*/
class ConnectOperation: public StationOperation {
	//Group=
	public:
		//{secret}
		ConnectOperation(Station* pStation, bool bDirectConnection);
		//{secret}
		virtual ~ConnectOperation();

		// TODO: Eventually document.
		bool EstablishDirectConnection() const {return m_bDirectConnection;}
		
		// TODO: Eventually document.
		bool EstablishRoute() const {return !m_bDirectConnection;}
		
		//{secret}
		virtual void Trace(Event eEvent) const;
		//{secret}
		virtual Type GetType() const {return Connect;}

		/* 
		Description:  This static method returns the system OperationLock for the ConnectOperation.
		
		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
		
		Returns:  A ConcurrentDenialOperationLock that controls the ConnectOperation.
		*/
		static ConcurrentDenialOperationLock* GetOperationLock();
		
/*
Description:
Sets the tracing of ConnectOperation to true.
			
Remarks:
To trace the ConnectOperation you must first set the TRACE_OPERATION flag with:
          
          TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags.  If the call to ConnectOperation::ClearTraceFlag was
made, however, then you can reenable the ConnectOperation trace with this SetTraceFlag method.          
		
See Also:
ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
/*
Description:
Disables the trace of ConnectOperation
			
Remarks:
Use this method to reset a trace flag back to inactive.   To trace 
operations you must set the TRACE_OPERATION flag.   You can then decide
which specific operations you want traced by disabling specific operation
traces.  Disable the ConnectOperation trace using this method.
			
See Also:
SetTraceFlag, TRACE_OPERATION			
*/
		static void ClearTraceFlag() {s_bTraceFlag=false;}
		
/*
Description:
Returns whether or not the trace flag for this operation is set.
		
Returns:
true if the trace flag for this operation is set, false if otherwise.
		
See Also:
SetTraceFlag, TRACE_OPERATION, ClearTraceFlag
*/
		static bool GetTraceFlag() {return s_bTraceFlag;}

		//{secret}
        static void RegisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

		//{secret}
        static void UnregisterCallback(CallbackRoot<DOOperation*> *pCallback, Operation::Event operationEvent);

		//{secret}
        virtual CallbackList<DOOperation*>* GetCallbackList(Operation::Event operationEvent);

		//{secret}
		bool Execute();
		// {secret}
		bool QueueExecution();

	private:
		//{secret}
		bool m_bDirectConnection;
		//{secret}
		static ConcurrentDenialOperationLock s_lockConnect;		
		//{secret}
		static bool s_bTraceFlag;		

        //typename CallbackList<DOOperation*>;
		//{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_Begin;
          
        //{secret}
        static PseudoGlobalVariable<CallbackListOfDOOperation> s_oCallbackList_End;

};

#endif
