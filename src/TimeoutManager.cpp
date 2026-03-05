#include "TimeoutManager.h"

#include <Platform/ScopedCS.h>
#include <Platform/SystemCheck.h>
#include <Platform/Trace.h>

TimeoutManager::TimeoutManager()
{
}

TimeoutManager::~TimeoutManager()
{
	ScopedCS lock(m_oCS);
}

void TimeoutManager::SchedulePacketTimeout(PacketOut *pPacket)
{
	ScopedCS lock(m_oCS);

	SYSTEMCHECK(pPacket != NULL);

	pPacket->GetTimeout()->Start();

	std::list<PacketOut *>::iterator it = m_lstPackets.begin();
	while (it != m_lstPackets.end()) {
		if (!(*(*it)->GetTimeout() < *pPacket->GetTimeout())) {
			break;
		}
		++it;
	}

	pPacket->AcquireRef();
	m_lstPackets.insert(it, pPacket);
}

void TimeoutManager::CancelPacketTimeout(PacketOut *pPacket)
{
	ScopedCS lock(m_oCS);

	TRACE(TRACE_NEVER, _T("Removing timeout of %d"), pPacket->GetSeqId());

	std::list<PacketOut *>::iterator it = m_lstPackets.begin();
	while (it != m_lstPackets.end()) {
		if (*it == pPacket) {
			break;
		}
		++it;
	}

	if (it != m_lstPackets.end()) {
		m_lstPackets.erase(it);
		pPacket->ReleaseRef();
		TRACE(TRACE_NEVER, _T("Removed timeout of %d"), pPacket->GetSeqId());
	}
}

void TimeoutManager::ServicePacketTimeouts()
{
	m_oCS.Enter();

	while (m_lstPackets.size() > 0) {
		PacketOut *pPacket = m_lstPackets.front();

		if (!pPacket->GetTimeout()->IsAwaited()) {
			if (!pPacket->GetTimeout()->IsExpired()) {
				break;
			}
		}

		m_lstPackets.pop_front();

		PRUDPEndPoint *pEndPoint = pPacket->GetEndPoint();

		TRACE(TRACE_NEVER, _T("%d: Servicing timeout of %d"), (unsigned long)Time::GetTime(), pPacket->GetSeqId());

		pEndPoint->ServiceTimeout(pPacket);

		pPacket->ReleaseRef();

		TRACE(TRACE_NEVER, _T("Serviced timeout of %d"), pPacket->GetSeqId());
	}

	m_oCS.Leave();
}
