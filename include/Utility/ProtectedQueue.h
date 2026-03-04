//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProtectedQueue_H_
#define _ProtectedQueue_H_

#include <Utility/UtilityDecl.h>
#include <Platform/Event.h>
#include <Platform/CriticalSection.h>
#include <Platform/ScopedCS.h>
#include <list>

template<class Type> class ProtectedQueue {

public:
	typedef std::list<Type>::iterator	Iterator;

	ProtectedQueue() 
	{
		m_pEvent = NULL;
	}

	ProtectedQueue(Event *pEvent) 
	{
		m_pEvent = pEvent;
	}
		
    bool Front(Type *a)
    {
		ScopedCS cs(m_csList);
		if (m_oList.empty()) return false;
		*a = m_oList.front();
		return true;
	}

    bool Back(Type *a)
    {
		ScopedCS cs(m_csList);
		if (m_oList.empty()) return false;
		*a = m_oList.back();
		return true;
	}

    void Push(Type x)
    {
		ScopedCS cs(m_csList);
		m_oList.push_back(x);
//		TRACE(D_TRACE_DEBUG,_T("Push: %d Elements in list"),m_oList.size());
		if ((m_oList.size() ==1) && (m_pEvent)) {
//			TRACE(D_TRACE_DEBUG,_T("Signaling Event"),m_oList.size());
			m_pEvent->Set();
		}
	}

    void PushFront(Type x)
    {
		ScopedCS cs(m_csList);
		m_oList.push_front(x);
//		TRACE(D_TRACE_DEBUG,_T("Push: %d Elements in list"),m_oList.size());
		if ((m_oList.size() ==1) && (m_pEvent)) {
//			TRACE(D_TRACE_DEBUG,_T("Signaling Event"),m_oList.size());
			m_pEvent->Set();
		}
	}

    void Pop()
    {
		ScopedCS cs(m_csList);
//		TRACE(D_TRACE_DEBUG,_T("Pop: %d Elements in list"),m_oList.size());
		if (m_oList.empty()) return;
		m_oList.pop_front();
		return;
	}

    bool Pop(Type *a)
    {
		ScopedCS cs(m_csList);
//		TRACE(D_TRACE_DEBUG,_T("Pop: %d Elements in list"),m_oList.size());
		if (m_oList.empty()) return false;
		*a = m_oList.front();
		m_oList.pop_front();
		return true;
	}

    bool Remove(Type a)
    {
		ScopedCS cs(m_csList);
		if (m_oList.empty()) return false;
		m_oList.remove(a);
		return true;
	}

	unsigned int Size() {
		ScopedCS cs(m_csList);
		unsigned int uiResult=m_oList.size();
		return uiResult;		
	}

	bool IsQueued(Type Item) {
		ScopedCS cs(m_csList);			
		Iterator	it;
		for (it = m_oList.begin();((it != m_oList.end()) && (*it != Item));it++);
		return (it != m_oList.end());
	}

	Iterator& AcquireIterator() {
		m_csList.Enter();
		m_oIterator = m_oList.begin();
		return m_oIterator;		
	}

	void ReleaseIterator() {
		m_csList.Leave();
	}

	Iterator End() {
		return m_oList.end();
	}

	Iterator Begin() {
		return m_oList.begin();
	}

	~ProtectedQueue() 
	{
	}

protected:
	std::list<Type>			m_oList;
	CriticalSection			m_csList;
	Iterator 				m_oIterator;
	Event					*m_pEvent;
};


template<class Type> class OProtectedQueue: public ProtectedQueue<Type> {

public:

	OProtectedQueue()
	{
	}

	OProtectedQueue(Event *pEvent):ProtectedQueue<Type>(pEvent)
	{
	}
		
    void Insert(Type x)
    {
		ScopedCS cs(m_csList);			
		std::list<Type>::iterator	it;
		for (it = Begin();(it != End()) && ((*(*it))<(*x));it++); 
		m_oList.insert(it,x);
	}

};




#ifdef _TEST_ENABLED
bool ProtectedQueueTest();
#endif


#endif
