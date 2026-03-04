//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransferRequest_H_
#define _TransferRequest_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOHandle.h>

class DOOperation;

class TransferRequest {

public:
	TransferRequest(DOHandle hToStation, double dLoadToTransfer) {
		m_hDestinationStation = hToStation;
		m_dLoadToTransfer = dLoadToTransfer;
	}

	~TransferRequest(){}

	DOHandle GetDestinationStation() {
		return m_hDestinationStation; 
	}

	double GetLoadToTransfer() {
		return m_dLoadToTransfer;
	}

private:

	DOHandle m_hDestinationStation;
	double	m_dLoadToTransfer;	
};


#endif
