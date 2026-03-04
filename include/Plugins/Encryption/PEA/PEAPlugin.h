//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _PEAPlugin_H_
#define _PEAPlugin_H_

#include <Plugins/Encryption/Interface/EncryptionPlugin.h>

class PEAPlugin: public EncryptionPlugin {
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
		static _declspec(dllexport) PEAPlugin *GetInstance();
		#else
		static PEAPlugin *GetInstance();
		#endif
	private:
		static PEAPlugin	s_oPlugin;
};

#endif

