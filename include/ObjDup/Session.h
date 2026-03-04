//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

// This file must have the name of the DOClass that it implements, Session

#ifndef _Session_H_
#define _Session_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/PseudoGlobalVariable.h>
#include <ObjDup/DOClass.h>
#include <ObjDup/SessionDDL.h>
#include <ObjDup/Station.h>
#include <Plugins/Transport/Interface/StationURL.h>

//Group=Miscellaneous Types and Macros

//Summary: The role of the session object is undefined.
#define SESSION_ROLE_UNDEFINED			0x0
//Summary: The session object is a Duplication master and is therefore, the Session master.
#define SESSION_ROLE_MASTER				0x01
//Summary: The session object is a Duplica.
#define SESSION_ROLE_DUPLICA			0x02

//Group=Miscellaneous Classes

// This macro is never defined.  It is used only to get around a compilation problem with 
// DocJet, which does not like the inheritance to the DOCLASS(Session).
#ifdef FOR_DOC_PURPOSE

//Description: Use this class to set and retrieve specific information about the session.
//Remarks: This class is used to set and retrieve specific information about the session 
//including creating and joining a session.
class Session {

#else

class Session: public DOCLASS(Session) {

#endif

//Group=
	public:
		Session();
		~Session();

		//Description: Use this method to retrieve a DOHandle to a Session instance.
		//Returns: A DOHandle to a Session instance.
		static DOHandle GetInstanceHandle();  

		// {secret}
		void InitDO();
		// {secret}
		void SessionIsAlive();

		// {secret}
		void InitSessionDuplicationSpace();

		/*
		Description: Use this method to retrieve the role of the session object.
		Returns: The role of the session object.
		Remarks: The role is one of SESSION_ROLE_MASTER, SESSION_ROLE_DUPLICA, 
		or SESSION_ROLE_UNDEFINED.
		*/
		static unsigned char GetRole();
	
		/*
		Description: Use this method to retrieve the session name.
		Returns: The session name.
		Remarks: The session name can be specified when a session is created via CreateSession.
		See Also: CreateSession
		*/
		TCHAR *GetSessionName();

		// {secret}
		bool CompleteCreation();
		// {secret}
		void CompleteJoin();

		// {secret}
        void CreateRootGroupReference(DOHandle hRootGroup);
		// {secret}
        void ReleaseRootGroupReference();

		// {secret}
		void AddStation(DOHandle hNewStation);

		/*
		Description: Use this method to set the system state.
		Remarks: The system state may be one of SYSTEM_STATE_PAUSED, SYSTEM_STATE_INITIALIZING,
		SYSTEM_STATE_RUNNING, or SYSTEM_STATE_TERMINATING. If called on a Duplica, the call will 
		fail and signal the error SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA.
		Returns: true if the update call is successful, false if it signals an error.  
		See Also: GetSystemState
		*/
		bool SetSystemState(unsigned long ulNewState);
		
		/*
		Description: Use this method to retrieve the system state.
		Returns: The system state.
		Remarks: The system state may be one of SYSTEM_STATE_PAUSED, SYSTEM_STATE_INITIALIZING,
		SYSTEM_STATE_RUNNING, or SYSTEM_STATE_TERMINATING.
		See Also: SetSystemState
		*/
		unsigned long GetSystemState();

		/*
		Description: Use this method to set a user-defined state.
		Parameters:
		dwNewState: A user-defined state.  

		Remarks: The user-defined state is not interpreted by $PRODUCTNAME$. $PRODUCTNAME$ 
		simply replicates it to all the stations.
		This method must be called on the session master.  The state is a
		distributed value: it is set on the session master but duplicated to
		all the stations that belong to the session.
		See Also: GetUserDefinedState

		Returns: true if the update call is successful, false if it
		signals an error.  The call will fail when called on a Duplica
		and signal the error SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA.

		*/
		bool SetUserDefinedState(unsigned long dwNewState);
		
		/*
		Description: Use this method to retrieve the user-defined state.
		Returns: The user-defined state.
		Remarks: This method can be called on any station that belongs to the session.  It
		returns the user state defined on the session master via the method SetUserDefinedState.
		See Also: SetUserDefinedState
		*/
		unsigned long GetUserDefinedState();

		/*
		Description:  These methods create a $PRODUCTNAME$ Session.

		Returns:  false if the call signals an error, true if otherwise.
		The SYSTEMERROR_DC_CLUSTER_REDEFINITION is signalled if this session has already been created.
		The SYSTEMERROR_OBJDUP_WKHANDLE_NOT_INITIALIZED is also possible.

		Remarks: The following sample code creates a session called "John's session":

			  $PRODUCTNAME$             *g_p$PRODUCTNAME$ = fnew $PRODUCTNAME$;
			  
			  if (!(Session::CreateSession(TEXT("John's session")))){
      			//SystemError
			  };
      
To create a session without giving it a name:
     
			  if(!(Session::CreateSession())){
						 // Process the session creation error
						 // SystemError
			  }
      
The following sample code finds and joins "John's session":

				  SessionDescription oLANSession;
				  bool bFound = Session::FindLANSession(TEXT("John's session"),&oLANSession);
				  if (bFound) {
					  if(!(Session::JoinSession(&oLANSession))){
	          					 // SystemError
					  }
				  } else {
								// session not found on the LAN
				 }

If you do not know the name of the session you wish to join you can use EnumerateLANSessions 
and then join the one you want.

		Parameters:
		szSessionName:  The name of the session that should be created. It is very useful if you
		want to be able to call FindLANSession from another station.
		bNetworked: Boolean value that determins if the session will be networked. By default this 
		is set to true. If you wish to create a non-networked session, set this parameter to false.
		usWKPortNumber: If Proprietary Reliable UDP (PRUDP) is used as the transport, this sets the IP port 
		number on which the connection is established. If none is supplied, 9103 is used by default. 
		*/
		static bool CreateSession(TCHAR *szSessionName, bool bNetworked);
		static bool CreateSession(TCHAR *szSessionName);
		static bool CreateSession(unsigned short usWKPortNumber);
		static bool CreateSession(TCHAR *szSessionName, unsigned short usWKPortNumber);

		/*
		Summary: These methods are used to join a $PRODUCTNAME$ session given the name of a station in 
		the session, or a SessionDescription respectively.

		Returns:  false if the call signals an error, true if otherwise.  
		SYSTEMERROR_DC_CLUSTER_JOIN_DENIED is signalled if the station does not pass the internal $PRODUCTNAME$
		authentication. SYSTEMERROR_OBJDUP_WKHANDLE_WERE_CREATED is signalled if the station attempting to join 
		has previously created	well-known objects (only the session creator can create well-known objects, 
		joining stations discover them). SYSTEMERROR_DC_CLUSTER_REDEFINITION is also possible.

		Remarks: The following sample code joins a session on machine "BobsMachine":

			  $PRODUCTNAME$              *g_p$PRODUCTNAME$ = fnew $PRODUCTNAME$;
			  
				  if(!(Session::JoinSession(TEXT("BobsMachine")))){
          			//SystemError
				  }

The following sample code finds and joins a session named "John's session":

				  SessionDescription oLANSession;
				  bool bFound = Session::FindLANSession(TEXT("John's session"),&oLANSession);
				  if (bFound) {
					  if(!(Session::JoinSession(&oLANSession))){
	          					 // SystemError
					  }
				  } else {
								// session not found on the LAN
				 }

		Parameters:

		pStationURL: A pointer to the StationURL of the station via which you wish to join the session. 
		szMachine: The name of a station that belongs to the session that will be joined using 
		Proprietary Reliable UDP (PRUDP) as the transport. 
		usWKPortNumber: The port number via which the session will be joined using Proprietary Reliable 
		UDP (PRUDP) as the transport.  
		pSessionDescription: A description of the session that will be joined using Proprietary Reliable 
		UDP (PRUDP) as the transport. This description contains the location of the session as
		well as other information (e.g. session name, library version number).
		
		See Also: EnumerateLANSessions, FindLANSession
		*/
		static bool JoinSession(StationURL *pStationURL);
		static bool JoinSession(TCHAR *szMachine);		
		static bool JoinSession(TCHAR *szMachine, unsigned short usWKPortNumber);		
		static bool JoinSession(SessionDescription *pSessionDescription);

		// TODO: Move checks from the SessionCtrlInterface here.
		/*
		Description: Enumerates through all the sessions that are running on
		the LAN and calls the function pfUserFunction for each SessionDescription that it finds.  

		Returns: false if the call signals an error, true if otherwise.
		The SYSTEMERROR_DC_CLUSTER_ALREADY_INITIALIZED is signalled if the call is made after an session
		is joined or created. Returns the number of sessions (SessionDescription) found on the network 
		at the given port number. In the case of an error, 0 is returned.

		Parameters:
		ulContext: The value that will be passed to the user function.
		pfUserFunction: Function that will be called for every SessionDescription found on the LAN.
		pSessionDescription: A pointer to the SessionDescription.
		ulTimeout: The timeout for the method.
		bFilterTitle: Boolean that tells if only the sessions that are enumerated should
		have the same title as the one calling this function. If none is supplied, the default is true.
		usWKPortNumber: The IP port number which is scanned for sessions using Proprietary Reliable 
		UDP (PRUDP) as the transport. If no port number is supplied, 9103 is used as the default. 

		Remarks: This method can only be called before the session is created
		or joined.  The pfUserFunction is called locally.
		
		See Also: FindLANSession, JoinSession
		*/
		static unsigned int EnumerateLANSessions(unsigned long ulContext,
					void (*pfUserFunction)(unsigned long ulContext, SessionDescription *pSessionDescription), 
					bool bFilterTitle = true, unsigned long ulTimeout = 1000);
		static unsigned int EnumerateLANSessions(unsigned long ulContext,
					void (*pfUserFunction)(unsigned long ulContext, SessionDescription *pSessionDescription), 
					unsigned short usWKPortNumber,
					bool bFilterTitle = true, unsigned long ulTimeout = 1000);

		// {secret}
		static void FindLANSessionCallback(unsigned long ulContext, 
									SessionDescription *pSessionDescription);
		/*
		Summary:  Finds the specified session on the network. If found,
		the SessionDescription of the session is stored in pSignature.
		Returns:  false if the call signals an error, true if otherwise.
		The SYSTEMERROR_DC_CLUSTER_ALREADY_INITIALIZED is signalled if the call is made after an session
		is joined or created. If the session is found on the network at the given usWKPortNumber, 
		the method returns true, otherwise it returns false.
	
		Remarks: This method can only be called before the session is created
		or joined. The following sample code finds and joins a session named "John's session":

			$PRODUCTNAME$              *g_p$PRODUCTNAME$ = fnew $PRODUCTNAME$;
		
					SessionDescription oLANSession;
					bool bFound = Session::FindLANSession(TEXT("John's session"),&oLANSession);
					if (bFound) {
						if(!(Session::JoinSession(&oLANSession))){
	          					 // SystemError
						}
					} else {
								 // session not found on the LAN
					}
      
To find and join sessions that you do not know the title of use EnumerateLANSessions.

		Parameters:
		szName: The session name.
		pSignature: A pointer to the SessionDescription. If the method succeeds this signature is 
		filled with the found session.
		ulTimeout: The timeout for the method.
		usWKPortNumber: The IP port number on which the connection is to be established using Proprietary 
		Reliable UDP (PRUDP) as the transport.	If none is supplied, 9103 is used as default. 

		See Also: EnumerateLANSessions, JoinSession
		*/
		static bool FindLANSession(TCHAR *szName, SessionDescription *pSignature, unsigned long ulTimeout = 1000);
		static bool FindLANSession(TCHAR *szName, SessionDescription *pSignature, 
									unsigned short usWKPortNumber, unsigned long ulTimeout = 1000);

		// {secret}
		static void PrepareToLeave();

	private:

		static void SetPRUDPWKPortNumber(unsigned short usWKPortNumber);

        MulticastGroup::Ref *m_pRefRootMulticastGroup;
};

#endif
