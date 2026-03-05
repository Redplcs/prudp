#ifndef _ICMPSocket_H_
#define _ICMPSocket_H_

#include <Platform/Event.h>
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

};

#endif
