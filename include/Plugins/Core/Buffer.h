//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Buffer_H_
#define _Buffer_H_


#include <Plugins/Core/RefCountedObject.h>

#define DEFAULT_BUF_SIZE	4096

class Buffer: public RefCountedObject {

public:

	Buffer(unsigned long ulBufSize = DEFAULT_BUF_SIZE);
	Buffer(const Buffer &oBuffer);
	~Buffer();

	bool	AppendData(void *pBuffer, unsigned long ulNbBytes, unsigned long ulStartOffset = 0xFFFFFFFF);
	bool	CopyContent(void *pBuffer, unsigned long ulNbBytes, unsigned long ulStartOffset = 0);
	void	Clear();

	unsigned long	GetSize();
	void	        Resize(unsigned long ulSize);

	unsigned char	*GetContentPtr() const;
	unsigned long	GetContentSize() const;
	void	        SetContentSize(unsigned long ulContentSize);

	unsigned char	ComputeCheckSum();
	unsigned char	GetCheckSum();
	void 	        AppendCheckSum();
	unsigned char 	RetrieveChecksum();
	bool 	        ValidateAndRetrieveChecksum();

	unsigned char 	&operator[](const unsigned long &ulIndex);
	Buffer& operator=(const Buffer& oBuffer);
	bool 	operator==(const Buffer& oBuffer) const;
	Buffer& operator+(const Buffer &oBuffer);
	Buffer& operator+=(const Buffer& oBuffer);

	void 	Trace();

	static bool Test();

protected:
	unsigned char			*m_pData;
	unsigned short			m_usRefCount;
	unsigned long			m_ulContentSize;
	unsigned long			m_ulBufSize;
	CriticalSection	        m_csRefCount;
};

#endif
