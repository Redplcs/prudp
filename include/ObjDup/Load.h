//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Load_H_
#define _Load_H_

#include <ObjDup/ObjDupDecl.h>

#define LOAD_STATUS_UNKNOWN	0
#define LOAD_STATUS_LOW		1
#define LOAD_STATUS_FAIR	2
#define LOAD_STATUS_HIGH	3

#define LOADARRAY_SIZE	1
#define LOADCAT_DUPLICATIONMASTERS	0x00		// Nb of DO that the node is duplicating...

class Load {
	public:
		Load();
		Load(const Load& oLoad);
		virtual ~Load();

		Load& operator=(const Load& oLoad);

		void Trace(TCHAR* strTraceDetail=_T(""), unsigned long ulFlag=TRACE_LOADBALANCING);
		void Reset();

		void SetLoad(unsigned long ulCat, double dValue);
		double GetLoad(unsigned long ulCat);
		double* GetAllLoad();

		void SetLoadStatus(unsigned long ulCat, int iStatus, double dDesired);
		int GetLoadStatus(unsigned long ulCat);

		void LoadIncrease(unsigned long ulCat, double dValue);
		void LoadDecrease(unsigned long ulCat, double dValue) {LoadIncrease(ulCat, -dValue);}

		void LoadAdd(const Load& oLoad);
		void LoadDivide(double dFactor);

	private:
		double m_dLoad[LOADARRAY_SIZE];
		int m_iLoadStatus[LOADARRAY_SIZE];
};

#endif


