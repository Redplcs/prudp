// Auto-generated from InterfaceTable.obj.md
#ifndef _INTERFACETABLE_H_
#define _INTERFACETABLE_H_


class InterfaceTable {
public:
    InterfaceTable(void);
    ~InterfaceTable();
    bool Query(void);
    unsigned long GetNbInterface(void);
    unsigned long GetNbLoopbackInterface(void);
    InterfaceInfo&  operator[](unsigned long);
    void Trace(unsigned long);
};

class InterfaceInfo {
public:
    void*  `vector deleting destructor'(unsigned int);
};

#endif // _INTERFACETABLE_H_
