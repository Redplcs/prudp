//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/DOHandle.h>

#include <ObjDup/Selection.h>

#ifndef _DuplicaLocationSet_H_
#define _DuplicaLocationSet_H_

// The DuplicaLocationSet is a class than encapsulates a set of stations where
// DO are duplicated.  

// This particular location set is implemented using a Selection.  This
// is the location set used by default for all duplication spaces.

class DuplicaLocationSet {
	public:
		DuplicaLocationSet();
		virtual ~DuplicaLocationSet();

		void Add(DOHandle hLocation);
		void Remove(DOHandle hLocation);
		void Clear();
		
		bool IsAMember(DOHandle hLocation);
		unsigned int GetSize();
		IteratorOverDOs* CreateLocationIterator();

#ifdef _TEST_ENABLED
		static bool Test(DOClassID idTestObjectClass);
#endif
		
	private:
		Selection m_oSelection;
};

#endif
