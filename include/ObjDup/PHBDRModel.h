//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PHBDRModel_H_
#define _PHBDRModel_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/UpdateContext.h>
#include <ObjDup/PHBDRVar.h>
#include <Platform/Time.h>
class Message;


class PHBDRModel: public UpdateContext {
	public:
		
		PHBDRModel() {}
		~PHBDRModel() {}

		void SetModel(int& v, double dValue, double dRateOfChange, double dAcceleration, Time tTimestamp=SessionClock::GetTime());

		int GetValue(const PHBDRParameters& oParams, PHBDRVAR(int)& v);
		double GetValue(const PHBDRParameters& oParams, PHBDRVAR(double)& v);
		float GetValue(const PHBDRParameters& oParams, PHBDRVAR(float)& v);

		double ComputeESE(const PHBDRParameters& oParams, int rv, PHBDRVAR(int)& ev);
		double ComputeESE(const PHBDRParameters& oParams, double rv, PHBDRVAR(double)& ev);
		double ComputeESE(const PHBDRParameters& oParams, float rv, PHBDRVAR(float)& ev);

		void AddSourceTo(Message* pMsg);

		TimeInterval CurrentUpdateDelay();
		const PHBDRTimeVector& GetTimeVector() const;

	protected: 

		PHBDRTimeVector	m_vectorTime;
};

#endif
