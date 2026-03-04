//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ChildrenProcesses_H_
#define _ChildrenProcesses_H_

#include <Platform/PlatformDecl.h>
#include <Platform/ChildProcess.h>

// Group=Utility Subsystem

#define MAX_CHILDRENPROCESSES	64

class ChildrenProcesses {
	// Group=
	public:
		ChildrenProcesses();
		virtual ~ChildrenProcesses() {};

		unsigned long Launch(char* strCmdLine);

		unsigned long FindEmptySpot();
		ChildProcess* FindChildProcess(unsigned long ulID);
		ChildProcess* FindAnyChildProcess();

		void KillThemAll();
		void Kill(unsigned long ulID);
		unsigned long NbRunningProcesses();
		
		bool EveryoneIsRunning();
		void WaitForEveryone();
		bool EveryoneSucceeded();
		
#ifdef _TEST_ENABLED
		static bool Test();
#endif

	private:
		unsigned long m_ulMax;
		ChildProcess* m_pCP[MAX_CHILDRENPROCESSES];
};

#endif
