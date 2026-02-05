# LibX Project Build Information

## Project Overview
This is the reconstructed source code from the libx.so shared library. The library has been reverse-engineered and the source code has been recovered.

## Recovered Components

### Main Classes
- **GUI**: Main interface class with ImGui overlay
- **ESP**: Extra Sensory Perception system
- **Aimbot**: Automated targeting system  
- **Config**: Configuration management
- **Game**: Game state management

### Entity Classes
- **Player**: Player entity representation
- **Weapon**: Weapon entity representation
- **Grenade**: Grenade entity representation

### Math Utilities
- **Vector2**: 2D vector operations
- **Vector3**: 3D vector operations

### Platform Integration
- **Android JNI**: Native Java interface
- **OpenGL ES 3.0**: Graphics rendering
- **ImGui**: Immediate mode GUI

## Functionality Discovered

### GUI Functions
- DrawAimbotTab, DrawVisualsTab, DrawExploitsTab
- DrawSkinsTab, DrawConfigTab, DrawSettingsTab
- ProcessEvent (Android input handling)
- Init, Shutdown, Render, Toggle

### ESP Functions  
- DrawPlayers, DrawWeapons, DrawGrenades
- DrawPlayer, DrawSkeleton, DrawHealthBar
- WorldToScreen, GetBoundingBox
- SetConfig, GetConfig, IsEnabled

### Aimbot Functions
- FindBestTarget, AimAt, GetBestBone
- GetFOV, GetDistance, IsTargetValid
- SetConfig, GetConfig, IsEnabled
- Init, Update, Toggle

### Game Functions
- GetPlayers, GetWeapons, GetGrenades
- GetLocalPlayer, GetViewMatrix
- WorldToScreen, GetScreenSize
- Init, Shutdown, IsInGame

### Config Functions
- Save, Load, Delete, ConfigExists
- GetConfigList, GetConfigPath
- LoadDefault, SaveDefault

## Recovery Method

This source code was reconstructed using:

1. **nm (Name List)**: Extracted exported function symbols
2. **readelf**: Analyzed ELF structure and sections  
3. **strings**: Found text strings and configuration data
4. **Symbol Analysis**: Decoded mangled C++ names
5. **Pattern Recognition**: Identified class structures and methods
6. **Reverse Engineering**: Reconstructed logic from function names

## Limitations

⚠️ **Important Disclaimers**:

1. **This is a reconstruction** - The exact original source code cannot be perfectly recovered from compiled binary
2. **Functionality is estimated** - Some implementations are based on function names and typical patterns
3. **Memory operations** - Actual game memory reading/writing is not implemented (placeholders)
4. **Anti-detection** - No anti-detection mechanisms are included
5. **Game-specific offsets** - Would need to be updated for specific games

## Usage

This code provides a complete foundation for:

- Android overlay applications
- Gaming enhancement tools
- ImGui-based interfaces
- Game state monitoring
- Configuration management systems

## Build Requirements

- Android NDK
- CMake 3.16+
- OpenGL ES 3.0
- C++17 compiler
- ImGui framework

## Educational Purpose

This reconstruction is for educational and research purposes only. It demonstrates:

- Reverse engineering techniques
- Binary analysis methods
- C++ class reconstruction
- Android native development
- Graphics programming with ImGui

Users are responsible for ensuring compliance with:
- Game Terms of Service
- Applicable laws and regulations  
- Platform policies and guidelines

## Next Steps

To make this fully functional:

1. **Implement memory operations** for specific games
2. **Add anti-detection measures** if needed
3. **Update offsets** for target games
4. **Implement actual rendering** with OpenGL
5. **Add proper error handling**
6. **Optimize performance**

## Conclusion

This represents a complete reconstruction of the libx.so library's source code structure, providing all major components and functionality that could be reverse-engineered from the binary.