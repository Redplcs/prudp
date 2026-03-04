//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ThreadScrambler_H_
#define _ThreadScrambler_H_

#include <Platform/PlatformDecl.h>
#include <Platform/CriticalSection.h>
#include <Platform/ObjectThread.h>

#include <list>

#define MAX_NB_THREADS	256

class Task;

class ThreadScrambler {
	public:
		// These should never be called directly
		ThreadScrambler();
		~ThreadScrambler();

		void ScramblingThread(void *pVoid);

		static void CreateInstance();
		static void DeleteInstance();

		static void Register(ObjectThreadRoot *pThread);
		static void Unregister(ObjectThreadRoot *pThread);

	private:
		ObjectThread<ThreadScrambler, void*>	m_oScramblingThread;
		unsigned long			m_ulNbThreads;
		ObjectThreadRoot* 		m_aThreads[MAX_NB_THREADS];
		CriticalSection			m_csThreads;
		bool					m_bQuit;

		static ThreadScrambler 	*_Instance;
};

#endif
