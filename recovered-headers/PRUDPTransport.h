// Auto-generated from PRUDPTransport.obj.md
#ifndef _PRUDPTRANSPORT_H_
#define _PRUDPTRANSPORT_H_

#include <Platform/UserContext.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Core/Plugin.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/EndPointEventHandler.h>
#include <Plugins/Transport/Interface/EndPointGroup.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/Transport.h>
#include "ICMPSocket.h"
#include "PRUDPEndPoint.h"
#include "PRUDPInetAddress.h"
#include "PRUDPTransportSettings.h"
#include "Packet.h"
#include "PacketOut.h"
#include "TimeoutManager.h"
#include "UDPSocket.h"




class PRUDPTransport {
public:
    PRUDPTransport(Plugin*);
    virtual ~PRUDPTransport();
    virtual bool ResponsibleForURL(StationURL*);
    virtual char*  GetType(void);
    virtual unsigned long Initialize(void);
    virtual unsigned long ListenOnWellKnown(void);
    virtual unsigned long ListenOnArbitrary(void);
    virtual unsigned long StopListenOnWellKnown(void);
    virtual unsigned long StopListenOnArbitrary(void);
    virtual EndPoint*  CreateEndPoint(void);
    virtual unsigned long DeleteEndPoint(EndPoint*);
    virtual unsigned long SendBroadcast(Buffer*);
    virtual unsigned long SendBroadcast(Buffer*,void (__cdecl*const)(Transport*,Buffer*,unsigned long,UserContext*),UserContext const&);
    virtual unsigned long Send(StationURL*,Buffer*);
    virtual unsigned long Send(StationURL*,Buffer*,void (__cdecl*const)(Transport*,Buffer*,unsigned long,UserContext*),UserContext const&);
    virtual unsigned long GetNbLocalURL(void);
    virtual StationURL*  GetLocalURL(unsigned long);
    virtual StationURL*  GetIPURL(unsigned long,unsigned short);
    virtual StationURL*  GetIPURL(char*,unsigned short);
    virtual bool GetIPFromURL(StationURL*,unsigned long*,unsigned short*);
    virtual void ReleaseURL(StationURL*);
    virtual bool IsCapable(unsigned long);
    virtual unsigned long SetOption(unsigned long,UserContext&);
    virtual unsigned long GetOption(unsigned long,UserContext&);
    void SetHighPrio(void);
    void TraceProto(char*,Packet*,PRUDPInetAddress*,PRUDPInetAddress*,unsigned long);
protected:
    virtual unsigned long ConnectEndPoint(EndPoint*,StationURL*,Buffer*,void (__cdecl*const)(EndPoint*,Buffer*,unsigned long,UserContext*),UserContext const&,unsigned long);
    virtual unsigned long DisconnectEndPoint(EndPoint*,void (__cdecl*const)(EndPoint*,Buffer*,unsigned long,UserContext*),UserContext const&,unsigned long);
    virtual unsigned long SendToEndPoint(EndPoint*,Buffer*,void (__cdecl*const)(EndPoint*,Buffer*,unsigned long,UserContext*),UserContext const&,unsigned long);
    virtual bool IsEndPointConnected(EndPoint*);
    virtual bool IsEndPointPeerConnected(EndPoint*);
    virtual bool IsEndPointDisconnected(EndPoint*);
    virtual bool IsEndPointPeerDisconnected(EndPoint*);
    virtual unsigned long RegisterEndPointEventHandler(EndPoint*,EndPointEventHandler*);
    virtual StationURL*  GetEndPointStationURL(EndPoint*);
    virtual unsigned long GetEndPointQueueSize(EndPoint*);
    virtual unsigned long GetEndPointRTT(EndPoint*);
    virtual unsigned long GetEndPointRTTAverage(EndPoint*);
    virtual unsigned long SendToEndPointGroup(EndPointGroup*,Buffer*,void (__cdecl*const*)(EndPointGroup*,Buffer*,UserContext*),UserContext const&,unsigned long);
private:
    void StartEventListener(void);
    bool UDPListen(unsigned long,unsigned short);
    bool StopUDPListen(unsigned long);
    bool ICMPListen(unsigned long,unsigned short);
    bool StopICMPListen(unsigned long);
    bool RegisterEndPoint(PRUDPEndPoint*);
    void UnregisterEndPoint(PRUDPEndPoint*);
    void SendReset(unsigned long,PRUDPInetAddress*);
    PRUDPEndPoint*  ServiceConnectionRequest(PRUDPInetAddress*,Buffer*,unsigned long);
    void ServiceUserMsg(PRUDPInetAddress*,Buffer*);
    void DemuxIncomingPacket(unsigned long);
    void CompleteICMP(ICMPSocket*);
    bool Send(unsigned long,PacketOut*);
    TimeoutManager*  GetTimeoutManager(void);
    void TimeSliceHandler(void);
    UDPSocket*  GetSocket(unsigned char);
    unsigned short GetPortNumber(unsigned long);
    PRUDPTransportSettings*  GetSettings(void);
};

class PRUDPEndPointMap {
public:
    ~PRUDPEndPointMap();
};

#endif // _PRUDPTRANSPORT_H_
