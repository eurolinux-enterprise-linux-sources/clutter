
/* Generated data (by glib-mkenums) */

#include "cogl-enum-types.h"
#include "cogl.h"

/* enumerations from "../../../clutter/cogl/cogl-debug.h" */
#include "../../../clutter/cogl/cogl-debug.h"

GType
cogl_debug_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { COGL_DEBUG_MISC, "COGL_DEBUG_MISC", "misc" },
        { COGL_DEBUG_TEXTURE, "COGL_DEBUG_TEXTURE", "texture" },
        { COGL_DEBUG_MATERIAL, "COGL_DEBUG_MATERIAL", "material" },
        { COGL_DEBUG_SHADER, "COGL_DEBUG_SHADER", "shader" },
        { COGL_DEBUG_OFFSCREEN, "COGL_DEBUG_OFFSCREEN", "offscreen" },
        { COGL_DEBUG_DRAW, "COGL_DEBUG_DRAW", "draw" },
        { COGL_DEBUG_PANGO, "COGL_DEBUG_PANGO", "pango" },
        { COGL_DEBUG_RECTANGLES, "COGL_DEBUG_RECTANGLES", "rectangles" },
        { COGL_DEBUG_HANDLE, "COGL_DEBUG_HANDLE", "handle" },
        { COGL_DEBUG_BLEND_STRINGS, "COGL_DEBUG_BLEND_STRINGS", "blend-strings" },
        { COGL_DEBUG_DISABLE_BATCHING, "COGL_DEBUG_DISABLE_BATCHING", "disable-batching" },
        { COGL_DEBUG_FORCE_CLIENT_SIDE_MATRICES, "COGL_DEBUG_FORCE_CLIENT_SIDE_MATRICES", "force-client-side-matrices" },
        { COGL_DEBUG_DISABLE_VBOS, "COGL_DEBUG_DISABLE_VBOS", "disable-vbos" },
        { COGL_DEBUG_JOURNAL, "COGL_DEBUG_JOURNAL", "journal" },
        { COGL_DEBUG_BATCHING, "COGL_DEBUG_BATCHING", "batching" },
        { COGL_DEBUG_DISABLE_SOFTWARE_TRANSFORM, "COGL_DEBUG_DISABLE_SOFTWARE_TRANSFORM", "disable-software-transform" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("CoglDebugFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "../../../clutter/cogl/cogl-material.h" */
#include "../../../clutter/cogl/cogl-material.h"

GType
cogl_material_filter_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_MATERIAL_FILTER_NEAREST, "COGL_MATERIAL_FILTER_NEAREST", "nearest" },
        { COGL_MATERIAL_FILTER_LINEAR, "COGL_MATERIAL_FILTER_LINEAR", "linear" },
        { COGL_MATERIAL_FILTER_NEAREST_MIPMAP_NEAREST, "COGL_MATERIAL_FILTER_NEAREST_MIPMAP_NEAREST", "nearest-mipmap-nearest" },
        { COGL_MATERIAL_FILTER_LINEAR_MIPMAP_NEAREST, "COGL_MATERIAL_FILTER_LINEAR_MIPMAP_NEAREST", "linear-mipmap-nearest" },
        { COGL_MATERIAL_FILTER_NEAREST_MIPMAP_LINEAR, "COGL_MATERIAL_FILTER_NEAREST_MIPMAP_LINEAR", "nearest-mipmap-linear" },
        { COGL_MATERIAL_FILTER_LINEAR_MIPMAP_LINEAR, "COGL_MATERIAL_FILTER_LINEAR_MIPMAP_LINEAR", "linear-mipmap-linear" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglMaterialFilter"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_material_alpha_func_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_MATERIAL_ALPHA_FUNC_NEVER, "COGL_MATERIAL_ALPHA_FUNC_NEVER", "never" },
        { COGL_MATERIAL_ALPHA_FUNC_LESS, "COGL_MATERIAL_ALPHA_FUNC_LESS", "less" },
        { COGL_MATERIAL_ALPHA_FUNC_EQUAL, "COGL_MATERIAL_ALPHA_FUNC_EQUAL", "equal" },
        { COGL_MATERIAL_ALPHA_FUNC_LEQUAL, "COGL_MATERIAL_ALPHA_FUNC_LEQUAL", "lequal" },
        { COGL_MATERIAL_ALPHA_FUNC_GREATER, "COGL_MATERIAL_ALPHA_FUNC_GREATER", "greater" },
        { COGL_MATERIAL_ALPHA_FUNC_NOTEQUAL, "COGL_MATERIAL_ALPHA_FUNC_NOTEQUAL", "notequal" },
        { COGL_MATERIAL_ALPHA_FUNC_GEQUAL, "COGL_MATERIAL_ALPHA_FUNC_GEQUAL", "gequal" },
        { COGL_MATERIAL_ALPHA_FUNC_ALWAYS, "COGL_MATERIAL_ALPHA_FUNC_ALWAYS", "always" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglMaterialAlphaFunc"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_material_layer_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_MATERIAL_LAYER_TYPE_TEXTURE, "COGL_MATERIAL_LAYER_TYPE_TEXTURE", "texture" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglMaterialLayerType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "../../../clutter/cogl/cogl-shader.h" */
#include "../../../clutter/cogl/cogl-shader.h"

GType
cogl_shader_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_SHADER_TYPE_VERTEX, "COGL_SHADER_TYPE_VERTEX", "vertex" },
        { COGL_SHADER_TYPE_FRAGMENT, "COGL_SHADER_TYPE_FRAGMENT", "fragment" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglShaderType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "../../../clutter/cogl/cogl-types.h" */
#include "../../../clutter/cogl/cogl-types.h"

GType
cogl_pixel_format_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_PIXEL_FORMAT_ANY, "COGL_PIXEL_FORMAT_ANY", "any" },
        { COGL_PIXEL_FORMAT_A_8, "COGL_PIXEL_FORMAT_A_8", "a-8" },
        { COGL_PIXEL_FORMAT_RGB_565, "COGL_PIXEL_FORMAT_RGB_565", "rgb-565" },
        { COGL_PIXEL_FORMAT_RGBA_4444, "COGL_PIXEL_FORMAT_RGBA_4444", "rgba-4444" },
        { COGL_PIXEL_FORMAT_RGBA_5551, "COGL_PIXEL_FORMAT_RGBA_5551", "rgba-5551" },
        { COGL_PIXEL_FORMAT_YUV, "COGL_PIXEL_FORMAT_YUV", "yuv" },
        { COGL_PIXEL_FORMAT_G_8, "COGL_PIXEL_FORMAT_G_8", "g-8" },
        { COGL_PIXEL_FORMAT_RGB_888, "COGL_PIXEL_FORMAT_RGB_888", "rgb-888" },
        { COGL_PIXEL_FORMAT_BGR_888, "COGL_PIXEL_FORMAT_BGR_888", "bgr-888" },
        { COGL_PIXEL_FORMAT_RGBA_8888, "COGL_PIXEL_FORMAT_RGBA_8888", "rgba-8888" },
        { COGL_PIXEL_FORMAT_BGRA_8888, "COGL_PIXEL_FORMAT_BGRA_8888", "bgra-8888" },
        { COGL_PIXEL_FORMAT_ARGB_8888, "COGL_PIXEL_FORMAT_ARGB_8888", "argb-8888" },
        { COGL_PIXEL_FORMAT_ABGR_8888, "COGL_PIXEL_FORMAT_ABGR_8888", "abgr-8888" },
        { COGL_PIXEL_FORMAT_RGBA_8888_PRE, "COGL_PIXEL_FORMAT_RGBA_8888_PRE", "rgba-8888-pre" },
        { COGL_PIXEL_FORMAT_BGRA_8888_PRE, "COGL_PIXEL_FORMAT_BGRA_8888_PRE", "bgra-8888-pre" },
        { COGL_PIXEL_FORMAT_ARGB_8888_PRE, "COGL_PIXEL_FORMAT_ARGB_8888_PRE", "argb-8888-pre" },
        { COGL_PIXEL_FORMAT_ABGR_8888_PRE, "COGL_PIXEL_FORMAT_ABGR_8888_PRE", "abgr-8888-pre" },
        { COGL_PIXEL_FORMAT_RGBA_4444_PRE, "COGL_PIXEL_FORMAT_RGBA_4444_PRE", "rgba-4444-pre" },
        { COGL_PIXEL_FORMAT_RGBA_5551_PRE, "COGL_PIXEL_FORMAT_RGBA_5551_PRE", "rgba-5551-pre" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglPixelFormat"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_feature_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { COGL_FEATURE_TEXTURE_RECTANGLE, "COGL_FEATURE_TEXTURE_RECTANGLE", "texture-rectangle" },
        { COGL_FEATURE_TEXTURE_NPOT, "COGL_FEATURE_TEXTURE_NPOT", "texture-npot" },
        { COGL_FEATURE_TEXTURE_YUV, "COGL_FEATURE_TEXTURE_YUV", "texture-yuv" },
        { COGL_FEATURE_TEXTURE_READ_PIXELS, "COGL_FEATURE_TEXTURE_READ_PIXELS", "texture-read-pixels" },
        { COGL_FEATURE_SHADERS_GLSL, "COGL_FEATURE_SHADERS_GLSL", "shaders-glsl" },
        { COGL_FEATURE_OFFSCREEN, "COGL_FEATURE_OFFSCREEN", "offscreen" },
        { COGL_FEATURE_OFFSCREEN_MULTISAMPLE, "COGL_FEATURE_OFFSCREEN_MULTISAMPLE", "offscreen-multisample" },
        { COGL_FEATURE_OFFSCREEN_BLIT, "COGL_FEATURE_OFFSCREEN_BLIT", "offscreen-blit" },
        { COGL_FEATURE_FOUR_CLIP_PLANES, "COGL_FEATURE_FOUR_CLIP_PLANES", "four-clip-planes" },
        { COGL_FEATURE_STENCIL_BUFFER, "COGL_FEATURE_STENCIL_BUFFER", "stencil-buffer" },
        { COGL_FEATURE_VBOS, "COGL_FEATURE_VBOS", "vbos" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("CoglFeatureFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_buffer_target_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { COGL_WINDOW_BUFFER, "COGL_WINDOW_BUFFER", "window-buffer" },
        { COGL_OFFSCREEN_BUFFER, "COGL_OFFSCREEN_BUFFER", "offscreen-buffer" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("CoglBufferTarget"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_texture_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { COGL_TEXTURE_NONE, "COGL_TEXTURE_NONE", "none" },
        { COGL_TEXTURE_NO_AUTO_MIPMAP, "COGL_TEXTURE_NO_AUTO_MIPMAP", "no-auto-mipmap" },
        { COGL_TEXTURE_NO_SLICING, "COGL_TEXTURE_NO_SLICING", "no-slicing" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("CoglTextureFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_fog_mode_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_FOG_MODE_LINEAR, "COGL_FOG_MODE_LINEAR", "linear" },
        { COGL_FOG_MODE_EXPONENTIAL, "COGL_FOG_MODE_EXPONENTIAL", "exponential" },
        { COGL_FOG_MODE_EXPONENTIAL_SQUARED, "COGL_FOG_MODE_EXPONENTIAL_SQUARED", "exponential-squared" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglFogMode"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_blend_string_error_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_BLEND_STRING_ERROR_PARSE_ERROR, "COGL_BLEND_STRING_ERROR_PARSE_ERROR", "parse-error" },
        { COGL_BLEND_STRING_ERROR_ARGUMENT_PARSE_ERROR, "COGL_BLEND_STRING_ERROR_ARGUMENT_PARSE_ERROR", "argument-parse-error" },
        { COGL_BLEND_STRING_ERROR_INVALID_ERROR, "COGL_BLEND_STRING_ERROR_INVALID_ERROR", "invalid-error" },
        { COGL_BLEND_STRING_ERROR_GPU_UNSUPPORTED_ERROR, "COGL_BLEND_STRING_ERROR_GPU_UNSUPPORTED_ERROR", "gpu-unsupported-error" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglBlendStringError"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "../../../clutter/cogl/cogl-vertex-buffer.h" */
#include "../../../clutter/cogl/cogl-vertex-buffer.h"

GType
cogl_attribute_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_ATTRIBUTE_TYPE_BYTE, "COGL_ATTRIBUTE_TYPE_BYTE", "byte" },
        { COGL_ATTRIBUTE_TYPE_UNSIGNED_BYTE, "COGL_ATTRIBUTE_TYPE_UNSIGNED_BYTE", "unsigned-byte" },
        { COGL_ATTRIBUTE_TYPE_SHORT, "COGL_ATTRIBUTE_TYPE_SHORT", "short" },
        { COGL_ATTRIBUTE_TYPE_UNSIGNED_SHORT, "COGL_ATTRIBUTE_TYPE_UNSIGNED_SHORT", "unsigned-short" },
        { COGL_ATTRIBUTE_TYPE_FLOAT, "COGL_ATTRIBUTE_TYPE_FLOAT", "float" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglAttributeType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_vertices_mode_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_VERTICES_MODE_POINTS, "COGL_VERTICES_MODE_POINTS", "points" },
        { COGL_VERTICES_MODE_LINE_STRIP, "COGL_VERTICES_MODE_LINE_STRIP", "line-strip" },
        { COGL_VERTICES_MODE_LINE_LOOP, "COGL_VERTICES_MODE_LINE_LOOP", "line-loop" },
        { COGL_VERTICES_MODE_LINES, "COGL_VERTICES_MODE_LINES", "lines" },
        { COGL_VERTICES_MODE_TRIANGLE_STRIP, "COGL_VERTICES_MODE_TRIANGLE_STRIP", "triangle-strip" },
        { COGL_VERTICES_MODE_TRIANGLE_FAN, "COGL_VERTICES_MODE_TRIANGLE_FAN", "triangle-fan" },
        { COGL_VERTICES_MODE_TRIANGLES, "COGL_VERTICES_MODE_TRIANGLES", "triangles" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglVerticesMode"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_indices_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { COGL_INDICES_TYPE_UNSIGNED_BYTE, "COGL_INDICES_TYPE_UNSIGNED_BYTE", "byte" },
        { COGL_INDICES_TYPE_UNSIGNED_SHORT, "COGL_INDICES_TYPE_UNSIGNED_SHORT", "short" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("CoglIndicesType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "../../../clutter/cogl/cogl.h" */
#include "../../../clutter/cogl/cogl.h"

GType
cogl_buffer_bit_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { COGL_BUFFER_BIT_COLOR, "COGL_BUFFER_BIT_COLOR", "color" },
        { COGL_BUFFER_BIT_DEPTH, "COGL_BUFFER_BIT_DEPTH", "depth" },
        { COGL_BUFFER_BIT_STENCIL, "COGL_BUFFER_BIT_STENCIL", "stencil" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("CoglBufferBit"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
cogl_read_pixels_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { COGL_READ_PIXELS_COLOR_BUFFER, "COGL_READ_PIXELS_COLOR_BUFFER", "color-buffer" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("CoglReadPixelsFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* Generated data ends here */

