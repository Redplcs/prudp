//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Migration_H_
#define _Migration_H_

#define FORCED_MIGRATION					1<<16

// Group = Miscellaneous Types and Macros

/*
Summary: Emigration of a duplicated object is requested since a process 
is leaving the session.
Remarks: When a process leaves, the DuplicatedObject::ApproveEmigration system 
callback is called with this reason to determine if the duplicated object for 
which the process is Duplication master should emigrate to another station.
See also: DuplicatedObject::ApproveEmigration
*/
#define MIGRATION_REASON_LEAVING_SESSION		0

/*
$ifdef TSIS$
{secret}
$endif$

Summary: Emigration of a duplicated object is requested since a process 
is leaving the game.
Remarks: When a process leaves, the DuplicatedObject::ApproveEmigration system 
callback is called with this reason to determine if the duplicated object for 
which the process is Duplication master should emigrate to another station.

Note: This method is now obsolete. Use MIGRATION_REASON_LEAVING_SESSION.

See also: DuplicatedObject::ApproveEmigration
*/
#define MIGRATION_REASON_LEAVING_GAME		MIGRATION_REASON_LEAVING_SESSION

/*
$ifdef NETZ$
{secret}
$endif$

Summary: Emigration of a duplicated object is requested since a process is 
leaving the session.
Remarks: When a process leaves, the DuplicatedObject::ApproveEmigration system callback 
is called with this reason to determine if the duplicated object for which the process 
is Duplication master should emigrate to another station.

Note: This method is now obsolete. Use MIGRATION_REASON_LEAVING_SESSION.

See also: DuplicatedObject::ApproveEmigration
*/
#define MIGRATION_REASON_LEAVING_CLUSTER	0

/*
Summary: Emigration of a duplicated object is requested to perform load balancing.
Remarks: When load balancing is called the DuplicatedObject::ApproveEmigration system 
callback is called with this reason to determine if the duplicated object should emigrate 
to another station.
See also: DuplicatedObject::ApproveEmigration
*/
#define MIGRATION_REASON_LOAD_BALANCING		1
#define MIGRATION_REASON_TWO_MASTERS		(2 | FORCED_MIGRATION)
#define MIGRATION_REASON_USER_REQUEST		3

#define MIGRATE_TO_ANY_LOCATION				INVALID_DOHANDLE

#endif

