//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _NetZ_H_
#define _NetZ_H_

#include <Products/NetZ/Facade/NetZDecl.h>
#include <Products/NetZ/Facade/Exports.h>
#include <Products/Foundation/ProductFacade.h>

class GameCtrlInterface;
class UserDOCtrlInterface;

/*
{group: NetZ Library}
{noAutoLink}

NetZ is the class that encapsulates the run time of the NetZ
system. It must be instantiated to use NetZ. Upon destruction
of this class NetZ will cease to function.
*/
class NetZ: public ProductFacade {
	public:
		NetZ(GameCtrlInterface* pGameCtrl=NULL, UserDOCtrlInterface* pDOCtrl=NULL);
		virtual ~NetZ();

		// {secret}
		// Obsolete.
		// TODO: Remove.
		GameCtrlInterface* GetGameCtrlInterface();
		// {secret}
		// Obsolete.
		// TODO: Remove.
		UserDOCtrlInterface* GetUserDOCtrlInterface();
		
		// {secret}
		unsigned long GetLocalAddress();

		// {secret}
		// Obsolete.
		bool AutomaticLoadBalancing(double dFrequency=0.1);

		// {secret}
		// Obsolete.
		bool ManualLoadBalancing();

		// {secret}
		// Obsolete.
		bool LoadBalance();

};

#endif
