#ifndef _Packet_H_
#define _Packet_H_

#include <Platform/Time.h>
#include <Plugins/Core/RefCountedObject.h>
#include <Plugins/Core/Buffer.h>
#include "PRUDPInetAddress.h"

class Packet : public RefCountedObject {
public:

	Packet();
	virtual ~Packet();

	Buffer *GetPayload();
	unsigned long GetHeader(void **ppHeader);
	bool Valid();

	void SetSeqId(unsigned long ulSeqId);
	unsigned long GetSeqId();

	PRUDPInetAddress *GetPeerAddress();
	void SetPeerAddress(PRUDPInetAddress *pAddress);

	void SetType(unsigned char ucType);
	unsigned char GetType();

	void SetContextInfo(unsigned char ucContextInfo);
	unsigned char GetContextInfo();

	void SetFlag(unsigned char ucFlag);
	void ClearFlag(unsigned char ucFlag);
	bool FlagSet(unsigned char ucFlag);

	unsigned short GetSize();

	void SetIOTime(Time tTime);
	Time GetIOTime();

	void SetIOResult(unsigned long ulResult);
	unsigned long GetIOResult();

	void Trace();

protected:

	bool SetPayload(Buffer *pPayload);

	unsigned char m_ucTypeFlags;
	unsigned char m_ucContextInfo;
	unsigned short m_usSize;
	unsigned long m_ulSeqId;
	Buffer *m_pPayload;
	PRUDPInetAddress m_peerAddress;
	Time m_tIOTime;
	unsigned long m_ulIOResult;

};

#endif
