//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Tokenizer_H_
#define _Tokenizer_H_


#include <Platform/PlatformDecl.h>

class Tokenizer {

public:

	Tokenizer(TCHAR *tzString, TCHAR tDelim);
	~Tokenizer();

	unsigned long	GetNbTokens();
	TCHAR* 	&operator[](const unsigned long &ulIndex);

	#ifdef _TEST_ENABLED
	static bool Test();
	#endif


private:
	void Tokenize(TCHAR *tzString, TCHAR tDelim);

protected:
	TCHAR	*m_atzToken[32];
	unsigned long	m_ulNbTokens;
};

#endif
