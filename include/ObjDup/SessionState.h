//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, SessionState.h

#ifndef _SessionState_H_
#define _SessionState_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/SessionStateDDL.h>
#include <Utility/PseudoGlobalVariable.h>

class Operation;

class SessionState: public DATASET(SessionState) {
	public:
		SessionState();
		~SessionState() {};

		void OperationEnd(const Operation* pOperation);

		void SetState(unsigned long ulNewState);
		unsigned long GetState();

		// The persistant state is the session state, but remains
		// valid before the object construction, and also after its
		// destruction.
		static unsigned long GetPersistantState();

	private:

		static PseudoGlobalVariable<unsigned long> s_ulPersistantSystemState;
};

#endif
