#include "GUI.h"
#include <android/log.h>

#define LOG_TAG "LibX-GUI"

GUI::GUI() 
    : m_Initialized(false)
    , m_Visible(false)
    , m_LastFrameTime(0.0f)
    , m_Context(nullptr)
    , m_CurrentTab(0)
    , m_StyleApplied(false)
    , m_Opacity(0.9f) {
    
    // Initialize default window properties
    m_WindowPos = ImVec2(50, 50);
    m_WindowSize = ImVec2(400, 600);
    
    // Initialize default colors
    m_PrimaryColor = ImVec4(0.2f, 0.2f, 0.2f, m_Opacity);
    m_SecondaryColor = ImVec4(0.1f, 0.1f, 0.1f, m_Opacity);
    m_AccentColor = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
    m_BackgroundColor = ImVec4(0.0f, 0.0f, 0.0f, m_Opacity);
}

GUI::~GUI() {
    if (m_Initialized) {
        Shutdown();
    }
}

bool GUI::Init() {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Initializing GUI");
    
    if (m_Initialized) {
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "GUI already initialized");
        return true;
    }
    
    InitializeImGui();
    SetupStyle();
    
    m_Initialized = true;
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "GUI initialized successfully");
    
    return true;
}

void GUI::Shutdown() {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Shutting down GUI");
    
    if (!m_Initialized) {
        return;
    }
    
    ShutdownImGui();
    m_Initialized = false;
    
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "GUI shutdown complete");
}

void GUI::Render() {
    if (!m_Initialized || !m_Visible) {
        return;
    }
    
    // Render main GUI window
    RenderMainWindow();
}

void GUI::Toggle() {
    m_Visible = !m_Visible;
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "GUI %s", m_Visible ? "visible" : "hidden");
}

void GUI::SetVisible(bool visible) {
    m_Visible = visible;
}

void GUI::ProcessEvent(AInputEvent* event) {
    if (!m_Initialized) {
        return;
    }
    
    // Process Android input event through ImGui
    // ImGui_ImplAndroid_HandleInputEvent(event);
}

void GUI::RenderMainWindow() {
    if (!ImGui::Begin("LibX", &m_Visible, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::End();
        return;
    }
    
    // Render title bar
    RenderTitleBar();
    
    // Render menu bar
    // RenderMenuBar();
    
    // Render tabs
    ImGui::BeginTabBar("MainTabs");
    
    switch (m_CurrentTab) {
        case 0:
            if (ImGui::BeginTabItem("Aimbot")) {
                DrawAimbotTab();
                ImGui::EndTabItem();
            }
            break;
        case 1:
            if (ImGui::BeginTabItem("Visuals")) {
                DrawVisualsTab();
                ImGui::EndTabItem();
            }
            break;
        case 2:
            if (ImGui::BeginTabItem("Exploits")) {
                DrawExploitsTab();
                ImGui::EndTabItem();
            }
            break;
        case 3:
            if (ImGui::BeginTabItem("Skins")) {
                DrawSkinsTab();
                ImGui::EndTabItem();
            }
            break;
        case 4:
            if (ImGui::BeginTabItem("Config")) {
                DrawConfigTab();
                ImGui::EndTabItem();
            }
            break;
        case 5:
            if (ImGui::BeginTabItem("Settings")) {
                DrawSettingsTab();
                ImGui::EndTabItem();
            }
            break;
    }
    
    ImGui::EndTabBar();
    
    // Render status bar
    RenderStatusBar();
    
    ImGui::End();
}

void GUI::DrawAimbotTab() {
    auto aimbotConfig = GetAimbotConfig();
    
    ImGui::Checkbox("Enabled", &aimbotConfig->enabled);
    ImGui::SliderFloat("FOV", &aimbotConfig->fov, 1.0f, 180.0f);
    ImGui::SliderFloat("Range", &aimbotConfig->range, 100.0f, 2000.0f);
    ImGui::SliderInt("Bone", &aimbotConfig->bone, 0, 18);
    ImGui::SliderFloat("Speed", &aimbotConfig->speed, 0.1f, 10.0f);
    ImGui::Checkbox("Silent", &aimbotConfig->silent);
    ImGui::Checkbox("Aimlock", &aimbotConfig->aimlock);
    ImGui::Checkbox("Fire on Spawn", &aimbotConfig->fire_on_spawn);
    ImGui::Checkbox("Ignore Friends", &aimbotConfig->ignore_friends);
    ImGui::Checkbox("Auto Shoot", &aimbotConfig->auto_shoot);
    ImGui::Checkbox("Prediction", &aimbotConfig->prediction);
}

void GUI::DrawVisualsTab() {
    auto espConfig = GetESPConfig();
    
    ImGui::Checkbox("ESP Enabled", &espConfig->enabled);
    ImGui::Checkbox("Players", &espConfig->players);
    ImGui::Checkbox("Weapons", &espConfig->weapons);
    ImGui::Checkbox("Grenades", &espConfig->grenades);
    ImGui::Checkbox("Skeleton", &espConfig->skeleton);
    ImGui::Checkbox("Health Bar", &espConfig->health_bar);
    ImGui::SliderFloat("Max Distance", &espConfig->max_distance, 100.0f, 5000.0f);
    ImGui::SliderFloat("Box Thickness", &espConfig->box_thickness, 1.0f, 5.0f);
    ImGui::ColorEdit4("Box Color", (float*)&espConfig->box_color);
}

void GUI::DrawExploitsTab() {
    auto exploitConfig = GetExploitConfig();
    
    ImGui::Checkbox("Rapid Fire", &exploitConfig->rapid_fire);
    ImGui::SliderFloat("Fire Rate Multiplier", &exploitConfig->fire_rate_multiplier, 1.0f, 5.0f);
    ImGui::Checkbox("No Recoil", &exploitConfig->no_recoil);
    ImGui::Checkbox("No Spread", &exploitConfig->no_spread);
    ImGui::Checkbox("Fast Reload", &exploitConfig->fast_reload);
    ImGui::Checkbox("Unlimited Ammo", &exploitConfig->unlimited_ammo);
    ImGui::Checkbox("Bunny Hop", &exploitConfig->bunny_hop);
    ImGui::Checkbox("Auto Strafe", &exploitConfig->auto_strafe);
}

void GUI::DrawSkinsTab() {
    auto skinConfig = GetSkinConfig();
    
    ImGui::Checkbox("Skin Changer", &skinConfig->enabled);
    ImGui::Checkbox("Weapon Skins", &skinConfig->weapon_skins);
    ImGui::Checkbox("Character Skins", &skinConfig->character_skins);
    ImGui::Checkbox("Knife Skins", &skinConfig->knife_skins);
    ImGui::Checkbox("Gloves", &skinConfig->gloves);
    ImGui::Checkbox("Stickers", &skinConfig->stickers);
}

void GUI::DrawConfigTab() {
    RenderConfigList();
    RenderConfigButtons();
}

void GUI::DrawSettingsTab() {
    auto settingsConfig = GetSettingsConfig();
    
    ImGui::SliderFloat("UI Opacity", &settingsConfig->ui_opacity, 0.1f, 1.0f);
    ImGui::ColorEdit4("UI Color", (float*)&settingsConfig->ui_color);
    ImGui::ColorEdit4("UI Accent", (float*)&settingsConfig->ui_accent);
    ImGui::Checkbox("Show FPS", &settingsConfig->show_fps);
    ImGui::Checkbox("Show Coordinates", &settingsConfig->show_coordinates);
    ImGui::Checkbox("Debug Mode", &settingsConfig->debug_mode);
}

void GUI::RenderConfigList() {
    if (!g_Config) {
        ImGui::Text("Config Manager not available");
        return;
    }
    
    auto configList = g_Config->GetConfigList();
    
    ImGui::Text("Available Configs:");
    for (const auto& config : configList) {
        ImGui::BulletText("%s", config.name.c_str());
    }
}

void GUI::RenderConfigButtons() {
    static char configName[256] = "";
    
    ImGui::InputText("Config Name", configName, sizeof(configName));
    
    if (ImGui::Button("Save Config")) {
        if (strlen(configName) > 0 && g_Config) {
            g_Config->Save(configName);
            strcpy(configName, "");
        }
    }
    
    if (ImGui::Button("Load Config")) {
        if (strlen(configName) > 0 && g_Config) {
            g_Config->Load(configName);
        }
    }
    
    if (ImGui::Button("Delete Config")) {
        if (strlen(configName) > 0 && g_Config) {
            g_Config->Delete(configName);
        }
    }
}

void GUI::RenderFPSCounter() {
    // Render FPS counter in corner
    float fps = GetFPS();
    ImGui::SetNextWindowPos(ImVec2(10, 10));
    ImGui::SetNextWindowBgAlpha(0.5f);
    
    if (ImGui::Begin("FPS", false, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("FPS: %.1f", fps);
    }
    ImGui::End();
}

void GUI::RenderCoordinates() {
    // Render coordinates in corner
    ImGui::SetNextWindowPos(ImVec2(10, 30));
    ImGui::SetNextWindowBgAlpha(0.5f);
    
    if (ImGui::Begin("Coords", false, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize)) {
        // Get current player coordinates
        // Placeholder implementation
        ImGui::Text("X: 0.0");
        ImGui::Text("Y: 0.0");
        ImGui::Text("Z: 0.0");
    }
    ImGui::End();
}

void GUI::InitializeImGui() {
    // Initialize ImGui context and settings
    m_Context = ImGui::CreateContext();
}

void GUI::ShutdownImGui() {
    if (m_Context) {
        ImGui::DestroyContext(m_Context);
        m_Context = nullptr;
    }
}

void GUI::SetupStyle() {
    auto& style = ImGui::GetStyle();
    
    // Set custom style
    style.WindowPadding = ImVec2(8, 8);
    style.FramePadding = ImVec2(4, 4);
    style.ItemSpacing = ImVec2(8, 4);
    style.ItemInnerSpacing = ImVec2(4, 4);
    style.WindowRounding = 8.0f;
    style.FrameRounding = 4.0f;
    style.GrabRounding = 4.0f;
    
    // Apply custom colors
    ImGui::StyleColorsDark();
}

void GUI::RenderTitleBar() {
    ImGui::Text("LibX - Cheat Menu");
    ImGui::Separator();
}

void GUI::RenderStatusBar() {
    ImGui::Separator();
    
    // Render status information
    float fps = GetFPS();
    ImGui::Text("FPS: %.1f", fps);
    
    ImGui::SameLine();
    ImGui::Text("Status: %s", m_Visible ? "Active" : "Hidden");
}

float GUI::GetFPS() const {
    // Placeholder FPS calculation
    return 60.0f;
}

AimbotConfig* GUI::GetAimbotConfig() {
    return g_Config ? &g_Config->GetAimbotConfig() : nullptr;
}

ESPConfig* GUI::GetESPConfig() {
    return g_Config ? &g_Config->GetESPConfig() : nullptr;
}

VisualConfig* GUI::GetVisualConfig() {
    return g_Config ? &g_Config->GetVisualConfig() : nullptr;
}

ExploitConfig* GUI::GetExploitConfig() {
    return g_Config ? &g_Config->GetExploitConfig() : nullptr;
}

SkinConfig* GUI::GetSkinConfig() {
    return g_Config ? &g_Config->GetSkinConfig() : nullptr;
}

SettingsConfig* GUI::GetSettingsConfig() {
    return g_Config ? &g_Config->GetSettingsConfig() : nullptr;
}