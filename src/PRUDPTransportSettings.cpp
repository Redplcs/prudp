#include "PRUDPTransportSettings.h"

PRUDPTransportSettings::PRUDPTransportSettings()
{
	SetDefaults();
}

void PRUDPTransportSettings::SetDefaults()
{
	m_ulWellKnownPortNumber = 0x238F;
	m_ulMaxRetransmission = 0x14;
	m_bTrapICMP = true;
	m_ulMaxSilenceTime = 0x1388;
	m_ulKeepAliveTimeout = 0x3E8;
	m_ulTimeSlice = 0x0A;
	m_ulWindowSize = 0x08;
	m_ulMTU = 0xFA0;
}

unsigned long PRUDPTransportSettings::SetWindowSize(unsigned long ulWindowSize)
{
	m_ulWindowSize = ulWindowSize;
	return 0;
}

unsigned long PRUDPTransportSettings::GetWindowSize()
{
	return m_ulWindowSize;
}

unsigned long PRUDPTransportSettings::SetWellKnownPortNumber(unsigned long ulPortNumber)
{
	m_ulWellKnownPortNumber = ulPortNumber;
	return 0;
}

unsigned long PRUDPTransportSettings::GetWellKnownPortNumber()
{
	return m_ulWellKnownPortNumber;
}

unsigned long PRUDPTransportSettings::SetMTU(unsigned long ulMTU)
{
	m_ulMTU = ulMTU;
	return 0;
}

unsigned long PRUDPTransportSettings::GetMTU()
{
	return m_ulMTU;
}

unsigned long PRUDPTransportSettings::SetMaxRetransmission(unsigned long ulMaxRetransmission)
{
	m_ulMaxRetransmission = ulMaxRetransmission;
	return 0;
}

unsigned long PRUDPTransportSettings::GetMaxRetransmission()
{
	return m_ulMaxRetransmission;
}

unsigned long PRUDPTransportSettings::TrapICMP(bool bTrap)
{
	m_bTrapICMP = bTrap;
	return 0;
}

bool PRUDPTransportSettings::IsTrappingICMP()
{
	return m_bTrapICMP;
}

unsigned long PRUDPTransportSettings::SetKeepAliveTimeout(unsigned long ulTimeout)
{
	m_ulKeepAliveTimeout = ulTimeout;
	return 0;
}

unsigned long PRUDPTransportSettings::GetKeepAliveTimeout()
{
	return m_ulKeepAliveTimeout;
}

unsigned long PRUDPTransportSettings::SetMaxSilenceTime(unsigned long ulMaxSilenceTime)
{
	m_ulMaxSilenceTime = ulMaxSilenceTime;
	return 0;
}

unsigned long PRUDPTransportSettings::GetMaxSilenceTime()
{
	return m_ulMaxSilenceTime;
}

bool PRUDPTransportSettings::IsBroadcastingEverywhere()
{
	return m_bBroadcastEverywhere;
}

unsigned long PRUDPTransportSettings::BroadcastEverywhere(bool bEverywhere)
{
	m_bBroadcastEverywhere = true;
	return 0;
}

unsigned long PRUDPTransportSettings::GetTimeSlice()
{
	return m_ulTimeSlice;
}

unsigned long PRUDPTransportSettings::SetTimeSlice(unsigned long ulTimeSlice)
{
	m_ulTimeSlice = ulTimeSlice;
	return 0;
}

unsigned long PRUDPTransportSettings::SetOption(unsigned long ulOption, UserContext &refContext)
{
	switch (ulOption)
	{
	case 2:
		return SetWellKnownPortNumber(refContext.GetULongValue());
	case 1:
		return SetMTU(refContext.GetULongValue());
	case 0x100:
		return BroadcastEverywhere(refContext.GetBoolValue());
	case 0x101:
		return SetMaxRetransmission(refContext.GetULongValue());
	case 0x102:
		return TrapICMP(refContext.GetBoolValue());
	case 0x103:
		return SetMaxSilenceTime(refContext.GetULongValue());
	case 0x104:
		return SetKeepAliveTimeout(refContext.GetULongValue());
	case 0x105:
		return SetTimeSlice(refContext.GetULongValue());
	case 0x106:
		return SetWindowSize(refContext.GetULongValue());
	default:
		return 1;
	}
}

unsigned long PRUDPTransportSettings::GetOption(unsigned long ulOption, UserContext &refContext)
{
	switch (ulOption)
	{
	case 2:
		refContext = GetWellKnownPortNumber();
		return 0;
	case 1:
		refContext = GetMTU();
		return 0;
	case 0x100:
		refContext = IsBroadcastingEverywhere();
		return 0;
	case 0x101:
		refContext = GetMaxRetransmission();
		return 0;
	case 0x102:
		refContext = IsTrappingICMP();
		return 0;
	case 0x103:
		refContext = GetMaxSilenceTime();
		return 0;
	case 0x104:
		refContext = GetKeepAliveTimeout();
		return 0;
	case 0x105:
		refContext = GetTimeSlice();
		return 0;
	case 0x106:
		refContext = GetWindowSize();
		return 0;
	default:
		return 1;
	}
}
