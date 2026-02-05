#ifndef LIBX_PLAYER_H
#define LIBX_PLAYER_H

#include "../math/Vector3.h"
#include <string>

class Player {
private:
    uintptr_t m_Base;
    int m_Index;
    
public:
    // Constructor
    Player(uintptr_t base = 0, int index = -1) : m_Base(base), m_Index(index) {}
    
    // Core methods
    bool IsValid() const;
    bool IsDead() const;
    bool IsAlive() const { return !IsDead(); }
    
    // Health and armor
    int GetHealth() const;
    int GetMaxHealth() const;
    int GetArmor() const;
    bool HasHelmet() const;
    
    // Position and movement
    Vector3 GetPosition() const;
    Vector3 GetOrigin() const { return GetPosition(); }
    Vector3 GetVelocity() const;
    Vector3 GetViewOffset() const;
    Vector3 GetEyePosition() const;
    
    // Team and player info
    int GetTeam() const;
    int GetTeamNumber() const { return GetTeam(); }
    std::string GetName() const;
    int GetIndex() const { return m_Index; }
    bool IsEnemy() const;
    bool IsLocalPlayer() const;
    
    // Weapon info
    int GetWeaponID() const;
    std::string GetWeaponName() const;
    int GetAmmo() const;
    int GetMaxAmmo() const;
    bool IsReloading() const;
    
    // Bones and hitboxes
    Vector3 GetBonePosition(int bone) const;
    Vector3 GetBonePosition(const std::string& boneName) const;
    bool IsBoneVisible(int bone) const;
    
    // Aimbot helpers
    float GetDistanceTo(const Vector3& position) const;
    float GetDistanceTo(const Player& other) const;
    float GetFOVTo(const Vector3& position) const;
    float GetFOVTo(const Player& other) const;
    bool IsInFOV(const Vector3& position, float fov) const;
    bool IsInRange(const Vector3& position, float range) const;
    
    // View angles and angles
    Vector3 GetViewAngles() const;
    Vector3 GetAimPunch() const;
    Vector3 GetAimPunchAngle() const { return GetAimPunch(); }
    
    // Flags and states
    bool IsInAir() const;
    bool IsOnGround() const;
    bool IsWalking() const;
    bool IsRunning() const;
    bool IsCrouching() const;
    bool IsScoped() const;
    bool IsReloading() const;
    bool IsFiring() const;
    
    // Movement and animation
    float GetMoveSpeed() const;
    float GetWalkSpeed() const;
    float GetRunSpeed() const;
    int GetMoveType() const;
    
    // Entity base
    uintptr_t GetBase() const { return m_Base; }
    void SetBase(uintptr_t base) { m_Base = base; }
    void SetIndex(int index) { m_Index = index; }
    
    // Static methods for entity iteration
    static int GetMaxPlayers();
    static Player GetByIndex(int index);
    static Player GetLocalPlayer();
    static std::vector<Player> GetAllPlayers();
    
    // Utility
    std::string ToString() const;
    bool operator==(const Player& other) const {
        return m_Base == other.m_Base && m_Index == other.m_Index;
    }
};

#endif // LIBX_PLAYER_H