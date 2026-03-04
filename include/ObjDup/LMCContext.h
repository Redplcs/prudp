//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _LMCContext_H_
#define _LMCContext_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/DOHandle.h>
#include <ObjDup/MethodID.h>
#include <Platform/CriticalSection.h>
#include <Utility/PseudoGlobalVariable.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/RMCContext.h>

#include <map>

class LMCContext {
	public:

		LMCContext(RMCContext::ID idRMC, DOHandle hSourceStation, unsigned char ucFlags, 
				   DOHandle hTargetObject, MethodID idTargetMethod, Message* pCallMessage);
		~LMCContext();

		void Trace(unsigned long ulTraceFlags=TRACE_ALWAYS);
		void DispatchCall();
		void PerformLocalCall();

		// Access to members.		
		RMCContext::ID GetRMCID() {return m_idRMC;}
		unsigned char GetOutcome() {return m_ucOutcome;}
		DOHandle GetSourceStation() {return m_hSourceStation;}
		
		MethodID GetTargetMethodID() {return m_idTargetMethod;}
		DuplicatedObject* GetTargetObject();
		
		Message* GetCallMessage();

		void CreateResponseHeader();
		void AddFailureDetails();
		Message* PrepareSuccessMessage();
		void SendResponse();

	private:
		// Source info.
		RMCContext::ID m_idRMC;		
		DOHandle m_hSourceStation;		

		// Method info.
		DuplicatedObject::Ref m_refTargetObject;
		MethodID m_idTargetMethod;
		Message* m_pCallMessage;
		Message* m_pResponseMessage;

		// Caller flags.
		unsigned char m_ucFlags;

		unsigned char m_ucOutcome;
};

#endif
