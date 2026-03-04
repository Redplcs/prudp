//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MEMBERLISTITERATOR_H_
#define _MEMBERLISTITERATOR_H_
#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/ContainerOperation.h>

//Group = Member Containers

template<class Type> class MemberList;
/*
Description:
This class offers standard C++ operators that can be performed on iterators over a MemberList.

Remarks:
Assuming that the dataset MyContainer is declared in the DDL as follows:

            dataset MyContainer {
                   list<double> lst;
            } reliable;
            
            doclass $AvatarORInformationObject$ {
                    MyContainer m_dsContainer;
            }

then to create an iterator for this container the following syntax is used:
        
           MyContainer::lstIterator it;
           
and we can now use MemberList methods manipulate the list using the created iterator:

            it = m_dsContainer.lst.Insert(it, 10.0);          

*/
template<class Type>
class MemberListIterator {
//Group = Operations
public:

/*
Description:
Creates a MemberListIterator.

Remarks:
Assuming that the dataset MyContainer is declared in the DDL as follows:

            dataset MyContainer {
                   list<double> lst;
            } reliable;
            
            doclass $AvatarORInformationObject$ {
                    MyContainer m_dsContainer;
            }

then to create an iterator for this container the following syntax is used:
        
           MyContainer::lstIterator it;

Please note that 'lstIterator' is the required name in order to specify that it is the 'lst' 
dataset member of MyContainer that we want to create the iterator for.           
*/
	MemberListIterator(){}

	MemberListIterator(const MemberListIterator<Type> &uliIterator)
	{
		m_pmlList = uliIterator.GetMemberList();
		m_pstdlList = m_pmlList->GetStdList();

		m_it=uliIterator.m_it;
		m_iPos=uliIterator.m_iPos;
	}

	//{secret}
	void Init(MemberList<Type> *pmlList) {
		m_pmlList = pmlList;
		m_pstdlList = pmlList->GetStdList();
		Begin();
	}

//{secret}
	bool IsValid() {
		return (m_iPos >=0);
	}

//{secret}
	void Invalidate() {
		m_iPos=-1;
	}
	
//{secret}
	void Begin()
	{
		m_iPos = 0;
		m_it = m_pstdlList->begin();
	}

	//{secret}
	bool Next()
	{
		if (m_it != m_pstdlList->end() && IsValid()) {
			m_it++;
			m_iPos++;
		}
		else {
			Invalidate();
		}
		return IsValid();
	}

	//{secret}
	bool Previous()
	{
		if (m_it != m_pstdlList->begin() && IsValid()) {
			m_it--;	
			m_iPos--;
		}
		else {
			Invalidate();
		}
		return IsValid();
	}

	MemberListIterator& operator++()
	{
		Next();
		return *this;
	}

	MemberListIterator& operator++(int iBid)
	{
		Next();
		return *this;
	}

	MemberListIterator& operator+(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Next();
		}
		return *this;
	}

	MemberListIterator& operator+=(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Next();
		}
		return *this;
	}


	MemberListIterator& operator-(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Previous();
		}
		return *this;
	}

	MemberListIterator& operator-=(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Previous();
		}
		return *this;
	}

	MemberListIterator& operator--()
	{
		Previous();
		return *this;
	}

	MemberListIterator& operator--(int iBid)
	{
		Previous();
		return *this;
	}

	int operator-(MemberListIterator& uli)
	{
		return 	Refresh()-uli.Refresh();
	}

	MemberListIterator& operator=(Type tElem)
	{
		*m_it = tElem;
		m_pmlList->Assign(this, tElem);
		return *this;
	}

	MemberListIterator& operator=(const MemberListIterator& uli)
	{
		m_pmlList = uli.GetMemberList();
		m_pstdlList = m_pmlList->GetStdList();
		m_it=uli.m_it;
		m_iPos=uli.m_iPos;
		return *this;
	}

	bool operator==(const MemberListIterator& It)
	{
		return (m_it == It.m_it); 
	}

	bool operator!=(const MemberListIterator& It)
	{
		return (m_it != It.m_it); 
	}

	Type& operator*() const {
		return *m_it;
	}

	Type& operator*() {
		int iPos = Refresh();
		m_pmlList->SetPendingOp(ContainerOperation<Type>::ASSIGN_OPCODE, iPos);
		return *m_it;
	}

	//{secret}
	int Refresh() {
		int iCount = 0, iCount2 = 0;
		while(m_it != m_pstdlList->begin()) {
			Previous();
			iCount++;
		}
		
		while(iCount2<iCount) {
			Next();
			iCount2++;
		}
		m_iPos = iCount;
		return m_iPos;
	}

	//{secret}
	bool SetPos(unsigned long iPos)
	{
		unsigned int i=0;
		Begin();
		for(i=0; i<=iPos; i++) {Next();}
		if (iPos != m_iPos || !IsValid()) {
			Invalidate();
			return false;
		}
		else {return true;}
	}

	//{secret}
	unsigned long GetPos()
	{
		return m_iPos;
	}

	//{secret}
	bool IncPos() {
		if(!IsValid()) {return false;}
		m_iPos++;
		return true;
	}

	//{secret}
	bool IncPos(int i) {
		if(!IsValid()) {return false;}
		m_iPos+=i;
		return true;
	}

	//{secret}
	void SetStdIterator(const typename std::list<Type>::iterator &it) {
		m_it = it;
	}

	//{secret}
	MemberList<Type>* GetMemberList() const {
		return m_pmlList;
	}

	//{secret}
	typename std::list<Type>::iterator* GetStdIterator() {
		return &m_it;
	}

private:
	typename std::list<Type>::iterator m_it;
	MemberList<Type> *m_pmlList;
	std::list<Type>			*m_pstdlList;
	unsigned long m_iPos;
};

#endif//_MEMBERLISTITERATOR_H_
