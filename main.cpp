#include "libx.h"
#include "gui/GUI.h"
#include "esp/ESP.h"
#include "aimbot/Aimbot.h"
#include "config/Config.h"
#include "game/Game.h"
#include "math/Vector2.h"
#include "math/Vector3.h"

// Global instances
GUI* g_GUI = nullptr;
ESP* g_ESP = nullptr;
Aimbot* g_Aimbot = nullptr;
ConfigManager* g_Config = nullptr;
Game* g_Game = nullptr;

// OpenGL loader
#include "imgl3w/imgl3w.h"

// JNI OnLoad
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    __android_log_print(ANDROID_LOG_INFO, "LibX", "JNI OnLoad called");
    
    JNIEnv* env;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "LibX", "Failed to get JNI environment");
        return JNI_ERR;
    }
    
    __android_log_print(ANDROID_LOG_INFO, "LibX", "JNI OnLoad successful");
    return JNI_VERSION_1_6;
}

// JNI OnUnload
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    __android_log_print(ANDROID_LOG_INFO, "LibX", "JNI OnUnload called");
    Shutdown();
}

// Java native methods
JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeInit(JNIEnv* env, jobject thiz, jobject surface) {
    __android_log_print(ANDROID_LOG_INFO, "LibX", "Native init called");
    
    // Get native window from surface
    ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
    if (window) {
        Initialize(window);
    } else {
        __android_log_print(ANDROID_LOG_ERROR, "LibX", "Failed to get native window");
    }
}

JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeShutdown(JNIEnv* env, jobject thiz) {
    __android_log_print(ANDROID_LOG_INFO, "LibX", "Native shutdown called");
    Shutdown();
}

JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeRender(JNIEnv* env, jobject thiz) {
    Render();
}

JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeHandleInput(JNIEnv* env, jobject thiz, jobject motion_event) {
    // Convert Java MotionEvent to AInputEvent
    // This is a simplified version - in practice, you'd need to properly convert the event
    AInputEvent* event = nullptr; // This would need proper conversion
    if (event) {
        HandleInputEvent(event);
    }
}

// Main initialization function
void Initialize(ANativeWindow* window) {
    __android_log_print(ANDROID_LOG_INFO, "LibX", "Initializing LibX");
    
    // Initialize OpenGL loader
    if (!imgl3wInit()) {
        __android_log_print(ANDROID_LOG_ERROR, "LibX", "Failed to initialize OpenGL loader");
        return;
    }
    
    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    
    // Set up ImGui for Android
    ImGui_ImplAndroid_Init(window);
    ImGui_ImplOpenGL3_Init("#version 300 es");
    
    // Create global instances
    g_Game = new Game();
    g_Config = new ConfigManager();
    g_GUI = new GUI();
    g_ESP = new ESP();
    g_Aimbot = new Aimbot();
    
    // Initialize systems
    if (g_Game->Init()) {
        __android_log_print(ANDROID_LOG_INFO, "LibX", "Game initialized");
    }
    
    if (g_Config) {
        g_Config->SetConfigPath("/data/data/com.example.libx/files/configs/");
        g_Config->LoadDefault();
        __android_log_print(ANDROID_LOG_INFO, "LibX", "Config loaded");
    }
    
    if (g_GUI->Init()) {
        __android_log_print(ANDROID_LOG_INFO, "LibX", "GUI initialized");
    }
    
    if (g_ESP->Init()) {
        __android_log_print(ANDROID_LOG_INFO, "LibX", "ESP initialized");
    }
    
    if (g_Aimbot->Init()) {
        __android_log_print(ANDROID_LOG_INFO, "LibX", "Aimbot initialized");
    }
    
    __android_log_print(ANDROID_LOG_INFO, "LibX", "LibX initialized successfully");
}

// Shutdown function
void Shutdown() {
    __android_log_print(ANDROID_LOG_INFO, "LibX", "Shutting down LibX");
    
    // Shutdown in reverse order
    if (g_Aimbot) {
        g_Aimbot->Shutdown();
        delete g_Aimbot;
        g_Aimbot = nullptr;
    }
    
    if (g_ESP) {
        g_ESP->Shutdown();
        delete g_ESP;
        g_ESP = nullptr;
    }
    
    if (g_GUI) {
        g_GUI->Shutdown();
        delete g_GUI;
        g_GUI = nullptr;
    }
    
    if (g_Config) {
        delete g_Config;
        g_Config = nullptr;
    }
    
    if (g_Game) {
        g_Game->Shutdown();
        delete g_Game;
        g_Game = nullptr;
    }
    
    // Shutdown ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();
    
    __android_log_print(ANDROID_LOG_INFO, "LibX", "LibX shutdown complete");
}

// Render function
void Render() {
    if (!g_GUI || !g_ESP || !g_Aimbot || !g_Game) {
        return;
    }
    
    // Update game state
    g_Game->UpdateGameState();
    
    // Update aimbot
    if (g_Aimbot->IsEnabled()) {
        g_Aimbot->Update();
    }
    
    // Start ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();
    ImGui::NewFrame();
    
    // Render ESP
    if (g_ESP->IsEnabled()) {
        g_ESP->Render();
    }
    
    // Render GUI
    if (g_GUI->IsVisible()) {
        g_GUI->Render();
    }
    
    // Render ImGui
    ImGui::Render();
    
    // Clear screen and render
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

// Input handling function
void HandleInputEvent(AInputEvent* event) {
    if (!g_GUI) {
        return;
    }
    
    // Process event through ImGui
    ImGui_ImplAndroid_HandleInputEvent(event);
    
    // Handle LibX-specific input
    int32_t eventType = AInputEvent_getType(event);
    
    if (eventType == AINPUT_EVENT_TYPE_MOTION) {
        // Handle touch events
        // Implementation would go here
    }
}

// Export functions for external access
extern "C" {
    // Enable/disable features
    __attribute__((visibility("default"))) void SetESPEnabled(bool enabled) {
        if (g_ESP) {
            ESPConfig config = g_ESP->GetConfig();
            config.enabled = enabled;
            g_ESP->SetConfig(config);
        }
    }
    
    __attribute__((visibility("default"))) void SetAimbotEnabled(bool enabled) {
        if (g_Aimbot) {
            AimbotConfig config = g_Aimbot->GetConfig();
            config.enabled = enabled;
            g_Aimbot->SetConfig(config);
        }
    }
    
    __attribute__((visibility("default"))) void ToggleGUI() {
        if (g_GUI) {
            g_GUI->Toggle();
        }
    }
    
    __attribute__((visibility("default"))) void SaveConfig(const char* name) {
        if (g_Config) {
            g_Config->Save(std::string(name));
        }
    }
    
    __attribute__((visibility("default"))) void LoadConfig(const char* name) {
        if (g_Config) {
            g_Config->Load(std::string(name));
        }
    }
    
    __attribute__((visibility("default"))) void GetVersion(char* buffer, int bufferSize) {
        const char* version = "LibX v1.0.0";
        strncpy(buffer, version, bufferSize - 1);
        buffer[bufferSize - 1] = '\0';
    }
}