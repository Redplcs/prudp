//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


// This file must have the name of the Dataset that it implements, DOHandleVector.h

#ifndef _DOHandleVector_H_
#define _DOHandleVector_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DataSet.h>
#include <ObjDup/DOHandleVectorDDL.h>

class DOHandleVector: public DATASET(DOHandleVector) {
	public:
		DOHandleVector();
		~DOHandleVector();

		void Add(DOHandle hNewDO);
		void Remove(DOHandle hDOToDel);
		bool Find(DOHandle hDO, MemberVector<DOHandle>::Iterator* pit=NULL);

        void SetCriticalSection(CriticalSection *pCS);

        CriticalSection *m_pCS;
};

#endif
