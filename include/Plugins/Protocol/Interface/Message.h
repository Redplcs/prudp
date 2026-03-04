//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Message_H_
#define _Message_H_

#include <Platform/Time.h>
#include <Platform/UserContext.h>
class Buffer;

class Message {

friend class Protocol;

public:
	Message();
	Message(Buffer *pBuffer);
	~Message();

	void SetToBegining();
	Buffer *GetBuffer();
	void SetIOTime(Time &oIOTime);
	Time GetIOTime();
	unsigned long GetLastError();
	void SetSize();
	unsigned long GetSize();
	unsigned long GetContentSize();
	bool IsValid();

	void AddData(bool *pbPart, unsigned long ulSize = 1);
	void AddData(unsigned char *bPart, unsigned long ulSize = 1);
	void AddData(char *pcPart, unsigned long ulSize = 1);
	void AddData(unsigned short *pusPart, unsigned long ulSize = 1);
	void AddData(short *pusPart, unsigned long ulSize = 1);
	void AddData(unsigned int *piPart, unsigned long ulSize = 1);
	void AddData(int *piPart, unsigned long ulSize = 1);
	void AddData(unsigned long *pulPart, unsigned long ulSize = 1);
	void AddData(long *pulPart, unsigned long ulSize = 1);
	void AddData(double *pdPart, unsigned long ulSize = 1);
	void AddData(float *pdPart, unsigned long ulSize = 1);
	void AddData(_LONGLONG *pllPart, unsigned long ulSize = 1);
	void AddData(_ULONGLONG *pullPart, unsigned long ulSize = 1);
	void AddData(void *pvBuffer, unsigned long ulSize);
	void AddDataString(TCHAR *strBuffer);
	void AddDataString(TCHAR *strBuffer, unsigned long ulMaxSize);
    void AddDataFromMessage(const Message &refMessage);

	Message& operator<<(const bool bPart);
	Message& operator<<(const unsigned char bPart);
	Message& operator<<(const char pcPart);
	Message& operator<<(const unsigned short pusPart);
	Message& operator<<(const short pusPart);
	Message& operator<<(const unsigned int piPart);
	Message& operator<<(const int ptPart);
	Message& operator<<(const unsigned long pulPart);
	Message& operator<<(const long pulPart);
	Message& operator<<(const double pdPart);
	Message& operator<<(const float pfPart);
	Message& operator<<(const _LONGLONG pllPart);
	Message& operator<<(const _ULONGLONG pui64Part);
	Message& operator<<(const Time ptPart);
	Message& operator<<(const Message &refMessage);

	Message& operator>>(bool &bPart);
	Message& operator>>(unsigned char &bPart);
	Message& operator>>(char &pcPart);
	Message& operator>>(unsigned short &pusPart);
	Message& operator>>(short &pusPart);
	Message& operator>>(unsigned int &piPart);
	Message& operator>>(int &piPart);
	Message& operator>>(unsigned long &pulPart);
	Message& operator>>(long &pulPart);
	Message& operator>>(double &pdPart);
	Message& operator>>(float &pfPart);
	Message& operator>>(_LONGLONG &pllPart);
	Message& operator>>(_ULONGLONG &pui64Part);
	Message& operator>>(Time &ptPart);
	Message& operator>>(Message &refMessage);

	void Extract(bool *pbPart, unsigned long ulSize = 1);
	void Extract(unsigned char *bPart, unsigned long ulSize = 1);
	void Extract(char *pcPart, unsigned long ulSize = 1);
	void Extract(unsigned short *pusPart, unsigned long ulSize = 1);
	void Extract(short *pusPart, unsigned long ulSize = 1);
	void Extract(unsigned int *piPart, unsigned long ulSize = 1);
	void Extract(int *piPart, unsigned long ulSize = 1);
	void Extract(unsigned long *pulPart, unsigned long ulSize = 1);
	void Extract(long *pulPart, unsigned long ulSize = 1);
	void Extract(double *pdPart, unsigned long ulSize = 1);
	void Extract(float *pdPart, unsigned long ulSize = 1);
	void Extract(_LONGLONG *pllPart, unsigned long ulSize = 1);
	void Extract(_ULONGLONG* pui64Part, unsigned long ulSize = 1);
	void Extract(Time* ptPart, unsigned long ulSize = 1);
	void Extract(void *pvPart, unsigned long ulSize);
	void ExtractString(TCHAR *strBuffer);

#ifdef _TEST_ENABLED
	static bool Test();
#endif

	void			SetUserContext(const UserContext& oContext);
	const UserContext&	GetUserContext() const;

private:
	
	Buffer		    *m_pBuffer;
	unsigned long	m_ulCurrentOffset;
	Time		    m_oIOTime;
	unsigned long	m_ulLastError;
	bool			m_bIncoming;
	UserContext		m_oContext;
};


#endif
