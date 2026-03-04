//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InetAddress_H_
#define _InetAddress_H_

#include <Platform/PlatformDecl.h>

struct sockaddr;

class InetAddress {
	class ImplAttributes;
public:
	InetAddress(); 
	~InetAddress(); 
	InetAddress(InetAddress *pInetAddress);
	InetAddress(InetAddress &oInetAddress);
//	InetAddress(TCHAR *szMachine, unsigned short usPort, unsigned long fne);
	InetAddress(unsigned long ulAddress, unsigned short usPort);

	unsigned long GetAddress();
	void SetPortNumber(unsigned short usPort);
	unsigned short GetPort();
	bool SetAddress(TCHAR *szMachine);
	void SetAddress(unsigned long ulAddress);

	struct sockaddr *GetSockAddr();
	void Trace(unsigned long ulTraceFlag);
	void ToStr(TCHAR *tszStr);

	bool operator==(InetAddress oInetAddress) const;
	InetAddress &operator=(InetAddress &oInetAddress) ;
	bool operator<(InetAddress oInetAddress) const;

	_LONGLONG GetKey();
	static unsigned long GetLocalAddress();

private:
	void SetAddress(void *iaAddress);
	ImplAttributes	*m_pImplAttributes;
};


#endif
