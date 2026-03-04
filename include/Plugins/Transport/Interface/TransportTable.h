//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransportTable_H_
#define _TransportTable_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Plugins/Transport/Interface/Transport.h>
#include <list>

class TransportTable {
public:
	typedef Transport *(TransportFactoryMethod)(TraceOutput *pTraceOutput, StationURL *pURL);

	TransportTable();
	virtual ~TransportTable();

	void Initialize();

	unsigned int GetSize();
	Transport *GetItem(unsigned int iTransportIndex);
	Transport* FindTransport(StationURL *pStationURL);
	Transport* FindTransport(TCHAR *szType);
	bool RemoveTransport(Transport *pTransport);

#ifdef _TEST_ENABLED
	static bool Test();
#endif

private:
	std::list<Transport*>	m_oTransportList;
};


#endif
