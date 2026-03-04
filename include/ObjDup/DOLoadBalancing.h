//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _DOLoadBalancing_H_
#define _DOLoadBalancing_H_
// User code...

#include "DOLoadBalancingDDL.h"

class DOLoadBalancing: public DOCLASS(DOLoadBalancing) {
	public:
		DOLoadBalancing();
		~DOLoadBalancing() {};

		double GetLocalCapacity() {return 1.0;}

		double GetLocalLoad();

		void TransferLoad(DOHandle hStation, double dLoadToTransfer);

		//Special things to do at the end of an episode
		virtual void EpisodeCompleted();

		static DOLoadBalancing::Ref GetInstance();

		virtual void DebugFunc(void *ptr) {
			TRACE(D_TRACE_DEBUG, _T("DOLoadBalancing -  domain received a local load report from station: %x*"), *((unsigned long*)ptr));
		}
		
	private:
		
};

#endif
