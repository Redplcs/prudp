//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _CriticalSection_H_
#define _CriticalSection_H_

// Group=Utility Subsystem

class CriticalSection {
	class Attributes;

	// Group=
	public:
		CriticalSection();
		~CriticalSection();

        CriticalSection(const CriticalSection &cs);
        CriticalSection& operator=(const CriticalSection &cs);

		void Enter();
		void Leave();
	private:
		Attributes		*m_pAttr;
};

#endif
