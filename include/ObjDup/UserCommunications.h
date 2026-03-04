//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _UserCommunications_H_
#define _UserCommunications_H_

#include <ObjDup/ObjDupDecl.h>
#include <Plugins/Protocol/Interface/Message.h>

#define USER_STATION_MESSAGE     0
#define SYSTEM_STATION_MESSAGE   1 

class UserCommunications {
	// Group=
	public:
		UserCommunications();
		virtual ~UserCommunications();

	public:

		bool SendMessageToAStation(unsigned long ulNodeID, unsigned int uiLength, unsigned char* pbyMessage);
		bool BroadcastMessage(unsigned int uiLength, unsigned char* pbyMessage);		
};

#endif
