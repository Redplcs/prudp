//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _LoadBalancingDomain_H_
#define _LoadBalancingDomain_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/LoadInfo.h>
#include <ObjDup/LoadBalancingDomainDDL.h>

class DOOperation;
class TransferRequest;

//Message types
//{secret}
#define LOCAL_LOAD_INFO_REPORT		1
#define REQUEST_LOAD_TRANSFER		2
#define REQUEST_LOCAL_LOAD_INFO_REPORT		3
#define SCHEDULE_LOAD_BALANCING_EPISODE	4
#define PARTICIPATE	5
#define CANCEL_PARTICIPATION	6

#define DEFAULT_EPISODE_PERIOD 20000


//Timeout values
//{secret}}
#define GET_REMOTE_LOAD_INFO_TIMEOUT 5000
#define TRANSFER_LOAD_TIMEOUT 5000

//Group=Load Balancing

// This macro is never defined.  It is used only to get around a compilation problem with 
// DocJet, which does not like the inheritance to the DOCLASS(LoadBalancingDomain).
#ifdef FOR_DOC_PURPOSE

/*
Description: This class manages the load balancing policy implemented by $PRODUCTNAME$.
Remarks: LoadBalancingDomain is the root class for all load balancing performed by $PRODUCTNAME$. 
The user may sub-class this class in order to define a custom load balancing scheme.
*/
class LoadBalancingDomain {

#else

class LoadBalancingDomain : public DOCLASS(LoadBalancingDomain) {

#endif
//Group=
	public:
		LoadBalancingDomain();
		~LoadBalancingDomain();

		// {secret}
		void DeleteLoadInfoMap();

		// {secret}
		void OperationEnd(DOOperation* pOperation);

		// {secret}
		bool GetRemoteLoadInfo(DOHandle hStation, double &dLoad, double &dCapacity);

		// {secret}
		void PerformLoadBalancing(void *ptr=NULL);
		// {secret}
		void QueuedLoadBalancing(DORef refMyself);
		
		//Duplica side methods
		// {secret}
		bool SendReportToMaster();

		// {secret}
		bool SendParticipateMessage();
		// {secret}
		bool SendCancelParticipationMessage();

		// {secret}
		bool RequestLoadTransfer(DOHandle hFromStation, DOHandle hToStation, double dLoad);
		
		// {secret}
		bool RequestAllLoadInfos();
		// {secret}
		bool RequestRemoteLoadInfo(DOHandle hStation);
		// {secret}
		double GetTotalCapacity() {return m_dTotalCapacity;}
		// {secret}
		double GetTotalLoad() {return m_dTotalLoad;}
		// {secret}
		bool ComputeInitialDelta(LoadInfo *oLI);

		// {secret}
		unsigned long GetTableSize() {ScopedCS oCS(m_cs); return m_LoadInfoMap.size();}

		//TODO: think about it : if capacity is Zero, delta==load ...

		// {secret}
		DOHandle FindMostLoaded();
		// {secret}
		DOHandle FindLeastLoaded();

		// {secret}
		bool CreateSubDomains() {
			//do nothing for now
		}

		// {secret}
		bool IsASuperDomain() {
			return false;
			//for now
		}

		//DOMessages
		// {secret}
		bool ProcessDOMessage(Message *pMsg);
		// {secret}
		bool ProcessLocalLoadInfoReport(Message *pMsg);
		// {secret}
		bool ProcessTransferRequest(Message *pMsg);
		// {secret}
		bool ProcessRequestLocalLoadInfoReport(Message *pMsg);
		// {secret}
		bool ProcessScheduleLoadBalancingEpisode(Message *pMsg);
		// {secret}
		bool ProcessParticipate(Message *pMsg);
		// {secret}
		bool ProcessCancelParticipation(Message *pMsg);
		// {secret}
		bool MustUnload(LoadInfo *pLI);
		// {secret}
		bool MayAcceptLoad(LoadInfo *pLI);

		//--------------------------API------------------------------
		
		/*
		Description: Use this method to retrieve the load on the local station.
		Returns: The current load on the local station.
		Remarks: It is up to the user to define what constitutes a load. Values such as 
		the CPU load, bandwidth, memory load, or duplicated objects may be defined as the load.
		See Also: TransferLoad
		*/
		virtual double GetLocalLoad() {return 0.0;}

		//Description: Use this method to retrieve the capacity of the local station.
		//Returns: The current capacity of the local station.
		//Remarks: Set the local capacity via SetLocalCapacity. 
		//See Also: SetLocalCapacity
		virtual double GetLocalCapacity() {return 0.0;}

		//Description: Use this method to set the capacity of the local station.
		//Remarks: It is up to the user to define what constitutes a capacity. Values such as 
		//the station CPU, memory, and bandwidth may be defined as the capacity.
		//See Also: GetLocalCapacity
		virtual void SetLocalCapacity(double dCap) {m_dLocalCapacity=dCap;}
	
		//Description: Use this method to specify how to transfer load between stations.
		//Remarks: $PRODUCTNAME$ uses this method to implement how a load is transferred 
		//between the stations involved in load balancing.
		//See Also: GetLocalLoad
		virtual void TransferLoad(DOHandle hStation, double dLoad) {}

		/*
		Description: Use this method to set the load ratio threshold.
		Remarks: The load ratio is the ratio of the load to the capacity on a given station. 
		If the load ratio on a given station is greater than the load ratio threshold, then 
		load balancing will be performed across all the participating stations to try to reduce 
		the load ratio of that station to the ideal ratio. The default load ratio threshold is 0.
		See Also: GetLoadRatioThreshold
		*/
		void SetLoadRatioThreshold(double dThresh) {m_dsPolicy.m_dLoadRatioThreshold=dThresh;}
			
		/*
		Description: Use this method to retrieve the load ratio threshold.
		Returns: The load ratio threshold.
		Remarks: Set the load ratio threshold via SetLoadRatioThreshold.
		See Also: SetLoadRatioThreshold
		*/
		double GetLoadRatioThreshold() {return m_dsPolicy.m_dLoadRatioThreshold;}
		
		/*
		Description: Use this method to set the equilibrium deviation threshold.
		Remarks: The equilibrium deviation is the load ratio of the local station minus
		the ideal load ratio. The ideal load ratio is the total load divided by the total
		capacity for all the stations that participate in load balancing. If the equilibrium 
		deviation on a given station is greater than the equilibrium deviation threshold, then  
		load balancing will be performed to transfer some load from that station in order to
		restore equilibrium between all the participating stations. The default equilibrium 
		deviation threshold is 0.05 units.
		See Also: GetEquilibriumDeviationThreshold
		*/
		void SetEquilibriumDeviationThreshold(double dThresh) {m_dsPolicy.m_dEquilibriumDeviationThreshold=dThresh;}
		
		//Description: Use this method to retrieve the equilibrium deviation threshold.
		//Returns: The equilibrium deviation threshold.
		//Remarks: Set the equilibrium deviation threshold via SetEquilibriumDeviationThreshold.
		//See Also: SetEquilibriumDeviationThreshold
		double GetEquilibriumDeviationThreshold() {return m_dsPolicy.m_dEquilibriumDeviationThreshold;}

		//Description: Use this method to invoke a load balancing cycle when manual load balancing is used.
		//Remarks: This method is only valid if manual load balancing is implemented via SelectManualLoadBalancing.
		//See Also: SelectManualLoadBalancing
		bool RequestLoadBalancingEpisode();

		//Description: Use this method to set the episode period, in milliseconds, for automatic load balancing.
		//Remarks: The default episode period is equal to 20 000 milliseconds.
		//See Also: SelectAutomaticLoadBalancing, GetEpisodePeriod
		void SetEpisodePeriod(unsigned long ulPeriod) {m_dsPolicy.m_ulEpisodePeriod = ulPeriod;}

		//Description: Use this method to get the episode period for automatic load balancing.
		//Returns: The load balancing episode period.
		//Remarks: Set the episode period via SetEpisodePeriod.
		//See Also: SelectAutomaticLoadBalancing, SetEpisodePeriod
		unsigned long GetEpisodePeriod() const;

		/*
		Description: Use this method to implement automatic load balancing.
		Parameters:
		ulPeriod: The time period, in milliseconds, between load balancing episodes. This parameter is optional.

		Remarks: If ulPeriod is omitted, $PRODUCTNAME$ uses a default value of 20 000, which 
		causes load balancing to be performed every 20 seconds. Load balancing may be toggled between the 
		automatic and manual implementations while an application is running. Load balancing is performed 
		manually by default. Use this method to perform load balancing automatically.
		See Also: SelectManualLoadBalancing, IsAutomatic, SetEpisodePeriod, GetEpisodePeriod
		*/
		void SelectAutomaticLoadBalancing(unsigned long ulPeriod=0);

		/*
		Description: Use this method to implement manual load balancing.
		Remarks: Instructs $PRODUCTNAME$ to only perfom load balancing when manually requested 
		to do so by a call to RequestLoadBalancingEpisode. Load balancing may be toggled between the 
		automatic and manual implementations while an application is running. Load balancing is performed 
		manually by default. Use SelectAutomaticLoadBalancing to perform load balancing automatically.
		See Also: SelectAutomaticLoadBalancing, IsAutomatic, RequestLoadBalancingEpisode
		*/
		void SelectManualLoadBalancing() {m_dsPolicy.m_bAutomatic = (unsigned char)false;}

		//Description: Use this method to determine if load balancing is performed automatically 
		//or manually.
		//Returns: true if load balancing is performed automatically, false if it is performed manually.
		//See Also: SelectAutomaticLoadBalancing, SelectManualLoadBalancing
		bool IsAutomatic() {return m_dsPolicy.m_bAutomatic;}

		/*
		Description: Use this method to dictate that the local station participates in
		load balancing.
		Remarks: By default a station is involved in load balancing. The participation of a 
		station in load balancing can be permitted and cancelled while an application is running.
		See Also: CancelParticipation
		*/
		bool Participate();
		
		/*
		Description: Use this method to ensure that the local station does not participate 
		in load balancing.
		Remarks: By default a station is involved in load balancing. Use this method to cancel 
		its participation. The participation of a station in load balancing can be permitted and 
		cancelled while an application is running.
		See Also: Participate
		*/
		bool CancelParticipation();

		//-----------------------------------------------------------

		
		// {Secret}
		bool ResetAll();

		// {Secret}
		bool ScheduleLoadBalancingEpisode(unsigned long ulPeriod);

		// {Secret}
		void ScheduleLoadTransfer(TransferRequest *pTR);

		// {Secret}
		void AttemptLoadTransfer(TransferRequest *pTR);

		// {Secret}
		virtual void EpisodeCompleted();

		// {Secret}
		void GatherEpisodeInitialInfo();

		// {Secret}
		void ComputeTotalLoadAndCapacity();
		// {Secret}
		void ComputeDeltas();
		// {Secret}
		bool ShouldPerformEpisode();
	
		// {secret}
		bool IsParticipating() {return m_bIsParticipating;}


		// {Secret}
		void TraceLoadInfos();


protected:
		double m_dLocalLoad;
		double m_dLocalCapacity;

private:
		std::map<DOHandle, LoadInfo*> m_LoadInfoMap;
		double m_dTotalLoad;
		double m_dTotalCapacity;
		Time m_tiResetTime;

		Job<LoadBalancingDomain, void*> *m_pLoadBalancingJob;

		bool m_bIsParticipating;

		CriticalSection m_cs;

};

#endif
