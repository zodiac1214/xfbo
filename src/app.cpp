#include "app.h"

App &App::instance()
{
    static App instance;
    return instance;
}

App::App()
{
    app_name = "xFBO";
    strcpy(name, (app_name + " - " VERSION_SHORT " - ").c_str());
    strcpy(signature, "com.github.zodiac1214.xfbo");
    strcpy(description, "x FBO with AI");
    // renderer_ = Renderer::Create();
}

App::~App()
{
    // Destructor code here
}

int App::initialize(char *out_name, char *out_sig, char *out_desc)
{
    LogMsg("Startup " VERSION);

    // Initialization code here
    strcpy(out_name, name);
    strcpy(out_sig, signature);
    strcpy(out_desc, description);

    // Always use Unix-native paths on the Mac!
    XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);
    XPLMEnableFeature("XPLM_USE_NATIVE_WIDGET_WINDOWS", 1);

    char buffer[2048];
    XPLMGetSystemPath(buffer);
    std::string base_dir(buffer); // has trailing slash
    App::instance().setXpDir(base_dir);
    App::instance().setPluginDir(base_dir + "Resources/plugins/" + app_name);
    App::instance().setOutputDir(base_dir + "Output/" + app_name);
    App::instance().setPrefPath(base_dir + "Output/preferences/" + app_name + ".prf");
    std::filesystem::create_directory(App::instance().getOutputDir());

    LogMsg("XPluginStart done, xp_dir: '%s'", App::instance().getXpDir().c_str());

    // intialize Ultralight here
    Config config;
    config.user_stylesheet = "body { background-color: #202020; color: #E0E0E0; }";
    Platform::instance().set_config(config);
    Platform::instance().set_font_loader(GetPlatformFontLoader());
    Platform::instance().set_file_system(GetPlatformFileSystem(plugin_dir.c_str()));
    Platform::instance().set_logger(GetDefaultLogger("ultralight.log"));

    RefPtr<Renderer> renderer = Renderer::Create();

    RefPtr<View> view = renderer->CreateView(800, 600, ViewConfig(), nullptr);

    // multiple line of js code to test
    String scripts = R"(
        function add(a, b) {
            return a + b;
        }
        add(5, 7);
    )";

    String result = view->EvaluateScript(scripts);
    LogMsg("FFFFFFF!!!!!!!!!!%s", result.utf8().data());

    scripts = R"(
        function add(a, b) {
            return a + b;
        }
        add(5, "7");
    )";
    result = view->EvaluateScript(scripts);
    LogMsg("FFFFFFF!!!!!!!!!!%s", result.utf8().data());

    return 1;
}

void App::shutdown()
{
    // Shutdown code here
}

void App::update()
{
    // Update code here
}
