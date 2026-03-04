//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _UserContext_H_
#define _UserContext_H_

#include <Platform/PlatformDecl.h>

// Group = Call Contexts

/*
Summary: The UserContext class is used to pass a user-defined value.

Remarks:The user-defined value passed via the UserContext class may be either
an unsigned long, double, or pointer to an object. It is typicaly used to pass a 
value that the user wishes to retain but is not automatically retained by $PRODUCTNAME$.

For example, when a MasterIDChangeOperation event occurs the original MasterID of the 
object is not retained by $PRODUCTNAME$. However, if you wish to retain this information 
it can be passed as user-defined data before the operation begins and retrieved after the 
operation ends. 
When user-defined information is passed in the context of an operation the methods 
Operation::SetUserData and Operation::GetUserData should be used. 

See also: Operation::SetUserData, Operation::GetUserData
*/
class UserContext {	

// Group =

	public:

		//Description: Defines the type of attribute that will be passed with the
		//UserContext.
		//Remarks: The user-defined value passed via the UserContext class may be either
		//an unsigned long, a double, a bool or a pointer to an object.
		UserContext(unsigned long ulValue=0) {
			m_uContextStorage.m_ulValue=ulValue;
		}
		UserContext(double dValue) {
			m_uContextStorage.m_dValue=dValue;
		}
		UserContext(bool bValue) {
			m_uContextStorage.m_bValue=bValue;
		}
		UserContext(void* pPointer) {
			m_uContextStorage.m_pPointer=pPointer;
		}
		
		//Description: Gets the user-defined value that was set via the method
		//SetULongValue.
		//Return Value: Returns the user-defined value set via the method SetULongValue.
		//
		//Note: It is the user's responsibility to ensure that this method is used in 
		//conjunction with SetULongValue and not with one of the alternative methods
		//that take either a double, a bool or a pointer as a variable. 
		//See Also: SetULongValue
		unsigned long GetULongValue() const {return m_uContextStorage.m_ulValue;}
	
		//Description: Gets the user-defined value that was set via the method
		//SetDoubleValue.
		//Return Value: Returns the user-defined value set via the method SetDoubleValue.
		//
		//Note: It is the user's responsibility to ensure that this method is used in 
		//conjunction with SetDoubleValue and not with one of the alternative methods
		//that take either an unsigned long, a bool or a pointer as a variable. 
		//See Also: SetDoubleValue
		double GetDoubleValue() const {return m_uContextStorage.m_dValue;}
		
		//Description: Gets the user-defined value that was set via the method
		//SetBoolValue.
		//Return Value: Returns the user-defined value set via the method SetBoolValue.
		//
		//Note: It is the user's responsibility to ensure that this method is used in 
		//conjunction with SetBoolValue and not with one of the alternative methods
		//that take either an unsigned long, a double or a pointer as a variable. 
		//See Also: SetBoolValue
		bool GetBoolValue() const {return m_uContextStorage.m_bValue;}

		//Description: Gets the user-defined value that was set via the method
		//SetPointer.
		//Return Value: Returns the user-defined value set via the method SetPointer.
		//
		//Note: It is the user's responsibility to ensure that this method is used in 
		//conjunction with SetPointer and not with one of the alternative methods
		//that take either an unsigned long, a bool or a double as a variable. 
		//See Also: SetPointer
		void* GetPointer() const {return m_uContextStorage.m_pPointer;}

		//Description: Sets a user-defined value that can be obtained via the method
		//GetULongValue.
		//See Also: GetULongValue
		void SetULongValue(unsigned long ulValue) {
			m_uContextStorage.m_ulValue=ulValue;
		}
		
		//Description: Sets a user-defined value that can be obtained via the method
		//GetDoubleValue.
		//See Also: GetDoubleValue
		void SetDoubleValue(double dValue) {
			m_uContextStorage.m_dValue=dValue;
		}
		
		//Description: Sets a user-defined value that can be obtained via the method
		//GetBoolValue.
		//See Also: GetBoolValue
		void SetBoolValue(bool bValue) {
			m_uContextStorage.m_bValue=bValue;
		}
		
		//Description: Sets a user-defined value that can be obtained via the method
		//GetPointer.
		//See Also: GetPointer
		void SetPointer(void* pPointer) {
			m_uContextStorage.m_pPointer=pPointer;
		}

	private:
		
		union UserContextStorage {
			unsigned long m_ulValue;
			double m_dValue;
			bool	m_bValue;
			void* m_pPointer;
		};	

		UserContextStorage m_uContextStorage;
};

#endif

 
