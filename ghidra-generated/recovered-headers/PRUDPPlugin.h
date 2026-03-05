// Auto-generated from PRUDPPlugin.obj.md
#ifndef _PRUDPPLUGIN_H_
#define _PRUDPPLUGIN_H_

#include <Plugins/Core/PluginObject.h>
#include <Plugins/Transport/Interface/StationURL.h>

class TraceOutput;




class PRUDPPlugin {
public:
    PRUDPPlugin(void);
    virtual ~PRUDPPlugin();
    virtual bool Activate(void);
    virtual void Release(void);
    virtual char*  GetGUID(void);
    virtual char*  GetAuthor(void);
    virtual char*  GetName(void);
    virtual unsigned long GetVersion(void);
    virtual bool IsCertified(void);
    virtual bool ResponsibleForURL(StationURL*);
    virtual PluginObject*  CreatePluginObject(void);
    virtual void DeletePluginObject(PluginObject*);
    virtual void SetTraceOutput(TraceOutput*);
    static PRUDPPlugin*  GetInstance(void);
};

class TransportPlugin {
public:
    virtual unsigned long GetInterfaceVersion(void);
    virtual unsigned long GetType(void);
};

#endif // _PRUDPPLUGIN_H_
