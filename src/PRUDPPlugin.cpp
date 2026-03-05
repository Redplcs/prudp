#include "PRUDPPlugin.h"
#include "PRUDPTransport.h"

PRUDPPlugin PRUDPPlugin::s_oPlugin;

PRUDPPlugin::PRUDPPlugin()
{
}

PRUDPPlugin::~PRUDPPlugin()
{
}

bool PRUDPPlugin::Activate()
{
	return true;
}

void PRUDPPlugin::Release()
{
}

TCHAR *PRUDPPlugin::GetGUID()
{
	return _T("6A718E55-82A7-4c0c-A65B-38230C45C043");
}

TCHAR *PRUDPPlugin::GetAuthor()
{
	return _T("Quazal");
}

TCHAR *PRUDPPlugin::GetName()
{
	return _T("Proksim Reliable UDP Transport Plugin");
}

unsigned long PRUDPPlugin::GetVersion()
{
	return 1;
}

bool PRUDPPlugin::IsCertified()
{
	return true;
}

bool PRUDPPlugin::ResponsibleForURL(StationURL *pURL)
{
	TCHAR szType[0x80];

	pURL->GetTransportType(szType, 0x80);

	return _tcscmp(szType, _T("prudp")) == 0;
}

PluginObject *PRUDPPlugin::CreatePluginObject()
{
	return new PRUDPTransport(this);
}

void PRUDPPlugin::DeletePluginObject(PluginObject *pObject)
{
	if (pObject)
		delete pObject;
}

void PRUDPPlugin::SetTraceOutput(TraceOutput *pTraceOutput)
{
	if (pTraceOutput != TraceOutput::GetInstance())
		TraceOutput::SetTheTraceOutput(pTraceOutput);
}

PRUDPPlugin *PRUDPPlugin::GetInstance()
{
	return &s_oPlugin;
}
