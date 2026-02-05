#ifndef LIBX_GRENADE_H
#define LIBX_GRENADE_H

#include "../math/Vector3.h"
#include <string>

class Grenade {
private:
    uintptr_t m_Base;
    int m_Index;
    int m_Owner;
    
public:
    // Constructor
    Grenade(uintptr_t base = 0, int index = -1, int owner = -1) : 
        m_Base(base), m_Index(index), m_Owner(owner) {}
    
    // Core methods
    bool IsValid() const;
    bool IsGrenade() const;
    bool IsExplosive() const;
    bool IsSmoke() const;
    bool IsFlash() const;
    bool IsMolotov() const;
    bool IsIncendiary() const;
    bool IsDecoy() const;
    
    // Grenade type
    int GetGrenadeType() const;
    std::string GetGrenadeName() const;
    std::string GetDisplayName() const;
    
    // Owner and position
    int GetOwner() const { return m_Owner; }
    void SetOwner(int owner) { m_Owner = owner; }
    int GetOwnerIndex() const { return m_Owner; }
    Player GetOwnerPlayer() const;
    
    Vector3 GetPosition() const;
    Vector3 GetOrigin() const { return GetPosition(); }
    Vector3 GetVelocity() const;
    
    // Timing and explosion
    float GetExplodeTime() const;
    float GetTimeSinceThrown() const;
    bool IsExploded() const;
    bool IsExploding() const;
    
    // Throw physics
    float GetThrowStrength() const;
    Vector3 GetThrowAngle() const;
    float GetFuseTime() const;
    
    // Damage and effects
    float GetDamage() const;
    float GetRadius() const;
    bool WillExplodeOnImpact() const;
    
    // Smoke effects
    float GetSmokeRadius() const;
    Vector3 GetSmokeCenter() const;
    bool IsSmokeActive() const;
    
    // Flash effects
    float GetFlashDuration() const;
    float GetFlashAlpha() const;
    bool IsFlashing() const;
    
    // Molotov/Incendiary effects
    float GetFireDuration() const;
    float GetFireSpread() const;
    bool IsBurning() const;
    
    // Model and effects
    uintptr_t GetModel() const;
    std::string GetModelName() const;
    uintptr_t GetEffectHandle() const;
    
    // Entity base
    uintptr_t GetBase() const { return m_Base; }
    void SetBase(uintptr_t base) { m_Base = base; }
    int GetIndex() const { return m_Index; }
    void SetIndex(int index) { m_Index = index; }
    
    // Static methods for entity iteration
    static int GetMaxGrenades();
    static Grenade GetByIndex(int index);
    static std::vector<Grenade> GetAllGrenades();
    static std::vector<Grenade> GetGrenadesByOwner(int ownerIndex);
    
    // Prediction and trajectory
    std::vector<Vector3> GetTrajectory(float deltaTime = 0.1f, int maxSteps = 100) const;
    Vector3 GetPredictedPosition(float deltaTime) const;
    bool WillHitTarget(const Vector3& targetPos, float targetRadius = 10.0f) const;
    
    // Utility
    std::string ToString() const;
    bool operator==(const Grenade& other) const {
        return m_Base == other.m_Base && m_Index == other.m_Index;
    }
};

// Grenade type definitions
enum GrenadeType {
    GRENADE_NONE = 0,
    GRENADE_HE = 4,
    GRENADE_SMOKE = 7,
    GRENADE_FLASH = 5,
    GRENADE_MOLOTOV = 6,
    GRENADE_INCENDIARY = 8,
    GRENADE_DECOY = 9,
    GRENADE_TASER = 31 // Special case for Zeus
};

// Explosion flags
#define EXP_NONE 0
#define EXP_PARTICLES 1
#define EXP_SOUND 2
#define EXP_NOSMOKE 4
#define EXP_FLASH 8

#endif // LIBX_GRENADE_H