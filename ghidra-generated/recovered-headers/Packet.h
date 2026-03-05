// Auto-generated from Packet.obj.md
#ifndef _PACKET_H_
#define _PACKET_H_

#include <Platform/Time.h>
#include <Plugins/Core/Buffer.h>
#include "PRUDPInetAddress.h"




class Packet {
public:
    Packet(void);
    virtual ~Packet();
    Buffer*  GetPayload(void);
    unsigned long GetHeader(void* *);
    bool Valid(void);
    void SetSeqId(unsigned long);
    unsigned long GetSeqId(void);
    PRUDPInetAddress*  GetPeerAddress(void);
    void SetPeerAddress(PRUDPInetAddress*);
    void SetType(unsigned char);
    unsigned char GetType(void);
    void SetContextInfo(unsigned char);
    unsigned char GetContextInfo(void);
    void SetFlag(unsigned char);
    void ClearFlag(unsigned char);
    bool FlagSet(unsigned char);
    unsigned short GetSize(void);
    void SetIOTime(Time);
    Time GetIOTime(void);
    void SetIOResult(unsigned long);
    unsigned long GetIOResult(void);
    void Trace(void);
protected:
    bool SetPayload(Buffer*);
};

#endif // _PACKET_H_
