//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _GENERICSELECTIONITERATOR_H_
#define _GENERICSELECTIONITERATOR_H_

class DOHandle;
#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/IteratorOverDOs.h>
#include <ObjDup/Collection.h>
class DOCtrlInterface;
class DuplicatedObject;

//Group = Miscellaneous Classes

/*
Summary:  All of the SelectionIterator instances you create inherit from this class.

Remarks:
The methods of this class can be used on any SelectionIterator instance you create.
*/
class GenericSelectionIterator : public IteratorOverDOs {
	
//Group=
	
	private:
		// {secret}
		friend DOCtrlInterface;
	
	public:
		// {secret}
		GenericSelectionIterator(Collection* pCollection, DOFilter* pFilter=NULL);
		
		// {secret}
		GenericSelectionIterator();
		// {secret}
		GenericSelectionIterator(const GenericSelectionIterator& oIt);
//Group=Operations		
		/*
		Description: Use this method to determin if the end of the GenericSelectionIterator list has been reached.
		Returns:  true if the end of the GenericSelectionIterator has been reached, false if otherwise.
		See Also: DuplicatedObject, IteratorOverDOs::GotoStart, IteratorOverDOs::GotoEnd
		*/
		virtual bool EndReached() {return m_it.EndReached();}
		
		/*
		Summary:  This operator turns the iterator element into a DuplicatedObject pointer.
		Remarks:  In order to call methods of the specific doclass (e.g. Render, doPhysic) you must either cast this pointer into 
		its appropriate doclass or use the SelectionIteratorTemplate. 
		See Also: DuplicatedObject, SelectionIteratorTemplate
		*/
		DuplicatedObject* operator->() {
			SYSTEMCHECK(m_it.GetContent()!=NULL);
			return (DuplicatedObject*) m_it.GetContent();
		}

		/*
		Description:
		This method returns a pointer to the DuplicatedObject 
		
        Returns: A pointer to the DuplicatedObject presently referenced by the iterator.  
		
		Remarks:  In order to call methods of the specific doclass (e.g. Render, doPhysic) you must either cast this pointer into 
		its appropriate doclass or use the SelectionIteratorTemplate. 
		
		See Also: DuplicatedObject, SelectionIteratorTemplate
		*/
		DuplicatedObject* GetDOPtr() {return (DuplicatedObject*) m_it.GetContent();}

		/*
		Description:
		The method returns the DOHandle of the duplicated object presently referenced by the iterator.
		
        Returns: The dohandle of the DuplicatedObject presently referenced by the iterator or
		INVALID_DOHANDLE if the call signals an error.
		
		See Also: DuplicatedObject, DOHandle
		*/
		virtual DOHandle GetHandle() {return m_it.GetHandle();}

		/*
		Description: Use this method to Find a given object in the iterator. 
		Remarks: This method moves the iterator to the given object or to the end if the object is not found.
		Returns: true if the object was found, false if not.		
		*/
		virtual bool Find(DOHandle hDO) {m_it.Find(hDO); return !EndReached();}

		//{secret}
		virtual bool Move(unsigned long ulLocation);
		//{secret}
		virtual bool IsSorted() {return true;}
		//{secret}
		virtual void Trace(unsigned long ulTraceFlag=TRACE_ALWAYS);
		//{secret}
		void AddItemWithMainRefDeleted() {
			m_it.AddItemWithMainRefDeleted();
		}

		
	protected:
		Iterator m_it;
		DOHandle m_hMinimumValidHandle;
		DOHandle m_hMaximumValidHandle;
};

#endif

#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/DOHandle.h>
