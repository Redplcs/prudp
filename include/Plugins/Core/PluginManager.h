//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//

#ifndef _PluginManager_H_
#define _PluginManager_H_

#include <Platform/PlatformDecl.h>
#include <Platform/File.h>
#include <Plugins/Core/Plugin.h>
#include <list>

class File::FindContext;

#define PLUGIN_MANAGER_VERSION	0x1

//Group=Plug-ins

//Summary: The plug-in is a transport plug-in. 
#define TRANSPORT_PLUGIN_TYPE 	0x1
//Summary: The plug-in is a compression plug-in.
#define COMPRESSION_PLUGIN_TYPE 0x2
//Summary: The plug-in is an encryption plug-in.
#define ENCRYPTION_PLUGIN_TYPE 	0x3

//{secret}
#define UNICODE_STRING_FORMAT		((unsigned long)0x1)
//{secret}
#define ANSI_STRING_FORMAT			((unsigned long)0x2)

//{secret}
#define DEBUG_TARGET				((unsigned long)0x1)
//{secret}
#define RELEASE_TARGET				((unsigned long)0x2)
//{secret}
#define CUSTOM_TARGET				((unsigned long)0x3)


//Description: Use this class to control how $PRODUCTNAME$ loads plug-ins. 
//Remarks: This class is used to control how $PRODUCTNAME$ loads plug-ins. 
class PluginManager {
//Group=
	public:
		PluginManager();
		~PluginManager();
		
		//{secret}
		static bool ValidateInterfaceVersion(Plugin *pPlugin);

		/*
		Description: Returns a pointer to the PluginManager instance.
		Returns: A reference to the PluginManager object.
		Remarks: Use the reference returned by this method to control the plug-in interface.
		For example, get the activation list size as follows:

			PluginManager::GetInstance()->GetActivationListSize();

		See Also: CreateInstance, DeleteInstance
		*/
		static PluginManager	*GetInstance();
		
		/*
		Description: Creates an instance of the PluginManager class.
		Remarks:
		See Also: GetInstance, DeleteInstance
		*/
		static PluginManager	*CreateInstance();
		
		/*
		Description: Deletes an instance of the PluginManager class.
		Remarks:
		See Also: GetInstance, CreateInstance
		*/static void				DeleteInstance();

		//Description: Adds the specified directory to the path that $PRODUCTNAME$ will load plug-ins from.
		//See Also: LoadFromPath, ClearPluginsPath
		void	AddDirToPluginsPath(TCHAR *szDir);
	
		
		//Description: Clears the paths that $PRODUCTNAME$ will load plug-ins from.
		//See Also: AddDirToPluginsPath, LoadFromPath
		void	ClearPluginsPath();
	
		/*
		Description: Loads plug-ins from the specified path constructed via the Path methods.
		Remarks: The default path is: c:\Program Files\Quazal\$PRODUCTNAME$\Plugins. 
		The default path can be changed via the methods AddDirToPluginsPath and ClearPluginsPath.
		Returns: The number of plug-ins loaded in the activation list
		See Also: AddDirToPluginsPath, ClearPluginsPath
		*/
		unsigned long	LoadFromPath();

		/*
		Description: Adds a specified plug-in to the activation list.
		Remarks: The activation list is a list of the plug-ins that are currently available for 
		$PRODUCTNAME$ to use.
		See Also: RemoveFromActivationList, GetActivationListItem, GetActivationListSize
		*/bool	AddToActivationList(Plugin *pPlugin);
		
		/*
		Description: Removes the specified plug-in from the activation list.
		Remarks: The activation list is a list of the plug-ins that are currently available for 
		$PRODUCTNAME$ to use. 
		See Also: AddToActivationList, GetActivationListItem, GetActivationListSize
		*/
		bool	RemoveFromActivationList(Plugin *pPlugin);

		/*
		Description: Returns an item from the activation list.
		Returns: An item from the activation list.
		Remarks: The activation list is a list of the plug-ins that are currently available for 
		$PRODUCTNAME$ to use.		
		See Also: AddToActivationList, RemoveFromActivationList, GetActivationListSize
		*/
		Plugin			*GetActivationListItem(unsigned long ulItemIndex);
		
		/*
		Description: Returns the size of the activation list.
		Returns: The size of the activation list.
		See Also: AddToActivationList, RemoveFromActivationList, GetActivationListItem
		*/
		unsigned long	GetActivationListSize();

		//{secret}
		Plugin	*Load(TCHAR* szPluginFilename);
		//{secret}
		Plugin	*LoadFirst(TCHAR* szPluginDir);
		//{secret}
		Plugin	*LoadNext();
		//{secret}
		void	LoadClose();
		//{secret}
		unsigned long 	LoadAllFromDir(TCHAR *szDir);

		//{secret}
		Plugin 			*FindByGUID(TCHAR *szGUID);
		
		//{secret}
		static unsigned long	GetVersion();
		//{secret}
		static unsigned long	GetStringFormat();
		//{secret}
		static unsigned long	GetTargetInfo();
		//{secret}
		static unsigned long	GetTransportInterfaceVersion();
		//{secret}
		static unsigned long	GetEncryptionInterfaceVersion();
		//{secret}
		static unsigned long	GetCompressionInterfaceVersion();

		//{secret}
		void 	ActivatePlugins();
		//{secret}
		void 	Activate(Plugin *pPlugin);
		//{secret}
		void 	ReleasePlugins();
		//{secret}
		void 	Release(Plugin *pPlugin);
		
		//{secret}
		void 			TraceActivationList(unsigned long ulTraceFlags);
	private:
		Plugin			*LoadWithOptionalValidation(TCHAR* szPluginFilename, bool bValidate);


		std::list<Plugin*>		m_oActivationList;
		static PluginManager	*s_pInstance;
		File::FindContext		*m_pFindContext;

		std::list<TCHAR*>		m_oPluginsPath;
};

#endif
