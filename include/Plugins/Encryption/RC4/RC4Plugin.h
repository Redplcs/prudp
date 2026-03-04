//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _RC4Plugin_H_
#define _RC4Plugin_H_

#include <Plugins/Encryption/Interface/EncryptionPlugin.h>

class RC4Plugin: public EncryptionPlugin {
    public:
		bool  Activate();
		void  Release();
		TCHAR *GetGUID();
		TCHAR *GetAuthor();
		TCHAR *GetName();
		unsigned long GetVersion();
		bool IsCertified();
		virtual PluginObject *CreatePluginObject() ;
		virtual void DeletePluginObject(PluginObject *pPlugin) ;
        void SetTraceOutput(TraceOutput *pTraceOutput) ;
		#ifdef EXPORT_SYMBOLS
		static _declspec(dllexport) RC4Plugin *GetInstance();
		#else
		static RC4Plugin *GetInstance();
		#endif
	private:
		static RC4Plugin	s_oPlugin;
};

#endif

