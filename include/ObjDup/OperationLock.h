//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _OperationLock_H_
#define _OperationLock_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/CREWLock.h>
#include <Utility/EREWLock.h>

// Group = System Operations
/*
Description:  
Operation locks are used by $PRODUCTNAME$ and can be used by the developer to control duplicated object operations.

Remarks:
Operation locks can be used by the developer to control duplicated object operations and are instigated via the 
OperationLock class. In $PRODUCTNAME$ there are two kinds of locks: ConcurrentDenialOperationLock and 
ExclusiveDenialOperationLock. Duplicated object and duplication space operations (DOOperation, DupSpaceOperation) 
use ConcurrentDenialOperationLocks and dataset operations (DataSetOperation) use ExclusiveDenialOperationLocks. 
Operation locks may be used to ensure that particular events occur in a specific order, or that an operation or group of
methods is executed atomically. 
 
In $PRODUCTNAME$, there are two manners in which to implement locks: via the OperationDenial class or the 
OperationLock class. The first manner is via the construction and destruction of an instance of the OperationDenial class,
whereas the second way is to call the methods OperationLock::BeginOperationDenial and OperationLock::EndOperationDenial 
directly. The advantage of using the OperationDenial class is that inadvertent deadlocks will be avoided as the lock 
is automatically destroyed. The advantage of using OperationLock methods directly is the ability to create and destroy 
the lock without being limited by scope. The time that an operation is locked should always be minimized because any 
network messages will be queued until the operation is unlocked. A typical use for a lock is to prevent a dataset 
being modified while a correction model is being calculated in the case of local corrections and continuity breaks.
*/
template <class Lock> class OperationLock {
	//Group=
	public:
		//{secret}
		OperationLock() {}
		
		//{secret}
		~OperationLock() {}

		//{secret}
		void BeginOperation() {			
			m_oOperationLock.BeginWriting();
		}
			
		//{secret}	
		void EndOperation() {
			m_oOperationLock.EndWriting();
		}
		
		/*
		Description:  Activate the lock for a particular Operation.
		Remarks: Get the lock by using one of: DataSet::GetBufferRefreshLock,
		AddToStoreOperation::GetOperationLock, MasterIDChangeOperation::GetOperationLock,
		RoleChangeOperation::GetOperationLock, FaultRecoveryOperation::GetOperationLock, 
		AddToStoreOperation::GetOperationLock, RemoveFromStoreOperation::GetOperationLock, 
		MatchOperation::GetOperationLock.  In order to avoid deadlocking the system,
		make sure to unlock with EndOperationDenial.
		*/
		void BeginOperationDenial() {
			m_oOperationLock.BeginReading();
		}

		/*
		Description: End the lock for a particular Operation.
		Remarks: Get the lock by using one of: DataSet::GetBufferRefreshLock,
		AddToStoreOperation::GetOperationLock, MasterIDChangeOperation::GetOperationLock,
		RoleChangeOperation::GetOperationLock, FaultRecoveryOperation::GetOperationLock, 
		RemoveFromStoreOperation::GetOperationLock, MatchOperation::GetOperationLock.
		*/
		void EndOperationDenial() {
			m_oOperationLock.EndReading();
		}

	protected:
		//{secret}
		Lock m_oOperationLock;
};
// Group = System Operations

/*
Description:
Defines a ConcurrentDenialOperationLock as a Concurrent Read Exclusive Write Lock type.

Remarks:
Concurrent Read Exclusive Write means that many threads may concurrently lock, but only one of them can proceed at a 
time.  There are six of these locks in $PRODUCTNAME$, one for each of the DOOperations (AddToStoreOperation, 
MasterIDChangeOperation, RoleChangeOperation, FaultRecoveryOperation, RemoveFromStoreOperation), and one for 
the DupSpaceOperation MatchOperation.  Since each DOOperation and DupSpaceOperation uses a 
ConcurrentDenialOperationLock, an operation of the class DOOperation and DupSpaceOperation may be 
simultaneously denied by several threads. 
*/
typedef OperationLock<CREWLock> ConcurrentDenialOperationLock;

/*
Description:
Defines an ExclusiveDenialOperationLock as an Exclusive Read Exclusive Write Lock type.

Remarks:
There is an EREW lock for each bufferred dataset member of a doclass.  Exclusive Read Exclusive Write means in this
case that only a single thread can lock or proceed at a single time.  An operation that uses an 
ExclusiveDenialOperationLock may only be denied by one thread at any given time. A reference to a
ExclusiveDenialOperationLock lock is received via the method DataSet::GetBufferRefreshLock.
*/
typedef OperationLock<EREWLock> ExclusiveDenialOperationLock;

#endif
