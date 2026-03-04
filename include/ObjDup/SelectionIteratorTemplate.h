//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _SELECTIONITERATORTEMPLATE_H_
#define _SELECTIONITERATORTEMPLATE_H_

#include <ObjDup/ObjDupImpl.h>
#include <ObjDup/GenericSelectionIterator.h>
#include <ObjDup/UserDOCtrlInterface.h>
#include <ObjDup/DuplicatedObjectStore.h>
#include <ObjDup/DOFilters.h>

// Group=Miscellaneous Classes

/*
Description:
Use this template to create a SelectionIterator for a specific doclass.

Remarks:
It is possible to create a SelectionIterator that holds all of the duplicated objects
of a certain class on a station via the following:

	     Sphere::SelectionIterator itALLSphere;
	
It is also possible to create a SelectionIterator that holds all of the DUPLICA or
DUPLICATION_MASTER instances of a given doclass on the local station.
For example, assuming that the Sphere doclass was declared in the DDL file, to create a 
Sphere SelectionIterator that holds all of the DUPLICATION_MASTER Spheres on a station the
following is used:

 	      Sphere::SelectionIterator itDMSphere (DUPLICATION_MASTER);
	      itDMSphere.GotoStart(); 
        	      while(! (itDMSphere.EndReached())){ 
         	                        itDMSphere->DoPhysic(); 
        	                        itDMSphere++; 
        	      }
  
*/
template<class DO> class SelectionIteratorTemplate: public GenericSelectionIterator {
	// Group=
	public:

		
		SelectionIteratorTemplate()
			: GenericSelectionIterator((Collection*) DuplicatedObjectStore::GetInstance(), 
			  m_pFilter = new IsAKindOfDOFilter(DO::GetRealDOClassID()))
		{
			//GotoStart();
		}

		SelectionIteratorTemplate(unsigned int uiSelectionType) 
			: GenericSelectionIterator(UserDOCtrlInterface::GetInstance()->
			  GetAssociatedDOS()->GetDOSBP().GetSBP(SBP_DUPLICATION)->GetSelection(uiSelectionType), 
			  m_pFilter = new IsAKindOfDOFilter(DO::GetRealDOClassID()))
			  
		{
			//GotoStart();
		}

		virtual ~SelectionIteratorTemplate() { delete m_pFilter;}
	
		
		/*
		Description:  Creates a copy of a SelectionIterator over a collection of duplicated objects.
		
		Remarks:  Refer to SelectionIteratorTemplate for basic examples.  
		If you do not know whether a SelectionIterator holds duplicas, duplication masters, or both and
		you need to iterate to check all of the objects against all others, e.g. for collisions, you can
		create a copy of the SelectionIterator in the following way:
		
		        bool CheckSphereCollisions(SelectionIteratorTemplate &itSphere){
		        	itSphere.GotoStart();
		        	//create a copy of the parameter
		        	Sphere::SelectionIterator itSphereCopy (itSphere);
		        	while (!itSphere.EndReached()){
		        		itSphereCopy.GotoStart();
		        		while (!itSphereCopy.EndReached()){
		        			
		        			//Check for collision..
		        			
		        			itSphereCopy++;
		        		}
		        		itSphere++;
		        	}	
		        }	
		
		Parameters:
		SelectionIteratorTemplate:  An existing SelectionIterator
		which in effect creates a copy of the specified SelectionIterator.
		*/
		SelectionIteratorTemplate(const SelectionIteratorTemplate& oIt) : GenericSelectionIterator(oIt) {
			GotoStart();
		}


		/*
		Description: Returns a pointer to a DuplicatedObject of a specific class.
		
		Remarks:  Refer to SelectionIteratorTemplate for an example.                 
       	*/
		DO* operator->() {return (DO*)m_it.GetContent();}

		/*
		Description: Returns a pointer to a DuplicatedObject of a specific class.

        Remarks:  Refer to SelectionIteratorTemplate for an example.                 
        */
		DO* GetDOPtr() {return (DO*)m_it.GetContent();}
};



#endif//_SELECTIONITERATORTEMPLATE_H_
