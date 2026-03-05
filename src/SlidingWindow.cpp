#include "SlidingWindow.h"

#include <Platform/ScopedCS.h>
#include <Platform/SystemCheck.h>
#include <Platform/Trace.h>

SlidingWindow::SlidingWindow(unsigned short usWindowSize)
{
	m_usWindowSize = usWindowSize;
	m_ulNextSeqId = 1;
	m_ulRightEdge = 1;
	m_ulLeftEdge = 1;
	m_ulDataPending = 0;
}

SlidingWindow::~SlidingWindow()
{
	ScopedCS lock(m_oCS);
	Purge();
}

void SlidingWindow::Purge()
{
	ScopedCS lock(m_oCS);

	std::map<unsigned long, PacketOut*>::iterator it = m_mapPackets.begin();
	while (it != m_mapPackets.end()) {
		PacketOut *pPacket = (*it).second;
		std::map<unsigned long, PacketOut*>::iterator current = it;
		++it;

		TRACE(TRACE_NEVER, _T("Purging PacketOut %d from SlidingWindow"), pPacket->GetSeqId());
		pPacket->ReleaseRef();
		m_mapPackets.erase(current);
	}

	m_ulRightEdge = m_ulNextSeqId;
	m_ulLeftEdge = m_ulNextSeqId;
	m_ulDataPending = 0;
}

void SlidingWindow::Push(PacketOut *pPacket)
{
	ScopedCS lock(m_oCS);

	SYSTEMCHECK(m_ulLeftEdge <= m_ulRightEdge);

	pPacket->AcquireRef();

	if (pPacket->GetType() == 1)
		m_ulDataPending++;

	m_mapPackets[m_ulNextSeqId] = pPacket;
	pPacket->SetSeqId(m_ulNextSeqId);
	m_ulNextSeqId++;
}

void SlidingWindow::Acknowledged(unsigned long ulSeqId)
{
	ScopedCS lock(m_oCS);

	SYSTEMCHECK(m_ulLeftEdge <= m_ulRightEdge);

	std::map<unsigned long, PacketOut*>::iterator it = m_mapPackets.find(ulSeqId);
	if (it == m_mapPackets.end())
		return;

	PacketOut *pPacket = (*it).second;

	if (ulSeqId == m_ulLeftEdge) {
		std::map<unsigned long, PacketOut*>::iterator next = it;
		++next;

		if (next == m_mapPackets.end()) {
			m_ulLeftEdge = m_ulNextSeqId;
			SYSTEMCHECK((m_ulLeftEdge == m_ulRightEdge) && (m_mapPackets.empty() == true));
		} else {
			m_ulLeftEdge = (*next).first;
		}
	}

	m_mapPackets.erase(it);

	if (pPacket->GetType() & 0x1)
		m_ulDataPending--;

	pPacket->ReleaseRef();
}

PacketOut *SlidingWindow::GetNextToSend()
{
	ScopedCS lock(m_oCS);

	SYSTEMCHECK(m_ulLeftEdge <= m_ulRightEdge);

	if ((m_ulRightEdge - m_ulLeftEdge) >= (unsigned long)m_usWindowSize)
		return NULL;

	std::map<unsigned long, PacketOut*>::iterator it = m_mapPackets.find(m_ulRightEdge);
	if (it == m_mapPackets.end())
		return NULL;

	m_ulRightEdge++;

	SYSTEMCHECK((*it).second->Valid() == true);

	return (*it).second;
}

PacketOut *SlidingWindow::GetPacket(unsigned long ulSeqId)
{
	ScopedCS lock(m_oCS);

	SYSTEMCHECK(m_ulLeftEdge <= m_ulRightEdge);

	std::map<unsigned long, PacketOut*>::iterator it = m_mapPackets.find(ulSeqId);
	if (it == m_mapPackets.end())
		return NULL;

	SYSTEMCHECK(ulSeqId == (*it).second->GetSeqId());
	SYSTEMCHECK((*it).second->Valid() == true);

	return (*it).second;
}

bool SlidingWindow::ReadyToSend()
{
	ScopedCS lock(m_oCS);

	if ((m_ulRightEdge - m_ulLeftEdge) >= (unsigned long)m_usWindowSize)
		return false;

	if (m_ulRightEdge == m_ulNextSeqId)
		return false;

	return true;
}

bool SlidingWindow::Empty()
{
	ScopedCS lock(m_oCS);
	return m_ulLeftEdge == m_ulNextSeqId;
}

std::map<unsigned long, PacketOut*>::iterator SlidingWindow::AcquireIterator()
{
	m_oCS.Enter();
	return m_mapPackets.begin();
}

PacketOut *SlidingWindow::GetPacket(std::map<unsigned long, PacketOut*>::iterator it)
{
	if (it == m_mapPackets.end())
		return NULL;

	SYSTEMCHECK((*it).second->Valid() == true);

	return (*it).second;
}

void SlidingWindow::ReleaseIterator()
{
	m_oCS.Leave();
}

bool SlidingWindow::DataPending()
{
	ScopedCS lock(m_oCS);
	return m_ulDataPending > 0;
}

unsigned long SlidingWindow::NbDataPending()
{
	ScopedCS lock(m_oCS);
	return m_ulDataPending;
}

void SlidingWindow::Trace()
{
	std::map<unsigned long, PacketOut*>::iterator it = m_mapPackets.begin();
	while (it != m_mapPackets.end()) {
		(*it).second->Trace();
		++it;
	}
}
