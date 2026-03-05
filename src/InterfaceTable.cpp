#include "InterfaceTable.h"

#include <Platform/SystemCheck.h>
#include <Platform/Trace.h>
#include <winsock2.h>
#include <ws2tcpip.h>

InterfaceTable::InterfaceTable()
{
	m_ulNbInterface = 0;
	m_pInterfaces = NULL;
}

InterfaceTable::~InterfaceTable()
{
	m_ulNbInterface = 0;

	if (m_pInterfaces != NULL) {
		delete[] m_pInterfaces;
	}
}

bool InterfaceTable::Query()
{
	m_ulNbInterface = 0;

	SOCKET sock = WSASocketA(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (sock == INVALID_SOCKET) {
		TRACE(D_TRACE_DEBUG, _T("Error %d opening socket in InterfaceTable::Query()"), WSAGetLastError());
		return false;
	}

	char *pBuffer = new char[0x2f8];
	unsigned long ulBytesReturned;

	int iResult = WSAIoctl(sock, SIO_GET_INTERFACE_LIST, NULL, 0, pBuffer, 0x2f8, &ulBytesReturned, NULL, NULL);
	if (iResult == SOCKET_ERROR) {
		delete pBuffer;
		closesocket(sock);
		TRACE(D_TRACE_DEBUG, _T("Error %d Querying interface list in InterfaceTable::Query()"), WSAGetLastError());
		return false;
	}

	unsigned long ulCount = ulBytesReturned / sizeof(INTERFACE_INFO);
	m_pInterfaces = new InterfaceInfo[ulCount];

	INTERFACE_INFO *pInfo = (INTERFACE_INFO *)pBuffer;
	for (unsigned long i = 0; i < ulCount; i++) {
		if (pInfo[i].iiAddress.AddressIn.sin_addr.s_addr == 0) {
			continue;
		}

		m_pInterfaces[m_ulNbInterface].SetName(_T("Unknown"));
		m_pInterfaces[m_ulNbInterface].SetAddress(pInfo[i].iiAddress.AddressIn.sin_addr.s_addr);
		m_pInterfaces[m_ulNbInterface].SetMask(pInfo[i].iiNetmask.AddressIn.sin_addr.s_addr);

		unsigned long ulBroadcast = (~m_pInterfaces[m_ulNbInterface].GetMask() & ~m_pInterfaces[m_ulNbInterface].GetAddress()) | m_pInterfaces[m_ulNbInterface].GetAddress();
		m_pInterfaces[m_ulNbInterface].SetBroadcastAddress(ulBroadcast);

		unsigned long ulFlags = 0;
		if (pInfo[i].iiFlags & IFF_BROADCAST) {
			ulFlags = 0x2;
		}
		if (pInfo[i].iiFlags & IFF_LOOPBACK) {
			ulFlags |= 0x4;
		}
		if (pInfo[i].iiFlags & IFF_POINTTOPOINT) {
			ulFlags |= 0x1;
		}
		m_pInterfaces[m_ulNbInterface].SetFlags(ulFlags);

		m_ulNbInterface++;
	}

	delete pBuffer;
	closesocket(sock);

	return true;
}

unsigned long InterfaceTable::GetNbInterface()
{
	return m_ulNbInterface;
}

unsigned long InterfaceTable::GetNbLoopbackInterface()
{
	unsigned long ulCount = 0;

	for (unsigned long i = 0; i < m_ulNbInterface; i++) {
		if ((*this)[i].GetFlags() & 0x4) {
			ulCount++;
		}
	}

	return ulCount;
}

InterfaceInfo &InterfaceTable::operator[](unsigned long ulIndex)
{
	SYSTEMCHECK(ulIndex < m_ulNbInterface);
	return m_pInterfaces[ulIndex];
}

void InterfaceTable::Trace(unsigned long ulLevel)
{
	for (unsigned long i = 0; i < GetNbInterface(); i++) {
		m_pInterfaces[i].Trace(ulLevel);
	}
}
