//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Observer_H_
#define _Observer_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOHandle.h>
#include <Platform/CriticalSection.h>
class DuplicatedObjectStore;
class Station;

// {Secret}
class Observer {
	public:
		Observer(Station *pStation);
		~Observer();

        /*
		void RegisterObserver(DOHandle dohObserver);
		void UnregisterObserver();

		bool GetObserverHandle(DOHandle* pdohObserver);
        bool Observer::IsRegistered();
        */

        // Compute distance method
		double GetDistanceTo(DOHandle dohDO);

		void UpdateDistanceIfRequired();
		void UpdateDistance();

	protected:

	private:
		CriticalSection m_csObserver;

        Station *m_pStation;

		double m_dDistance;
		DOHandle m_dohFrom;
		DOHandle m_dohTo;
		Time m_tUpdateTime;

		static Time s_tMaximumUpdateDelay;
};

#endif

