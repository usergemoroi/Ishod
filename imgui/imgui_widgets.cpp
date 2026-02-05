#include "imgui.h"

// Empty implementation for missing functions
bool ImGui::CheckboxFlags(const char* label, int* flags, int flags_value) {
    if (!flags) return false;
    bool* boolFlags = (bool*)flags;
    int boolValue = flags_value ? 1 : 0;
    bool* current = (bool*)flags;
    
    if (*current != (boolValue != 0)) {
        *current = (boolValue != 0);
        return true;
    }
    return false;
}

void ImGui::Spacing() {}

void ImGui::Dummy(const ImVec2& size) {}

void ImGui::Indent(float indent_w) {}

void ImGui::Unindent(float indent_w) {}

void ImGui::BeginGroup() {}

void ImGui::EndGroup() {}

ImVec2 ImGui::GetCursorPos() { return ImVec2(); }

float ImGui::GetCursorPosX() { return 0.0f; }

float ImGui::GetCursorPosY() { return 0.0f; }

void ImGui::SetCursorPos(const ImVec2& local_pos) {}

void ImGui::SetCursorPosX(float x) {}

void ImGui::SetCursorPosY(float y) {}

ImVec2 ImGui::GetCursorStartPos() { return ImVec2(); }

ImVec2 ImGui::GetCursorScreenPos() { return ImVec2(); }

void ImGui::SetCursorScreenPos(const ImVec2& screen_pos) {}

void ImGui::AlignTextToFramePadding() {}

float ImGui::GetTextLineHeight() { return 16.0f; }

float ImGui::GetTextLineHeightWithSpacing() { return 20.0f; }

float ImGui::GetFrameHeight() { return 24.0f; }

float ImGui::GetFrameHeightWithSpacing() { return 28.0f; }

void ImGui::PushID(const char* str_id) {}

void ImGui::PushID(const char* str_id_begin, const char* str_id_end) {}

void ImGui::PushID(const void* ptr_id) {}

void ImGui::PushID(int int_id) {}

void ImGui::PopID() {}

void ImGui::TextColored(const ImVec4& col, const char* fmt, ...) {}

void ImGui::TextDisabled(const char* fmt, ...) {}

void ImGui::TextWrapped(const char* fmt, ...) {}

void ImGui::LabelText(const char* label, const char* fmt, ...) {}

void ImGui::BulletText(const char* fmt, ...) {}

bool ImGui::ArrowButton(const char* str_id, ImGuiDir dir) {
    return false;
}

void ImGui::Image(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col) {}

bool ImGui::ImageButton(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col) {
    return false;
}

bool ImGui::RadioButton(const char* label, bool active) {
    return false;
}

bool ImGui::RadioButton(const char* label, int* v, int v_button) {
    return false;
}

void ImGui::ProgressBar(float fraction, const ImVec2& size_arg, const char* overlay) {}

void ImGui::Bullet() {}

bool ImGui::InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data) {
    return false;
}

bool ImGui::InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data) {
    return false;
}

bool ImGui::InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data) {
    return false;
}

bool ImGui::InputFloat(const char* label, float* v, float step, float step_fast, const char* format, ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputFloat2(const char* label, float v[2], const char* format, ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputFloat3(const char* label, float v[3], const char* format, ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputFloat4(const char* label, float v[4], const char* format, ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputInt(const char* label, int* v, int step, int step_fast, ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputInt2(const char* label, int v[2], ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputInt3(const char* label, int v[3], ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputInt4(const char* label, int v[4], ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::InputDouble(const char* label, double* v, double step, double step_fast, const char* format, ImGuiInputTextFlags flags) {
    return false;
}

bool ImGui::SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::SliderAngle(const char* label, float* v_rad, float v_deg_min, float v_deg_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}

bool ImGui::VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags) {
    return false;
}