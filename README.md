# LibX - Android Gaming Overlay Library

LibX is a comprehensive gaming overlay library for Android that provides ESP (Extra Sensory Perception), Aimbot, and various gaming enhancements using ImGui for the user interface.

## Features

### ESP (Extra Sensory Perception)
- **Player ESP**: Display player names, health, distances
- **Weapon ESP**: Show weapon information and ammo
- **Grenade ESP**: Track grenades with timer and trajectory
- **Skeleton ESP**: Visual bone structure rendering
- **Health Bars**: Visual health indicators
- **Configurable colors and ranges**

### Aimbot
- **FOV-based targeting**: Configurable field of view
- **Bone selection**: Aim at different body parts
- **Silent aim**: Aimbot without visible movement
- **Target filtering**: Exclude friends, dead players
- **Prediction**: Lead moving targets
- **Auto-fire**: Automatic shooting triggers

### Visual Enhancements
- **Crosshair**: Customizable crosshair overlay
- **Radar**: Mini-map radar implementation
- **FPS Counter**: Performance monitoring
- **Coordinates display**: Real-time position info

### Exploits
- **Rapid Fire**: Increased fire rate
- **No Recoil**: Eliminate weapon recoil
- **No Spread**: Remove weapon spread
- **Fast Reload**: Instant reload times
- **Bunny Hop**: Continuous jumping
- **Auto Strafe**: Automatic strafe optimization

### Configuration System
- **Multiple configs**: Save/load different settings
- **Auto-save**: Automatic configuration backup
- **Import/Export**: Share configurations
- **Default profiles**: Pre-configured setups

## Project Structure

```
libx/
├── main.cpp                 # Main entry point
├── libx.h                  # Main header file
├── CMakeLists.txt          # Build configuration
│
├── config/                 # Configuration management
│   ├── Config.h           # Configuration structures
│   └── Config.cpp         # Configuration implementation
│
├── entities/              # Game entity classes
│   ├── Player.h           # Player entity definition
│   ├── Player.cpp         # Player implementation
│   ├── Weapon.h           # Weapon entity definition
│   ├── Weapon.cpp         # Weapon implementation
│   ├── Grenade.h          # Grenade entity definition
│   └── Grenade.cpp        # Grenade implementation
│
├── math/                  # Mathematical utilities
│   ├── Vector2.h         # 2D vector operations
│   ├── Vector2.cpp       # 2D vector implementation
│   ├── Vector3.h         # 3D vector operations
│   └── Vector3.cpp       # 3D vector implementation
│
├── gui/                   # Graphical user interface
│   ├── GUI.h             # GUI class definition
│   └── GUI.cpp           # GUI implementation
│
├── esp/                   # ESP functionality
│   ├── ESP.h             # ESP class definition
│   └── ESP.cpp           # ESP implementation
│
├── aimbot/               # Aimbot functionality
│   ├── Aimbot.h          # Aimbot class definition
│   └── Aimbot.cpp        # Aimbot implementation
│
├── game/                 # Game integration
│   ├── Game.h            # Game class definition
│   └── Game.cpp          # Game implementation
│
├── imgui/                # ImGui UI framework
│   ├── imgui.h           # ImGui headers
│   ├── imgui.cpp         # ImGui implementation
│   ├── imgui_widgets.cpp # Widget implementations
│   ├── imgui_draw.cpp    # Drawing utilities
│   ├── imgui_tables.cpp  # Table functionality
│   └── backends/         # Platform backends
│       ├── imgui_impl_opengl3.cpp # OpenGL backend
│       └── imgui_impl_android.cpp # Android backend
│
└── imgl3w/               # OpenGL loader
    ├── imgl3w.h          # OpenGL loader headers
    └── imgl3w.cpp        # OpenGL loader implementation
```

## Architecture

### Core Classes

1. **GUI**: Main interface class managing the ImGui overlay
2. **ESP**: Extra Sensory Perception rendering system
3. **Aimbot**: Automated targeting system
4. **Game**: Game state and entity management
5. **Config**: Configuration management system
6. **Entity Classes**: Player, Weapon, Grenade representations

### Math Utilities

- **Vector2**: 2D vector operations (position, velocity)
- **Vector3**: 3D vector operations (world positions, angles)

### Platform Integration

- **Android**: Native Android integration with JNI
- **OpenGL ES 3.0**: Graphics rendering backend
- **ImGui**: Immediate mode GUI framework

## Dependencies

- **ImGui**: Immediate mode GUI library
- **OpenGL ES 3.0**: Graphics rendering
- **Android NDK**: Native development kit
- **Android Logging**: Debug and error logging

## Building

### Prerequisites
- Android NDK
- CMake 3.16+
- OpenGL ES 3.0 compatible device
- Android API level 21+

### Build Steps
1. Clone the repository
2. Set up Android NDK environment
3. Create build directory
4. Run CMake configuration
5. Build the shared library

```bash
# Example build commands
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=$NDK/build/cmake/android.toolchain.cmake \
      -DANDROID_ABI=arm64-v8a \
      -DANDROID_PLATFORM=android-21 \
      ..
make -j$(nproc)
```

## Usage

### Initialization
```cpp
#include "libx.h"

// Initialize LibX with Android surface
JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeInit(
    JNIEnv* env, jobject thiz, jobject surface) {
    
    ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
    Initialize(window);
}
```

### Main Loop
```cpp
void RenderFrame() {
    Render();  // Process game logic and render overlay
}
```

### Input Handling
```cpp
void HandleInput(AInputEvent* event) {
    HandleInputEvent(event);  // Forward input to GUI
}
```

## Configuration

### Aimbot Settings
```cpp
AimbotConfig config;
config.enabled = true;
config.fov = 10.0f;
config.range = 1000.0f;
config.bone = 6;  // Head
config.speed = 5.0f;
config.silent = false;
config.aimlock = true;
```

### ESP Settings
```cpp
ESPConfig config;
config.enabled = true;
config.players = true;
config.weapons = true;
config.grenades = true;
config.skeleton = true;
config.health_bar = true;
config.max_distance = 1000.0f;
```

## Safety and Ethics

⚠️ **IMPORTANT**: This library is for educational and research purposes only. Users are responsible for:

- Complying with game Terms of Service
- Following applicable laws and regulations
- Using the software responsibly and ethically
- Understanding the risks of account penalties

## Features Roadmap

### Planned Features
- [ ] Support for multiple games
- [ ] Advanced aimbot features (legit aim)
- [ ] More ESP visualization options
- [ ] Scripting system for custom features
- [ ] Cloud configuration sync
- [ ] Performance optimization
- [ ] Additional exploits and enhancements

### Known Limitations
- Currently supports specific games only
- Requires root access for some games
- Performance impact depends on device
- Some features may be detected by anti-cheat systems

## Development

### Contributing
1. Fork the repository
2. Create feature branch
3. Make changes with proper testing
4. Submit pull request with description

### Code Style
- Follow C++17 standards
- Use consistent naming conventions
- Add comments for complex logic
- Maintain modular architecture

### Testing
- Test on multiple Android devices
- Verify performance impact
- Check for memory leaks
- Validate configuration persistence

## License

This project is for educational purposes only. See LICENSE file for details.

## Disclaimer

This software is provided "as is" without warranty of any kind. The authors are not responsible for any consequences arising from the use of this software. Users must comply with all applicable laws and game terms of service.

## Contact

For questions, issues, or contributions, please refer to the project repository.