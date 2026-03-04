//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _RegistryVariable_H_
#define _RegistryVariable_H_

#include <Platform/PlatformDecl.h>

#ifdef REGISTRY_VARIABLE_SUPPORT

// Products have same ID than in src\ProductInfo\ProductInfo.h  !!!
#define INVALID_REGISTRY_PATH			0
#define USE_NETZ_REGISTRY_PATH			1
#define USE_TSIS_REGISTRY_PATH			2
#define USE_ETERNA_REGISTRY_PATH		3

#define INVALID_REGISTRY_ENDING		0
#define USE_WIN32_REGISTRY_ENDING	1
#define USE_WINCE_REGISTRY_ENDING	2

class RegistryVariable {
	public:
		RegistryVariable(TCHAR* strName);
		virtual ~RegistryVariable();
		
		bool Read(TCHAR* strValue, unsigned long uiValueSize);
		bool Write(TCHAR* strValue);
		
		void SetRegistryPathID(unsigned int uiRegistryPath);
		void SetRegistryEnding(unsigned int uiRegistryEnding);
		
	private:
		#ifndef UNDER_CE
		bool ReadANSIRegistryKey(TCHAR* strValue, unsigned long uiValueSize);
		#endif
		void GetRegistryPathString(TCHAR* szRegistryPath, unsigned int uiMaxSize);
	
		TCHAR* m_strName;
		unsigned int   m_uiRegistryPathID;
		unsigned int   m_uiRegistryEnding;
};

#endif

#endif
