//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Defs_H_
#define _Defs_H_

#define WAIT_INFINITE			0xFFFFFFFF

#ifdef linux
//#define SYSTEMCHECK(a) 	assert(a)
#define STDCALL
#define CALLBACK
#define WINAPI
#define INVALID_HANDLE_VALUE	0xFFFFFFFF
#define ERROR_SUCCESS			0
#define GetLastOSError()		errno
#define IN_ADDR					struct in_addr
#define LPIN_ADDR				IN_ADDR*
#define IN_ADDR_ADDRESS(a)		a.s_addr
#define LPHOSTENT				struct hostent*
#define INVALID_SOCKET			-1
#define SOCKET_ERROR			-1
#define SOCKADDR_IN				struct sockaddr
#define __CDECL
#ifndef NULL
#define NULL					0
#endif
#endif

#ifdef WIN32
#define __CDECL	__cdecl
#define STDCALL	__stdcall
#define IN_ADDR_ADDRESS(a)	a.S_un.S_addr
#define socklen_t               int
#define GetLastOSError()		GetLastError()
#endif

#endif
