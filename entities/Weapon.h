#ifndef LIBX_WEAPON_H
#define LIBX_WEAPON_H

#include "../math/Vector3.h"
#include <string>

class Weapon {
private:
    uintptr_t m_Base;
    int m_Index;
    int m_Owner;
    
public:
    // Constructor
    Weapon(uintptr_t base = 0, int index = -1, int owner = -1) : 
        m_Base(base), m_Index(index), m_Owner(owner) {}
    
    // Core methods
    bool IsValid() const;
    bool IsWeapon() const;
    bool IsGun() const;
    bool IsKnife() const;
    bool IsGrenade() const;
    
    // Weapon info
    std::string GetName() const;
    std::string GetDisplayName() const;
    int GetWeaponID() const;
    int GetItemDefinitionIndex() const { return GetWeaponID(); }
    std::string GetClassName() const;
    
    // Owner and position
    int GetOwner() const { return m_Owner; }
    void SetOwner(int owner) { m_Owner = owner; }
    int GetOwnerIndex() const { return m_Owner; }
    Player GetOwnerPlayer() const;
    
    Vector3 GetPosition() const;
    Vector3 GetOrigin() const { return GetPosition(); }
    
    // Ammo and firing
    int GetAmmo() const;
    int GetMaxAmmo() const;
    int GetClip1() const;
    int GetClip2() const;
    int GetReserveAmmo() const;
    
    bool HasAmmo() const;
    bool IsEmpty() const;
    bool IsReloading() const;
    
    // Weapon stats
    float GetDamage() const;
    float GetRange() const;
    float GetFireRate() const;
    float GetSpread() const;
    float GetRecoil() const;
    
    // Firing modes
    bool IsSemiAuto() const;
    bool IsFullAuto() const;
    bool IsBurst() const;
    int GetFireMode() const;
    
    // Recoil and spread control
    float GetSpreadAngle() const;
    float GetInaccuracy() const;
    Vector3 GetRecoilAngle() const;
    Vector3 GetRecoilVector() const;
    
    // Skins and customization
    int GetSkinID() const;
    void SetSkinID(int skinID);
    int GetPaintKit() const { return GetSkinID(); }
    
    int GetStatTrack() const;
    int GetKillEater() const;
    std::string GetCustomName() const;
    
    // Model and world model
    uintptr_t GetModel() const;
    uintptr_t GetWorldModel() const;
    std::string GetModelName() const;
    std::string GetWorldModelName() const;
    
    // Entity base
    uintptr_t GetBase() const { return m_Base; }
    void SetBase(uintptr_t base) { m_Base = base; }
    int GetIndex() const { return m_Index; }
    void SetIndex(int index) { m_Index = index; }
    
    // Static methods for entity iteration
    static int GetMaxWeapons();
    static Weapon GetByIndex(int index);
    static std::vector<Weapon> GetAllWeapons();
    static std::vector<Weapon> GetWeaponsByOwner(int ownerIndex);
    
    // Utility
    std::string ToString() const;
    bool operator==(const Weapon& other) const {
        return m_Base == other.m_Base && m_Index == other.m_Index;
    }
};

// Weapon ID definitions
enum WeaponID {
    WEAPON_NONE = 0,
    WEAPON_DEAGLE = 1,
    WEAPON_ELITE = 2,
    WEAPON_FIVESEVEN = 3,
    WEAPON_GLOCK = 4,
    WEAPON_AK47 = 7,
    WEAPON_AUG = 8,
    WEAPON_AWP = 9,
    WEAPON_FAMAS = 10,
    WEAPON_G3SG1 = 11,
    WEAPON_GALIL = 13,
    WEAPON_M249 = 14,
    WEAPON_M4A4 = 16,
    WEAPON_MAC10 = 17,
    WEAPON_P90 = 19,
    WEAPON_UMP45 = 24,
    WEAPON_XM1014 = 25,
    WEAPON_BIZON = 26,
    WEAPON_MAG7 = 27,
    WEAPON_NEGEV = 28,
    WEAPON_SAWEDOFF = 29,
    WEAPON_TEC9 = 30,
    WEAPON_TASER = 31,
    WEAPON_HKP2000 = 32,
    WEAPON_MP7 = 33,
    WEAPON_MP9 = 34,
    WEAPON_NOVA = 35,
    WEAPON_P250 = 36,
    WEAPON_SCAR20 = 38,
    WEAPON_SG556 = 39,
    WEAPON_SCOUT = 40,
    WEAPON_KNIFE = 42,
    WEAPON_FLASHBANG = 43,
    WEAPON_HEGRENADE = 44,
    WEAPON_SMOKEGRENADE = 45,
    WEAPON_MOLOTOV = 46,
    WEAPON_DECOY = 47,
    WEAPON_INCGRENADE = 48,
    WEAPON_C4 = 49,
    WEAPON_KNIFE_T = 59,
    WEAPON_M4A1S = 60,
    WEAPON_USPS = 61,
    WEAPON_CZ75 = 63,
    WEAPON_R8 = 64,
    WEAPON_KNIFE_BAYONET = 500,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT = 506,
    WEAPON_KNIFE_KARAMBIT = 507,
    WEAPON_KNIFE_M9BAYONET = 508,
    WEAPON_KNIFE_HUNTSMAN = 509,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY = 515,
    WEAPON_KNIFE_HUNTSMAN = 516
};

#endif // LIBX_WEAPON_H