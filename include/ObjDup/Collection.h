//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Collection_H_
#define _Collection_H_

#include <ObjDup/ObjDupDecl.h>

#include <Platform/CriticalSection.h>
#include <Platform/ScopedCS.h>

#include <Platform/SystemError.h>
#include <ObjDup/CollectionItem.h>
#include <ObjDup/DOHandle.h>
#include <map>
#include <list>
class DORef;

// Group=Utility Subsystem

class Iterator;
class Store;

class Collection {
	// Group=
	public:
		Collection();
		virtual ~Collection();

		bool AddToCollection(DOHandle hDO, CollectionItem* pItemValue);
		bool RemoveFromCollection(DOHandle hDO);
		unsigned int GetSize() const;

		bool FindItem(DOHandle hItemToFind, DORef* prefItem=NULL);
		CollectionItem* GetObjectPtr(DOHandle hItemToFind);
		
		DOHandle GetFirst(bool bSkipIfMainRefDeleted);
		DOHandle GetNext(DOHandle hDO, bool bSkipIfMainRefDeleted);

		Store* GetStorePtr();

		
	protected:
		std::map<DOHandle, CollectionItem*> m_map;
};

#include <ObjDup/Iterator.h>

#endif
