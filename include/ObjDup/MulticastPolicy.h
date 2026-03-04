//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MulticastPolicy_H_
#define _MulticastPolicy_H_


#include <Platform/PerfCounter.h>
#include <Plugins/Protocol/Interface/Message.h>
#include <ObjDup/ObjDupDecl.h>
#include <Utility/PseudoGlobalVariable.h>

class DOHandle;
class DuplicatedObject;
class IteratorOverDOs;
class MulticastControl;
class Selection;
class DOFilter;

//{secret}
#define NO_LIMIT  0xFFFFFFFF    //With this parameter, there is no limit of a number of station to contact. 
                                //This will be used for multicast

#define BROADCAST   0
#define MULTICAST   1

// Group=Miscellaneous Classes

/*
Summary: This class defines the policy used when multicast updates are implemented.

Remarks: Multicasted updates can be used to deal with station capacity and bandwidth limitations.
Rather than a Duplication master sending an update message to each of its duplicas, the update 
message may be multicasted, i.e. a hierarchical arrangement of MulticastGroup objects 
is used to distribute the message sent from a Duplication master to its duplicas.
*/
class MulticastPolicy {
//Group =

	public:
		MulticastPolicy();
		~MulticastPolicy();

        /*
		Description: Returns a pointer to the MulticastPolicy instance.
		Returns: A reference to the MulticastPolicy.
		Remarks: Use the reference returned by this method to control multicasted updates.
		For example, set the default message sending capacity as follows:

			MulticastPolicy::GetInstance()->SetDefaultMsgSendingCapacity(10);

		*/
		static MulticastPolicy *GetInstance();

        //{secret}
		static void Create();
        //{secret}
		static void Delete();
         
		/*
		Description: Sets the maximum group size.
		Remarks: The maximum group size is the the maximum number of members that a multicast group
		object will contain. A member is either another multicast group or a station if we are
		at the lowest level of the hierarchy. If no maximum group size is set a default value of 16 is used.
		
Note: The group size must be equal to or greater than 1.
        
		See Also: GetMaximumGroupSize
		*/
		void SetMaximumGroupSize(unsigned long ulSize);
        
		//Description: Gets the maximum group size set via the method SetMaximumGroupSize.
		//See Also: SetMaximumGroupSize
		unsigned long GetMaximumGroupSize();

        /*
		Description: Use this method to disable a distributed broadcast.
        Remarks: By default a distributed broadcast is enabled however, it may be disabled and
		re-enabled while an application is running. When a distributed broadcast is disabled,
		each Duplication master will send an update message directly to each of its duplicas.
		See Also: DistributedBroadcastIsEnabled
        */
		void DisableDistributedBroadcast();
        
         /*
		Description: Use this method to enable a distributed broadcast.
        Remarks: By default a distributed broadcast is enabled however, it may be disabled and
		re-enabled while an application is running. When a distributed broadcast is enabled,
		messages will be sent via the multicast group hierarchy.
		See Also: DistributedBroadcastIsEnabled, DisableDistributedBroadcast
        */
		void EnableDistributedBroadcast();

		//Description: Use this method to determin if a distributed broadcast is enabled or not.
		//Returns: true if a distributed broadcast is enabled, false if it is not.
		//See Also: DisableDistributedBroadcast
        bool DistributedBroadcastIsEnabled();

		/*
		Description: Sets the default message sending capacity of a station.
		Remarks: The message sending capacity of a station is the maximum number of stations that a 
		station will send an update message to directly. This quantity is set for all the stations in
		the session. For example, if the DefaultMsgSendingCapacity is set to 10, a station will send 
		update messages directly to 10 stations. If there are more than 10 duplicas that the station
		needs to update, then 9 messages will be sent directly to the duplicas and 1 message to the 
		RootMulticastGroup which will then forward the message via the multicast group hierarchy to
		all the other duplicas. If no message sending capacity is set a default value of 16 is used.
		
Note: The message sending capacity must be equal to or greater than 1.
		
		See Also: GetDefaultMsgSendingCapacity, DuplicatedObject::MsgSendingCapacity
        */
		void SetDefaultMsgSendingCapacity(unsigned long ulNbStations);
        
		//Description: Gets the default message sending capacity of a station set via SetDefaultMsgSendingCapacity.
		//See Also: SetDefaultMsgSendingCapacity
		unsigned long GetDefaultMsgSendingCapacity();

        //{secret}
		void UpdateMulticastGroupsSelection();

		//{secret}
		void SendMessage(Message* pMsg,  IteratorOverDOs *pStationIterator, MulticastControl* pControl, bool bReliable=true);
		//{secret}
		void SendMessage(Message* pMsg, Selection* pStationSelection, MulticastControl* pControl, bool bReliable=true);
        //{secret}
        void BroadcastMessage(Message *pMsg, IteratorOverDOs *pStationsToExclude, DuplicatedObject *pDO, bool bReliable=true);
        //{secret}
		void BroadcastMessage(Message *pMsg, Selection *pStationsToExclude = NULL, DuplicatedObject *pDO = NULL, bool bReliable=true);
        //{secret}
        void MulticastMessage(Message *pMsg, IteratorOverDOs *pStationIterator, DuplicatedObject *pDO, bool bReliable=true);
        //{secret}
		void MulticastMessage(Message *pMsg, Selection *pStationSelection = NULL, DuplicatedObject *pDO = NULL, bool bReliable=true);
        //{secret}
		void SendMsgToRootGroup(Message *pMsg, bool bBroadcast, Selection *pStationSelection);
        //{secret}
        void CreateStationIterator(Selection *pSelection, Selection* pStationsToExclude = NULL);
        //{secret}
		void AddAllStationsToSelection(DOHandle hGroup, Selection *pSelection);

        //{secret}
		PerfCounter* GetPerfCounter() {return m_pPerfMulticast;}
        //{secret}
		void         SetPerfCounterFilter(DOFilter *pFilter);
        //{secret}
		void         DeletePerfCounterFilter();

        //{secret}
        static void AllowDeleteStationToSendMessage(bool bValue);

        //{secret}
        static bool DeletedStationIsAllowedToSendMessage();

    private:

        static PseudoGlobalVariable<MulticastPolicy*> s_pMulticastPolicy;
        static PseudoGlobalVariable<bool>             s_bAllowDeletedStationToSendMessage;

        unsigned long m_ulMaximumGroupSize;
        bool          m_bDistributedBroadcast;
        unsigned long m_ulDefaultMsgSendingCapacity;

        PerfCounter         m_pPerfMulticast[2];
        DOFilter           *m_pPerfCounterFilter;
};

#endif
