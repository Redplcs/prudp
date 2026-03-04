//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PseudoSingleton_H_
#define _PseudoSingleton_H_

#include <Utility/UtilityDecl.h>
#include <Platform/ThreadVariable.h>
#include <Utility/InstantiationContext.h>
#include <Utility/InstanceControl.h>

class PseudoSingleton : public InstanceControl {
	public:
		PseudoSingleton(ICType icInstanceType);
		virtual ~PseudoSingleton();

		static bool SetContext(ICContext icNewContext);
		static void SetContextIfRequired(ICContext icNewContext);
		static ICContext GetCurrentContext();
		
		static bool UseInstantiationContext(unsigned int uiNbExtraContexts);
		static bool UseNoInstantiationContext();
		static bool UsingInstantiationContext();

	private:

#ifdef _TEST_ENABLED
		static ThreadVariable<ICContext> st_icContext;
#endif
		static bool s_bUseInstantiationContext;
};

// For the TraceOutput.
// {secret}
extern unsigned long GetCurrentContext();


#endif

