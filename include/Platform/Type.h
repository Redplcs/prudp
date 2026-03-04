//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Type_H_
#define _Type_H_

#ifdef WIN32
typedef __int64 _LONGLONG;
typedef unsigned __int64 _ULONGLONG;
#endif

#ifdef linux
typedef long long int	_LONGLONG;
typedef long long unsigned int	_ULONGLONG;

#define HANDLE	unsigned long

#define _T(a)	a
#define LPSTR	char*
#define LPTSTR	LPSTR
#define TCHAR	char

#endif


#endif
