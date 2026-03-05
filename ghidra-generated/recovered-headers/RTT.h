// Auto-generated from RTT.obj.md
#ifndef _RTT_H_
#define _RTT_H_


class RTT {
public:
    RTT(void);
    ~RTT();
    void Adjust(unsigned long);
    unsigned long GetRTO(void);
    unsigned long GetRTTSmoothedAvg(void);
    unsigned long GetRTTSmoothedDev(void);
    unsigned long GetLastRTT(void);
    void Trace(unsigned long);
};

#endif // _RTT_H_
