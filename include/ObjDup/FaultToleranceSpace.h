//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _FaultToleranceSpace_H_
#define _FaultToleranceSpace_H_

#include <ObjDup/ObjDupDecl.h>

#include <ObjDup/FaultToleranceSpaceDDL.h>
#include <ObjDup/DOHandle.h>

class SecondaryStation;

class FaultToleranceSpace: public DUPSPACE(FaultToleranceSpace) {
	public:

		FaultToleranceSpace();
		virtual ~FaultToleranceSpace();

		virtual bool PSMatch(DuplicatedObject* pPublisher, DuplicatedObject* pSubscriber);

		// In this space, although no user cells are defined, we don't
		// use default cells.
		virtual bool CellMatch(DuplicatedObject* pPorS, DuplicatedObject* pCell) {SYSTEMCHECK(false); return false;}
		virtual void CreateCells() {};
		virtual bool UsesDefaultCells() {return false;}

		static void CheckSecondaryStationsLocation();
		static void CheckSecondaryStationLocation(SecondaryStation* pStation);

		static void DeleteSecondaryStation(DOHandle hPrimaryStation);
		
		void Enable();
		void Disable();
		bool IsEnabled() {return m_bEnabled;}

	private:
		void MigrateASecondary(DOHandle hSecondaryToMigrate);

		
	private:
		bool m_bEnabled;		
};

#endif
