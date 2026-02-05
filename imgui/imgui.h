#ifndef IMGUI_H
#define IMGUI_H

// Dear ImGui - a game developer targeted GUI library
// Version 1.91 (headers only)
// Help: https://github.com/ocornut/imgui

#include <stdint.h>
#include <stddef.h>

// Define assertion handler (by default we use assert.h)
#ifndef IM_ASSERT
#include <assert.h>
#define IM_ASSERT(_EXPR)  assert(_EXPR)
#endif

// Define attributes
#ifndef IMGUI_API
#define IMGUI_API
#endif

// Define deprecated macroes for backward compatibility
#ifndef IMGUI_DISABLE_DEPRECATED_API
#define IMGUI_DISABLE_DEPRECATED_WARNING
#endif

// Helper Macros
#ifndef IM_ARRAYSIZE
#define IM_ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR)/sizeof(*(_ARR))))
#endif

// Forward declarations
struct ImDrawCmd;
struct ImDrawData;
struct ImDrawList;
struct ImDrawVert;
struct ImFont;
struct ImFontAtlas;
struct ImFontConfig;
struct ImGuiContext;
struct ImGuiIO;
struct ImGuiInputTextCallbackData;
struct ImGuiListClipper;
struct ImGuiOnceUponAFrame;
struct ImGuiPayload;
struct ImGuiSizeConstraintCallbackData;
struct ImGuiStorage;
struct ImGuiStyle;
struct ImGuiTextBuffer;
struct ImGuiTextFilter;
struct ImGuiViewport;

// Basic Types
typedef unsigned int ImU32;
typedef unsigned short ImWchar;
typedef void* ImTextureID;
typedef int ImGuiCol;
typedef int ImGuiCond;
typedef int ImGuiDataType;
typedef int ImGuiDir;
typedef int ImGuiKey;
typedef int ImGuiMouseButton;
typedef int ImGuiMouseCursor;
typedef int ImGuiStyleVar;
typedef int ImGuiTabBarFlags;
typedef int ImGuiTabItemFlags;
typedef int ImGuiTreeNodeFlags;
typedef int ImGuiWindowFlags;
typedef int (*ImGuiInputTextCallback)(ImGuiTextEditCallbackData* data);
typedef void (*ImGuiSizeConstraintCallback)(ImGuiSizeConstraintCallbackData* data);
typedef void (*ImGuiErrorLogCallback)(void* user_data, const char* fmt, ...);

// Simple types
struct ImVec2 {
    float x, y;
    ImVec2() { x = y = 0.0f; }
    ImVec2(float _x, float _y) { x = _x; y = _y; }
};

struct ImVec4 {
    float x, y, z, w;
    ImVec4() { x = y = z = w = 0.0f; }
    ImVec4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }
};

// ImGui main context
IMGUI_API ImGuiContext* CreateContext(ImFontAtlas* shared_font_atlas = NULL);
IMGUI_API void DestroyContext(ImGuiContext* ctx = NULL);
IMGUI_API ImGuiContext* GetCurrentContext();
IMGUI_API void SetCurrentContext(ImGuiContext* ctx);

// Main
IMGUI_API void NewFrame();
IMGUI_API void Render();
IMGUI_API ImDrawData* GetDrawData();

// Demo, Debug, Information
IMGUI_API void ShowDemoWindow(bool* p_open = NULL);
IMGUI_API void ShowMetricsWindow(bool* p_open = NULL);
IMGUI_API void ShowStyleEditor(ImGuiStyle* ref = NULL);
IMGUI_API void ShowStyleSelector(const char* label);
IMGUI_API void ShowFontSelector(const char* label);
IMGUI_API void ShowUserGuide();
IMGUI_API void GetVersion(char* buf, int buf_size);

// Styles
IMGUI_API void StyleColorsClassic(ImGuiStyle* dst = NULL);
IMGUI_API void StyleColorsDark(ImGuiStyle* dst = NULL);
IMGUI_API void StyleColorsLight(ImGuiStyle* dst = NULL);

// IO
IMGUI_API ImGuiIO& GetIO();

// Style
IMGUI_API ImGuiStyle& GetStyle();

// Windows
IMGUI_API void Begin(const char* name, bool* p_open = NULL);
IMGUI_API void End();
IMGUI_API bool BeginChild(const char* str_id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0);
IMGUI_API bool BeginChild(ImGuiID id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0);
IMGUI_API void EndChild();

// Windows Utilities
IMGUI_API bool IsWindowAppearing();
IMGUI_API bool IsWindowCollapsed();
IMGUI_API bool IsWindowFocused(ImGuiWindowFlags flags = 0);
IMGUI_API bool IsWindowHovered(ImGuiWindowFlags flags = 0);
IMGUI_API ImDrawList* GetWindowDrawList();
IMGUI_API ImVec2 GetWindowPos();
IMGUI_API ImVec2 GetWindowSize();
IMGUI_API float GetWindowWidth();
IMGUI_API float GetWindowHeight();

// Content region
IMGUI_API ImVec2 GetContentRegionMax();
IMGUI_API ImVec2 GetContentRegionAvail();
IMGUI_API float GetContentRegionAvailWidth();
IMGUI_API ImVec2 GetWindowContentRegionMin();
IMGUI_API ImVec2 GetWindowContentRegionMax();

// Windows Scrolling
IMGUI_API void SetScrollX(float scroll_x);
IMGUI_API void SetScrollY(float scroll_y);
IMGUI_API void SetScrollHereX(float center_x_ratio = 0.5f);
IMGUI_API void SetScrollHereY(float center_y_ratio = 0.5f);
IMGUI_API void SetScrollFromPosX(float local_x, float center_x_ratio = 0.5f);
IMGUI_API void SetScrollFromPosY(float local_y, float center_y_ratio = 0.5f);
IMGUI_API float GetScrollX();
IMGUI_API float GetScrollY();
IMGUI_API float GetScrollMaxX();
IMGUI_API float GetScrollMaxY();
IMGUI_API void SetScrollAllowMousewheel(bool allow);

// Parameters stacks (shared)
IMGUI_API void PushFont(ImFont* font);
IMGUI_API void PopFont();
IMGUI_API void PushStyleColor(ImGuiCol idx, ImU32 col);
IMGUI_API void PushStyleColor(ImGuiCol idx, const ImVec4& col);
IMGUI_API void PopStyleColor(int count = 1);
IMGUI_API void PushStyleVar(ImGuiStyleVar idx, float val);
IMGUI_API void PushStyleVar(ImGuiStyleVar idx, const ImVec2& val);
IMGUI_API void PopStyleVar(int count = 1);
IMGUI_API void PushAllowKeyboardFocus(bool allow_keyboard_focus);
IMGUI_API void PopAllowKeyboardFocus();
IMGUI_API void PushTextWrapPos(float wrap_local_pos_x = 0.0f);
IMGUI_API void PopTextWrapPos();

// Cursor/Layout
IMGUI_API void Separator();
IMGUI_API void SameLine(float local_pos_x = 0.0f, float spacing_w = -1.0f);
IMGUI_API void NewLine();
IMGUI_API void Spacing();
IMGUI_API void Dummy(const ImVec2& size);
IMGUI_API void Indent(float indent_w = 0.0f);
IMGUI_API void Unindent(float indent_w = 0.0f);
IMGUI_API void BeginGroup();
IMGUI_API void EndGroup();
IMGUI_API ImVec2 GetCursorPos();
IMGUI_API float GetCursorPosX();
IMGUI_API float GetCursorPosY();
IMGUI_API void SetCursorPos(const ImVec2& local_pos);
IMGUI_API void SetCursorPosX(float x);
IMGUI_API void SetCursorPosY(float y);
IMGUI_API ImVec2 GetCursorStartPos();
IMGUI_API ImVec2 GetCursorScreenPos();
IMGUI_API void SetCursorScreenPos(const ImVec2& screen_pos);
IMGUI_API void AlignTextToFramePadding();
IMGUI_API float GetTextLineHeight();
IMGUI_API float GetTextLineHeightWithSpacing();
IMGUI_API float GetFrameHeight();
IMGUI_API float GetFrameHeightWithSpacing();

// ID scope
IMGUI_API void PushID(const char* str_id);
IMGUI_API void PushID(const char* str_id_begin, const char* str_id_end);
IMGUI_API void PushID(const void* ptr_id);
IMGUI_API void PushID(int int_id);
IMGUI_API void PopID();

// Widgets: Text
IMGUI_API void Text(const char* fmt, ...) IM_PRINTFARGS(1);
IMGUI_API void TextV(const char* fmt, va_list args);
IMGUI_API void TextColored(const ImVec4& col, const char* fmt, ...) IM_PRINTFARGS(2);
IMGUI_API void TextColoredV(const ImVec4& col, const char* fmt, va_list args);
IMGUI_API void TextDisabled(const char* fmt, ...) IM_PRINTFARGS(1);
IMGUI_API void TextDisabledV(const char* fmt, va_list args);
IMGUI_API void TextWrapped(const char* fmt, ...) IM_PRINTFARGS(1);
IMGUI_API void TextWrappedV(const char* fmt, va_list args);
IMGUI_API void LabelText(const char* label, const char* fmt, ...) IM_PRINTFARGS(2);
IMGUI_API void LabelTextV(const char* label, const char* fmt, va_list args);
IMGUI_API void BulletText(const char* fmt, ...) IM_PRINTFARGS(1);
IMGUI_API void BulletTextV(const char* fmt, va_list args);

// Widgets: Main
IMGUI_API bool Button(const char* label, const ImVec2& size = ImVec2(0, 0));
IMGUI_API bool SmallButton(const char* label);
IMGUI_API bool InvisibleButton(const char* str_id, const ImVec2& size);
IMGUI_API bool ArrowButton(const char* str_id, ImGuiDir dir);
IMGUI_API void Image(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), const ImVec4& tint_col = ImVec4(1, 1, 1, 1), const ImVec4& border_col = ImVec4(0, 0, 0, 0));
IMGUI_API bool ImageButton(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), int frame_padding = -1, const ImVec4& bg_col = ImVec4(0, 0, 0, 0), const ImVec4& tint_col = ImVec4(1, 1, 1, 1));
IMGUI_API bool Checkbox(const char* label, bool* v);
IMGUI_API bool CheckboxFlags(const char* label, int* flags, int flags_value);
IMGUI_API bool RadioButton(const char* label, bool active);
IMGUI_API bool RadioButton(const char* label, int* v, int v_button);
IMGUI_API void ProgressBar(float fraction, const ImVec2& size_arg = ImVec2(-1, 0), const char* overlay = NULL);
IMGUI_API void Bullet();

// Widgets: Input
IMGUI_API bool InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
IMGUI_API bool InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
IMGUI_API bool InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
IMGUI_API bool InputFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputFloat2(const char* label, float v[2], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputFloat3(const char* label, float v[3], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputFloat4(const char* label, float v[4], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputInt2(const char* label, int v[2], ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputInt3(const char* label, int v[3], ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputInt4(const char* label, int v[4], ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputDouble(const char* label, double* v, double step = 0.0, double step_fast = 0.0, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
IMGUI_API bool InputTextEx(const char* label, char* buf, size_t buf_size, const ImVec2& size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data);

// Widgets: Sliders
IMGUI_API bool SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderAngle(const char* label, float* v_rad, float v_deg_min = -360.0f, float v_deg_max = 360.0f, const char* format = "%.0f deg", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderInt(const char* label, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
IMGUI_API bool SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
IMGUI_API bool VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
IMGUI_API bool VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);

// Widgets: Input with Keyboard
IMGUI_API void InputTextDeactivateAfterEdit(ImGuiInputTextCallbackData* data);

// Clipper
struct ImGuiListClipper {
    float StartPosY;
    float ItemsHeight;
    int ItemsCount, DisplayStart, DisplayEnd;
    
    ImGuiListClipper() { memset(this, 0, sizeof(*this)); }
    void Begin(int items_count, float items_height = -1.0f);
    void End();
    bool Step();
    int GetDisplayStart() const { return DisplayStart; }
    int GetDisplayEnd() const { return DisplayEnd; }
};

#endif // IMGUI_H