//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MEMBERCONTAINER_H_
#define _MEMBERCONTAINER_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/ContainerOperation.h>
#include <list>
#include <vector>
#include <queue>

#define OPERATIONS 0
#define CONTENT	1

//group=Member Containers

/*
Description:
$PRODUCTNAME$ allows for the association of a vector, list, or queue as a dataset member.

Remarks:
The containers used in $PRODUCTNAME$ function in a very similar manner to the containers of the 
C++ standard library.  The types of containers used in $PRODUCTNAME$ are vector, list, and queue.   
In $PRODUCTNAME$, the methods available to perform standard operations such as
remove, add, insert, and iterate over the dataset members of a container are found 
in the classes MemberVector, MemberList, and MemberQueue. When declared in the DDL, 
a container must specify that updates are sent over a reliable channel and they cannot specify 
the use of an extrapolation filter. For example, the dataset class MyContainer, which contains 
three containers and is associated to the duplicated object class $AvatarORInformationObject$, 
would be defined in the DDL according to DDL File Syntax as follows:

         dataset MyContainer {
                vector<double> vec;
                list<dohandle> lst;
                queue<int> que;
        } reliable;

        doclass $AvatarORInformationObject$ {
                MyContainer m_dsContainer;
        };

To perform operations on these dataset containers access the relevant duplicated object instance of the
$AvatarORInformationObject$'s dataset (m_dsContainer) and use the methods of MemberVector, MemberList, and MemberQueue.

See Also:  DDL File Syntax, MemberList, MemberVector, MemberQueue, MemberListIterator, MemberVectorIterator        
*/
template<class Type>
class MemberContainer {

		//{secret}
	typedef ContainerOperation<Type> ContOp;
public :
		//{secret}
	MemberContainer()
	{
		ClearStatus();
	}

	//{secret}
	~MemberContainer()
	{
		while(!m_coOperationList.empty()) {
			m_coOperationList.pop_front();	
		}
	}

	/*
	Description: Sets the update of a container to content mode.
	Remarks: When this mode is set, each time the method DuplicatedObject::Update is
	called the total content of the container is updated on each Duplica.  
 	See Also: SetOperationUpdate
	*/
	void SetContentUpdate() {
		m_bReplayable = false;
	}
	
	/*
	Description: Sets the update of a container to operation mode.
	Remarks: When this mode is set, each time the method DuplicatedObject::Update is
	called the operations that were performed since the last calll to DuplicatedObject::Update
	are sent to and reapplied on the Duplica.
	
	Note: It is the user's responsibility to ensure that data is accessed 
	via standard container operations so that the operation can be reapplied 
	on the Duplica.
	
	See Also: SetContentUpdate
	*/
	void SetOperationUpdate() {
		m_bReplayable = true;
	}
	
	//{secret}
	void ClearPendingOp() {
		m_bPendingOp = ContOp::NOP_OPCODE;
		m_iPendingOpIndex = -1;
	}
	//{secret}
	void ClearStatus() {
		m_bReplayable = true;
		m_bPendingOp = ContOp::NOP_OPCODE;
	}
	
	//{secret}
	void ClearOperations() {
		m_coOperationList.clear();
	}

	//{secret}
	virtual void TrapSpecificOperationSideEffect(){}
	
	//{secret}
	virtual bool ReplayOperations(){return true;}

	//{secret}
	virtual std::list<ContOp>* GetOperationsList() {
		return &m_coOperationList;
	}

	//{secret}
	virtual bool Small() {return false;}

	//{secret}
	virtual void AddContentToMsg(Message *pMsg){};
	//{secret}
	virtual void ExtractContentFromMsg(Message *pMsg){};

	//{secret}
	virtual void AddOperationsToMsg(Message *pMsg) {
		std::list<ContOp> olTmp = m_coOperationList;
		unsigned int uiSize = m_coOperationList.size();
		*pMsg << uiSize;

		while(!m_coOperationList.empty()) {
			m_coOperationList.back().AddSourceTo(pMsg);
			m_coOperationList.pop_back();
		}
	}
	//{secret}
	void SetPendingOp(unsigned char bOpCode, int iIndex) {
		m_bPendingOp = bOpCode;
		m_iPendingOpIndex = iIndex;
	}
	
	//{secret}
	virtual bool TrapLastOperationSideEffect(){return true;} 

	//{secret}
	virtual void ExtractOperationsFromMsg(Message *pMsg) {
		ContOp coTmp;
		unsigned int uiNbOp=0;
		pMsg->Extract(&uiNbOp);
		m_coOperationList.clear();
		while(uiNbOp>0) {
			coTmp.ExtractFrom(pMsg);
			m_coOperationList.push_front(coTmp);
			uiNbOp--;
		}
	}

	//{secret}
	virtual void AddSourceTo(Message *pMsg, bool bDiscovery=false) {
		if (Small() || bDiscovery) {
			m_bReplayable = false; 
		}
		if(m_bReplayable) {
			TrapLastOperationSideEffect();
			*pMsg << (unsigned char) OPERATIONS;
			AddOperationsToMsg(pMsg);
		}
		else {
			*pMsg << (unsigned char) CONTENT;
			AddContentToMsg(pMsg);
			ClearOperations();
		}
		if(!bDiscovery) {
			ClearStatus();
		}
		else {
			ClearPendingOp();
		}
	}

	//{secret}
	virtual void ExtractFrom(Message *pMsg) {
		unsigned char bDataType=0;
		pMsg->Extract(&bDataType);
		switch(bDataType) {
			case OPERATIONS:
				ExtractOperationsFromMsg(pMsg);
				ReplayOperations();
				break;
			case CONTENT:
				ExtractContentFromMsg(pMsg);
				break;
		}
	}

	//{secret}
	bool TraceOperations(TCHAR* szFormat, unsigned long ulTraceFlag) {
		std::list<ContOp>::iterator it = m_coOperationList.end();
		TRACE(ulTraceFlag, _T("Tracing operations : "));
		while(it != m_coOperationList.begin()) {
			it--;
			(*it).Trace(szFormat, ulTraceFlag);
		}
		return true;
	}

protected:
	//{secret}
	int AddOperation(ContOp cOp)
	{
		m_coOperationList.push_front(cOp);
		return 0;
	}

	//{secret}
	std::list<ContOp> m_coOperationList;
	//{secret}
	bool m_bReplayable;
	//{secret}
	unsigned char m_bPendingOp;
	//{secret}
	int m_iPendingOpIndex;
};

#endif//_MEMBERCONTAINER_H_
