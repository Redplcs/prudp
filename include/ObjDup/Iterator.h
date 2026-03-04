//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Iterator_H_
#define _Iterator_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/Collection.h>
#include <ObjDup/DORef.h>

class Iterator {
	// Group=
	public:
		Iterator();
		Iterator(Collection* pCollection);
		Iterator(const Iterator& it);
		virtual ~Iterator();

		void SetCollection(Collection* pCollection);

		Iterator& Find(DOHandle hDO);
		Iterator& GotoStart();
		Iterator& GotoEnd();
		Iterator& operator++();
		Iterator& operator++(int iDummy);
		bool EndReached();
		bool Advance();

		DOHandle GetHandle();
        CollectionItem* GetContent();

		// {secret}
		void AddItemWithMainRefDeleted();

	private:
		DORef m_refCurrentItem;
		Collection *m_pCollection;
		bool m_bSkipIfMainRefDeleted;
};

#endif
