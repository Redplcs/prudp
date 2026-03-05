#ifndef _PacketIn_H_
#define _PacketIn_H_

#include <Plugins/Core/Buffer.h>
#include "Packet.h"

class PacketIn : public Packet {
public:

	PacketIn();
	virtual ~PacketIn();

	bool Unpack(Buffer *pBuffer);

};

#endif
