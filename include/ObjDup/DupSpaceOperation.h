//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _DupSpaceOperation_H_
#define _DupSpaceOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/Operation.h>
class DuplicationSpace;


//Group = System Operations
/*
Description: DupSpaceOperation encapsulates operations done on DuplicationSpace 
instances.
Remarks: The only type of DuplicationSpace operation is the Match operation.
See Also: MatchOperation
*/
class DupSpaceOperation: public Operation {
//Group=Operations	
	public:
		//{secret}
		DupSpaceOperation(DuplicationSpace* pDupSpace);
		//{secret}
		virtual ~DupSpaceOperation();

		/*
		Description: Returns a pointer to the DuplicationSpace instance that is associated with 
		this operation.
		Returns: A DuplicationSpace pointer to the duplication space instance associated with the operation.
		See Also: MatchOperation
		*/
		DuplicationSpace* GetAssociatedDupSpace() {return m_pDupSpace;}

	protected:	
		//{secret}	
		void CallOperationBegin();	
		//{secret}
		void CallOperationEnd();

	protected:
		DuplicationSpace* m_pDupSpace;
	private:
#ifdef _DEBUG_CHECK
		bool m_bOpBeginCalled;
		bool m_bOpEndCalled;
#endif
};

#endif
