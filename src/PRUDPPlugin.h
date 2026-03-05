#ifndef _PRUDPPlugin_H_
#define _PRUDPPlugin_H_

#include <Plugins/Core/PluginObject.h>
#include <Plugins/Transport/Interface/TransportPlugin.h>
#include <Plugins/Transport/Interface/StationURL.h>

class PRUDPPlugin : public TransportPlugin {
public:

	PRUDPPlugin();
	virtual ~PRUDPPlugin();

	virtual bool Activate();
	virtual void Release();
	virtual TCHAR *GetGUID();
	virtual TCHAR *GetAuthor();
	virtual TCHAR *GetName();
	virtual unsigned long GetVersion();
	virtual bool IsCertified();
	virtual bool ResponsibleForURL(StationURL *pURL);
	virtual PluginObject *CreatePluginObject();
	virtual void DeletePluginObject(PluginObject *pObject);
	virtual void SetTraceOutput(TraceOutput *pTraceOutput);

	static PRUDPPlugin *GetInstance();

private:

	static PRUDPPlugin s_oPlugin;

};

#endif
