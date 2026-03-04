//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Selection_H_
#define _Selection_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/Collection.h>
#include <ObjDup/Selection.h>
#include <ObjDup/Store.h>
#include <Utility/Callback.h>
#include <map>

class DOOperation;

class Selection: public Collection {
	// Group=
	public:
		typedef enum _Flags {
			OwnsReference=1,
			AllowsEarlyAdditions=2,
			Active=4,
			IteratorsLockRole=8,
			AutomaticRemoval=16,
		} Flags;

		
		Selection(unsigned char ucFlags);
		virtual ~Selection();

		bool FlagIsSet(unsigned char ucFlag) const {return (m_ucFlags & ucFlag)==ucFlag;}

		void Clear();

		void RemoveFromStoreOperationEnd(DOOperation* pOperation);
		void RoleChangeOperationBegin(DOOperation* pOperation);

		// Acquires a reference to an item from the store.
		//
		// Throws:
		//
		//   SYSTEMERROR_GEN_DUPLICATED_KEY: The key was already found
		//     in the Selection.  Nothing happens.
		//   SYSTEMERROR_GEN_ITEM_NOT_FOUND: The item does not exist in
		//     the store.  Nothing happens.
		bool Acquire(DOHandle hDO);

		// Release a reference to an item.
		bool Release(DOHandle hDO);

	private:
#ifdef _DEBUG_CHECK
		Store* m_pStore;
#endif
		unsigned char m_ucFlags;
		
		Callback<Selection, DOOperation*>* m_pcbRemoveFromStore;
		Callback<Selection, DOOperation*>* m_pcbRoleChange;
};

#endif
