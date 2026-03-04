//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//

#ifndef _PluginObject_H_
#define _PluginObject_H_

class Plugin;

class PluginObject {
	public:
		PluginObject(Plugin *pPlugin) { m_pPlugin = pPlugin; }
		virtual ~PluginObject() {}

		Plugin	*GetPlugin() { return m_pPlugin; }

	protected:
		Plugin			*m_pPlugin;
};
		
#endif
