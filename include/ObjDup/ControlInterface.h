//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ControlInterface_H_
#define _ControlInterface_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/InstantiationContext.h>

// {secret}

class ControlInterface {
	// Group=
	public:

		ControlInterface();
		virtual ~ControlInterface();

		static ControlInterface* GetInstance(ICType icInstanceType);
};

#endif
