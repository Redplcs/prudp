//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SYSTEMCHECK_H_
#define _SYSTEMCHECK_H_

#include <Platform/PlatformDecl.h>

#define SYSTEMCHECK(C) Platform::SystemCheck(C,_T(#C),_T(__FILE__),__LINE__)

#endif
