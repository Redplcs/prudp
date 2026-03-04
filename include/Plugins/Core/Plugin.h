//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//

#ifndef _Plugin_H_
#define _Plugin_H_

#include <Platform/PlatformDecl.h>
class PluginObject;

//Group=Plug-ins

//Description: Use this class to retrieve details regarding a particular plug-in.
//Remarks: This class is used to retrieve details regarding a particular plug-in
class Plugin {
//Group=
	public:
		Plugin();
		virtual ~Plugin();

		// This has to be the first virtual method since
		// we rely on that for versionning.
		//{secret}
		virtual unsigned long GetInterfaceVersion()=0;
		//{secret}
		virtual void    SetTraceOutput(TraceOutput *pTraceOutput);

		//Description: Use this method to determine the Global Universal ID of a particular plug-in.
		//Returns: The Global Universal ID of the plug-in.
		virtual TCHAR			*GetGUID()=0;
		
		//Description: Use this method to determine the name of a particular plug-in.
		//Returns: The name of the plug-in.
		virtual TCHAR			*GetName()=0;
	
		//Description: Use this method to determine the author of a particular plug-in.
		//Returns: The author of the plug-in.
		virtual TCHAR 			*GetAuthor()=0;
		
		//Description: Use this method to determine the version number of a particular plug-in.
		//Returns: The version number of the plug-in.
		virtual unsigned long	GetVersion()=0;
		
		//{secret}
		virtual bool 			IsCertified()=0;
		
		//Description: Use this method to determine the type of a particular plug-in.
		//Returns: The type of plug-in. 
		//Remarks: The type of plug-in may be one of TRANSPORT_PLUGIN_TYPE, COMPRESSION_PLUGIN_TYPE, or 
		//ENCRYPTION_PLUGIN_TYPE.
		virtual unsigned long 	GetType()=0;


		//{secret}
		static Plugin *Load(TCHAR *szPluginFilename);
		//{secret}
		void Unload();

		//{secret}
		virtual bool Activate()=0;
		//{secret}
		virtual void Release()=0;

		//{secret}
		virtual unsigned long	GetStringFormat();
		//{secret}
		virtual unsigned long	GetTargetInfo();

		//{secret}
		virtual bool			Initialize();
		//{secret}
		virtual void			ThreadAttach();
		//{secret}
		virtual void			ThreadDetach();
		//{secret}
		virtual void			Destroy();

		//{secret}
		void					Trace(unsigned long ulFlags);

		//{secret}
		static Plugin	*GetInstance();
		//{secret}
		void					SetLibrary(void *hLibrary);

		//{secret}
		virtual PluginObject		 	*CreatePluginObject()=0;
		//{secret}
		virtual void 			DeletePluginObject(PluginObject *pPlugin)=0;

	protected:
		static Plugin	*s_pInstance;
		void					*m_hLibrary;
};
		
#endif
