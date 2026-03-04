//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, SecondaryStation.h

#ifndef _SecondaryStation_H_
#define _SecondaryStation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/SecondaryStationDDL.h>
#include <ObjDup/Station.h>

class SecondaryStation: public DOCLASS(SecondaryStation) {
	public:
		SecondaryStation();
		~SecondaryStation();
		
		bool ApproveEmigration(unsigned long ulReason);
		bool ApproveFaultRecovery() {return true;}

		// TODO: Rename to GetPrimaryStation?
		DOHandle GetPrimaryStationHandle();
		
		void OperationEnd(DOOperation* pOperation);

		void MigrateToAnotherStation();
		
		static DOHandle FindSecondary(DOHandle hStation=Station::GetLocalStation());
		
		void Trace(unsigned long ulTraceFlag);
};

#endif
