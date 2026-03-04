//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InstanceControl_H_
#define _InstanceControl_H_

#include <Utility/UtilityDecl.h>
#include <Utility/InstantiationContext.h>
#include <Utility/InstanceTable.h>

class InstanceControl {
	public:
		InstanceControl(ICType icInstanceType, ICContext icInstanceContext);
		virtual ~InstanceControl();

	#ifdef _TEST_ENABLED
		static bool Test();
	#endif
		
		void SetDelegatorInstance(void*);
		void* GetDelegatorInstance();

		// InstanceTable static functions
		static void AllocateExtraContexts(unsigned int uiNewSize);
		static void FreeExtraContexts();

		static ICContext CreateContext();
		static bool DeleteContext(ICContext icInstanceContext);

		static InstanceControl* FindInstance(ICType icInstanceType, ICContext icInstanceContext);
		static ICContext FindInstanceContext(InstanceControl* icElement, ICType icInstanceType);

		bool IsValid() const {return m_bIsValid;}
		
	protected:
		static InstanceTable s_oInstanceTable;

		ICContext m_icInstanceContext;
		ICType m_icInstanceType;
		void* m_pDelegatorInstance;
		bool 	m_bIsValid;
};


#endif
