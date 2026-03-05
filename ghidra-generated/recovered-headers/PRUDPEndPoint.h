// Auto-generated from PRUDPEndPoint.obj.md
#ifndef _PRUDPENDPOINT_H_
#define _PRUDPENDPOINT_H_

#include <Platform/Time.h>
#include <Platform/UserContext.h>
#include <Plugins/Core/Buffer.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Transport/Interface/StationURL.h>
#include <Plugins/Transport/Interface/Transport.h>
#include "PRUDPInetAddress.h"
#include "PRUDPTransport.h"
#include "Packet.h"
#include "PacketIn.h"
#include "PacketOut.h"
#include "RTT.h"




class PRUDPEndPoint {
public:
    PRUDPEndPoint(Transport*,unsigned long);
    ~PRUDPEndPoint();
    unsigned long Connect(StationURL*,Buffer*,void (__cdecl*const)(EndPoint*,Buffer*,unsigned long,UserContext*),UserContext const&,unsigned long);
    unsigned long Disconnect(void (__cdecl*const)(EndPoint*,Buffer*,unsigned long,UserContext*),UserContext const&,unsigned long);
    unsigned long Send(Buffer*,void (__cdecl*const)(EndPoint*,Buffer*,unsigned long,UserContext*),UserContext const&,unsigned long);
    bool IsConnected(void);
    bool IsDisconnected(void);
    unsigned long GetQueueSize(void);
    unsigned long GetNbReliablePending(void);
    StationURL*  GetStationURL(void);
    bool IsPeerConnected(void);
    bool IsPeerDisconnected(void);
private:
    bool Send(PacketOut*);
    void SendNextReliable(void);
    void SendReliable(PacketOut*);
    PacketIn*  GetNextDispatchPacket(void);
    void Dispatch(PacketIn*,Time);
    void SignalFaultEvent(unsigned long);
    void ServiceIncomingPacket(PacketIn*);
    void PacketAcknowledged(Packet*);
    void ServiceTimeout(PacketOut*);
    void CancelPacketTimeout(PacketOut*);
    void StartPing(void);
    void StopPing(void);
    void TimeToPing(void);
    void SetState(PRUDPEndPoint::_ConnectionState);
    void GetStringState(char*);
    void TraceState(unsigned long);
    bool ReadyToDisconnect(void);
    bool IsNotConnected(void);
    bool IsConnecting(void);
    bool IsDisconnecting(void);
    bool IsPeerFlooded(void);
    void SetPeerFlooded(bool);
    void SetPeerDisconnected(bool);
    void SetPeerConnected(bool);
    unsigned long GetAssociatedSocket(void);
    RTT*  GetRTT(void);
    void SetSocket(unsigned long);
    bool IsIdle(void);
    void SetPRUDPInetAddress(PRUDPInetAddress*);
    PRUDPInetAddress*  GetPRUDPInetAddress(void);
    bool IsFlooded(void);
    PRUDPTransport*  GetTransport(void);
};

#endif // _PRUDPENDPOINT_H_
