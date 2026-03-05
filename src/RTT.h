#ifndef _RTT_H_
#define _RTT_H_

class RTT {
public:

	RTT();
	~RTT();

	void Adjust(unsigned long ulRTT);
	unsigned long GetRTO();
	unsigned long GetRTTSmoothedAvg();
	unsigned long GetRTTSmoothedDev();
	unsigned long GetLastRTT();
	void Trace(unsigned long ulLevel);

};

#endif
