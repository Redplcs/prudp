//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _SessionDescription_H_
#define _SessionDescription_H_

#include <ObjDup/ObjDupDecl.h>
class Message;
class StationURL;

#define GetClusterName GetSessionName

// Group=Miscellaneous Classes

/*	
Summary: SessionDescription information includes the $gameORsession$ name, $gameORapp$ version number, 
the location ( IP address, Port ), and any additional extra information defined by the user.

Remarks:  SessionDescription information includes the $gameORsession$ name, $gameORapp$ version number, 
the location ( IP address, Port ), and any additional extra information defined by the user, 
such as the number of current users. With the $gameORapp$'s SessionDescription you can use 
$GameORBCluster$CtrlInterface::Join$GameORCluster$. Methods in the $GameORBCluster$CtrlInterface 
locate a SessionDescription ($GameORBCluster$CtrlInterface::FindLAN$GameORCluster$) or enumerate 
through all of the SessionDescriptions on a LAN ($GameORBCluster$CtrlInterface::EnumerateLAN$GameORCluster$s).
*/
class SessionDescription {

// Group =

public:
	
	//{secret}
	SessionDescription();

	//{secret}
	SessionDescription(Message *pMessage);
	
	~SessionDescription();

	// {secret}
	void Init(TCHAR *szTitle, unsigned long ulLibraryVersionNumber, unsigned long ulLibraryBuildNumber);
	// {secret}
	static SessionDescription *CreateInstance(TCHAR *szTitle, unsigned long ulNetZVersionNumber, unsigned long ulNetZBuildNumber);
	// {secret}
	static SessionDescription *Instance();
	// {secret}
	static void DeleteInstance();

	/*
	Summary:  Sets the $gameORsession$ name.  
	Remarks:  The $gameORsession$ master returns and holds this information.  
	*/
	// {secret}
	void SetGameName(TCHAR *szGameName);

	/*
	Summary:  Sets the $gameORapp$ version number.  
	Remarks:  The $gameORsession$ master returns and holds this information.
	*/
	// {secret}
	void SetGameVersionNumber(unsigned long ulVersion);

	/* 
	Summary:  Sets the custom extra information that may be implemented in a $gameORapp$ 
	and retrieved from the SessionDescription with a call to GetExtraInfo.

	Parameters:  
	pExtraInfo: A pointer to the extra information, such as number of users
	currently connected to the $gameORsession$.
	usExtraInfoLen: The length of the extra information data structure.
	
    Remarks:  The $GameORSession$ Master returns and holds this information.
	*/
	void SetExtraInfo(unsigned char *pExtraInfo, unsigned short usExtraInfoLen);


	// {secret}
	void SetStationURL(StationURL *pStationURL);

	/* 
	$ifdef NETZ$
	Summary:  Returns the title of the game as declared in the DDF file.
	
	Remarks:  Only the game master can return this information.
	$endif$

	$ifdef TSIS$
	{secret}
	$endif$
	*/
	TCHAR *GetGameTitle();
	
	/*
	$ifdef NETZ$
	Summary:  Returns the name of the game as declared upon creation with 
	GameCtrlInterface::CreateGame.
	
	Remarks: Only the game master can return this information.
    $endif$

    $ifdef TSIS$
	{secret}
	$endif$
    */
	TCHAR *GetGameName();
	
	/*
	$ifdef NETZ$
	Summary:  Returns the version number of the game as set with 
	SessionCtrlInterface::SetAuthenticationInfo
	Remarks: Only the game master can return this information.
	$endif$

	$ifdef TSIS$
	{secret}
	$endif$
	*/
	unsigned long  GetGameVersionNumber();

	/* 
	$ifdef TSIS$
	Summary:  Returns the title of the application as declared in the DDF file.

	Remarks:  Only the session master can return this information.
	$endif$

	$ifdef NETZ$
	{secret}
	$endif$
	*/
	TCHAR *GetApplicationTitle();

	/*
	$ifdef TSIS$
	Summary:  Returns the name of the session as declared upon creation
	with SessionCtrlInterface::CreateSession.

	Remarks:  Only the session master can return this information.
	$endif$

	$ifdef NETZ$
	{secret}
	$endif$
    */
	TCHAR *GetSessionName();

	/*
	$ifdef TSIS$
	Summary:  Returns the version number of the application as set with
	SessionCtrlInterface::SetAuthenticationInfo.
	
	Remarks:  Only the session master can return this information.
	$endif$
	
	$ifdef NETZ$
	{secret}
	$endif$
	*/
	unsigned long  GetApplicationVersionNumber();

	
    /*
	Summary:  Returns the extra information that was set using
	SetExtraInfo.
	
	Remarks:  Only the $gameORcluster$ master can return this information.
	*/
	void GetExtraInfo (unsigned char **pExtraInfo, unsigned short *usExtraInfoLen);
	
	// {secret}
	unsigned long GetAddress();
	
	//Summary:  Returns the IP of the $gameORsession$ with the given SessionDescription as a string.
	void GetAddressString(TCHAR *szAddress);
	
    /*
	Summary:  Returns the port number of the $gameORcluster$. 

	You can use this port number along with the IP (i.e. machine name) to use 
	$GameORCluster$CtrlInterface::Join$GameORCluster$
	*/
	unsigned short GetPort();
	
	//Summary:  Returns the URL of the $gameORsession$.
	bool GetStationURL(StationURL *pStationURL);
    
	//Summary:  Returns true if the $gameORcluster$ was linked with the $PRODUCTNAME$ unicode library.
	bool IsUnicode();
    
	//Summary:  Returns true if the $gameORcluster$ was linked with the $PRODUCTNAME$ debug library.
	bool IsDebug();

	// {secret}
	void AddSourceTo(Message *pMessage);
	// {secret}
	void ExtractFrom(Message *pMessage);

	// {secret}
	void Trace(unsigned long ulTraceFlags);

protected:
	// {secret}
	SessionDescription(TCHAR *szTitle, unsigned long ulLibraryVersionNumber, unsigned long ulLibraryBuildNumber);

	TCHAR	m_szTitle[128];
	unsigned long	m_ulLibraryVersionNumber;
	unsigned long	m_ulLibraryBuildNumber;
	TCHAR	m_szGameName[128];
	unsigned long	m_ulGameVersionNumber;
	TCHAR	m_szStationURL[128];
	bool	m_bAuthoritative;
	unsigned short	m_usExtraInfoLen;
	unsigned char	m_pExtraInfo[128];
	unsigned char	m_byLibraryTarget;

	static  SessionDescription *_Instance;
};


#endif



