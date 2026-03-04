//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TimedQueue_H_
#define _TimedQueue_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <list>
#include <map>

template<class Type> class TimedQueue {
	struct Pair {	
		Type	first;
		Time	second;
		Pair(Type oNode, Time oTime) { first = oNode; second = oTime; }
	};
public:
	TimedQueue() { };
	~TimedQueue() {
		while(m_oQueue.size()) {
			Dequeue();
		}
	}		

	void Queue(Type oNode, Time oTime) {
		ACQUIREREF(oNode);
		m_oQueue.push_back(fnew Pair(oNode,oTime));
	}

	void QueueHighPriority(Type oNode, Time oTime) {
		ACQUIREREF(oNode);
		m_oQueue.push_front(fnew Pair(oNode,oTime));
	}

	bool Head(Type *Node, Time *pTime = NULL)
	{
		if (m_oQueue.size()) {
			Pair	*pFrontPair;
			pFrontPair = m_oQueue.front();
			if ((_LONGLONG)pFrontPair->second <= (_LONGLONG)Time::GetTime()) {
				*Node = pFrontPair->first;
				if (pTime) {
					*pTime = pFrontPair->second;
				}
				return true;
			}
		}
		return false;
	}

	void Dequeue()
	{
		SYSTEMCHECK(m_oQueue.size()>0);
		RELEASEREF(m_oQueue.front()->first);
		fdelete m_oQueue.front();
		m_oQueue.pop_front();
	}

	unsigned long Size()
	{
		return m_oQueue.size();
	}

	Time HeadTime()
	{
		Time oTime;
		if (m_oQueue.size()>0) {
			oTime = m_oQueue.front()->second; 
			return oTime;
		} else {
			return 0;
		}
	}

private:
	std::list<Pair*> m_oQueue;
};



#endif
