#ifndef _PacketOut_H_
#define _PacketOut_H_

#include <Plugins/Core/Buffer.h>
#include "PRUDPEndPoint.h"
#include "Timeout.h"
#include "Packet.h"

class IORequestContext;

class PacketOut : public Packet {
public:

	PacketOut(PRUDPEndPoint *pEndPoint, unsigned char ucType, unsigned char ucFlags, Buffer *pPayload);
	virtual ~PacketOut();

	Timeout *GetTimeout();
	void IncNbTransmission();
	unsigned short GetNbTransmission();
	PRUDPEndPoint *GetEndPoint();

	void SetIORequestContext(IORequestContext *pContext);
	IORequestContext *GetIORequestContext();

	bool Pack(Buffer *pBuffer);

};

#endif
