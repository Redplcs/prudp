//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ObjectThreadRoot_H_
#define _ObjectThreadRoot_H_

#include <Platform/PlatformDecl.h>
#include <Platform/AtomicValue.h>

#define PRIORITY_LOW			0
#define PRIORITY_NORMAL			1
#define PRIORITY_HIGH			2
// For the TraceOutput.
extern TCHAR* GetThreadName();
class ObjectThreadRoot {

    class Handle;

	public:
		ObjectThreadRoot(TCHAR* szName);
		virtual ~ObjectThreadRoot();

		static ObjectThreadRoot* GetInstance();

		bool Wait(unsigned long ulTimeout=WAIT_INFINITE);

		static unsigned long NbRunningThreads() {return s_avRunningThreads.Get();}
		unsigned int GetThreadId() { return m_uiThreadID; }

		void SetPriority(unsigned long ulPriority); 
		bool Launched() {return m_bLaunched;}

		static unsigned int GetCurrentThreadID();

		static TCHAR* GetThreadName();
        void SetThreadName(TCHAR *szName);
TCHAR* m_szName;
	protected:

		bool Launch();
		void ReadyToRun();

		
	private:
		#ifndef UNDER_CE
		friend unsigned int STDCALL ObjectThreadProc(void *lpParameter);
		#else
		friend unsigned long STDCALL ObjectThreadProc(void *lpParameter);
		#endif		
		
		void Wrapper();
		virtual void CallObjectMethod()=0;

	private:
		Handle		 *m_pHandle;
		unsigned int m_uiThreadID;

		bool m_bLaunched;
		bool m_bRunning;
		bool m_bFinished;

		

		static AtomicValue s_avRunningThreads;
};



#endif
