//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _RefCountedObject_H_
#define _RefCountedObject_H_

#include <Utility/UtilityDecl.h>
#include <Utility/RefCount.h>
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

	unsigned long GetRefCount();

private:
	bool			m_bDeletingFromRelease;
	RefCount		m_oRefCount;
	CriticalSection	m_oCS;
};


#endif
