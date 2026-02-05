#include "Grenade.h"
#include <android/log.h>

#define LOG_TAG "LibX-Grenade"

bool Grenade::IsValid() const {
    return m_Base != 0 && m_Index >= 0;
}

bool Grenade::IsGrenade() const {
    return IsValid() && GetGrenadeType() > 0;
}

bool Grenade::IsExplosive() const {
    int type = GetGrenadeType();
    return (type == GRENADE_HE || type == GRENADE_MOLOTOV || type == GRENADE_INCENDIARY);
}

bool Grenade::IsSmoke() const {
    return GetGrenadeType() == GRENADE_SMOKE;
}

bool Grenade::IsFlash() const {
    return GetGrenadeType() == GRENADE_FLASH;
}

bool Grenade::IsMolotov() const {
    return GetGrenadeType() == GRENADE_MOLOTOV;
}

bool Grenade::IsIncendiary() const {
    return GetGrenadeType() == GRENADE_INCENDIARY;
}

bool Grenade::IsDecoy() const {
    return GetGrenadeType() == GRENADE_DECOY;
}

int Grenade::GetGrenadeType() const {
    if (!IsValid()) {
        return GRENADE_NONE;
    }
    
    // This would read grenade type from game memory
    // For now, return random type based on index
    int types[] = {GRENADE_HE, GRENADE_SMOKE, GRENADE_FLASH, GRENADE_MOLOTOV, GRENADE_DECOY};
    return types[m_Index % 5];
}

std::string Grenade::GetGrenadeName() const {
    int type = GetGrenadeType();
    
    switch (type) {
        case GRENADE_HE: return "HE Grenade";
        case GRENADE_SMOKE: return "Smoke Grenade";
        case GRENADE_FLASH: return "Flashbang";
        case GRENADE_MOLOTOV: return "Molotov";
        case GRENADE_INCENDIARY: return "Incendiary Grenade";
        case GRENADE_DECOY: return "Decoy Grenade";
        default: return "Unknown Grenade";
    }
}

std::string Grenade::GetDisplayName() const {
    return GetGrenadeName();
}

Player Grenade::GetOwnerPlayer() const {
    if (m_Owner < 0) {
        return Player();
    }
    
    return Player::GetByIndex(m_Owner);
}

Vector3 Grenade::GetPosition() const {
    if (!IsValid()) {
        return Vector3();
    }
    
    // This would read position from game memory
    // For now, return position based on index
    return Vector3(m_Index * 50.0f, 0.0f, 0.0f);
}

Vector3 Grenade::GetVelocity() const {
    if (!IsValid()) {
        return Vector3();
    }
    
    // This would read velocity from game memory
    // For now, return zero velocity
    return Vector3();
}

float Grenade::GetExplodeTime() const {
    int type = GetGrenadeType();
    
    switch (type) {
        case GRENADE_HE: return 3.0f;
        case GRENADE_SMOKE: return 2.0f;
        case GRENADE_FLASH: return 1.0f;
        case GRENADE_MOLOTOV: return 4.0f;
        case GRENADE_INCENDIARY: return 4.0f;
        case GRENADE_DECOY: return 5.0f;
        default: return 3.0f;
    }
}

float Grenade::GetTimeSinceThrown() const {
    // This would calculate time since grenade was thrown
    // Placeholder implementation
    return 0.0f;
}

bool Grenade::IsExploded() const {
    return GetTimeSinceThrown() >= GetExplodeTime();
}

bool Grenade::IsExploding() const {
    return IsExploded();
}

float Grenade::GetThrowStrength() const {
    return 1.0f; // Placeholder
}

Vector3 Grenade::GetThrowAngle() const {
    return Vector3(); // Placeholder
}

float Grenade::GetFuseTime() const {
    return GetExplodeTime();
}

float Grenade::GetDamage() const {
    int type = GetGrenadeType();
    
    switch (type) {
        case GRENADE_HE: return 90.0f;
        case GRENADE_MOLOTOV: return 60.0f;
        case GRENADE_INCENDIARY: return 45.0f;
        default: return 0.0f;
    }
}

float Grenade::GetRadius() const {
    int type = GetGrenadeType();
    
    switch (type) {
        case GRENADE_HE: return 350.0f;
        case GRENADE_SMOKE: return 450.0f;
        case GRENADE_MOLOTOV: return 300.0f;
        case GRENADE_INCENDIARY: return 300.0f;
        default: return 0.0f;
    }
}

bool Grenade::WillExplodeOnImpact() const {
    return GetGrenadeType() == GRENADE_HE;
}

float Grenade::GetSmokeRadius() const {
    return IsSmoke() ? GetRadius() : 0.0f;
}

Vector3 Grenade::GetSmokeCenter() const {
    return GetPosition();
}

bool Grenade::IsSmokeActive() const {
    return IsSmoke() && IsExploded();
}

float Grenade::GetFlashDuration() const {
    return IsFlash() ? 3.0f : 0.0f;
}

float Grenade::GetFlashAlpha() const {
    // This would calculate flash alpha based on distance and grenade properties
    // Placeholder implementation
    return 0.0f;
}

bool Grenade::IsFlashing() const {
    return IsFlash() && !IsExploded();
}

float Grenade::GetFireDuration() const {
    if (IsMolotov() || IsIncendiary()) {
        return 7.0f;
    }
    return 0.0f;
}

float Grenade::GetFireSpread() const {
    return GetRadius() * 0.7f;
}

bool Grenade::IsBurning() const {
    return (IsMolotov() || IsIncendiary()) && IsExploded();
}

uintptr_t Grenade::GetModel() const {
    return 0; // Placeholder
}

std::string Grenade::GetModelName() const {
    return ""; // Placeholder
}

uintptr_t Grenade::GetEffectHandle() const {
    return 0; // Placeholder
}

int Grenade::GetMaxGrenades() {
    return 32; // Maximum number of grenades
}

Grenade Grenade::GetByIndex(int index) {
    if (index < 0 || index >= GetMaxGrenades()) {
        return Grenade();
    }
    
    // This would get grenade by index from game memory
    // For now, create placeholder grenade
    return Grenade(0x3000 + index * 0x100, index, index % 10);
}

std::vector<Grenade> Grenade::GetAllGrenades() {
    std::vector<Grenade> grenades;
    
    for (int i = 0; i < GetMaxGrenades(); i++) {
        Grenade grenade = GetByIndex(i);
        if (grenade.IsValid()) {
            grenades.push_back(grenade);
        }
    }
    
    return grenades;
}

std::vector<Grenade> Grenade::GetGrenadesByOwner(int ownerIndex) {
    std::vector<Grenade> ownerGrenades;
    auto allGrenades = GetAllGrenades();
    
    for (const auto& grenade : allGrenades) {
        if (grenade.GetOwner() == ownerIndex) {
            ownerGrenades.push_back(grenade);
        }
    }
    
    return ownerGrenades;
}

std::vector<Vector3> Grenade::GetTrajectory(float deltaTime, int maxSteps) const {
    std::vector<Vector3> trajectory;
    
    // Simple trajectory calculation
    Vector3 startPos = GetPosition();
    Vector3 velocity = GetVelocity();
    
    for (int i = 0; i < maxSteps; i++) {
        Vector3 pos = startPos + velocity * (i * deltaTime);
        trajectory.push_back(pos);
    }
    
    return trajectory;
}

Vector3 Grenade::GetPredictedPosition(float deltaTime) const {
    return GetPosition() + GetVelocity() * deltaTime;
}

bool Grenade::WillHitTarget(const Vector3& targetPos, float targetRadius) const {
    // Check if grenade will hit target
    // Placeholder implementation
    return false;
}

std::string Grenade::ToString() const {
    std::string result = "Grenade(";
    result += "Index: " + std::to_string(m_Index) + ", ";
    result += "Type: " + GetGrenadeName() + ", ";
    result += "Position: (" + std::to_string(GetPosition().x) + ", " + std::to_string(GetPosition().y) + ", " + std::to_string(GetPosition().z) + ")";
    result += ")";
    
    return result;
}