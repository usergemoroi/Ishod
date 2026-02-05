#include "imgl3w.h"
#include <android/log.h>
#include <dlfcn.h>
#include <EGL/egl.h>

#define LOG_TAG "imgl3w"

static void* g_GlHandle = nullptr;

bool imgl3wInit() {
    g_GlHandle = dlopen("libGLESv3.so", RTLD_LAZY);
    if (!g_GlHandle) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Failed to loadv3.so: GLES %s", dlerror());
        return false;
    }
    
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Successfully loaded OpenGL ES 3.0");
    return true;
}

void imgl3wShutdown() {
    if (g_GlHandle) {
        dlclose(g_GlHandle);
        g_GlHandle = nullptr;
    }
}

bool imgl3wIsSupported(int major, int minor) {
    // For simplicity, assume GLES 3.0 is supported
    return (major >= 3);
}

void* imgl3wGetProcAddress(const char* proc) {
    if (!g_GlHandle) {
        return nullptr;
    }
    
    void* result = dlsym(g_GlHandle, proc);
    if (!result) {
        // Try with different prefixes/suffixes
        std::string name = std::string("gl") + proc;
        result = dlsym(g_GlHandle, name.c_str());
        
        if (!result) {
            name = std::string("gl") + proc + "ARB";
            result = dlsym(g_GlHandle, name.c_str());
        }
    }
    
    return result;
}

// GL function definitions
PFNGLACTIVETEXTUREPROC imgl3w::ActiveTexture = nullptr;
PFNGLATTACHSHADERPROC imgl3w::AttachShader = nullptr;
PFNGLBINDATTRIBLOCATIONPROC imgl3w::BindAttribLocation = nullptr;
PFNGLBINDBUFFERPROC imgl3w::BindBuffer = nullptr;
PFNGLBINDFRAMEBUFFERPROC imgl3w::BindFramebuffer = nullptr;
PFNGLBINDRENDERBUFFERPROC imgl3w::BindRenderbuffer = nullptr;
PFNGLBINDTEXTUREPROC imgl3w::BindTexture = nullptr;
PFNGLBLENDFUNCSEPARATEPROC imgl3w::BlendFuncSeparate = nullptr;
PFNGLBUFFERDATAPROC imgl3w::BufferData = nullptr;
PFNGLBUFFERSUBDATAPROC imgl3w::BufferSubData = nullptr;
PFNGLCHECKFRAMEBUFFERSTATUSPROC imgl3w::CheckFramebufferStatus = nullptr;
PFNGLCLEARPROC imgl3w::Clear = nullptr;
PFNGLCLEARCOLORPROC imgl3w::ClearColor = nullptr;
PFNGLCLEARDEPTHFPROC imgl3w::ClearDepthf = nullptr;
PFNGLCLEARSTENCILPROC imgl3w::ClearStencil = nullptr;
PFNGLCOLORMASKPROC imgl3w::ColorMask = nullptr;
PFNGLCOMPILESHADERPROC imgl3w::CompileShader = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC imgl3w::CompressedTexImage2D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC imgl3w::CompressedTexSubImage2D = nullptr;
PFNGLCOPYTexImage2DPROC imgl3w::CopyTexImage2D = nullptr;
PFNGLCOPYTexSUBIMAGE2DPROC imgl3w::CopyTexSubImage2D = nullptr;
PFNGLCREATEPROGRAMPROC imgl3w::CreateProgram = nullptr;
PFNGLCREATESHADERPROC imgl3w::CreateShader = nullptr;
PFNGLCULLFACEPROC imgl3w::CullFace = nullptr;
PFNGLDELETEBUFFERSPROC imgl3w::DeleteBuffers = nullptr;
PFNGLDELETEFRAMEBUFFERSPROC imgl3w::DeleteFramebuffers = nullptr;
PFNGLDELETEPROGRAMPROC imgl3w::DeleteProgram = nullptr;
PFNGLDELETERENDERBUFFERSPROC imgl3w::DeleteRenderbuffers = nullptr;
PFNGLDELETESHADERPROC imgl3w::DeleteShader = nullptr;
PFNGLDELETETEXTURESPROC imgl3w::DeleteTextures = nullptr;
PFNGLDEPTHFUNCPROC imgl3w::DepthFunc = nullptr;
PFNGLDEPTHMASKPROC imgl3w::DepthMask = nullptr;
PFNGLDEPTHRANGEFPROC imgl3w::DepthRangef = nullptr;
PFNGLDETACHSHADERPROC imgl3w::DetachShader = nullptr;
PFNGLDISABLEPROC imgl3w::Disable = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC imgl3w::DisableVertexAttribArray = nullptr;
PFNGLDRAWARRAYSPROC imgl3w::DrawArrays = nullptr;
PFNGLDRAWELEMENTSPROC imgl3w::DrawElements = nullptr;
PFNGLDRAWPIXELSPROC imgl3w::DrawPixels = nullptr;
PFNGLENABLEPROC imgl3w::Enable = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC imgl3w::EnableVertexAttribArray = nullptr;
PFNGLFINISHPROC imgl3w::Finish = nullptr;
PFNGLFLUSHPROC imgl3w::Flush = nullptr;
PFNGLFRAMEBUFFERRENDERBUFFERPROC imgl3w::FramebufferRenderbuffer = nullptr;
PFNGLFRAMEBUFFERTEXTURE2DPROC imgl3w::FramebufferTexture2D = nullptr;
PFNGLFRONTFACEPROC imgl3w::FrontFace = nullptr;
PFNGLGENBUFFERSPROC imgl3w::GenBuffers = nullptr;
PFNGLGENFRAMEBUFFERSPROC imgl3w::GenFramebuffers = nullptr;
PFNGLGENRENDERBUFFERSPROC imgl3w::GenRenderbuffers = nullptr;
PFNGLGENTEXTURESPROC imgl3w::GenTextures = nullptr;
PFNGLGETACTIVEATTRIBPROC imgl3w::GetActiveAttrib = nullptr;
PFNGLGETACTIVEUNIFORMPROC imgl3w::GetActiveUniform = nullptr;
PFNGLGETATTACHEDSHADERSPROC imgl3w::GetAttachedShaders = nullptr;
PFNGLGETATTRIBLOCATIONPROC imgl3w::GetAttribLocation = nullptr;
PFNGLGETBUFFERPARAMETERIVPROC imgl3w::GetBufferParameteriv = nullptr;
PFNGLGETERRORPROC imgl3w::GetError = nullptr;
PFNGLGETFLOATVPROC imgl3w::GetFloatv = nullptr;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC imgl3w::GetFramebufferAttachmentParameteriv = nullptr;
PFNGLGETINTEGERVPROC imgl3w::GetIntegerv = nullptr;
PFNGLGETPOINTERVPROC imgl3w::GetPointerv = nullptr;
PFNGLGETPROGRAMIVPROC imgl3w::GetProgramiv = nullptr;
PFNGLGETPROGRAMINFOLOGPROC imgl3w::GetProgramInfoLog = nullptr;
PFNGLGETRENDERBUFFERPARAMETERIVPROC imgl3w::GetRenderbufferParameteriv = nullptr;
PFNGLGETSHADERIVPROC imgl3w::GetShaderiv = nullptr;
PFNGLGETSHADERINFOLOGPROC imgl3w::GetShaderInfoLog = nullptr;
PFNGLGETSHADERPRECISIONFORMATPROC imgl3w::GetShaderPrecisionFormat = nullptr;
PFNGLGETSHADERSOURCEPROC imgl3w::GetShaderSource = nullptr;
PFNGLGETSTRINGPROC imgl3w::GetString = nullptr;
PFNGLGETTEXENVFVPROC imgl3w::GetTexEnvfv = nullptr;
PFNGLGETTEXENVIVPROC imgl3w::GetTexEnviv = nullptr;
PFNGLGETTEXPARAMETERFVPROC imgl3w::GetTexParameterfv = nullptr;
PFNGLGETTEXPARAMETERIVPROC imgl3w::GetTexParameteriv = nullptr;
PFNGLGETUNIFORMLOCATIONPROC imgl3w::GetUniformLocation = nullptr;
PFNGLGETUNIFORMFVPROC imgl3w::GetUniformfv = nullptr;
PFNGLGETUNIFORMIVPROC imgl3w::GetUniformiv = nullptr;
PFNGLGETVERTEXATTRIBFVPROC imgl3w::GetVertexAttribfv = nullptr;
PFNGLGETVERTEXATTRIBIVPROC imgl3w::GetVertexAttribiv = nullptr;
PFNGLGETVERTEXATTRIBPOINTERVPROC imgl3w::GetVertexAttribPointerv = nullptr;
PFNGLHINTPROC imgl3w::Hint = nullptr;
PFNGLISBUFFERPROC imgl3w::IsBuffer = nullptr;
PFNGLISENABLEDPROC imgl3w::IsEnabled = nullptr;
PFNGLISFRAMEBUFFERPROC imgl3w::IsFramebuffer = nullptr;
PFNGLISPROGRAMPROC imgl3w::IsProgram = nullptr;
PFNGLISRENDERBUFFERPROC imgl3w::IsRenderbuffer = nullptr;
PFNGLISSHADERPROC imgl3w::IsShader = nullptr;
PFNGLISTEXTUREPROC imgl3w::IsTexture = nullptr;
PFNGLLINEWIDTHPROC imgl3w::LineWidth = nullptr;
PFNGLLINKPROGRAMPROC imgl3w::LinkProgram = nullptr;
PFNGLPIXELSTOREIPROC imgl3w::PixelStorei = nullptr;
PFNGLPOLYGONOFFSETPROC imgl3w::PolygonOffset = nullptr;
PFNGLREADPIXELSPROC imgl3w::ReadPixels = nullptr;
PFNGLRELEASESHADERCOMPILERPROC imgl3w::ReleaseShaderCompiler = nullptr;
PFNGLRENDERBUFFERSTORAGEPROC imgl3w::RenderbufferStorage = nullptr;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC imgl3w::RenderbufferStorageMultisample = nullptr;
PFNGLSAMPLECOVERAGEPROC imgl3w::SampleCoverage = nullptr;
PFNGLSCISSORPROC imgl3w::Scissor = nullptr;
PFNGLSHADERBINARYPROC imgl3w::ShaderBinary = nullptr;
PFNGLSHADERSOURCEPROC imgl3w::ShaderSource = nullptr;
PFNGLSTENCILFUNCPROC imgl3w::StencilFunc = nullptr;
PFNGLSTENCILFUNCSEPARATEPROC imgl3w::StencilFuncSeparate = nullptr;
PFNGLSTENCILMASKPROC imgl3w::StencilMask = nullptr;
PFNGLSTENCILMASKSEPARATEPROC imgl3w::StencilMaskSeparate = nullptr;
PFNGLSTENCILOPPROC imgl3w::StencilOp = nullptr;
PFNGLSTENCILOPSEPARATEPROC imgl3w::StencilOpSeparate = nullptr;
PFNGLTEXIMAGE2DPROC imgl3w::TexImage2D = nullptr;
PFNGLTEXPARAMETERFPROC imgl3w::TexParameterf = nullptr;
PFNGLTEXPARAMETERFVPROC imgl3w::TexParameterfv = nullptr;
PFNGLTEXPARAMETERIPROC imgl3w::TexParameteri = nullptr;
PFNGLTEXPARAMETERIVPROC imgl3w::TexParameteriv = nullptr;
PFNGLTEXSUBIMAGE2DPROC imgl3w::TexSubImage2D = nullptr;
PFNGLUNIFORM1FPROC imgl3w::Uniform1f = nullptr;
PFNGLUNIFORM1FVPROC imgl3w::Uniform1fv = nullptr;
PFNGLUNIFORM1IPROC imgl3w::Uniform1i = nullptr;
PFNGLUNIFORM1IVPROC imgl3w::Uniform1iv = nullptr;
PFNGLUNIFORM2FPROC imgl3w::Uniform2f = nullptr;
PFNGLUNIFORM2FVPROC imgl3w::Uniform2fv = nullptr;
PFNGLUNIFORM2IPROC imgl3w::Uniform2i = nullptr;
PFNGLUNIFORM2IVPROC imgl3w::Uniform2iv = nullptr;
PFNGLUNIFORM3FPROC imgl3w::Uniform3f = nullptr;
PFNGLUNIFORM3FVPROC imgl3w::Uniform3fv = nullptr;
PFNGLUNIFORM3IPROC imgl3w::Uniform3i = nullptr;
PFNGLUNIFORM3IVPROC imgl3w::Uniform3iv = nullptr;
PFNGLUNIFORM4FPROC imgl3w::Uniform4f = nullptr;
PFNGLUNIFORM4FVPROC imgl3w::Uniform4fv = nullptr;
PFNGLUNIFORM4IPROC imgl3w::Uniform4i = nullptr;
PFNGLUNIFORM4IVPROC imgl3w::Uniform4iv = nullptr;
PFNGLUNIFORMMATRIX2FVPROC imgl3w::UniformMatrix2fv = nullptr;
PFNGLUNIFORMMATRIX3FVPROC imgl3w::UniformMatrix3fv = nullptr;
PFNGLUNIFORMMATRIX4FVPROC imgl3w::UniformMatrix4fv = nullptr;
PFNGLUSEPROGRAMPROC imgl3w::UseProgram = nullptr;
PFNGLVALIDATEPROGRAMPROC imgl3w::ValidateProgram = nullptr;
PFNGLVERTEXATTRIB1FPROC imgl3w::VertexAttrib1f = nullptr;
PFNGLVERTEXATTRIB1FVPROC imgl3w::VertexAttrib1fv = nullptr;
PFNGLVERTEXATTRIB2FPROC imgl3w::VertexAttrib2f = nullptr;
PFNGLVERTEXATTRIB2FVPROC imgl3w::VertexAttrib2fv = nullptr;
PFNGLVERTEXATTRIB3FPROC imgl3w::VertexAttrib3f = nullptr;
PFNGLVERTEXATTRIB3FVPROC imgl3w::VertexAttrib3fv = nullptr;
PFNGLVERTEXATTRIB4FPROC imgl3w::VertexAttrib4f = nullptr;
PFNGLVERTEXATTRIB4FVPROC imgl3w::VertexAttrib4fv = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC imgl3w::VertexAttribPointer = nullptr;
PFNGLVIEWPORTPROC imgl3w::Viewport = nullptr;