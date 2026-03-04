//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Config_H_
#define _Config_H_

#include <Platform/PlatformDecl.h>

#ifdef WIN32
#pragma warning(disable:4786)
#endif

#ifdef linux
#define ENV_VARIABLE_SUPPORT
//#define FILE_VARIABLE_SUPPORT
#endif

#ifdef WIN32
#define REGISTRY_VARIABLE_SUPPORT
//#define FILE_VARIABLE_SUPPORT
#ifndef UNDER_CE
#define ENV_VARIABLE_SUPPORT
#endif
#endif

#ifdef WIN32
#ifndef UNDER_CE
#define THREAD_SCHEDULER_SUPPORT
#endif
#endif

#endif
