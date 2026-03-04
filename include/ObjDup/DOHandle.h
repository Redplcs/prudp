//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DOHandle_H_
#define _DOHandle_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOClassID.h>
#include <Plugins/Protocol/Interface/Message.h>

// Group = Miscellaneous Types and Macros

// {Secret}
#define CLASSID_BITS	10	 // 1024 Class ID...
#define OBJECTID_BITS	(32-CLASSID_BITS)

#define MAX_NB_CLASSID	(1<<CLASSID_BITS)
#define MAX_NB_OBJECTID (1<<OBJECTID_BITS)

#define MAX_NB_WELLKNOWNDO	256

#define OBJECTID_MASK	((1<<OBJECTID_BITS)-1)
#define CLASSID_MASK	(((unsigned long)-1)^OBJECTID_MASK)

// TODO: This should be moved elsewhere???

/*
Summary:  A global station identifier unique across a $PRODUCTNAME$ session.

Remarks: StationID's are not reused. When a station leaves the session, its
ID will not be used again. An implication of this is that the valid StationID is not
limited by the session size. For example, in a session with n stations, some 
stations may have an ID greater than n.
*/
typedef unsigned long StationID;



/*
Summary: This constant is used for a DOHandle that does not reference a duplicated object.

Remarks: With the use of the SelectionIteratorTemplate you can iterate methods over collections
of duplicated objects with a stop condition. When the stop condition is satisfied,
the SelectionIteratorTemplate method will return the DOHandle of the duplicated object that
the iteration with a stop condition found. 

Returns: INVALID_DOHANDLE if the iteration stop condition is never satisfied 
throughout the iteration.

See Also:  DOHandle
*/
#define INVALID_DOHANDLE DOHandle(0)

#define MAX_DOHANDLE	DOHandle((unsigned long)-1)

// Group = Miscellaneous Classes

/*
Summary:
A DOHandle refers to a local instance of a duplicated object. It is
used to execute a method on a duplicated object.  

Remarks: A DOHandle can be passed accross the network, either as an action
argument or as a dataset variable. For example, process A is
Duplication master for the duplicated object O, while process B
contains a Duplica of this object called O'. When a DOHandle on O is
passed from process A to process B, the DOHandle now refers
to the local instance of the object O'. Similarly, if B sends a
DOHandle on O' to  process A, the received DOHandle now refers to
the Duplication master O.

One important use of a DOHandle is that you can
construct a Ref out of it in order to call methods on a duplicated object.
          
See Also: DuplicatedObject::GetHandle, RefTemplate

*/
class DOHandle {
	//Group=
	public:
	
/*
Description:
Creates a DOHandle object.
		
Remarks:
If no arguments are passed to the constructor, the DOHandle instance
will initialize the value of the object to INVALID_DOHANDLE.  An optional
already existing DOHandle can be passed to the constructor as a parameter,
this will create a DOHandle that references the same object as the parameter.
 	
See Also: RefTemplate
		*/
		DOHandle(unsigned long ulValue=INVALID_DOHANDLE) {
			m_ulValue=ulValue;
		}
		DOHandle(const DOHandle& dohOther) {
			m_ulValue=dohOther.m_ulValue;
		}

		// The following operators provide an ordering of the DOHandles.
		bool operator==(const DOHandle& dohOther) const {
			return m_ulValue==dohOther.m_ulValue;
		}
		bool operator!=(const DOHandle& dohOther) const {
			return m_ulValue!=dohOther.m_ulValue;
		}
		bool operator<(const DOHandle& dohOther) const {
			return m_ulValue<dohOther.m_ulValue;
		}

		operator unsigned long() {return GetValue();}

		//{secret}
		unsigned long GetValue() const {return m_ulValue;}

		/*
		Description: Use this method to determin if an object is well-known.
		Returns: true if the duplicated object that is referenced by
		the DOHandle is a well-known object, false if it is not.
		See Also:  DDF File Syntax, WKHandle
		*/
		bool IsAWKHandle() const;
		
		//{secret}
		bool RefersToACoreDO();
		
		//{secret}
		bool RefersToAUserDO();

	public:

		// Manipulation of the handle details...
		//{secret}
		unsigned long GetObjectID() const {return m_ulValue & OBJECTID_MASK;}
		
		//{secret}
		unsigned long GetShiftedClassID() const {return m_ulValue & CLASSID_MASK;}
		
		//{secret}
		unsigned long GetClassID() const {return GetShiftedClassID()>>OBJECTID_BITS;}

		/*
		Description: Use this method to determin if an object is a member of a given class.
		Returns: true if the duplicated object that is referenced by
		the DOHandle is an instance of the specified doclass, false if it is not.

		Parameters:
		idDOCID:  The DOClassID of the duplicated object class.   

		See Also:  DuplicatedObject::IsA
		*/
		bool IsA(DOClassID idDOCID);
		
		/*
		Description: Use this method to determin if an object is a member of or inherits from a given class.
		Returns: true if the duplicated object that is referenced by the DOHandle is an instance of 
		or an instance of a child class of the specified doclass, false if it is not.

		Parameters:
		idDOCID:  The DOClassID of the duplicated object class.

		See Also:  DuplicatedObject::IsAKindOf
		*/
		bool IsAKindOf(DOClassID idDOCID);

		/*
		Description: This method returns the class name of the DuplicatedObject to which this
		handle refers, as a string.
		Returns: A string that represents the class name of the DuplicatedObject to which this 
		handle refers.
		See Also: DuplicatedObject::GetClassNameString
		*/
		const TCHAR* GetClassNameString();

		

		//{secret}
		void SetObjectID(unsigned long ulObjectID);
		//{secret}
		void SetClassID(unsigned long ulClassID);

	public:
		// Sending and receiving DOHandles.
		//{secret}
		void ExtractFrom(Message *pMessage);
		//{secret}
		void AddSourceTo(Message *pMessage, bool bCompleteUpdate=false);
		//{secret}
		void SetValue(unsigned long ulValue);

#ifdef _TEST_ENABLED
		//{secret}
		static bool Test();
#endif

	private:

		unsigned long m_ulValue;
};
//{secret}
Message& operator<<(Message &refMsg, DOHandle &refDoh);
//{secret}
Message& operator>>(Message &refMsg, DOHandle &refDoh);

//Message& operator<<(Message &msg, const DOHandle dohHandle) \
//						{ msg.AddData((void*)&((unsigned long)dohHandle), sizeof(unsigned long));	}


#endif
