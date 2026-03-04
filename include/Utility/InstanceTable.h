//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InstanceTable_H_
#define _InstanceTable_H_

#include <Utility/UtilityDecl.h>
#include <Utility/InstantiationContext.h>
#include <vector>

typedef std::vector<InstantiationContext*> ContextVector;
#define DEFAULT_CONTEXT			0
#define INVALID_CONTEXT			0xFFFF

class InstanceTable {
	public:
		InstanceTable();
		~InstanceTable();

		ICContext CreateContext();
		bool DeleteContext(ICContext icInstanceContext);

		bool AddInstance(InstanceControl* icElement, ICType icInstanceType, ICContext icInstanceContext);
		bool AddInstanceToVector(InstanceControl* icElement, ICType icInstanceType, ICContext icInstanceContext);
		void DelInstance(InstanceControl* icElement, ICType icInstanceType, ICContext icInstanceContext);
		bool DelInstanceFromVector(InstanceControl* icElement, ICType icInstanceType, ICContext icInstanceContext);
		InstanceControl* FindInstance(ICType icInstanceType, ICContext icInstanceContext);
		ICContext 	FindInstanceContext(InstanceControl* icElement, ICType icInstanceType);

		void AllocateExtraContexts(unsigned int uiNewSize);
		void FreeExtraContexts();
		
	private:
		InstantiationContext m_oDefaultContext;
		ContextVector* m_pvContextVector;
};


#endif

 
