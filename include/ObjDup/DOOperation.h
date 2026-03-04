//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _DOOperation_H_
#define _DOOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/Operation.h>
#include <ObjDup/DOHandle.h>
#include <Utility/CallbackList.h>

// Used for PseudoGlobalVariable definition of CallbackLists
// {Secret}
typedef CallbackList<DOOperation*> CallbackListOfDOOperation;


//Group = System Operations
/*
Description:
DOOperation encapsulates operations done on duplicated objects. 

Remarks:
The types of DuplicatedObject operations are AddToStore, RoleChange, MasterIDChange,
FaultRecovery, and RemoveFromStore.  

*/
class DOOperation: public Operation {
//Group=Operations	
	public:
		//{secret}
		DOOperation(DuplicatedObject* pDO, bool bCreateRef=true);
		//{secret}
		virtual ~DOOperation();
		//{secret}
		void SetAutomaticCalls();

		//{secret}
		void CallOperationBegin();		
		//{secret}
		void CallOperationEnd();

		//{secret}
		void CreateRef();
		
/*
Description:
Returns the DOHandle of the duplicated object that is associated with this operation.
		
Returns:
A DOHandle to the DuplicatedObject instance that is associated with the operation.
		
See Also:
GetAssociatedDO, DOHandle, DuplicatedObject
*/
		DOHandle GetAssociatedDOHandle() const {return m_hDO;}
	
/*
Description:
Returns the pointer to a DuplicatedObject instance that is associated with this operation.
		
Returns:
A DuplicatedObject pointer to the instance that is associated with the operation.
		
See Also:
GetAssociatedDOHandle, DuplicatedObject
*/
		DuplicatedObject* GetAssociatedDO() const {return m_pDO;}

		//{secret}
        virtual CallbackList<DOOperation*>* GetCallbackList(Operation::Event operationEvent) = 0;

	protected:

		bool m_bAutomaticCalls;
		DuplicatedObject::Ref* m_pDORef;
		DOHandle m_hDO;
		DuplicatedObject* m_pDO;

#ifdef _DEBUG_CHECK
		bool m_bOpBeginCalled;
		bool m_bOpEndCalled;
#endif
};

#endif
