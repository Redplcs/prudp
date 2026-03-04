//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, Range.h

#ifndef _Range_H_
#define _Range_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/RangeDDL.h>

class Range: public DATASET(Range) {
	public:
		Range();
		~Range();

		unsigned long GetFirst() {return m_ulFirst;}
		unsigned long GetLast() {return m_ulLast;}
};

#endif
