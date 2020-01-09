/*
 * Clutter.
 *
 * An OpenGL based 'interactive canvas' library.
 *
 * Authored By Matthew Allum  <mallum@openedhand.com>
 *
 * Copyright (C) 2006 OpenedHand
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef _HAVE_CLUTTER_PRIVATE_H
#define _HAVE_CLUTTER_PRIVATE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <math.h>

#include <glib.h>

#include "pango/cogl-pango.h"

#include "clutter-backend.h"
#include "clutter-event.h"
#include "clutter-feature.h"
#include "clutter-id-pool.h"
#include "clutter-master-clock.h"
#include "clutter-stage-manager.h"
#include "clutter-stage-window.h"
#include "clutter-stage.h"
#include "clutter-timeline.h"

G_BEGIN_DECLS

typedef enum {
  CLUTTER_ACTOR_UNUSED_FLAG    = 0,

  CLUTTER_ACTOR_IN_DESTRUCTION = 1 << 0,
  CLUTTER_ACTOR_IS_TOPLEVEL    = 1 << 1,
  CLUTTER_ACTOR_IN_REPARENT    = 1 << 2,
  CLUTTER_ACTOR_SYNC_MATRICES  = 1 << 3, /* Used by stage to indicate GL
					  * viewport / perspective etc
					  * needs (re)setting.
                                          */
  CLUTTER_ACTOR_IN_PAINT       = 1 << 4, /* Used to avoid recursion */
  CLUTTER_ACTOR_IN_RELAYOUT    = 1 << 5, /* Used to avoid recursion */
  CLUTTER_STAGE_IN_RESIZE      = 1 << 6
} ClutterPrivateFlags;

struct _ClutterInputDevice
{
  gint          id;

  ClutterInputDeviceType device_type;

  ClutterActor *pointer_grab_actor;
  ClutterActor *motion_last_actor;

  gint          click_count;
  gint          previous_x; 
  gint          previous_y; 
  guint32       previous_time;
  gint          previous_button_number;
};

typedef struct _ClutterMainContext ClutterMainContext;

struct _ClutterMainContext
{
  ClutterBackend  *backend;            /* holds a pointer to the windowing 
                                          system backend */
  GQueue          *events_queue;       /* the main event queue */

  guint            is_initialized : 1;  
  guint            motion_events_per_actor : 1;/* set for enter/leave events */
  guint            defer_display_setup : 1;
  guint            options_parsed : 1;

  GTimer          *timer;	       /* Used for debugging scheduler */

  ClutterPickMode  pick_mode;          /* Indicates pick render mode   */

  gint             num_reactives;      /* Num of reactive actors */

  ClutterIDPool   *id_pool;            /* mapping between reused integer ids 
                                        * and actors 
                                        */
  guint            frame_rate;         /* Default FPS */

  ClutterActor    *pointer_grab_actor; /* The actor having the pointer grab
                                        * (or NULL if there is no pointer grab
                                        */
  ClutterActor    *keyboard_grab_actor; /* The actor having the pointer grab
                                         * (or NULL if there is no pointer 
                                         *  grab) 
                                         */
  GSList          *shaders;            /* stack of overridden shaders */

  ClutterActor    *motion_last_actor;

  /* fb bit masks for col<->id mapping in picking */
  gint fb_r_mask, fb_g_mask, fb_b_mask;
  gint fb_r_mask_used, fb_g_mask_used, fb_b_mask_used;

  PangoContext     *pango_context;      /* Global Pango context */
  CoglPangoFontMap *font_map;           /* Global font map */

  GSList              *input_devices;   /* For extra input devices, i.e
                                           MultiTouch */

  guint32 last_event_time;

  gulong redraw_count;

  GList *repaint_funcs;
};

#define CLUTTER_CONTEXT()	(_clutter_context_get_default ())
ClutterMainContext *_clutter_context_get_default (void);
gboolean            _clutter_context_is_initialized (void);
PangoContext *_clutter_context_create_pango_context (ClutterMainContext *self);
PangoContext *_clutter_context_get_pango_context    (ClutterMainContext *self);

#define CLUTTER_PRIVATE_FLAGS(a)	 (((ClutterActor *) (a))->private_flags)
#define CLUTTER_SET_PRIVATE_FLAGS(a,f)	 (CLUTTER_PRIVATE_FLAGS (a) |= (f))
#define CLUTTER_UNSET_PRIVATE_FLAGS(a,f) (CLUTTER_PRIVATE_FLAGS (a) &= ~(f))

#define CLUTTER_PARAM_READABLE  \
        G_PARAM_READABLE | G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB
#define CLUTTER_PARAM_WRITABLE  \
        G_PARAM_WRITABLE | G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB
#define CLUTTER_PARAM_READWRITE \
        G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK |G_PARAM_STATIC_BLURB

#define I_(str)  (g_intern_static_string ((str)))

/* stage manager */
struct _ClutterStageManager
{
  GObject parent_instance;

  GSList *stages;
};

void _clutter_stage_manager_add_stage    (ClutterStageManager *stage_manager,
                                          ClutterStage        *stage);
void _clutter_stage_manager_remove_stage (ClutterStageManager *stage_manager,
                                          ClutterStage        *stage);

/* stage */

void                _clutter_stage_set_window           (ClutterStage       *stage,
                                                         ClutterStageWindow *stage_window);
ClutterStageWindow *_clutter_stage_get_window           (ClutterStage       *stage);
ClutterStageWindow *_clutter_stage_get_default_window   (void);
void                _clutter_stage_maybe_setup_viewport (ClutterStage       *stage);
void                _clutter_stage_maybe_relayout       (ClutterActor       *stage);
gboolean            _clutter_stage_needs_update         (ClutterStage       *stage);
gboolean            _clutter_stage_do_update            (ClutterStage       *stage);

void     _clutter_stage_queue_event           (ClutterStage *stage,
					       ClutterEvent *event);
gboolean _clutter_stage_has_queued_events     (ClutterStage *stage);
void     _clutter_stage_process_queued_events (ClutterStage *stage);

/* vfuncs implemented by backend */
GType         _clutter_backend_impl_get_type  (void);

void          _clutter_backend_redraw         (ClutterBackend  *backend,
                                               ClutterStage    *stage);
ClutterActor *_clutter_backend_create_stage   (ClutterBackend  *backend,
                                               ClutterStage    *wrapper,
                                               GError         **error);
void          _clutter_backend_ensure_context (ClutterBackend  *backend,
                                               ClutterStage    *stage);
gboolean      _clutter_backend_create_context (ClutterBackend  *backend,
                                               gboolean         is_offscreen,
                                               GError         **error);

void          _clutter_backend_add_options    (ClutterBackend  *backend,
                                               GOptionGroup    *group);
gboolean      _clutter_backend_pre_parse      (ClutterBackend  *backend,
                                               GError         **error);
gboolean      _clutter_backend_post_parse     (ClutterBackend  *backend,
                                               GError         **error);
void          _clutter_backend_init_events    (ClutterBackend  *backend);

ClutterFeatureFlags _clutter_backend_get_features (ClutterBackend *backend);

gfloat        _clutter_backend_get_units_per_em   (ClutterBackend       *backend,
                                                   PangoFontDescription *font_desc);

void          _clutter_feature_init (void);

/* Reinjecting queued events for processing */
void _clutter_process_event (ClutterEvent *event);

/* Picking code */
ClutterActor *_clutter_do_pick (ClutterStage    *stage,
				gint             x,
				gint             y,
				ClutterPickMode  mode);

/* the actual redraw */
void          _clutter_do_redraw (ClutterStage *stage);

guint         _clutter_pixel_to_id (guchar pixel[4]);

void          _clutter_id_to_color (guint id, ClutterColor *col);

/* use this function as the accumulator if you have a signal with
 * a G_TYPE_BOOLEAN return value; this will stop the emission as
 * soon as one handler returns TRUE
 */
gboolean _clutter_boolean_handled_accumulator (GSignalInvocationHint *ihint,
                                               GValue                *return_accu,
                                               const GValue          *handler_return,
                                               gpointer               dummy);

void _clutter_actor_apply_modelview_transform_recursive (ClutterActor *self,
						       ClutterActor *ancestor);

void _clutter_actor_rerealize           (ClutterActor    *self,
                                         ClutterCallback  callback,
                                         void            *data);

void _clutter_actor_set_opacity_parent (ClutterActor *self,
                                        ClutterActor *parent);

void _clutter_actor_set_enable_model_view_transform (ClutterActor *self,
                                                     gboolean      enable);

void _clutter_actor_set_enable_paint_unmapped (ClutterActor *self,
                                               gboolean      enable);

void _clutter_run_repaint_functions (void);

G_END_DECLS

#endif /* _HAVE_CLUTTER_PRIVATE_H */
