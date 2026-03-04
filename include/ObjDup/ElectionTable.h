//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, ElectionTable.h

#ifndef _ElectionTable_H_
#define _ElectionTable_H_

#include <ObjDup/ObjDupDecl.h>

#include <list>
#include <ObjDup/DOHandle.h>

class ElectionTable {
	public:
		ElectionTable();
		~ElectionTable();

		// Entry point.
		DOHandle ElectNewMaster(DOHandle hObject, DOHandle hFaultyMaster, DOHandle hCalleeStation);

#ifdef _TEST_ENABLED
		static bool Test();
#endif

	private:
		// Implementation.
		
		typedef std::pair<DOHandle,DOHandle> ElectionID;
		typedef struct _TableEntry {
			ElectionID m_id;
			DOHandle m_hResult;
			Time m_tExpiration;
		} TableEntry;

		DOHandle SearchPreviousElectionResult(ElectionID idElection);
		void StoreNewElectionResult(ElectionID idElection, DOHandle hResult, TimeInterval tiLifeTime);

		std::list<TableEntry> m_lstTableEntries;
};

#endif
