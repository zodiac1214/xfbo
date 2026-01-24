
#pragma once
#include <cstring>
#include <string>
#include <memory>
#include <filesystem>

#include "XPLMDataAccess.h"
#include "XPLMScenery.h"
#include "XPLMPlugin.h"
#include "XPLMProcessing.h"
#include "XPLMUtilities.h"
#include "XPLMMenus.h"

#include "log_msg.h"
#include "../version.h"

class App
{

public:
    static App &instance();

    int initialize(char *out_name, char *out_sig, char *out_desc);
    void shutdown();
    void update();

    // Plugin info getters
    const char *getName() const { return name; }
    const char *getSignature() const { return signature; }
    const char *getDescription() const { return description; }

    // Accessors
    const std::string &getXpDir() const { return xp_dir; }
    const std::string &getPluginDir() const { return plugin_dir; }
    const std::string &getOutputDir() const { return output_dir; }
    const std::string &getPrefPath() const { return pref_path; }

    // Setters
    void setXpDir(const std::string &v) { xp_dir = v; }
    void setPluginDir(const std::string &v) { plugin_dir = v; }
    void setOutputDir(const std::string &v) { output_dir = v; }
    void setPrefPath(const std::string &v) { pref_path = v; }

private:
    // ...existing code...
    char name[128] = {};
    char signature[128] = {};
    char description[256] = {};

private:
    App();
    ~App();
    App(const App &) = delete;
    App &operator=(const App &) = delete;

    std::string app_name, xp_dir, plugin_dir, output_dir, pref_path;
};
