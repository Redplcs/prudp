//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProductCapability_H_
#define _ProductCapability_H_

#include <Platform/PlatformDecl.h>


#define  STATIONS_ALWAYS_GLOBAL     1<<0
#define  OTHER_FEATURE1             1<<1
#define  OTHER_FEATURE2             1<<2
#define  OTHER_FEATURE3             1<<3
#define  OTHER_FEATURE4             1<<4
#define  OTHER_FEATURE5             1<<5


class ProductCapability {
	public:
		ProductCapability();
		~ProductCapability();

		static void SetFlag(unsigned int uiFlag);
		static bool FlagIsSet(unsigned int uiFlag);

    protected :
		static unsigned int m_uiFlags;

};


#endif

