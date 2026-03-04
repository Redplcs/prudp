//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _IDGenerator_H_
#define _IDGenerator_H_

#include <Utility/UtilityDecl.h>

// Group=Utility Subsystem

typedef unsigned long ID;

#define MAXID	((ID)-2)	

class IDGenerator {
	public:
		IDGenerator();
		IDGenerator(ID idMin, ID idMax);

		~IDGenerator() {};

		IDGenerator& operator=(const IDGenerator& oIDGen);

		bool GetID(ID* pID);
		bool GetIDRange(unsigned long ulNbRequestedID, ID* pidFirst, ID* pidLast);

		unsigned long GetNbAvailableIDs();
		bool IsNewIDGenerator() {return m_idFirst==0 && m_idAfterLast==0;}

		void SetIDRange(ID idFirst, ID idLast);

		void RemoveFromIDRange(ID id);

#ifdef _TEST_ENABLED
		/* {Secret} */
		static bool Test();
#endif

	private:
		ID m_idFirst;
		// We store the ID past the last one. e.g., if the last ID that
		// can be allocated is 5, m_idAfterLast is 6.  This makes
		// easier to indicate an object that has no IDs available
		// (m_idFirst==m_idAfterLast)
		ID m_idAfterLast; 
};

#endif
