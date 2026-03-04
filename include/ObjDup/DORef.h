//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _DORef_H_
#define _DORef_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOHandle.h>
class Message;
class DuplicatedObject;

// Group=Miscellaneous Classes

#ifdef _DEBUG_CHECK
class DuplicatedObjectStore;
#endif


/*
Description: Duplicated objects can be accessed via references which are implemented
via the RefTemplate.
Remarks: References are implemented via a template that is detailed under RefTemplate.

See Also: RefTemplate
*/
class DORef {
	// Group=
	public:
		
		/*
		Description: Creates a reference to a duplicated object.

		Parameters:
		hDO: A DOHandle that refers to the duplicated object to which a
		reference is wanted.
		oRef: A reference to a duplicated object. 

		Remarks: The method IsValid should be used to check if the reference was correctly constructed. 
		See Also: Duplicated Object Overview, RefTemplate
		*/
		DORef();
		DORef(DOHandle hDO);
		DORef(const DORef& oRef);
		
		~DORef();
				
		DORef& operator=(const DORef& oRef);

		// Summary: Returns the DOHandle used to construct this reference.
		// See Also: Duplicated Object Overview, RefTemplate
		DOHandle GetHandle() const;


		/*
		Summary: Indicates if the object was constructed correctly.
		Returns: true if the reference construction is valid, false if otherwise. 
		Remarks: This method will return false if you pass a reference or a DOHandle to an invalid or 
		unknown object or to an object of the wrong type. The possible errors that will be returned 
		are SYSTEMERROR_OBJDUP_DO_NOT_FOUND and SYSTEMERROR_GEN_INVALID_OPERATION. If you create a 
		reference by specifying a DOHandle to the object the error SYSTEMERROR_OBJDUP_MISMATCHED_DOCLASS
		is also possible.
		See Also: Duplicated Object Overview, RefTemplate
		*/
		bool IsValid() const {
			return GetDOPtr()!=NULL;
		}

		//Description: Use this method to check if a reference is valid.
		//Returns: true if the DORef is valid, false if it is not.
		//See Also: Wait
		bool Poll();
		
		/*
		Description: Use this method to continually check for a specified length of time if the 
		reference is valid.
		Returns: true if the DORef is valid, false if it is not or the timeout is exceeded.
		See Also: Poll
		*/
		bool Wait(unsigned long ulTimeout=WAIT_INFINITE);

#ifdef _TEST_ENABLED
		//{secret}
		static bool Test(DOClassID idTestObjectClass);
#endif

	public:
		// TODO: Should be protected.

		// {secret}
		DuplicatedObject* GetDOPtr() const;
		// {secret}
		void Release();

	protected:
		
		void Acquire();

	private:

		DuplicatedObject* m_poReferencedDO;
		DOHandle m_hReferencedDO;
#ifdef _DEBUG_CHECK
		DuplicatedObjectStore* m_poStore;
#endif
};

#endif
