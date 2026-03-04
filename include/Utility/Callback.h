//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Callback_H_
#define _Callback_H_

#include <Utility/UtilityDecl.h>
#include <Utility/CallbackRoot.h>

// Group=Utility Subsystem
template<class TargetClass, class ArgumentType> class Callback: public CallbackRoot<ArgumentType> {
	// Group=
	public:
		Callback(TargetClass* pTargetObject,
				 void (TargetClass::*pMethod)(ArgumentType arg),
                 long lPriority = 0) : CallbackRoot<ArgumentType>(lPriority) {

			m_pTargetObject=pTargetObject;
			m_pMethod=pMethod;
			m_arg = NULL;
		}

		virtual ~Callback() {
		}

        void SetCallbackArgument(ArgumentType arg)
        {
			m_arg = arg;
        }

        ArgumentType GetCallbackArgument()
        {
			return m_arg;
        }

	private:

		virtual void CallObjectMethod() {
			void (TargetClass::*pMethod)(ArgumentType arg)=m_pMethod;
			(m_pTargetObject->*pMethod)(m_arg);
		}

	private:
		TargetClass* m_pTargetObject;
		void (TargetClass::*m_pMethod)(ArgumentType arg);
		ArgumentType m_arg;
};

#ifdef _TEST_ENABLED
    bool CallbackTest();
#endif


#endif
