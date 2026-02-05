#ifndef LIBX_AIMBOT_H
#define LIBX_AIMBOT_H

#include "../entities/Player.h"
#include "../entities/Weapon.h"
#include "../math/Vector3.h"
#include "imgui.h"
#include "../config/Config.h"

class Aimbot {
private:
    bool m_Enabled;
    AimbotConfig m_Config;
    
    // Current target
    Player m_CurrentTarget;
    int m_TargetBone;
    
    // Aimbot state
    bool m_AimActive;
    Vector3 m_AimAngle;
    Vector3 m_RecoilAngle;
    
    // Prediction
    Vector3 m_PredictedPosition;
    Vector3 m_PredictedVelocity;
    bool m_PredictionEnabled;
    
public:
    Aimbot();
    virtual ~Aimbot();
    
    // Lifecycle
    bool Init();
    void Shutdown();
    void Update();
    void Toggle();
    bool IsEnabled() const { return m_Enabled; }
    
    // Configuration
    void SetConfig(const AimbotConfig& config);
    AimbotConfig GetConfig() const { return m_Config; }
    
    // Targeting
    void FindBestTarget();
    Player GetBestTarget();
    int GetBestBone(const Player& target);
    
    // Aiming
    void AimAt(const Player& target, int bone = 6);
    void AimAtPosition(const Vector3& position);
    void SmoothAim(const Vector3& targetAngle, float smoothing);
    void ApplyRecoil();
    
    // Validation
    bool IsTargetValid(const Player& target);
    bool IsTargetInFOV(const Player& target, float fov = 10.0f);
    bool IsTargetInRange(const Player& target, float range = 1000.0f);
    bool IsTargetVisible(const Player& target);
    bool IsTargetHittable(const Player& target, int bone);
    
    // Calculations
    float CalculateFOV(const Player& target, int bone = 6);
    float CalculateDistance(const Player& target);
    float CalculateHitChance(const Player& target, int bone);
    Vector3 CalculatePrediction(const Player& target);
    Vector3 CalculateLeading(const Player& target);
    
    // Triggerbot integration
    bool ShouldFire();
    bool ShouldFireAtTarget(const Player& target);
    bool IsShooting();
    
    // Smoothing and control
    Vector3 GetCurrentAim();
    Vector3 GetTargetAim();
    void SetAimAngle(const Vector3& angle);
    void ResetAim();
    
    // Bone selection
    int SelectBestBone(const Player& target);
    std::vector<int> GetPriorityBones();
    bool IsBoneVisible(const Player& target, int bone);
    
    // Target filtering
    bool FilterEnemies(const Player& target);
    bool FilterFriends(const Player& target);
    bool FilterDead(const Player& target);
    bool FilterInvalid(const Player& target);
    
    // Multi-target support
    void CycleTarget();
    void SetTarget(const Player& target);
    Player GetCurrentTarget() const { return m_CurrentTarget; }
    
    // Silent aim
    void EnableSilentAim(bool enable);
    bool IsSilentAimEnabled() const { return m_Config.silent; }
    
    // Humanization
    void AddHumanization(float jitter = 2.0f);
    void AddTimingDelay(int minMs = 50, int maxMs = 200);
    
    // Debug information
    void RenderDebugInfo();
    std::string GetTargetInfo();
    
    // Legit bot features
    void EnableLegitMode(bool enable);
    void SetFOVWhileScoping(bool enable);
    void EnableAutoScope(bool enable);
    
private:
    void InitializeAimbot();
    void CleanupAimbot();
    
    // Target evaluation
    float EvaluateTarget(const Player& target);
    float EvaluateBone(const Player& target, int bone);
    float EvaluateDistance(const Player& target);
    float EvaluateVisibility(const Player& target);
    float EvaluateHealth(const Player& target);
    
    // Math helpers
    Vector3 CalculateAngle(const Vector3& source, const Vector3& destination);
    Vector3 ClampAngle(const Vector3& angle);
    float GetAngleDifference(const Vector3& angle1, const Vector3& angle2);
    bool IsAngleVisible(const Vector3& angle);
    
    // Settings validation
    void ValidateConfig();
    void UpdateSettings();
};

#endif // LIBX_AIMBOT_H