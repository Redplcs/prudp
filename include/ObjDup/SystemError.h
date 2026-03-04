//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ObjDupSystemError_H_
#define _ObjDupSystemError_H_


// Group = System Errors
/*
description:
A method was called on a Duplica but the method is only valid on a Duplication master.
*/
#define	SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,0)

/*
description:
A method was called on a Duplication master but the method is only valid on a Duplica.
*/
#define	SYSTEMERROR_OBJDUP_INVALID_ON_MASTER	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,1)

/*
description:
An operation was called that would cause an invalid object property transition.

remarks:
An example of such an operation is to call DuplicatedObject::MarkForDeletion
more than once on a duplicated object.
*/
#define SYSTEMERROR_OBJDUP_INVALID_PROPERTY_TRANSITION	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,2)

/*
{secret}
description:
An attempt was made to call a non-existent duplicated object method.
Check the DDL file and ensure that the function is declared.

Note:
Callbacks are now obsolete, please see Iterators Overview for more details.
*/
#define SYSTEMERROR_OBJDUP_UNDEFINED_CALLBACK	SET_ERROR_CODE(SEV_WARNING,SUBSYSTEM_OBJDUP,3)

/*
description:
The duplicated object was not found.  This is usually because the DOHandle passed to 
a function is invalid or the object represented by the DOHandle no longer exists.
*/
#define SYSTEMERROR_OBJDUP_DO_NOT_FOUND		SET_ERROR_CODE(SEV_WARNING,SUBSYSTEM_OBJDUP,4)

/*
description:
One or more arguments to the function are invalid.
*/
#define SYSTEMERROR_OBJDUP_INVALID_PARAMETER	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,5)

/*
description:
An attempt was made to migrate an object to an invalid location.
Examples of invalid locations are the migration of an object to the local
station and the migration of an object to a StationID that does not exist or
that has earlier failed.

See Also: DuplicatedObject::AttemptEmigration
*/
#define SYSTEMERROR_OBJDUP_CANNOT_EMIGRATE	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,6)

/*
description:
An attempt was made at publishing a duplicated object using a pointer that
was obtained by manually instanciating the DuplicatedObject.  The correct way
to create a duplicated object is via the method DuplicatedObject::Create.

See Also: DuplicatedObject::Create, DuplicatedObject::Publish
*/
#define SYSTEMERROR_OBJDUP_INVALID_CONSTRUCTION  SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,7)

/*
description:
A duplicated object cannot be published more than once.

See Also: DuplicatedObject::Publish
*/
#define SYSTEMERROR_OBJDUP_ALREADY_PUBLISHED	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,8)

/*
description:
A dataset specified a custom update policy but the corresponding callback was not defined.
See Also: DataSet::ReliableUpdate
*/
#define SYSTEMERROR_MISSING_DATASET_CALLBACK	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,9)

/*
description:
The duplicated object corresponding to a declared well-known handle has not been initialized yet.
*/
#define SYSTEMERROR_OBJDUP_WKHANDLE_NOT_INITIALIZED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,10)

/*
description:
A duplicated object corresponding to a well-known handle has been
created on a node that joins a session.
*/
#define SYSTEMERROR_OBJDUP_WKHANDLE_WERE_CREATED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,11)

/*
description:
The duplicated object that a DOHandle refers to does not match the
type of the reference being constructed.
*/
#define SYSTEMERROR_OBJDUP_MISMATCHED_DOCLASS SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,12)

/*
description:
A duplicated object corresponding to a well-known handle has been
created twice.
*/
#define SYSTEMERROR_OBJDUP_WKHANDLE_EXISTS		SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,13)

/*
description: A generic duplicated object cannot be published.
See Also: DuplicatedObject::Publish
*/
#define SYSTEMERROR_OBJDUP_CANNOT_PUBLISH	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,14)

/*
description:
The station was not found.  This is usually because the StationID passed to a 
function is invalid or represents a station that has left the session.
*/
#define SYSTEMERROR_OBJDUP_STATION_NOT_FOUND		SET_ERROR_CODE(SEV_WARNING,SUBSYSTEM_OBJDUP,15)



/*
Summary:  An attempt was made to create or join the session more than once.
See Also: Session::CreateSession, Session::JoinSession.
*/
#define	SYSTEMERROR_DC_CLUSTER_REDEFINITION	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,16)

/*
Summary:  An attempt was made to join a session and the station hosting the session
denied the join request.  
See Also: Session::JoinSession.
*/
#define SYSTEMERROR_DC_CLUSTER_JOIN_DENIED	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,17)

/*
Summary:  The join operation failed due to a transient network failure.
See Also: Session::JoinSession.
*/
#define SYSTEMERROR_DC_CLUSTER_JOIN_FAILED	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,18)

/*
{Secret}
*/
#define SYSTEMERROR_DC_MISMATCHED_BARRIER_ID	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,19)
/*
{Secret}
*/
#define SYSTEMERROR_DC_BARRIER_TIMEOUT		SET_ERROR_CODE(SEV_INFORMATIONAL,SUBSYSTEM_OBJDUP,20)

/*
Summary: An operation that requires the session to be initialized was called, but
the session had not been initialized beforehand.

See Also: Session::CreateSession, Session::JoinSession
*/
#define SYSTEMERROR_DC_CLUSTER_NOT_INITIALIZED	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,21)

/*
Summary:  An operation that must be called on the session master was called on a secondary node.
*/
#define SYSTEMERROR_DC_NOT_CLUSTER_MASTER	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,22)

/*
Summary:  An invalid system state transition occured.
*/
#define SYSTEMERROR_DC_INVALID_STATE_TRANSITION	SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,23)

/*
Summary:  A method that must be called prior to Session::CreateSession 
or Session::JoinSession was called after Session::CreateSession or 
Session::JoinSession was called.
*/
#define SYSTEMERROR_DC_CLUSTER_ALREADY_INITIALIZED SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,24)

/*
Summary:  No responsible transport found for the specified URL.  The
transport type was not recognized by the loaded transports.
*/
#define SYSTEMERROR_OBJDUP_TRANSPORT_NOT_FOUND SET_ERROR_CODE(SEV_ERROR,SUBSYSTEM_OBJDUP,25)


#endif
