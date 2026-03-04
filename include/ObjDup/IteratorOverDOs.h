//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _IteratorOverDOs_H_
#define _IteratorOverDOs_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOFilter.h>

#define IT_MOVE_START	0
#define IT_MOVE_END		1
#define IT_MOVE_NEXT	2


//Group=Miscellaneous Classes

/*
Summary:  Instances of this class are used to iterate methods over subsets of the duplicated objects on the station.
Remarks:  SelectionIterator instances inherit methods from GenericSelectionIterator class.
See Also:  GenericSelectionIterator
*/
class IteratorOverDOs {
//Group=
	public: 

		// {Secret}
		IteratorOverDOs(DOFilter* pFilter=NULL);
		// {Secret}
		IteratorOverDOs(const IteratorOverDOs& oIt);
		virtual ~IteratorOverDOs() {};
//Group=Operations
		/*
		Summary:  Forces the iterator's instance pointer to the 
		first duplicated object in the iterator.
		See Also:  GenericSelectionIterator::EndReached, GotoEnd, Count
		*/
		void GotoStart();

		/*
		Summary:  Forces the iterator's instance pointer to point
		to the last duplicated object of the iterator.
		See Also:  GenericSelectionIterator::EndReached, GotoStart, Count
		*/
		void GotoEnd();

		/*
		Summary: Returns the number of duplicated objects in the iterator.
		Returns: The number of duplicated objects in the iterator as an unsigned int.
		Remarks:
		For example,

		      //the following creates a Selection Iterator of $AvatarORInformationObject$ duplicas
		      $AvatarORInformationObject$::SelectionIterator itDup$AvatarORInformationObject$(DUPLICA);
		      //return the number of $AvatarORInformationObject$ duplicas:
		      return (itDup$AvatarORInformationObject$.Count());

		See Also:  GenericSelectionIterator::EndReached, GenericSelectionIterator
		*/
		unsigned int Count(); 

		/*
		Summary:  Advances the GenericSelectionIterator's instance pointer to the next
		duplicated object in the iterator.
		See Also:  GenericSelectionIterator::EndReached, Count, GenericSelectionIterator
		*/
		IteratorOverDOs& operator++() {AdvanceToValidItem(false); return *this;}
		IteratorOverDOs& operator++(int iDummy) {AdvanceToValidItem(false); return *this;}

		//{secret}
		virtual DOHandle GetHandle()=0;
		
		//{secret}
		virtual bool EndReached()=0;

		//{secret}
		void AdvanceToValidItem(bool bCurrentItemIsFine);
		//{secret}
		void SetCreationContext(void* pCreationContext);
		//{secret}
		void* GetCreationContext();

		// {Secret}
		virtual bool IsSorted()=0;

		//{secret}
		virtual void Trace(unsigned long ulTraceFlag=TRACE_ALWAYS)=0;

		//{secret}
		virtual bool Find(DOHandle hDO);
		
		//{secret}
		// TODO.  Clean this up.  It should not be required.
		virtual void AddItemWithMainRefDeleted() {}
		
	protected:

		//{secret}
		virtual bool Move(unsigned long ulLocation)=0;
		DOFilter* m_pFilter;

	private:
		// This context is used to release the iterator.
		//{secret}
		void* m_pCreationContext;
		
};

#endif
