//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

//#include <ObjDup/DOClassTemplate.h>
#ifndef _IDFactory_H_
#define _IDFactory_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/IDFactoryDDL.h>

#define DEFAULT_REQUESTED_RANGE_SIZE 16
#define GET_RANGE_TIMEOUT 10000

#define LARGESTID (1<<OBJECTID_BITS)-2

class Message;

// Group=Object Duplication Subsystem

typedef unsigned long ID;

class IDFactory : public DOCLASS(IDFactory) {
	// Group=
	public:
		IDFactory();
		IDFactory(ID idMinCache, ID idMaxCache, ID idMinDist=0, ID idMaxDist=0);
		IDFactory& operator=(const IDFactory& oIDFac);
		virtual ~IDFactory();

	public:

		bool ApproveEmigration(unsigned long ulReason);
		bool ApproveFaultRecovery();

		void SetFreeIDRange(ID idFirst, ID idLast=LARGESTID);
		unsigned long GetFreeRangeFirst() {return m_dsFree.m_ulFirst;}
		unsigned long GetFreeRangeLast() {return m_dsFree.m_ulFirst;}
		
		void SetWorkIDRange(ID idFirst, ID idLast);
		unsigned long GetWorkRangeFirst() {return m_idWorkRangeFirst;}
		unsigned long GetWorkRangeLast() {return m_idWorkRangeLast;}

		bool IsWorkRangeEmpty() { return true;}
		bool IsFreeRangeEmpty() { return true;}

		unsigned long GetNbLocallyAvailableIDs();
		unsigned long GetNbIdRemainingInFreeRange();

		unsigned long GetLocalID();
		ID GetID();

		//RMC methods
		void GetIDRange(unsigned long ulNbRequestedID, ID* pidFirst, ID* pidLast);

	private:
	
		CriticalSection m_cs;
		unsigned long GetNbAvailableIDs();

#ifdef _TEST_ENABLED
		/* {Secret} */
		static bool Test();
#endif

	private:
		//New
		ID m_idWorkRangeFirst;
		ID m_idWorkRangeLast;
};

#endif
