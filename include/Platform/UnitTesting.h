//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _UnitTesting_H_
#define _UnitTesting_H_

#include <Platform/PlatformDecl.h>

// Group=Utility Subsystem

class UnitTesting {
	public:
		// The method accessible to the user...

		//;<unittest>
		//; The user's unittest process must implement a C++ main function that calls
		//; the following static method of UnitTesting class:
		//;<&verbatim($arg)>		

		static bool PerformTests(int argc, TCHAR** argv,
								 bool (*fTest)(int iTestID, TCHAR** pstrDescription, bool bDoIt));

		static bool PerformTests(TCHAR* strCmdLine,
								  bool (*fTest)(int iTestID, TCHAR** pstrDescription, bool bDoIt));

		bool InternalPerformTests(int argc, TCHAR** argv,
								  bool (*fTest)(int iTestID, TCHAR** pstrDescription, bool bDoIt));
		//;</&>
		//; The first two arguments are those passed to the main, and third argument is
		//; a pointer to the main test function.  If the fourth argument is true,
		//; then it is expected that a TestServer is running.
		//;</unittest>

		// And those called by the TEST macros...
		static void PrintTestResult(bool bResult, TCHAR* strDescription,
									TCHAR* strFile, unsigned long ulLine);

		static void SRand(int iSeed);
		static void SRand();
		
	public:
		UnitTesting();
		virtual ~UnitTesting();
		
		static UnitTesting *Instance();
		static void DeleteInstance();

	protected:

		bool Test(int iTestID, TCHAR** pstrDescription, bool bDoIt=true);
		void Usage();

	protected:
		virtual void PrepareTest() {};
		virtual bool GetAdditionalTestResult(TCHAR* strResult) {return true;}
		virtual bool AdditionalTestResultAvailable() {return false;}
		virtual bool CallTest(int iTestID) {TCHAR *strDescription; return Test(iTestID,&strDescription);}
		bool PerformTest(int iTestID);

	private:
		bool (*m_fTest)(int iTestID, TCHAR** pstrDescription, bool bDoIt);

	protected:
		static UnitTesting* _Instance;

	private:
		// Behavior modifiers...
		bool m_bTraceSuccess;
		bool m_bMightLeak;
		bool m_bWillLeak;
		unsigned long m_ulUserFirstArg;

		bool m_bTrapExceptions;

		bool m_bGlobalSuccessConditions;
		TCHAR m_strUserCommandLineArgs[256];

		int m_iTestRepetitionAllowed;

	public:
		static bool Testing() {return _Instance!=NULL;}	
		static void StrongMemoryChecks();
		static void MightLeak() {UnitTesting::Instance()->m_bMightLeak=true; UnitTesting::Instance()->m_bWillLeak=false;}
		static void WillLeak() {UnitTesting::Instance()->m_bMightLeak=true; UnitTesting::Instance()->m_bWillLeak=true; }
		static void WillNotLeak() {UnitTesting::Instance()->m_bMightLeak=false; UnitTesting::Instance()->m_bWillLeak=false; }
		static void TrapExceptions(bool bTrapExceptions);
		static unsigned long UserFirstArg() {return UnitTesting::Instance()->m_ulUserFirstArg;}

		static void AllowTestRepetition(int iTestRepetitionAllowed) {
			UnitTesting::Instance()->m_iTestRepetitionAllowed=iTestRepetitionAllowed;
		}

		static void UnitTestFailed(TCHAR* strDescription=NULL, unsigned long ulFlag=TRACE_ALWAYS);
};



#define PRINTTESTRESULT(R,S) UnitTesting::PrintTestResult(R, S, _T(__FILE__), __LINE__);

// Macros used in the client's main Test function.

#define TEST_NOTDEFINED _T("test not defined")
#define SetTestDescription(A) if (pstrDescription) {*pstrDescription=A;}

// Macros used in the individual test functions.

//;<individual-testfunction>
//; An individual test function performs a set of tests on a specific
//; component, and returns either true, if all tests succeeded, or false, if one failed.

//; To ease the management and tracing of the current status of the
//; tests results, a set of macros are provided.

//;</individual-testfunction>

//;<individual-testfunction>
//; All individual test functions starts with the macro \verb+BEGIN_TEST+, and
//; ends with the line \verb+return TESTRESULT;+.
//;</individual-testfunction>

#define BEGIN_TESTS bool bResult=true; TCHAR* strTryBlock=_T("");
#define TESTRESULT bResult

#define TRY_BLOCK(S)					strTryBlock=S; try {
#define SHOULD_NOT_THROW_AN_EXCEPTION	} catch(...) {PRINTTESTRESULT(false,strTryBlock); bResult=false;}
#define SHOULD_THROW_AN_EXCEPTION		bResult=false;} catch(...) {};

//;<individual-testfunction>
//;
//; Between the calls to \verb+BEGIN_TEST+ and \verb+return TESTRESULT+, the function 
//; will test the component.  Every time aa particular result is expected, the following
//; macros are used:
//;
//; \begin{itemize}
//;

//; \item \verb+TEST(C)+: Tests the condition C.  If it is false,
//; then result of the individual test function will be false.  All false results are
//; always printed, while true results are only printed when the
//; unittesting are ran in verbose mode (see command line arguments).
//;
//; \item \verb+TEST(C,S)+: Similar to TEST, but the second argument is the string used
//; to describe the test, when the result is traced.

#define TEST2(C,S) {bool bTmp=(C); if (!bTmp) {bResult=false;} PRINTTESTRESULT(bTmp,S);}
#define TEST(C) TEST2(C,_T(#C))
#define SPINTEST(C,DELAY)	{				\
		bool bSuccess = false;				\
		SpinTest	oST(100,(DELAY)*1000);	\
		oST.LeaveOnTimeout();				\
		SpinOn(oST,!(C));					\
		if (C) {bSuccess=true;} else {bResult=false;}	\
		PRINTTESTRESULT(bSuccess, _T(#C)); \
		if (!bSuccess) { bResult = false; } \
		if (oST.GetElapsed() <= oST.GetTimeout()) { \
			TRACE(D_TRACE_TEST,_T("Spinned %d/%d on %s"),oST.GetElapsed(),oST.GetTimeout(),_T(#C)); \
		} \
		else { \
			TRACE(D_TRACE_TEST,_T("SpinTest Timeout occured")); \
		} \
	}
//#define SPINTEST(C,DELAY) {bool bFailed=false; bool bSuccess=false; unsigned long ulElapsed=0; \
//	while (!bFailed && !bSuccess) {if (C) {bSuccess=true;}; Platform::Sleep(100); ulElapsed+=100; if (ulElapsed==DELAY*1000) {bFailed=true;}};  \
 //   TRACE(D_TRACE_TEST,_T("Out of spin test <%s,%d> with %d elapsed out of %d"), _T(__FILE__), __LINE__, ulElapsed, DELAY*1000);	\
  //  if (!bSuccess) {bResult=false;} PRINTTESTRESULT(bSuccess, _T(#C));}

//; \item \verb+CRITICAL_TEST(C)+ and \verb+CRITICAL_TEST(C)+: Similar to the two previous
//; macros, except that a false result indicates the function returns immediaty, and that the
//; remaining tests are not performed.

#define CRITICAL_TEST2(C,S) {bool bTmp=(C); if (!bTmp) {bResult=false;} PRINTTESTRESULT(bTmp,S); if (!bTmp) return false;}
#define CRITICAL_TEST(C) CRITICAL_TEST2(C,_T(#C))

#define STANDARD_TESTMAIN(TESTFAMILY, TESTMETHOD)							\
	int TestMain(int argc, TCHAR** argv) {									\
		TRACE(TRACE_ALWAYS,_T("Running %s"), TESTFAMILY);					\
		return UnitTesting::PerformTests(argc, argv, &TESTMETHOD)?0:-1;		\
	}																		\
	MAIN_WRAPPER(TestMain);

//; \end{itemize}
//; 
//;</individual-testfunction>

#endif
