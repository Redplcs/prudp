//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _InstantiationContext_H_
#define _InstantiationContext_H_

#include <Utility/UtilityDecl.h>

class InstanceControl;

#define IC_TYPE_FACADE						0
#define IC_TYPE_APP_CTRL_INTERFACE			1
#define IC_TYPE_USER_DO_CTRL_INTERFACE		2
#define IC_TYPE_CORE_DO_CTRL_INTERFACE		3
#define IC_TYPE_DOS							4
#define IC_TYPE_LOAD_BALANCING_ACTIVITY		5
#define IC_TYPE_DUPLICATION_SPACE_TABLE		6
#define IC_TYPE_CLUSTER_CLOCK				7

#define TOTAL_INSTANCE_TYPE					8
#define INVALID_INSTANCE			(InstanceControl*)0xFFFFFFFF

typedef unsigned int ICType;
typedef unsigned int ICContext;


class InstantiationContext {
	public:
	InstantiationContext();
	InstantiationContext(InstanceControl* icElement, ICType icInstanceType);
	~InstantiationContext();

	bool AddInstance(InstanceControl* icElement, ICType icInstanceType);
	bool DelInstance(InstanceControl* icElement, ICType icInstanceType);
	InstanceControl* GetInstance(ICType icInstanceType);

	void InitContext();
	bool IsValid() {return m_IsValid;}
	
	private:
	InstanceControl* m_icInstanceContext[TOTAL_INSTANCE_TYPE];
	bool m_IsValid;
};

#endif

 
