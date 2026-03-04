//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _SessionDescription_H_
#define _SessionDescription_H_

#include <ObjDup/ObjDupDecl.h>
class Message;

// Group=Miscellaneous Classes

/*	
Summary: This class contains a description of the session.

Remarks: The SessionDescription information includes the application title, session name, 
the GUIDs of the compression and encryption plug-ins used, and the library version and build numbers.
The SessionDescription can be used as a parameter of the methods Session::JoinSession, 
Session::FindLANSession and Session::EnumerateLANSessions.
*/
class SessionDescription {

// Group =

public:
	
	SessionDescription();

	//{secret}
	~SessionDescription();

	//{secret}
	void Init();

	//{secret}
	void SetApplicationTitle(TCHAR *szApplicationTitle);

	//{secret}
	void SetSessionName(TCHAR *szSessionName);

	//{secret}
	void SetEncryptionGUID(TCHAR *szEncryptionGUID);

	//{secret}
	void SetCompressionGUID(TCHAR *szCompressionGUID);

	//{secret}
	void SetStationURL(TCHAR *szStationURL);

	//{secret}
	void SetLibraryVersionNumber(unsigned long ulVersionNumber, unsigned long ulBuildNumber);

	
	//Summary:  Returns the title of the application as declared in the DDF file.
	//Remarks:  Only the session master can return this information.
	TCHAR *GetApplicationTitle();
	
	/*
	Summary:  Returns the name of the session as declared upon creation with 
	Session::CreateSession.
	Remarks: Only the session master can return this information.
    */
	TCHAR *GetSessionName();
	
	//Summary:  Returns the GUID of the compression plug-in used.
	//Remarks: Only the session master can return this information.
	//See Also: Protocol::GetCompressionAlgorithm
    TCHAR *GetCompressionGUID();
	
	//Summary:  Returns the GUID of the encryption plug-in used.
	//Remarks: Only the session master can return this information.
	//See Also: Protocol::GetEncryptionAlgorithm
    TCHAR *GetEncryptionGUID();

	
	//Summary:  Returns the URL of the session.
	//See Also: StationURL
	TCHAR *GetStationURL();
    
	//Summary:  Returns the library version number of the session.
	unsigned long GetLibraryVersionNumber();

	//Summary:  Returns the library build number of the session.
	unsigned long GetLibraryBuildNumber();


	// {secret}
	bool ExtractFrom(Message *pMessage);

	// {secret}
	void AddSourceTo(Message *pMessage);

	// {secret}
	void Trace(unsigned long ulTraceFlags);

protected:

	TCHAR			m_szApplicationTitle[128];
	TCHAR			m_szSessionName[128];
	TCHAR			m_szStationURL[128];
	TCHAR			m_szCompressionGUID[128];
	TCHAR			m_szEncryptionGUID[128];
	unsigned long	m_ulLibraryVersionNumber;
	unsigned long	m_ulLibraryBuildNumber;
};


#endif



