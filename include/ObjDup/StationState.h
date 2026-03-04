//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _StationState_H_
#define _StationState_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/StationStateDDL.h>

class StationState: public DATASET(StationState) {
	public:

		StationState();
		~StationState();

		void AssociatedStation(Station* pAssociatedStation) {m_pAssociatedStation=pAssociatedStation;}

		unsigned short Get() const {return m_usState;}
		void Set(unsigned short usValue) {m_usState=usValue;}

		void OperationBegin(DataSetOperation * pOperation);
		void OperationEnd(DataSetOperation * pOperation);

		CriticalSection& CriticalSectionRef() {return m_csStateLock;}

		TCHAR* GetStateString() const {return GetStateString(m_usState);}
		TCHAR* GetStateString(unsigned short usState) const;
		
	private:
		CriticalSection m_csStateLock;
		Station* m_pAssociatedStation;
};

#endif
