//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ScopedCS_H_
#define _ScopedCS_H_

#include <Utility/UtilityDecl.h>
#include <Platform/CriticalSection.h>

// Group=Utility Subsystem

class ScopedCS {
	// Group=
	public:
		ScopedCS(CriticalSection &pCS, TCHAR* strName=_T("<unspecified>"));
		~ScopedCS();
	private:
		CriticalSection *m_pCS;
};

#endif
