//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ConfigurationVariable_H_
#define _ConfigurationVariable_H_

#include <Platform/PlatformDecl.h>
#include <Platform/ConfigurationVariable.h>
#include <Platform/RegistryVariable.h>

#define VARIABLE_SOURCE_NONE			0
#define VARIABLE_SOURCE_DEFAULT			1
#define VARIABLE_SOURCE_REGISTRY		2
#define VARIABLE_SOURCE_ENVIRONMENT		3
#define VARIABLE_SOURCE_FILE			4

#define DEFAULT_SOURCE_UNDEFINED	0xFFFF

class ConfigurationVariable {
	public:
		ConfigurationVariable(TCHAR* strName, TCHAR* strDefaultValue=NULL);
		virtual ~ConfigurationVariable();
		
		TCHAR* GetName();
		TCHAR* GetValue();
		void SetValue(const TCHAR* strValue);
		unsigned int GetSourceType();
		
		bool Read();
		bool ReadFromDefaultValue();
		bool ReadFromFile();
		bool ReadFromEnvironment();
		bool ReadFromRegistry();
		bool WriteToRegistry();

		#ifdef REGISTRY_VARIABLE_SUPPORT
		void SetRegistryPathID(unsigned int uiRegistryPath);
		void SetRegistryEnding(unsigned int uiRegistryEnding);
		#endif

	private:
		void SetName(TCHAR* strName);
		void InitVariables();


		TCHAR* m_strName;
		TCHAR* m_strValue;

#ifdef REGISTRY_VARIABLE_SUPPORT
		RegistryVariable* m_pRegistryVariable;
#endif
		unsigned int m_uiSourceType;
};

#endif
