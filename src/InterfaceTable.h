#ifndef _InterfaceTable_H_
#define _InterfaceTable_H_

#include "InterfaceInfo.h"

class InterfaceTable {
public:

	InterfaceTable();
	~InterfaceTable();

	bool Query();
	unsigned long GetNbInterface();
	unsigned long GetNbLoopbackInterface();
	InterfaceInfo &operator[](unsigned long ulIndex);
	void Trace(unsigned long ulLevel);

private:

	unsigned long m_ulNbInterface;
	InterfaceInfo *m_pInterfaces;

};

#endif