//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _EncryptionPlugin_H_
#define _EncryptionPlugin_H_

#include <Plugins/Core/PluginManager.h>
#include <Plugins/Core/Plugin.h>
#include <Plugins/Encryption/Interface/EncryptionAlgorithm.h>

class EncryptionPlugin: public Plugin {
    public:
		EncryptionPlugin() {}
		unsigned long GetType() { return ENCRYPTION_PLUGIN_TYPE; }
		unsigned long GetInterfaceVersion() { return PluginManager::GetEncryptionInterfaceVersion(); }
};

#endif

