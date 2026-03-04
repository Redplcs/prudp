//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _StaticArrayIterator_H_
#define _StaticArrayIterator_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/IteratorOverDOs.h>
#include <ObjDup/DOHandle.h>

class StaticArrayIterator: public IteratorOverDOs {
	public: 

		StaticArrayIterator(DOHandle hSingleDOHandle);
		StaticArrayIterator(DOHandle* phDOArray, int iSize);
		StaticArrayIterator(const StaticArrayIterator& oIt);
		virtual ~StaticArrayIterator();

		virtual bool EndReached();
		virtual DOHandle GetHandle();
		virtual bool Move(unsigned long ulLocation);

		virtual bool IsSorted();
		virtual void Trace(unsigned long ulTraceFlag=TRACE_ALWAYS);

#ifdef _TEST_ENABLED
		static bool Test();
#endif

	private:
		void MoveToStart();
		void MoveToEnd();
		bool MoveToNext();

	private:
		DOHandle* m_phDOArray;
		
		int m_iPos;
		int m_iSize;
		bool m_bIsSorted;
};

#endif
