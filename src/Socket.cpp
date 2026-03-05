#include "Socket.h"

#include <Win32.h>
#include <Platform/SystemCheck.h>
#include <Platform/Trace.h>

#define WSA_IO_PENDING   0x3e5
#define WSAENOTCONN      0x2749

struct Socket::SocketData {
	SOCKET m_socket;
	WSABUF m_aSendBufs[2];
	WSABUF m_aRecvBufs[2];
};

Socket::Socket(unsigned long ulType)
{
	m_pSocketData = new SocketData;
	m_pSocketData->m_socket = INVALID_SOCKET;
	m_ulType = ulType;
	m_eState = CLOSE;
}

Socket::~Socket()
{
	Close();
	delete m_pSocketData;
}

bool Socket::Open()
{
	SYSTEMCHECK(m_eState == CLOSE);

	if (m_ulType == 1) {
		m_pSocketData->m_socket = WSASocketA(AF_INET, SOCK_RAW, IPPROTO_ICMP, NULL, 0, WSA_FLAG_OVERLAPPED);
	} else if (m_ulType == 0x11) {
		m_pSocketData->m_socket = WSASocketA(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, WSA_FLAG_OVERLAPPED);
	}

	if (m_pSocketData->m_socket == INVALID_SOCKET) {
		TRACE(TRACE_NEVER, _T("Socket() failed with error %d"), GetLastSocketError());
		return false;
	}

	SetBroadcastMode(true);
	m_eState = OPEN;
	return true;
}

bool Socket::Bind(PRUDPInetAddress *pAddress)
{
	SYSTEMCHECK(m_eState == OPEN);

	sockaddr *pAddr = pAddress->GetSockAddr();
	int iResult = bind(m_pSocketData->m_socket, pAddr, sizeof(sockaddr_in));
	if (iResult == -1) {
		TRACE(TRACE_NEVER, _T("bind() failed with error %d"), GetLastSocketError());
		return false;
	}

	m_eState = BOUND;
	int iAddrLen = sizeof(sockaddr_in);
	sockaddr *pLocalAddr = m_address.GetSockAddr();
	getsockname(m_pSocketData->m_socket, pLocalAddr, &iAddrLen);
	*pAddress = m_address;
	return true;
}

PRUDPInetAddress *Socket::GetAddress()
{
	return &m_address;
}

void Socket::Shutdown(unsigned long ulHow)
{
	if (m_eState == CLOSE) {
		TRACE(TRACE_ALWAYS, _T("Shutting Down a closed socket!!"));
	}

	while (m_eState != SHUTDOWN) {
		int iResult = shutdown(m_pSocketData->m_socket, ulHow);
		if (iResult == -1 && GetLastSocketError() != WSAENOTCONN) {
			TRACE(TRACE_ALWAYS, _T("Shutdown returned error %d"), GetLastSocketError());
			Platform::Sleep(10);
		} else {
			m_eState = SHUTDOWN;
		}
	}
}

void Socket::Close()
{
	if (m_eState != CLOSE) {
		Shutdown(SD_SEND);
		closesocket(m_pSocketData->m_socket);
		m_eState = CLOSE;
	}
}

int Socket::Send(Buffer *pBuffer, PRUDPInetAddress *pAddress, unsigned long *pulBytesSent, AsyncIOContext *pContext)
{
	*pulBytesSent = 0;

	m_pSocketData->m_aSendBufs[0].buf = (char *)pBuffer->GetContentPtr();
	m_pSocketData->m_aSendBufs[0].len = pBuffer->GetContentSize();

	TCHAR szAddr[128];
	pAddress->ToStr(szAddr);
	TRACE(TRACE_NEVER, _T("Sending %d bytes to %s (%x,%x)"),
		pBuffer->GetContentSize(), szAddr,
		*(unsigned long *)pBuffer->GetContentPtr(),
		*(unsigned long *)(pBuffer->GetContentPtr() + 4));

	OVERLAPPED *pOverlapped = pContext->GetOverlapped();
	sockaddr *pAddr = pAddress->GetSockAddr();
	int iResult = WSASendTo(m_pSocketData->m_socket, &m_pSocketData->m_aSendBufs[0], 1,
		pulBytesSent, 0, pAddr, sizeof(sockaddr_in), pOverlapped, NULL);

	if (iResult == -1) {
		unsigned long ulError = GetLastSocketError();
		if (ulError != WSA_IO_PENDING) {
			TRACE(TRACE_ALWAYS, _T("Send error %d on %x"), GetLastSocketError(), this);
			return GetLastSocketError();
		}
	}

	return 0;
}

int Socket::Recv(Buffer *pBuffer, PRUDPInetAddress *pAddress, unsigned long *pulBytesRecv, AsyncIOContext *pContext)
{
	m_iAddrLen = sizeof(sockaddr_in);
	unsigned long ulFlags = 0;
	*pulBytesRecv = 0;

	m_pSocketData->m_aRecvBufs[0].buf = (char *)pBuffer->GetContentPtr();
	m_pSocketData->m_aRecvBufs[0].len = pBuffer->GetSize();

	OVERLAPPED *pOverlapped = pContext->GetOverlapped();
	sockaddr *pAddr = pAddress->GetSockAddr();
	int iResult = WSARecvFrom(m_pSocketData->m_socket, &m_pSocketData->m_aRecvBufs[0], 1,
		pulBytesRecv, &ulFlags, pAddr, &m_iAddrLen, pOverlapped, NULL);

	if (iResult == -1) {
		unsigned long ulError = GetLastSocketError();
		if (ulError != WSA_IO_PENDING) {
			TRACE(D_TRACE_TRANSPORT, _T("Recv error %d on %x"), GetLastSocketError(), this);
			return -1;
		}
	}

	pContext->SetIOSize(*pulBytesRecv);
	return 0;
}

void Socket::TryIOCompletion(AsyncIOContext *pContext)
{
}

bool Socket::WaitForIOCompletion(AsyncIOContext *pContext, unsigned long ulTimeout, unsigned long *pulResult)
{
	unsigned long ulBytesTransferred = 0;

	OVERLAPPED *pOverlapped = pContext->GetOverlapped();
	int iResult = WSAWaitForMultipleEvents(1, (WSAEVENT *)((char *)pOverlapped + 0x10), FALSE, ulTimeout, FALSE);

	if (iResult == WSA_WAIT_EVENT_0) {
		*pulResult = GetIOResult(pContext, &ulBytesTransferred);
		pContext->SetIOSize(ulBytesTransferred);
		pContext->SetReturnCode(*pulResult);
		return true;
	}

	return false;
}

unsigned long Socket::GetIOResult(AsyncIOContext *pContext, unsigned long *pulBytesTransferred)
{
	OVERLAPPED *pOverlapped = pContext->GetOverlapped();
	unsigned long ulFlags = 0;
	int iResult = WSAGetOverlappedResult(m_pSocketData->m_socket, pOverlapped, pulBytesTransferred, FALSE, &ulFlags);

	if (iResult == 0) {
		return GetLastSocketError();
	}

	return 0;
}

bool Socket::SetAsync(bool bAsync)
{
	unsigned long ulMode = (unsigned long)bAsync;
	int iResult = ioctlsocket(m_pSocketData->m_socket, FIONBIO, &ulMode);
	return iResult == 0;
}

bool Socket::SetNoDelay(bool bNoDelay)
{
	int iResult = setsockopt(m_pSocketData->m_socket, IPPROTO_TCP, TCP_NODELAY, (char *)&bNoDelay, sizeof(bool));
	if (iResult == -1) {
		TRACE(TRACE_NEVER, _T("SetNoDelay failed with error %d"), GetLastSocketError());
		return false;
	}
	return true;
}

bool Socket::SetBuffers()
{
	unsigned long ulZero = 0;
	int iResult = setsockopt(m_pSocketData->m_socket, SOL_SOCKET, SO_SNDBUF, (char *)&ulZero, sizeof(unsigned long));
	if (iResult == -1) {
		TRACE(TRACE_NEVER, _T("SetBuffers failed with error %d"), GetLastSocketError());
		return false;
	}
	return true;
}

bool Socket::ReuseAddress(bool bReuse)
{
	int iResult = setsockopt(m_pSocketData->m_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&bReuse, sizeof(bool));
	if (iResult == -1) {
		TRACE(TRACE_NEVER, _T("SetReuse failed with error %d"), GetLastSocketError());
		return false;
	}
	return true;
}

bool Socket::SetDebugMode(bool bDebug)
{
	int iResult = setsockopt(m_pSocketData->m_socket, SOL_SOCKET, SO_DEBUG, (char *)&bDebug, sizeof(bool));
	if (iResult == -1) {
		TRACE(TRACE_NEVER, _T("SetDebug failed with error %d"), GetLastSocketError());
		return false;
	}
	return true;
}

bool Socket::SetBroadcastMode(bool bBroadcast)
{
	unsigned int uiMode = (unsigned int)bBroadcast;
	int iResult = setsockopt(m_pSocketData->m_socket, SOL_SOCKET, SO_BROADCAST, (char *)&uiMode, sizeof(unsigned int));
	return iResult != -1;
}

unsigned long Socket::GetLastSocketError()
{
	return GetLastError();
}

unsigned short Socket::GetBoundPort()
{
	return m_address.GetPort();
}
