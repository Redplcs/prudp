//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _PlatformImpl_H_
#define _PlatformImpl_H_

#include <Platform/PlatformDecl.h>
#include <Platform/SystemCheck.h>

#ifndef _TEST_ENABLED
// {Secret}
// The following modules should be in ifdefs...
// But makedepend does not work well when some includes are between ifdefs.  The easy
// solution is to define the macros that protect them!
#define _UnitTesting_H_
#endif

#include <Platform/Platform.h>
#include <Platform/UnitTesting.h>
#include <Platform/LeakTracker.h>
#include <Platform/SystemError.h>
#include <Platform/Tokenizer.h>

#ifdef UNDER_CE
#include <winbase.h>
#include <wingdi.h>
#include <winuser.h>
#endif

#endif

