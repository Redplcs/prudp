//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MEMBERLIST_H_
#define _MEMBERLIST_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/MemberListIterator.h>
#include <ObjDup/MemberContainer.h>
#include <ObjDup/MemberVector.h>
#include <ObjDup/MemberQueue.h>
#include <list>

//Group = Member Containers

/*
Description:  This class contains methods to control the elements of a list declared in a 
dataset and associated with a doclass in the DDL file.

Remarks:
A MemberList instance is associated with a doclass in the DDL file in the following way:

        dataset ListDataset{
              List<double> lst;
        }
        doclass MyDOClass{
             ListDataset m_dsListOfDoubles;
        }

The MyDOClass implementation inherits from the DDL generated DOCLASS (MyDOClass) that 
associates the m_dsListOfDoubles to your class.  Thus you can access this dataset member
and perform operations on it just like any other dataset member of your doclass.  For example:

        class MyDOClass: public DOCLASS( MyDOClass) {
        	public:
        	
        	void PushFrontAndUpdate(double dNewValue) {
        		m_dsListOfDoubles.lst.Push_Front (dNewValue);
        		Update();
        	}
        	// other user-implemented code

		}
*/
template<class Type>
class MemberList : public MemberContainer<Type> {
//Group=Operations
public:
	//{secret}
	typedef MemberListIterator<Type> Iterator;
	
	//{secret}
	MemberList() : MemberContainer<Type>() {
		m_it.Init(this);
		m_begin.Init(this);
		m_end.Init(this);
	}

	/*
	Description:
	Pushes an element to the front of the list.
	
	Parameters:
	tElem: The element that is to be pushed to the front of the list.
	*/
	void Push_Front(const Type& tElem) {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::PUSH_FRONT_OPCODE, tElem);
		AddOperation(p_cOp);
		m_stdlList.push_front(tElem);
	}
	/*
	Description:
	Pushes an element to the back of the list.
	
	Parameters:
	tElem: The element that is to be pushed to the back of the list.
	*/
	void Push_Back(const Type& tElem) {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::PUSH_BACK_OPCODE, tElem);
		AddOperation(p_cOp);
		m_stdlList.push_back(tElem);
	}
	
	/*
	Description:
	Pops an element from the front of the list.
	
	Parameters:
	tElem: The element that is to be popped from the front of the list.
	*/
	void Pop_Front() {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::POP_FRONT_OPCODE);
		AddOperation(p_cOp);
		m_stdlList.pop_front();
	}
	
	/*
	Description:
	Pops an element from the back of the list.
	
	Parameters:
	tElem: The element that is to be popped from the back of the list.
	*/
	void Pop_Back() {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::POP_BACK_OPCODE);
		AddOperation(p_cOp);
		m_stdlList.pop_back();
	}

	/*
	Description:
	Inserts an element into a MemberList at the current position of the MemberListIterator.
	
	Parameters:
	it:  The MemberListIterator that is to be used to insert the element into the MemberList.
	tElem: The element that is to be inserted into the MemberList.
	n: Optional parameter that specifies how many copies of the element are to be inserted.
	
	Returns:
	The MemberListIterator with the inserted elements.  The returned MemberListIterator now points
	to the element immediately after the last inserted element.
	*/
	Iterator Insert(Iterator &it, const Type& tElem) {
		if(!it.IsValid()) {
			return it;
		}
		TrapLastOperationSideEffect();
		it.Refresh();
		it.SetStdIterator(m_stdlList.insert(*(it.GetStdIterator()), tElem)); it.IncPos();
		ContOp p_cOp((unsigned char)ContOp::INSERT_PX_OPCODE, it.GetPos(), tElem);
		AddOperation(p_cOp);
		return it;
	}

	
	bool Insert(Iterator &it, unsigned int n, const Type& tElem) {
		if(!it.IsValid()) {
			return false;
		}
		TrapLastOperationSideEffect();
		it.Refresh();
		m_stdlList.insert(*(it.GetStdIterator()), n, tElem); it.IncPos(n);
		ContOp p_cOp((unsigned char)ContOp::INSERT_PNX_OPCODE, it.GetPos(), n, tElem);
		AddOperation(p_cOp);
		return true;
	}

	//{secret}
	MemberListIterator<Type>& Erase(MemberListIterator<Type> &it) {
		TrapLastOperationSideEffect();
		it.Refresh();
		it.SetIterator(m_stdlList.erase(*(it.GetStdIterator())));
		ContOp p_cOp((unsigned char)ContOp::ERASE_OPCODE, it.GetPos(), 0);
		AddOperation(p_cOp);
		it.Invalidate();
		return it;
	}

	//{secret}
	bool Assign(Iterator *it,  const Type& tElem) {
		if(!it.IsValid()) {
			return false;
		}
		TrapLastOperationSideEffect();
		it->Refresh();
		ContOp p_cOp((unsigned char)ContOp::ASSIGN_OPCODE, it->GetPos(), tElem);
		AddOperation(p_cOp);
		return true;
	}

	//{secret}
	bool Assign(typename std::list<Type>::size_type n, const Type& tElem) { //To optimize
		if(!it.IsValid()) {
			return false;
		}
		Clear();
		Insert(Begin(), n, tElem);
		return true;
	}

	//{secret}
	bool InnerAssign(int iPos,  const Type& tElem) {
		ContOp p_cOp((unsigned char)ContOp::ASSIGN_OPCODE, iPos, tElem);
		AddOperation(p_cOp);
		return true;
	}

	//{secret}
	void Clear() {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::CLEAR_OPCODE);
		AddOperation(p_cOp);
		m_stdlList.clear();
	}

	/*
	Description:  Returns the element at the front of the list.
	
	Returns: The element at the front of the list.
	*/
	typename std::list<Type>::value_type& Front() {
		TrapLastOperationSideEffect();
		SetPendingOp(ContOp::FRONT_OPCODE, -1);
		return m_stdlList.front();
	}


	/*
	Description:  
	Returns the element at the back of the list.
	
	Returns: 
	The element at the back of the list.
	*/
	typename std::list<Type>::value_type& Back() {
		TrapLastOperationSideEffect();
		SetPendingOp(ContOp::BACK_OPCODE, -1);
		return m_stdlList.back();
	}
	
	/*
	Description:  Returns whether or not the list is empty.
	
	Returns:  true if the MemberList is empty, false if otherwise.
	*/
	bool Empty() {
		return m_stdlList.empty();
	}

	/*
	Description:  Returns the number of elements in the list.
	
	Returns:
	The number of elements in the MemberList
	*/
	typename std::list<Type>::size_type Size() {
		return m_stdlList.size();
	}
	/* End of List operations */

	MemberList& operator=(MemberList &ULT)
	{
		MemberListIterator<Type> uli = ULT.Begin();
		Clear();
		while(uli != ULT.End()) {
			TRACE(D_TRACE_DEBUG, _T("pushing back value %f"), *uli);
			Push_Back(*uli);
			uli++;
		}

		return *this;
	}

	/* Replay operations */
	//{secret}
	bool ReplayInsert(int iPos, const Type& tElem) {
		m_it.Begin();
		for(int i=0; i<iPos-1; i++) {m_it++;}
		m_stdlList.insert(*(m_it.GetStdIterator()), tElem);
		return true;
	}

	//{secret}
	bool ReplayInsert(int iPos, unsigned int n, const Type& tElem) {
		m_it.Begin();
        unsigned int i;
		for(i=0; i<iPos-n; i++) {m_it++;}
		m_stdlList.insert(*(m_it.GetStdIterator()), n, tElem);
		m_it.Invalidate();
		return true;
	}
	
	//{secret}
	bool ReplayErase(int iPos) {
		m_it.Begin();
		for(int i=0; i<iPos; i++) {m_it++;}
		m_stdlList.erase(*(m_it.GetStdIterator()));
		m_it.Invalidate();
		return true;
	}

	//{secret}
	bool ReplayAssign(int iPos, const Type& tElem) {
		m_it.Begin();
		typename std::list<Type>::iterator stdIt;
		for(int i=0; i<iPos; i++) {m_it++;}
		stdIt = *(m_it.GetStdIterator());
		*stdIt = tElem;
		return true;
	}
	/* End of replay operations */
	
	/*
	Description:  Sets the MemberListIterator to point to the first element in the MemberList.
	
	Returns:  The MemberListIterator that now points to the beginning of the MemberList.
	*/
	MemberListIterator<Type>& Begin() {
		*(m_begin.GetStdIterator()) = m_stdlList.begin();
		return m_begin;
	}

	/*
	Description:  Sets the MemberListIterator to point to the last element in the MemberList.
	
	Returns:  The MemberListIterator that now points to the last element in the MemberList.
	*/
	MemberListIterator<Type>& End() {
		*(m_end.GetStdIterator()) = m_stdlList.end();
		return m_end;
	}

	//{secret}
	bool TrapLastOperationSideEffect() {
		bool bRet = true;
		int iPos = 0;
		switch (m_bPendingOp) {
			case ContOp::FRONT_OPCODE:
				bRet = InnerAssign(0, m_stdlList.front()); 
				ClearPendingOp();
				break;
			case ContOp::BACK_OPCODE:
				iPos = m_stdlList.size()-1;
				bRet = InnerAssign(iPos, m_stdlList.back()); 
				ClearPendingOp();
				break;
			case ContOp::ASSIGN_OPCODE:
				m_it.SetPos(m_iPendingOpIndex);
				bRet = InnerAssign(m_iPendingOpIndex, *m_it); 
				ClearPendingOp();
				break;
			default:
				break;
		}
		return bRet;
	}

	//{secret}
	virtual bool Small() {return Size() <= m_coOperationList.size();}

	//{secret}
	bool ReplayOperations() {
		bool bRet=true;
		std::list<ContOp>::iterator it = m_coOperationList.begin();
		ContOp *pcoOpTmp=NULL;
		while(!m_coOperationList.empty()) {
			pcoOpTmp = &m_coOperationList.back();

			switch(pcoOpTmp->GetOpCode()) {
				case ContOp::PUSH_FRONT_OPCODE:
					m_stdlList.push_front(pcoOpTmp->GetData());
					break;
				case ContOp::PUSH_BACK_OPCODE:
					m_stdlList.push_back(pcoOpTmp->GetData());
					break;
				case ContOp::POP_FRONT_OPCODE:
					m_stdlList.pop_front();
					break;
				case ContOp::POP_BACK_OPCODE:
					m_stdlList.pop_back();
					break;
				case ContOp::INSERT_PX_OPCODE:
					bRet = ReplayInsert(pcoOpTmp->GetPos(), pcoOpTmp->GetData());
					break;
				case ContOp::INSERT_PNX_OPCODE:
					bRet = ReplayInsert(pcoOpTmp->GetPos(), pcoOpTmp->GetRepeat(), pcoOpTmp->GetData());
					break;
				case ContOp::INSERT_PFL_OPCODE:
					//TODO
					break;
				case ContOp::ERASE_OPCODE:
					bRet = ReplayErase(pcoOpTmp->GetPos());
					break;
				case ContOp::CLEAR_OPCODE:
					m_stdlList.clear();
					break;
				case ContOp::ASSIGN_OPCODE:
					bRet = ReplayAssign(pcoOpTmp->GetPos(), pcoOpTmp->GetData());
					break;
				default: return false;
			}
			pcoOpTmp = NULL;
			m_coOperationList.pop_back();
		}
		return bRet;
	}

	//{secret}
	virtual void AddContentToMsg(Message *pMsg) {
		std::list<Type> lTmp = m_stdlList;
		unsigned int uiSize = lTmp.size();
		*pMsg << uiSize;
		
		while(!lTmp.empty()) {
			*pMsg << lTmp.back();
			lTmp.pop_back();
		}
	}

//{secret}
	virtual void ExtractContentFromMsg(Message *pMsg) {
		unsigned int uiNbElem=0;
		Type tElem=0;
		m_stdlList.clear();
		pMsg->Extract(&uiNbElem);
		while(uiNbElem>0) {
			*pMsg >> tElem;
			m_stdlList.push_front(tElem);
			uiNbElem--;
		}
	}
	
	virtual bool operator==(MemberList& ult) {
		return *GetStdList()==*(ult.GetStdList());
	}

	//{secret}
	std::list<Type>* GetStdList() {
		return &m_stdlList;
	}

	//{secret}
	bool TraceContent(TCHAR* szFormat, unsigned long ulTraceFlag) {
		TRACE(ulTraceFlag, _T("\n\nTracing list content : "));
		std::list<Type>::iterator itTmp = m_stdlList.begin();
		double valTmp=0.0;
		while(itTmp != m_stdlList.end()) {
			valTmp = *itTmp;
			TRACE(ulTraceFlag, szFormat, (float) valTmp);
			itTmp++;
		}
		return true;
	}

#ifdef _TEST_ENABLED
	//{secret}
	bool static Test()
	{
		return (ListTestExt() && QueueTestExt() && VectorTestExt());
	}
#endif//_RELEASE

//{secret}
	virtual bool ApplyAllOperations(){return true;}

private:
	std::list<Type> m_stdlList;
	MemberListIterator<Type> m_it, m_begin, m_end;
};

#ifdef _TEST_ENABLED
static int ListTestExt() {
		BEGIN_TESTS;

		TRACE(D_TRACE_TEST, _T("\n\nBegin tests ... "));

		{
			int i=0;
			std::list<double> ListDouble;

			MemberList<double> UCT1, UCT2, UCT3, UCTTmp;

			MemberListIterator<double> ite = UCT1.Begin();

			/* simple operations */


			/* More complex operations */	

			UCT1.Push_Front(1.0);
			UCT1.Push_Front(2.0);

			ite = UCT1.Begin();
			UCT1.Insert(ite, 111.0);
			UCT1.Insert(ite, 112.0);
			UCT1.Insert(ite, 113.0);
			UCT1.Push_Back(33.0);

			UCT1.Front() = 1234.0;
			*ite=444.0;
			ite++;
			UCT1.Back() = 4321.0;
			*ite=777.0;
		
			UCT1.Push_Front(7.0);

			UCT1.Push_Front(44.0);


			TRACE(D_TRACE_TEST, _T("content:%f"), *ite);

			UCT1.TraceOperations(_T("%f"), D_TRACE_TEST); 
			UCT1.TraceContent(_T("%f"), D_TRACE_TEST);

			UCTTmp = UCT1;

			TRACE(D_TRACE_TEST, _T("\n\nContent of UCTTmp : "));
			UCTTmp.TraceContent(_T("%f"), D_TRACE_TEST);

			TEST(UCT1 == UCTTmp);


			//TRACE(D_TRACE_TEST, _T("Replaying operations on Queue2"));
			//UCT2.ReplayOperationsFromList(UCT1.GetOperationsList());
			//UCT2.TraceOperations();
			//UCT2.TraceContent();
			
			//TEST(UCT1 == UCT2);

			/* End of first test */
			UCT2.Clear();
			UCT2.ClearOperations();

			Message mMsg;
			Message *pMsg = &mMsg;

			UCT3 = UCT1;
			TEST(UCT1 == UCT3);
			UCT3.AddSourceTo(pMsg);
			UCT2.ExtractFrom(pMsg);

			TRACE(D_TRACE_TEST, _T("Replaying operations on Queue2"));
			UCT2.ReplayOperations();

			UCT2.TraceOperations(_T("%f"), D_TRACE_TEST);
			UCT2.TraceContent(_T("%f"), D_TRACE_TEST);
			TEST(UCT1 == UCT2);
			
			return TESTRESULT;	
		}
		
}

//{secret}
static int VectorTestExt() {
BEGIN_TESTS;

		TRACE(D_TRACE_TEST, _T("\n\nBegin tests ... "));

		{
			int i=0;
			MemberVector<double> UCT1, UCT2, UCTTmp;
			
			//UCT1.Assign(10, 0.0); 	

			MemberVectorIterator<double> ite = UCT1.Begin();


			/* simple operations */
			UCT1.Insert(ite, 3333.0);
			for(i=0; i<10; i++) {
				ite = UCT1.Insert(ite, 3333.0);
			}

			
			/* More complex operations */

			UCT1.SetContentUpdate();
			UCT1.Push_Back(-1.0);
//			UCT1.Clear();
			
			UCT1.Push_Back(1.0);
			UCT1.Push_Back(2.0);
		
			UCT1.Front() = 2000.0;

			UCT1.Push_Back(3.0);
			UCT1.Push_Back(4.0);
			UCT1.Back() = 3000.0;
			
			//ite.Begin(); for(int i=0;(ite != UCT1.End()); i++) {ite++;}
			ite.Begin();//ite++;ite++;ite++;
			//TRACE(D_TRACE_TEST, _T("it is now at pos %d, that is %d according to the Iterator"), i, ite.GetPos());
			TRACE(D_TRACE_TEST, _T("it is now at pos %d according to the Iterator"), ite.GetPos());

			UCT1.Erase(ite);
			UCT1.Insert(ite, 21.0);
			UCT1.Insert(ite, 23.0);
			UCT1.Insert(ite, 24.0);


			TRACE(D_TRACE_TEST, _T("Test1"));
			UCT1[3] = 777.0;
			UCT1.Insert(ite, 3, 22.0);
			
			ite = UCT1.Begin();
			ite+=3;
			*ite = 3333333.0;
			UCT1.Erase(ite);
			ite-=2;
			TRACE(D_TRACE_TEST, _T("Test2"));
			UCT1.Insert(ite, 44444444.0);
			*++ite = 666.0;
			ite+=7;
			ite+=(++ite-ite);
			UCT1.Insert(ite, 6, 777777777.0);
			UCT1.Front() = 1000.0;
			
			UCTTmp = UCT1;

			TRACE(D_TRACE_TEST, _T("\n\nContent of UCTTmp : "));
			UCTTmp.TraceContent(_T("%f"), D_TRACE_TEST);

			TEST(UCT1 == UCTTmp);


			TRACE(D_TRACE_TEST, _T("Test3"));
			
			//UCT1.TraceOperations(); 
			//UCT1.TraceContent();
			/*
			//TRACE(D_TRACE_DEBUG, _T("Replaying operations on Queue2"));
			//UCT2.ReplayOperationsFromList(UCT1.GetOperationsList());
			//UCT2.TraceOperations();
			//UCT2.TraceContent();
			
			//TEST(UCT1 == UCT2);
			*/

			/* End of first test */

			TRACE(D_TRACE_TEST, _T("Tracing UCT1 content:"));
			UCT1.TraceContent(_T("%f"), D_TRACE_TEST);

			
			Message mMsg;
			Message *pMsg = &mMsg;

			UCT1.AddSourceTo(pMsg);
			UCT2.ExtractFrom(pMsg);

			TRACE(D_TRACE_TEST, _T("Replaying operations on Queue2"));
			UCT2.ReplayOperations();

			UCT2.TraceOperations(_T("%f"), D_TRACE_TEST);
			TRACE(D_TRACE_TEST, _T("Tracing UCT2 content:"));
			UCT2.TraceContent(_T("%f"), D_TRACE_TEST);
			TEST(UCT1 == UCT2)
		}
		return TESTRESULT;	
}

//{secret}
static int QueueTestExt() {
			BEGIN_TESTS;

			TRACE(D_TRACE_TEST, _T("\n\nBegin tests ... "));
			MemberQueue<double> UCT1, UCT2, UCTTmp;

			UCT1.Push(-1.0);
			UCT1.Push(1.0);
			UCT1.Push(2.0);
			UCT1.Pop();
			UCT1.Push(3.0);

			UCT1.Front() = 222.0;
			UCT1.Back() = 333.0;
			UCT1.Push(5.0);
			UCT1.Push(6.0);
			
			UCT1.TraceOperations(_T("%f"), D_TRACE_TEST); 
			UCT1.TraceContent(_T("%f"), D_TRACE_TEST);

			UCTTmp = UCT1;

			TRACE(D_TRACE_TEST, _T("\n\nContent of UCTTmp : "));
			UCTTmp.TraceContent(_T("%f"), D_TRACE_TEST);

			TEST(UCT1 == UCTTmp);

			//TRACE(D_TRACE_TEST, _T("Replaying operations on Queue2"));
		/*	UCT2.ReplayOperations(UCT1.GetOperationsList());

			UCT2.TraceOperations();
			UCT2.TraceContent();
			
			TEST(UCT1 == UCT2)*/
			//End of first test

			//Second test : add to msg, extract and replay
			Message mMsg;
			Message *pMsg = &mMsg;
			while(!UCT2.Empty()){UCT2.Pop();}
			UCT2.ClearOperations();

			UCTTmp.AddSourceTo(pMsg);
			UCT2.ExtractFrom(pMsg);

			//TRACE(D_TRACE_TEST, _T("Replaying operations on Queue2"));
			UCT2.ReplayOperations();

			UCT2.TraceOperations(_T("%f"), D_TRACE_TEST);
			UCT2.TraceContent(_T("%f"), D_TRACE_TEST);
			TEST(UCT1 == UCT2)
			return TESTRESULT;
}
#endif//_RELEASE

#endif//_MEMBERLIST_H_

