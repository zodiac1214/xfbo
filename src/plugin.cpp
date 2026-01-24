
#include "plugin.h"
const char *log_msg_prefix = App::instance().getName();

// =========================== plugin entry points ===============================================
PLUGIN_API int XPluginStart(char *out_name, char *out_sig, char *out_desc)
{

    return App::instance().initialize(out_name, out_sig, out_desc);
}

PLUGIN_API void XPluginStop(void)
{
    LogMsg("Plugin stopped");
}

PLUGIN_API int XPluginEnable(void)
{
    LogMsg("Plugin enabled");
    return 1;
}

PLUGIN_API void XPluginDisable(void)
{
    LogMsg("Plugin disabled");
}