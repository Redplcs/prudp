//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  



#ifndef _Singleton_H_
#define _Singleton_H_

#include <Utility/UtilityDecl.h>
#include <Utility/InstantiationContext.h>
#include <Utility/InstanceControl.h>

class Singleton : public InstanceControl {
	public:
		Singleton(ICType icInstanceType);
		virtual ~Singleton();
};


#endif

 
