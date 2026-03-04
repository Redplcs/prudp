//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/SelectionByProperty.h>

#ifndef _DuplicationSBP_H_
#define _DuplicationSBP_H_

// Group = Miscellaneous Types and Macros

/*
Summary: A Duplication master is a duplicated object that is controlled 
by the local station. The Duplication master can update the values of 
its datasets, an operation that a Duplica cannot perform. 

See Also: Duplication master, MasterIDChangeOperation
*/
#define DUPLICATION_MASTER	0

/*
Summary: A Duplica is a copy of a duplicated object that is controlled by 
a remote station. Its datasets are updated remotely, automatically,
and transparently by $PRODUCTNAME$ whenever its Duplication master performs an update. 

See Also: Duplica, MasterIDChangeOperation
*/
#define DUPLICA				1

// {Secret}
class DuplicationSBP: public SelectionByProperty {
	public:
		DuplicationSBP() {};
		~DuplicationSBP() {};

		void Create() {
			SelectionByProperty::Create(2,Selection::AutomaticRemoval | Selection::IteratorsLockRole );
		}
};

#endif
