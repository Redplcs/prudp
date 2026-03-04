//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, DefaultCellParameter.h

#ifndef _DefaultCellParameter_H_
#define _DefaultCellParameter_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/DefaultCellParameterDDL.h>

class DefaultCellParameter: public DATASET(DefaultCellParameter) {
	public:
		DefaultCellParameter() {}
		~DefaultCellParameter() {}
};

#endif
