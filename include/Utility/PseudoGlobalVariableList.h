//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PseudoGlobalVariableList_H_
#define _PseudoGlobalVariableList_H_

#include <Utility/UtilityDecl.h>
#include <Utility/InstantiationContext.h>

#define UNDEFINED_VARIABLE	0xFFFF

class PseudoGlobalVariableRoot;

class PseudoGlobalVariableList {
	public:
		PseudoGlobalVariableList();
		virtual ~PseudoGlobalVariableList();
		
		#ifdef _TEST_ENABLED
		static bool Test();
		#endif 

		static PseudoGlobalVariableRoot* GetVariable(unsigned int uiIndex);
		static unsigned int FindVariableIndex(PseudoGlobalVariableRoot* pVariable);
		static unsigned int GetNbOfVariables();
	
		void AddVariable(PseudoGlobalVariableRoot* pVariable);
		void RemoveVariable(PseudoGlobalVariableRoot* pVariable);
		void AllocateExtraContextsForAllVariables();
		void FreeExtraContextsForAllVariables();
		void ResetContextForAllVariables(ICContext icContext);

	private:
		static PseudoGlobalVariableRoot* s_pVariableListHead;
		static unsigned int m_uiNbOfVariables;
};

#endif
