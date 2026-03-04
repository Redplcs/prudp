//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Job_H_
#define _Job_H_

#include <Utility/UtilityDecl.h>
#include <Utility/JobRoot.h>

// Group=Utility Subsystem
template<class TargetClass, class ArgumentType> class Job: public JobRoot {
	// Group=
	public:
		Job(const TCHAR* szName, TargetClass* pTargetObject,
					void (TargetClass::*pMethod)(ArgumentType arg),
					ArgumentType arg, bool bDeleteOnFinish=false,
					bool bDeleteTargetOnFinish=false): JobRoot(szName, bDeleteOnFinish) {
			m_pTargetObject=pTargetObject;
			m_bDeleteTargetOnFinish=bDeleteTargetOnFinish;
			m_pMethod=pMethod;
			m_arg = arg;
		}

		virtual ~Job() {
			if (m_bDeleteTargetOnFinish) {
				fdelete m_pTargetObject;
			}
		}

	private:

		virtual void CallObjectMethod() {
			TargetClass* pTargetObject=m_pTargetObject;
			void (TargetClass::*pMethod)(ArgumentType arg)=m_pMethod;
			(pTargetObject->*pMethod)(m_arg);
		}

	private:
		TargetClass* m_pTargetObject;
		void (TargetClass::*m_pMethod)(ArgumentType arg);
		ArgumentType m_arg;

		bool m_bDeleteTargetOnFinish;
		friend bool JobTest();
};

#ifdef _TEST_ENABLED
bool JobTest();
#endif

#endif
