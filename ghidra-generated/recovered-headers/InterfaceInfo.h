// Auto-generated from InterfaceInfo.obj.md
#ifndef _INTERFACEINFO_H_
#define _INTERFACEINFO_H_


class InterfaceInfo {
public:
    InterfaceInfo(void);
    ~InterfaceInfo();
    void SetAddress(unsigned long);
    void SetBroadcastAddress(unsigned long);
    void SetMask(unsigned long);
    void SetFlags(unsigned long);
    void SetName(char*);
    bool GetAddress(char*,unsigned long);
    bool GetBroadcastAddress(char*,unsigned long);
    bool GetMask(char*,unsigned long);
    bool GetName(char*,unsigned long);
    bool GetFlags(char*,unsigned long);
    unsigned long GetAddress(void);
    unsigned long GetBroadcastAddress(void);
    unsigned long GetMask(void);
    unsigned long GetFlags(void);
    char*  GetName(void);
    void Trace(unsigned long);
private:
    bool Addr2Str(unsigned long,char*,unsigned long);
};

#endif // _INTERFACEINFO_H_
