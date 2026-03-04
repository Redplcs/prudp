//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MethodIDFactory_H_
#define _MethodIDFactory_H_


#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/MethodID.h>
#include <Utility/IDGenerator.h>
#include <Platform/AtomicValue.h>
#include <string>
#include <map>

// {Secret}
class MethodIDFactory {
	public:
		MethodIDFactory() {}
		~MethodIDFactory() {}

		static MethodID AssignID(std::string strMethodName);
		static MethodID GetID(std::string strMethodName);

		static void CleanupMethodIDTable();

#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
#endif

	private:
		static std::map<std::string, ID> s_mapID;
		static AtomicValue s_ulNextID;
};

#define _METHODID(METHOD)	MethodIDFactory::GetID(#METHOD)

//Group = Miscellaneous Types and Macros

/*
{secret}
Summary: Returns the MethodID associated with a user callback.

This macro is used to retrieve a MethodID, when using the iteration
and call methods of the DOCtrlInterface.

For example, given the following DDL:

      doclass $AvatarORInformationObject$ {
	    callback DoControl;
	  };


CALLBACKID(DoControl) returns the MethodID associated to the user
callback DoControl.

Returns: The MethodID associated with the callback.  Use of the macro can 
signal the SYSTEMERROR_OBJDUP_UNDEFINED_CALLBACK.
*/
#define CALLBACKID(METHOD)	_METHODID(METHOD)


#endif
