//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _RefCountedObject_H_
#define _RefCountedObject_H_

#include <Platform/PlatformDecl.h>
#include <Platform/CriticalSection.h>

#ifdef _TEST_ENABLED
#define ACQUIREREF(a) a->AcquireRef(_T(__FILE__),__LINE__)
#define RELEASEREF(a) a->ReleaseRef(_T(__FILE__),__LINE__)
#else 
#define ACQUIREREF(a) a->AcquireRef()
#define RELEASEREF(a) a->ReleaseRef()
#endif

class RefCountedObject {

public:
	RefCountedObject();
	virtual	~RefCountedObject();

	#ifdef _TEST_ENABLED
	RefCountedObject  	*AcquireRef(TCHAR *szFile, unsigned long ulFileNo);
	void   				ReleaseRef(TCHAR *szFile, unsigned long ulFileNo);
	#else
	RefCountedObject  	*AcquireRef();
	void   				ReleaseRef();
	#endif

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif

	unsigned short GetRefCount();

private:
	bool			m_bDeletingFromRelease;
	unsigned short	m_usRefCount;
	CriticalSection	m_oCS;
};


#endif
