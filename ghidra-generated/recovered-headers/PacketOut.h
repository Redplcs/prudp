// Auto-generated from PacketOut.obj.md
#ifndef _PACKETOUT_H_
#define _PACKETOUT_H_

#include <Plugins/Core/Buffer.h>
#include "PRUDPEndPoint.h"
#include "Timeout.h"

class IORequestContext;




class PacketOut {
public:
    PacketOut(PRUDPEndPoint*,unsigned char,unsigned char,Buffer*);
    virtual ~PacketOut();
    Timeout*  GetTimeout(void);
    void IncNbTransmission(void);
    unsigned short GetNbTransmission(void);
    PRUDPEndPoint*  GetEndPoint(void);
    void SetIORequestContext(IORequestContext*);
    IORequestContext*  GetIORequestContext(void);
    bool Pack(Buffer*);
};

#endif // _PACKETOUT_H_
