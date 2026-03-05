#ifndef _Socket_H_
#define _Socket_H_

#include <Plugins/Core/Buffer.h>
#include "AsyncIOContext.h"
#include "PRUDPInetAddress.h"

class Socket {
public:

	Socket(unsigned long ulType);
	~Socket();

	bool Open();
	bool Bind(PRUDPInetAddress *pAddress);
	PRUDPInetAddress *GetAddress();
	void Shutdown(unsigned long ulHow);
	void Close();

	int Send(Buffer *pBuffer, PRUDPInetAddress *pAddress, unsigned long *pulBytesSent, AsyncIOContext *pContext);
	int Recv(Buffer *pBuffer, PRUDPInetAddress *pAddress, unsigned long *pulBytesRecv, AsyncIOContext *pContext);
	void TryIOCompletion(AsyncIOContext *pContext);
	bool WaitForIOCompletion(AsyncIOContext *pContext, unsigned long ulTimeout, unsigned long *pulResult);
	unsigned long GetIOResult(AsyncIOContext *pContext, unsigned long *pulBytesTransferred);

	bool SetAsync(bool bAsync);
	bool SetNoDelay(bool bNoDelay);
	bool SetBuffers();
	bool ReuseAddress(bool bReuse);
	bool SetDebugMode(bool bDebug);
	bool SetBroadcastMode(bool bBroadcast);

	static unsigned long GetLastSocketError();
	unsigned short GetBoundPort();

};

#endif
