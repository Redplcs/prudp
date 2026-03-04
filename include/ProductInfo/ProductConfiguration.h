//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ProductConfiguration_H_
#define _ProductConfiguration_H_


#include <Platform/PlatformDecl.h>
#include <Utility/Configuration.h>


class ProductConfiguration
{

public:
    ProductConfiguration(TCHAR *szPrefix, unsigned long ulRegistryPath);
    ~ProductConfiguration();

    TCHAR *GetInstallDir();
    TCHAR *GetProductKey();
    void  SetProductKey(TCHAR *szProductKey);

private:
    Configuration 	oProductConfiguration;
	TCHAR			m_szProductKeyVarName[64];
	TCHAR			m_szInstallDirVarName[64];
};


#endif