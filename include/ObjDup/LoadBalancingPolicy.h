//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, LoadBalancingPolicy.h

#ifndef _LoadBalancingPolicy_H_
#define _LoadBalancingPolicy_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/LoadBalancingPolicyDDL.h>

class LoadBalancingPolicy: public DATASET(LoadBalancingPolicy) {
	public:
		LoadBalancingPolicy();
		~LoadBalancingPolicy();
};

#endif
