//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _CallContext_H_
#define _CallContext_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/DOHandle.h>
#include <Platform/CriticalSection.h>
#include <ObjDup/DuplicatedObject.h>
#include <Platform/EventHandler.h>
#include <Utility/CallbackList.h>

#include <list>

class Event;
class RMCRegister;

// Group=Call Contexts

/*
Summary: This class defines the context of a call.
Remarks: This class is used to define the call context of calls made to Fetch and Migrate
duplicated objects and of RMCs.
*/
class CallContext {
//Group=Type Definitions
	public:
		// {secret}
		typedef unsigned long ID;

		//Description: This enumerates the different Types of call contexts that can be called by $PRODUCTNAME$. 
		//See Also: _Type
		typedef enum _Type {
			//A call to perform a Remote Method Call.
			RMC,
			//A call to fetch a Duplica.
			FetchCall,
			//A call to migrate a Duplication master.
			MigrationCall,
		} Type;
		
		// Description: This enumerates the various States of a CallContext.
		// See Also: _State,
		typedef enum _State {
			// The call can be called. When this is done the State will change to
			// CallInProgress. If Reset is called when the State is one of CallSuccess,
			// CallFailure, or CallCancelled the State will change to
			// Available.
			Available, 
			// The call is in progress. The method Cancel may be called.
			CallInProgress, 
			// The call has terminated. The method Reset may be called.
			CallSuccess, 
			// The call failed. The method Reset may be called.
			CallFailure, 
			// The call was cancelled by the user via the method Cancel. The method 
			// Reset may be called.
			CallCancelled} State;
		
		
		// This macro is never defined.  It is used only to get around a compilation problem with 
		// DocJet, as DeleteOnCompletion and ErrorCallTimeout cannot be made secret.
		#ifdef FOR_DOC_PURPOSE

		// Description: This enumerates the various Flags that may be used with a CallContext.
		// See Also: _Flags
		typedef enum _Flags {
			// The call will be synchronous i.e. the system will wait for the call to return
			// a value or an error before performing the next task.
			SynchronousCall=1,
			// The call will only be called on an object that is a Duplication master.
			TargetObjectMustBeMaster=2,
			// The call cannot be cancelled. This flag is only valid if the context is MigrationContext.
			CancellationNotAllowed=4,
		} Flags;

		// Description: This enumerates the various Outcomes that a call may return.
		// See Also: _Outcome
		typedef enum _Outcome {
			// The call terminated successfully.
			Success,
			// The TargetStation of the call could not be reached.
			ErrorStationNotReached,
			// The call was invoked but the TargetStation was disconnected before a response was received.
			ErrorTargetStationDisconnect,
			// The call was invoked but the local station is leaving the session and a response 
			// will never be received.
			ErrorLocalStationLeaving,
			// The object on which the call was called could not be found on the TargetStation of the call. 
			ErrorObjectNotFound, 
			// The object was found, but the role of the object was not
			// the one expected.  For example, this occurs if the flag
			// TargetObjectMustBeMaster was set but a RMC was called
			// on a Duplica instead of a Duplication master.
			ErrorInvalidRole,
			// The method invocation of a RMC failed.  This can be caused by
			// conflicting versions of the DDL between the caller and the
			// callee. This outcome is only valid if the context is a RMCContext.
			ErrorRMCDispatchFailed,
			// The migration of an object is in progress. This outcome is only valid if the context 
			// is a MigrationContext.
			ErrorMigrationInProgress,
			// The call has not yet terminated and therefore, the outcome is not known.
			UnknownOutcome,
		} Outcome;

		#else
		
		typedef enum _Flags {
					SynchronousCall=1,
					TargetObjectMustBeMaster=2,
					CancellationNotAllowed=4,
					DeleteOnCompletion=8,
		} Flags;

	
		typedef enum _Outcome {
			Success,
			ErrorStationNotReached,
			ErrorTargetStationDisconnect,
			ErrorLocalStationLeaving,
			ErrorObjectNotFound, 
			ErrorInvalidRole,
			ErrorCallTimeout,
			ErrorRMCDispatchFailed,
			ErrorMigrationInProgress,
			UnknownOutcome,
		} Outcome;
	
		#endif
		
		/*
		Parameters:
		hTargetStation: The TargetStation of the call.
		bSynchronousCall: true if the call is made asynchronously, false if asynchronously.

		Remarks: If no arguments are passed to the constructor, the CallContext instance will
		initialize the value of the TargetStation to INVALID_DOHANDLE. By default the call 
		will be made asynchronously i.e. the thread will keep running while it waits for the
		call to return a value or an error. The method Wait can be used if the call is to be made 
		asynchronously.
		*/
		CallContext(DOHandle hTargetStation=INVALID_DOHANDLE,
				   bool bSynchronousCall=true);
		
		virtual ~CallContext();

//Group=Operations	

		/*
		Description: Sets the target station of the call.
		Parameters:
		hTargetStation: A DOHandle to the target station of the call. 
		  
		Remarks: By default the DOHandle for the target station is INVALID_DOHANDLE. The significance 
		of the target station depends on the CallContext. For a RMCContext the target station is the station
		that the RMC is called on, for a FetchContext it is the station from which we wish to fetch a
		Duplica, and for a MigrationContext it is the station to which we wish to migrate an object.
		See Also: GetTargetStation
		*/
		void SetTargetStation(DOHandle hTargetStation);
		
		/*
		Description: Gets the target station of the call.
		Returns: The DOHandle of the target station of the call.
		See Also: SetTargetStation
		*/
		DOHandle GetTargetStation() {return m_refTargetStation.GetHandle();}

		/*
		Description: Sets the flag to be used with the call.
		Parameters: 
		ucFlag: the flag with which the call is called. It may be either SynchronousCall,
		TargetObjectMustBeMaster, or CancellationNotAllowed.

		Remarks: By default a call will be asynchronous and can be made on either a Duplica 
		or Duplication master.
		See Also: ClearFlag, FlagIsSet, _Flags
		*/
		void SetFlag(unsigned char ucFlag);
		
		/*
		Description: Clears the flag set via SetFlag.
		Parameters:
		ucFlag: the flag with which the call is called. It may be either SynchronousCall,
		TargetObjectMustBeMaster, or CancellationNotAllowed.

		See Also: SetFlag, FlagIsSet, _Flags
		*/
		void ClearFlag(unsigned char ucFlag);
	
		/*
		Description: Returns whether a particular flag is set or not.
		Parameters:
		ucFlag: the flag with which the call is called. It may be either SynchronousCall,
		TargetObjectMustBeMaster, or CancellationNotAllowed.
		
		Returns: true if the stated flag is set, false if it is not set.
		See Also: SetFlag, ClearFlag, _Flags
		*/
		bool FlagIsSet(unsigned char ucFlag) const;
		// {secret}
		unsigned char GetFlags() const {return m_ucFlags;}
		
		/*
		Description: Sets the time that we will wait for a call to return an Outcome.
		Remarks: This method may only be called if the current State of the call is 
		CallInProgress and the flag SynchronousCall is set to false. The method 
		returns true if the Wait has succeeded i.e. the State is no longer CallInProgress. 
	    The error SYSTEMERROR_GEN_TIMEOUT will result if the method returns false.	
		The default wait time is infinite. 
		See Also: State, _State, _Flags
		*/
		bool Wait(unsigned long ulTimeout=WAIT_INFINITE);
		
		/*
		Description: Sets the State of the call to CallCancelled.
		Remarks: The State of the call will be set to CallCancelled and the place holder for the 
		results deleted. This method may only be called if the current State of the call is 
		CallInProgress. The error SYSTEMERROR_GEN_INVALID_OPERATION will result if this method 
		is called when the current State is any State other than
		CallInProgress. A call is automatically cancelled if the CallContext is deleted.

Note: If the CallContext does not allow cancellation of the call, which is the case for a 
Migration call, this call will lock untill the call has terminated.
		
		See Also: State, Reset, _State, 
		*/
		bool Cancel(State eNewState=CallCancelled);

		/*
		Description: Resets the State of the call to Available.
		Remarks: This method may only be called if the current State of the call is one of 
		Sucess, Failure, or Cancelled. The error SYSTEMERROR_GEN_INVALID_OPERATION will 
		result if this method is called when the current State is
		Available or CallInProgress.
		See Also: State, Cancel, _State, 
		*/
		bool Reset();
		
		/*
		Description: Gets the current State of the call.
		Returns: The current State of the call which is one of Available, 
		CallInProgress, CallSuccess, CallFailure, or CallCancelled.
		See Also: State, Reset, Cancel, _State, 
		*/
		State GetState() {return m_eState;}
		
		/*
		Description: Gets the Outcome of the call.
		Returns: The Outcome of the call.
		Remarks: The Outcome may be one of Success, ErrorStationNotReached, 
		ErrorTargetStationDisconnect, ErrorLocalStationLeaving, ErrorObjectNotFound,
		ErrorInvalidRole, ErrorRMCDispatchFailed, ErrorMigrationInProgress,or UnknownOutcome.
		See Also: _Outcome
		*/
		unsigned char GetOutcome() {return m_ucOutcome;}

		// {secret}
		static TCHAR* GetOutcomeString(Outcome uOutcome);

		// Access to members.
		// {secret}
		ID GetID() {return m_idRMCCall;}

		// Called by the RMCRegister, on registration.
		// {secret}
		void SetID(CallContext::ID id);

		// Called by the RMCRegister, on disconnection.
		// {secret}
		void SetOutcome(CallContext::Outcome ucOutcome);

		// {secret}
		bool PerformCall();
		// {secret}
		virtual bool SendCallMessage(Message* pCallMessage);

		// {secret}
		void SignalResponse(UserContext ucResponseContext=UserContext());
		// {secret}
		virtual State ProcessResponse(UserContext ucResponseContext);
		
		// {secret}
		void SignalOutcome(Outcome uOutcome);
		// {secret}
		virtual void ProcessOutcome(Outcome uOutcome) {};

		// {secret}
		Message* GetCallMessage();

		// {secret}
		DOHandle GetSourceStation() {return m_hSourceStation;}
		
		// {secret}
		virtual void Trace(unsigned long ulTraceFlags=TRACE_ALWAYS);
		// {secret}
		virtual Type GetType() const=0;

		// {secret}
		void SetExpirationDelay(TimeInterval tiExpirationDelay);
		// {secret}
		bool HasExpired();
		// {secret}
		Time GetExpirationTime() {return m_tExpirationTime;}

		

	protected:

		// Available for specific call contextes.
		// {secret}
		void SetState(State eNewState);
		// {secret}
		void SignalCallCompletion(State eCompletionState, bool bCallIsRegistered=true);


	private:
		
		State m_eState;

		// Portion of info filled by the RMCRegister upon
		// registration.
		// {secret}
		ID m_idRMCCall;
		
		DOHandle m_hSourceStation;

	protected:
		// User controlled info.
		// {secret}
		DORef m_refTargetStation;
	private:
		unsigned char m_ucFlags;


	protected:
		// Messages...
		// {secret}
		Message* m_pCallMessage;

	private:
		// Events.
		// {secret}
		EventHandler m_oEventHandler;
		Event* m_pResponseEvent;
		unsigned char m_ucOutcome;
		CriticalSection m_csDestruction;
		Time m_tExpirationTime;
};
		

#endif
