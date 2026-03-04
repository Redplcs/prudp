//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, StationInfo.h

#ifndef _StationInfo_H_
#define _StationInfo_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/DOSID.h>
#include <ObjDup/StationInfoDDL.h>

class StationInfo: public DATASET(StationInfo) {
	public:
		StationInfo();
		~StationInfo();		

		TCHAR *GetURL(int iIndex);
		void   SetURL(int iIndex, TCHAR *szTransportURL);
		void   AddURL(TCHAR* szTransportURL);
		
		void	OperationEnd(DataSetOperation * pOperation);

		void	InitMachineUniqueID();
		unsigned long GetMachineUniqueID();

		// This flag is true when a station has attempted a direct
		// connection using all available URLs.
		//{secret}
		bool m_bTriedAllURLs;
};

#endif
