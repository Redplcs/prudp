//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _CompressionAlgorithm_H
#define _CompressionAlgorithm_H

#include <Plugins/Core/PluginObject.h>
class Buffer;
class Plugin;

class CompressionAlgorithm: public PluginObject {

public:

	CompressionAlgorithm(Plugin *pPlugin);
	virtual ~CompressionAlgorithm();

	virtual void Compress(const Buffer &oInBuffer, Buffer *pOutBuffer); 
	virtual void Compress(Buffer *pInOutBuffer);

	virtual void Decompress(const Buffer &oInBuffer, Buffer *pOutBuffer);
	virtual void Decompress(Buffer *pInOutBuffer);

};

#endif




