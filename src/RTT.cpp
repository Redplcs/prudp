#include "RTT.h"

#include <Platform/Trace.h>

RTT::RTT()
{
	m_ulSmoothedAvg = 0x7d0;
	m_ulSmoothedDev = 0;
	m_ulLastRTT = 0xfa;
}

RTT::~RTT()
{
}

void RTT::Adjust(unsigned long ulRTT)
{
	if (m_ulLastRTT == (unsigned long)-1) {
		m_ulLastRTT = ulRTT;
		m_ulSmoothedAvg = ulRTT * 8;
		return;
	}

	long lErr = (long)(ulRTT - (m_ulSmoothedAvg >> 3));
	m_ulSmoothedAvg += lErr;

	if (lErr < 0)
		lErr = -lErr;

	m_ulLastRTT = ulRTT;
	m_ulSmoothedDev = m_ulSmoothedDev - (m_ulSmoothedDev >> 2) + lErr;
}

unsigned long RTT::GetRTO()
{
	unsigned long ulDev = GetRTTSmoothedDev();
	unsigned long ulAvg = GetRTTSmoothedAvg();

	return ulAvg + ulDev * 4;
}

unsigned long RTT::GetRTTSmoothedAvg()
{
	return m_ulSmoothedAvg >> 3;
}

unsigned long RTT::GetRTTSmoothedDev()
{
	return m_ulSmoothedDev >> 2;
}

unsigned long RTT::GetLastRTT()
{
	if (m_ulLastRTT != (unsigned long)-1)
		return m_ulLastRTT;

	return 0x7d0;
}

void RTT::Trace(unsigned long ulLevel)
{
	TRACE(ulLevel,
		_T("LastRTT = %dms, RTTSmoothedAvg = %dms, RTTSmoothedDev = %dms"),
		m_ulLastRTT, m_ulSmoothedAvg >> 3, m_ulSmoothedDev >> 3);
}
