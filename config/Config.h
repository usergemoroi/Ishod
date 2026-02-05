#ifndef LIBX_CONFIG_MANAGER_H
#define LIBX_CONFIG_MANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include "Config.h"

class ConfigManager {
private:
    std::string m_ConfigPath;
    std::string m_DefaultConfigName;
    
    // Current configurations
    AimbotConfig m_AimbotConfig;
    ESPConfig m_ESPConfig;
    VisualConfig m_VisualConfig;
    ExploitConfig m_ExploitConfig;
    SkinConfig m_SkinConfig;
    SettingsConfig m_SettingsConfig;
    
public:
    ConfigManager();
    virtual ~ConfigManager();
    
    // Path management
    void SetConfigPath(const std::string& path);
    std::string GetConfigPath() const { return m_ConfigPath; }
    std::string GetConfigPathB5cxx11() const;
    
    // Config management
    bool Save(const std::string& name);
    bool Load(const std::string& name);
    bool Delete(const std::string& name);
    bool ConfigExists(const std::string& name);
    std::vector<ConfigEntry> GetConfigList();
    
    // Default config
    void LoadDefault();
    void SaveDefault();
    bool HasDefault() const;
    
    // Individual config saving/loading
    bool SaveAimbotConfig(const std::string& name);
    bool LoadAimbotConfig(const std::string& name);
    
    bool SaveESPConfig(const std::string& name);
    bool LoadESPConfig(const std::string& name);
    
    bool SaveVisualConfig(const std::string& name);
    bool LoadVisualConfig(const std::string& name);
    
    bool SaveExploitConfig(const std::string& name);
    bool LoadExploitConfig(const std::string& name);
    
    bool SaveSkinConfig(const std::string& name);
    bool LoadSkinConfig(const std::string& name);
    
    bool SaveSettingsConfig(const std::string& name);
    bool LoadSettingsConfig(const std::string& name);
    
    // Getters and setters for configurations
    AimbotConfig GetAimbotConfig() const { return m_AimbotConfig; }
    void SetAimbotConfig(const AimbotConfig& config) { m_AimbotConfig = config; }
    
    ESPConfig GetESPConfig() const { return m_ESPConfig; }
    void SetESPConfig(const ESPConfig& config) { m_ESPConfig = config; }
    
    VisualConfig GetVisualConfig() const { return m_VisualConfig; }
    void SetVisualConfig(const VisualConfig& config) { m_VisualConfig = config; }
    
    ExploitConfig GetExploitConfig() const { return m_ExploitConfig; }
    void SetExploitConfig(const ExploitConfig& config) { m_ExploitConfig = config; }
    
    SkinConfig GetSkinConfig() const { return m_SkinConfig; }
    void SetSkinConfig(const SkinConfig& config) { m_SkinConfig = config; }
    
    SettingsConfig GetSettingsConfig() const { return m_SettingsConfig; }
    void SetSettingsConfig(const SettingsConfig& config) { m_SettingsConfig = config; }
    
    // Import/Export
    bool ExportConfig(const std::string& name, const std::string& destination);
    bool ImportConfig(const std::string& source, const std::string& name);
    
    // Reset to defaults
    void ResetAimbotConfig();
    void ResetESPConfig();
    void ResetVisualConfig();
    void ResetExploitConfig();
    void ResetSkinConfig();
    void ResetSettingsConfig();
    void ResetAllConfigs();
    
    // Validation
    bool ValidateConfig(const std::string& name);
    void ValidateConfigs();
    
    // Auto-save functionality
    void EnableAutoSave(bool enable);
    void SetAutoSaveInterval(int minutes);
    
    // Backup functionality
    bool CreateBackup(const std::string& name);
    bool RestoreBackup(const std::string& name);
    std::vector<std::string> GetBackupList();
    
private:
    void InitializeDefaultConfigs();
    std::string GetConfigFileName(const std::string& name) const;
    bool CreateDirectory(const std::string& path) const;
    bool IsValidConfigName(const std::string& name) const;
    
    // Serialization helpers
    template<typename T>
    bool SerializeConfig(const T& config, std::ofstream& file);
    
    template<typename T>
    bool DeserializeConfig(T& config, std::ifstream& file);
    
    // Config structure validation
    bool ValidateAimbotConfig(const AimbotConfig& config);
    bool ValidateESPConfig(const ESPConfig& config);
    bool ValidateVisualConfig(const VisualConfig& config);
    bool ValidateExploitConfig(const ExploitConfig& config);
    bool ValidateSkinConfig(const SkinConfig& config);
    bool ValidateSettingsConfig(const SettingsConfig& config);
    
    // String utilities
    static std::string Trim(const std::string& str);
    static std::string EscapeString(const std::string& str);
    static std::string UnescapeString(const std::string& str);
};

#endif // LIBX_CONFIG_MANAGER_H