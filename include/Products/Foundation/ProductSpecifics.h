//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ProductSpecifics_H_
#define _ProductSpecifics_H_

#include <Products/Foundation/FacadesDecl.h>
class SessionCtrlInterface;

class ProductSpecifics {
	public:
		ProductSpecifics();
		virtual ~ProductSpecifics();

		virtual unsigned long GetProductID()=0;
		virtual SessionCtrlInterface* CreateSessionCtrlInterface();
};

#endif
