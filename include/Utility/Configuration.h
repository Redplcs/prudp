//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Configuration_H_
#define _Configuration_H_

#include <Utility/UtilityDecl.h>
#include <vector>
class ConfigurationVariable;

typedef std::vector<ConfigurationVariable*> ConfigurationVariablesVector;

class Configuration {
	public:
		Configuration();
		virtual ~Configuration();
		
		#ifdef _TEST_ENABLED
		static bool Test();
		#endif
	
		void CreateVariable(ConfigurationVariable* pConfigurationVariable);
		ConfigurationVariable* FindVariable(TCHAR* strName);

		ConfigurationVariable* GetVariable(unsigned int uiIndex);
		unsigned int GetVariablesNumber();
		
	private:
		ConfigurationVariablesVector* m_pConfigurationVariablesVector;
};



#endif
