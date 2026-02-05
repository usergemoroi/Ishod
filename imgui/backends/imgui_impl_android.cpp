#include "imgui.h"
#include <android/input.h>
#include <android/native_window.h>
#include <android/log.h>

static ANativeWindow* g_Window = nullptr;
static int32_t g_Width = 0;
static int32_t g_Height = 0;
static float g_MouseWheel = 0.0f;

bool ImGui_ImplAndroid_Init(ANativeWindow* window) {
    g_Window = window;
    if (g_Window) {
        g_Width = ANativeWindow_getWidth(g_Window);
        g_Height = ANativeWindow_getHeight(g_Window);
    }
    
    // Setup ImGui IO
    ImGuiIO& io = ImGui::GetIO();
    io.KeyMap[ImGuiKey_Tab] = AKEYCODE_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = AKEYCODE_DPAD_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = AKEYCODE_DPAD_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = AKEYCODE_DPAD_UP;
    io.KeyMap[ImGuiKey_DownArrow] = AKEYCODE_DPAD_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = AKEYCODE_PAGE_UP;
    io.KeyMap[ImGuiKey_PageDown] = AKEYCODE_PAGE_DOWN;
    io.KeyMap[ImGuiKey_Home] = AKEYCODE_MOVE_HOME;
    io.KeyMap[ImGuiKey_End] = AKEYCODE_MOVE_END;
    io.KeyMap[ImGuiKey_Insert] = AKEYCODE_INSERT;
    io.KeyMap[ImGuiKey_Delete] = AKEYCODE_FORWARD_DEL;
    io.KeyMap[ImGuiKey_Backspace] = AKEYCODE_DEL;
    io.KeyMap[ImGuiKey_Space] = AKEYCODE_SPACE;
    io.KeyMap[ImGuiKey_Enter] = AKEYCODE_ENTER;
    io.KeyMap[ImGuiKey_Escape] = AKEYCODE_ESCAPE;
    io.KeyMap[ImGuiKey_A] = AKEYCODE_A;
    io.KeyMap[ImGuiKey_C] = AKEYCODE_C;
    io.KeyMap[ImGuiKey_V] = AKEYCODE_V;
    io.KeyMap[ImGuiKey_X] = AKEYCODE_X;
    io.KeyMap[ImGuiKey_Y] = AKEYCODE_Y;
    io.KeyMap[ImGuiKey_Z] = AKEYCODE_Z;
    
    return true;
}

void ImGui_ImplAndroid_Shutdown() {
    g_Window = nullptr;
}

void ImGui_ImplAndroid_NewFrame() {
    ImGuiIO& io = ImGui::GetIO();
    
    // Setup display size (every frame to accommodate for window rotation)
    if (g_Window) {
        g_Width = ANativeWindow_getWidth(g_Window);
        g_Height = ANativeWindow_getHeight(g_Window);
    }
    
    io.DisplaySize = ImVec2((float)g_Width, (float)g_Height);
    
    // Setup time step
    static double g_Time = 0.0;
    const double current_time = 0.0; // Placeholder time
    io.DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)(1.0f / 60.0f);
    g_Time = current_time;
    
    // Handle mouse wheel
    io.MouseWheel = g_MouseWheel;
    g_MouseWheel = 0.0f;
}

bool ImGui_ImplAndroid_HandleInputEvent(AInputEvent* event) {
    if (!event) return false;
    
    ImGuiIO& io = ImGui::GetIO();
    int32_t event_type = AInputEvent_getType(event);
    
    switch (event_type) {
        case AINPUT_EVENT_TYPE_KEY: {
            int32_t action = AKeyEvent_getAction(event);
            int32_t key_code = AKeyEvent_getKeyCode(event);
            bool down = (action == AKEY_EVENT_ACTION_DOWN);
            
            io.KeysDown[key_code] = down;
            
            // Also update ctrl, shift, alt states
            if (key_code == AKEYCODE_SHIFT_LEFT || key_code == AKEYCODE_SHIFT_RIGHT) {
                io.KeyShift = down;
            }
            if (key_code == AKEYCODE_ALT_LEFT || key_code == AKEYCODE_ALT_RIGHT) {
                io.KeyAlt = down;
            }
            if (key_code == AKEYCODE_CTRL_LEFT || key_code == AKEYCODE_CTRL_RIGHT) {
                io.KeyCtrl = down;
            }
            
            return true;
        }
        
        case AINPUT_EVENT_TYPE_MOTION: {
            int32_t action = AMotionEvent_getAction(event);
            int32_t pointer_index = (action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK) >> AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
            action &= AMOTION_EVENT_ACTION_MASK;
            
            AMotionEvent_getX(event, pointer_index);
            AMotionEvent_getY(event, pointer_index);
            
            switch (action) {
                case AMOTION_EVENT_ACTION_DOWN:
                case AMOTION_EVENT_ACTION_POINTER_DOWN:
                    io.MouseDown[0] = true;
                    break;
                    
                case AMOTION_EVENT_ACTION_UP:
                case AMOTION_EVENT_ACTION_POINTER_UP:
                    io.MouseDown[0] = false;
                    break;
                    
                case AMOTION_EVENT_ACTION_MOVE:
                    // Handle mouse move
                    break;
            }
            
            return true;
        }
    }
    
    return false;
}

void ImGui_ImplAndroid_SetDisplaySize(int32_t width, int32_t height) {
    g_Width = width;
    g_Height = height;
}

int32_t ImGui_ImplAndroid_GetDisplayWidth() {
    return g_Width;
}

int32_t ImGui_ImplAndroid_GetDisplayHeight() {
    return g_Height;
}

void ImGui_ImplAndroid_MouseWheel(ANativeWindow* window, float wheel) {
    g_MouseWheel = wheel;
}

bool ImGui_ImplAndroid_GetMouseDown(ImGuiMouseButton button) {
    ImGuiIO& io = ImGui::GetIO();
    return io.MouseDown[button];
}

void ImGui_ImplAndroid_SetMouseDown(ImGuiMouseButton button, bool down) {
    ImGuiIO& io = ImGui::GetIO();
    io.MouseDown[button] = down;
}

void ImGui_ImplAndroid_SetMousePos(float x, float y) {
    ImGuiIO& io = ImGui::GetIO();
    io.MousePos = ImVec2(x, y);
}