//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _RMCContext_H_
#define _RMCContext_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/DOHandle.h>
#include <ObjDup/MethodID.h>
#include <Platform/CriticalSection.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/CallContext.h>
#include <Platform/EventHandler.h>

class Event;
class RMCRegister;

// Group=Call Contexts

/*
Summary: This class defines the context of a RMC.
Remarks: Before a RMC is invoked the context of the call must be defined via the 
RMCContext class. Within this class you set the station you wish the method to be
called on and the appropriate flags. You can also obtain information about the 
CallContext::State and CallContext::Outcome of the call. Refer to the Remote Method Calls 
Overview for an example of the complete implementation of RMCs.
See Also: Remote Method Calls Overview, DDL File Syntax 
*/
class RMCContext: public CallContext {
//Group=Type Definitions
	public:
		/*
		Remarks: If no arguments are passed to the constructor, the RMCContext instance will
		initialize the value of the TargetStation to INVALID_DOHANDLE. By default the RMC 
		will be made asynchronously i.e. the thread will keep running while it waits for the
		RMC to return a value or an error. The method CallContext::Wait can be used if the RMC is made 
		asynchronously.

		Parameters: 
		hTargetStation: The station we wish to call the RMC on.
		bSynchronousCall: true if the call is made asynchronously, false if asynchronously.
		*/
		RMCContext(DOHandle hTargetStation=INVALID_DOHANDLE,
				   bool bSynchronousCall=true);
		
		virtual ~RMCContext();

		// {secret}
		MethodID GetTargetMethodID() {return m_idTargetMethod;}
		// {secret}
		DOHandle GetTargetObject() {return m_hTargetObject;}

		// {secret}
		bool PrepareCallMessage(DOHandle hTarget, MethodID id);

		// {secret}
		virtual State ProcessResponse(UserContext ucResponseContext);

		// Return value ptr manipulation.
		// {secret}
		void AddReturnValuePtr(void* pReturnValue);
		// {secret}
		void* GetReturnValuePtr(int iIndex);
		// {secret}
		void ClearReturnValuePtr();

		// {secret}
		virtual void Trace(unsigned long ulTraceFlags);
		// {secret}
		virtual Type GetType() const {return RMC;}

		// {secret}
		Message* GetResponseMessage();

	private:
		// Info filled by the caller - on call initialization.		
		// {secret}
		DOHandle m_hTargetObject;		
		MethodID m_idTargetMethod;

		// Result 
		// {secret}
		std::vector<void*> m_vReturnValuePtr;

		// Temporary ptr.
		// {secret}
		unsigned char* m_pucDummyBuffer;

		Message* m_pResponseMessage;
};
		

#endif
