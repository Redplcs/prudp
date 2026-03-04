//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/SelectionByProperty.h>

#ifndef _DeletionSBP_H_
#define _DeletionSBP_H_

#define MARKED_FOR_DELETION			0
#define MARKED_FOR_LOCAL_DELETION	1

// Group=Object Duplication Subsystem

class DeletionSBP: public SelectionByProperty {
	// Group=
	public:
		DeletionSBP() {};
		~DeletionSBP() {};

		void Create() {
			SelectionByProperty::Create(2, Selection::AutomaticRemoval);
		}
};

#endif
