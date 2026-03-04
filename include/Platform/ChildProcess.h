//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ChildProcess_H_
#define _ChildProcess_H_

#include <Platform/PlatformDecl.h>

// Group=Utility Subsystem

class ChildProcess {
	// Group=
	class Attributes;

	public:
		ChildProcess();
		virtual ~ChildProcess();

		bool Launch(char* strCmdLine);
		void Kill(unsigned long ulDelayAfterKill=1000);

		bool IsRunning();

		bool Wait(unsigned long ulTimeout=WAIT_INFINITE);
		unsigned long GetExitCode();
		bool HasSucceeded();

#ifdef _TEST_ENABLED
		static bool Test();
#endif

	private:
		Attributes	*m_pAttributes;
		bool m_bIsRunning;
		unsigned long m_ulExitCode;
};

#endif
