//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _RefTemplate_H_
#define _RefTemplate_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/SystemError.h>
#include <ObjDup/DORef.h>
#include <ObjDup/DOClass.h>

// Group=Miscellaneous Classes

/*
Description:  
In $PRODUCTNAME$, the safe way to access a duplicated object is via a reference.  The 
template RefTemplate provides a safe reference to a duplicated object.

You may create a reference to a duplicated object in order to call any
of your C++ methods.  If you have a reference to an object, you can
perform actions on it just like any other C++ object.

Every duplicated object class defines a typedef to the appropriate RefTemplate.

As long as a reference to a duplicated object exists, the duplicated object pointer 
will not be invalidated by $PRODUCTNAME$.  Typically a reference would be created 
on the stack and destroyed as soon as it was no longer required. It is important to 
ensure that a reference to an object is only kept for a short period of time as an object
can not be deleted while there is still a vaild reference to it.

A reference may be created in one of 2 ways: by specifying a DOHandle to an object or by 
specifying a reference to an object. The default constructor may also be used and then an object
assigned to the reference via the assignment operator.

$ifdef NETZ$

For example, if the DOClass Sphere is defined in the DDL and hSphere is a DOHandle to a Sphere, 
then the following code provides access to the Sphere object referenced by hSphere.
     		       
        {
			Sphere::Ref refSphere(hSphere);
				if (refSphere.IsValid()){
					// Call the Sphere method SelectSound;
					refSphere->SelectSound();
					// Call the action PlaySound on all duplicas of this Sphere
					refSphere->PlaySound_OnDuplicas();	
				}
		}
     
$endif$

$ifdef TSIS$
For example, if the DOClass Dentist is defined in the DDL and hDentist is a DOHandle to a dentist, 
then the following code provides access object referenced by hDentist.
    		  
		{
			Doctor::Ref refDentist(hDentist);
				if (refDentist.IsValid()){
					// Call the Dentist method ComputeAvailability
					refDentist->ComputeAvailability();
					// Call the action DisplayAvailability on all duplicas of this Dentist
					refDentist->DisplayAvailability_OnDuplicas();
				}
		}
    		  
$endif$

See also: DuplicatedObject::Ref, DORef
*/
template<class DO> class RefTemplate: public DORef {
	// Group=
	public:
		/*
		Description: Creates a reference to a duplicated object.

		Parameters:
		hDO: DOHandle that refers to the duplicated object to which a
		reference is wanted.
		oRef: A reference to a reference of a duplicated object.

		Remarks: The method DORef::IsValid should be used to check if the reference was correctly 
		constructed.
		See Also: Duplicated Object Overview, DORef
		*/
		RefTemplate() {}
		RefTemplate(DOHandle hDO): DORef(hDO) {}
		RefTemplate(const DORef& oRef): DORef(oRef) {}
		
		~RefTemplate() {};
	
		DO* operator->() {
			if (!IsValid()) {
				return NULL;
			} else {
				return (DO*) GetDOPtr();
			}
		}

		/*
		Summary: Provides access to the duplicated object.  
		Remarks: Returns a pointer to the duplicated object of a specific doclass.  This
		pointer can safely be used to call actions or methods.
		See Also: Duplicated Object Overview, DORef
		*/
		DO* operator*() {
			if (!IsValid()) {
				return NULL;
			} else {
				return (DO*) GetDOPtr();
			}
		}

		bool IsValid(){
			if (GetDOPtr()==NULL) {				
				SIGNAL_SYSTEMERROR(SYSTEMERROR_OBJDUP_DO_NOT_FOUND, 0);
				return false;
			} else {
				if (!GetDOPtr()->GetDOClass()->IsAKindOf(DO::GetRealDOClassID())) {
					SIGNAL_SYSTEMERROR(SYSTEMERROR_OBJDUP_MISMATCHED_DOCLASS, 0);
					return false;
				}
				return true;
			}			
		}

};

#endif
