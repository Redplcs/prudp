#include "Timeout.h"

#include <Platform/SystemCheck.h>

Timeout::Timeout()
{
	m_tAwaitedTime = 0;
	m_tExpirationTime = 0;
	m_oRTO = 0;
}

Timeout::~Timeout()
{
}

void Timeout::SetExpirationTime(Time tTime)
{
	m_tExpirationTime = tTime;
}

void Timeout::SetRelativeExpirationTime(long lTime)
{
	SetExpirationTime(Time::GetTime() + lTime);
}

bool Timeout::IsExpired()
{
	if (m_tExpirationTime > Time(0)) {
		if ((_ULONGLONG)m_tExpirationTime < (_ULONGLONG)Time::GetTime()) {
			return true;
		}
	}

	return false;
}

bool Timeout::IsAwaited()
{
	if ((_ULONGLONG)m_tAwaitedTime < (_ULONGLONG)Time::GetTime()) {
		return true;
	}

	return false;
}

void Timeout::SetRTO(unsigned long ulRTO)
{
	m_oRTO = ulRTO;
	SYSTEMCHECK((m_oRTO >= 0) && (m_oRTO < 100000));
}

unsigned long Timeout::GetRTO()
{
	return m_oRTO;
}

void Timeout::Start()
{
	m_tAwaitedTime = Time::GetTime() + (long)m_oRTO;
}

Time Timeout::GetAwaitedTime()
{
	return m_tAwaitedTime;
}

bool Timeout::operator<(Timeout &refTimeout)
{
	if ((_ULONGLONG)m_tAwaitedTime < (_ULONGLONG)refTimeout.m_tAwaitedTime) {
		return true;
	}

	return false;
}
