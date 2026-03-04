//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SessionSpace_H_
#define _SessionSpace_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/SessionSpaceDDL.h>
#include <ObjDup/DOHandle.h>
class IteratorOverDOs;
class DuplicatedObject;

class SessionSpace: public DUPSPACE(SessionSpace) {
	public:

		SessionSpace();
		virtual ~SessionSpace();

		void SetSessionRootMulticastGroup(DOHandle hSessionRootMulticastGroup);

		virtual bool IsADiscovery(DuplicatedObject* pPublisher, DOHandle hLocation);

		virtual bool PSMatch(DuplicatedObject* pPublisher, DuplicatedObject* pSubscriber);

		virtual bool IsDuplicaRelevant(DuplicatedObject *pDO);

		// In this space, although no user cells are defined, we don't
		// use default cells.
		virtual bool CellMatch(DuplicatedObject* pPorS, DuplicatedObject* pCell) {SYSTEMCHECK(false); return false;}
		virtual void CreateCells() {};
		virtual bool UsesDefaultCells() {return false;}

		//{secret}
		virtual void OperationEndMatchTrigger(DOOperation* pOperation);


		virtual IteratorOverDOs* CreateLocationIterator(DuplicatedObject* pPublisher);

		virtual bool UsesRegularLocationSet() {return false;}

		virtual bool UsesBroadcast() {return true;}
        
	private:
		DOHandle m_hRootMulticastGroup;
};

#endif
