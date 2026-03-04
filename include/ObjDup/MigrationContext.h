//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MigrationContext_H_
#define _MigrationContext_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/DOHandle.h>
#include <ObjDup/DORef.h>
#include <ObjDup/CallContext.h>

// Group=Call Contexts

/*
Summary: This class defines the context of a Migration call.
Remarks: Before the migration of an object is performed the context of the call must be 
defined via this class.  Within this class you set the appropriate flags and can also 
obtain information about the CallContext::State and CallContext::Outcome of the call.
Migration is performed via the calls DuplicatedObject::Emigrate or DuplicatedObject::AttemptEmigration.
*/
class MigrationContext: public CallContext {
//Group=
	public:
		
		//Remarks: By default a migration call will be made asynchronously.
		//Parameters:
		//bSynchronousCall: true if the call is made asynchronously, false if asynchronously.
		MigrationContext(bool bSynchronousCall=true);
		virtual ~MigrationContext();

		//Description: Use this method to retrieve the DOHandle of a migrating object.
		//Returns: The DOHandle of the object that is in the process of migrating or will migrate.
		DOHandle GetMigratingObject() {return m_refMigratingObject.GetHandle();}

		// {secret}
		virtual void Trace(unsigned long ulTraceFlags);
		// {secret}
		virtual Type GetType() const {return MigrationCall;}

		// {secret}
		bool MigrateObject(DOHandle hMigratingObject, DOHandle hNewStation);

		// {secret}
		virtual bool SendCallMessage(Message* pCallMessage);

		// {secret}
		virtual void ProcessOutcome(Outcome uOutcome);

	private:
		DORef m_refMigratingObject;
};
		

#endif
