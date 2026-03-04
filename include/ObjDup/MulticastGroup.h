//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

// This file must have the name of the DOClass that it implements, MulticastGroup

#ifndef _MulticastGroup_H_
#define _MulticastGroup_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOClass.h>
#include <ObjDup/MulticastGroupDDL.h>
#include <ObjDup/MulticastGroupInfo.h>


class MulticastGroup: public DOCLASS(MulticastGroup) {
	public:
		MulticastGroup();
		~MulticastGroup();

		//void OperationBegin(DOOperation* pOperation);
		void OperationEnd(DOOperation* pOperation);    
        void DataSetOperationEnd(DataSetOperation *pOperation);

        void AddMember(DOHandle hNewDO);
        void RemoveMember(DOHandle hDOToDel);
        bool FindMember(DOHandle hDO) {return m_dsMembers.Find(hDO);}
        DOHandle& operator[](int iIndex) {return m_dsMembers.m_vhMembers[iIndex];}
        DOHandle& GetMember(int iIndex)  {return (*this)[iIndex];}

        int    GetCurrentSize() {return m_dsMembers.m_vhMembers.Size();}
        double GetWeight() {return (double)GetCurrentSize();}

        void   SetContent(int iContent) {m_dsInfo.m_iContent = iContent;}
        int    GetContent() {return m_dsInfo.m_iContent;}

        void   SetRoot(bool bRoot) {m_dsInfo.m_bRoot = bRoot;}
        bool   IsRoot() {return m_dsInfo.m_bRoot;}

        void   SetLevel(int iLevel) {m_dsInfo.m_iLevel = iLevel;}
        int    GetLevel() {return m_dsInfo.m_iLevel;}

		bool ApproveFaultRecovery() {return true;}
		bool ApproveEmigration(unsigned long ulReason) {return true;}
		
		void SetUpdateOnPromotion() {m_bUpdateOnPromotion=true;}

        bool ProcessDOMessage(Message *pMsg);

        static void UpdateAllMulticastGroupSelection();

        static const unsigned long BROADCAST_GROUP_MSG;
        static const unsigned long MULTICAST_GROUP_MSG;

        static void RemoveMemberIteration(DOHandle hObjToDelete);
		bool HasToMaintainSelection();
        void ClearSelection();
        void UpdateSelection();

		void Trace(unsigned long ulTraceFlag);

    private :

        void SendMessageToGroup(DOHandle hGroup, unsigned long ulCastType, Message *pMsg);

        void ProcessBroadcastMessage(Message *pMsg);
        void ProcessMulticastMessage(Message *pMsg);

        void CleanMessage(unsigned long ulCastType, Message *pSrcMsg, Message *pDestMsg);

        IteratorOverDOs *CreateStationIterator(unsigned long ulNbStations, DOHandle *pStationVector, Selection *pSelection, bool bBroadcast);

        MulticastGroup* CreateSubGroup(bool bTransferLocalMembers, DOHandle hStationToAdd);
        void            AddMemberToASubGroup(DOHandle hNewDO);
        void            AddMemberToSpecificSubGroup(DOHandle hNewDO, DOHandle hGroup);
        void            AddMemberToRandomSubGroup(int iContent, DOHandle hNewDO, int iNbGroup);
        bool            FindEmptySpot(int iContent, DOHandle *hFoundedGroup, int *iNbGroupFound);


	private:

        CriticalSection m_oCS;
		bool            m_bUpdateOnPromotion;
        Selection      *m_pSelection;

};

#endif
