//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _EndPointGroup_H_
#define _EndPointGroup_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Platform/CriticalSection.h>
#include <Platform/UserContext.h>
#include <list>
class EndPoint;
class Transport;
class Buffer;

class EndPointGroup {

	friend class Transport;

public:
	typedef void (*Callback)(EndPointGroup*, Buffer *pBuffer, UserContext *pContext);
	typedef std::list<EndPointGroup*>			EndPointGroupList;
	typedef std::list<EndPointGroup*>::iterator	EndPointGroupIterator;
	typedef std::list<EndPoint*> 				EndPointList;
	typedef std::list<EndPoint*>::iterator 		EndPointIterator;

	EndPointGroup();
	~EndPointGroup();

	unsigned long		AddEndPoint(EndPoint *pEndPoint, unsigned long ulTimeout = 30000);
	unsigned long		AddEndPoint(EndPoint *pEndPoint, 
							const EndPointGroup::Callback *pCallback, const UserContext &oContext, 
							unsigned long ulTimeout = 30000);

	unsigned long		RemoveEndPoint(EndPoint *pEndPoint, unsigned long ulTimeout = 30000);
	unsigned long		RemoveEndPoint(EndPoint *pEndPoint, 
							const EndPointGroup::Callback *pCallback, const UserContext &oContext, 
							unsigned long ulTimeout = 30000);


	unsigned long		AddEndPointGroup(EndPointGroup *pEndPointGroup, unsigned long ulTimeout = 30000);
	unsigned long		AddEndPointGroup(EndPointGroup *pEndPointGroup, 
							const EndPointGroup::Callback *pCallback, const UserContext &oContext, 
							unsigned long ulTimeout = 30000);

	unsigned long		RemoveEndPointGroup(EndPointGroup *pEndPointGroup, unsigned long ulTimeout = 30000);
	unsigned long		RemoveEndPointGroup(EndPointGroup *pEndPointGroup, 
							const EndPointGroup::Callback *pCallback, const UserContext &oContext, 
							unsigned long ulTimeout = 30000);


	unsigned long		Send(Buffer *pBuffer, unsigned long ulFlags = 0);
	unsigned long		Send(Buffer *pBuffer, 
							const EndPointGroup::Callback *pCallback, const UserContext &oContext, 
							unsigned long ulFlags = 0);
	
	void			Lock();
	void			Unlock();

	EndPointGroupIterator	GetEndPointGroupIterator();
	EndPointIterator		GetEndPointIterator();

#ifdef _TEST_ENABLED
	static bool Test();
#endif

protected:
	EndPointGroup(Transport *pTransport);

protected:
	EndPointList		m_oEndPointList;
	EndPointGroupList	m_oEndPointGroupList;
	CriticalSection		m_csLock;
	Transport*			m_pAssociatedTransport;
};


#endif
