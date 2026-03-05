# PRUDPTransport.obj.c

Комментарии с восстановленными сигнатурами функций из Ghidra:

1. `public: __thiscall PRUDPTransport::PRUDPTransport(class Plugin *)`
2. `public: virtual void * __thiscall PRUDPTransport::`scalar deleting destructor'(unsigned int)`
3. `public: __thiscall PRUDPEndPointMap::~PRUDPEndPointMap(void)`
4. `public: virtual __thiscall PRUDPTransport::~PRUDPTransport(void)`
5. `public: virtual bool __thiscall PRUDPTransport::ResponsibleForURL(class StationURL *)`
6. `public: virtual char * __thiscall PRUDPTransport::GetType(void)`
7. `public: virtual unsigned long __thiscall PRUDPTransport::Initialize(void)`
8. `public: virtual unsigned long __thiscall PRUDPTransport::ListenOnWellKnown(void)`
9. `public: virtual unsigned long __thiscall PRUDPTransport::ListenOnArbitrary(void)`
10. `public: virtual unsigned long __thiscall PRUDPTransport::StopListenOnWellKnown(void)`
11. `public: virtual unsigned long __thiscall PRUDPTransport::StopListenOnArbitrary(void)`
12. `public: virtual class EndPoint * __thiscall PRUDPTransport::CreateEndPoint(void)`
13. `public: virtual unsigned long __thiscall PRUDPTransport::DeleteEndPoint(class EndPoint *)`
14. `public: virtual unsigned long __thiscall PRUDPTransport::SendBroadcast(class Buffer *)`
15. `public: virtual unsigned long __thiscall PRUDPTransport::SendBroadcast(class Buffer *,void (__cdecl*const)(class Transport *,class Buffer *,unsigned long,class UserContext *),class UserContext const &)`
16. `public: virtual unsigned long __thiscall PRUDPTransport::Send(class StationURL *,class Buffer *)`
17. `public: virtual unsigned long __thiscall PRUDPTransport::Send(class StationURL *,class Buffer *,void (__cdecl*const)(class Transport *,class Buffer *,unsigned long,class UserContext *),class UserContext const &)`
18. `public: virtual unsigned long __thiscall PRUDPTransport::GetNbLocalURL(void)`
19. `public: virtual class StationURL * __thiscall PRUDPTransport::GetLocalURL(unsigned long)`
20. `public: virtual class StationURL * __thiscall PRUDPTransport::GetIPURL(unsigned long,unsigned short)`
21. `public: virtual class StationURL * __thiscall PRUDPTransport::GetIPURL(char *,unsigned short)`
22. `public: virtual bool __thiscall PRUDPTransport::GetIPFromURL(class StationURL *,unsigned long *,unsigned short *)`
23. `public: virtual void __thiscall PRUDPTransport::ReleaseURL(class StationURL *)`
24. `protected: virtual unsigned long __thiscall PRUDPTransport::ConnectEndPoint(class EndPoint *,class StationURL *,class Buffer *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)`
25. `protected: virtual unsigned long __thiscall PRUDPTransport::DisconnectEndPoint(class EndPoint *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)`
26. `protected: virtual unsigned long __thiscall PRUDPTransport::SendToEndPoint(class EndPoint *,class Buffer *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)`
27. `protected: virtual bool __thiscall PRUDPTransport::IsEndPointConnected(class EndPoint *)`
28. `protected: virtual bool __thiscall PRUDPTransport::IsEndPointPeerConnected(class EndPoint *)`
29. `protected: virtual bool __thiscall PRUDPTransport::IsEndPointDisconnected(class EndPoint *)`
30. `protected: virtual bool __thiscall PRUDPTransport::IsEndPointPeerDisconnected(class EndPoint *)`
31. `protected: virtual unsigned long __thiscall PRUDPTransport::RegisterEndPointEventHandler(class EndPoint *,class EndPointEventHandler *)`
32. `protected: virtual class StationURL * __thiscall PRUDPTransport::GetEndPointStationURL(class EndPoint *)`
33. `protected: virtual unsigned long __thiscall PRUDPTransport::GetEndPointQueueSize(class EndPoint *)`
34. `protected: virtual unsigned long __thiscall PRUDPTransport::GetEndPointRTT(class EndPoint *)`
35. `protected: virtual unsigned long __thiscall PRUDPTransport::GetEndPointRTTAverage(class EndPoint *)`
36. `protected: virtual unsigned long __thiscall PRUDPTransport::SendToEndPointGroup(class EndPointGroup *,class Buffer *,void (__cdecl*const *)(class EndPointGroup *,class Buffer *,class UserContext *),class UserContext const &,unsigned long)`
37. `public: virtual bool __thiscall PRUDPTransport::IsCapable(unsigned long)`
38. `public: virtual unsigned long __thiscall PRUDPTransport::SetOption(unsigned long,class UserContext &)`
39. `public: virtual unsigned long __thiscall PRUDPTransport::GetOption(unsigned long,class UserContext &)`
40. `private: void __thiscall PRUDPTransport::StartEventListener(void)`
41. `public: void __thiscall PRUDPTransport::SetHighPrio(void)`
42. `private: bool __thiscall PRUDPTransport::UDPListen(unsigned long,unsigned short)`
43. `private: bool __thiscall PRUDPTransport::StopUDPListen(unsigned long)`
44. `private: bool __thiscall PRUDPTransport::ICMPListen(unsigned long,unsigned short)`
45. `private: bool __thiscall PRUDPTransport::StopICMPListen(unsigned long)`
46. `private: bool __thiscall PRUDPTransport::RegisterEndPoint(class PRUDPEndPoint *)`
47. `private: void __thiscall PRUDPTransport::UnregisterEndPoint(class PRUDPEndPoint *)`
48. `private: void __thiscall PRUDPTransport::SendReset(unsigned long,class PRUDPInetAddress *)`
49. `private: class PRUDPEndPoint * __thiscall PRUDPTransport::ServiceConnectionRequest(class PRUDPInetAddress *,class Buffer *,unsigned long)`
50. `private: void __thiscall PRUDPTransport::ServiceUserMsg(class PRUDPInetAddress *,class Buffer *)`
51. `private: void __thiscall PRUDPTransport::DemuxIncomingPacket(unsigned long)`
52. `private: void __thiscall PRUDPTransport::CompleteICMP(class ICMPSocket *)`
53. `private: bool __thiscall PRUDPTransport::Send(unsigned long,class PacketOut *)`
54. `private: class TimeoutManager * __thiscall PRUDPTransport::GetTimeoutManager(void)`
55. `private: void __thiscall PRUDPTransport::TimeSliceHandler(void)`
56. `private: class UDPSocket * __thiscall PRUDPTransport::GetSocket(unsigned char)`
57. `private: unsigned short __thiscall PRUDPTransport::GetPortNumber(unsigned long)`
58. `private: class PRUDPTransportSettings * __thiscall PRUDPTransport::GetSettings(void)`
59. `public: void __thiscall PRUDPTransport::TraceProto(char *,class Packet *,class PRUDPInetAddress *,class PRUDPInetAddress *,unsigned long)`
60. `public: __thiscall std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >::~list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >(void)`
61. `public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::erase(class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator)`
62. `public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::erase(class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator,class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator)`
63. `public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::find(__int64 const &)`
64. `public: class std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >::erase(class std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >::iterator)`
65. `public: struct std::pair<class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator,bool> __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::insert(struct std::pair<__int64 const ,class PRUDPEndPoint *> const &)`
66. `public: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::lower_bound(__int64 const &)`
67. `protected: void __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Erase(struct std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Node *)`
68. `public: void __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::const_iterator::_Inc(void)`
69. `public: class std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::list<class PRUDPEndPoint *,class std::allocator<class PRUDPEndPoint *> >::iterator::operator++(int)`
70. `protected: class std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::iterator __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Insert(struct std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Node *,struct std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Node *,struct std::pair<__int64 const ,class PRUDPEndPoint *> const &)`
71. `protected: struct std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Node * __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Lbound(__int64 const &)const`
72. `public: void __thiscall std::_Tree<__int64,struct std::pair<__int64 const ,class PRUDPEndPoint *>,struct std::map<__int64,class PRUDPEndPoint *,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::_Kfn,struct std::less<__int64>,class std::allocator<class PRUDPEndPoint *> >::const_iterator::_Dec(void)`
