//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransportEventHandler_H_
#define _TransportEventHandler_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/Transport.h>

class TransportEventHandler {

public:

	TransportEventHandler();
	virtual ~TransportEventHandler();

	virtual void Receive(Transport *pTransport, Buffer *pBuffer, StationURL *pStationURL);
	virtual void ReceiveBroadcast(Transport *pTransport, Buffer *pBuffer, StationURL *pStationURL);

	virtual void DeviceDiscovery(Transport *pTransport, TCHAR *szDevice);
	virtual bool ConnectionRequest(Transport *pTransport, StationURL *pStationURL, Buffer *pBuffer, EndPoint *pEndPoint);
};


#endif
