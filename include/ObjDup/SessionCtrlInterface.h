//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _SessionCtrlInterface_H_
#define _SessionCtrlInterface_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/ControlInterface.h>
#include <ObjDup/DuplicatedObjectStore.h>
#include <ObjDup/UserCommunications.h>
#include <ObjDup/DOOperationCallback.h>
#include <ObjDup/Session.h>
#include <Plugins/Transport/Interface/StationURL.h>
class SessionDescription;

// Group = Miscellaneous Types and Macros

/*
Summary:  This event is signalled when a station joins the $gameORsession$.
*/
#define STATION_EVENT_JOIN				0

/*
Summary:  This event is signalled when a station leaves the $gameORsession$ 
before the $gameORsession$ terminates.

A station leaves the $gameORsession$ when its $PRODUCTNAME$ instance is destroyed.

$ifdef TSIS$
See also: SessionCtrlInterface::TerminateSession
$endif$

$ifdef NETZ$
See also:  GameCtrlInterface::TerminateGame
$endif$
*/
#define STATION_EVENT_QUIT				1


/*

Summary:  This event is signalled when a station fails.  Station failures that
occur after a call to $GameORSession$CtrlInterface::Terminate$GameORApp$ not signalled.


$ifdef TSIS$
See also: SessionCtrlInterface::TerminateSession
$endif$

$ifdef NETZ$
See also: GameCtrlInterface::TerminateGame
$endif$
*/
#define STATION_EVENT_FAILURE			2

/*

Summary:  This event is signalled if a station is promoted to $gameORsession$ 
master. The event is signalled on all the stations that belong to the $gameORsession$,
including the one being promoted.
*/
#define STATION_EVENT_PROMOTION		3

#define LAST_GAME_EVENT_ID					3

/*
Summary: INVALID_STATION_ID is returned if a method is called on an invalid station.
*/
#define INVALID_STATION_ID					0xFFFFFFFF

//group=Control Interface

/*
Summary:  The SessionCtrlInterface is the control interface that 
provides basic control functionality over the $PRODUCTNAME$ $gameORsession$.  
The SessionCtrlInterface is a singleton. 

Remarks:  
$ifdef NETZ$
The GameCtrlInterface inherits from this class.
$endif$
The SessionCtrlInterface is a singleton, 
$ifdef NETZ$
and you obtain it by getting its subclass GameCtrlInterface from $PRODUCTNAME$, or
by calling the method GameCtrlInterface::GetInstance.
$endif$
$ifdef TSIS$
and you obtain it by getting it from $PRODUCTNAME$ with the $PRODUCTNAME$::GetSessionCtrlInterface method,
or via the method SessionCtrlInterface::GetInstance.

Note: The ApplicationCtrlInterface has been renamed the SessionCtrlInterface. Several methods of the 
ApplicationCtrlInterface class have also been been renamed in the SessionCtrlInterface class.
$endif$

See Also: $PRODUCTNAME$::Get$GameORSession$CtrlInterface, $PRODUCTNAME$::$PRODUCTNAME$, Interface Overview
*/
class SessionCtrlInterface: public ControlInterface {
	// Group=
	public:
		SessionCtrlInterface();
		virtual ~SessionCtrlInterface();

		/*
		$ifdef NETZ$
		{secret}
		$endif$
		
		Summary: This static method returns a pointer to the SessionCtrlInterface.

		Return Value:  A pointer to the SessionCtrlInterface.
  
		Remarks:  Use this method to quickly access the SessionCtrlInterface methods.  
		For example:

      		SessionCtrlInterface::GetInstance()->GetNbStations();

        Note:  The $PRODUCTNAME$ object must be created before GetInstance method is called.
		
		$ifdef NETZ$
		See Also: $PRODUCTNAME$::$PRODUCTNAME$, $PRODUCTNAME$::GetGameCtrlInterface,
		$endif$
		$ifdef TSIS$
		See Also: $PRODUCTNAME$::$PRODUCTNAME$, $PRODUCTNAME$::GetSessionCtrlInterface,
		$endif$
		*/
		static SessionCtrlInterface* GetInstance();

		// {Secret}
		bool AssociateDOS(DuplicatedObjectStore* poAssociatedDOS);

		// {Secret}
		DuplicatedObjectStore* GetAssociatedDOS() const;

		// {Secret}
		bool PrepareToLeave();

		// Called to initiate the creation of an session.
		bool CreateSession();
		bool CreateSession(TCHAR *szSessionName);
		// These signatures are using PRUDP 
		bool CreateSession(unsigned short usStaticPortNumber);
		bool CreateSession(TCHAR *szSessionName, unsigned short usWKPortNumber);

		bool CreateNonNetworkedSession();

		// Called on the station that wants to joins.  Triggers a
		// ProcessJoinRequest on the master, then waits until the join
		// process has completed.
		bool JoinSession(StationURL *pStationURL);
		bool JoinSession(SessionDescription *pGameSignature);
		// These signature are using PRUDP !
		bool JoinSession(TCHAR *szMachine);		
		bool JoinSession(TCHAR *szMachine, unsigned short usPortNumber);		

		unsigned int EnumerateLANSessions(unsigned long ulContext,
					void (*pfUserFunction)(unsigned long ulContext, SessionDescription *pSessionDescription), 
					bool bFilterTitle = true, unsigned long ulTimeout = 1000);
		// This signature is using PRUDP !
		unsigned int EnumerateLANSessions(unsigned long ulContext,
					void (*pfUserFunction)(unsigned long ulContext, SessionDescription *pSessionDescription), 
					unsigned short usWKPortNumber,
					bool bFilterTitle = true, unsigned long ulTimeout = 1000);
		/*
		$ifdef NETZ$
		{secret}
		$endif$
		*/
		bool FindLANSession(TCHAR *szName, SessionDescription *pSignature, unsigned long ulTimeout = 1000);
		// This signature is using PRUDP !
		bool FindLANSession(TCHAR *szName, SessionDescription *pSignature, unsigned short usWKPortNumber, unsigned long ulTimeout = 1000);

		unsigned int GetNbStations() const;
		StationID GetStationID() const;
		StationID GetMasterID() const;

/*
Description: 
Returns true if the SessionCtrlInterface is valid, false otherwise.
	
Returns:
Returns true if the SessionCtrlInterface is valid, false otherwise.
If more than one SessionCtrlInterface is created, it will not be valid.
	
*/
		bool IsValid() const;
		
		/*
		$ifdef NETZ$
		{secret}
		$endif$
		*/
		bool IsSessionMaster() const;

		SessionDescription *GetSessionDescription();

/*
{Group:Virtual methods}

Summary: Notifies of an event concerning a station.

Parameters:
	id: Station on which the event occurred.
	ulEvent: Event that occured.

Remarks:
The event is one of STATION_EVENT_JOIN, STATION_EVENT_QUIT,
STATION_EVENT_FAILURE or STATION_EVENT_PROMOTION.

Whenever an event occurs this method is called.  Redefine this 
virtual method if you want additional control.
*/
		virtual void StationEvent(StationID id, unsigned long ulEvent) {};

/*
{Group:Virtual methods}

Summary: Notifies of a system state update.

Remarks: Whenever the system state changes this virtual method is called by the system 
on all stations except that of the $gameORsession$ master.

$ifdef TSIS$
See also: GetSystemState, StartSession, PauseSession, ResumeSession, TerminateSession
$endif$

$ifdef NETZ$
See also: GetSystemState, GameCtrlInterface::StartGame, GameCtrlInterface::PauseGame, 
GameCtrlInterface::ResumeGame, GameCtrlInterface::TerminateGame
$endif$
*/
		virtual void SystemStateUpdate() {}

/*
{Group:Virtual methods}

Summary: Notifies all stations, except that of the $gameORsession$ master, of a user state update.

Remarks: Whenever the user-defined state changes this virtual method is called by the system 
on all stations except that of the $gameORsession$ master.

See also: GetUserState, SetUserState
*/
		virtual void UserStateUpdate() {}

		unsigned long GetUserState();
		void SetUserState(unsigned long ulNewState);

		unsigned long GetSystemState();
		
		// {Secret}
		void SetSystemState(unsigned long ulNewState);
		
		bool StartSession();
	
		bool PauseSession();

		bool ResumeSession();

		bool TerminateSession();

		bool EnumeratePeerStations(unsigned long ulContext,
								   void (*f)(unsigned long ulContext, StationID idStation));
		bool SkipLibraryAuthentication();

		bool SetAuthenticationInfo(unsigned long ulVersion,
								   unsigned long ulAdditionalInfoLength=0,
								   unsigned char* pbyAdditionalInfo=NULL);

/*
{Group:Virtual methods}

Summary:  This virtual method can be redefined to the authentication of a station.

Remarks: 
  Upon joining, $PRODUCTNAME$ checks by default the following:


 1.  $GameORApp$ titles match (as defined in DDF);

 2.  $PRODUCTNAME$ versions used match;

 3.  Compares the user-defined custom authentication information. It is set with SetAuthenticationInfo 
 on the $gameORsession$ master and the joining station and implemented with Authenticate.

The user-defined authentication is done based on the information passed
with SetAuthenticationInfo.  The call to SetAuthenticationInfo must
be done before the $gameORsession$ is created or joined.  You must SetAuthenticationInfo
on both the $gameORsession$ master and all the stations that wish to join.

When a new station joins the $gameORsession$, the method Authenticate will be called
on the $gameORsession$ master.

$PRODUCTNAME$ provides a default implementation of the method which ensures that 
the $GameORApp$ version numbers match.  If you supply additional information
then you must also implement the check in Authenticate.

Note:  Calling SkipLibraryAuthentication is the way to bypass the $PRODUCTNAME$ default check of the 
$PRODUCTNAME$ version numbers (number 2).  If you do not supply any $gameORapp$ 
version numbers with SetAuthenticationInfo then Authenticate will return true since the default
$gameORapp$ version number of 0 is set.

Arguments:

ulMyVersion: $GameORApp$ version, as specified with SetAuthenticationInfo on
the $gameORsession$ master.

ulMyAdditionalInfoLength: Length of the additional authentication
info buffer passed with SetAuthenticationInfo on the $gameORsession$ master.

pbyMyAdditionalInfo: Pointer to a copy of the additional
authentication info buffer passed with SetAuthenticationInfo on the
$gameORsession$ master.

ulOtherVersion: $GameORApp$ version, as specified with SetAuthenticationInfo on
the station that joins.

ulOtherAdditionalInfoLength: Length of the additional authentication
info buffer passed with SetAuthenticationInfo on the station that joins.

pbyOtherAdditionalInfo: Pointer to a copy of the additional
authentication info buffer passed with SetAuthenticationInfo on the
station that joins.

Returns: true if the station can join the $gameORsession$, false if it can not.
*/
		virtual bool Authenticate(unsigned long ulMyVersion,
								  unsigned long ulMyAdditionalInfoLength,
								  unsigned char* pbyMyAdditionalInfo,
								  unsigned long ulOtherVersion,
								  unsigned long ulOtherAdditionalInfoLength,
								  unsigned char* pbyOtherAdditionalInfo);

		bool SendMessageToAStation(StationID id, unsigned int uiLength, unsigned char* pbyMessage);
		bool BroadcastMessage(unsigned int uiLength, unsigned char* pbyMessage);

/*
{Group:Virtual methods}

Summary: Called whenever a user message has been received.

Remarks:
This virtual method must be overidden to receive any user messages as the 
default implementation simply ignores all incoming messages. Messages can be sent via
the methods SendMessageToAStation or BroadcastMessage.

  uiLength: Length of the message, in bytes.
  pbyMessage: Address of a buffer that contains the message.

See Also: SendMessageToAStation, BroadcastMessage
*/
		virtual void ReceiveMessages(StationID idSource, unsigned int uiLength, unsigned char* pbyMessage);

		double GetDistance(StationID id, DOHandle hDO);

   		// {Secret}
        void RegisterStationEventCallback();

   		// {Secret}
        void UnregisterStationEventCallback();

		// {Secret}
        void TrapStationAddToStoreEnd(DOOperation *pDOOperation);
        void TrapStationRemoveFromStoreEnd(DOOperation *pDOOperation);
        void TrapSessionMasterIDChangeEnd(DOOperation *pDOOperation);
        void TrapStationFaultRecoveryBegin(DOOperation *pDOOperation);

	private:
		DuplicatedObjectStore* m_poAssociatedDOS;
		UserCommunications* m_poUserCommunications;
		unsigned int m_uiCallbackID;

		PseudoSingleton m_psInstance;

        DOOperationCallback<SessionCtrlInterface>	*m_callbackStationAddToStoreEnd;
        DOOperationCallback<SessionCtrlInterface>	*m_callbackStationRemoveFromStoreEnd;
        DOOperationCallback<SessionCtrlInterface>	*m_callbackSessionMasterIDChangeEnd;
        DOOperationCallback<SessionCtrlInterface>	*m_callbackStationFaultRecoveryBegin;
};

#endif
