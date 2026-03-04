
//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#include <ObjDup/DOClassTemplate.h> // special case
#include <ObjDup/DataSetTemplate.h> // special case

#ifndef _SessionClock_H_
#define _SessionClock_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOClass.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/SessionClockDDL.h>

#include <Utility/SmoothedAverage.h>
#include <Platform/Time.h>
#include <Platform/CriticalSection.h>

/*
#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOClass.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/StationDDL.h>
#include <Utility/PseudoGlobalVariable.h>
#include <Plugins/Protocol/Interface/Message.h>
#include <ObjDup/UpdateContextMap.h>
*/

// Group=Time Management

// This macro is never defined.  It is used only to get around a compilation problem with 
// DocJet, which does not like the inheritance to the DOCLASS(SessionClock).
#ifdef FOR_DOC_PURPOSE

/*
Description:  The session clock provides a synchronized time, in milliseconds, 
across all stations.

Remarks:  The time provided by the session clock is synchronised accross
all stations that belong to the session. The session clock is automatically 
set to zero on the session master when Session::CreateSession 
is called. Only the session master may reset the session clock via the method SetTime.  

Use the session clock to synchronize or compare events on different stations. However, 
in order to measure the time it takes to perform a set of operations on a single station
use an instance of LocalClock or Chrono.

The accuracy of the synchronization is determined by the latency and jitter of
the network. Latency is the time lag before a message reaches its destination, 
while jitter is the variation in latency. The synchronization algorithm 
assumes that the latency between two stations is symmetrical. Therefore, the 
non-symmetry of latency between two stations will cause an error in the session
clock on the local station.

See also: LocalClock, Chrono, Time 
*/
class SessionClock {

#else

	class SessionClock : public DOCLASS(SessionClock) {

#endif
	//group=Operations
	public:

		// API for the class.

		//Summary: Creates and initializes the SessionClock instance.
		static bool CreateSessionClock();

		/*
		Summary: Returns the current time of the session clock on the local station,
		which is synchronized with the session clock on the session master.
		Remarks:  Any connected station can call this method.
		Returns:  The current time, in milliseconds, of the session clock on the local station.
		*/
		static Time GetTime();

		/*
		Summary:  Sets the time, in milliseconds, of the session clock on the
		session master.
		Remarks: Only the session master can set the time of the session clock.
		Returns: true if the call did not signal an error, false if otherwise.
		The SYSTEMERROR_DC_NOT_CLUSTER_MASTER is signalled if the method is called 
		on a station that is not the session master.
		*/
		static bool SetTime(Time tNow);


		//Summary: Sends a message to all SessionClock duplicas
		static bool BroadcastMessage(Message *pMsg);

		// group=Fine Tuning Methods

		/*
		Summary:  Sets the initial minimum number of synchronization pulses sent to synchronize
		the SessionClock before we leave the Session::JoinSession method. 
		Remarks:   The default number of synchronization pulses is s_iDefaultMinimumNbSyncPulse. 
		This means that at least s_iDefaultMinimumNbSyncPulse messages will be sent between the 
		host and session master to synchronize the clock before we leave the 
		Session::JoinSession method. Increase the value of this 
		parameter for a more precise time synchronization.  
		
		Parameters:  
		iMinSyncPulse:  The minimum number of synchronization pulses that will be sent
		before we leave Session::JoinSession. Increase the 
		value of this parameter to improve the accuracy of synchronization, at the cost of 
		greater bandwidth usage. iMinSyncPulse can take any value greater than 0.

		Returns:  true if the method does not signal an error, false if otherwise.  
		SYSTEMERROR_GEN_OUT_OF_RANGE is signalled if the iMinSyncPulse is not greater than 0.
		*/
		static bool SetMinimumNbSyncPulse(int iMinSyncPulse);
		
		/*
		Summary:  Sets the amount of delay between consecutive pulses sent to keep the session clock
		synchronized after the inital Session::JoinSession.
		Remarks: The default value is s_tiDefaultSyncPulseDelay. You can set the tiPulseDelay to any value 
		greater than zero or to INFINITE. Setting the minimum synchronization pulse delay to INFINITE 
		means that the SessionClock will synchronize initialy using the minimum number of synchronization 
		pulses at Session::JoinSession, but will not send any pulses after that to prevent drift. This 
		method can be called on any station.  
	
		Parameters:
		tiPulseDelay:  The amount of delay, in milliseconds, between two consecutive pulses
		sent. Decrease the value of this parameter to prevent drift and to improve the accuracy of 
		synchronization, although it will increase the bandwidth usage. tiPulseDelay can take any 
		value greater than 0.

		Returns:  true if the method does not signal an error, false if otherwise. 
		SYSTEMERROR_GEN_OUT_OF_RANGE is signalled if the tiPulseDelay is not greater than 0.
		*/
		static bool SetSyncPulseDelay(TimeInterval tiPulseDelay);

		// {secret}
		static void SendSyncRequest();
	
		// {secret}
		void ProcessSyncRequest(Message *pMessage);
		
		// {secret}
		void ProcessTimeSync(Message *pMessage);
		
		// {secret}
		void ProcessSetTime(Message *pMessage);
		
		// {secret}
		void ProcessSetRealTimeRatio(Message *pMessage);

		/*
		Summary:  Sets the size (number) of pulses used to synchronize the local session
		clock with that of the session master. 
		Remarks: The default is s_iDefaultSyncPulseSampleSize. The session clock on the local 
		station is synchronized by sending a series of pulses to the session master at a set time 
		interval. This method sets the size (in number of pulses) of each sample that will be sent.

		Parameters:
		iSyncPulseSampleSize:  The number of pulses sent per sample. Increase the value 
		of this parameter to improve the accuracy of synchronization, at the cost of greater
		bandwidth usage. s_iDefaultSyncPulseSampleSize can take any value greater than 0.

		Returns:  true if the method does not signal an error, false if otherwise. 
		SYSTEMERROR_GEN_OUT_OF_RANGE is signalled if the iSyncPulseSampleSize is not greater than 0.
		*/
		static bool SetSyncPulseSampleSize(int iSyncPulseSampleSize);

		//group=Default Constants

		// Summary: The default value for the minimum number of initial synchronization pulses is 10. 
		static const int s_iDefaultMinimumNbSyncPulse;
	
		// Summary: The default value for the pulse delay to keep the SessionClock synchronized is 
		// 10000 milliseconds ( = 10 seconds).
		static const TimeInterval s_tiDefaultSyncPulseDelay;
		
		// Summary: The default value for the sample size of the synchronization pulse is 25 pulses. 
		static const int s_iDefaultSyncPulseSampleSize;

	public:
		// Interface to the class - as seen by the cluster.

		// {Secret}
		SessionClock();

		//{Secret}
		static bool Initialize();

		//{Secret}
		static bool IsInitialized();

		//{Secret}
		bool ProcessDOMessage(Message *pMessage);

		// {Secret}
		~SessionClock();

		// {Secret}
		void GetFrequency(Time* pliFrequency);

		// {Secret}
		void StartTheTime();

		// {Secret}
		static void RestoreRealTimeRatio();

		// {Secret}
		void _Initialize();

		// {Secret}
		bool _IsInitialized();

		// {Secret}
		void _Sync(Time liCurrentTime);


		// {Secret}
		bool _SetTime(Time liCurrentTime);

		// {Secret}
		Time _GetTime();

	private:

		// {Secret}
		bool _SetRealTimeRatio(double dRatio);

		void SendPulseIfRequired();
		bool _SendSyncRequest();
		bool _Pause();
		bool _Resume();

	public:
		
		// {secret}
		static void ApplyDefaultsIfRequired();

	private:
		// {Secret}
		SmoothedAverage<TimeInterval> m_tiOffset;
		bool m_bSet;

		double m_dRealTimeRatio;
		double m_bPaused;
		double m_dRealTimeRatioBeforePause;

		CriticalSection m_csSettingClock;

		static	bool s_bDefaultsApplied;

	private:
		unsigned int m_uiTimeSyncReceived;
		Time m_tLastSyncPulse;

	private:
		// Fine tuning values.
		// {secret}
		static TimeInterval s_tiPulseDelay;
		static int s_iMinNbSyncPulse;
		static int s_iSyncPulseSampleSize;

	public :
		// {secret}
		static bool s_bSimulateDelayOnReception;

#ifdef _TEST_ENABLED
	public:
		// Interface for the tests.

		// {Secret}
		void FakeTheTime();//For tests
	
		// {Secret}
		static bool Test();
#endif

	private :
		bool m_bInitialized;

		Time m_tiLastSyncRequest;

};

#endif
