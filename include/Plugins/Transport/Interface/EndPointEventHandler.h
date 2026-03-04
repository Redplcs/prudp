//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _EndPointEventHandler_H_
#define _EndPointEventHandler_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/EndPoint.h>

#define NET_FAULT_CONNRESET		1
#define NET_FAULT_TIMEOUT		2
#define NET_FAULT_UNREACHABLE	3

class EndPointEventHandler {

public:

	EndPointEventHandler();
	virtual ~EndPointEventHandler();

	virtual void Receive(EndPoint *pEndPoint, Buffer *pBuffer);
	virtual void FaultDetection(EndPoint *pEndPoint, unsigned long ulFault);
	virtual void FloodDetection(EndPoint *pEndPoint);
	virtual void PeerDisconnected(EndPoint *pEndPoint);
};


#endif
