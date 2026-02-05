#ifndef LIBX_MAIN_H
#define LIBX_MAIN_H

#include <jni.h>
#include <android/log.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <android/native_window.h>
#include <android/input.h>

// ImGui includes
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_android.h"

// Math includes
#include "Vector2.h"
#include "Vector3.h"

// Forward declarations
class GUI;
class ESP;
class Aimbot;
class Config;

// Global variables
extern GUI* g_GUI;
extern ESP* g_ESP;
extern Aimbot* g_Aimbot;

// JNI functions for Android
extern "C" {
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);
    JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved);
    
    JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeInit(JNIEnv* env, jobject thiz, jobject surface);
    JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeShutdown(JNIEnv* env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeRender(JNIEnv* env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_example_libx_MainActivity_nativeHandleInput(JNIEnv* env, jobject thiz, jobject motion_event);
}

// Main initialization function
void Initialize(ANativeWindow* window);
void Shutdown();
void Render();
void HandleInputEvent(AInputEvent* event);

#endif // LIBX_MAIN_H