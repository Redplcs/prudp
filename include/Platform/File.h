//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _File_H_
#define _File_H_

#include <Platform/PlatformDecl.h>

#define FILE_CREATE_ALWAYS		(1<<0)
#define FILE_OPEN_EXISTING		(1<<1)
#define FILE_OPEN_ALWAYS		(1<<2)

class File {
public:

	File();
	~File();

	bool Open(TCHAR *Filename, unsigned long ulFlags, bool bExclusive=true);
	bool Close();
    bool Delete();
	unsigned long Read(void *pBuffer, unsigned long ulSize);
	unsigned long Write(void *pBuffer, unsigned long ulSize);
	bool SeekToPosition(unsigned long ulPosition);
	unsigned long GetSize();
	bool SetSize(unsigned long ulSize);

	class FindContext {
	public:
		void	*m_hFindContext;
		TCHAR 	*m_szLoadFirstDir;
		TCHAR 	*m_szFullFileName;
	};

	static FindContext *FindFirst(TCHAR *szDir);
	static bool FindNext(FindContext *pFindContext);
	static void FindClose(FindContext *pFindContext);

#ifdef _TEST_ENABLED
	static bool Test();
#endif

private:
	int      m_iFileHandle;
    TCHAR    m_szFilename[260];
};


#endif
