//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProductFacade_H_
#define _ProductFacade_H_

#include <Products/Foundation/FacadesDecl.h>
#include <Utility/PseudoSingleton.h>
#include <ObjDup/DuplicationSpaceTable.h>
#include <ObjDup/SessionCtrlInterface.h>
#include <ObjDup/UserDOCtrlInterface.h>
class CoreDOCtrlInterface;
class ProductSpecifics;
class UtilitySubsystem;
class ObjDupSubsystem;
class DuplicatedObjectStore;

/*

{group: ProductFacade Library}
{noAutoLink}

ProductFacade is the class that encapsulates the run time of the
product.  

*/
class ProductFacade: public PseudoSingleton {
	public:
		ProductFacade(SessionCtrlInterface* pSessionCtrl,
					  UserDOCtrlInterface* pDOCtrl,
					  ProductSpecifics* pProductSpecifics);
		virtual ~ProductFacade();

		void InitSubsystems();
		void DestroySubsystems();

		SessionCtrlInterface* GetSessionCtrlInterface() {
			return m_poSessionCtrl;
		}

		UserDOCtrlInterface* GetUserDOCtrlInterface() {
			return m_poDOCtrl;
		}

		// TODO: Document this.
		bool IsValid() const {return m_bIsValid;}

		void TraceSystemState(unsigned long ulTraceFlag=TRACE_ALWAYS);


	protected:
		static UtilitySubsystem*		s_poUtilitySubsystem;
		static ObjDupSubsystem*			s_poObjDupSubsystem;

		static unsigned int s_uiProductFacadeCount;

		DuplicatedObjectStore* m_pDOS;

		// Control interfaces.

		SessionCtrlInterface* m_poSessionCtrl;
		bool m_bDeleteSessionCtrl;

		CoreDOCtrlInterface* m_poCoreDOCtrl;

		UserDOCtrlInterface* m_poDOCtrl;
		bool m_bDeleteDOCtrl;

		DuplicationSpaceTable m_oDSTable;

		ProductSpecifics* m_pProductSpecifics;

		bool m_bIsValid;

		bool m_bPluginManagerOwner;
};

#endif
