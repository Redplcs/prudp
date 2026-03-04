//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DOFilters_H_
#define _DOFilters_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOFilter.h>

// Only let CoreDO pass.
class CoreDOFilter: public DOFilter {
	public:
		CoreDOFilter() {}
		virtual ~CoreDOFilter() {}

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
};

// Only let UserDO pass.
class UserDOFilter: public DOFilter {
	public:
		UserDOFilter() {}
		virtual ~UserDOFilter() {}

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
};

// Only let some DO pass, based on ClassID.
class IsADOFilter: public DOFilter {
	public:
		IsADOFilter(DOClassID idDOCID);
		virtual ~IsADOFilter() {}

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
		
		virtual DOHandle GetMinimumValidHandle();
		virtual DOHandle GetMaximumValidHandle();

	private:
		DOClassID m_idDOCID;
};

// Only let some DO pass, based on being ans instance 
//of a subclass.
class IsAKindOfDOFilter: public DOFilter {
	public:
		IsAKindOfDOFilter(DOClassID idDOCID);
		virtual ~IsAKindOfDOFilter() {}

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);

		virtual DOHandle GetMinimumValidHandle();
		virtual DOHandle GetMaximumValidHandle();

	private:
		DOClassID m_idDOCID;
};

class ConstantDOFilter: public DOFilter {
	public:
		// If true, all DO pass through, if false, all are blocked.
		ConstantDOFilter(bool bDesiredAnswer);
		virtual ~ConstantDOFilter() {};

		virtual bool Filter(DuplicatedObject* pDO) {return m_bDesiredAnswer;}
		virtual bool Filter(DOHandle hDO) {return m_bDesiredAnswer;}

		virtual DOHandle GetMaximumValidHandle();

	private:
		bool m_bDesiredAnswer;
};

class OrDOFilter: public DOFilter {
	public:
		OrDOFilter(DOFilter *pfFilter1, DOFilter *pfFilter2);
		virtual ~OrDOFilter();

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);

		virtual DOHandle GetMinimumValidHandle();
		virtual DOHandle GetMaximumValidHandle();
	
	#ifdef _TEST_ENABLED
		static bool Test();
	#endif
	private:
	DOFilter *m_pfFilter1, *m_pfFilter2;
};

class AndDOFilter: public DOFilter {
	public:
		AndDOFilter(DOFilter *pfFilter1, DOFilter *pfFilter2);
		virtual ~AndDOFilter();

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);

		virtual DOHandle GetMinimumValidHandle();
		virtual DOHandle GetMaximumValidHandle();
	
	private:
	DOFilter *m_pfFilter1, *m_pfFilter2;
};

class NotDOFilter: public DOFilter {
	public:
		NotDOFilter(DOFilter *pfFilter1);
		virtual ~NotDOFilter();

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
	
	private:
	DOFilter *m_pfFilter1;
};


class IsADuplicationMasterDOFilter: public DOFilter {
	public:
		IsADuplicationMasterDOFilter();
		virtual ~IsADuplicationMasterDOFilter();

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
	private:
};

class IsADuplicaDOFilter: public DOFilter {
	public:
		IsADuplicaDOFilter();
		virtual ~IsADuplicaDOFilter();

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
	private:
};

class IsAWellKnownDOFilter: public DOFilter {
	public:
		IsAWellKnownDOFilter(bool bIsOrIsNot);
		virtual ~IsAWellKnownDOFilter();

		virtual bool Filter(DuplicatedObject* pDO);
		virtual bool Filter(DOHandle hDO);
	private:
        bool m_bIsOrIsNot;
};

#endif //_DOFilters_H_

