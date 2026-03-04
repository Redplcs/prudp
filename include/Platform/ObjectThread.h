//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ObjectThread_H_
#define _ObjectThread_H_

#include <Platform/PlatformDecl.h>
#include <Platform/ObjectThreadRoot.h>

// Group=Utility Subsystem
template<class TargetClass, class ArgumentType> class ObjectThread: public ObjectThreadRoot {
	// Group=
	public:
		ObjectThread(TCHAR* szName): ObjectThreadRoot(szName) {
			m_pTargetObject=NULL;
			m_pMethod=NULL;
		}
		virtual ~ObjectThread() {
		}

		bool Launch(TargetClass* pTargetObject,
					void (TargetClass::*pMethod)(ArgumentType arg),
					ArgumentType arg, bool bScheduled = true) {			
			m_pTargetObject=pTargetObject;
			m_pMethod=pMethod;
			m_arg=arg;
			m_bScheduled = bScheduled;
			return ObjectThreadRoot::Launch();
		}

	private:

		virtual void CallObjectMethod() {
			//SYSTEMCHECK(m_pTargetObject!=NULL);
			//SYSTEMCHECK(m_pMethod!=NULL);
			TargetClass* pTargetObject=m_pTargetObject;
			void (TargetClass::*pMethod)(ArgumentType arg)=m_pMethod;
			ArgumentType arg=m_arg;
			ReadyToRun(); // When this is called, we cannot use any class variables anymore...
			(pTargetObject->*pMethod)(arg);
		}

	private:
		TargetClass* m_pTargetObject;
		void (TargetClass::*m_pMethod)(ArgumentType arg);
		ArgumentType m_arg;
		bool m_bScheduled;

		friend bool ObjectThreadTest();
};

#ifdef _TEST_ENABLED
bool ObjectThreadTest();
#endif

#endif
