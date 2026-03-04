//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _MainWrapper_H_
#define _MainWrapper_H_

#include <Platform/PlatformImpl.h>

#ifdef UNDER_CE
#ifdef DEBUG_TO_FILE
#define MAIN_WRAPPER(USERMAIN)																\
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int CmdShow) {	\
    TraceOutput::GetInstance()->SelectFileDevice();\
    TRACE(TRACE_ALWAYS,_T("Args = %s"),lpCmdLine);\
	unsigned long argc; TCHAR *argv[16]; Tokenizer oTokenizer(lpCmdLine,_T(' '));						\
	argv[0]=_T("");																				\
	for (argc=0;argc<oTokenizer.GetNbTokens();argc++) {argv[argc+1]=oTokenizer[argc];}			\
	exit(USERMAIN(argc+1, argv));																\
    return 0; /* To get rid of a warning. */														\
}
#else
#define MAIN_WRAPPER(USERMAIN)																\
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int CmdShow) {	\
    TraceOutput::GetInstance()->SelectDebugOutputDevice();\
    TRACE(TRACE_ALWAYS,_T("Args = %s"),lpCmdLine);\
	unsigned long argc; TCHAR *argv[16]; Tokenizer oTokenizer(lpCmdLine,_T(' '));						\
	argv[0]=_T("");																				\
	for (argc=0;argc<oTokenizer.GetNbTokens();argc++) {argv[argc+1]=oTokenizer[argc];}			\
	exit(USERMAIN(argc+1, argv));																\
    return 0; /* To get rid of a warning. */														\
}
#endif
#else
#define MAIN_WRAPPER(USERMAIN)	int __CDECL _tmain(int argc, TCHAR** argv) {return USERMAIN(argc, argv);}
#endif	

#ifdef UNDER_CE
#ifdef DEBUG_TO_FILE
#define CHILDPROCESS_MAIN_WRAPPER(USERMAIN)														\
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int CmdShow) {	\
    TraceOutput::GetInstance()->SelectFileDevice();\
	unsigned long argc; TCHAR *argv[16]; Tokenizer oTokenizer(lpCmdLine,_T(' '));						\
	argv[0]=_T("");																				\
	for (argc=0;argc<oTokenizer.GetNbTokens();argc++) {argv[argc+1]=oTokenizer[argc];}			\
	ExitThread(USERMAIN(argc+1, argv));															\
    return 0;																					\
}
#else
#define CHILDPROCESS_MAIN_WRAPPER(USERMAIN)														\
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int CmdShow) {	\
    TraceOutput::GetInstance()->SelectDebugOutputDevice();\
	unsigned long argc; TCHAR *argv[16]; Tokenizer oTokenizer(lpCmdLine,_T(' '));						\
	argv[0]=_T("");																				\
	for (argc=0;argc<oTokenizer.GetNbTokens();argc++) {argv[argc+1]=oTokenizer[argc];}			\
	ExitThread(USERMAIN(argc+1, argv));															\
    return 0;																					\
}
#endif
#else
#define CHILDPROCESS_MAIN_WRAPPER(USERMAIN)	MAIN_WRAPPER(USERMAIN)
#endif	

#endif
