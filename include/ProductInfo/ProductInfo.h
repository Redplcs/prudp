//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProductInfo_H_
#define _ProductInfo_H_

#include <Platform/PlatformDecl.h>
#include <ProductInfo/ProductConfiguration.h>

// Group=Utility Subsystem

#define MAJOR_VERSION(x)	(x>>16)
#define	MINOR_VERSION(x)	(x&0xFFFF)

#define MAJOR_BUILD(x)		(x>>16)
#define MINOR_BUILD(x)		(x&0xFFFF)

	// Group=
// Group=ProductInfo Subsystem
#define CORE_PRODUCTID			0
#define NETZ_PRODUCTID			1
#define TSIS_PRODUCTID			2	// Not used anymore, but remains there since product keys were generated.
#define ETERNA_PRODUCTID		3

#define USE_PRODUCT_KEY(KEY)	ProductInfo::SetProductKey(KEY);

class ProductInfo {
	public:
		ProductInfo();
		~ProductInfo();

		static unsigned long GetProductID();

		bool IsValid(unsigned long ulValidationType);
		ProductConfiguration *GetConfiguration();

		static void Banner(TCHAR *strDescription);

		TCHAR* GetProductName();

		// Return the official copyright string.
		TCHAR* GetCopyrightString();
		TCHAR* GetLongVersionString();
		TCHAR* GetDDLVersionString();
		TCHAR* GetShortVersionString();
		
		unsigned long GetVersion();
		unsigned long GetBuild();

		static void SetProductKey(const TCHAR *szKey);
		const TCHAR* GetProductKey();

        // Multicast default value
        static unsigned long GetMaximumGroupSize() {return m_ulMaximumGroupSize;}
        static bool          DistributedBroadcastIsEnabled() {return m_bDistributedBroadcast;}
        static unsigned long GetDefaultMsgSendingCapacity() {return m_ulDefaultMsgSendingCapacity;}

	protected:
		void SetVersionInfo(unsigned short wv1, unsigned short wv2, TCHAR* strVersionString=NULL);
		void _Banner(TCHAR *strDescription);
		
		unsigned short m_wV1, m_wV2, m_wV3, m_wV4;
		unsigned long m_ulVersion;
		unsigned long m_ulBuild;

		TCHAR m_szProductName[128];
		TCHAR m_szShortVersion[128];
		TCHAR m_szDDLVersion[256];
		TCHAR m_szLongVersion[256];
	
		static TCHAR 			*s_szProductKey;
		ProductConfiguration	*m_pConfiguration;

        static unsigned long m_ulMaximumGroupSize;
        static bool          m_bDistributedBroadcast;
        static unsigned long m_ulDefaultMsgSendingCapacity;
};


#endif

