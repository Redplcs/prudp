//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InternalEncryption_H
#define _InternalEncryption_H

class CriticalSection;
class Buffer;
class UserContext;

class InternalEncryption {

	public:

		InternalEncryption();
		virtual ~InternalEncryption();

		virtual bool Encrypt(const Buffer &oInBuffer, Buffer *pOutBuffer);
		virtual bool Encrypt(Buffer *pInOutBuffer);

		virtual bool Decrypt(const Buffer &oInBuffer, Buffer *pOutBuffer);
		virtual bool Decrypt(Buffer *pInOutBuffer);

		virtual bool SetEncryptionKey(unsigned long ulKeyLength, UserContext &oContext);

		void Encrypt(unsigned char* pInData, unsigned long ulInSize);
		void Decrypt(unsigned char* pInData, unsigned long ulInSize);

	private:
		void EncryptDecrypt(unsigned char* pInData, unsigned long ulInSize);
		void SwapByte(unsigned char* a, unsigned char* b);
		void PrepareEncryption();
		void ReinitStateArray();

		unsigned long GetKeyLength();

		unsigned char *m_pEncryptionKey;
        unsigned long m_ulKeyLength;

		unsigned char m_bState[256];
		unsigned char m_bStateCopy[256];
		unsigned char m_bKeyX;        
		unsigned char m_bKeyY;

		CriticalSection	*m_pCriticalSection;
};

#endif

