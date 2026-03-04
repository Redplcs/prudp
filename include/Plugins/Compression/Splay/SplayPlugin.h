//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SplayPlugin_H_
#define _SplayPlugin_H_

#include <Plugins/Compression/Interface/CompressionPlugin.h>
#include <Plugins/Compression/Splay/SplayCompression.h>
#include <Plugins/Compression/Splay/Splay.h>

class SplayPlugin: public CompressionPlugin {
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
		_declspec(dllexport) static SplayPlugin *GetInstance();			
		#else
		static SplayPlugin *GetInstance();			
		#endif
	private:
		static SplayPlugin	s_oPlugin;
};

#endif

