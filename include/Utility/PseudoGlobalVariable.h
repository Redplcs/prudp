//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PseudoGlobalVariable_H_
#define _PseudoGlobalVariable_H_

#include <Utility/PseudoGlobalVariableRoot.h>
#include <Utility/PseudoSingleton.h>

#include <Utility/UtilityDecl.h>

template <class T> 
class PseudoGlobalVariable : public PseudoGlobalVariableRoot {
	public:
		PseudoGlobalVariable(const T& oDefaultValue = T()) 
		{
			m_oDefaultValue = oDefaultValue;
			m_oValueInDefaultContext = m_oDefaultValue;
			m_pValueInContextList = NULL;
			
			s_oList.AddVariable((PseudoGlobalVariableRoot*)this);

			// If the size has been specified, we can allocate contexts. Else, we will allocate it when it will be specified later
			if(s_uiNbOfExtraContexts > 1) {
				AllocateExtraContexts();
			}
		}


		virtual ~PseudoGlobalVariable()
		{
			s_oList.RemoveVariable((PseudoGlobalVariableRoot*)this);
			
			FreeExtraContexts();
		}

		PseudoGlobalVariable<T>& operator=(T oValue) {
			SetValue(GetCurrentContext(), oValue);
			return *this;
		}

		operator T() {
			return GetValue(GetCurrentContext());
		}

		// All pseudo global and pseudo singleton share the same
		// context.
		ICContext GetCurrentContext() {
			return PseudoSingleton::GetCurrentContext();
		}

		void SetValue(ICContext icInstanceContext, T oValue)
		{
			SYSTEMCHECK(icInstanceContext < s_uiNbOfExtraContexts);

			// Index are used like in InstanceTable, 
			// Element 0 is m_oValueInDefaultContext, 
			// Element 1 is m_pValueInContextList[1], Element 2 is m_pValueInContextList[2] ...
			if(icInstanceContext == 0) {
				m_oValueInDefaultContext = oValue;
			}
			else {
				SYSTEMCHECK(m_pValueInContextList != NULL);
				m_pValueInContextList[icInstanceContext] = oValue;
			}
		}


		T GetValue(ICContext icInstanceContext)
		{
			SYSTEMCHECK(icInstanceContext < s_uiNbOfExtraContexts);

			if(icInstanceContext == 0) {
				return m_oValueInDefaultContext;
			}
			else {
				SYSTEMCHECK(m_pValueInContextList != NULL);
				return m_pValueInContextList[icInstanceContext];
			}
		}

		T* GetValuePtr(ICContext icInstanceContext)
		{
			SYSTEMCHECK(icInstanceContext < s_uiNbOfExtraContexts);

			if(icInstanceContext == 0) {
				return &m_oValueInDefaultContext;
			}
			else {
				SYSTEMCHECK(m_pValueInContextList != NULL);
				return &m_pValueInContextList[icInstanceContext];
			}
		}

		void AllocateExtraContexts()
		{
			unsigned int cnt;
			m_pValueInContextList = fnew T[s_uiNbOfExtraContexts];
			for(cnt=0; cnt<s_uiNbOfExtraContexts; cnt++) {
				m_pValueInContextList[cnt] = m_oDefaultValue;
			}
		}


		void FreeExtraContexts()
		{
			if(m_pValueInContextList != NULL) {
				fdelete []m_pValueInContextList;
				m_pValueInContextList = NULL;
			}
		}

		virtual void ResetContext(ICContext icContext)
		{
			SYSTEMCHECK(icContext<s_uiNbOfExtraContexts);
			m_pValueInContextList[icContext] = m_oDefaultValue;
		}


		PseudoGlobalVariableRoot* GetNext()
		{
			return m_pNext;
		}


		void SetNext(PseudoGlobalVariableRoot* pVariable)
		{
			m_pNext = pVariable;
		}

	private:
		T* m_pValueInContextList;
		T m_oValueInDefaultContext;

		T m_oDefaultValue;
};

#endif
