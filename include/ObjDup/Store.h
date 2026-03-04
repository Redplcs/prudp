//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Store_H_
#define _Store_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/Collection.h>
#include <map>

// Group=Utility Subsystem

class Selection;

class Store: public Collection {
	// Group=
	public:
		Store();
		virtual ~Store();
		void Clear();
		
		virtual void DestroyItem(CollectionItem *pItem, DOHandle hDO)=0; 
		
		bool AddToStore(DOHandle hDO, CollectionItem* pItemValue);
        bool RemoveFromStore(DOHandle hDO);
		CollectionItem* AcquireRef(DOHandle hDO);
		
		// This method can be used to decrease the refcount of the item.
		bool ReleaseRef(DOHandle hDO, bool bMainReference=false);

		unsigned int GetRefCount(DOHandle hDO);

		CriticalSection& GetStoreCS();


	protected:

		std::list<Selection*> m_listSelection;
		CriticalSection m_csStore;
};

#include <ObjDup/Selection.h>

#endif
