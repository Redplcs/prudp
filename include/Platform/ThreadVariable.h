//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ThreadVariable_H_
#define _ThreadVariable_H_

#include <Platform/PlatformDecl.h>
#include <Platform/ObjectThread.h>
#include <Platform/ScopedCS.h>
#include <map>
#include <list>

class ThreadVariableRoot {
	public:
		ThreadVariableRoot();
		~ThreadVariableRoot();
		virtual void ResetValues()=0;
		virtual void ClearValue()=0;
		unsigned long GetThreadID();
};

	

template<class VariableType> class ThreadVariable: public ThreadVariableRoot {
	public:
		ThreadVariable(VariableType oInitialValue) {
			m_oInitialValue=oInitialValue;
		}

		~ThreadVariable() {
			ResetValues();
		}

		void ResetValues() {
			ScopedCS oCS(m_csValues);
			std::map<unsigned long, VariableType>::iterator it;
			while (m_mapValues.size()!=0) {
				it=m_mapValues.begin();
				m_mapValues.erase(it);
			}
		}

		void ClearValue() {
			ScopedCS oCS(m_csValues);
			std::map<unsigned long, VariableType>::iterator it;
			it = m_mapValues.find(GetThreadID());
			if (it != m_mapValues.end()) {
				m_mapValues.erase(it);
			}
		}

		ThreadVariable& operator=(const VariableType& oValue) {
			ScopedCS oCS(m_csValues);
			m_mapValues[GetThreadID()]=oValue;
			return *this;
		}

		operator VariableType() {
			ScopedCS oCS(m_csValues);
			if (m_mapValues.find(GetThreadID())==m_mapValues.end()) {
				return m_oInitialValue;
			} else {
				return m_mapValues[GetThreadID()];
			}
		}		

	private:

		VariableType m_oInitialValue;
		CriticalSection m_csValues;
		std::map<unsigned long, VariableType> m_mapValues;
};

template<class VariableType> void ResetThreadVariable(VariableType& oVar) {};
template<class VariableType> void ResetThreadVariable(ThreadVariable<VariableType>& oVar) {
	oVar.ResetValues();
};


class ThreadVariableList {
public:
	ThreadVariableList();
	~ThreadVariableList();

	static ThreadVariableList& GetInstanceRef();

	void ResetValues();
	void ClearValue();
	void AddVariable(ThreadVariableRoot *pThreadVariable);
	void RemoveVariable(ThreadVariableRoot *pThreadVariable);

private:

	std::list<ThreadVariableRoot*> 	m_tvList;
	CriticalSection m_csList;
};


#ifdef _TEST_ENABLED
bool ThreadVariableTest();
#endif


#endif
