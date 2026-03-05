#include "PRUDPInetAddress.h"

#include <Platform/SocketSysDefs.h>

#include <stdio.h>
#include <stdlib.h>

PRUDPInetAddress::PRUDPInetAddress()
{
	m_pSockAddr = (sockaddr *)new sockaddr_in;

	((sockaddr_in *)m_pSockAddr)->sin_family = AF_INET;
	((sockaddr_in *)m_pSockAddr)->sin_addr.s_addr = 0;
	((sockaddr_in *)m_pSockAddr)->sin_port = 0;
}

PRUDPInetAddress::PRUDPInetAddress(PRUDPInetAddress *pAddress)
{
	m_pSockAddr = (sockaddr *)new sockaddr_in;

	sockaddr_in *pSrc = (sockaddr_in *)pAddress->m_pSockAddr;
	sockaddr_in *pDst = (sockaddr_in *)m_pSockAddr;

	*(unsigned long *)&pDst->sin_family = *(unsigned long *)&pSrc->sin_family;
	pDst->sin_addr.s_addr = pSrc->sin_addr.s_addr;
	*(unsigned long *)((char *)pDst + 0x8) = *(unsigned long *)((char *)pSrc + 0x8);
	*(unsigned long *)((char *)pDst + 0xc) = *(unsigned long *)((char *)pSrc + 0xc);
}

PRUDPInetAddress::PRUDPInetAddress(PRUDPInetAddress &refAddress)
{
	m_pSockAddr = (sockaddr *)new sockaddr_in;
	*this = refAddress;
}

PRUDPInetAddress::PRUDPInetAddress(unsigned long ulAddress, unsigned short usPort)
{
	m_pSockAddr = (sockaddr *)new sockaddr_in;
	((sockaddr_in *)m_pSockAddr)->sin_family = AF_INET;
	SetAddress(ulAddress);
	SetPortNumber(usPort);
}

PRUDPInetAddress::~PRUDPInetAddress()
{
	delete (sockaddr_in *)m_pSockAddr;
}

bool PRUDPInetAddress::SetFromURL(StationURL *pURL, unsigned short usDefaultPort)
{
	TCHAR szAddress[0x80];
	TCHAR szPort[0x10];

	if (pURL->GetParamValue(_T("address"), szAddress, 0x80))
		return false;

	if (!SetAddress(szAddress))
		return false;

	if (pURL->GetParamValue(_T("port"), szPort, 0x10) == 0)
	{
		SetPortNumber((unsigned short)_ttoi(szPort));
		return true;
	}

	SetPortNumber(usDefaultPort);
	return true;
}

bool PRUDPInetAddress::GetURL(StationURL *pURL)
{
	TCHAR szAddress[0x80];
	TCHAR szPort[0x10];

	char *pAddr = inet_ntoa(((sockaddr_in *)m_pSockAddr)->sin_addr);
	StringConversion::A2T(pAddr, szAddress, 0x80);

	_stprintf(szAddress, _T("%s"), szAddress);

	pURL->AddParam(_T("address"), szAddress);

	unsigned short usPort = ntohs(((sockaddr_in *)m_pSockAddr)->sin_port);
	_stprintf(szPort, _T("%d"), (unsigned long)usPort);

	pURL->AddParam(_T("port"), szPort);

	return true;
}

bool PRUDPInetAddress::SetAddress(TCHAR *szAddress)
{
	char szAnsi[0x100];

	((sockaddr_in *)m_pSockAddr)->sin_family = AF_INET;

	StringConversion::T2A(szAddress, szAnsi, 0x100);

	unsigned long ulAddr = inet_addr(szAnsi);

	if (ulAddr != INADDR_NONE)
	{
		TRACE(0, _T("Address IP %s"), szAddress);
		((sockaddr_in *)m_pSockAddr)->sin_addr.s_addr = ulAddr;
		return true;
	}

	TRACE(0, _T("Address Name %s"), szAddress);

	hostent *pHost = gethostbyname(szAnsi);

	if (pHost == NULL)
	{
		TRACE(0, _T("Could not connect to %s"), szAddress);
		return false;
	}

	SetAddress(pHost->h_addr_list[0]);
	return true;
}

sockaddr *PRUDPInetAddress::GetSockAddr()
{
	return m_pSockAddr;
}

void PRUDPInetAddress::SetAddress(void *pAddress)
{
	((sockaddr_in *)m_pSockAddr)->sin_addr.s_addr = *(unsigned long *)pAddress;
}

void PRUDPInetAddress::SetAddress(unsigned long ulAddress)
{
	((sockaddr_in *)m_pSockAddr)->sin_addr.s_addr = htonl(ulAddress);
}

unsigned long PRUDPInetAddress::GetAddress()
{
	return ntohl(((sockaddr_in *)m_pSockAddr)->sin_addr.s_addr);
}

void PRUDPInetAddress::SetPortNumber(unsigned short usPort)
{
	((sockaddr_in *)m_pSockAddr)->sin_port = htons(usPort);
}

unsigned short PRUDPInetAddress::GetPort()
{
	return ntohs(((sockaddr_in *)m_pSockAddr)->sin_port);
}

long long PRUDPInetAddress::GetKey()
{
	unsigned short usPort = ((sockaddr_in *)m_pSockAddr)->sin_port;
	unsigned long ulAddr = ((sockaddr_in *)m_pSockAddr)->sin_addr.s_addr;

	return (long long)usPort | ((long long)ulAddr << 32);
}

bool PRUDPInetAddress::operator<(PRUDPInetAddress oAddress) const
{
	TRACE(0, _T("Operator < called"));

	sockaddr_in *pThis = (sockaddr_in *)m_pSockAddr;
	sockaddr_in *pOther = (sockaddr_in *)oAddress.m_pSockAddr;

	if (pThis->sin_addr.s_addr > pOther->sin_addr.s_addr)
		return false;

	return pThis->sin_port < pOther->sin_port;
}

bool PRUDPInetAddress::operator==(PRUDPInetAddress oAddress) const
{
	TRACE(0, _T("Operator == called"));

	sockaddr_in *pThis = (sockaddr_in *)m_pSockAddr;
	sockaddr_in *pOther = (sockaddr_in *)oAddress.m_pSockAddr;

	if (pThis->sin_addr.s_addr != pOther->sin_addr.s_addr)
		return false;

	return pThis->sin_port == pOther->sin_port;
}

PRUDPInetAddress &PRUDPInetAddress::operator=(PRUDPInetAddress &refAddress)
{
	TRACE(0, _T("Operator = called (%x,%x)"), this, &refAddress);

	sockaddr_in *pSrc = (sockaddr_in *)refAddress.m_pSockAddr;
	sockaddr_in *pDst = (sockaddr_in *)m_pSockAddr;

	*(unsigned long *)&pDst->sin_family = *(unsigned long *)&pSrc->sin_family;
	pDst->sin_addr.s_addr = pSrc->sin_addr.s_addr;
	*(unsigned long *)((char *)pDst + 0x8) = *(unsigned long *)((char *)pSrc + 0x8);
	*(unsigned long *)((char *)pDst + 0xc) = *(unsigned long *)((char *)pSrc + 0xc);

	return *this;
}

void PRUDPInetAddress::Trace(unsigned long ulLevel)
{
	TCHAR szBuffer[0x80];

	ToStr(szBuffer);
	TRACE(ulLevel, _T("%s"), szBuffer);
}

void PRUDPInetAddress::ToStr(TCHAR *szBuffer)
{
	char *pAddr = inet_ntoa(((sockaddr_in *)m_pSockAddr)->sin_addr);
	StringConversion::A2T(pAddr, szBuffer, 0x80);

	unsigned short usPort = ntohs(((sockaddr_in *)m_pSockAddr)->sin_port);
	_stprintf(szBuffer, _T("%s:%d"), szBuffer, (unsigned long)usPort);
}
