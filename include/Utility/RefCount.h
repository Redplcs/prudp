//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _RefCount_H_
#define _RefCount_H_

#include <Utility/UtilityDecl.h>
// Group=Utility Subsystem

#include <Platform/SystemCheck.h>

class RefCount {
	// Group=
	public:
		RefCount();
		~RefCount();

		unsigned int GetRefCount() const;
		void IncreaseRefCount();
		void DecreaseRefCount();

	private:
		unsigned int m_uiRefCount;
};

#endif
