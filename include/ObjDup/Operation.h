//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _Operation_H_
#define _Operation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/OperationLock.h>
#include <Utility/EREWLock.h>
#include <Utility/CREWLock.h>
#include <Platform/UserContext.h>

//Group = System Operations
/*
Description: Contains information about the various types of Operations possible in $PRODUCTNAME$.

Remarks: The operations in $PRODUCTNAME$ fall under three major categories: DOOperation, 
DataSetOperation, and DupSpaceOperation.  

DOOperation encapsulates the operations performed on duplicated objects: AddToStoreOperation, 
RoleChangeOperation, MasterIDChangeOperation, FaultRecoveryOperation, and RemoveFromStoreOperation.   

A DataSetOperation is an operation that deals with a specific dataset: RefreshOperation and 
BufferRefreshOperation.

A DupSpaceOperation encapsulates operations performed on DuplicationSpace instances: MatchOperation.

The Operation class contains methods that enable the extraction of information about the type 
of operation that it is, if there is a user-defined context associated to the operation and whether 
or not the operation has a lock.
*/
class Operation {
//Group=Type Definitions
	public:

		// This macro is never defined.  It is used only to get around a compilation problem with 
		// DocJet, as Connect and Disconnect cannot be made secret.
		#ifdef FOR_DOC_PURPOSE
		
		//Description: This enumerates the different types of operations that can be called by $PRODUCTNAME$.
		//See Also: _Type
		typedef enum _Type {
			/*see RefreshOperation*/       
			Refresh, 
			/*see BufferRefreshOperation*/ 
			BufferRefresh, 
			/*see RoleChangeOperation*/ 
			RoleChange,
			/*see MasterIDChangeOperation*/ 
			MasterIDChange,
			/*see FaultRecoveryOperation*/  
			FaultRecovery, 
			/*see AddToStoreOperation*/ 
			AddToStore, 
			/*see RemoveFromStoreOperation*/
			RemoveFromStore,
			/*see MatchOperation*/
			Match,
		} Type;

		#else

		typedef enum _Type {
			Refresh, 
			BufferRefresh, 
			RoleChange,
			MasterIDChange,
			FaultRecovery, 
			AddToStore, 
			RemoveFromStore,
			Match,
			Connect,
			Disconnect,
		} Type;

			
		typedef enum _Event {
			Begin, End, BeginDenial, EndDenial
			} Event;	
	
		#endif	

//Group=Operations	
		
		//{secret}
		Operation() {
			m_pCREWLock=NULL;
			m_pEREWLock=NULL;
		}

		//{secret}
		virtual ~Operation() {
		}
		
		//{secret}
		bool AssociateLock(OperationLock<EREWLock>* pLock, bool bLockNow) {
			if (HasALock()) {
				SIGNAL_SYSTEMERROR(SYSTEMERROR_GEN_INVALID_OPERATION,0);
				return false;
			}
			m_pEREWLock=pLock;
			if (bLockNow) {
				Lock();
			}
			return true;
		}
		
		//{secret}
		bool AssociateLock(OperationLock<CREWLock>* pLock) {
			if (HasALock()) {
				SIGNAL_SYSTEMERROR(SYSTEMERROR_GEN_INVALID_OPERATION,0);
				return false;
			}			
			m_pCREWLock=pLock;
			return true;
		}

		//{secret}
		void Lock() {
			if (m_pCREWLock) {
				m_pCREWLock->BeginOperation();
				return;
			}
			if (m_pEREWLock) {
				m_pEREWLock->BeginOperation();
				return;
			}
			SYSTEMCHECK(false); // Has no lock!
		}

		//{secret}
		void Unlock() {
			if (m_pCREWLock) {
				m_pCREWLock->EndOperation();
				return;
			}
			if (m_pEREWLock) {
				m_pEREWLock->EndOperation();
				return;
			}
			SYSTEMCHECK(false); // Has no lock!
		}

		/*
		Description: Returns whether or not an operation has a lock associated with it.
		Remarks: See OperationLock and OperationDenial for more details on the use 
		of locks.
		Returns: true if the operation has a lock associated with it, false if otherwise.
		*/
		bool HasALock();
		
		//{secret}
		virtual void Trace(Event oEvent) const =0;		
		
		/*
		Description: Returns the Type of the operation.
		Returns: The type of operation that has been called. The Type is one of
		Refresh, BufferRefresh, RoleChange, MasterIDChange, FaultRecovery, AddToStore, 
		RemoveFromStore, or Match.

        See Also: Type, _Type
		*/
		virtual Type GetType() const =0;

		/*
		Description: Gets the user-defined value that was set via the method SetUserData.
		Returns: The user-defined value set via the method SetUserData. The value may be either
		an unsigned long, double, or pointer to an object.
		Remarks: The user-defined data should be set when one of the methods DataSet::OperationBegin,
		DuplicatedObject::OperationBegin, or DuplicationSpace::OperationBegin is called and retrieved
		when one of the methods DataSet::OperationEnd, DuplicatedObject::OperationEnd, or 
		DuplicationSpace::OperationEnd is called.
		
Note: The user must ensure that the methods SetUserData and GetUserData are called in 
relation to the same operation.
		
		See Also: SetUserData, UserContext
		*/
		UserContext GetUserData();
		
		/*
		Description: Sets a user-defined value that can be obtained via the method GetUserData.
		Remarks: The user-defined value may be either an unsigned long, double, or pointer to an 
		object. It should be set when one of the methods DataSet::OperationBegin,
		DuplicatedObject::OperationBegin, or DuplicationSpace::OperationBegin is called and retrieved
		when one of the methods DataSet::OperationEnd, DuplicatedObject::OperationEnd, or 
		DuplicationSpace::OperationEnd is called. 
		
Note: The user must ensure that the methods SetUserData and GetUserData are called in 
relation to the same operation.
	
		See Also: GetUserData, UserContext
		*/
		void SetUserData(UserContext uUserData);

		/*
		Description: This method returns the operation type as a string.
		Returns: A string that represents the type of operation.
		Remarks: Use this method to get the operation type as a string. The 
		operation is one of Refresh, BufferRefresh, RoleChange, MasterIDChange, 
		FaultRecovery, AddToStore, RemoveFromStore,	or Match.

        See Also: Type, _Type
		*/
		const TCHAR* GetClassNameString() const;

		// {secret}
		static void SetTraceFlag();
		// {secret}
		static void ClearTraceFlag();



	protected:
		// {secret}
		TCHAR* GetEventString(Event eEvent) const;
		
	private:
		// {secret}
		UserContext m_uUserData;

		//{secret}
		OperationLock<EREWLock>* m_pEREWLock;
		
		//{secret}
		OperationLock<CREWLock>* m_pCREWLock;
};

#endif
