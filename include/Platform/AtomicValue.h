//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _AtomicValue_H_
#define _AtomicValue_H_

#include <Platform/PlatformDecl.h>
#include <Platform/CriticalSection.h>

class AtomicValue {
	public:
		AtomicValue() {m_ulValue=0;}
		AtomicValue(unsigned long ulValue) {m_ulValue=ulValue;}
		~AtomicValue() {};

		unsigned long Get() {return m_ulValue;}
		void Set(unsigned long ulValue) {
			m_cs.Enter();
			m_ulValue=ulValue;
			m_cs.Leave();
		}
		unsigned long GetAndSet(unsigned long ulValue) {
			m_cs.Enter();
			unsigned long ulResult=m_ulValue;
			m_ulValue=ulValue;
			m_cs.Leave();
			return ulResult;
		}
		unsigned long TestAndSet() {return GetAndSet(1);}
		unsigned long operator=(unsigned long ulValue) {Set(ulValue); return ulValue;}
		operator unsigned long() {return Get();}
		// Prefix form...
		unsigned long operator++() {
			m_cs.Enter();
			unsigned long ulResult=++m_ulValue;
			m_cs.Leave();
			return ulResult;
		}
		// Postfix form
		unsigned long operator++(int iDummy) {
			m_cs.Enter();
			unsigned long ulResult=m_ulValue++;
			m_cs.Leave();
			return ulResult;
		}
		// Prefix form...
		unsigned long operator--() {
			m_cs.Enter();
			unsigned long ulResult=--m_ulValue;
			m_cs.Leave();
			return ulResult;
		}
		// Postfix form
		unsigned long operator--(int iDummy) {
			m_cs.Enter();
			unsigned long ulResult=m_ulValue--;
			m_cs.Leave();
			return ulResult;
		}

#ifdef _TEST_ENABLED
		// {Secret}
		static bool Test();
#endif

	private:
		unsigned long m_ulValue;
		CriticalSection m_cs;
};

#endif
