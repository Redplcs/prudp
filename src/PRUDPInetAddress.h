#ifndef _PRUDPInetAddress_H_
#define _PRUDPInetAddress_H_

#include <Platform/InetAddress.h>
#include <Plugins/Transport/Interface/StationURL.h>

class PRUDPInetAddress {
public:

	PRUDPInetAddress();
	PRUDPInetAddress(PRUDPInetAddress *pAddress);
	PRUDPInetAddress(PRUDPInetAddress &refAddress);
	PRUDPInetAddress(unsigned long ulAddress, unsigned short usPort);
	~PRUDPInetAddress();

	bool SetFromURL(StationURL *pURL, unsigned short usDefaultPort);
	bool GetURL(StationURL *pURL);
	bool SetAddress(TCHAR *szAddress);
	sockaddr *GetSockAddr();
	void SetAddress(unsigned long ulAddress);
	unsigned long GetAddress();
	void SetPortNumber(unsigned short usPort);
	unsigned short GetPort();
	long long GetKey();

	bool operator<(PRUDPInetAddress oAddress) const;
	bool operator==(PRUDPInetAddress oAddress) const;
	PRUDPInetAddress &operator=(PRUDPInetAddress &refAddress);

	void Trace(unsigned long ulLevel);
	void ToStr(TCHAR *szBuffer);

private:

	void SetAddress(void *pAddress);

	sockaddr *m_pSockAddr;

};

#endif
