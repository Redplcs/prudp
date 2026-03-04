//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _CompressionPlugin_H_
#define _CompressionPlugin_H_

#include <Plugins/Core/PluginManager.h>
#include <Plugins/Core/Plugin.h>
#include <Plugins/Compression/Interface/CompressionAlgorithm.h>

class CompressionPlugin: public Plugin {
    public:
		CompressionPlugin() {}
		unsigned long GetType() { return COMPRESSION_PLUGIN_TYPE; }
		unsigned long GetInterfaceVersion() { return PluginManager::GetCompressionInterfaceVersion(); }
};

#endif

