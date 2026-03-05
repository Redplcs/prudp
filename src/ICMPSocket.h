#ifndef _ICMPSocket_H_
#define _ICMPSocket_H_

#include <Platform/Event.h>
#include <Plugins/Core/Buffer.h>
#include "AsyncIOContext.h"
#include "PRUDPInetAddress.h"
#include "Socket.h"

class ICMPSocket : public Socket {
public:

	ICMPSocket();
	~ICMPSocket();

	void SetCompletionEvent(Event *pEvent);
	bool Bind(PRUDPInetAddress *pAddress);
	void QueueRecv();
	void TryIOCompletion();
	unsigned long GetIOCompletionResult(PRUDPInetAddress *pAddress);

private:

	void TraceICMPErrorPacket(PRUDPInetAddress *pAddress, void *pData, unsigned long ulFlags);

	PRUDPInetAddress m_recvAddress;
	Buffer m_recvBuffer;
	AsyncIOContext *m_pAsyncIOContext;
	unsigned long m_ulBytesRecv;
	bool m_bRecvQueued;

};

#endif
