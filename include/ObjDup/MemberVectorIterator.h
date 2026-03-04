//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MEMBERVECTORITERATOR_H_
#define _MEMBERVECTORITERATOR_H_
#include <ObjDup/ObjDupDecl.h>

//Group = Member Containers

template<class Type> class MemberVector;

/*
Description:
This class offers standard C++ operators that can be performed on iterators over a MemberVector.

Remarks:
Assuming that the dataset MyContainer is declared in the DDL as follows:

        dataset MyContainer{
                   vector<double> vec;
        } reliable;

then to create an iterator for this container the following syntax is used:
        
        MyContainer::vecIterator it;

*/
template<class Type>
class MemberVectorIterator {
//Group = Operations
public:

/*
Description:
Creates a MemberListIterator.

Remarks:
Assuming that the dataset MyContainer is declared in the DDL as follows:

            dataset MyContainer {
                   vector<double> vec;
            } reliable;
            
            doclass $AvatarORInformationObject$ {
                    MyContainer m_dsContainer;
            }

then to create an iterator for this container the following syntax is used:
        
           MyContainer::vecIterator it;

Please note that 'vecIterator' is the required name in order to specify that it is the 'vec' 
dataset member of MyContainer that we want to create the iterator for.           


*/
	MemberVectorIterator(){}

	MemberVectorIterator(const MemberVectorIterator<Type> &uviIterator)
	{
		m_pmvVector = uviIterator.GetMemberVector();
		m_pstdvVector = m_pmvVector->GetStdVector();
		m_it=uviIterator.m_it;
		m_iPos=uviIterator.m_iPos;
	}

	//{secret}
	void Init(MemberVector<Type> *pmvVector) {
		m_pmvVector = pmvVector;
		m_pstdvVector = pmvVector->GetStdVector();
		Begin();
	}

	//{secret}
	bool IsValid() {
		return (m_iPos>=0);
	}

	//{secret}
	void Invalidate() {
		m_iPos = -1;
	}

	//{secret}
	void Begin()
	{
		m_iPos = 0;
		m_it = m_pstdvVector->begin();
		m_iPos=-1;
	}

	//{secret}
	bool Next()
	{
		if (m_it != m_pstdvVector->end() && IsValid()) {
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
		if (m_it != m_pstdvVector->begin() && IsValid()) {
			m_it--;	
			m_iPos--;
		}
		else {
			Invalidate();
		}
		return IsValid();
	}

	MemberVectorIterator& operator++()
	{
		Next();
		return *this;
	}

	MemberVectorIterator& operator++(int iBid)
	{
		Next();
		return *this;
	}

	MemberVectorIterator& operator--()
	{
		Previous();
		return *this;
	}

	MemberVectorIterator& operator--(int iBid)
	{
		Previous();
		return *this;
	}

	MemberVectorIterator& operator+(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Next();
		}
		return *this;
	}

	MemberVectorIterator& operator+=(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Next();
		}
		return *this;
	}

	MemberVectorIterator& operator-(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Previous();
		}
		return *this;
	}

	MemberVectorIterator& operator-=(int iInc)
	{
		int i=0;
		for(i=0; i<iInc; i++) {
			Previous();
		}
		return *this;
	}

	int operator-(MemberVectorIterator& uvi)
	{
		return 	Refresh()-uvi.Refresh();
	}

	//std::vector<Type>& operator (std::vector<Type>)() {
	//	return it;
	//}

	MemberVectorIterator& operator=(Type tElem)
	{
		*m_it = tElem;
		m_pmvVector->Assign(this, tElem);
		return *this;
	}

	MemberVectorIterator& operator=(MemberVectorIterator& uvi)
	{
		m_pmvVector = uvi.GetMemberVector();
		m_pstdvVector = m_pmvVector->GetStdVector();
		m_it=uvi.m_it;
		m_iPos=uvi.m_iPos;
		return *this;
	}

	bool operator==(const MemberVectorIterator& It)
	{
		return (m_it == It.m_it); 
	}

	bool operator!=(const MemberVectorIterator& It)
	{
		return (m_it != It.m_it); 
	}

	Type& operator*() const {
		return *m_it;
	}

	Type& operator*() {
		int iPos = Refresh();
		m_pmvVector->SetPendingOp(ContainerOperation<Type>::BRACKET_OPCODE, iPos);
		return *m_it;
	}

	//{secret}
	int Refresh() {
		int iCount = 0, iCount2 = 0;
		while(m_it != m_pstdvVector->begin()) {
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
	void SetStdIterator(typename std::vector<Type>::iterator it) {
		m_it = it;
	}

	//{secret}
	MemberVector<Type>* GetMemberVector() const {
		return m_pmvVector;
	}

	//{secret}
	typename std::vector<Type>::iterator* GetStdIterator() {
		return &m_it;
	}

private:
	typename std::vector<Type>::iterator m_it;
	MemberVector<Type> *m_pmvVector;
	std::vector<Type>			*m_pstdvVector;
	unsigned long m_iPos;
};

#endif//_MEMBERVECTORITERATOR_H_
