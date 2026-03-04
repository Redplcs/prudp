//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _UpdateContextMap_H_
#define _UpdateContextMap_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/UpdateContext.h>
#include <ObjDup/DOHandle.h>
#include <map>

// An UpdateContextMap maps a <DOID, dataset index> to an UpdateContext.
// Every Station contains an update context map.

class UpdateContextMap {
	public:
		UpdateContextMap();
		~UpdateContextMap();

		void Create(DOHandle idDO, unsigned long ulDataSetIndex, UpdateContext* pNewContext);
		void Delete(DOHandle idDO, unsigned long ulDataSetIndex);
		UpdateContext* Find(DOHandle idDO, unsigned long ulDataSetIndex);

	private:

		_LONGLONG CreateKey(DOHandle idDO, unsigned long ulDataSetIndex);

	private:
		std::map<_LONGLONG, UpdateContext*> m_mapUC;

#ifdef _TEST_ENABLED
	public:
		static bool Test();		
#endif
};

#endif


