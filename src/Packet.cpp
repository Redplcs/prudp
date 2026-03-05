#include "Packet.h"

#include <Platform/Trace.h>

Packet::Packet()
{
	m_ucTypeFlags = 0;
	m_usSize = 8;
	m_ulSeqId = 0;
	m_pPayload = NULL;
	m_ulIOResult = 0;
}

Packet::~Packet()
{
	if (m_pPayload != NULL) {
		m_pPayload->ReleaseRef();
	}
}

bool Packet::SetPayload(Buffer *pPayload)
{
	m_pPayload = pPayload;
	m_usSize += (unsigned short)pPayload->GetContentSize();
	return m_usSize <= 0x1000;
}

Buffer *Packet::GetPayload()
{
	return m_pPayload;
}

unsigned long Packet::GetHeader(void **ppHeader)
{
	*ppHeader = &m_ucTypeFlags;
	return 8;
}

bool Packet::Valid()
{
	return m_usSize < 0x1000;
}

void Packet::SetSeqId(unsigned long ulSeqId)
{
	m_ulSeqId = ulSeqId;
}

unsigned long Packet::GetSeqId()
{
	return m_ulSeqId;
}

PRUDPInetAddress *Packet::GetPeerAddress()
{
	return &m_peerAddress;
}

void Packet::SetPeerAddress(PRUDPInetAddress *pAddress)
{
	m_peerAddress = *pAddress;
}

void Packet::SetType(unsigned char ucType)
{
	m_ucTypeFlags = ucType & 0x07;
}

unsigned char Packet::GetType()
{
	return m_ucTypeFlags & 0x07;
}

void Packet::SetContextInfo(unsigned char ucContextInfo)
{
	m_ucContextInfo = ucContextInfo;
}

unsigned char Packet::GetContextInfo()
{
	return m_ucContextInfo;
}

void Packet::SetFlag(unsigned char ucFlag)
{
	m_ucTypeFlags = m_ucTypeFlags | (ucFlag & 0xF8);
}

void Packet::ClearFlag(unsigned char ucFlag)
{
	m_ucTypeFlags = m_ucTypeFlags & ~(ucFlag & 0xF8);
}

bool Packet::FlagSet(unsigned char ucFlag)
{
	return (m_ucTypeFlags & ucFlag) != 0;
}

unsigned short Packet::GetSize()
{
	return m_usSize;
}

void Packet::SetIOTime(Time tTime)
{
	m_tIOTime = tTime;
}

Time Packet::GetIOTime()
{
	return m_tIOTime;
}

void Packet::SetIOResult(unsigned long ulResult)
{
	m_ulIOResult = ulResult;
}

unsigned long Packet::GetIOResult()
{
	return m_ulIOResult;
}

void Packet::Trace()
{
	TRACE(D_TRACE_DEBUG, _T("{%x, %d}"), m_ucTypeFlags, m_ulSeqId);
}
