//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _NetZSpecifics_H_
#define _NetZSpecifics_H_

#include <Products/NetZ/Facade/NetZDecl.h>

#include <Products/Foundation/ProductSpecifics.h>

class NetZSpecifics: public ProductSpecifics {
	public:
		NetZSpecifics();
		virtual ~NetZSpecifics();

		virtual unsigned long GetProductID();
		virtual SessionCtrlInterface* CreateSessionCtrlInterface();
};

#endif
