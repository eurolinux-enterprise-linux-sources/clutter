/*
 * Cogl
 *
 * An object oriented GL/GLES Abstraction/Utility Layer
 *
 * Copyright (C) 2007,2008,2009 Intel Corporation.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "cogl.h"
#include "cogl-internal.h"
#include "cogl-util.h"
#include "cogl-context.h"
#include "cogl-texture-private.h"
#include "cogl-material-private.h"

#include <string.h>

static CoglContext *_context = NULL;
static gboolean gl_is_indirect = FALSE;

static gboolean
cogl_create_context ()
{
  GLubyte default_texture_data[] = { 0xff, 0xff, 0xff, 0x0 };
  gulong  enable_flags = 0;
  CoglDrawBufferState *draw_buffer;

  if (_context != NULL)
    return FALSE;

  /* Allocate context memory */
  _context = (CoglContext*) g_malloc (sizeof (CoglContext));

  /* Init default values */
  _context->feature_flags = 0;
  _context->features_cached = FALSE;

  _context->enable_flags = 0;
  _context->color_alpha = 0;

  _context->enable_backface_culling = FALSE;

  _context->indirect = gl_is_indirect;

  _context->default_material = cogl_material_new ();
  _context->source_material = NULL;

  _context->default_gl_texture_2d_tex = COGL_INVALID_HANDLE;
  _context->default_gl_texture_rect_tex = COGL_INVALID_HANDLE;

  _context->journal = g_array_new (FALSE, FALSE, sizeof (CoglJournalEntry));
  _context->logged_vertices = g_array_new (FALSE, FALSE, sizeof (GLfloat));

  _context->current_material = NULL;
  _context->current_material_flags = 0;
  memset (&_context->current_material_flush_options,
          0, sizeof (CoglMaterialFlushOptions));
  _context->current_layers = g_array_new (FALSE, FALSE,
                                          sizeof (CoglLayerInfo));
  _context->n_texcoord_arrays_enabled = 0;

  draw_buffer = g_slice_new0 (CoglDrawBufferState);
  draw_buffer->target = COGL_WINDOW_BUFFER;
  draw_buffer->offscreen = COGL_INVALID_HANDLE;
  _context->draw_buffer_stack =
    g_slist_prepend (NULL, draw_buffer);

  _context->path_nodes = g_array_new (FALSE, FALSE, sizeof (CoglPathNode));
  _context->last_path = 0;
  _context->stencil_material = cogl_material_new ();

  _context->in_begin_gl_block = FALSE;

  _context->viewport_width = 0;
  _context->viewport_height = 0;

  _context->pf_glGenRenderbuffersEXT = NULL;
  _context->pf_glBindRenderbufferEXT = NULL;
  _context->pf_glRenderbufferStorageEXT = NULL;
  _context->pf_glGenFramebuffersEXT = NULL;
  _context->pf_glBindFramebufferEXT = NULL;
  _context->pf_glFramebufferTexture2DEXT = NULL;
  _context->pf_glFramebufferRenderbufferEXT = NULL;
  _context->pf_glCheckFramebufferStatusEXT = NULL;
  _context->pf_glDeleteFramebuffersEXT = NULL;
  _context->pf_glBlitFramebufferEXT = NULL;
  _context->pf_glRenderbufferStorageMultisampleEXT = NULL;

  _context->pf_glCreateProgramObjectARB = NULL;
  _context->pf_glCreateShaderObjectARB = NULL;
  _context->pf_glShaderSourceARB = NULL;
  _context->pf_glCompileShaderARB = NULL;
  _context->pf_glAttachObjectARB = NULL;
  _context->pf_glLinkProgramARB = NULL;
  _context->pf_glUseProgramObjectARB = NULL;
  _context->pf_glGetUniformLocationARB = NULL;
  _context->pf_glDeleteObjectARB = NULL;
  _context->pf_glGetInfoLogARB = NULL;
  _context->pf_glGetObjectParameterivARB = NULL;
  _context->pf_glUniform1fARB = NULL;
  _context->pf_glUniform2fARB = NULL;
  _context->pf_glUniform3fARB = NULL;
  _context->pf_glUniform4fARB = NULL;
  _context->pf_glUniform1fvARB = NULL;
  _context->pf_glUniform2fvARB = NULL;
  _context->pf_glUniform3fvARB = NULL;
  _context->pf_glUniform4fvARB = NULL;
  _context->pf_glUniform1iARB = NULL;
  _context->pf_glUniform2iARB = NULL;
  _context->pf_glUniform3iARB = NULL;
  _context->pf_glUniform4iARB = NULL;
  _context->pf_glUniform1ivARB = NULL;
  _context->pf_glUniform2ivARB = NULL;
  _context->pf_glUniform3ivARB = NULL;
  _context->pf_glUniform4ivARB = NULL;
  _context->pf_glUniformMatrix2fvARB = NULL;
  _context->pf_glUniformMatrix3fvARB = NULL;
  _context->pf_glUniformMatrix4fvARB = NULL;

  _context->pf_glDrawRangeElements = NULL;
  _context->pf_glActiveTexture = NULL;
  _context->pf_glClientActiveTexture = NULL;

  _context->pf_glBlendFuncSeparate = NULL;
  _context->pf_glBlendEquationSeparate = NULL;

  /* Initialise the clip stack */
  _cogl_clip_stack_state_init ();

  /* Initialise matrix stack */
  _cogl_current_matrix_state_init ();

  /* Create default textures used for fall backs */
  _context->default_gl_texture_2d_tex =
    cogl_texture_new_from_data (1, /* width */
                                1, /* height */
                                COGL_TEXTURE_NO_SLICING,
                                COGL_PIXEL_FORMAT_RGBA_8888_PRE, /* data format */
                                /* internal format */
                                COGL_PIXEL_FORMAT_RGBA_8888_PRE,
                                0, /* auto calc row stride */
                                default_texture_data);
  _context->default_gl_texture_rect_tex =
    cogl_texture_new_from_data (1, /* width */
                                1, /* height */
                                COGL_TEXTURE_NO_SLICING,
                                COGL_PIXEL_FORMAT_RGBA_8888_PRE, /* data format */
                                /* internal format */
                                COGL_PIXEL_FORMAT_RGBA_8888_PRE,
                                0, /* auto calc row stride */
                                default_texture_data);

  cogl_set_source (_context->default_material);
  _cogl_material_flush_gl_state (_context->source_material, NULL);
  enable_flags =
    _cogl_material_get_cogl_enable_flags (_context->source_material);
  cogl_enable (enable_flags);

  _context->quad_indices_byte = COGL_INVALID_HANDLE;
  _context->quad_indices_short = COGL_INVALID_HANDLE;
  _context->quad_indices_short_len = 0;

  return TRUE;
}

void
_cogl_destroy_context ()
{
  if (_context == NULL)
    return;

  _cogl_clip_stack_state_destroy ();

  _cogl_current_matrix_state_destroy ();

  if (_context->path_nodes)
    g_array_free (_context->path_nodes, TRUE);

  if (_context->default_gl_texture_2d_tex)
    cogl_handle_unref (_context->default_gl_texture_2d_tex);
  if (_context->default_gl_texture_rect_tex)
    cogl_handle_unref (_context->default_gl_texture_rect_tex);

  if (_context->default_material)
    cogl_handle_unref (_context->default_material);

  if (_context->journal)
    g_array_free (_context->journal, TRUE);
  if (_context->logged_vertices)
    g_array_free (_context->logged_vertices, TRUE);

  if (_context->current_layers)
    g_array_free (_context->current_layers, TRUE);

  if (_context->quad_indices_byte)
    cogl_handle_unref (_context->quad_indices_byte);
  if (_context->quad_indices_short)
    cogl_handle_unref (_context->quad_indices_short);

  g_free (_context);
}

CoglContext *
_cogl_context_get_default ()
{
  /* Create if doesn't exist yet */
  if (_context == NULL)
    cogl_create_context ();

  return _context;
}

/**
 * _cogl_set_indirect_context:
 * @indirect: TRUE if GL context is indirect
 *
 * Advises COGL that the GL context is indirect (commands are sent
 * over a socket). COGL uses this information to try to avoid
 * round-trips in its use of GL, for example.
 *
 * This function cannot be called "on the fly," only before COGL
 * initializes.
 */
void
_cogl_set_indirect_context (gboolean indirect)
{
  /* we get called multiple times if someone creates
   * more than the default stage
   */
  if (_context != NULL)
    {
      if (indirect != _context->indirect)
        g_warning ("Right now all stages will be treated as "
                   "either direct or indirect, ignoring attempt "
                   "to change to indirect=%d", indirect);
      return;
    }

  gl_is_indirect = indirect;
}
