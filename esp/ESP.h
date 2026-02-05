#ifndef LIBX_ESP_H
#define LIBX_ESP_H

#include "../entities/Player.h"
#include "../entities/Weapon.h"
#include "../entities/Grenade.h"
#include "../math/Vector2.h"
#include "../math/Vector3.h"
#include "imgui.h"
#include "../config/Config.h"

class ESP {
private:
    bool m_Enabled;
    ESPConfig m_Config;
    
    // Screen dimensions
    int m_ScreenWidth;
    int m_ScreenHeight;
    
    // View matrix
    float m_ViewMatrix[16];
    
public:
    ESP();
    virtual ~ESP();
    
    // Lifecycle
    bool Init();
    void Shutdown();
    void Render();
    void Toggle();
    bool IsEnabled() const { return m_Enabled; }
    
    // Configuration
    void SetConfig(const ESPConfig& config);
    ESPConfig GetConfig() const { return m_Config; }
    
    // Player ESP
    void DrawPlayers();
    void DrawPlayer(const Player& player);
    void DrawSkeleton(const Player& player);
    void DrawHealthBar(const Vector2& screenPos, float health, float maxHealth);
    void DrawName(const Player& player, const Vector2& screenPos);
    void DrawHealth(const Player& player, const Vector2& screenPos);
    void DrawWeapon(const Player& player, const Vector2& screenPos);
    void DrawDistance(const Player& player, const Vector2& screenPos);
    
    // Weapon ESP
    void DrawWeapons();
    void DrawWeapon(const Weapon& weapon);
    void DrawWeaponName(const Weapon& weapon, const Vector2& screenPos);
    void DrawWeaponAmmo(const Weapon& weapon, const Vector2& screenPos);
    
    // Grenade ESP
    void DrawGrenades();
    void DrawGrenade(const Grenade& grenade);
    void DrawGrenadeName(const Grenade& grenade, const Vector2& screenPos);
    void DrawGrenadeTimer(const Grenade& grenade, const Vector2& screenPos);
    
    // Drawing helpers
    void DrawBox(const Vector2& topLeft, const Vector2& bottomRight, float thickness = 2.0f);
    void DrawFilledBox(const Vector2& topLeft, const Vector2& bottomRight, float alpha = 0.3f);
    void DrawLine(const Vector2& start, const Vector2& end, float thickness = 1.0f);
    void DrawText(const Vector2& position, const char* text, float size = 14.0f);
    void DrawCircle(const Vector2& center, float radius, float thickness = 1.0f);
    void DrawFilledCircle(const Vector2& center, float radius, float alpha = 0.3f);
    
    // Geometry helpers
    Vector2 WorldToScreen(const Vector3& worldPos);
    bool GetBoundingBox(const Player& player, Vector2& topLeft, Vector2& bottomRight);
    bool IsVisible(const Player& player);
    bool IsOnScreen(const Vector2& screenPos);
    
    // Utility
    void SetScreenSize(int width, int height);
    void SetViewMatrix(const float* matrix);
    
private:
    void InitializeRenderState();
    void CleanupRenderState();
    ImColor GetESPColor(const Player& player);
    float GetDistanceAlpha(const Player& player);
    
    // Draw optimized elements
    void DrawPlayerBox(const Player& player);
    void DrawPlayerInfo(const Player& player);
    void DrawPlayerLines(const Player& player);
};

#endif // LIBX_ESP_H