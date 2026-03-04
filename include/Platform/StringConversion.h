//  
//   (c) Copyright 1998-1999, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _StringConversion_H_
#define _StringConversion_H_
#include <Platform/PlatformDecl.h>


class StringConversion {
	public:

// Unicode
#ifdef UNICODE 
	static void A2T(const char* szASrc, TCHAR* szTDest, unsigned int uiDestLength);
	static void T2A(const TCHAR* szTSrc, char* szADest, unsigned int uiDestLength);

#ifndef linux
	static void T2W(const TCHAR* szTSrc, wchar_t* szWDest, unsigned int uiDestLength);
	static void W2T(const wchar_t* szWSrc, TCHAR* szTDest, unsigned int uiDestLength);
#endif
#endif

// ANSI
#ifndef UNICODE 
	static void A2T(const char* szASrc, TCHAR* szTDest, unsigned int uiDestLength);
	static void T2A(const TCHAR* szTSrc, char* szADest, unsigned int uiDestLength);

#ifndef linux
	static void T2W(const TCHAR* szTSrc, wchar_t* szWDest, unsigned int uiDestLength);
	static void W2T(const wchar_t* szWSrc, TCHAR* szTDest, unsigned int uiDestLength);
#endif
#endif

#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
#endif

};

#endif
