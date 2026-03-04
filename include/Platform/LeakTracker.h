//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _LeakTracker_H_
#define _LeakTracker_H_


#ifdef UNDER_CE
#undef ENABLE_LEAK_TRACKER
#endif

#ifdef ENABLE_LEAK_TRACKER
#include <Platform/PlatformDecl.h>
#include <Platform/CriticalSection.h>
#ifdef linux
#include <new>
//#include <malloc.h>
#endif


#pragma warning(disable : 4291)

#define fnew   					new(_T(__FILE__), __LINE__)
#define fdelete		   			delete
#define ISGOODPTR(a) 			true
//#define ISGOODPTR(a) 			LeakTracker::IsGoodPtr(a)

class LeakTracker {

	class MemState;
	class MemInfo;

	public:

	    friend void *operator new(size_t size, TCHAR *file, unsigned long line);
	    friend void *operator new(size_t size);
        friend void *operator new[](size_t size, TCHAR *file, unsigned long line);
        friend void *operator new[](size_t size);
        friend void  operator delete[](void *pointer);
	    friend void  operator delete(void *pointer);

		static void *Allocate(size_t stSize, TCHAR *file, unsigned long ulLine);
		static void Deallocate(void *pPtr);

		static void Start();
		static bool Check();
		static void Stop();
		static void DumpLeaks();

		static void DumpAllocation();
		static bool IsGoodPtr(void *pPtr);

		static void AddMemInfo(MemInfo *mi);
		static MemInfo *RemoveMemInfo(void *ptr);
		static void ClearMemInfoList();
		static void MemInfoInit(MemInfo *mi, void *ptr, size_t size, TCHAR *file, unsigned long line);
		static unsigned long MemInfoGetSize(MemInfo *mi);
		static void MemInfoTrace(MemInfo *mi);

	private:
		static bool					s_bStarted;
		#ifdef WIN32
		static MemState				*s_pMemState;
		#endif
		static MemInfo 				*s_pMemInfoList;
		static unsigned long		s_ulTotalAllocationSize;
		static CriticalSection		s_hCriticalSection;
};

#else 

#define fnew   					new
#define fdelete		   			delete
#define ISGOODPTR(a) 			true

#endif


#endif
