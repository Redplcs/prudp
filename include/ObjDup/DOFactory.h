//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DOFactory_H_
#define _DOFactory_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/WKHandle.h>
#include <ObjDup/DuplicatedObject.h>

// Group=Object Duplication Subsystem

class DOClass;

class DOFactory {
	// Group=
	private:
		// Cannot be instanciated...
		DOFactory() {}
#ifdef linux
	protected:
		// These methods should be private.  However, gcc does not like
		// having a private destructor.
#else
	private:
#endif
		~DOFactory() {}

	private:

		static DuplicatedObject* CreateDO(unsigned long ulClassID);

	public:

		static DuplicatedObject* CreateWellKnownDO(WKHandle hDO);
		static DuplicatedObject* CreateDuplicationMaster(unsigned long ulClassID);
		static DuplicatedObject* CreateDuplica(DOHandle id, unsigned long ulManagerID);
		static DuplicatedObject* CreateDuplica(DOHandle id, DOHandle hMasterStation);
		static void DeleteDO(DuplicatedObject* pDO);
};

#endif
