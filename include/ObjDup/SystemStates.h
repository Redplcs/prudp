//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DistributedStateAlgo_H_
#define _DistributedStateAlgo_H_

// Group = Miscellaneous Types and Macros

/*
Summary:  The system is initializing. This state can be used to determine 
if the session setup stage is still in progress or if the session has 
already started.

To $PRODUCTNAME$ the states SYSTEM_STATE_INITIALIZING and
SYSTEM_STATE_RUNNING are identical. In both states objects can be published 
and discovered and data can be updated. 
*/
#define SYSTEM_STATE_INITIALIZING	0

//Summary:  The system is running.  
#define SYSTEM_STATE_RUNNING		1

/*
Summary: The system is paused.

The fact that the system is paused does not influence $PRODUCTNAME$. It is
the responsibility of the user to poll the system state and to pause the 
session when appropriate.
*/
#define SYSTEM_STATE_PAUSED			2

/*
Summary:  The session is terminating.  

Remarks:  The state SYSTEM_STATE_TERMINATING is the
only state that $PRODUCTNAME$ interprets. When the session
terminates certain operations, such as migration, are not performed. It does 
not make sense to perform the migration of the managed duplicated objects 
since there is no place to migrate as each station is leaving the session.
Therefore, the system callback DuplicatedObject::ApproveEmigration will not be
called when a station leaves since the session is terminating. For the
same reason, the system callback DuplicatedObject::ApproveFaultRecovery 
will not be called.  
*/
#define SYSTEM_STATE_TERMINATING	3

#endif
