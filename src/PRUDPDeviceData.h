#ifndef _PRUDPDeviceData_H_
#define _PRUDPDeviceData_H_

#include <Plugins/Transport/Interface/DeviceData.h>
#include "Packet.h"
#include "UDPSocket.h"

class PRUDPDeviceData : public DeviceData {
public:

	PRUDPDeviceData(Packet *pPacket, UDPSocket *pSocket, DeliverCallback pfCallback);
	virtual ~PRUDPDeviceData();

	Packet *m_pPacket;
	UDPSocket *m_pSocket;

};

#endif
