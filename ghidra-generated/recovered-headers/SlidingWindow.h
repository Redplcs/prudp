// Auto-generated from SlidingWindow.obj.md
#ifndef _SLIDINGWINDOW_H_
#define _SLIDINGWINDOW_H_

#include "PacketOut.h"



class SlidingWindow {
public:
    SlidingWindow(unsigned short);
    ~SlidingWindow();
    void Purge(void);
    void Push(PacketOut*);
    void Acknowledged(unsigned long);
    PacketOut*  GetNextToSend(void);
    PacketOut*  GetPacket(unsigned long);
    bool ReadyToSend(void);
    bool Empty(void);
    std::Tree<unsigned long,std::pair<unsigned long const,PacketOut* >,std::map<unsigned long,PacketOut*,std::less<unsigned long>,std::allocator<PacketOut* > >::_Kfn,std::less<unsigned long>,std::allocator<PacketOut* > >::iterator AcquireIterator(void);
    PacketOut*  GetPacket(std::Tree<unsigned long,std::pair<unsigned long const,PacketOut* >,std::map<unsigned long,PacketOut*,std::less<unsigned long>,std::allocator<PacketOut* > >::_Kfn,std::less<unsigned long>,std::allocator<PacketOut* > >::iterator);
    void ReleaseIterator(void);
    bool DataPending(void);
    unsigned long NbDataPending(void);
    void Trace(void);
};

#endif // _SLIDINGWINDOW_H_
