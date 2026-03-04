//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MulticastGroupLoadBalancing_H_
#define _MulticastGroupLoadBalancing_H_
// User code...

#include "MulticastGroupLoadBalancingDDL.h"

class MulticastGroupLoadBalancing: public DOCLASS(MulticastGroupLoadBalancing) {
	public:
		MulticastGroupLoadBalancing();
		~MulticastGroupLoadBalancing() {};

		double GetLocalCapacity() {return 0.0;}

		double GetLocalLoad();

		void TransferLoad(DOHandle hStation, double dLoadToTransfer);

		//Special things to do at the end of an episode
		virtual void EpisodeCompleted();

		static MulticastGroupLoadBalancing::Ref GetInstance();

		virtual void DebugFunc(void *ptr) {
			TRACE(D_TRACE_DEBUG, _T("******MulticastGroup load balancing domain received a local load report from station: %x******"), *((unsigned long*)ptr));
		}
		
	private:
		
};

#endif
