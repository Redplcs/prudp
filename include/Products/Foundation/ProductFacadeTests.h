//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProductFacadeTest_H_
#define _ProductFacadeTest_H_

#include <Platform/SpinTest.h>
#include <ObjDup/SessionCtrlInterface.h>
#include <Plugins/Compression/Splay/Splay.h>
#include <Plugins/Compression/LZss/LZss.h>
#include <Plugins/Compression/LZrw/LZrw.h>
#include <Plugins/Encryption/RC4/RC4.h>
#include <Plugins/Encryption/PEA/PEA.h>

#ifdef _TEST_ENABLED

template<class SpecificFacade, class SpecificAppCtrlInterface> class ProductFacadeTests {
	public:

		static bool Test0() {
			// Basic mem leaks tests!
			BEGIN_TESTS;
			SpecificFacade oSpecificFacade;
			TEST(oSpecificFacade.IsValid());
			return TESTRESULT;
		}

		static bool Test1() {
			// Basic mem leaks tests!
			BEGIN_TESTS;
			SpecificFacade oSpecificFacade;
			TEST(oSpecificFacade.IsValid());
			TEST(oSpecificFacade.GetSessionCtrlInterface()->CreateSession());
			return TESTRESULT;
		}

		static bool Test2() {
			BEGIN_TESTS;
			SpecificFacade* poFirstInstance=NULL;
			SpecificFacade* poSecondInstance=NULL;
			poFirstInstance=fnew SpecificFacade();
			UnitTesting::WillLeak();
			{
				poSecondInstance=fnew SpecificFacade();
				TEST(poSecondInstance->IsValid()==false);
				TEST(SystemError::GetLast()==SYSTEMERROR_GEN_MULTIPLE_INSTANCES);
				delete poSecondInstance;
			}
			fdelete poFirstInstance;
			return TESTRESULT;
		}

		static bool Test3() {
			BEGIN_TESTS;
			SpecificAppCtrlInterface oAppCtrlInterface;
			TEST(!oAppCtrlInterface.IsSessionMaster());
			TEST(SystemError::GetLast()==SYSTEMERROR_GEN_NOT_INITIALIZED);
			return TESTRESULT;
		}

		static bool Test4() {
			BEGIN_TESTS;
			TEST(PseudoSingleton::UseInstantiationContext(15));
			ICContext icStation1=InstanceControl::CreateContext();
			ICContext icStation2=InstanceControl::CreateContext();

			TEST(PseudoSingleton::SetContext(icStation1));
			SpecificFacade* poFacade1=fnew SpecificFacade();

			TEST(!poFacade1->GetSessionCtrlInterface()->JoinSession(_T("localhost")));
			TEST(SystemError::GetLast()==SYSTEMERROR_DC_CLUSTER_JOIN_FAILED);
			TEST(!poFacade1->GetSessionCtrlInterface()->JoinSession(_T("localhost")));
			TEST(SystemError::GetLast()==SYSTEMERROR_DC_CLUSTER_JOIN_FAILED);
			TEST(poFacade1->GetSessionCtrlInterface()->CreateSession());

			TEST(PseudoSingleton::SetContext(icStation2));
			SpecificFacade* poFacade2=fnew SpecificFacade();
			TEST(!poFacade2->GetSessionCtrlInterface()->JoinSession(_T("invalidipaddress")));
			TEST(SystemError::GetLast()==SYSTEMERROR_DC_CLUSTER_JOIN_FAILED);
			TEST(poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost")));

			fdelete poFacade2;

			TEST(PseudoSingleton::SetContext(icStation1));
			try {
				fdelete poFacade1;
			} catch (...) {
				SYSTEMCHECK(false);
			}

			TEST(InstanceControl::DeleteContext(icStation1));
			TEST(InstanceControl::DeleteContext(icStation2));
			TEST(PseudoSingleton::UseNoInstantiationContext());
			
			return TESTRESULT;
		}

		static bool Test5() {
			BEGIN_TESTS;
			{
				SpecificFacade oSpecificFacade;
			}
			{
				SpecificFacade oSpecificFacade;
			}
			return TESTRESULT;
		}

		static bool Test6() {
			// Test two instances in different contextes.
			BEGIN_TESTS;
			TEST(PseudoSingleton::UseInstantiationContext(15));
#ifdef CPP_EXCEPTION_SUPPORT
			try {
#endif
				ICContext icStation1=InstanceControl::CreateContext();
				ICContext icStation2=InstanceControl::CreateContext();
				{
					TEST(PseudoSingleton::SetContext(icStation1));
					SpecificFacade* poSpecificFacade1=new SpecificFacade();
					TEST(SessionCtrlInterface::GetInstance()->CreateSession(9101));
					TEST(SessionCtrlInterface::GetInstance()->GetSystemState()==SYSTEM_STATE_INITIALIZING);

					TEST(PseudoSingleton::SetContext(icStation2));
					SpecificFacade* poSpecificFacade2=new SpecificFacade();
					TEST(SessionCtrlInterface::GetInstance()->JoinSession(_T("localhost"),9101));

					SPINTEST(SessionCtrlInterface::GetInstance()->GetNbStations()==2,10);
					TEST(PseudoSingleton::SetContext(icStation1));
					SPINTEST(SessionCtrlInterface::GetInstance()->GetNbStations()==2,10);					
					
					TEST(PseudoSingleton::SetContext(icStation2));
					TRACE(D_TRACE_TEST,_T("****************************************************Will delete the facade."));
					delete poSpecificFacade2;
					TRACE(D_TRACE_TEST,_T("Deleted the facade."));

					TEST(PseudoSingleton::SetContext(icStation1));
					SPINTEST(SessionCtrlInterface::GetInstance()->GetNbStations()==1,10);
					TEST(SessionCtrlInterface::GetInstance()->GetSystemState()==SYSTEM_STATE_INITIALIZING);
					delete poSpecificFacade1;
				}
				TEST(InstanceControl::DeleteContext(icStation1));
				TEST(InstanceControl::DeleteContext(icStation2));
#ifdef CPP_EXCEPTION_SUPPORT
			} catch (...) {
				if(PseudoSingleton::UseNoInstantiationContext() == false) {
					THROW_EXCEPTION(SystemError::GetLast(), 0);
				}
				throw;
			}
#endif
			TEST(PseudoSingleton::UseNoInstantiationContext());
			return TESTRESULT;
		}

		static bool Test7() {
			// Test non networked Sessions.
			BEGIN_TESTS;
			TEST(PseudoSingleton::UseInstantiationContext(15));
			ICContext icStation1=InstanceControl::CreateContext();
			ICContext icStation2=InstanceControl::CreateContext();

			TEST(PseudoSingleton::SetContext(icStation1));
			SpecificFacade* poSpecificFacade1=new SpecificFacade();
			TEST(SessionCtrlInterface::GetInstance()->CreateNonNetworkedSession()); // Non networked.
			TEST(SessionCtrlInterface::GetInstance()->GetSystemState()==SYSTEM_STATE_INITIALIZING);

			TEST(PseudoSingleton::SetContext(icStation2));
			SpecificFacade* poSpecificFacade2=new SpecificFacade();
			TEST(!SessionCtrlInterface::GetInstance()->JoinSession(_T("localhost"))); // Cannot join.

			TEST(PseudoSingleton::SetContext(icStation1));
			TEST(SessionCtrlInterface::GetInstance()->GetNbStations()==1);

			TEST(PseudoSingleton::SetContext(icStation2));
			TRACE(D_TRACE_TEST,_T("Will delete the facade."));
			delete poSpecificFacade2;
			TRACE(D_TRACE_TEST,_T("Deleted the facade."));

			TEST(PseudoSingleton::SetContext(icStation1));
			TEST(SessionCtrlInterface::GetInstance()->GetSystemState()==SYSTEM_STATE_INITIALIZING);
			delete poSpecificFacade1;

			TEST(InstanceControl::DeleteContext(icStation1));
			TEST(InstanceControl::DeleteContext(icStation2));
			TEST(PseudoSingleton::UseNoInstantiationContext());

			return TESTRESULT;
		}


		static bool Test8() {
			BEGIN_TESTS;
            TRACE(TRACE_ALWAYS,_T("Running test 8"));
            {
                TEST(PseudoSingleton::UseInstantiationContext(15));
                ICContext icStation1=InstanceControl::CreateContext();
                ICContext icStation2=InstanceControl::CreateContext();
    
                TEST(PseudoSingleton::SetContext(icStation1));
                SpecificFacade* poFacade1=fnew SpecificFacade();
                TEST(poFacade1->GetSessionCtrlInterface()->CreateSession(_T("test")));
    
                TEST(PseudoSingleton::SetContext(icStation2));
                SpecificFacade* poFacade2=fnew SpecificFacade();
				SessionDescription oSessionDescription;
                TEST(poFacade2->GetSessionCtrlInterface()->FindLANSession(_T("test"),&oSessionDescription));
                TEST(!poFacade2->GetSessionCtrlInterface()->FindLANSession(_T("test"),&oSessionDescription,(unsigned short)9101));
                fdelete poFacade2;
    
                TEST(PseudoSingleton::SetContext(icStation1));
                fdelete poFacade1;
    
                TEST(InstanceControl::DeleteContext(icStation1));
                TEST(InstanceControl::DeleteContext(icStation2));
                TEST(PseudoSingleton::UseNoInstantiationContext());
		    }	
            {
                TEST(PseudoSingleton::UseInstantiationContext(15));
                ICContext icStation1=InstanceControl::CreateContext();
                ICContext icStation2=InstanceControl::CreateContext();
    
                TEST(PseudoSingleton::SetContext(icStation1));
                SpecificFacade* poFacade1=fnew SpecificFacade();
                TEST(poFacade1->GetSessionCtrlInterface()->CreateSession());
    
                TEST(PseudoSingleton::SetContext(icStation2));
                SpecificFacade* poFacade2=fnew SpecificFacade();
                TEST(poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost")));
                fdelete poFacade2;
    
                TEST(PseudoSingleton::SetContext(icStation1));
                fdelete poFacade1;
    
                TEST(InstanceControl::DeleteContext(icStation1));
                TEST(InstanceControl::DeleteContext(icStation2));
                TEST(PseudoSingleton::UseNoInstantiationContext());
		    }	
            {
                TEST(PseudoSingleton::UseInstantiationContext(15));
                ICContext icStation1=InstanceControl::CreateContext();
                ICContext icStation2=InstanceControl::CreateContext();
    
                TEST(PseudoSingleton::SetContext(icStation1));
                SpecificFacade* poFacade1=fnew SpecificFacade();
                TEST(poFacade1->GetSessionCtrlInterface()->CreateSession());
    
                TEST(PseudoSingleton::SetContext(icStation2));
                SpecificFacade* poFacade2=fnew SpecificFacade();
                TEST(poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost"),9103));
                fdelete poFacade2;
    
                TEST(PseudoSingleton::SetContext(icStation1));
                fdelete poFacade1;
    
                TEST(InstanceControl::DeleteContext(icStation1));
                TEST(InstanceControl::DeleteContext(icStation2));
                TEST(PseudoSingleton::UseNoInstantiationContext());
		    }	
            {
                TEST(PseudoSingleton::UseInstantiationContext(15));
                ICContext icStation1=InstanceControl::CreateContext();
                ICContext icStation2=InstanceControl::CreateContext();
    
                TEST(PseudoSingleton::SetContext(icStation1));
                SpecificFacade* poFacade1=fnew SpecificFacade();
                TEST(poFacade1->GetSessionCtrlInterface()->CreateSession(9101));
    
                TEST(PseudoSingleton::SetContext(icStation2));
                SpecificFacade* poFacade2=fnew SpecificFacade();
                TEST(!poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost")));
                TEST(poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost"),9101));
                fdelete poFacade2;
    
                TEST(PseudoSingleton::SetContext(icStation1));
                fdelete poFacade1;
    
                TEST(InstanceControl::DeleteContext(icStation1));
                TEST(InstanceControl::DeleteContext(icStation2));
                TEST(PseudoSingleton::UseNoInstantiationContext());
		    }	
			return TESTRESULT;
		}


		static bool TestCompression(TCHAR *szGUID1, TCHAR *szGUID2) {
            {
                BEGIN_TESTS;
                TEST(PseudoSingleton::UseInstantiationContext(15));
                ICContext icStation1=InstanceControl::CreateContext();
                ICContext icStation2=InstanceControl::CreateContext();
    
                TEST(PseudoSingleton::SetContext(icStation1));
                SpecificFacade* poFacade1=fnew SpecificFacade();
                TEST(Protocol::GetInstance()->SelectCompressionPlugin(szGUID1));
                TEST(poFacade1->GetSessionCtrlInterface()->CreateSession());
    
                TEST(PseudoSingleton::SetContext(icStation2));
                SpecificFacade* poFacade2=fnew SpecificFacade();
                TEST(Protocol::GetInstance()->SelectCompressionPlugin(szGUID2));
                bool bJoinResult = poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost"));
                fdelete poFacade2;
    
                TEST(PseudoSingleton::SetContext(icStation1));
                fdelete poFacade1;
    
                TEST(InstanceControl::DeleteContext(icStation1));
                TEST(InstanceControl::DeleteContext(icStation2));
                TEST(PseudoSingleton::UseNoInstantiationContext());
                return (bJoinResult && TESTRESULT);
            }
        }

		static bool Test9() {
			BEGIN_TESTS;
            TRACE(TRACE_ALWAYS,_T("Running test 9"));
            {
                TEST(TestCompression(NULL,NULL));
                TEST(TestCompression(PROKSIM_LZSS_GUID,PROKSIM_LZSS_GUID));
                TEST(TestCompression(PROKSIM_LZRW_GUID,PROKSIM_LZRW_GUID));
                TEST(TestCompression(PROKSIM_SPLAY_GUID,PROKSIM_SPLAY_GUID));
                TEST(!TestCompression(PROKSIM_LZSS_GUID,PROKSIM_SPLAY_GUID));
                //TEST(!TestCompression(PROKSIM_SPLAY_GUID,NULL));
		    }	
			return TESTRESULT;
		}


		static bool TestEncryption(TCHAR *szGUID1, TCHAR *szGUID2) {
            {
                BEGIN_TESTS;
                TEST(PseudoSingleton::UseInstantiationContext(15));
                ICContext icStation1=InstanceControl::CreateContext();
                ICContext icStation2=InstanceControl::CreateContext();
    
                TEST(PseudoSingleton::SetContext(icStation1));
                SpecificFacade* poFacade1=fnew SpecificFacade();
                TEST(Protocol::GetInstance()->SelectEncryptionPlugin(szGUID1));
                TEST(poFacade1->GetSessionCtrlInterface()->CreateSession());
    
                TEST(PseudoSingleton::SetContext(icStation2));
                SpecificFacade* poFacade2=fnew SpecificFacade();
                TEST(Protocol::GetInstance()->SelectEncryptionPlugin(szGUID2));
                bool bJoinResult = poFacade2->GetSessionCtrlInterface()->JoinSession(_T("localhost"));
                fdelete poFacade2;
    
                TEST(PseudoSingleton::SetContext(icStation1));
                fdelete poFacade1;
    
                TEST(InstanceControl::DeleteContext(icStation1));
                TEST(InstanceControl::DeleteContext(icStation2));
                TEST(PseudoSingleton::UseNoInstantiationContext());
                return (bJoinResult && TESTRESULT);
            }
        }

		static bool Test10() {
			BEGIN_TESTS;
            TRACE(TRACE_ALWAYS,_T("Running test 9"));
            {
                TEST(TestEncryption(NULL,NULL));
                TEST(TestEncryption(PROKSIM_RC4_GUID,PROKSIM_RC4_GUID));
                TEST(TestEncryption(PROKSIM_PEA_GUID,PROKSIM_PEA_GUID));
                TEST(!TestEncryption(PROKSIM_RC4_GUID,PROKSIM_PEA_GUID));
		    }	
			return TESTRESULT;
		}


		static bool Test(int iTestID, TCHAR** pstrDescription, bool bDoIt=true) {
			bool bResult=true;
			switch (iTestID) {
				// Internal test serie...
				case 0:
					SetTestDescription(_T("Facade unittests, Test0"));
					if (bDoIt) bResult=Test0();
					break;
				case 1:
					SetTestDescription(_T("Facade unittests, Test1"));
					if (bDoIt) bResult=Test1();
					break;
				case 2:
					SetTestDescription(_T("Facade unittests, Test2"));
					if (bDoIt) bResult=Test2();
					break;
				case 3:
					SetTestDescription(_T("Facade unittests, Test3"));
					if (bDoIt) bResult=Test3();
					break;
				case 4:
					SetTestDescription(_T("Facade unittests, Test4"));
					if (bDoIt) bResult=Test4();
					break;
				case 5:
					SetTestDescription(_T("Facade unittests, Test5"));
					if (bDoIt) bResult=Test5();
					break;
				case 6:
					SetTestDescription(_T("Facade unittests, Test6"));
					if (bDoIt) bResult=Test6();
					break;
				case 7:
					SetTestDescription(_T("Facade unittests, Test7"));
					if (bDoIt) bResult=Test7();
					break;
				case 8:
					SetTestDescription(_T("Facade unittests, Test8"));
					if (bDoIt) bResult=Test8();
					break;
				case 9:
					SetTestDescription(_T("Facade unittests, Test9"));
					if (bDoIt) bResult=Test9();
					break;
				case 10:
					SetTestDescription(_T("Facade unittests, Test10"));
					if (bDoIt) bResult=Test10();
					break;
				default:
					bResult=true;
					SetTestDescription(TEST_NOTDEFINED);
					break;
			}
			return bResult;
		}
};

#endif

#endif
