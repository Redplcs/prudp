#include "PRUDPDeviceData.h"

PRUDPDeviceData::PRUDPDeviceData(Packet *pPacket, UDPSocket *pSocket, DeliverCallback pfCallback)
	: DeviceData(pPacket->GetSize(), pfCallback)
{
	m_pPacket = (Packet *)pPacket->AcquireRef();
	m_pSocket = pSocket;
}

PRUDPDeviceData::~PRUDPDeviceData()
{
	m_pPacket->ReleaseRef();
}
