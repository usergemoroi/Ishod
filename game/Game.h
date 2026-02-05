#ifndef LIBX_GAME_H
#define LIBX_GAME_H

#include "../entities/Player.h"
#include "../entities/Weapon.h"
#include "../entities/Grenade.h"
#include "../math/Vector2.h"
#include "../math/Vector3.h"
#include <vector>

class Game {
private:
    bool m_Initialized;
    bool m_InGame;
    int m_GameMode;
    float m_GameTime;
    
    // View and screen info
    int m_ScreenWidth;
    int m_ScreenHeight;
    float m_ViewMatrix[16];
    
    // Game state
    int m_LocalPlayerIndex;
    std::vector<Player> m_Players;
    std::vector<Weapon> m_Weapons;
    std::vector<Grenade> m_Grenades;
    
public:
    Game();
    virtual ~Game();
    
    // Lifecycle
    bool Init();
    void Shutdown();
    
    // Game state
    bool IsInGame() const { return m_InGame; }
    int GetGameMode() const { return m_GameMode; }
    float GetGameTime() const { return m_GameTime; }
    
    // Player management
    Player GetLocalPlayer();
    std::vector<Player> GetPlayers();
    std::vector<Player> GetAlivePlayers();
    std::vector<Player> GetEnemyPlayers();
    std::vector<Player> GetTeammates();
    
    // Weapon management
    std::vector<Weapon> GetWeapons();
    std::vector<Weapon> GetWeaponsByOwner(int ownerIndex);
    Weapon GetWeaponByIndex(int index);
    
    // Grenade management
    std::vector<Grenade> GetGrenades();
    std::vector<Grenade> GetGrenadesByOwner(int ownerIndex);
    Grenade GetGrenadeByIndex(int index);
    
    // View and screen info
    int GetScreenWidth() const { return m_ScreenWidth; }
    int GetScreenHeight() const { return m_ScreenHeight; }
    float* GetViewMatrix() { return m_ViewMatrix; }
    
    // Coordinate transformations
    Vector2 WorldToScreen(const Vector3& worldPos);
    Vector3 ScreenToWorld(const Vector2& screenPos, float distance = 1000.0f);
    Vector3 GetCameraPosition();
    Vector3 GetCameraAngles();
    
    // Ray tracing
    bool Raycast(const Vector3& start, const Vector3& end, Vector3& hitPos, uintptr_t& hitEntity);
    bool Raycast(const Vector3& start, const Vector3& direction, float distance, Vector3& hitPos, uintptr_t& hitEntity);
    
    // Entity finding
    Player GetPlayerByIndex(int index);
    Player GetPlayerByHandle(int handle);
    Weapon GetWeaponByHandle(int handle);
    Grenade GetGrenadeByHandle(int handle);
    
    // Crosshair
    Vector2 GetCrosshairPosition();
    bool IsCrosshairOnTarget();
    
    // Radar
    void GetRadarPosition(const Vector3& worldPos, Vector2& radarPos);
    float GetRadarScale();
    
    // Game events
    void OnPlayerSpawn(int playerIndex);
    void OnPlayerDeath(int playerIndex);
    void OnWeaponFire(int weaponIndex);
    void OnGrenadeThrow(int grenadeIndex);
    void OnRoundStart();
    void OnRoundEnd();
    
    // Utilities
    bool IsValidEntity(uintptr_t entity);
    int GetEntityTeam(uintptr_t entity);
    float GetDistanceToEntity(uintptr_t entity);
    
    // Static methods
    static Game& GetInstance();
    static bool IsValidIndex(int index);
    
    // Information
    std::string GetMapName();
    int GetMaxPlayers();
    int GetMaxRounds();
    int GetCurrentRound();
    bool IsRoundFreezeTime();
    
private:
    void UpdateGameState();
    void UpdateEntities();
    void UpdateScreenSize();
    void UpdateViewMatrix();
    
    // Memory reading helpers
    template<typename T>
    T ReadMemory(uintptr_t address);
    
    bool ReadString(uintptr_t address, std::string& buffer, int maxLength = 256);
    
    // Entity iteration
    void EnumeratePlayers();
    void EnumerateWeapons();
    void EnumerateGrenades();
    
    // Cache management
    void ClearCache();
    void UpdateCache();
};

#endif // LIBX_GAME_H