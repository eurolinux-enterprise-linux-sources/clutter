/*
 * Cogl
 *
 * An object oriented GL/GLES Abstraction/Utility Layer
 *
 * Copyright (C) 2008,2009 Intel Corporation.
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

  ;
const char cogl_fixed_fragment_shader_variables_start[] =
  "\n"
  "/* There is no default precision for floats in fragment shaders in\n"
  "   GLES 2 so we need to define one */\n"
  "precision highp float;\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_inputs[] =
  "\n"
  "/* Inputs from the vertex shader */\n"
  "varying vec4       frag_color;\n"
  "varying float      fog_amount;\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_texturing_options[] =
  "\n"
  "/* Texturing options */\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_fogging_options[] =
  "\n"
  "/* Fogging options */\n"
  "uniform vec4       fog_color;\n"
  "\n"
  "/* Alpha test options */\n"
  "uniform float      alpha_test_ref;\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_main_declare[] =
  "\n"
  "void\n"
  "main (void)\n"
  "{\n"
  ;
const char cogl_fixed_fragment_shader_main_start[] =
  "\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_fog[] =
  "\n"
  "  /* Mix the calculated color with the fog color */\n"
  "  gl_FragColor.rgb = mix (fog_color.rgb, gl_FragColor.rgb, fog_amount);\n"
  "\n"
  "  /* Alpha testing */\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_alpha_never[] =
  "  discard;\n"
  ;
const char cogl_fixed_fragment_shader_alpha_less[] =
  "  if (gl_FragColor.a >= alpha_test_ref)\n"
  "    discard;\n"
  ;
const char cogl_fixed_fragment_shader_alpha_equal[] =
  "  if (gl_FragColor.a != alpha_test_ref)\n"
  "    discard;\n"
  ;
const char cogl_fixed_fragment_shader_alpha_lequal[] =
  "  if (gl_FragColor.a > alpha_test_ref)\n"
  "    discard;\n"
  ;
const char cogl_fixed_fragment_shader_alpha_greater[] =
  "  if (gl_FragColor.a <= alpha_test_ref)\n"
  "    discard;\n"
  ;
const char cogl_fixed_fragment_shader_alpha_notequal[] =
  "  if (gl_FragColor.a == alpha_test_ref)\n"
  "    discard;\n"
  ;
const char cogl_fixed_fragment_shader_alpha_gequal[] =
  "  if (gl_FragColor.a < alpha_test_ref)\n"
  "    discard;\n"
  "\n"
  ;
const char cogl_fixed_fragment_shader_end[] =
  "}\n"
  ;
