//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _UtilitySubsystem_H_
#define _UtilitySubsystem_H_

#include <Utility/UtilityDecl.h>

#pragma warning(disable : 4786)
#pragma warning(disable : 4291)

// {Secret}
class UtilitySubsystem {
public:
	UtilitySubsystem();
	~UtilitySubsystem();

	static UtilitySubsystem *Instance();	

	static bool Test();
private:
		
	static	UtilitySubsystem	*_Instance;
};

#endif
