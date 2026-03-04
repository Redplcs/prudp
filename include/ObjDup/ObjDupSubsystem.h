//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ObjDupSubsystem_H_
#define _ObjDupSubsystem_H_

// memory usage.  

class ErrorDescriptionTable;

// {Secret}
class ObjDupSubsystem {
public:
	ObjDupSubsystem();
	~ObjDupSubsystem();
	
	static bool Test();
private:
	ErrorDescriptionTable	*m_pedtObjDup;
	
};

#endif
