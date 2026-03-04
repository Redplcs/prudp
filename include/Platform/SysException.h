//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SysException_H_
#define _SysException_H_

#include <Platform/PlatformDecl.h>

class SysException {
public:
	#ifdef WIN32
    SysException(TCHAR *strContext, unsigned long ulExceptionCode, void *pExPtrs);
	#else
    SysException(TCHAR *strContext);
	#endif
    ~SysException() {}

    TCHAR *GetContext() { return m_strContext; }
	#ifdef WIN32
	unsigned long GetExceptionCode() { return m_ulExceptionCode; }
	void *GetExceptionPtrs() { return m_pExPtrs; }
	#endif

	void Trace(unsigned long ulFlags=TRACE_SYSTEMCHECK);

private:
	#ifdef WIN32
	void				*m_pExPtrs;
	unsigned long		m_ulExceptionCode;
	#endif
	TCHAR				*m_strContext;
};



#endif
