//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _PRUDPPlugin_H_
#define _PRUDPPlugin_H_

#include <Plugins/Core/PluginObject.h>
#include <Plugins/Transport/Interface/TransportPlugin.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Platform/Trace.h>

class PRUDPPlugin: public TransportPlugin {
    public:
		virtual ~PRUDPPlugin();
		bool  Activate();
		void  Release();
		TCHAR *GetGUID();
		TCHAR *GetAuthor();
		TCHAR *GetName();
		unsigned long GetVersion();
		bool IsCertified();
		virtual bool ResponsibleForURL(StationURL *pStationURL);
		virtual PluginObject *CreatePluginObject();
		virtual void DeletePluginObject(PluginObject *pPlugin);
        void SetTraceOutput(TraceOutput *pTraceOutput);
		#ifdef EXPORT_SYMBOLS
		_declspec(dllexport) static PRUDPPlugin *GetInstance();			
		#else
		static PRUDPPlugin *GetInstance();			
		#endif
	private:
		static PRUDPPlugin	s_oPlugin;
};

#endif

