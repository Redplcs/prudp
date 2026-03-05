#include "PacketIn.h"

PacketIn::PacketIn()
{
	SetPayload(new Buffer);
}

PacketIn::~PacketIn()
{
}

bool PacketIn::Unpack(Buffer *pBuffer)
{
	unsigned long ulContentSize = pBuffer->GetContentSize();
	if (ulContentSize == 0) {
		return false;
	}

	if (!pBuffer->ValidateAndRetrieveChecksum()) {
		return false;
	}

	if (!pBuffer->CopyContent(&m_ucTypeFlags, 8, 0)) {
		return false;
	}

	Buffer *pPayload = GetPayload();
	pPayload->Clear();

	unsigned short usSize = GetSize();
	ulContentSize = pBuffer->GetContentSize();
	if (ulContentSize != usSize) {
		return false;
	}

	unsigned long ulDataSize = pBuffer->GetContentSize() - 8;
	unsigned char *pData = pBuffer->GetContentPtr() + 8;
	pPayload = GetPayload();
	return pPayload->AppendData(pData, ulDataSize);
}
