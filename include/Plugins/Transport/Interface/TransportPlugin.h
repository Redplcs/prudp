//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _TransportPlugin_H_
#define _TransportPlugin_H_

#include <Plugins/Core/PluginManager.h>
#include <Plugins/Core/Plugin.h>
#include <Plugins/Transport/Interface/Transport.h>
#include <Plugins/Transport/Interface/StationURL.h>

class TransportPlugin: public Plugin {
    public:
		unsigned long GetInterfaceVersion() { return PluginManager::GetTransportInterfaceVersion(); }
		unsigned long GetType() { return TRANSPORT_PLUGIN_TYPE; }
		virtual bool ResponsibleForURL(StationURL *pStationURL)=0;
};

#endif

