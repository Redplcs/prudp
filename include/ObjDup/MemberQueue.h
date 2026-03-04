//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MEMBERQUEUE_H_
#define _MEMBERQUEUE_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/MemberContainer.h>
#include <list>
#include <queue>

//Group = Member Containers

/*
Description:  This class contains methods to control the elements of a queue declared in a 
dataset and associated with a doclass in the DDL file.

Remarks:
A MemberQueue instance is associated with a doclass in the DDL file in the following way: 

        dataset QueueDataset{ 
                 Queue<double> que; 
         } 
         
         doclass MyDOClass{ 
                  QueueDataset m_dsQueueOfDoubles; 
        } 

The MyDOClass implementation inherits from the DDL generated DOCLASS (MyDOClass) that associates the m_dsQueueOfDoubles to your class. 
Thus you can access this dataset member and perform operations on it just like any other dataset member of your doclass. For example: 

              class MyDOClass: public DOCLASS ( MyDOClass) { 
                 public: 
                   
                 void PushToBackOfQueue(double dNewValue) { 
                                  m_dsQueueOfDoubles.lst.Push(dNewValue); 
                                 Update(); 
                 } 
                 // other user-implemented code 
			  }


*/
template<class Type>
class MemberQueue : public MemberContainer<Type>{
//Group=Operations
public:

//{secret}
	MemberQueue() : MemberContainer<Type>() {}

	/*
	Description:
	Pops an element from the front of the queue.
	
	Parameters:
	tElem: The element that is to be popped from the front of the queue.
	*/
	void Pop() {
		TrapLastOperationSideEffect();
		ContOp p_cOp = ContOp((unsigned char)ContOp::POP_OPCODE);
		AddOperation(p_cOp);
		m_stdqQueue.pop();
	}
	
	/*
	Description:
	Pushes an element to the back of the queue.
	
	Parameters:
	tElem: The element that is to be pushed to the back of the queue.
	*/
	void Push(const Type& co_Elem) {
		TrapLastOperationSideEffect();
		ContOp p_cOp = ContOp((unsigned char)ContOp::PUSH_OPCODE, co_Elem);
		AddOperation(p_cOp);
		m_stdqQueue.push(co_Elem);	
	}
	
	/*
	Description:  Returns the element at the front of the queue.
	
	Returns:
	The element at the front of the queue.
	*/
	typename std::queue<Type>::value_type& Front() {
		TrapLastOperationSideEffect();
		m_bPendingOp = ContOp::FRONT_OPCODE;
		return m_stdqQueue.front();
	}

	/*
	Description:  Returns the element at the back of the queue.
	
	Returns:
	The element at the back of the queue.
	*/
	typename std::queue<Type>::value_type& Back() {
		TrapLastOperationSideEffect();
		m_bPendingOp = ContOp::BACK_OPCODE;
		return m_stdqQueue.back();
	}

	/*
	Description:  Returns whether or not the queue is empty.
	
	Returns:  true if the MemberQueue is empty, false if otherwise.
	*/
	bool Empty() {
		return m_stdqQueue.empty();
	}

	/*
	Description:  Returns the number of elements in the queue.
	
	Returns:
	The number of elements in the MemberQueue
	*/
	typename std::queue<Type>::size_type Size() {
		return m_stdqQueue.size();
	}
	

//{secret}
	virtual bool Small() {return Size() <= m_coOperationList.size();}

	//{secret}
	bool InnerAssign(int iPos,  const Type& tElem) {
		ContOp p_cOp((unsigned char)ContOp::ASSIGN_OPCODE, iPos, tElem);
		AddOperation(p_cOp);
		return true;
	}

	/*Replay operations*/
	//{secret}
	bool ReplayInnerAssign(int iPos, const Type& tElem) {
		if(iPos==0) {
			m_stdqQueue.front() = tElem;
		}
		else if ((unsigned int)iPos==m_stdqQueue.size()-1){
			m_stdqQueue.back() = tElem;
		}
		else {
			//error.
			return false;
		}
		return true;
	}
	/*End of replay operations*/

//{secret}
	bool ReplayOperations() {
		bool bRet=true;
		std::list<ContOp>::iterator it = m_coOperationList.begin();
		ContOp *pcoOpTmp=NULL;
		while(!m_coOperationList.empty()) {
			pcoOpTmp = m_coOperationList.back().GetPtr();
			switch(pcoOpTmp->GetOpCode()) {
			case ContOp::POP_OPCODE:
					m_stdqQueue.pop();
					break;
				case ContOp::PUSH_OPCODE:
					m_stdqQueue.push(pcoOpTmp->GetData());
					break;
				case ContOp::ASSIGN_OPCODE:
					bRet = ReplayInnerAssign(pcoOpTmp->GetPos(), pcoOpTmp->GetData());
					break;
				default : return false;
			}
			m_coOperationList.pop_back();
		}
		return bRet;
	}

	//{secret}
	bool TrapLastOperationSideEffect() {
		bool bRet=true;
		int iPos = 0;
		switch (m_bPendingOp) {
			case ContOp::FRONT_OPCODE:
				bRet = InnerAssign(0, m_stdqQueue.front()); 
				ClearPendingOp();
				break;
			case ContOp::BACK_OPCODE:
				iPos = m_stdqQueue.size()-1;
				bRet = InnerAssign(iPos, m_stdqQueue.back()); 
				ClearPendingOp();
				break;
			default:
				break;
		}
		return bRet;
	}

//{secret}
	virtual void AddContentToMsg(Message *pMsg) {
		std::queue<Type> qTmp = m_stdqQueue;
		unsigned int uiSize = m_stdqQueue.size();
		*pMsg << uiSize;
		while(!qTmp.empty()) {
 			double tmp = qTmp.front(); 
			*pMsg << qTmp.front();
			qTmp.pop();
		}
	}

//{secret}
	virtual void ExtractContentFromMsg(Message *pMsg) {
		Type tElem=0;
		unsigned int uiSize=0;
		pMsg->Extract(&uiSize);
		while(!m_stdqQueue.empty()) {m_stdqQueue.pop();}
		while(uiSize>0) {
			*pMsg >> tElem;
			m_stdqQueue.push(tElem);
			uiSize--;
		}
	}

	//{secret}
	std::queue<Type>* GetStdqQueue() {
		return &m_stdqQueue;
	}

	MemberQueue& operator=(MemberQueue<Type> &mqQ)
	{
		int i=0;
		MemberQueue<Type> mqTmp;
		
		while(!Empty()) {Pop();}
		while(!mqQ.Empty()) {
			mqTmp.Push(mqQ.Front());
			Push(mqQ.Front());
			mqQ.Pop();
		}
		
		//Rebuild mqQ
		while(!mqTmp.Empty()) {
			mqQ.Push(mqTmp.Front());
			mqTmp.Pop();
		}
		return *this;
	}

	virtual bool operator==(MemberQueue& uqt) {
		return *GetStdqQueue()==*(uqt.GetStdqQueue());
	}

	//Unit tests
	//{secret}
	bool TraceContent(TCHAR* szFormat, unsigned long ulTraceFlag) {
		TRACE(ulTraceFlag, _T("\n\nTracing queue content : "));
		std::queue<Type> qTmp = m_stdqQueue;
		while(!qTmp.empty()) {
			TRACE(ulTraceFlag, szFormat, (float) qTmp.front());
			qTmp.pop();
		}
		return true;
	}

	//{secret}
	std::queue<Type> m_stdqQueue;
};


#endif//_MEMBERQUEUE_H_
