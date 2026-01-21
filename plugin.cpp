#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>
#include <filesystem>
#include <array>
#include <thread>

#include "plugin.h"

#include "XPLMPlugin.h"
#include "XPLMProcessing.h"
#include "XPLMUtilities.h"
#include "XPLMMenus.h"

#include "version.h"

const char *log_msg_prefix = "xfbo: ";

std::string xp_dir, plugin_dir, output_dir, pref_path;

// =========================== plugin entry points ===============================================
PLUGIN_API int XPluginStart(char *out_name, char *out_sig, char *out_desc)
{
    LogMsg("Startup " VERSION);

    strcpy(out_name, "xFBO - " VERSION);
    strcpy(out_sig, "com.github.zodiac1214.xfbo");
    strcpy(out_desc, "x FBO with AI");

    // Always use Unix-native paths on the Mac!
    XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);
    XPLMEnableFeature("XPLM_USE_NATIVE_WIDGET_WINDOWS", 1);

    char buffer[2048];
    XPLMGetSystemPath(buffer);
    xp_dir = std::string(buffer); // has trailing slash
    plugin_dir = xp_dir + "Resources/plugins/xfbo";
    output_dir = xp_dir + "Output/xfbo";
    pref_path = xp_dir + "Output/preferences/xfbo.prf";
    std::filesystem::create_directory(output_dir);

    LogMsg("XPluginStart done, xp_dir: '%s'", xp_dir.c_str());

    // ... and off we go
    return 1;
}

PLUGIN_API void XPluginStop(void)
{
    LogMsg("Plugin stopped");
}

PLUGIN_API int XPluginEnable(void)
{
    return 1;
}

PLUGIN_API void XPluginDisable(void)
{
    LogMsg("Plugin disabled");
}