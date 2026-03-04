//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, PromotionReferee.h

#ifndef _PromotionReferee_H_
#define _PromotionReferee_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/PromotionRefereeDDL.h>
#include <ObjDup/ElectionTable.h>
#include <ObjDup/DOOperationCallback.h>

class PromotionReferee: public DOCLASS(PromotionReferee) {
	public:
		PromotionReferee();
		~PromotionReferee();

		// Entry point, for the system.
		DOHandle ElectNewMaster(DOHandle hObject, DOHandle hFaultyMaster, DOHandle hCalleeStation);

	private:
		// Implementation - for bootstrap.
		DOHandle ElectOwnMaster(DOHandle hFaultyMaster, DOHandle hCalleeStation);

		ElectionTable m_oLocalElectionTable;
};

#endif
