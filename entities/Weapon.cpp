#include "Weapon.h"
#include <android/log.h>

#define LOG_TAG "LibX-Weapon"

bool Weapon::IsValid() const {
    return m_Base != 0 && m_Index >= 0;
}

bool Weapon::IsWeapon() const {
    return IsValid() && GetWeaponID() > 0;
}

bool Weapon::IsGun() const {
    int weaponId = GetWeaponID();
    return (weaponId >= 1 && weaponId <= 50);
}

bool Weapon::IsKnife() const {
    int weaponId = GetWeaponID();
    return (weaponId >= 42 && weaponId <= 59) || (weaponId >= 500 && weaponId <= 516);
}

bool Weapon::IsGrenade() const {
    int weaponId = GetWeaponID();
    return (weaponId >= 43 && weaponId <= 49);
}

std::string Weapon::GetName() const {
    int weaponId = GetWeaponID();
    
    switch (weaponId) {
        case WEAPON_DEAGLE: return "Desert Eagle";
        case WEAPON_ELITE: return "Dual Berettas";
        case WEAPON_FIVESEVEN: return "Five-SeveN";
        case WEAPON_GLOCK: return "Glock-18";
        case WEAPON_AK47: return "AK-47";
        case WEAPON_AUG: return "AUG";
        case WEAPON_AWP: return "AWP";
        case WEAPON_FAMAS: return "FAMAS";
        case WEAPON_G3SG1: return "G3SG1";
        case WEAPON_GALIL: return "Galil-AR";
        case WEAPON_M249: return "M249";
        case WEAPON_M4A4: return "M4A4";
        case WEAPON_MAC10: return "MAC-10";
        case WEAPON_P90: return "P90";
        case WEAPON_UMP45: return "UMP-45";
        case WEAPON_XM1014: return "XM1014";
        case WEAPON_BIZON: return "PP-Bizon";
        case WEAPON_MAG7: return "MAG-7";
        case WEAPON_NEGEV: return "Negev";
        case WEAPON_SAWEDOFF: return "Sawed-Off";
        case WEAPON_TEC9: return "Tec-9";
        case WEAPON_TASER: return "Zeus x27";
        case WEAPON_HKP2000: return "P2000";
        case WEAPON_MP7: return "MP7";
        case WEAPON_MP9: return "MP9";
        case WEAPON_NOVA: return "Nova";
        case WEAPON_P250: return "P250";
        case WEAPON_SCAR20: return "SCAR-20";
        case WEAPON_SG556: return "SG 553";
        case WEAPON_SCOUT: return "SSG 08";
        case WEAPON_KNIFE: return "Knife";
        case WEAPON_FLASHBANG: return "Flashbang";
        case WEAPON_HEGRENADE: return "HE Grenade";
        case WEAPON_SMOKEGRENADE: return "Smoke Grenade";
        case WEAPON_MOLOTOV: return "Molotov";
        case WEAPON_DECOY: return "Decoy Grenade";
        case WEAPON_INCGRENADE: return "Incendiary Grenade";
        case WEAPON_C4: return "C4 Explosive";
        case WEAPON_KNIFE_T: return "Knife (Terrorist)";
        case WEAPON_M4A1S: return "M4A1-S";
        case WEAPON_USPS: return "USP-S";
        case WEAPON_CZ75: return "CZ75-Auto";
        case WEAPON_R8: return "R8 Revolver";
        default: return "Unknown Weapon";
    }
}

std::string Weapon::GetDisplayName() const {
    return GetName();
}

int Weapon::GetWeaponID() const {
    if (!IsValid()) {
        return 0;
    }
    
    // This would read weapon ID from game memory
    // For now, return random weapon based on index
    int weapons[] = {4, 7, 9, 10, 13, 16, 19};
    return weapons[m_Index % 7];
}

std::string Weapon::GetClassName() const {
    // This would get class name from game memory
    return "CWeapon"; // Placeholder
}

Player Weapon::GetOwnerPlayer() const {
    if (m_Owner < 0) {
        return Player();
    }
    
    return Player::GetByIndex(m_Owner);
}

Vector3 Weapon::GetPosition() const {
    if (!IsValid()) {
        return Vector3();
    }
    
    // This would read position from game memory
    // For now, return position based on index
    return Vector3(m_Index * 100.0f, 0.0f, 0.0f);
}

int Weapon::GetAmmo() const {
    if (!IsValid()) {
        return 0;
    }
    
    // This would read ammo from game memory
    // For now, return random ammo
    return 30 - (m_Index % 5);
}

int Weapon::GetMaxAmmo() const {
    int weaponId = GetWeaponID();
    
    // Return max ammo for different weapons
    switch (weaponId) {
        case WEAPON_AWP: return 10;
        case WEAPON_AK47: return 30;
        case WEAPON_M4A4: return 30;
        case WEAPON_P90: return 50;
        default: return 30;
    }
}

int Weapon::GetClip1() const {
    return GetAmmo();
}

int Weapon::GetClip2() const {
    // Secondary clip (for weapons with dual clips)
    return 0;
}

int Weapon::GetReserveAmmo() const {
    return GetMaxAmmo() * 3; // Assume 3 spare magazines
}

bool Weapon::HasAmmo() const {
    return GetAmmo() > 0;
}

bool Weapon::IsEmpty() const {
    return GetAmmo() <= 0;
}

bool Weapon::IsReloading() const {
    if (!IsValid()) {
        return false;
    }
    
    // This would check reload state from game memory
    // For now, return false
    return false;
}

float Weapon::GetDamage() const {
    int weaponId = GetWeaponID();
    
    switch (weaponId) {
        case WEAPON_AWP: return 115.0f;
        case WEAPON_AK47: return 36.0f;
        case WEAPON_M4A4: return 33.0f;
        case WEAPON_DEAGLE: return 54.0f;
        case WEAPON_GLOCK: return 28.0f;
        default: return 30.0f;
    }
}

float Weapon::GetRange() const {
    return 8192.0f; // Default range
}

float Weapon::GetFireRate() const {
    int weaponId = GetWeaponID();
    
    switch (weaponId) {
        case WEAPON_MP9: return 750.0f;
        case WEAPON_P90: return 714.0f;
        case WEAPON_GLOCK: return 400.0f;
        case WEAPON_AWP: return 41.0f;
        default: return 600.0f;
    }
}

float Weapon::GetSpread() const {
    return 0.01f; // Placeholder
}

float Weapon::GetRecoil() const {
    return 0.02f; // Placeholder
}

bool Weapon::IsSemiAuto() const {
    int weaponId = GetWeaponID();
    
    switch (weaponId) {
        case WEAPON_DEAGLE:
        case WEAPON_HKP2000:
        case WEAPON_P250:
        case WEAPON_R8:
            return true;
        default:
            return false;
    }
}

bool Weapon::IsFullAuto() const {
    int weaponId = GetWeaponID();
    
    switch (weaponId) {
        case WEAPON_GLOCK:
        case WEAPON_MP9:
        case WEAPON_MAC10:
        case WEAPON_P90:
            return true;
        default:
            return false;
    }
}

bool Weapon::IsBurst() const {
    int weaponId = GetWeaponID();
    
    switch (weaponId) {
        case WEAPON_FAMAS:
            return true;
        default:
            return false;
    }
}

int Weapon::GetFireMode() const {
    if (IsFullAuto()) return 2; // Full auto
    if (IsBurst()) return 1; // Burst
    return 0; // Semi auto
}

float Weapon::GetSpreadAngle() const {
    return 0.0f; // Placeholder
}

float Weapon::GetInaccuracy() const {
    return 0.0f; // Placeholder
}

Vector3 Weapon::GetRecoilAngle() const {
    return Vector3(); // Placeholder
}

Vector3 Weapon::GetRecoilVector() const {
    return Vector3(); // Placeholder
}

int Weapon::GetSkinID() const {
    if (!IsValid()) {
        return 0;
    }
    
    // This would read skin ID from game memory
    // For now, return 0 (default skin)
    return 0;
}

void Weapon::SetSkinID(int skinID) {
    // This would set skin ID in game memory
    // Placeholder implementation
}

int Weapon::GetStatTrack() const {
    return 0; // Placeholder
}

int Weapon::GetKillEater() const {
    return 0; // Placeholder
}

std::string Weapon::GetCustomName() const {
    return ""; // Placeholder
}

uintptr_t Weapon::GetModel() const {
    return 0; // Placeholder
}

uintptr_t Weapon::GetWorldModel() const {
    return 0; // Placeholder
}

std::string Weapon::GetModelName() const {
    return ""; // Placeholder
}

std::string Weapon::GetWorldModelName() const {
    return ""; // Placeholder
}

int Weapon::GetMaxWeapons() {
    return 64; // Maximum number of weapons
}

Weapon Weapon::GetByIndex(int index) {
    if (index < 0 || index >= GetMaxWeapons()) {
        return Weapon();
    }
    
    // This would get weapon by index from game memory
    // For now, create placeholder weapon
    return Weapon(0x2000 + index * 0x100, index, index % 10);
}

std::vector<Weapon> Weapon::GetAllWeapons() {
    std::vector<Weapon> weapons;
    
    for (int i = 0; i < GetMaxWeapons(); i++) {
        Weapon weapon = GetByIndex(i);
        if (weapon.IsValid()) {
            weapons.push_back(weapon);
        }
    }
    
    return weapons;
}

std::vector<Weapon> Weapon::GetWeaponsByOwner(int ownerIndex) {
    std::vector<Weapon> ownerWeapons;
    auto allWeapons = GetAllWeapons();
    
    for (const auto& weapon : allWeapons) {
        if (weapon.GetOwner() == ownerIndex) {
            ownerWeapons.push_back(weapon);
        }
    }
    
    return ownerWeapons;
}

std::string Weapon::ToString() const {
    std::string result = "Weapon(";
    result += "Index: " + std::to_string(m_Index) + ", ";
    result += "Name: " + GetName() + ", ";
    result += "Ammo: " + std::to_string(GetAmmo()) + "/" + std::to_string(GetMaxAmmo());
    result += ")";
    
    return result;
}