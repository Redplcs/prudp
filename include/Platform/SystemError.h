//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|1|R|     Subsystem         |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      R - is a reserved bit
//
//      Subsystem - is the Subsystem code
//
//      Code - is the Subsystem's status code
//
//
// Define the facility codes
//

#ifndef _SystemError_H_
#define _SystemError_H_

#include <Platform/PlatformDecl.h>

#ifndef UNDER_CE
#define CPP_EXCEPTION_SUPPORT
#endif

#define SEV_SUCCESS							0x0
#define SEV_INFORMATIONAL					0x1
#define SEV_WARNING							0x2
#define SEV_ERROR							0x3

#define SUBSYSTEM_GENERAL					0x0
#define SUBSYSTEM_NETWORK					0x1
#define SUBSYSTEM_DC						0x2	
#define SUBSYSTEM_OBJDUP					0x3
#define NUMBER_OF_SUBSYSTEMS				4
#define SUBSYSTEM_NONE						0x10

#define SET_ERROR_CODE(SEV,SUBSYS,STATUS)	((SEV<<30)|(1<<29)|(SUBSYS<<16)|STATUS)
#define ERROR_IS_WIN32(ERRCODE)				((ERRCODE&(0x1<<29))==0)
#define GET_SUBSYSTEM(ERRCODE)				((ERRCODE>>16)&0xFFF)
#define GET_STATUS(ERRCODE)					(ERRCODE&0xFFFF)
#define GET_SEVERITY(ERRCODE)				((ERRCODE>>30)&0x3)

// {secret}
// SUBSYSTEM_NONE Error Codes
#define	SYSTEMERROR_FACADE_NOT_INITIALIZED	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_NONE,0)

#if 0
#ifdef NO_SYSTEMERROR_SUPPORT
#define TRY { SystemError::_ClearException(); __try
#define CATCH_EXCEPTION __except (SystemError::_HandleException())
#define CATCH_SYS_EXCEPTION 
#define CATCH_ALL __except (EXCEPTION_EXECUTE_HANDLER)
#define SYSTEMERROR_CODE		SystemError::_GetErrorCode()
#define SYSTEMERROR_EXTCODE	SystemError::_GetExtErrorCode()
#define SYSTEMERROR_STRING(s,l)	SystemError::_GetErrorString(SYSTEMERROR_CODE,s,l)
#define TRACE_EXCEPTION(f)	SystemError::_Trace(f)
#define END_TRY				SystemError::_ClearException(); }
#ifdef _TEST_ENABLED
#define THROW_EXCEPTION(Code,ExtCode) SystemError::_Throw(_T(__FILE__),__LINE__,Code,ExtCode);
#else
#define THROW_EXCEPTION(Code,ExtCode) SystemError::_Throw(NULL,0,Code,ExtCode); 
#endif
#else
#define TRY try
#define CATCH(e) catch (SystemError &e)
#define CATCH_SYS_EXCEPTION(e) catch (SysException &e)
#define CATCH_ALL catch (...)
#define END_TRY 
#define SYSTEMERROR_CODE		e.GetErrorCode();
#define SYSTEMERROR_EXTCODE	e.GetExtErrorCode();
#define TRACE_EXCEPTION		e.Trace();
#endif
#endif

#ifdef _TEST_ENABLED
#define SIGNAL_SYSTEMERROR(Code,ExtCode) SystemError::SignalError(_T(__FILE__),__LINE__,Code,ExtCode);
#define THROW_EXCEPTION throw SystemError(_T(__FILE__),__LINE__).SetErrorInfo
#else
#define SIGNAL_SYSTEMERROR(Code,ExtCode) SystemError::SignalError(NULL,0,Code,ExtCode);
#define THROW_EXCEPTION throw SystemError(NULL,0).SetErrorInfo
#endif

#ifdef UNDER_CE
#undef THROW_EXCEPTION
// #define try	error EH not supported
// #define catch error EH not supported.
#endif


#ifdef _TEST_ENABLED
#define NEW_EXCEPTION fnew SystemError(_T(__FILE__),__LINE__)
#else
#define NEW_EXCEPTION fnew SystemError(NULL,0)
#endif

// Group = System Errors
/*
description:
There was not enough memory to complete the operation.
*/
#define	SYSTEMERROR_GEN_NOT_ENOUGH_MEM	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,0)

/*
{Secret}
*/
#define	SYSTEMERROR_GEN_ILLEGAL_ACCESS	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,1)

/*
description:
An underlying WIN32 operation has failed.  The WIN32 error code can be
retreived with SystemError::GetLastExt
*/
#define	SYSTEMERROR_GEN_WIN32_ERROR		SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,2)

/*
{Secret}
*/
#define	SYSTEMERROR_GEN_INDEX_OOB			SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,3)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_DUPLICATED_KEY	SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL,4)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_ITEM_NOT_DELETED	SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL,5)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_ITEM_NOT_FOUND	SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL,6)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_END_OF_COLLECTION	SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL,7)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_OBJ_NOT_INIT		SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,8)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_NOT_IMPLEMENTED	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,9)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_OUT_OF_ID			SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL, 10)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_INTERNAL			SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL, 11)

/*
description:
The delay allowed for an operation to occur has expired.
*/
#define SYSTEMERROR_GEN_TIMEOUT			SET_ERROR_CODE(SEV_ERROR, SUBSYSTEM_GENERAL, 12)

/*
{Secret}
*/
#define SYSTEMERROR_GEN_CHILDPROCESS_FAILED SET_ERROR_CODE(SEV_WARNING, SUBSYSTEM_GENERAL, 13)

/*
description:
An operation has been called in an invalid context.
*/
#define SYSTEMERROR_GEN_INVALID_OPERATION	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,14)

/*
description:
An attempt was made at instanciating more than one $PRODUCTNAME$ object in the same process.
*/
#define SYSTEMERROR_GEN_MULTIPLE_INSTANCES SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,15)

/*
{secret}
description:
An attempt to register more than one ExceptionHandler was made.
*/
#define SYSTEMERROR_GEN_MULTIPLE_EXCEPTION_HANDLER SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,16)

/*
description:
An attempt to use an expired version of $PRODUCTNAME$ was made.
*/
#define SYSTEMERROR_GEN_EXPIRED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,17)

/*
description:
A method was called with a parameter that is out of range.
*/
#define SYSTEMERROR_GEN_OUT_OF_RANGE SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,18)

//{secret}
#define SYSTEMERROR_GEN_ASSERTION_FAILED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,19)

//{secret}
#define SYSTEMERROR_GEN_DEADLOCK_DETECTED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,20)

/*
description:
$PRODUCTNAME$ has not been initialized.
*/
#define SYSTEMERROR_GEN_NOT_INITIALIZED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,21)

/*
description:
An invalid parameter, which is typically NULL, was passed to a method.
*/
#define SYSTEMERROR_GEN_INVALID_PARAMETER SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,22)

//Description: An invalid input was passed to a method.
#define SYSTEMERROR_GEN_IO_ERROR SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,23)

/*
description:
The product key used for $PRODUCTNAME$ does not exist or is invalid.
*/
#define SYSTEMERROR_GEN_INVALID_PRODUCT_KEY   SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_GENERAL,24)


// {Secret}
class ErrorDescriptionTable {

public:

	ErrorDescriptionTable(TCHAR *aszStatusMessage[], unsigned long ulSubsystem);
	~ErrorDescriptionTable();
	
	unsigned long		m_ulSubsystem;
	TCHAR		**m_aszStatusMessage;
};


/*
{group: System Errors}

Description: The class that enables the retrieval of error information.

$PRODUCTNAME$ uses error codes to signal errors.  The error codes are used to
obtain more information about the error.  If an error occurs
while calling a method from any $PRODUCTNAME$ interface, information about the error
is stored within this class.  If a method causes a $PRODUCTNAME$ error, it is the return value
of that method that will signal the error.  For example, Session::CreateSession will
return true if the call did not signal an error, and false if it did.  In the case of a method that 
returns a value such as DuplicatedObject::Create, NULL is returned in case of error.  
To retrieve the error information, use the methods of this class.  For example:

             $AvatarORInformationObject$* pNew$AvatarORInformationObject$= $AvatarORInformationObject$::Create();
             if (pNew$AvatarORInformationObject$==NULL) {
                        Display(_T("ERROR: Could not create $AvatarORInformationObject$."));  
                        TCHAR strError[256] = _T("");
                        SystemError::GetErrorString(SystemError::GetLast(), strError, 256);
                        Display(_T("%s!\n"), strError);
                        return 0;
             }                

*/
class SystemError {
	//{secret}
	class ImplAttributes;
//Group=
public:

	// Constructor / Destructor
	// {secret}
	SystemError(TCHAR *szFilename, unsigned int LineNo);
	// {Secret}
	~SystemError() {}

	// {secret}
	SystemError SetErrorInfo(unsigned long ulErrorCode, unsigned long ulExtErrorCode, ...);
	// {Secret}
	void Trace(unsigned long ulTraceFlag=TRACE_ALWAYS); 

	/*
	Summary: The GetErrorString function fills a user supplied buffer with the
	description of an error.

	Parameters:
	ulErrorCode: The $PRODUCTNAME$ error code that caused the error.  See GetLast.
	szStringBuf: A string buffer that will hold the result.
	uiBufSize: Specifies the maximum number of characters that can be copied into
	the buffer pointed to by szStringBuf, including a terminating null character.

	See Also: GetLast, GetLastExt
	*/
	static void GetErrorString(unsigned long ulErrorCode, TCHAR *szStringBuf, unsigned int uiBufSize);

	// {Secret}
	static void SignalError(TCHAR *szFilename, unsigned int LineNo, unsigned long ulErrorCode, unsigned long ulExtErrorCode);
	
	/*
	Summary: ClearLast will remove the stored error.
	
	Remarks: This method may be called before GetLast or GetLastExt to ensure that the 
	returned error is generated by the most recently called method.

	See Also: GetLast, GetLastExt
	*/
	static void ClearLast();
	
	/*
	Summary: The GetLast function returns the $PRODUCTNAME$ error code that caused an error.

	Return Value: The function returns the specific error code of the most recent $PRODUCTNAME$ 
	error that occurred. 0 is returned if no error is encountered.

	See Also: GetLastExt
	*/
	static unsigned long GetLast();
	
	/*
	Summary: The GetLastExt function returns the system error code that caused an error.

	Return Value: The function returns the system error code of the most recent error that occurred.

	See Also: GetLast
	*/
	static unsigned long GetLastExt();
	
	//Summary: The TraceLast function outputs a string describing an error to 
	//the display, the debugger, or a file.
	static void TraceLast(unsigned long ulTraceFlag=TRACE_ALWAYS); 

#ifdef _TEST_ENABLED
	// Tests
	// {secret}
	static bool Test();
#endif

	// {Secret}
	unsigned long GetErrorCode() {return m_ulErrorCode;}
	// {Secret}
	unsigned long GetExtErrorCode() {return m_ulExtErrorCode;}

private:
	unsigned long		m_ulErrorCode;
	unsigned long		m_ulExtErrorCode;
	TCHAR 				*m_szFilename;
	unsigned int 		m_uiLineNo;
};

#define ConvertErrorToException(CALL) if (!(CALL)) {THROW_EXCEPTION(SystemError::GetLast(), SystemError::GetLastExt());}

#endif

