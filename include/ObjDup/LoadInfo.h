//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _LoadInfo_H_
#define _LoadInfo_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/LocalClock.h>
#include <Platform/Time.h>
#include <ObjDup/Station.h>




class LoadInfo {


	public:

	LoadInfo() {
		m_dLoad = 0.0;
		m_dCapacity = 0.0;
		m_tiResetTime = 0;
		m_dDelta=0.0;
		m_bInvolvedInEpisode = false;
		m_bReady = true;
		m_bDone = false;
	}

	~LoadInfo() {}

	LoadInfo(const LoadInfo& oInfo) {
		m_dLoad = oInfo.m_dLoad;
		m_dCapacity = oInfo.m_dCapacity;
		m_tiResetTime = oInfo.m_tiResetTime;		
		m_bInvolvedInEpisode = oInfo.m_bInvolvedInEpisode;
		m_dDelta = oInfo.m_dDelta;
		m_bReady = oInfo.m_bReady;
	}
	
	double GetLoad() {return m_dLoad;}
	double* GetLoadPtr() {return &m_dLoad;}
	void SetLoad(double dLoad) {m_dLoad = dLoad;}

	double GetOffBalanceRatio() {
		return m_dDelta/m_dCapacity;
	}
	
	double GetCapacity() {return m_dCapacity;}
	double* GetCapacityPtr() {return &m_dCapacity;}
	void SetCapacity(double dCapacity) {m_dCapacity = dCapacity;}

	Time GetResetTime() {return m_tiResetTime;}
	void SetResetTime(Time tiT) {m_tiResetTime = tiT;}

	double GetDelta() {return m_dDelta;}
	void SetDelta(double dDelta) {m_dDelta=dDelta;}
	void DecreaseDelta(double dDec) {
		m_dDelta-=dDec;
		m_dLoad-=dDec;
	}
	void IncreaseDelta(double dInc) {
		m_dDelta+=dInc;
		m_dLoad+=dInc;
	}

	void Reset(Time ti=LocalClock::GetTime()) {
		m_bReady=true;
		m_bDone=false;
	}

	bool IsReady() {
		return m_bReady;
	}

	void SetNotReady() {
		m_bReady=false;
	}
	
	bool IsDone() {
		return m_bDone;
	}

	void SetDone() {
		m_bDone=true;
	}

	void SetStationID(unsigned long ulStation) {
		m_ulStation=ulStation;
	}



	void Trace() {
		TRACE(TRACE_LOADBALANCING, _T("<Station: %x Load:%f Cap:%f, Delta:%f, ready:%d"), m_ulStation, m_dLoad, m_dCapacity, m_dDelta, IsReady());
	}


private:		
	double m_dLoad;
	double m_dCapacity;
	unsigned long m_ulStation;
	Time m_tiResetTime;
	bool m_bInvolvedInEpisode;
	double m_dDelta;
	bool m_bReady;
	bool m_bDone;
		
};


#endif
