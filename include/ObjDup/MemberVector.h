//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MEMBERVECTOR_H_
#define _MEMBERVECTOR_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/MemberContainer.h>
#include <ObjDup/MemberVectorIterator.h>
#include <list>
#include <vector>


//Group = Member Containers

/*
Description:  This class contains methods to control the elements of a vector declared in a 
dataset and associated with a doclass in the DDL file.

Remarks:
A MemberVector instance is associated with a doclass in the DDL file in the following way:

        dataset VectorDataset{
              vector<double> vec;
        }
        doclass MyDOClass{
             VectorDataset m_dsVectorOfDoubles;
        }

The MyDOClass implementation inherits from the DDL generated DOCLASS (MyDOClass) that 
associates the m_dsVectorOfDoubles to your class.  Thus you can access this dataset member
and perform operations on it just like any other dataset member of your doclass.  For example:

        class MyDOClass: public DOCLASS( MyDOClass) {
        	public:
        	
        	void PushBackAndUpdate(double dNewValue) {
        		m_dsVectorOfDoubles.vec.Push_Back (dNewValue);
        		Update();
        	}
        	// other user-implemented code
		}

*/
template<class Type>
class MemberVector : public MemberContainer<Type> {
//Group=Operations
public:

	//{secret}
	typedef MemberVectorIterator<Type> Iterator;
	
	//{secret}
	MemberVector() :	MemberContainer<Type>() {
		m_it.Init(this);
		m_begin.Init(this);
		m_end.Init(this);
		m_iPendingOpIndex=-1;
	}

	
	/*
	Description:
	Pushes an element to the back of the vector.
	
	Parameters:
	tElem: The element that is to be pushed to the back of the vector.
	*/
	void Push_Back(const Type& tElem) {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::PUSH_BACK_OPCODE, tElem);
		AddOperation(p_cOp);
		m_stdvVector.push_back(tElem);
	}

	
	/*
	Description: Pops an element from the back of the vector.
	*/
	void Pop_Back() {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::POP_BACK_OPCODE);
		AddOperation(p_cOp);
		m_stdvVector.pop_back();
	}
	
	/*
	Description:
	Inserts an element into a MemberVector at the current position of the MemberVectorIterator.
	
	Parameters:
	it:  The MemberVectorIterator that is to be used to insert the element into the MemberVector.
	tElem: The element that is to be inserted into the MemberVector.
	n: Optional parameter that specifies how many copies of the element are to be inserted.
	
	Returns:
	The MemberVectorIterator with the inserted elements.  The returned MemberVectorIterator now points
	to the element immediately after the last inserted element.
	
	*/
	Iterator& Insert(Iterator &it, const Type& tElem) {
		TrapLastOperationSideEffect();
		it.Refresh();
		it.SetStdIterator(m_stdvVector.insert(*(it.GetStdIterator()), tElem)); it.IncPos();
		ContOp p_cOp = ContOp((unsigned char)ContOp::INSERT_PX_OPCODE, it.GetPos(), tElem);
		AddOperation(p_cOp);
		return it;
	}

	bool Insert(Iterator &it, unsigned int n, const Type& tElem) {
		if(!it.IsValid()) {return false;}
		TrapLastOperationSideEffect();
		it.Refresh();
		m_stdvVector.insert(*(it.GetStdIterator()), n, tElem); it.IncPos(n);
		ContOp p_cOp = ContOp((unsigned char)ContOp::INSERT_PNX_OPCODE, it.GetPos(), n, tElem);
		AddOperation(p_cOp);
		it.Invalidate();
		return true;
	}

	//{secret}
	bool Assign(Iterator *it,  const Type& tElem) {
		if(!it->IsValid()) {return false;}
		TrapLastOperationSideEffect();
		it->Refresh();
		ContOp p_cOp((unsigned char)ContOp::ASSIGN_OPCODE, it->GetPos(), tElem);
		AddOperation(p_cOp);
		return true;
	}

	//replaces vector by new vector containing n copies of tElem
	void Assign(typename std::vector<Type>::size_type n, const Type& tElem) { //To optimize
		Clear();
		Insert(Begin(), n, tElem);
	}

	/*
	Description:  Returns the element at the position specified
	
	Returns:  The element in the MemberVector at the position specified
	
	Parameters:
	iPos: Index into the MemberVector 
	*/
	typename std::vector<Type>::value_type& operator[](const int iPos) {
		TrapLastOperationSideEffect();
		SetPendingOp(ContOp::BRACKET_OPCODE, iPos);
		return m_stdvVector[m_iPendingOpIndex];
	}

	//{secret}
	MemberVectorIterator<Type>& Erase(MemberVectorIterator<Type> &it) {
		TrapLastOperationSideEffect();
		it.Refresh();
		it.SetStdIterator(m_stdvVector.erase(*(it.GetStdIterator())));
		ContOp p_cOp = ContOp((unsigned char)ContOp::ERASE_OPCODE, it.GetPos(), 0);
		AddOperation(p_cOp);
		it.Invalidate();
		return it;
	}

	//{secret}
	void Clear() {
		TrapLastOperationSideEffect();
		ContOp p_cOp((unsigned char)ContOp::CLEAR_OPCODE);
		AddOperation(p_cOp);
		m_stdvVector.clear();
	}

	/*
	Description:  Returns the element at the front of the MemberVector.
	
	Returns:
	The element at the front of the vector.
	*/
	typename std::vector<Type>::value_type& Front() {
		TrapLastOperationSideEffect();
		SetPendingOp(ContOp::FRONT_OPCODE, -1);
		return m_stdvVector.front();
	}

	/*
	Description:  Returns the element at the back of the MemberVector.
	
	Returns:
	The element at the back of the vector.
	*/
	typename std::vector<Type>::value_type& Back() {
		TrapLastOperationSideEffect();
		SetPendingOp(ContOp::BACK_OPCODE, -1);
		return m_stdvVector.back();
	}

	/*
	Description:  Returns whether or not the MemberVector is empty.
	
	Returns:  true if the MemberVector is empty, false if otherwise.
	*/
	bool Empty() {
		return m_stdvVector.empty();
	}

	/*
	Description:  Returns the number of elements in the MemberVector.
	
	Returns:  The number of elements in the MemberVector.
	*/
	typename std::vector<Type>::size_type Size() {
		return m_stdvVector.size();
	}

	//{secret}
	virtual bool Small() {return Size() <= m_coOperationList.size();}

	/*
	Description:  Sets the MemberVectorIterator to point to the first element in the MemberVector.
	
	Returns:  The MemberVectorIterator that now points to the beginning of the MemberVector.
	*/
	MemberVectorIterator<Type>& Begin() {
		*(m_begin.GetStdIterator()) = m_stdvVector.begin();
		return m_begin;
	}

	/*
	Description:  Sets the MemberVectorIterator to point to the last element in the MemberVector.
	
	Returns:  The MemberVectorIterator that now points to the last element in the MemberVector.
	*/
	MemberVectorIterator<Type>& End() {
		*(m_end.GetStdIterator()) = m_stdvVector.end();
		SYSTEMCHECK(*m_end.GetStdIterator()==m_stdvVector.end());
		return m_end;
	}

	virtual bool operator==(MemberVector& oVec) {
		return *GetStdVector()==*(oVec.GetStdVector());
	}

	MemberVector& operator=(MemberVector& oVec)
	{
		unsigned int i=0;
		Clear();
		
		for(i=0; i<oVec.Size(); i++) {
			Push_Back(oVec[i]);
		}

		return *this;
	}

	//{secret}
	bool InnerAssign(int iPos,  const Type& tElem) {
		ContOp p_cOp((unsigned char)ContOp::ASSIGN_OPCODE, iPos, tElem);
		AddOperation(p_cOp);
		return true;
	}


	//{secret}
	bool TrapLastOperationSideEffect() {
		bool bRet=true;
		unsigned int iPos = 0;
		switch (m_bPendingOp) {
			case ContOp::FRONT_OPCODE:
				bRet = InnerAssign(0, m_stdvVector.front()); 
				ClearPendingOp();
				break;
			case ContOp::BACK_OPCODE:
				iPos = m_stdvVector.size()-1;
				bRet = InnerAssign(iPos, m_stdvVector.back()); 
				ClearPendingOp();
				break;
			case ContOp::ASSIGN_OPCODE:
				m_it.SetPos(m_iPendingOpIndex);
				bRet = InnerAssign(m_iPendingOpIndex, *m_it); 
				ClearPendingOp();
				break;
			case ContOp::BRACKET_OPCODE:
				SYSTEMCHECK(m_iPendingOpIndex!=-1);
				bRet = InnerAssign(m_iPendingOpIndex, m_stdvVector[m_iPendingOpIndex]); 
				ClearPendingOp();
				break;
			default:
				break;
		}
		return bRet;
	}

/* Replay operations */
	//{secret}
	void ReplayInsert(int iPos, const Type& tElem) {
		m_it.Begin();
		double dum=1.0;
		for(int i=0; i<iPos-1; i++) {m_it++;}
		m_stdvVector.insert(*(m_it.GetStdIterator()), tElem);
	}

	//{secret}
	void ReplayInsert(int iPos, unsigned int n, const Type& tElem) {
		m_it.Begin();
        unsigned int i;
		for(i=0; i<iPos-n; i++) {m_it++;}
		m_stdvVector.insert(*(m_it.GetStdIterator()), n, tElem);
	}
	
	//{secret}
	void ReplayErase(int iPos) {
		m_it.Begin();
		for(int i=0; i<iPos; i++) {m_it++;}
		m_stdvVector.erase(*(m_it.GetStdIterator()));
	}

	//{secret}
	void ReplayAssign(int iPos, const Type& tElem) {
		m_it.Begin();
		typename std::vector<Type>::iterator stdIt;
		for(int i=0; i<iPos; i++) {m_it++;}
		stdIt = *(m_it.GetStdIterator());
		*stdIt = tElem;
	}
	/* End of replay operations */

	//{secret}
	virtual void AddContentToMsg(Message *pMsg) {
		unsigned int i=0;
		unsigned int uiSize = m_stdvVector.size();
		*pMsg << uiSize;
		for(i=0; i<m_stdvVector.size(); i++) {
			*pMsg << m_stdvVector[i];
		}
	}

	//{secret}
	virtual void ExtractContentFromMsg(Message *pMsg) {
		unsigned int uiNbElem=0, i=0;
		std::vector<Type>::iterator itTmp = m_stdvVector.begin();
		Type tElem=0;
		m_stdvVector.clear();
		*pMsg >> uiNbElem;
		
		for(i=0; i<uiNbElem; i++) {
			*pMsg >> tElem;
			itTmp = m_stdvVector.insert(itTmp, tElem); itTmp++;
		}
	}

	//{secret}
	bool TraceContent(TCHAR* szFormat, unsigned long ulTraceFlag) {
		unsigned int i=0;
		TRACE(ulTraceFlag, _T("**Vector content**"));
		for(i=0; i<m_stdvVector.size(); i++) {
			TRACE(ulTraceFlag, szFormat, m_stdvVector[i]);
		}
		return true;
	}

	//{secret}
	bool ReplayOperations() {
		std::list<ContOp>::iterator it = m_coOperationList.begin();
		ContOp *pcoOpTmp=NULL;
		while(!m_coOperationList.empty()) {
			pcoOpTmp = m_coOperationList.back().GetPtr();
			switch(pcoOpTmp->GetOpCode()) {
				case ContOp::PUSH_BACK_OPCODE:
					m_stdvVector.push_back(pcoOpTmp->GetData());
					break;
				case ContOp::POP_BACK_OPCODE:
					m_stdvVector.pop_back();
					break;
				case ContOp::INSERT_PX_OPCODE:
					ReplayInsert(pcoOpTmp->GetPos(), pcoOpTmp->GetData());
					break;
				case ContOp::INSERT_PNX_OPCODE:
					ReplayInsert(pcoOpTmp->GetPos(), pcoOpTmp->GetRepeat(), pcoOpTmp->GetData());
					break;
				case ContOp::INSERT_PFL_OPCODE:
					//TODO
					break;
				case ContOp::ERASE_OPCODE:
					ReplayErase(pcoOpTmp->GetPos());
					break;
				case ContOp::CLEAR_OPCODE:
					m_stdvVector.clear();
					break;
				case ContOp::ASSIGN_OPCODE:
					ReplayAssign(pcoOpTmp->GetPos(), pcoOpTmp->GetData());
					break;
				default: return false;
			}
			m_coOperationList.pop_back();
		}
		return true;
	}

	//{secret}
	std::vector<Type>* GetStdVector() {
		return &m_stdvVector;
	}

private:
	std::vector<Type> m_stdvVector;
	MemberVectorIterator<Type> m_it, m_begin, m_end;

};


#endif//_MEMBERVECTOR_H_
