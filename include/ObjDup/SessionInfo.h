//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, SessionInfo.h

#ifndef _SessionInfo_H_
#define _SessionInfo_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/SessionInfoDDL.h>

class SessionInfo: public DATASET(SessionInfo) {
	public:
		SessionInfo();
		~SessionInfo();

   		void SetRootMulticastGroup(DOHandle dohGroup);
		DOHandle GetRootMulticastGroup();

		void SetSessionName(TCHAR *szSessionName);
		TCHAR *GetSessionName();
};

#endif
