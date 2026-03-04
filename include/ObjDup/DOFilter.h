//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DOFilter_H_
#define _DOFilter_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOHandle.h>
class DuplicatedObject;

// TODO: DOFilters can be optimized, by specifying a range of DOHandle
// than can pass - e.g. based on min and max ClassID.  This would speed
// up iteration.

/*

summary:  
DOFilter is the class that filters...

*/
class DOFilter {
	public:
		DOFilter();
		virtual ~DOFilter();

		virtual bool Filter(DuplicatedObject* pDO)=0;
		virtual bool Filter(DOHandle hDO)=0;

		// In some cases the minimum or maximum values can be known,
		// and used to speed up iterators.
		virtual DOHandle GetMinimumValidHandle();
		virtual DOHandle GetMaximumValidHandle();

		bool HandleIsWithinRange(DOHandle hHandle);

	protected:
};

#endif
