//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/ControlInterface.h>
#include <ObjDup/MethodID.h>
#include <ObjDup/GenericSelectionIterator.h>

#ifndef _DOCtrlInterface_H_
#define _DOCtrlInterface_H_

class DOFilter;
class DuplicatedObjectStore;
class WKHandle;
class DOSOperation;


//group=Control Interface

/*
summary: The DOCtrlInterface is the class that provides control over
the duplicated objects within the $GameORCluster$. 

See also: $PRODUCTNAME$::GetUserDOCtrlInterface, UserDOCtrlInterface::GetInstance, Interface Overview
*/
class DOCtrlInterface: public ControlInterface {
	public:
		DOCtrlInterface();
		virtual ~DOCtrlInterface();

		// Secret
		void SetDOFilter(DOFilter* pFilter);
		// Secret
		void SetAssociatedDOS(DuplicatedObjectStore* pDOS);
		// Secret
		DuplicatedObjectStore* GetAssociatedDOS();

		DuplicatedObject* CreateDO(DOClassID idDOClass);
		DuplicatedObject* CreateWellKnownDO(WKHandle& hWK);	
		bool PublishDO(DuplicatedObject* pDO);

		void DeleteMarkedDOs();

		// Iteration methods.

		void IterateOverAllDOs(MethodID idMethod, unsigned long ulArg=0);
		void IterateOverDuplicas(MethodID idMethod, unsigned long ulArg=0);
		void IterateOverDuplicationMasters(MethodID idMethod, unsigned long ulArg=0);

		DOHandle IterateOverAllDOs(MethodID idMethod, unsigned long ulArg, unsigned long ulStopCondition, unsigned long ulStopValue);
		DOHandle IterateOverDuplicas(MethodID idMethod, unsigned long ulArg, unsigned long ulStopCondition, unsigned long ulStopValue);
		DOHandle IterateOverDuplicationMasters(MethodID idMethod, unsigned long ulArg, unsigned long ulStopCondition, unsigned long ulStopValue);

		GenericSelectionIterator CreateAllDOsIterator();
		GenericSelectionIterator CreateDuplicasIterator();
		GenericSelectionIterator CreateDuplicationMastersIterator();


		unsigned long CallAny(DOHandle hDO, MethodID idMethod, unsigned long ulArg=0);
		unsigned long CallDuplica(DOHandle hDO, MethodID idMethod, unsigned long ulArg=0);
		unsigned long CallDuplicationMaster(DOHandle hDO, MethodID idMethod, unsigned long ulArg=0);

		bool Discovered(DOHandle hDO);
		bool WaitForDiscovery(DOHandle hDO, unsigned long ulTimeout=WAIT_INFINITE);

//group = Virtual Methods

/*
 Description: A virtual function that is called whenever a duplicated object 
 is discovered.

 Parameters:
 hDO: DOHandle of the duplicated object that was discovered. 

 Remarks:
 Redefine this method if you want to expand control over duplicated
 objects.  This method is called whenever a host discovers a new
 duplicated object as a result of someone else publishing it
 (DuplicatedObject::Publish).  

 See also:  WaitForDiscovery
*/
		virtual void DiscoveryEvent(DOHandle hDO) {}
		static void SignalDiscoveryEvent(DuplicatedObject* pDO);

		// {Secret}
		bool AtLeastOneWKCreated() {return m_bAtLeastOneWKCreated;}

		// {Secret}
		virtual void OperationBegin(DOSOperation* pOperation) {}
		// {secret}
		virtual void OperationEnd(DOSOperation* pOperation) {}

	private:
		bool m_bAtLeastOneWKCreated;
		
		DuplicatedObjectStore* m_pDOS;
		DOFilter* m_pDOFilter;
};

#endif
