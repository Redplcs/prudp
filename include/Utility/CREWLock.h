//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This is a solution to the single writer, multiple reader problem.
// 

#ifndef _CREWLock_H_
#define _CREWLock_H_

#include <Utility/UtilityDecl.h>
#include <Platform/CriticalSection.h>

class CREWLock {
	public:
		CREWLock(bool bBeFair=false);
		~CREWLock();

		void BeginReading();
		void EndReading();

		void BeginWriting();
		void EndWriting();
		
		CriticalSection* GetCriticalSection();

	#ifdef _TEST_ENABLED
		static bool Test();
	#endif

	private:
		unsigned long m_ulNbReaders;
		CriticalSection m_csWW; 
		CriticalSection m_csNbReaders;
		CriticalSection m_csAccess;

		bool m_bBeFair;
};


#endif

 
