//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _EndPoint_H_
#define _EndPoint_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Platform/UserContext.h>
class Buffer;
class Transport;
class StationURL;
class EndPointEventHandler;

#define MSG_UNRELIABLE	0x0
#define MSG_RELIABLE	0x1
#define MSG_PRIO_HIGH	0x2
#define MSG_PRIO_NORMAL	0x0
#define MSG_PRIO_LOW	0x4

class EndPoint {
public:
	typedef void (*Callback)(EndPoint* pEndPoint, Buffer *pBuffer, unsigned long ulResult, UserContext *pContext);


	EndPoint(Transport *pTransport);
	~EndPoint();

	unsigned long	Connect(StationURL *pStationURL, Buffer *pBuffer, 
							unsigned long ulTimeout = 30000);
	unsigned long	Connect(StationURL *pStationURL, Buffer *pBuffer, 
							const EndPoint::Callback pCallback, const UserContext &oContext, 
							unsigned long ulTimeout = 30000);

	unsigned long	Disconnect(unsigned long ulTimeout = 30000);
	unsigned long	Disconnect(const EndPoint::Callback pCallback, const UserContext &oContext, 
								unsigned long ulTimeout = 30000);

	unsigned long 	Delete();

	unsigned long	Send(Buffer *pBuffer, unsigned long ulFlags = 0);
	unsigned long	Send(Buffer *pBuffer, 
							const EndPoint::Callback pCallback, const UserContext &oContext, 
							unsigned long ulFlags = 0);

	bool			IsConnected();
	bool			IsPeerConnected();
	bool			IsDisconnected();
	bool			IsPeerDisconnected();
	unsigned long	RegisterEventHandler(EndPointEventHandler *pEndPointEventHandler);
	unsigned long	GetQueueSize();

	void				SetUserContext(const UserContext& oContext);
	const UserContext&	GetUserContext() const;

	StationURL 			*GetStationURL();
	void	 			ReleaseURL(StationURL *pStationURL);

	Transport				*GetTransport();
	EndPointEventHandler	*GetEventHandler();

	unsigned long			GetRTT();
	unsigned long			GetRTTAverage();

#ifdef _TEST_ENABLED
	static bool Test();
#endif

protected:
	Transport				*m_pTransport;
	EndPointEventHandler	*m_pEventHandler;
	UserContext				m_oContext;
};


#endif
