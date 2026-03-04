//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOHandle.h>
class DuplicatedObject;
#include <ObjDup/Store.h>

#ifndef _SelectionByProperty_H_
#define _SelectionByProperty_H_

// Group=Miscellaneous Types and Macros

// Summary:  Before a DuplicatedObject is initialized its property is unknown.
#define PROPERTY_UNKNOWN	((unsigned long)-1)

// {Secret}
#define PROPERTY_NONE		((unsigned long)-2)

// Group=Object Duplication Subsystem
// {Secret}
class SelectionByProperty {
	// Group=
	public:
		SelectionByProperty();
		~SelectionByProperty();

		void Create(unsigned long ulNbProperties, unsigned char ucFlags);

		bool SetProperty(DOHandle id, unsigned long ulProperty);
		bool ChangeProperty(DOHandle id, unsigned long ulSpecifiedPreviousProperty, unsigned long ulNewProperty);
		
		unsigned long GetProperty(DOHandle id);
		bool HasProperty(DOHandle id);
		
		Selection* GetSelection(unsigned long ulProperty);
		
#ifdef _TEST_ENABLED
		// {Secret}
		// Called by Integration, SingleProcess test.
		static bool Test(DOHandle hTestObjectA, DOHandle hTestObjectB);
#endif
			
	private:
		Selection** m_ppSelection;
		unsigned long m_ulNbProperties;
};

#endif

#include <ObjDup/DuplicatedObject.h>
