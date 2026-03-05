#ifndef _InterfaceInfo_H_
#define _InterfaceInfo_H_

#include <Platform/PlatformDecl.h>

class InterfaceInfo {
public:

	InterfaceInfo();
	~InterfaceInfo();

	void SetAddress(unsigned long ulAddress);
	void SetBroadcastAddress(unsigned long ulBroadcastAddress);
	void SetMask(unsigned long ulMask);
	void SetFlags(unsigned long ulFlags);
	void SetName(TCHAR *szName);

	bool GetAddress(TCHAR *szBuffer, unsigned long ulSize);
	bool GetBroadcastAddress(TCHAR *szBuffer, unsigned long ulSize);
	bool GetMask(TCHAR *szBuffer, unsigned long ulSize);
	bool GetName(TCHAR *szBuffer, unsigned long ulSize);
	bool GetFlags(TCHAR *szBuffer, unsigned long ulSize);

	unsigned long GetAddress();
	unsigned long GetBroadcastAddress();
	unsigned long GetMask();
	unsigned long GetFlags();
	TCHAR *GetName();

	void Trace(unsigned long ulLevel);

private:

	bool Addr2Str(unsigned long ulAddr, TCHAR *szBuffer, unsigned long ulSize);

	unsigned long m_ulAddress;
	unsigned long m_ulBroadcastAddress;
	unsigned long m_ulMask;
	unsigned long m_ulFlags;
	TCHAR *m_szName;

};

#endif
