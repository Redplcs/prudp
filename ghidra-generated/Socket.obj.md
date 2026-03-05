# Socket.obj.c

Комментарии с восстановленными сигнатурами функций из Ghidra:

1. `public: __thiscall Socket::Socket(unsigned long)`
2. `public: __thiscall Socket::~Socket(void)`
3. `public: bool __thiscall Socket::Open(void)`
4. `public: bool __thiscall Socket::Bind(class PRUDPInetAddress *)`
5. `public: class PRUDPInetAddress * __thiscall Socket::GetAddress(void)`
6. `public: void __thiscall Socket::Shutdown(unsigned long)`
7. `public: void __thiscall Socket::Close(void)`
8. `public: int __thiscall Socket::Send(class Buffer *,class PRUDPInetAddress *,unsigned long *,class AsyncIOContext *)`
9. `public: int __thiscall Socket::Recv(class Buffer *,class PRUDPInetAddress *,unsigned long *,class AsyncIOContext *)`
10. `public: void __thiscall Socket::TryIOCompletion(class AsyncIOContext *)`
11. `public: bool __thiscall Socket::WaitForIOCompletion(class AsyncIOContext *,unsigned long,unsigned long *)`
12. `public: unsigned long __thiscall Socket::GetIOResult(class AsyncIOContext *,unsigned long *)`
13. `public: bool __thiscall Socket::SetAsync(bool)`
14. `public: bool __thiscall Socket::SetNoDelay(bool)`
15. `public: bool __thiscall Socket::SetBuffers(void)`
16. `public: bool __thiscall Socket::ReuseAddress(bool)`
17. `public: bool __thiscall Socket::SetDebugMode(bool)`
18. `public: bool __thiscall Socket::SetBroadcastMode(bool)`
19. `public: static unsigned long __cdecl Socket::GetLastSocketError(void)`
20. `public: unsigned short __thiscall Socket::GetBoundPort(void)`
