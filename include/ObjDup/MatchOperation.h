//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _MatchOperation_H_
#define _MatchOperation_H_

#include <ObjDup/DupSpaceOperation.h>
#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOHandle.h>
#include <Platform/Time.h>

class DuplicatedObject;

//Group = System Operations
/*
Description:
Match operation is called by $PRODUCTNAME$ as a result of the calls DuplicationSpace::PSMatch 
and DuplicationSpace::CellMatch.

Remarks:
When the MatchOperation is called on a Duplication space the following sequence of events occurs:

	o	The method DuplicationSpace::OperationBegin is called and the MatchOperation begins,
	o	The appropriate DuplicationSpace::PSMatch or DuplicationSpace::CellMatch sequence is called,
	o	According to the return value of the DuplicationSpace::PSMatch or DuplicationSpace::CellMatch function the AddToStoreOperation or RemoveFromStoreOperation may be triggered,
	o	The method DuplicationSpace::OperationEnd is called and the MatchOperation ends.

Use the GetOperationLock method to obtain a lock on the matching activity of a DuplicationSpace.
A reference to this lock can be used along with the OperationDenial class to lock this operation.
*/
class MatchOperation: public DupSpaceOperation {
	
//Group=	
	public:

		// This macro is never defined.  It is used only to get around a compilation problem with 
		// DocJet, as _MatchTypes cannot be made secret.
		#ifdef FOR_DOC_PURPOSE
		
		#else
		
		typedef enum _MatchType {
			CheckRelevance, 
			MatchSingleObject,
			MatchAcrossPublishers, MatchAcrossSubscribers,
			MatchAcrossCells, MatchAcrossPS,
			Dummy} MatchType;
		
		#endif

		//{secret}
		MatchOperation(DuplicationSpace* pDupSpace, MatchType eMatchType, 
					   DOHandle hDOArgument=INVALID_DOHANDLE);
		//{secret}
		virtual ~MatchOperation();

		//{secret}
		const TCHAR* GetClassName(DuplicatedObject* pDO) const;
		//{secret}
		virtual void Trace(Event eEvent) const;
		//{secret}
		virtual Type GetType() const {return Match;}

//Group=Operations		
		/* 
		Description:  This static method returns the system OperationLock for the MatchOperation.
		
		Remarks:  A reference to this lock can be used along with the OperationDenial class to lock
		this operation.
		
		Returns:  A ConcurrentDenialOperationLock that controls the MatchOperation.
		*/
		static ConcurrentDenialOperationLock* GetOperationLock();
		
/*
Description:
Sets the tracing of the MatchOperation to true.
			
Remarks:
To trace the MatchOperation you must first set the TRACE_OPERATION flag with:
		          
       TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to MatchOperation::ClearTraceFlag
was made then you can reenable the MatchOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		/*
		Description: Disables the trace of the MatchOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the MatchOperation trace via this method.
					
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
		static void Queue(DuplicationSpace* pDupSpace, MatchType eMatchType, 
						  DOHandle hDOArgument=INVALID_DOHANDLE, TimeInterval tiWhenFromNow=0);
		//{secret}
		static void Execute(DuplicationSpace* pDupSpace, MatchType eMatchType, 
							DOHandle hDOArgument=INVALID_DOHANDLE);

		//{secret}
		void ExecuteOperation(int iDummy=0);

	private:
		static ConcurrentDenialOperationLock s_lockMatch;		
		static bool s_bTraceFlag;
		MatchType m_eMatchType;
		DOHandle m_hDOArgument;
};

#endif
