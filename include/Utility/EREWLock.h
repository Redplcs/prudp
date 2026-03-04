//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This is a solution to the single writer, multiple reader problem.
// 

#ifndef _EREWLock_H_
#define _EREWLock_H_

#include <Utility/UtilityDecl.h>
#include <Platform/CriticalSection.h>

// An EREWLock is simply a CriticalSection with a different interface.

class EREWLock: private CriticalSection {
	public:
		EREWLock() {}
		~EREWLock() {}

		void BeginReading() {Enter();}
		void EndReading() {Leave();}

		void BeginWriting() {Enter();}
		void EndWriting() {Leave();}

#ifdef _TEST_ENABLED
		static bool Test();
#endif
};


#endif

 
