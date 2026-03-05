#include "UDPSocket.h"

#include <Platform/ScopedCS.h>
#include <Platform/SystemCheck.h>
#include <Platform/SystemError.h>
#include <Platform/Time.h>
#include <Plugins/Core/RefCountedObject.h>
#include <Plugins/Transport/Interface/EmulationDevice.h>
#include <Plugins/Transport/Interface/InputEmulationDevice.h>
#include <Plugins/Transport/Interface/OutputEmulationDevice.h>
#include <Plugins/Transport/Interface/TransportPerfCounters.h>
#include "PRUDPDeviceData.h"

#define UDPSOCKET_BUFFER_SIZE 0x1000

struct UDPSocket::IOContext {
	UDPSocket *m_pSocket;
	Buffer *m_pBuffer;
	unsigned long m_ulBytesTransferred;
	PRUDPInetAddress m_address;
	AsyncIOContext m_oAsyncIOContext;
};

static bool DeliverToSend(DeviceData *pDeviceData);
static bool DeliverToApp(DeviceData *pDeviceData);

UDPSocket::UDPSocket(PRUDPTransport *pTransport)
	: Socket(0x11)
{
	m_pRecvIOContext = new IOContext;
	m_pRecvIOContext->m_pSocket = this;
	m_pRecvIOContext->m_pBuffer = NULL;
	m_pRecvIOContext->m_ulBytesTransferred = 0;

	m_pSendIOContext = new IOContext;
	m_pSendIOContext->m_pSocket = this;
	m_pSendIOContext->m_pBuffer = NULL;
	m_pSendIOContext->m_ulBytesTransferred = 0;

	m_pTransport = pTransport;
	m_bSendPending = false;
	m_bRecvPending = false;
	m_pRecvPacket = NULL;
}

UDPSocket::~UDPSocket()
{
	Close();
	CompleteRecv();
	CompleteSend();

	if (m_pRecvIOContext != NULL) {
		delete m_pRecvIOContext;
	}

	if (m_pSendIOContext != NULL) {
		delete m_pSendIOContext;
	}

	if (m_pRecvPacket != NULL) {
		m_pRecvPacket->ReleaseRef();
	}
}

void UDPSocket::SetCompletionEvents(Event *pRecvEvent, Event *pSendEvent)
{
	m_pRecvIOContext->m_oAsyncIOContext.SetEvent(pRecvEvent);
	m_pSendIOContext->m_oAsyncIOContext.SetEvent(pSendEvent);
}

bool UDPSocket::Bind(PRUDPInetAddress *pAddress, unsigned short *pusPort)
{
	if (!SetBuffers()) {
		return false;
	}
	SetAsync(true);
	if (!Socket::Bind(pAddress)) {
		return false;
	}
	*pusPort = pAddress->GetPort();
	return true;
}

void UDPSocket::Queue(PacketOut *pPacket)
{
	pPacket->SetIOTime(Time::GetTime());

	PRUDPDeviceData *pDeviceData = new PRUDPDeviceData(pPacket, this, DeliverToSend);

	if (!pPacket->FlagSet(0x80)) {
		OutputEmulationDevice *pDevice = m_pTransport->GetOutputEmulationDevice();
		pDevice->Queue(pDeviceData);
		pDevice = m_pTransport->GetOutputEmulationDevice();
		pDevice->DeliverData();
		pDeviceData->ReleaseRef();
	}
}

bool UDPSocket::Send(PacketOut *pPacket)
{
	{
		ScopedCS lock(m_sendCS);
		if (m_bSendPending) {
			return false;
		}
		m_bSendPending = true;
	}

	m_pSendIOContext->m_pBuffer = new Buffer(UDPSOCKET_BUFFER_SIZE);
	pPacket->Pack(m_pSendIOContext->m_pBuffer);

	PRUDPInetAddress *pPeerAddr = pPacket->GetPeerAddress();
	m_pSendIOContext->m_address = *pPeerAddr;
	m_pSendIOContext->m_ulBytesTransferred = 0;

	Event *pEvent = m_pSendIOContext->m_oAsyncIOContext.GetEvent();
	pEvent->Reset();

	pPeerAddr = pPacket->GetPeerAddress();
	m_pTransport->TraceProto(_T("->"), pPacket, GetAddress(), pPeerAddr, 0x8000000);

	int iResult = Socket::Send(m_pSendIOContext->m_pBuffer, &m_pSendIOContext->m_address,
		&m_pSendIOContext->m_ulBytesTransferred, &m_pSendIOContext->m_oAsyncIOContext);

	if (iResult == -1) {
		pEvent = m_pSendIOContext->m_oAsyncIOContext.GetEvent();
		pEvent->Set();
	}

	return true;
}

unsigned long UDPSocket::CompleteSend()
{
	unsigned long ulTransferred = 0;
	Buffer *pBuffer = m_pSendIOContext->m_pBuffer;
	m_pSendIOContext->m_pBuffer = NULL;

	if (pBuffer != NULL) {
		unsigned long ulResult = GetIOResult(&m_pSendIOContext->m_oAsyncIOContext, &ulTransferred);
		if (ulResult == 0) {
			SYSTEMCHECK(ulTransferred == pBuffer->GetContentSize());
		}

		TransportPerfCounters *pCounters = m_pTransport->GetPerfCounters();
		pCounters->Inc(PERF_TRANSPORT_BPS_SENT, ulTransferred * 8);

		pCounters = m_pTransport->GetPerfCounters();
		pCounters->Inc(PERF_TRANSPORT_PACKETS_SENT, 1);

		pBuffer->ReleaseRef();
		m_bSendPending = false;

		if (m_eState == OPEN || m_eState == BOUND) {
			OutputEmulationDevice *pDevice = m_pTransport->GetOutputEmulationDevice();
			pDevice->DeliverData();
		}
	}

	return ulTransferred;
}

void UDPSocket::Listen()
{
	ScopedCS lock(m_recvCS);

	SYSTEMCHECK(m_pRecvIOContext->m_oAsyncIOContext.GetEvent() != NULL);
	SYSTEMCHECK(!m_bRecvPending);

	m_bRecvPending = true;

	m_pRecvIOContext->m_pBuffer = new Buffer(UDPSOCKET_BUFFER_SIZE);
	m_pRecvIOContext->m_ulBytesTransferred = 0;

	Event *pEvent = m_pRecvIOContext->m_oAsyncIOContext.GetEvent();
	pEvent->Reset();

	int iResult = Socket::Recv(m_pRecvIOContext->m_pBuffer, &m_pRecvIOContext->m_address,
		&m_pRecvIOContext->m_ulBytesTransferred, &m_pRecvIOContext->m_oAsyncIOContext);

	if (iResult == -1) {
		pEvent = m_pRecvIOContext->m_oAsyncIOContext.GetEvent();
		pEvent->Set();
	}
}

void UDPSocket::TryIOCompletion()
{
	if (m_bSendPending) {
		Socket::TryIOCompletion(&m_pSendIOContext->m_oAsyncIOContext);
	}
	if (m_bRecvPending) {
		Socket::TryIOCompletion(&m_pRecvIOContext->m_oAsyncIOContext);
	}
}

PacketIn *UDPSocket::Recv()
{
	ScopedCS lock(m_recvCS);

	InputEmulationDevice *pDevice = m_pTransport->GetInputEmulationDevice();
	pDevice->DeliverData();

	PacketIn *pPacket = m_pRecvPacket;
	m_pRecvPacket = NULL;
	return pPacket;
}

unsigned long UDPSocket::CompleteRecv()
{
	ScopedCS lock(m_recvCS);

	unsigned long ulTransferred = 0;
	Buffer *pBuffer = m_pRecvIOContext->m_pBuffer;
	m_pRecvIOContext->m_pBuffer = NULL;

	if (pBuffer != NULL) {
		unsigned long ulResult = GetIOResult(&m_pRecvIOContext->m_oAsyncIOContext, &ulTransferred);
		if (ulResult == 0) {
			pBuffer->SetContentSize(ulTransferred);
		}

		m_bRecvPending = false;

		if (m_eState == OPEN || m_eState == BOUND) {
			if (ulResult == 0 && ulTransferred != 0) {
				PacketIn *pPacketIn = new PacketIn;

				if (pPacketIn->Unpack(pBuffer)) {
					pPacketIn->SetPeerAddress(&m_pRecvIOContext->m_address);

					PRUDPDeviceData *pDeviceData = new PRUDPDeviceData(pPacketIn, this, DeliverToApp);

					InputEmulationDevice *pDevice = m_pTransport->GetInputEmulationDevice();
					pDevice->Queue(pDeviceData);
					pDevice = m_pTransport->GetInputEmulationDevice();
					pDevice->DeliverData();
					pDeviceData->ReleaseRef();
				} else {
					pPacketIn->ReleaseRef();
					SystemError::TraceLast(0);
				}
			}
			Listen();
		}

		pBuffer->ReleaseRef();
	}

	return ulTransferred;
}

unsigned long UDPSocket::QueueSize()
{
	return 0;
}

bool UDPSocket::InputFlooded()
{
	return false;
}

bool UDPSocket::OutputFlooded()
{
	return false;
}

static bool DeliverToSend(DeviceData *pDeviceData)
{
	PRUDPDeviceData *pData = (PRUDPDeviceData *)pDeviceData;
	return pData->m_pSocket->Send((PacketOut *)pData->m_pPacket);
}

static bool DeliverToApp(DeviceData *pDeviceData)
{
	PRUDPDeviceData *pData = (PRUDPDeviceData *)pDeviceData;
	UDPSocket *pSocket = pData->m_pSocket;

	ScopedCS lock(pSocket->m_recvCS);

	if (pSocket->m_pRecvPacket == NULL) {
		pSocket->m_pRecvPacket = (PacketIn *)pData->m_pPacket;
		pSocket->m_pRecvPacket->SetIOTime(Time::GetTime());

		TransportPerfCounters *pCounters = pSocket->m_pTransport->GetPerfCounters();
		pCounters->Inc(PERF_TRANSPORT_BPS_RECV, pSocket->m_pRecvPacket->GetSize() * 8);

		pCounters = pSocket->m_pTransport->GetPerfCounters();
		pCounters->Inc(PERF_TRANSPORT_PACKETS_RECV, 1);

		PRUDPInetAddress *pPeerAddr = pSocket->m_pRecvPacket->GetPeerAddress();
		pSocket->m_pTransport->TraceProto(_T("<-"), pSocket->m_pRecvPacket, pSocket->GetAddress(), pPeerAddr, 0x8000000);

		return true;
	}

	return false;
}
