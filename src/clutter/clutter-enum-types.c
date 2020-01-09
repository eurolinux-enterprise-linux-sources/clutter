
/* Generated data (by glib-mkenums) */

#include "clutter-enum-types.h"

/* enumerations from "./clutter-actor.h" */
#include "./clutter-actor.h"

GType
clutter_actor_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_ACTOR_MAPPED, "CLUTTER_ACTOR_MAPPED", "mapped" },
        { CLUTTER_ACTOR_REALIZED, "CLUTTER_ACTOR_REALIZED", "realized" },
        { CLUTTER_ACTOR_REACTIVE, "CLUTTER_ACTOR_REACTIVE", "reactive" },
        { CLUTTER_ACTOR_VISIBLE, "CLUTTER_ACTOR_VISIBLE", "visible" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterActorFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_allocation_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_ALLOCATION_NONE, "CLUTTER_ALLOCATION_NONE", "allocation-none" },
        { CLUTTER_ABSOLUTE_ORIGIN_CHANGED, "CLUTTER_ABSOLUTE_ORIGIN_CHANGED", "absolute-origin-changed" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterAllocationFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-event.h" */
#include "./clutter-event.h"

GType
clutter_modifier_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_SHIFT_MASK, "CLUTTER_SHIFT_MASK", "shift-mask" },
        { CLUTTER_LOCK_MASK, "CLUTTER_LOCK_MASK", "lock-mask" },
        { CLUTTER_CONTROL_MASK, "CLUTTER_CONTROL_MASK", "control-mask" },
        { CLUTTER_MOD1_MASK, "CLUTTER_MOD1_MASK", "mod1-mask" },
        { CLUTTER_MOD2_MASK, "CLUTTER_MOD2_MASK", "mod2-mask" },
        { CLUTTER_MOD3_MASK, "CLUTTER_MOD3_MASK", "mod3-mask" },
        { CLUTTER_MOD4_MASK, "CLUTTER_MOD4_MASK", "mod4-mask" },
        { CLUTTER_MOD5_MASK, "CLUTTER_MOD5_MASK", "mod5-mask" },
        { CLUTTER_BUTTON1_MASK, "CLUTTER_BUTTON1_MASK", "button1-mask" },
        { CLUTTER_BUTTON2_MASK, "CLUTTER_BUTTON2_MASK", "button2-mask" },
        { CLUTTER_BUTTON3_MASK, "CLUTTER_BUTTON3_MASK", "button3-mask" },
        { CLUTTER_BUTTON4_MASK, "CLUTTER_BUTTON4_MASK", "button4-mask" },
        { CLUTTER_BUTTON5_MASK, "CLUTTER_BUTTON5_MASK", "button5-mask" },
        { CLUTTER_SUPER_MASK, "CLUTTER_SUPER_MASK", "super-mask" },
        { CLUTTER_HYPER_MASK, "CLUTTER_HYPER_MASK", "hyper-mask" },
        { CLUTTER_META_MASK, "CLUTTER_META_MASK", "meta-mask" },
        { CLUTTER_RELEASE_MASK, "CLUTTER_RELEASE_MASK", "release-mask" },
        { CLUTTER_MODIFIER_MASK, "CLUTTER_MODIFIER_MASK", "modifier-mask" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterModifierType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_event_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_EVENT_NONE, "CLUTTER_EVENT_NONE", "none" },
        { CLUTTER_EVENT_FLAG_SYNTHETIC, "CLUTTER_EVENT_FLAG_SYNTHETIC", "flag-synthetic" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterEventFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_event_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_NOTHING, "CLUTTER_NOTHING", "nothing" },
        { CLUTTER_KEY_PRESS, "CLUTTER_KEY_PRESS", "key-press" },
        { CLUTTER_KEY_RELEASE, "CLUTTER_KEY_RELEASE", "key-release" },
        { CLUTTER_MOTION, "CLUTTER_MOTION", "motion" },
        { CLUTTER_ENTER, "CLUTTER_ENTER", "enter" },
        { CLUTTER_LEAVE, "CLUTTER_LEAVE", "leave" },
        { CLUTTER_BUTTON_PRESS, "CLUTTER_BUTTON_PRESS", "button-press" },
        { CLUTTER_BUTTON_RELEASE, "CLUTTER_BUTTON_RELEASE", "button-release" },
        { CLUTTER_SCROLL, "CLUTTER_SCROLL", "scroll" },
        { CLUTTER_STAGE_STATE, "CLUTTER_STAGE_STATE", "stage-state" },
        { CLUTTER_DESTROY_NOTIFY, "CLUTTER_DESTROY_NOTIFY", "destroy-notify" },
        { CLUTTER_CLIENT_MESSAGE, "CLUTTER_CLIENT_MESSAGE", "client-message" },
        { CLUTTER_DELETE, "CLUTTER_DELETE", "delete" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterEventType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_scroll_direction_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_SCROLL_UP, "CLUTTER_SCROLL_UP", "up" },
        { CLUTTER_SCROLL_DOWN, "CLUTTER_SCROLL_DOWN", "down" },
        { CLUTTER_SCROLL_LEFT, "CLUTTER_SCROLL_LEFT", "left" },
        { CLUTTER_SCROLL_RIGHT, "CLUTTER_SCROLL_RIGHT", "right" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterScrollDirection"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_stage_state_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_STAGE_STATE_FULLSCREEN, "CLUTTER_STAGE_STATE_FULLSCREEN", "fullscreen" },
        { CLUTTER_STAGE_STATE_OFFSCREEN, "CLUTTER_STAGE_STATE_OFFSCREEN", "offscreen" },
        { CLUTTER_STAGE_STATE_ACTIVATED, "CLUTTER_STAGE_STATE_ACTIVATED", "activated" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterStageState"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_input_device_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_POINTER_DEVICE, "CLUTTER_POINTER_DEVICE", "pointer-device" },
        { CLUTTER_KEYBOARD_DEVICE, "CLUTTER_KEYBOARD_DEVICE", "keyboard-device" },
        { CLUTTER_EXTENSION_DEVICE, "CLUTTER_EXTENSION_DEVICE", "extension-device" },
        { CLUTTER_N_DEVICE_TYPES, "CLUTTER_N_DEVICE_TYPES", "n-device-types" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterInputDeviceType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-feature.h" */
#include "./clutter-feature.h"

GType
clutter_feature_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_FEATURE_TEXTURE_NPOT, "CLUTTER_FEATURE_TEXTURE_NPOT", "texture-npot" },
        { CLUTTER_FEATURE_SYNC_TO_VBLANK, "CLUTTER_FEATURE_SYNC_TO_VBLANK", "sync-to-vblank" },
        { CLUTTER_FEATURE_TEXTURE_YUV, "CLUTTER_FEATURE_TEXTURE_YUV", "texture-yuv" },
        { CLUTTER_FEATURE_TEXTURE_READ_PIXELS, "CLUTTER_FEATURE_TEXTURE_READ_PIXELS", "texture-read-pixels" },
        { CLUTTER_FEATURE_STAGE_STATIC, "CLUTTER_FEATURE_STAGE_STATIC", "stage-static" },
        { CLUTTER_FEATURE_STAGE_USER_RESIZE, "CLUTTER_FEATURE_STAGE_USER_RESIZE", "stage-user-resize" },
        { CLUTTER_FEATURE_STAGE_CURSOR, "CLUTTER_FEATURE_STAGE_CURSOR", "stage-cursor" },
        { CLUTTER_FEATURE_SHADERS_GLSL, "CLUTTER_FEATURE_SHADERS_GLSL", "shaders-glsl" },
        { CLUTTER_FEATURE_OFFSCREEN, "CLUTTER_FEATURE_OFFSCREEN", "offscreen" },
        { CLUTTER_FEATURE_STAGE_MULTIPLE, "CLUTTER_FEATURE_STAGE_MULTIPLE", "stage-multiple" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterFeatureFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-main.h" */
#include "./clutter-main.h"

GType
clutter_init_error_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_INIT_SUCCESS, "CLUTTER_INIT_SUCCESS", "success" },
        { CLUTTER_INIT_ERROR_UNKNOWN, "CLUTTER_INIT_ERROR_UNKNOWN", "error-unknown" },
        { CLUTTER_INIT_ERROR_THREADS, "CLUTTER_INIT_ERROR_THREADS", "error-threads" },
        { CLUTTER_INIT_ERROR_BACKEND, "CLUTTER_INIT_ERROR_BACKEND", "error-backend" },
        { CLUTTER_INIT_ERROR_INTERNAL, "CLUTTER_INIT_ERROR_INTERNAL", "error-internal" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterInitError"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-path.h" */
#include "./clutter-path.h"

GType
clutter_path_node_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_PATH_MOVE_TO, "CLUTTER_PATH_MOVE_TO", "move-to" },
        { CLUTTER_PATH_LINE_TO, "CLUTTER_PATH_LINE_TO", "line-to" },
        { CLUTTER_PATH_CURVE_TO, "CLUTTER_PATH_CURVE_TO", "curve-to" },
        { CLUTTER_PATH_CLOSE, "CLUTTER_PATH_CLOSE", "close" },
        { CLUTTER_PATH_REL_MOVE_TO, "CLUTTER_PATH_REL_MOVE_TO", "rel-move-to" },
        { CLUTTER_PATH_REL_LINE_TO, "CLUTTER_PATH_REL_LINE_TO", "rel-line-to" },
        { CLUTTER_PATH_REL_CURVE_TO, "CLUTTER_PATH_REL_CURVE_TO", "rel-curve-to" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterPathNodeType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-script.h" */
#include "./clutter-script.h"

GType
clutter_script_error_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_SCRIPT_ERROR_INVALID_TYPE_FUNCTION, "CLUTTER_SCRIPT_ERROR_INVALID_TYPE_FUNCTION", "type-function" },
        { CLUTTER_SCRIPT_ERROR_INVALID_PROPERTY, "CLUTTER_SCRIPT_ERROR_INVALID_PROPERTY", "property" },
        { CLUTTER_SCRIPT_ERROR_INVALID_VALUE, "CLUTTER_SCRIPT_ERROR_INVALID_VALUE", "value" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterScriptError"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-shader.h" */
#include "./clutter-shader.h"

GType
clutter_shader_error_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_SHADER_ERROR_NO_ASM, "CLUTTER_SHADER_ERROR_NO_ASM", "no-asm" },
        { CLUTTER_SHADER_ERROR_NO_GLSL, "CLUTTER_SHADER_ERROR_NO_GLSL", "no-glsl" },
        { CLUTTER_SHADER_ERROR_COMPILE, "CLUTTER_SHADER_ERROR_COMPILE", "compile" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterShaderError"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-stage.h" */
#include "./clutter-stage.h"

GType
clutter_pick_mode_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_PICK_NONE, "CLUTTER_PICK_NONE", "none" },
        { CLUTTER_PICK_REACTIVE, "CLUTTER_PICK_REACTIVE", "reactive" },
        { CLUTTER_PICK_ALL, "CLUTTER_PICK_ALL", "all" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterPickMode"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-texture.h" */
#include "./clutter-texture.h"

GType
clutter_texture_error_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_TEXTURE_ERROR_OUT_OF_MEMORY, "CLUTTER_TEXTURE_ERROR_OUT_OF_MEMORY", "out-of-memory" },
        { CLUTTER_TEXTURE_ERROR_NO_YUV, "CLUTTER_TEXTURE_ERROR_NO_YUV", "no-yuv" },
        { CLUTTER_TEXTURE_ERROR_BAD_FORMAT, "CLUTTER_TEXTURE_ERROR_BAD_FORMAT", "bad-format" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterTextureError"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_texture_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_TEXTURE_NONE, "CLUTTER_TEXTURE_NONE", "none" },
        { CLUTTER_TEXTURE_RGB_FLAG_BGR, "CLUTTER_TEXTURE_RGB_FLAG_BGR", "rgb-flag-bgr" },
        { CLUTTER_TEXTURE_RGB_FLAG_PREMULT, "CLUTTER_TEXTURE_RGB_FLAG_PREMULT", "rgb-flag-premult" },
        { CLUTTER_TEXTURE_YUV_FLAG_YUV2, "CLUTTER_TEXTURE_YUV_FLAG_YUV2", "yuv-flag-yuv2" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterTextureFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_texture_quality_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_TEXTURE_QUALITY_LOW, "CLUTTER_TEXTURE_QUALITY_LOW", "low" },
        { CLUTTER_TEXTURE_QUALITY_MEDIUM, "CLUTTER_TEXTURE_QUALITY_MEDIUM", "medium" },
        { CLUTTER_TEXTURE_QUALITY_HIGH, "CLUTTER_TEXTURE_QUALITY_HIGH", "high" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterTextureQuality"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-timeline.h" */
#include "./clutter-timeline.h"

GType
clutter_timeline_direction_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_TIMELINE_FORWARD, "CLUTTER_TIMELINE_FORWARD", "forward" },
        { CLUTTER_TIMELINE_BACKWARD, "CLUTTER_TIMELINE_BACKWARD", "backward" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterTimelineDirection"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-types.h" */
#include "./clutter-types.h"

GType
clutter_gravity_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_GRAVITY_NONE, "CLUTTER_GRAVITY_NONE", "none" },
        { CLUTTER_GRAVITY_NORTH, "CLUTTER_GRAVITY_NORTH", "north" },
        { CLUTTER_GRAVITY_NORTH_EAST, "CLUTTER_GRAVITY_NORTH_EAST", "north-east" },
        { CLUTTER_GRAVITY_EAST, "CLUTTER_GRAVITY_EAST", "east" },
        { CLUTTER_GRAVITY_SOUTH_EAST, "CLUTTER_GRAVITY_SOUTH_EAST", "south-east" },
        { CLUTTER_GRAVITY_SOUTH, "CLUTTER_GRAVITY_SOUTH", "south" },
        { CLUTTER_GRAVITY_SOUTH_WEST, "CLUTTER_GRAVITY_SOUTH_WEST", "south-west" },
        { CLUTTER_GRAVITY_WEST, "CLUTTER_GRAVITY_WEST", "west" },
        { CLUTTER_GRAVITY_NORTH_WEST, "CLUTTER_GRAVITY_NORTH_WEST", "north-west" },
        { CLUTTER_GRAVITY_CENTER, "CLUTTER_GRAVITY_CENTER", "center" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterGravity"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_rotate_axis_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_X_AXIS, "CLUTTER_X_AXIS", "x-axis" },
        { CLUTTER_Y_AXIS, "CLUTTER_Y_AXIS", "y-axis" },
        { CLUTTER_Z_AXIS, "CLUTTER_Z_AXIS", "z-axis" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterRotateAxis"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_rotate_direction_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_ROTATE_CW, "CLUTTER_ROTATE_CW", "cw" },
        { CLUTTER_ROTATE_CCW, "CLUTTER_ROTATE_CCW", "ccw" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterRotateDirection"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_request_mode_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_REQUEST_HEIGHT_FOR_WIDTH, "CLUTTER_REQUEST_HEIGHT_FOR_WIDTH", "height-for-width" },
        { CLUTTER_REQUEST_WIDTH_FOR_HEIGHT, "CLUTTER_REQUEST_WIDTH_FOR_HEIGHT", "width-for-height" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterRequestMode"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_animation_mode_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_CUSTOM_MODE, "CLUTTER_CUSTOM_MODE", "custom-mode" },
        { CLUTTER_LINEAR, "CLUTTER_LINEAR", "linear" },
        { CLUTTER_EASE_IN_QUAD, "CLUTTER_EASE_IN_QUAD", "ease-in-quad" },
        { CLUTTER_EASE_OUT_QUAD, "CLUTTER_EASE_OUT_QUAD", "ease-out-quad" },
        { CLUTTER_EASE_IN_OUT_QUAD, "CLUTTER_EASE_IN_OUT_QUAD", "ease-in-out-quad" },
        { CLUTTER_EASE_IN_CUBIC, "CLUTTER_EASE_IN_CUBIC", "ease-in-cubic" },
        { CLUTTER_EASE_OUT_CUBIC, "CLUTTER_EASE_OUT_CUBIC", "ease-out-cubic" },
        { CLUTTER_EASE_IN_OUT_CUBIC, "CLUTTER_EASE_IN_OUT_CUBIC", "ease-in-out-cubic" },
        { CLUTTER_EASE_IN_QUART, "CLUTTER_EASE_IN_QUART", "ease-in-quart" },
        { CLUTTER_EASE_OUT_QUART, "CLUTTER_EASE_OUT_QUART", "ease-out-quart" },
        { CLUTTER_EASE_IN_OUT_QUART, "CLUTTER_EASE_IN_OUT_QUART", "ease-in-out-quart" },
        { CLUTTER_EASE_IN_QUINT, "CLUTTER_EASE_IN_QUINT", "ease-in-quint" },
        { CLUTTER_EASE_OUT_QUINT, "CLUTTER_EASE_OUT_QUINT", "ease-out-quint" },
        { CLUTTER_EASE_IN_OUT_QUINT, "CLUTTER_EASE_IN_OUT_QUINT", "ease-in-out-quint" },
        { CLUTTER_EASE_IN_SINE, "CLUTTER_EASE_IN_SINE", "ease-in-sine" },
        { CLUTTER_EASE_OUT_SINE, "CLUTTER_EASE_OUT_SINE", "ease-out-sine" },
        { CLUTTER_EASE_IN_OUT_SINE, "CLUTTER_EASE_IN_OUT_SINE", "ease-in-out-sine" },
        { CLUTTER_EASE_IN_EXPO, "CLUTTER_EASE_IN_EXPO", "ease-in-expo" },
        { CLUTTER_EASE_OUT_EXPO, "CLUTTER_EASE_OUT_EXPO", "ease-out-expo" },
        { CLUTTER_EASE_IN_OUT_EXPO, "CLUTTER_EASE_IN_OUT_EXPO", "ease-in-out-expo" },
        { CLUTTER_EASE_IN_CIRC, "CLUTTER_EASE_IN_CIRC", "ease-in-circ" },
        { CLUTTER_EASE_OUT_CIRC, "CLUTTER_EASE_OUT_CIRC", "ease-out-circ" },
        { CLUTTER_EASE_IN_OUT_CIRC, "CLUTTER_EASE_IN_OUT_CIRC", "ease-in-out-circ" },
        { CLUTTER_EASE_IN_ELASTIC, "CLUTTER_EASE_IN_ELASTIC", "ease-in-elastic" },
        { CLUTTER_EASE_OUT_ELASTIC, "CLUTTER_EASE_OUT_ELASTIC", "ease-out-elastic" },
        { CLUTTER_EASE_IN_OUT_ELASTIC, "CLUTTER_EASE_IN_OUT_ELASTIC", "ease-in-out-elastic" },
        { CLUTTER_EASE_IN_BACK, "CLUTTER_EASE_IN_BACK", "ease-in-back" },
        { CLUTTER_EASE_OUT_BACK, "CLUTTER_EASE_OUT_BACK", "ease-out-back" },
        { CLUTTER_EASE_IN_OUT_BACK, "CLUTTER_EASE_IN_OUT_BACK", "ease-in-out-back" },
        { CLUTTER_EASE_IN_BOUNCE, "CLUTTER_EASE_IN_BOUNCE", "ease-in-bounce" },
        { CLUTTER_EASE_OUT_BOUNCE, "CLUTTER_EASE_OUT_BOUNCE", "ease-out-bounce" },
        { CLUTTER_EASE_IN_OUT_BOUNCE, "CLUTTER_EASE_IN_OUT_BOUNCE", "ease-in-out-bounce" },
        { CLUTTER_ANIMATION_LAST, "CLUTTER_ANIMATION_LAST", "animation-last" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterAnimationMode"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}
GType
clutter_font_flags_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GFlagsValue values[] = {
        { CLUTTER_FONT_MIPMAPPING, "CLUTTER_FONT_MIPMAPPING", "mipmapping" },
        { CLUTTER_FONT_HINTING, "CLUTTER_FONT_HINTING", "hinting" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_flags_register_static (g_intern_static_string ("ClutterFontFlags"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* enumerations from "./clutter-units.h" */
#include "./clutter-units.h"

GType
clutter_unit_type_get_type (void)
{
  static volatile gsize g_enum_type_id__volatile = 0;

  if (g_once_init_enter (&g_enum_type_id__volatile))
    {
      static const GEnumValue values[] = {
        { CLUTTER_UNIT_PIXEL, "CLUTTER_UNIT_PIXEL", "pixel" },
        { CLUTTER_UNIT_EM, "CLUTTER_UNIT_EM", "em" },
        { CLUTTER_UNIT_MM, "CLUTTER_UNIT_MM", "mm" },
        { CLUTTER_UNIT_POINT, "CLUTTER_UNIT_POINT", "point" },
        { 0, NULL, NULL }
      };
      GType g_enum_type_id;

      g_enum_type_id =
        g_enum_register_static (g_intern_static_string ("ClutterUnitType"), values);

      g_once_init_leave (&g_enum_type_id__volatile, g_enum_type_id);
    }

  return g_enum_type_id__volatile;
}

/* Generated data ends here */

