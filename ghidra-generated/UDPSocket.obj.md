# UDPSocket.obj.c

Комментарии с восстановленными сигнатурами функций из Ghidra:

1. `public: __thiscall UDPSocket::UDPSocket(class PRUDPTransport *)`
2. `public: __thiscall UDPSocket::~UDPSocket(void)`
3. `public: void __thiscall UDPSocket::SetCompletionEvents(class Event *,class Event *)`
4. `public: bool __thiscall UDPSocket::Bind(class PRUDPInetAddress *,unsigned short *)`
5. `public: void __thiscall UDPSocket::Queue(class PacketOut *)`
6. `public: bool __thiscall UDPSocket::Send(class PacketOut *)`
7. `public: unsigned long __thiscall UDPSocket::CompleteSend(void)`
8. `public: void __thiscall UDPSocket::Listen(void)`
9. `public: void __thiscall UDPSocket::TryIOCompletion(void)`
10. `public: class PacketIn * __thiscall UDPSocket::Recv(void)`
11. `public: unsigned long __thiscall UDPSocket::CompleteRecv(void)`
12. `public: unsigned long __thiscall UDPSocket::QueueSize(void)`
13. `public: bool __thiscall UDPSocket::InputFlooded(void)`
14. `public: bool __thiscall UDPSocket::OutputFlooded(void)`
