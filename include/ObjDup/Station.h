//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

// This file must have the name of the DOClass that it implements, Station

#ifndef _Station_H_
#define _Station_H_

#include <ObjDup/ObjDupDecl.h>

class Message;
class EndPoint;
#include <ObjDup/DOClass.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/StationDDL.h>
#include <Utility/PseudoGlobalVariable.h>
#include <ObjDup/UpdateContextMap.h>
#include <ObjDup/QualityFactor.h>
#include <ObjDup/DOOperationCallback.h>
#include <ObjDup/MulticastGroup.h>
class Observer;

//Group=Miscellaneous Classes

// This macro is never defined.  It is used only to get around a compilation problem with 
// DocJet, which does not like the inheritance to the DOCLASS(Station).
#ifdef FOR_DOC_PURPOSE

//Description: Use this class to retrieve specific information about a station.
//Remarks: This class is used to retrieve specific information about a station and to set 
//the observer used when distance-based dead reckoning is invoked.
class Station {

#else

class Station: public DOCLASS(Station) {

#endif

	public:
		Station();
		~Station();

//Group=Type Definitions

		//Description: This enumerates the various states of a Station.
		//See Also: _State
		typedef enum _State {
			// The State of the Station is unknown.
			Unknown, 
			// The Station is in the process of joining the session.
			JoiningSession,
			// The Station is in the process of creating the session.
			CreatingSession,
			// The Station is currently participating in the session.
			Participating, 
			// The Station is in the process of leaving the session.
			Leaving, 
			// The Station is in the process of leaving the session due to a fault.
			LeavingOnFault
		} State;

		// This macro is never defined. Here it is used to prevent DocJet from exposing the connection types.
		#ifdef FOR_DOC_PURPOSE
		#else
		
		typedef enum _ConnectionType {
			NoConnection, 
			DirectConnection,
			IndirectConnection
		} ConnectionType;
		
		#endif
	
//Group=
		/*
		Description: Use this method to return the current State of the station.
		Returns: The current State of the station, which is one of: Unknown, JoiningSession,
		CreatingSession, Participating, Leaving, or LeavingOnFault.
		See Also: State, _State
		*/
		State GetState() {return (State) m_dsStationState.Get();}

		// {secret}
		void SetState(State uNewState);

		/*
		Description: Use this method to determine if a station is a peer.
		Returns: true if the station is a peer station, false if it is the local station.
		Remarks: The peers of a given station depend on the implementation of the distributed 
		braodcast. If a distributed broadcast is implemented the peers of a given station will
		consist of: the stations where the duplication masters of the duplicas on the local 
		station reside, the stations where the duplicas of the duplication masters of the 
		local station reside, and the station where the Duplication master of the 
		RootMulticastGroup	object resides. In addition, if the local station contains a 
		Duplication master of a MulticastGroup, its peers will also include the stations of
		all of the MulticastGroup members. In contrast, if a distributed broadcast is 
		disabled, the peers will consist of all the stations in the session.
		See Also: IsLocal
		*/
		bool IsAPeer();
		
		/*
		Description: Use this method to determine if a station is the local station.
		Returns: true if the station is the local station, false if it is a peer station.
		Remarks: The local station is typically the Duplication master of the station
		but this is not always the case.
		See Also: IsAPeer
		*/
		bool IsLocal();

		// {secret}
		void ReleaseOwnReference();
		// {secret}
		void AcquireOwnReference();
		// {secret}
		bool OwnsReferenceToItself();

		//Description: Use this method to retrieve the ID of the station.
		//Returns: The StationID of the station.
		StationID GetStationID() const;

		// {secret}
		void ConnectionRequired();

		// {secret}
		bool SendMessage(Message* pMsg, bool bReliable=true);

		// {secret}
		bool ApproveEmigration(unsigned long ulReason);
		// {secret}
		bool ApproveFaultRecovery();

		// {secret}
		void OperationBegin(DOOperation* pOperation);
		// {secret}
		void OperationEnd(DOOperation* pOperation);

		// {secret}
		void LeaveSession(bool bOnFault) {
			LeaveSession(bOnFault, GetMasterID());
		}
		// {secret}
		void LeaveSession(bool bOnFault, unsigned long ulOldMasterID);

		// {secret}
		bool IsConnected();

		// {secret}
		ConnectionType GetConnectionType();
		// {secret}
		TCHAR* GetConnectionTypeString();

		//{secret}
		bool ShouldTryDirectConnection();
		
		// {secret}
		bool EstablishDirectConnection();
		// {secret}
		bool ConnectToRouter(DOHandle hRouterStation);
		// {secret}
		void DisconnectFromRouter();

		// {secret}
		DOHandle GetRouterStation();

		// {secret}
		void Disconnect(bool bWaitForDisconnect);
		// {secret}
		void WaitForDisconnect();
		// {secret}
		void QueuedDisconnect(Station::Ref refMyself);
		// {secret}
		void QueueDisconnect(bool bWaitForDisconnect, TimeInterval tiWhenFromNow=0);

		// {secret}
		static void SetLocalStation(DOHandle hStation);

		//Description: Use this method to retrieve the DOHandle of the local station.
		//Returns: The DOHandle of the local station.
		static DOHandle GetLocalStation();
		
		// {secret}
		static DOHandle ConvertIDToDOHandle(StationID idStation);
		// {secret}
		static unsigned long ConvertDOHandleToID(DOHandle hStation);

		// {secret}
		UpdateContextMap& GetUpdateContextMapRef() {return m_ucMap;}
		// {secret}
		QualityFactor* GetQualityFactor();

		// Observer methods
		// {secret}
	    void SetObserverHandle(DOHandle hDO);
		// {secret}
		DOHandle GetObserverHandle();

		// {secret}
        Observer *GetObserverPtr();

        /*
        Description: Determines if an observer is registered and if so, which object is the observer. 

        Parameters:
        phObserver: DOHandle of the observer if one was registered with RegisterObserver. 
    
        Returns: true if an observer is registered, false if no observer is registered.
        Remarks: If an observer, which is used in dead reckoning calculations, is registered then 
        the method will determine which object is the observer. 
        See Also: RegisterObserver, UnregisterObserver, Dead Reckoning Overview
        */
		bool GetObserver(DOHandle* phObserver);

        /*
        Description: Selects a duplicated object as the observer.

        Parameters:  
		idObserver: DOHandle of the object that you want to register as the observer.  

        Returns: false if the call signalled an error, true if otherwise. If an observer is 
		already registered then the error SYSTEMERROR_GEN_INVALID_OPERATION is signalled.

        Remarks: Either a Duplication master or a Duplica may be selected as the observer for dead 
        reckoning calculations. At any time, the number of observers registered can only be equal to 
        0 or 1. If no observer is registered and distance-based dead reckoning is invoked, then the 
		default distance defined by ErrorToleranceFunction::SetDefaultDistance is used to calculate 
		the error tolerance used in the dead reckoning algorithm.

        See Also: GetObserver, UnregisterObserver, ErrorToleranceFunction::SetDefaultDistance, 
		Dead Reckoning, Dead Reckoning Overview
        */
		static bool RegisterObserver(DOHandle idObserver);

        /*
        Description: Unregisters the current observer.
        Returns: false if the call signals an error, true if otherwise. If no observer is 
		currently registered the error SYSTEMERROR_GEN_INVALID_OPERATION is signalled. 
        See Also: GetObserver, RegisterObserver, Dead Reckoning Overview
        */
        static bool UnregisterObserver();

		// {secret}
		CriticalSection& GetConnectionCS() {return m_csConnection;}

		// {secret}
        bool ProcessDOMessage(Message *pMsg);

		// {secret}
		void PerformStationFaultRecovery();

		// {secret}
		void SetAtEOS();
		// {secret}
		bool AtEOS();
		// {secret}
		void WaitForEOS();

		// {secret}
		bool RouteMessage(DOHandle hTargetStation, Message* pMessageToRoute, bool bReliable=true);

		// {secret}
		void FlushMessages();

		// {secret}
		unsigned long GetMachineUID();

		// {secret}
		bool TestAndSetFaultFlag();
		// {secret}
		bool Faulty();

		// {secret}
		void Trace(unsigned long ulFlags=TRACE_ALWAYS);

		// {secret}
		void InitLocalStationInfo();
		// {secret}
		unsigned long GetMachineUniqueID();

	private:

		void DisconnectEndPoint(bool bWaitForDisconnect);


	private:
		// Connection info.
		// {secret}
		CriticalSection m_csConnection;
		// If m_poEndPoint is non NULL use it, else use the
		// routing station.
		// {secret}
		EndPoint* m_poEndPoint;
		Station::Ref m_refRouterStation;

		// Indicate with which URL this station is connected
		// {secret}
		int m_iCurrentConnectedURL;

		// Local station.
		// {secret}
		static PseudoGlobalVariable<DOHandle> s_hLocalStation;

		// Info used to implement different functionnality of the system.
		// {secret}
		UpdateContextMap m_ucMap;
		Observer *m_pObserver;
		QualityFactor m_oQualityFactor;

		bool m_bAtEOS;
		AtomicValue m_bFaulty;
};

// For the TraceOutput.
// {secret}
extern unsigned long GetLocalStationHandle();

#endif
