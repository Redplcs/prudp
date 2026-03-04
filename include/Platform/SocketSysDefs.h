//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _SocketSysDefs_H_
#define _SocketSysDefs_H_

#ifdef WIN32
#ifndef UNDER_CE
#define USE_WINSOCK2
#endif
#endif

#ifdef WIN32
#ifdef USE_WINSOCK2
#include <winsock2.h>
#else
#include <winsock.h>
#endif
#endif
#ifdef linux
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#endif

#ifdef USE_WINSOCK2
#define	SOCKET_WOULD_BLOCK		WSAEWOULDBLOCK			
#define SOCKET_NOT_CONNECTED	WSAENOTCONN
#else 
#define SOCKET_NOT_CONNECTED	ENOTCONN
#ifndef WIN32
#define FROM_LEN				size_t
#define SD_SEND					SHUT_WR
#define SD_RECV					SHUT_RD
#define SD_BOTH                 SHUT_RDWR
#define WSAOVERLAPPED			unsigned long
#define SOCKET int
#define	SOCKET_WOULD_BLOCK		EAGAIN			
#define	SOCKET_WAS_CLOSED		EAGAIN			
#else
#ifdef UNDER_CE
#define SD_RECV					0
#define SD_SEND					1
#define SD_BOTH                 2
#endif
#define FROM_LEN				int
#define	SOCKET_WOULD_BLOCK		WSAEWOULDBLOCK			
#define	SOCKET_WAS_CLOSED		WSAECONNRESET			
#endif

#endif

#endif
