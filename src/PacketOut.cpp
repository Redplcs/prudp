#include "PacketOut.h"

#include <stdlib.h>

PacketOut::PacketOut(PRUDPEndPoint *pEndPoint, unsigned char ucType, unsigned char ucFlags, Buffer *pPayload)
{
	SetType(ucType);
	SetFlag(ucFlags);
	m_usNbTransmission = 0;
	m_tRetransmitTime = 0;
	m_pIORequestContext = NULL;
	m_pEndPoint = pEndPoint;
	SetContextInfo((unsigned char)rand());

	if (pPayload != NULL) {
		SetPayload((Buffer *)pPayload->AcquireRef());
	}

	if (FlagSet(0x20)) {
		m_pTimeout = new Timeout;
	} else {
		m_pTimeout = NULL;
	}
}

PacketOut::~PacketOut()
{
	if (m_pIORequestContext != NULL) {
		delete m_pIORequestContext;
	}

	if (m_pTimeout != NULL) {
		delete m_pTimeout;
	}
}

Timeout *PacketOut::GetTimeout()
{
	return m_pTimeout;
}

void PacketOut::IncNbTransmission()
{
	m_usNbTransmission++;
}

unsigned short PacketOut::GetNbTransmission()
{
	return m_usNbTransmission;
}

PRUDPEndPoint *PacketOut::GetEndPoint()
{
	return m_pEndPoint;
}

void PacketOut::SetIORequestContext(IORequestContext *pContext)
{
	m_pIORequestContext = pContext;
	pContext->m_pPacket = this;
}

IORequestContext *PacketOut::GetIORequestContext()
{
	return m_pIORequestContext;
}

bool PacketOut::Pack(Buffer *pBuffer)
{
	if (!pBuffer->AppendData(&m_ucTypeFlags, 8)) {
		return false;
	}

	if (GetPayload() != NULL) {
		*pBuffer += *GetPayload();
	}

	pBuffer->AppendCheckSum();
	return true;
}
