//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _CallRegister_H_
#define _CallRegister_H_

#include <ObjDup/ObjDupDecl.h>

#include <Utility/ItemRegister.h>
#include <ObjDup/CallContext.h>

#define INVALID_CONTEXT_ID		0

class CallRegister: public ItemRegister<CallContext> {
	public:

		CallRegister();
		~CallRegister();

		static CallRegister& GetInstanceRef();

		void Start();
		void CheckExpiredCalls(int iDummy);

		virtual void Register(CallContext* pContext);
		virtual void Unregister(CallContext* pContext);

		void Trace(unsigned long ulFlags=TRACE_ALWAYS);
		
		void CancelCallToStation(DOHandle hStation);
		void QueueCancelCallToStation(DOHandle hStation);
		void CancelPendingCalls();

		void CancelExpiredCalls();

		// Accessors for FetchContextes.
		void SignalRelevantFetchContextes(DOHandle hFetchedObject);
		bool FetchInProgress(DOHandle hFetchedObject, DOHandle hTargetStation=INVALID_DOHANDLE);

		// Accessors for MigrationContextes.
		bool MigrationInProgress(DOHandle hMigratingObject, DOHandle hTargetStation=INVALID_DOHANDLE);

	private:

		CallContext::ID GetNextID();

	private:
		
		CallContext::ID m_idNextValid;
};

#endif
