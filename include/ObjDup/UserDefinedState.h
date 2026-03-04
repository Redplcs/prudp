//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, UserDefinedState.h

#ifndef _UserDefinedState_H_
#define _UserDefinedState_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/UserDefinedStateDDL.h>

class UserDefinedState: public DATASET(UserDefinedState) {
	public:
		UserDefinedState();
		~UserDefinedState() {};

		void OperationEnd(const Operation* pOperation);

		void SetState(unsigned long ulNewState);
		unsigned long GetState();
};

#endif
