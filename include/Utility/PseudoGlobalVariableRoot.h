//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PseudoGlobalVariableRoot_H_
#define _PseudoGlobalVariableRoot_H_

#include <Utility/UtilityDecl.h>
#include <Utility/PseudoGlobalVariableList.h>

class PseudoGlobalVariableRoot {
	public:
		PseudoGlobalVariableRoot();
		virtual ~PseudoGlobalVariableRoot();

		static void AllocateExtraContextsForAllVariables(unsigned int uiNbOfExtraContexts);
		static void FreeExtraContextsForAllVariables();
		static void ResetContextForAllVariables(ICContext icContext);
		static unsigned int GetNbOfExtraContexts();

		virtual void AllocateExtraContexts() = 0;
		virtual void FreeExtraContexts() = 0;
		virtual void ResetContext(ICContext icContext)=0;
	
		virtual PseudoGlobalVariableRoot* GetNext() = 0;
		virtual void SetNext(PseudoGlobalVariableRoot* pNextVariable) = 0;

	protected:
		static PseudoGlobalVariableList s_oList;

		PseudoGlobalVariableRoot* m_pNext;

		static unsigned int s_uiNbOfExtraContexts;
};

#endif
