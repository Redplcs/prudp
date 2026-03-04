//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _CallbackRoot_H_
#define _CallbackRoot_H_

#include <Utility/UtilityDecl.h>

template<class ArgumentType> class CallbackRoot {
	public:
        CallbackRoot(long lPriority) {
            m_lPriority = lPriority;
        }

        virtual ~CallbackRoot() {}

        virtual void SetCallbackArgument(ArgumentType type) = 0;
        virtual ArgumentType GetCallbackArgument() = 0;

        virtual void Call() {
        	CallObjectMethod();
        }

        long GetPriority() { return m_lPriority; }
		
	private:
		virtual void CallObjectMethod()=0;

        long m_lPriority;

};

#endif
