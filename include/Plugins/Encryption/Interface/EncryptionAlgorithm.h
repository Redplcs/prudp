//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _EncryptionAlgorithm_H
#define _EncryptionAlgorithm_H

#include <Platform/PlatformDecl.h>
#include <Plugins/Core/PluginObject.h>
#include <Platform/UserContext.h>
class Buffer;
class Plugin;

//Group=Plug-ins

//Description: Use this class to specify specific atributes of the encryption algorithm.  
//Remarks: This class is used to specify specific atributes of the encryption algorithm.
class EncryptionAlgorithm: public PluginObject {

public:
//Group=

	//{secret}
	EncryptionAlgorithm(Plugin *pPlugin);
	//{secret}
	virtual ~EncryptionAlgorithm();

	/*
    Description: Sets a custom encryption key for the session.
    Remarks: SetEncryptionKey sets a custom encryption key for the session. The UserContext 
	will depend on the encryption algorithm used.
    */
	virtual unsigned long SetEncryptionKey(unsigned long ulSize, const UserContext &oContext);

	//{secret}
	virtual unsigned long Encrypt(const Buffer &oInBuffer, Buffer *pOutBuffer) = 0;
	virtual unsigned long Encrypt(Buffer *pInOutBuffer);

	//{secret}
	virtual unsigned long Decrypt(const Buffer &oInBuffer, Buffer *pOutBuffer) = 0;
	virtual unsigned long Decrypt(Buffer *pInOutBuffer);

	//{secret}
	virtual bool GetErrorString(unsigned long ulError, TCHAR *szString, unsigned long ulStringSize);

	#ifdef _TEST_ENABLED
	//{secret}
	static bool Test();
	#endif
};

#endif




