//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

// This file must have the name of the DOClass that it implements, DefaultCell

#ifndef _DefaultCell_H_
#define _DefaultCell_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DefaultCellDDL.h>

class DefaultCell: public DOCLASS(DefaultCell) {
	public:
		DefaultCell() {}
		~DefaultCell() {}

		bool ApproveFaultRecovery() {return true;}
		bool ApproveEmigration(unsigned long ulReason) {return true;}
};

#endif
