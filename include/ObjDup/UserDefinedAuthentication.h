//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _UserDefinedAuthentication_H_
#define _UserDefinedAuthentication_H_

#include <ObjDup/ObjDupDecl.h>

class Message;

class UserDefinedAuthentication {
	public:
		UserDefinedAuthentication();
		~UserDefinedAuthentication();

		void AddSourceTo(Message *pMessage);
		void ExtractFrom(Message *pMessage);

		void SetAuthenticationInfo(unsigned long ulVersion,
								   unsigned long ulAdditionalInfoLength=0,
								   unsigned char* pbyAdditionalInfo=NULL);		
		
		// Game specific info, specified by the user.
		unsigned long m_ulVersion;
		unsigned long m_ulAdditionalInfoLength;
		unsigned char* m_pbyAdditionalInfo;		
};

#endif
