// Auto-generated from PRUDPInetAddress.obj.md
#ifndef _PRUDPINETADDRESS_H_
#define _PRUDPINETADDRESS_H_

#include <Plugins/Transport/Interface/StationURL.h>



class PRUDPInetAddress {
public:
    PRUDPInetAddress(void);
    PRUDPInetAddress(PRUDPInetAddress*);
    PRUDPInetAddress(PRUDPInetAddress&);
    PRUDPInetAddress(unsigned long,unsigned short);
    ~PRUDPInetAddress();
    bool SetFromURL(StationURL*,unsigned short);
    bool GetURL(StationURL*);
    bool SetAddress(char*);
    sockaddr*  GetSockAddr(void);
    void SetAddress(unsigned long);
    unsigned long GetAddress(void);
    void SetPortNumber(unsigned short);
    unsigned short GetPort(void);
    long long GetKey(void);
    bool operator<(PRUDPInetAddress) const;
    bool operator==(PRUDPInetAddress) const;
    PRUDPInetAddress&  operator=(PRUDPInetAddress&);
    void Trace(unsigned long);
    void ToStr(char*);
private:
    void SetAddress(void*);
};

#endif // _PRUDPINETADDRESS_H_
