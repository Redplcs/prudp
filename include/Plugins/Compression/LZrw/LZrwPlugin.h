//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _LZrwPlugin_H_
#define _LZrwPlugin_H_

#include <Plugins/Compression/Interface/CompressionPlugin.h>

class LZrwPlugin: public CompressionPlugin {
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
		_declspec(dllexport) static LZrwPlugin *GetInstance();			
		#else
		static LZrwPlugin *GetInstance();			
		#endif
	private:
		static LZrwPlugin	s_oPlugin;
};

#endif

