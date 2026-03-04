//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, SecondaryStationInfo.h

#ifndef _SecondaryStationInfo_H_
#define _SecondaryStationInfo_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/SecondaryStationInfoDDL.h>

class SecondaryStationInfo: public DATASET(SecondaryStationInfo) {
	public:
		SecondaryStationInfo() {}
		~SecondaryStationInfo() {}	
};

#endif
