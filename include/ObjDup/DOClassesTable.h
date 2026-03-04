//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DOClassesTable_H_
#define _DOClassesTable_H_

// Group=Object Duplication Subsystem

class DOClass;

class DOClassesTable {
	// Group=
	public:
		DOClassesTable();
		~DOClassesTable();

		static DOClassesTable* GetDOClassesTable();
		static void TearDownDOClassesTable();

		void RegisterDOClass(unsigned long ulClassID, DOClass* pDOClass);

		DOClass* FindDOClass(unsigned long ulClassID);
		
		unsigned long GetCurrentSize() { return m_ulCurrentSize; }

		DOClass* GetDOClassByIndex(unsigned long ulIndex);

		void SetObjectIDInitialRanges();
		void CreateObjectIDFactories();
		
		unsigned long GetNbDOClasses();
		unsigned long GetLastClassID();

	private:
		unsigned long m_ulCurrentSize;
		DOClass** m_ppTable;
		// Variable used to implement the singleton...
		static DOClassesTable* s_poTheTable;
};

#endif
