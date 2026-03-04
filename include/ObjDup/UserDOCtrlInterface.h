//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOCtrlInterface.h>
#include <Utility/PseudoSingleton.h>

#ifndef _UserDOCtrlInterface_H_
#define _UserDOCtrlInterface_H_

//group=Control Interface

/*
summary:  UserDOCtrlInterface is the class that inherits methods from DOCtrlInterface 
as well as adds Observer related methods (see Dead Reckoning Overview.)

Remarks: This class contains Observer related methods 
(see Dead Reckoning Overview) of duplicated object control.  All of the
DOCtrlInterface methods are available through inheritance. 

See also: $PRODUCTNAME$::GetUserDOCtrlInterface, Interface Overview
*/
class UserDOCtrlInterface: public DOCtrlInterface {
	
//Group=
	public:
		UserDOCtrlInterface();
		virtual ~UserDOCtrlInterface();

		// {Secret}
		void AssociateDOS(DuplicatedObjectStore* pDOS);

		bool GetObserver(DOHandle* phObserver);
		bool RegisterObserver(DOHandle hObserver);
		bool UnregisterObserver();

/*
Description: 
Returns true if the UserDOCtrlInterface is valid, false otherwise.
	
Returns:
Returns true if the UserDOCtrlInterface is valid, false otherwise.
If more than one UserDOCtrlInterface is created, it will not be valid.
		
*/
		bool IsValid() const;

		static UserDOCtrlInterface* GetInstance();

	private:
		PseudoSingleton m_psInstance;

#ifdef _TEST_ENABLED
	public:
		static bool Test();
#endif
};

#endif
