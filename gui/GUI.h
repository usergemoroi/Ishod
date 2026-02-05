#ifndef LIBX_GUI_H
#define LIBX_GUI_H

#include <android/input.h>
#include "imgui.h"

// Forward declarations
class Aimbot;
class ESP;
class AimbotConfig;
class ESPConfig;
class VisualConfig;
class ExploitConfig;
class SkinConfig;
class SettingsConfig;

class GUI {
private:
    bool m_Initialized;
    bool m_Visible;
    float m_LastFrameTime;
    ImGuiContext* m_Context;
    
    // UI state
    int m_CurrentTab;
    bool m_StyleApplied;
    
    // Window properties
    ImVec2 m_WindowPos;
    ImVec2 m_WindowSize;
    float m_Opacity;
    
    // Colors
    ImVec4 m_PrimaryColor;
    ImVec4 m_SecondaryColor;
    ImVec4 m_AccentColor;
    ImVec4 m_BackgroundColor;
    
public:
    GUI();
    virtual ~GUI();
    
    // Lifecycle
    bool Init();
    void Shutdown();
    void Render();
    void Toggle();
    void SetVisible(bool visible);
    bool IsVisible() const { return m_Visible; }
    
    // Input handling
    void ProcessEvent(AInputEvent* event);
    
    // UI rendering
    void ApplyStyle();
    void RenderMainWindow();
    
    // Tab rendering
    void DrawAimbotTab();
    void DrawVisualsTab();
    void DrawExploitsTab();
    void DrawSkinsTab();
    void DrawConfigTab();
    void DrawSettingsTab();
    
    // UI controls
    void RenderCheckbox(const char* label, bool* value);
    void RenderSliderFloat(const char* label, float* value, float min, float max);
    void RenderSliderInt(const char* label, int* value, int min, int max);
    void RenderComboBox(const char* label, int* value, const char* const* items, int count);
    void RenderColorPicker(const char* label, float* color);
    void RenderButton(const char* label, const ImVec2& size = ImVec2(0, 0));
    
    // Config management
    void RenderConfigList();
    void RenderConfigButtons();
    
    // FPS counter
    void RenderFPSCounter();
    
    // Coordinates display
    void RenderCoordinates();
    
    // Style customization
    void RenderStyleSettings();
    
    // Utility
    void ShowMessage(const char* title, const char* message);
    void ShowConfirmDialog(const char* title, const char* message, void(*callback)(bool));
    
    // Getters for configurations
    AimbotConfig* GetAimbotConfig();
    ESPConfig* GetESPConfig();
    VisualConfig* GetVisualConfig();
    ExploitConfig* GetExploitConfig();
    SkinConfig* GetSkinConfig();
    SettingsConfig* GetSettingsConfig();
    
    // Statistics
    float GetFPS() const;
    int GetFrameCount() const;
    
private:
    void InitializeImGui();
    void ShutdownImGui();
    void SetupStyle();
    void RenderTitleBar();
    void RenderMenuBar();
    void RenderStatusBar();
};

#endif // LIBX_GUI_H