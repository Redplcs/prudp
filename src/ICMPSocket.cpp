#include "ICMPSocket.h"

#include "AsyncIOContext.h"
#include <Plugins/Core/Buffer.h>
#include <Platform/Trace.h>

#define ICMP_RECV_BUFFER_SIZE 0x1000

ICMPSocket::ICMPSocket()
	: Socket(1)
	, m_recvBuffer(ICMP_RECV_BUFFER_SIZE)
{
	m_bRecvQueued = false;
	m_pAsyncIOContext = new AsyncIOContext;
}

ICMPSocket::~ICMPSocket()
{
	Close();
	delete m_pAsyncIOContext;
}

void ICMPSocket::SetCompletionEvent(Event *pEvent)
{
	m_pAsyncIOContext->SetEvent(pEvent);
}

bool ICMPSocket::Bind(PRUDPInetAddress *pAddress)
{
	if (!SetBuffers()) {
		return false;
	}
	SetAsync(true);
	return Socket::Bind(pAddress);
}

void ICMPSocket::QueueRecv()
{
	m_bRecvQueued = true;
	int iResult = Socket::Recv(&m_recvBuffer, &m_recvAddress, &m_ulBytesRecv, m_pAsyncIOContext);
	if (iResult == -1) {
		Event *pEvent = m_pAsyncIOContext->GetEvent();
		pEvent->Set();
	}
}

void ICMPSocket::TryIOCompletion()
{
	if (m_bRecvQueued) {
		Socket::TryIOCompletion(m_pAsyncIOContext);
	}
}

unsigned long ICMPSocket::GetIOCompletionResult(PRUDPInetAddress *pAddress)
{
	unsigned long ulBytesTransferred = 0;
	unsigned long ulResult = GetIOResult(m_pAsyncIOContext, &ulBytesTransferred);

	if (ulResult == 0) {
		m_recvBuffer.SetContentSize(ulBytesTransferred);
		unsigned char *pContent = m_recvBuffer.GetContentPtr();

		// IP header (20 bytes): 0x00–0x13
		// ICMP header: Code at 0x15, Type at 0x14
		if (pContent[0x15] == 0x03) {
			unsigned short usPort = ntohs(*(unsigned short *)(pContent + 0x32));
			unsigned long ulIP = ntohl(*(unsigned long *)(pContent + 0x2C));
			PRUDPInetAddress errorAddr(ulIP, usPort);

			unsigned long ulFlags;
			if (pContent[0x14] == 0x03) {
				ulFlags = 0x20;
			} else {
				ulFlags = 0x8000000;
			}

			TraceICMPErrorPacket(&errorAddr, pContent, ulFlags);
			*pAddress = errorAddr;
		}
	} else {
		TRACE(TRACE_ALWAYS, _T("Error is %d"), ulResult);
	}

	m_bRecvQueued = false;
	return ulResult;
}

void ICMPSocket::TraceICMPErrorPacket(PRUDPInetAddress *pAddress, void *pData, unsigned long ulFlags)
{
}
