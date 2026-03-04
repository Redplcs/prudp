//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _JobRoot_H_
#define _JobRoot_H_

#include <Utility/UtilityDecl.h>

class JobRoot {
	public:
		JobRoot(const TCHAR* szName, bool DeleteOnFinish);
		virtual ~JobRoot();

		// bool Wait(unsigned long ulTimeout=WAIT_INFINITE);

		void Launch();
		void Cancel();
		bool Launched() {return m_bLaunched;}
		bool Running() {return m_bRunning;}
		const TCHAR* GetName() {return m_szName;}
		bool DeleteOnFinish() {return m_bDeleteOnFinish;}

		bool IsCritical() {return m_bIsCritical;}
		void SetCriticalFlag() {m_bIsCritical=true;}
		void ClearCriticalFlag() {m_bIsCritical=true;}

	private:
		virtual void CallObjectMethod()=0;

	private:
		bool m_bLaunched;
		bool m_bRunning;
		bool m_bDeleteOnFinish;
		bool m_bIsCritical;

	protected:
		const TCHAR* m_szName;
};

#endif
