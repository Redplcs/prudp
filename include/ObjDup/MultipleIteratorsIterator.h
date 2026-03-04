//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MultipleIteratorsIterator_H_
#define _MultipleIteratorsIterator_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/IteratorOverDOs.h>
#include <ObjDup/DOHandle.h>

class MultipleIteratorsIterator: public IteratorOverDOs {
	public: 

		MultipleIteratorsIterator(int iNbIterators);
		MultipleIteratorsIterator(const MultipleIteratorsIterator& oIt);
		virtual ~MultipleIteratorsIterator();

		void SetIterator(int iIndex, IteratorOverDOs* pIterator, bool bDeleteIt=false);
		IteratorOverDOs* GetIterator(int iIndex);

		virtual bool EndReached();

		virtual DOHandle GetHandle();

		virtual bool IsSorted() {return true;}

		virtual bool Find(DOHandle hDO);

		virtual void Trace(unsigned long ulTraceFlag);

	private:
		virtual bool Move(unsigned long ulLocation);
		bool Advance();
		void SelectLowestValue();

		DOHandle m_hCurrentValue;
		int m_iNbIterators;
		IteratorOverDOs** m_ppIterators;
		bool* m_aDeleteIterator;
};

#endif
