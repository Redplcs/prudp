//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

// This file must have the name of the DOClass that it implements, RootDO

#ifndef _RootDO_H_
#define _RootDO_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/RootDODDL.h>
#include <ObjDup/DuplicationSpace.h>
#include <ObjDup/SessionSpace.h>
#include <ObjDup/DuplicaLocationSet.h>


class RootDO: public DOCLASS(RootDO) {
	public:
		RootDO();
		~RootDO();

		bool IsDuplicatedOn(DOHandle hLocation);

		bool AddDuplicaLocation(DOHandle hStation,
								bool bUpdateLocationSet,
								bool bAlwaysSendMessage=false,
								DOHandle hAvailableRouting=INVALID_DOHANDLE);

		void RemoveDuplicaLocation(DOHandle hLocation);
		void ClearLocationSet();

		// This method is called on a duplica as a result of a
		// relevance check.
		void DeleteLocalDuplica();
		// This method is called on a master or a duplica, as a result
		// of a match operation.
		void CreateDuplicaIfRequired(DOHandle hLocation, bool bUpdateLocationSet);

		IteratorOverDOs* CreateRegularLocationIterator();

	private:
		// RegularLocationSetIterator: rename MulticastIterator?
		DuplicaLocationSet m_lsRegularLocationSet;
};

#endif
