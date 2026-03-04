//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Wrappers_H_
#define _Wrappers_H_

#include <Platform/PlatformDecl.h>

#ifdef linux
//#include <stdio.h>
//#include <string.h>

#define _tmain		main

#define _tprintf	printf
#define _stprintf	sprintf
#define _vstprintf	vsprintf
#define	_ftprintf	fprintf

#define _tfopen		fopen


#define _tcscat		strcat
#define lstrcat		strcat
#define _tcscmp		strcmp
#define _tcscpy		strcpy
#define _tcsncpy	strncpy
#define _tcslen		strlen
#define _tcschr		strchr
#define _tgetenv	getenv

#define _ttoi		atoi
#define	_getts		gets
#define	_fgetts		fgets

#define closesocket(a) close(a)

void _tcsupr(TCHAR* strString);


#endif

#endif
