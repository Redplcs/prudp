// Auto-generated from PRUDPTransportSettings.obj.md
#ifndef _PRUDPTRANSPORTSETTINGS_H_
#define _PRUDPTRANSPORTSETTINGS_H_

#include <Platform/UserContext.h>



class PRUDPTransportSettings {
public:
    PRUDPTransportSettings(void);
    void SetDefaults(void);
    unsigned long SetWindowSize(unsigned long);
    unsigned long GetWindowSize(void);
    unsigned long SetWellKnownPortNumber(unsigned long);
    unsigned long GetWellKnownPortNumber(void);
    unsigned long SetMTU(unsigned long);
    unsigned long GetMTU(void);
    unsigned long SetMaxRetransmission(unsigned long);
    unsigned long GetMaxRetransmission(void);
    unsigned long TrapICMP(bool);
    bool IsTrappingICMP(void);
    unsigned long SetKeepAliveTimeout(unsigned long);
    unsigned long GetKeepAliveTimeout(void);
    unsigned long SetMaxSilenceTime(unsigned long);
    unsigned long GetMaxSilenceTime(void);
    bool IsBroadcastingEverywhere(void);
    unsigned long BroadcastEverywhere(bool);
    unsigned long GetTimeSlice(void);
    unsigned long SetTimeSlice(unsigned long);
    unsigned long SetOption(unsigned long,UserContext&);
    unsigned long GetOption(unsigned long,UserContext&);
};

#endif // _PRUDPTRANSPORTSETTINGS_H_
