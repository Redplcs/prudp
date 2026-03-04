//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#include <ObjDup/ObjDupDecl.h>
class SelectionByProperty;
#include <ObjDup/DuplicationSBP.h>
#include <ObjDup/DeletionSBP.h>

#ifndef _DOSBP_H_
#define _DOSBP_H_

//Group = Miscellaneous Types and Macros

/*
Summary: All of the duplicated objects are kept in an object store on each 
station. Duplication master and Duplica consist of selections from that store.
The PropertyCategory refers to the category of selection store.  

Remarks: The Property Category value can be any one of the following constants:

SBP_DUPLICATION - Both the Duplication master and Duplica selections 
of the object store belong to this category of selections of store.
*/
typedef enum {
// {Secret}
	SBP_DUPLICATION,
// {Secret}
	SBP_DELETION
} PropertyCategory;

/*
{Secret}
Group=Object DO Subsystem
*/
class DOSBP {
	// Group=
	public:
		DOSBP();
		~DOSBP();

		void Create();
		SelectionByProperty* GetSBP(PropertyCategory ulSBPType);

	private:
		DuplicationSBP m_sbpDuplication;
		DeletionSBP m_sbpDeletion;
};

#endif
