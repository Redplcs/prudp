//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _OperationDenial_H_
#define _OperationDenial_H_

//Group = System Operations
/*
Description:
This class can be used to temporarily deny one of the DataSetOperation, DOOperation or DupSpaceOperation on a particular 
duplicated object, one of its datasets or an entire DuplicationSpace.

Remarks:  
In $PRODUCTNAME$, there are two manners in which to implement locks: via the OperationDenial class or 
the OperationLock class. The first is via the construction and destruction of an instance of the OperationDenial 
class.  Upon construction, the OperationDenial instance calls the method OperationLock::BeginOperationDenial 
and upon destruction it calls OperationLock::EndOperationDenial. The OperationDenial instance is automatically 
destroyed with a return or the end of the block within which it was created.  An example of the implementation of 
an operation denial is given below. In this case we prevent the buffer of a buffered dataset being 
refreshed while the local correction model is being calculated. 

           if (g_bDuplicaCorrections && IsADuplica()) {
                 // Prevent refreshes while the local correction model is 
                 // being calculated
                 OperationDenial oDenial(m_dsPos.GetBufferRefreshLock());
                 if (CollisionOccurs()) {
                 // Calculate local correction
                 }
          }

*/
class OperationDenial {
	// Group=
	public:	
		/*
		Description:
		Creates an OperationDenial for a particular dataset operation or duplicated object operation.
		
		Parameters:
		pLock: The ExclusiveDenialOperationLock or ConcurrentDenialOperationLock that is to be used for the denial.  
		strReason: An optional parameter that specifies the reason for the denial.
		
		Remarks:  In order to lock a DataSetOperation pass the ExclusiveDenialOperationLock that you can get for 
		each bufferred dataset member with the method DataSet::GetBufferRefreshLock.  Alternatively,
		provide one of the ConcurrentDenialOperationLocks that is associated with each possible $PRODUCTNAME$ DOOperation, 
		using one of the following static methods:  AddToStoreOperation::GetOperationLock,
		FaultRecoveryOperation::GetOperationLock, MasterIDChangeOperation::GetOperationLock,
		RoleChangeOperation::GetOperationLock, RemoveFromStoreOperation::GetOperationLock, or
		MatchOperation::GetOperationLock
		*/	
		OperationDenial(OperationLock<EREWLock>* pLock, TCHAR* strReason=NULL) {
			pLock->BeginOperationDenial();
			m_pEREWLock=pLock;
			m_pCREWLock=NULL;
		}
		OperationDenial(OperationLock<CREWLock>* pLock, TCHAR* strReason=NULL) {
			pLock->BeginOperationDenial();
			m_pEREWLock=NULL;
			m_pCREWLock=pLock;
		}
		
		/*
		Description:  Destroys an OperationDenial instance.
		
		Remarks:  An OperationDenial instance is destroyed automatically when the execution
		leaves the block in which it was created.
		*/
		~OperationDenial() {
			if (m_pEREWLock) {m_pEREWLock->EndOperationDenial();}
			if (m_pCREWLock) {m_pCREWLock->EndOperationDenial();}
		}
	private:
		//{secret}
		OperationLock<EREWLock>* m_pEREWLock;
		//{secret}
		OperationLock<CREWLock>* m_pCREWLock;
};

#endif
