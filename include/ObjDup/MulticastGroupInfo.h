//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, MulticastGroupInfo.h

#ifndef _MulticastGroupInfo_H_
#define _MulticastGroupInfo_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/MulticastPolicy.h>
#include <ObjDup/MulticastGroupInfoDDL.h>

#define STATION_CONTENT       0
#define GROUP_CONTENT         1

class MulticastGroupInfo: public DATASET(MulticastGroupInfo) {
	public:
		MulticastGroupInfo();
		~MulticastGroupInfo();

    //void OperationBegin(DataSetOperation* pOperation);
    //void OperationEnd(DataSetOperation* pOperation);
};

#endif
