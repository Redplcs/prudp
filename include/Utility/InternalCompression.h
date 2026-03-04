//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InternalCompression_H
#define _InternalCompression_H

#include <Platform/CriticalSection.h>
class Buffer;

#define RING_BUFFER_SIZE		4096
#define MATCH_LENGTH_LIMIT		18	


class InternalCompression {
	public:
		InternalCompression();
		virtual ~InternalCompression();
	
		void Compress(const Buffer &oInBuffer, Buffer *pOutBuffer); 
		void Compress(Buffer *pInOutBuffer);
	
		void Decompress(const Buffer &oInBuffer, Buffer *pOutBuffer);
		void Decompress(Buffer *pInOutBuffer);

		unsigned long Compress(unsigned char* pInData, unsigned long ulInSize, unsigned char* pOutData); 
		unsigned long Decompress(unsigned char* pInData, unsigned long ulInSize, unsigned char* pOutData);
		float GetCompressionRatio();
		
	private:
		void InitCompression();
		void InitTree();
		void InsertNode(int iNodeIndex);
		void DeleteNode(int iNodeIndex);
		unsigned long Encode(unsigned char* pInData, unsigned long ulInSize, unsigned char* pOutData);
		unsigned long Decode(unsigned char* pInData, unsigned long ulInSize, unsigned char* pOutData);

		unsigned long m_ulTotalDataSize;
		unsigned long m_ulTotalCompressedDataSize;

		CriticalSection s_CompressionCS;

		unsigned char	m_abBuffer[RING_BUFFER_SIZE + MATCH_LENGTH_LIMIT - 1];
		int		m_iMatchPosition, m_iMatchLength;
		int		m_iLSon[RING_BUFFER_SIZE + 1];
		int		m_iRSon[RING_BUFFER_SIZE + 257], m_iRSonInitial[RING_BUFFER_SIZE + 257];
		int		m_iDad[RING_BUFFER_SIZE + 1], m_iDadInitial[RING_BUFFER_SIZE + 1];
};

#endif




