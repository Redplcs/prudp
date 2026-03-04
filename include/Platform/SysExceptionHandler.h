//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _SysExceptionHandler_H_
#define _SysExceptionHandler_H_

#include <Platform/PlatformDecl.h>
class SysException;
#ifdef WIN32
extern "C" {
unsigned long __cdecl _exception_code();
void* __cdecl _exception_info();
}
#endif

//Group= System Errors

/*


An SysExceptionHandler is used to catch exceptions raised in the user
callbacks.  An SysExceptionHandler is required since some of these
callbacks are executed in the context of a system thread.

*/
class SysExceptionHandler {
	// group=
	public:
		SysExceptionHandler();

/*
Summary: Called when an exception has been raised in a user callback.

Parameters:
  strClass: Name of the class in which the user callback is defined.
  strCallback: Name of the user callback that raised the exception.
*/
		virtual void CatchSysException(SysException *e);

		#ifdef WIN32
		// {Secret}
		static unsigned long SignalSysException(TCHAR *szContext1, TCHAR *szContext2, unsigned long ulCode, 
					void *pExPtrs, bool bUser);
		#else
		// {Secret}
		static unsigned long SignalSysException(TCHAR *szContext1, TCHAR *szContext2, bool bUser);
		#endif

/*
Summary: Registers a user-defined SysExceptionHandler.

Parameters:

  pHandler: Pointer to an object of type SysExceptionHandler.  This is
typically a pointer to a subclass of the SysExceptionHandler class,
where the virtual methods SignalSysException have been redefined.

Throws: SYSTEMERROR_GEN_MULTIPLE_SYSTEMERROR_HANDLER_NOT_ALLOWED

*/
		static bool Register(SysExceptionHandler* pHandler);
/*
Summary: Unregisters a user-defined SysExceptionHandler.

Returns: A pointer to a previously register SysExceptionHandler.  NULL if none was registered.
*/
		static SysExceptionHandler* Unregister();

/*
Summary: Turns on the tracing of all exceptions that occur in a user callback.

Remarks: This is the default behavior of an SysExceptionHandler.

See also: TraceOn
*/
		static void TraceOn() {s_bTrace=true;}
/*
Summary: Turns off the tracing of all exceptions that occur in a user callback.

See also: TraceOff
*/
		static void TraceOff() {s_bTrace=false;}

		// {Secret}
		static void CatchExceptions() {s_bThrow=false;}
		// {Secret}
		static void ThrowExceptions() {s_bThrow=true;}

		// {Secret}
        #ifdef _TEST_ENABLED
		static void UnitTestingShouldNotFail() {s_bUnitTestingShouldFail=false;}
		// {Secret}
		static void UnitTestingShouldFail() {s_bUnitTestingShouldFail=true;}
        #endif

#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
#endif

	private:
		static SysExceptionHandler* s_pInstance;
		static bool s_bTrace;
		static bool s_bThrow;
		#ifdef _TEST_ENABLED
		static bool s_bUnitTestingShouldFail;
		#endif
};

#ifdef WIN32

#define TRY_SYS_EXCEPTIONS	__try 

#define CATCH_USER_SYS_EXCEPTIONS(CONTEXT1, CONTEXT2)\
	__except (SysExceptionHandler::SignalSysException(CONTEXT1, CONTEXT2,\
			_exception_code(),(void*)_exception_info(),true)){}

#define CATCH_SYS_EXCEPTIONS(CONTEXT1, CONTEXT2)\
	__except (SysExceptionHandler::SignalSysException(CONTEXT1, CONTEXT2,\
			_exception_code(),(void*)_exception_info(),false)){}

#else
#ifdef linux
#define TRY_SYS_EXCEPTIONS	try 

#define CATCH_USER_SYS_EXCEPTIONS(CONTEXT1, CONTEXT2)\
	catch (...) {SysExceptionHandler::SignalSysException(CONTEXT1, CONTEXT2, true);}

#define CATCH_SYS_EXCEPTIONS(CONTEXT1, CONTEXT2)\
	catch (...) {SysExceptionHandler::SignalSysException(CONTEXT1, CONTEXT2, false);}

#else
#define TRY_SYS_EXCEPTIONS	
#define CATCH_USER_SYS_EXCEPTIONS(CONTEXT, CB)
#define CATCH_SYS_EXCEPTIONS(CONTEXT, CB)
#endif
#endif

#endif
