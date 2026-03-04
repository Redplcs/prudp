//  
//   (c) Copyright 1998-1999, Quazal
//   ALL RIGHTS RESERVED
//  
//  
//   Last modification:	$Date: 2001/10/26 16:11:38 $
//   Current Revision:	$Revision: 1.16.8.1 $
//  
//   Id: $Id: Win32.h,v 1.16.8.1 2001/10/26 16:11:38 cdionne Exp $

#ifndef _Win32_H_
#define _Win32_H_


#ifndef UNDER_CE
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#else
#include <winsock.h>
#endif
#include <windows.h>
#ifndef UNDER_CE
#include <process.h>
#endif
#include <tchar.h>
#ifndef UNDER_CE
#include <time.h>
#endif

#ifndef UNDER_CE
#define USE_WINSOCK2
#endif

#include "Defs.h"


#endif
