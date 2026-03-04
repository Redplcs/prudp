//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _StationOperation_H_
#define _StationOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/Station.h>
#include <ObjDup/Operation.h>
#include <ObjDup/DOHandle.h>
#include <Utility/CallbackList.h>

//Group = System Operations
/*
Description:
StationOperation encapsulates operations done on stations.

Remarks:
The types of Station operations are AddToStore, RoleChange, MasterIDChange,
FaultRecovery, RemoveFromStore.  

*/
class StationOperation: public DOOperation {
//Group=Operations	
	public:
		//{secret}
		StationOperation(Station* pStation);
		//{secret}
		virtual ~StationOperation();
};

#endif
