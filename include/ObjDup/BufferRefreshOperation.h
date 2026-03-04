//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _BufferRefreshOperation_H_
#define _BufferRefreshOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSetOperation.h>

class DuplicatedObject;

//Group = System Operations
/*
Description:
Refreshes the buffer of a buffered dataset member of a Duplica.

The BufferRefreshOperation can only be performed on a buffered dataset of a Duplica.

	o	The method DataSet::OperationBegin is called as the result of a network message and the BufferRefreshOperation starts,
	o	The dataset members of the buffer of the Duplica are refreshed from the Duplication master,
	o	The method DataSet::OperationEnd is called and the BufferRefreshOperation ends.
*/
class BufferRefreshOperation: public DataSetOperation {	
	//Group=
	public:
		//{secret}
		BufferRefreshOperation(DataSet* pDataSet, bool bInitialRefresh, OperationLock<EREWLock>* pLock, DuplicatedObject *pDO): DataSetOperation(pDataSet, pDO) {
			m_bInitialRefresh=bInitialRefresh;
			AssociateLock(pLock, false);
			Lock();
		}
		//{secret}
		~BufferRefreshOperation() {
			Unlock();
		}

		//{secret}
		virtual void Trace(Event eEvent) const;
		
		//{secret}
		virtual Type GetType() const {
			return BufferRefresh;
		}

		/*
		Description:  Returns whether or not the BufferRefreshOperation is the first refresh operation for this 
		dataset buffer.
		
		Returns:  true if the BufferRefreshOperation is the initial one for this dataset, false if otherwise.
		*/
		bool InitialRefresh() const {return m_bInitialRefresh;}
		
/*
Description:
Sets the tracing of the BufferRefreshOperation to true.
			
Remarks:
To trace the BufferRefreshOperation you must first set the TRACE_OPERATION flag with:
		          
        TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to BufferRefreshOperation::ClearTraceFlag
was made then you can reenable the BufferRefreshOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
		*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		
		/*
		Description: Disables the trace of the BufferRefreshOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the BufferRefreshOperation trace via this method.
					
		See Also: SetTraceFlag, TRACE_OPERATION			
		*/
		static void ClearTraceFlag() {s_bTraceFlag=false;}
		
		/*
		Description: Returns whether or not the trace flag for this operation is set.
				
		Returns: true if the trace flag for this operation is set, false if otherwise.
				
		See Also: SetTraceFlag, TRACE_OPERATION, ClearTraceFlag
		*/
		static bool GetTraceFlag() {return s_bTraceFlag;}

	private:
		//{secret}
		bool m_bInitialRefresh;
		
		//{secret}		
		static bool s_bTraceFlag;
};

#endif
