#ifndef _PRUDPTransportSettings_H_
#define _PRUDPTransportSettings_H_

#include <Platform/UserContext.h>

class PRUDPTransportSettings {
public:

	PRUDPTransportSettings();

	void SetDefaults();
	unsigned long SetWindowSize(unsigned long ulWindowSize);
	unsigned long GetWindowSize();
	unsigned long SetWellKnownPortNumber(unsigned long ulPortNumber);
	unsigned long GetWellKnownPortNumber();
	unsigned long SetMTU(unsigned long ulMTU);
	unsigned long GetMTU();
	unsigned long SetMaxRetransmission(unsigned long ulMaxRetransmission);
	unsigned long GetMaxRetransmission();
	unsigned long TrapICMP(bool bTrap);
	bool IsTrappingICMP();
	unsigned long SetKeepAliveTimeout(unsigned long ulTimeout);
	unsigned long GetKeepAliveTimeout();
	unsigned long SetMaxSilenceTime(unsigned long ulMaxSilenceTime);
	unsigned long GetMaxSilenceTime();
	bool IsBroadcastingEverywhere();
	unsigned long BroadcastEverywhere(bool bEverywhere);
	unsigned long GetTimeSlice();
	unsigned long SetTimeSlice(unsigned long ulTimeSlice);
	unsigned long SetOption(unsigned long ulOption, UserContext &refContext);
	unsigned long GetOption(unsigned long ulOption, UserContext &refContext);

private:

	unsigned long m_ulWellKnownPortNumber;
	unsigned long m_ulMaxRetransmission;
	bool m_bTrapICMP;
	unsigned long m_ulKeepAliveTimeout;
	unsigned long m_ulMaxSilenceTime;
	unsigned long m_ulMTU;
	unsigned long m_ulTimeSlice;
	unsigned long m_ulWindowSize;
	bool m_bBroadcastEverywhere;

};

#endif
