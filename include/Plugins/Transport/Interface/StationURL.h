//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _StationURL_H_
#define _StationURL_H_

#include <Plugins/Transport/Interface/TransportDecl.h>

#define URL_TYPE_DELIMITER			_T(":/")
#define URL_PARAM_DELIMITER			_T(";")
#define URL_USER_PARAM_DELIMITER	_T("#")
#define URL_TAG_ASSIGN				_T("=")

//Group=Plug-ins

//Description: Use this class to construct a station URL.  
//Remarks: This class is used to construct a station URL.  
class StationURL {

	//{secret}
	class Param;
	friend class Param;

public:
//Group=
	/*
	Description: Constructs a station URL.
	Remarks: 
	*/
	StationURL(TCHAR *szURL);
	StationURL();
	StationURL(const StationURL &oStationURL);
	
	~StationURL();

	/*
	Description: Use this method to set the URL of a station.
	See Also: GetURL
	*/
	void   SetURL(TCHAR *szURL);
	
	/*
	Description: Use this method to return the station URL.
	Returns: The station URL set via SetURL.
	See Also: SetURL
	*/
	TCHAR *GetURL();

	//Description: Use this method to return the transport type specified in the URL.
	//Returns: The transport type specified in the URL.
	unsigned long GetTransportType(TCHAR *szTransportType, unsigned long ulSize);

	//{secret}
	unsigned long  GetParamValue(TCHAR* szKey, TCHAR *szValue, unsigned long ulSize, bool bUserParam = false);
	//{secret}
	unsigned long  SetParamValue(TCHAR* szKey, TCHAR* szValue, bool bUserParam = false);
	//{secret}
	unsigned long  AddParam(TCHAR *szKey, TCHAR *szValue, bool bUserParam = false);
	//{secret}
	unsigned long  RemoveParam(TCHAR *szKey, bool bUserParam = false);
	//{secret}
	unsigned int GetNbParam(bool bUserParam = false);
	//{secret}
	unsigned long  GetParamByIndex(unsigned long ulIndex, TCHAR *szKey, unsigned long ulSize, bool bUserParam = false);
	
    //Description: Returns whether or not the StationURL instance is valid. 
	//Returns: true if the StationURL instance is valid, false if otherwise.
	bool  IsValid();

	StationURL &operator=(const StationURL &oStationURL);

	//{secret}
	void Trace(unsigned long dwTraceFlags = TRACE_ALWAYS);

#ifdef _TEST_ENABLED
	//{secret}
	static bool Test();
#endif

private:
	unsigned long  CopyInSuppliedBuffer(TCHAR *szDest, unsigned long ulSize, TCHAR *szSource, unsigned long ulNeededSize);
	static TCHAR *GetNextParamDelimiter(TCHAR *szURLPtr, bool *bIsAUserDelimiter);
	unsigned long  GetNextParam(Param *pParam);

private:
	TCHAR	*m_szURL;
};


#endif
