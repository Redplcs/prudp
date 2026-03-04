//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _RefreshOperation_H_
#define _RefreshOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSetOperation.h>

class DuplicatedObject;

//Group = System Operations

/*
Description:
This DataSetOperation is performed whenever DataSet::Refresh is called on a dataset of a Duplica.

Remarks:
The RefreshOperation can only be performed on a Duplica and is the only system operation that is not automatically locked while in progress. 
If the operation is performed on a buffered dataset then the BufferRefreshOperation is denied while a RefreshOperation is in progress.
If the dataset is unbuffered the following sequence of events occurs:

	o	The method DataSet::OperationBegin is called as the result of a network message and the RefreshOperation starts,
	o	The dataset members of the Duplica are refreshed from the Duplication master,
	o	The method DataSet::OperationEnd is called and the RefreshOperation ends.

If the dataset is buffered the following sequence of events occurs:

	o	The method DataSet::OperationBegin is called as the result of the user calling the method DataSet::Refresh and the RefreshOperation starts,
	o	The BufferRefreshOperation is denied,
	o	The dataset members of the Duplica are refreshed from the buffer,
	o	The BufferRefreshOperation is permitted,
	o	The method DataSet::OperationEnd is called and the RefreshOperation ends.

*/
class RefreshOperation: public DataSetOperation {
	//Group=
	public:
		//{secret}
		RefreshOperation(DataSet* pDataSet, bool bInitialRefresh, DuplicatedObject *pDO): DataSetOperation(pDataSet, pDO) {
			m_bInitialRefresh=bInitialRefresh;
		}
		
		//{secret}
		~RefreshOperation() {}
		
		//{secret}
		virtual void Trace(Event eEvent) const;
		
		//{secret}		
		virtual Type GetType() const {
			return Refresh;
		}

		/*
		Description:  Returns whether or not the RefreshOperation is the first refresh operation for this dataset.
		
		Returns:  true if the RefreshOperation is the initial one for this dataset, false if otherwise.
		*/
		bool InitialRefresh() const {return m_bInitialRefresh;}
		
/*
Description:
Sets the tracing of the RefreshOperation to true.
			
Remarks:
To trace the RefreshOperation you must first set the TRACE_OPERATION flag with:
		          
        TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
		
which by default sets all of the Operation flags. However, if the call to RefreshOperation::ClearTraceFlag was
made then you can reenable the RefreshOperation trace via this method.          
		
See Also: ClearTraceFlag, TRACE_OPERATION
*/
		static void SetTraceFlag() {s_bTraceFlag=true;}
		
		
		/*
		Description: Disables the trace of the RefreshOperation.
					
		Remarks: Use this method to reset a trace flag to inactive.   To trace 
		operations you must set the TRACE_OPERATION flag.   You can then decide
		which specific operations you want traced by disabling specific operation
		traces.  Disable the RefreshOperation trace via this method.
					
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
