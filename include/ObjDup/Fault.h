//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Fault_H_
#define _Fault_H_

#include <ObjDup/ObjDupDecl.h>

class Cluster;
class PeerNode;
#include <ObjDup/DOHandle.h>
#include <ObjDup/Station.h>

class Fault {
	// Group=
	public:

		static void ProcessFaultIfRequired(DOHandle hStation);
		void Trace(unsigned long ulTraceFlags=TRACE_ALWAYS);

#ifdef linux
	protected:
		// These methods should be private.  However, gcc does not like
		// having a private destructor.
#else
	private:
#endif
		Fault(DOHandle hStation);
		virtual ~Fault();

	private:

		void CreateProcessFaultThread();
		void ProcessFaultThreadRoot(int iDummy);
		void ProcessFault();
		
	private:
		DOHandle m_hFaultyStation;
		ICContext m_icContext;
};

#endif
