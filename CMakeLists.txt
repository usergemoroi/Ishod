cmake_minimum_required(VERSION 3.16)
project(LibX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)

# ImGui requires specific definitions for Android
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GL3W=1)
add_definitions(-DGL_SILENCE_DEPRECATION=1)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/math
)

# Source files
set(SOURCES
    main.cpp
    gui/GUI.cpp
    esp/ESP.cpp
    aimbot/Aimbot.cpp
    config/Config.cpp
    game/Game.cpp
    entities/Player.cpp
    entities/Weapon.cpp
    entities/Grenade.cpp
    math/Vector2.cpp
    math/Vector3.cpp
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/backends/imgui_impl_android.cpp
    imgl3w/imgl3w.cpp
)

# Create shared library
add_library(libx SHARED ${SOURCES})

# Link libraries
target_link_libraries(libx
    ${OPENGL_LIBRARIES}
    Threads::Threads
    dl
    log
    android
)

# Set output name
set_target_properties(libx PROPERTIES OUTPUT_NAME "x")