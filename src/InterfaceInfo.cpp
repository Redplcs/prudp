#include "InterfaceInfo.h"

#include <Platform/SystemCheck.h>
#include <Platform/StringConversion.h>
#include <Platform/Trace.h>
#include <winsock2.h>
#include <tchar.h>

InterfaceInfo::InterfaceInfo()
{
	m_ulAddress = 0;
	m_ulBroadcastAddress = 0;
	m_ulMask = 0;
	m_ulFlags = 0;
	m_szName = NULL;
}

InterfaceInfo::~InterfaceInfo()
{
	if (m_szName != NULL) {
		delete m_szName;
		m_szName = NULL;
	}
}

void InterfaceInfo::SetAddress(unsigned long ulAddress)
{
	m_ulAddress = ulAddress;
}

void InterfaceInfo::SetBroadcastAddress(unsigned long ulBroadcastAddress)
{
	m_ulBroadcastAddress = ulBroadcastAddress;
}

void InterfaceInfo::SetMask(unsigned long ulMask)
{
	m_ulMask = ulMask;
}

void InterfaceInfo::SetFlags(unsigned long ulFlags)
{
	m_ulFlags = ulFlags;
}

void InterfaceInfo::SetName(TCHAR *szName)
{
	SYSTEMCHECK(szName != NULL);

	unsigned long ulLen = _tcslen(szName) + 1;
	m_szName = new TCHAR[ulLen];
	memcpy(m_szName, szName, ulLen * sizeof(TCHAR));
}

bool InterfaceInfo::Addr2Str(unsigned long ulAddr, TCHAR *szBuffer, unsigned long ulSize)
{
	char *pStr = inet_ntoa(*(struct in_addr *)&ulAddr);

	unsigned long ulLen = strlen(pStr);
	if (ulSize > ulLen) {
		StringConversion::A2T(pStr, szBuffer, ulSize);
		return true;
	}

	return false;
}

bool InterfaceInfo::GetAddress(TCHAR *szBuffer, unsigned long ulSize)
{
	return Addr2Str(m_ulAddress, szBuffer, ulSize);
}

bool InterfaceInfo::GetBroadcastAddress(TCHAR *szBuffer, unsigned long ulSize)
{
	return Addr2Str(m_ulBroadcastAddress, szBuffer, ulSize);
}

bool InterfaceInfo::GetMask(TCHAR *szBuffer, unsigned long ulSize)
{
	return Addr2Str(m_ulMask, szBuffer, ulSize);
}

bool InterfaceInfo::GetName(TCHAR *szBuffer, unsigned long ulSize)
{
	if (m_szName == NULL) {
		return false;
	}

	_tcsncpy(szBuffer, m_szName, ulSize);
	return true;
}

bool InterfaceInfo::GetFlags(TCHAR *szBuffer, unsigned long ulSize)
{
	TCHAR szTemp[0x200];
	szTemp[0] = _T('\0');
	memset(szTemp + 1, 0, sizeof(szTemp) - 1);

	unsigned long ulFlags = m_ulFlags;

	if (ulFlags & 0x1) {
		_tcscat(szTemp, _T("POINT2POINT"));
	}

	if (ulFlags & 0x4) {
		_tcscat(szTemp, _T("LOOPBACK "));
	}

	if (ulFlags & 0x2) {
		_tcscat(szTemp, _T("BROADCAST "));
	}

	_tcsncpy(szBuffer, szTemp, ulSize);
	return true;
}

unsigned long InterfaceInfo::GetAddress()
{
	return m_ulAddress;
}

unsigned long InterfaceInfo::GetBroadcastAddress()
{
	return m_ulBroadcastAddress;
}

unsigned long InterfaceInfo::GetMask()
{
	return m_ulMask;
}

unsigned long InterfaceInfo::GetFlags()
{
	return m_ulFlags;
}

TCHAR *InterfaceInfo::GetName()
{
	return m_szName;
}

void InterfaceInfo::Trace(unsigned long ulLevel)
{
	TCHAR szBuffer[0x80];

	TRACE(ulLevel, _T("Interface Info:"));

	if (GetName(szBuffer, 0x80)) {
		TRACE(ulLevel, _T("\tName            : %s"), szBuffer);
	}

	if (GetAddress(szBuffer, 0x80)) {
		TRACE(ulLevel, _T("\tAddress         : %s"), szBuffer);
	}

	if (GetBroadcastAddress(szBuffer, 0x80)) {
		TRACE(ulLevel, _T("\tBroadcastAddress: %s"), szBuffer);
	}

	if (GetMask(szBuffer, 0x80)) {
		TRACE(ulLevel, _T("\tSubnet Mask     : %s"), szBuffer);
	}

	if (GetFlags(szBuffer, 0x80)) {
		TRACE(ulLevel, _T("\tFlags           : %s"), szBuffer);
	}
}
