# PRUDPEndPoint.obj.c

Комментарии с восстановленными сигнатурами функций из Ghidra:

1. `public: __thiscall PRUDPEndPoint::PRUDPEndPoint(class Transport *,unsigned long)`
2. `public: __thiscall PRUDPEndPoint::~PRUDPEndPoint(void)`
3. `public: unsigned long __thiscall PRUDPEndPoint::Connect(class StationURL *,class Buffer *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)`
4. `public: unsigned long __thiscall PRUDPEndPoint::Disconnect(void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)`
5. `public: unsigned long __thiscall PRUDPEndPoint::Send(class Buffer *,void (__cdecl*const)(class EndPoint *,class Buffer *,unsigned long,class UserContext *),class UserContext const &,unsigned long)`
6. `public: bool __thiscall PRUDPEndPoint::IsConnected(void)`
7. `public: bool __thiscall PRUDPEndPoint::IsDisconnected(void)`
8. `public: unsigned long __thiscall PRUDPEndPoint::GetQueueSize(void)`
9. `public: unsigned long __thiscall PRUDPEndPoint::GetNbReliablePending(void)`
10. `public: class StationURL * __thiscall PRUDPEndPoint::GetStationURL(void)`
11. `private: bool __thiscall PRUDPEndPoint::Send(class PacketOut *)`
12. `private: void __thiscall PRUDPEndPoint::SendNextReliable(void)`
13. `private: void __thiscall PRUDPEndPoint::SendReliable(class PacketOut *)`
14. `private: class PacketIn * __thiscall PRUDPEndPoint::GetNextDispatchPacket(void)`
15. `private: void __thiscall PRUDPEndPoint::Dispatch(class PacketIn *,class Time)`
16. `private: void __thiscall PRUDPEndPoint::SignalFaultEvent(unsigned long)`
17. `private: void __thiscall PRUDPEndPoint::ServiceIncomingPacket(class PacketIn *)`
18. `private: void __thiscall PRUDPEndPoint::PacketAcknowledged(class Packet *)`
19. `private: void __thiscall PRUDPEndPoint::ServiceTimeout(class PacketOut *)`
20. `private: void __thiscall PRUDPEndPoint::CancelPacketTimeout(class PacketOut *)`
21. `private: void __thiscall PRUDPEndPoint::StartPing(void)`
22. `private: void __thiscall PRUDPEndPoint::StopPing(void)`
23. `private: void __thiscall PRUDPEndPoint::TimeToPing(void)`
24. `private: void __thiscall PRUDPEndPoint::SetState(enum PRUDPEndPoint::_ConnectionState)`
25. `private: void __thiscall PRUDPEndPoint::GetStringState(char *)`
26. `private: void __thiscall PRUDPEndPoint::TraceState(unsigned long)`
27. `private: bool __thiscall PRUDPEndPoint::ReadyToDisconnect(void)`
28. `private: bool __thiscall PRUDPEndPoint::IsNotConnected(void)`
29. `private: bool __thiscall PRUDPEndPoint::IsConnecting(void)`
30. `private: bool __thiscall PRUDPEndPoint::IsDisconnecting(void)`
31. `private: bool __thiscall PRUDPEndPoint::IsPeerFlooded(void)`
32. `public: bool __thiscall PRUDPEndPoint::IsPeerConnected(void)`
33. `public: bool __thiscall PRUDPEndPoint::IsPeerDisconnected(void)`
34. `private: void __thiscall PRUDPEndPoint::SetPeerFlooded(bool)`
35. `private: void __thiscall PRUDPEndPoint::SetPeerDisconnected(bool)`
36. `private: void __thiscall PRUDPEndPoint::SetPeerConnected(bool)`
37. `private: unsigned long __thiscall PRUDPEndPoint::GetAssociatedSocket(void)`
38. `private: class RTT * __thiscall PRUDPEndPoint::GetRTT(void)`
39. `private: void __thiscall PRUDPEndPoint::SetSocket(unsigned long)`
40. `private: bool __thiscall PRUDPEndPoint::IsIdle(void)`
41. `private: void __thiscall PRUDPEndPoint::SetPRUDPInetAddress(class PRUDPInetAddress *)`
42. `private: class PRUDPInetAddress * __thiscall PRUDPEndPoint::GetPRUDPInetAddress(void)`
43. `private: bool __thiscall PRUDPEndPoint::IsFlooded(void)`
44. `private: class PRUDPTransport * __thiscall PRUDPEndPoint::GetTransport(void)`
