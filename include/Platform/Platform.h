//  
//   (c) Copyright 1998-1999, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Platform_H_
#define _Platform_H_

#include <Platform/PlatformDecl.h>
class ErrorDescriptionTable;

#if defined(linux) && defined(UNICODE)
#error NO SUPPORT FOR UNICODE UNDER LINUX
#endif

#pragma warning(disable : 4786)
#pragma warning(disable : 4291)
#ifdef UNDER_CE
#pragma warning(disable : 4530)
#endif

#ifdef APPLY_PATCHES
#include <../bugs/bugs.patches>
#endif


// {Secret}
class Platform {
public:
	Platform();
	~Platform();

	static Platform *Instance();	
	static void CreateInstance();
	static void DeleteInstance();
	
	#ifdef _TEST_ENABLED
	static bool Test();
	#endif
	
	static void Sleep(unsigned long ulTime);
	static void SystemCheck(bool bExpression, TCHAR* strExpression, TCHAR* strFile, unsigned long ulLine);

private:
	static int AssertTranslator( int ReportType, char *UserMsg, int *RetVal );

private:
	static	Platform		*_Instance;
	ErrorDescriptionTable	*m_pedtGeneral;
};

#endif
