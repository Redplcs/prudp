//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _FetchContext_H_
#define _FetchContext_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/DOHandle.h>
#include <ObjDup/DORef.h>
#include <ObjDup/CallContext.h>

// Group=Call Contexts

/*
Summary: This class defines the context of a call to DuplicatedObject::FetchDuplica.
Remarks: Before a call to DuplicatedObject::FetchDuplica is made, the context of the 
call must be defined via 
the FetchContext class. Within this class you set the station you wish to fetch a Duplica from
and the appropriate flags. You can also obtain information about the CallContext::State and 
CallContext::Outcome of the call. 
*/
class FetchContext: public CallContext {
//Group=
	public:
		/*
		Remarks: If no arguments are passed to the constructor, the FetchContext instance will
		initialize the value of the TargetStation to INVALID_DOHANDLE. By default the 
		DuplicatedObject::FetchDuplica call
		will be made asynchronously i.e. the thread will keep running while it waits for the
		Fetch call to return a value or an error. The method CallContext::Wait can be used if 
		the Fetch call is to be made asynchronously.

		Parameters:
		hTargetStation: The station from which we wish to fetch a Duplica.
		bSynchronousCall: true if the call is made asynchronously, false if asynchronously.
		*/
		FetchContext(DOHandle hTargetStation=INVALID_DOHANDLE,
					 bool bSynchronousCall=true);
		virtual ~FetchContext();

		//Description: Use this method to retrieve a DOHandle to a fetched object.
		//Returns: A DOHandle to a fetched object.
		DOHandle GetFetchedObject() {return m_refFetchedObject.GetHandle();}
		
		// {secret}
		void ReleaseFetchedObject() {m_refFetchedObject=INVALID_DOHANDLE;}

		// {secret}
		virtual void Trace(unsigned long ulTraceFlags);
		// {secret}
		virtual Type GetType() const {return FetchCall;}

		// {secret}
		bool FetchDuplica(DOHandle hFetchedObject);
		// {secret}
		virtual State ProcessResponse(UserContext ucResponseContext);

	private:
		DORef m_refFetchedObject;
};
		

#endif
