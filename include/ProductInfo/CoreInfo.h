//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _CoreInfo_H_
#define _CoreInfo_H_

#include <Platform/PlatformDecl.h>
#include <ProductInfo/ProductInfo.h>

class CoreInfo: public ProductInfo {
	// Group=	
	public:
		CoreInfo();
		~CoreInfo();

		bool IsValid(unsigned long ulValidationType);
		virtual unsigned long GetProductID();

		virtual ProductConfiguration *GetConfiguration();

		ProductConfiguration	*m_pConfiguration;
		static CoreInfo  		s_oCoreInfo;
};


#endif

