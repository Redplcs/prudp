//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Transport_H_
#define _Transport_H_

#include <Plugins/Core/PluginObject.h>
#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/EndPointGroup.h>
#include <Plugins/Transport/Interface/TransportTable.h>
#include <Plugins/Transport/Interface/TransportPerfCounters.h>
#include <Plugins/Transport/Interface/TransportCaps.h>
#include <Plugins/Transport/Interface/TransportOptions.h>
#include <Platform/UserContext.h>
class OutputEmulationDevice;
class InputEmulationDevice;
class TransportEventHandler;
class TransportTable;

//Group=Plug-ins

//Description: Use this class to specify specific atributes of a transport plug-in.  
//Remarks: This class is used to specify specific atributes of a transport plug-in.
class Transport: public PluginObject {

	friend class EndPoint;
	friend class EndPointGroup;

public:
//Group=
	//{secret}
	typedef void (*Callback)(Transport*, Buffer *pBuffer, unsigned long ulResult, UserContext *pContext);

	Transport(Plugin *pPlugin);
	virtual ~Transport();

	//{secret}
	virtual bool			ResponsibleForURL(StationURL *pStationURL) = 0;
	//{secret}
	virtual TCHAR 			*GetType() = 0;
	
	//{secret}
	virtual unsigned long 	Initialize();

	//{secret}
	virtual EndPoint 		*CreateEndPoint() = 0;
	//{secret}
	virtual unsigned long	DeleteEndPoint(EndPoint *pEndPoint) = 0;

	//{secret}
	virtual unsigned long	ListenOnWellKnown() = 0;
	//{secret}
	virtual unsigned long	ListenOnArbitrary() = 0;

	//{secret}
	virtual unsigned long	StopListenOnWellKnown() = 0;
	//{secret}
	virtual unsigned long	StopListenOnArbitrary() = 0;

	//{secret}
	virtual unsigned long	RegisterEventHandler(TransportEventHandler *pEventHandler);

	//{secret}
	virtual unsigned long	SendBroadcast(Buffer *pBuffer);
	virtual unsigned long	SendBroadcast(Buffer *pBuffer, 
										const Transport::Callback pCallback, const UserContext &oContext);

	//{secret}
	virtual unsigned long	Send(StationURL *pStationURL, Buffer *pBuffer) = 0;
	virtual unsigned long	Send(StationURL *pStationURL, Buffer *pBuffer, 
										const Transport::Callback pCallback, const UserContext &oContext) = 0;

	//{secret}
	virtual unsigned long	AddEndPointToGroup(EndPoint *pEndPoint, EndPointGroup *pEndPointGroup);
	//{secret}
	virtual unsigned long	RemoveEndPointFromGroup(EndPoint *pEndPoint, EndPointGroup *pEndPointGroup);

	//{secret}
	TransportEventHandler	*GetEventHandler();

	/*
	Description: Use this method to determine the  capabilities of the currently loaded transport protocol.
	Returns: true if the currently loaded transport protocol is capable of supporting the specified
	capability, false if it is not.
	Remarks: The capabilities of a transport is one of the following: TRANSPORT_CAPS_IP_BASED,
	TRANSPORT_CAPS_BROADCAST, TRANSPORT_CAPS_DEVICE_EMULATION, TRANSPORT_CAPS_PERF_COUNTERS,				
	TRANSPORT_CAPS_GROUPING, TRANSPORT_CAPS_WELLKNOWN_LISTEN_SUPPORTED, or 
	TRANSPORT_CAPS_ARBITRARY_LISTEN_SUPPORTED	
	*/
	virtual bool 			IsCapable(unsigned long ulCapability) = 0;

	/*
	Description: Use this method to set the specific transport options of the transport plug-in
	Remarks: The transport option may be one of: TRANSPORT_OPTION_MTU, TRANSPORT_OPTION_WELLKNOWN_INFO, 	
	PRUDP_BROADCAST_EVERYWHERE, PRUDP_MAXRETRANSMISSION, PRUDP_TRAPICMPERRORS, PRUDP_MAXSILENCETIME,
	PRUDP_KEEPALIVETIMEOUT, PRUDP_TIMESLICE, or PRUDP_WINDOW_SIZE 
	See Also: GetOption
	*/
	virtual unsigned long	SetOption(unsigned long ulOption, UserContext &oOptionSetting) = 0;
	
	//Description: Use this method to return the specific transport options set via SetOption.
	//Returns: The transport options of the transport plug-in.
	//See Also: SetOption
	virtual unsigned long	GetOption(unsigned long ulOption, UserContext &oOptionSetting) = 0;

	/*
	Description: Use this method to return a StationURL for a given IP address and port number.
	Returns: The StationURL for a given IP address and port number.
	Remarks: This method will only succeed if the transport is IP based
	See Also: IsCapable, TRANSPORT_CAPS_IP_BASED, StationURL
	*/
	virtual StationURL 		*GetIPURL(unsigned long ulAddress, unsigned short usPort);
	virtual StationURL 		*GetIPURL(TCHAR *szAddress, unsigned short usPort);

	/*
	Description: Use this method to return an IP address and port number for a given StationURL.
	Returns: An IP address and port number for a given StationURL.
	Remarks: This method will only succeed if the transport is IP based.
	See Also: IsCapable, TRANSPORT_CAPS_IP_BASED, StationURL
	*/
	virtual bool 			GetIPFromURL(StationURL *pStationURL, unsigned long *ulAddress, unsigned short *usPort);

	//Description: Use this method to retrieve the number of local URLs.
	//Returns: The number of local URLs.
	virtual unsigned long	GetNbLocalURL() = 0;
	
	//Description: Use this method to retrieve the local URL.
	//Returns: The URL of the local station.
	virtual StationURL 		*GetLocalURL(unsigned long ulIndex) = 0;
	
	//Description: Deletes the station URL obtained via GetIPURL or GetLocalURL.
	virtual void 			ReleaseURL(StationURL *pStationURL) = 0;

	//Description: Use this method to access the performance counters.
	//Returns: A pointer to an instance of TransportPerfCounters.
	TransportPerfCounters	*GetPerfCounters();

	//Description: Use this method to access an instance of the OutputEmulationDevice.
	//Returns: A pointer to an instance of the OutputEmulationDevice.
	OutputEmulationDevice	*GetOutputEmulationDevice();
	
	//Description: Use this method to access an instance of the InputEmulationDevice.
	//Returns: A pointer to an instance of the InputEmulationDevice.
	InputEmulationDevice	*GetInputEmulationDevice();

#ifdef _TEST_ENABLED
	//{secret}
	static bool Test();
#endif

protected:
	virtual unsigned long	ConnectEndPoint(EndPoint *pEndPoint, StationURL *pStationURL, Buffer *pBuffer, 
								const EndPoint::Callback pCallback, const UserContext &oContext, 
								unsigned long ulTimeout) = 0;
	virtual unsigned long	DisconnectEndPoint(EndPoint *pEndPoint, const EndPoint::Callback pCallback, const UserContext &oContext, 
								unsigned long ulTimeout) = 0;
	virtual unsigned long	SendToEndPoint(EndPoint *pEndPoint, Buffer *pBuffer, 
								const EndPoint::Callback pCallback, const UserContext &oContext, 
								unsigned long ulFlags) = 0;
	virtual bool			IsEndPointConnected(EndPoint *pEndPoint) = 0;
	virtual bool			IsEndPointPeerConnected(EndPoint *pEndPoint) = 0;
	virtual bool			IsEndPointDisconnected(EndPoint *pEndPoint) = 0;
	virtual bool			IsEndPointPeerDisconnected(EndPoint *pEndPoint) = 0;
	virtual unsigned long	RegisterEndPointEventHandler(EndPoint *pEndPoint, EndPointEventHandler *pEndPointEventHandler) = 0;
	virtual unsigned long	GetEndPointQueueSize(EndPoint *pEndPoint);
	virtual StationURL* 	GetEndPointStationURL(EndPoint *pEndPoint) = 0;

	virtual unsigned long	SendToEndPointGroup(EndPointGroup *pEndPoint, Buffer *pBuffer, 
								const EndPointGroup::Callback *pCallback, const UserContext &oContext, 
								unsigned long ulFlags);
	virtual unsigned long	GetEndPointRTT(EndPoint *pEndPoint) = 0;
	virtual unsigned long	GetEndPointRTTAverage(EndPoint *pEndPoint) = 0;

protected:
	TransportEventHandler   *m_pEventHandler;
	TransportPerfCounters	*m_pPerfCounters;
	OutputEmulationDevice	*m_pOutputEmulationDevice;
	InputEmulationDevice	*m_pInputEmulationDevice;
};


#endif
