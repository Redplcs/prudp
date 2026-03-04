//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Authentication_H_
#define _Authentication_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/UserDefinedAuthentication.h>
class Message;

// Group=Distributed Computing Subsystem

class Authentication {
	// Group=
	public:

		Authentication();
		~Authentication();

		void AddSourceTo(Message *pMessage);
		void ExtractFrom(Message *pMessage);

		bool Authenticate(const Authentication& oAuthentication);

		void Trace(unsigned long ulFlag);

		void SetAuthenticationInfo(unsigned long ulVersion,
								   unsigned long ulAdditionalInfoLength=0,
								   unsigned char* pbyAdditionalInfo=NULL);


		typedef bool (* AuthenticationFunction)(unsigned long ulContext,
												const UserDefinedAuthentication& oServer,
												const UserDefinedAuthentication& oClient);

		void SetAuthenticationFunction(unsigned long ulContext,
									   AuthenticationFunction pfAuthentication);

		static void SetTitle(TCHAR* strTitle);
		static TCHAR* GetTitle();
		void ComputeTitleChecksum();

		void SkipLibraryAuthentication();

		void SetVersionInfo(unsigned long ulVersion, unsigned long ulBuild);

#ifdef _TEST_ENABLED
		static bool Test();
#endif

	private:
		// NetZ info...
		unsigned char m_byStructureVersion;
		unsigned char m_byProtocolVersion;
		unsigned char m_byVersionInfo;
		unsigned long m_ulVersion;
		unsigned long m_ulBuild;

		// NetZ managed game info
		unsigned long m_ulTitleChecksum;

		UserDefinedAuthentication m_oUserDefinedAuthentication;

		AuthenticationFunction m_pfAuthentication;
		unsigned long m_ulAuthenticationContext;

		static TCHAR* s_strTitle;
		
		bool m_bDoLibraryAuthentication;
};


#endif
