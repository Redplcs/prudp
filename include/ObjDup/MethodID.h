//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MethodID_H_
#define _MethodID_H_

#define UNASSIGNED_METHODID	0

// Group = Miscellaneous Types and Macros

/*
Summary: A MethodID is used by $PRODUCTNAME$ to call a method on a particular
duplicated object.

The macro CALLBACKID is used to retrieve the MethodID associated with a 
particular user callback.

The following code sample calls the _GetPosition_ method of the duplicated object
specified in _hDuplicatedObject_ :

	  DOHandle        hDuplicatedObject;
	  Position        pos;
     	 $PRODUCTNAME$            *g_$PRODUCTNAME$ = fnew $PRODUCTNAME$;
      	 UserDOCtrlInterface::GetInstance()->CallAny(hDuplicatedObject, CALLBACKID(GetPosition), &pos)
 
See also: Actions Overview, DOCtrlInterface::CallAny, DOCtrlInterface::CallDuplica,
DOCtrlInterface::CallDuplicationMaster, DOCtrlInterface, CALLBACKID, 
DOCtrlInterface::IterateOverAllDOs, DOCtrlInterface::IterateOverDuplicas,
DOCtrlInterface::IterateOverDuplicationMasters
*/
typedef unsigned long MethodID;

#endif
