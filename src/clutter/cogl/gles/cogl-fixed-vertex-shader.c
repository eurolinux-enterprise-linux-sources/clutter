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
const char cogl_fixed_vertex_shader_per_vertex_attribs[] =
  "\n"
  "/* Per vertex attributes */\n"
  "attribute vec4     vertex_attrib;\n"
  "attribute vec4     color_attrib;\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_transform_matrices[] =
  "\n"
  "/* Transformation matrices */\n"
  "uniform mat4       modelview_matrix;\n"
  "uniform mat4       mvp_matrix; /* combined modelview and projection matrix */\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_output_variables[] =
  "\n"
  "/* Outputs to the fragment shader */\n"
  "varying vec4       frag_color;\n"
  "varying float      fog_amount;\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_fogging_options[] =
  "\n"
  "/* Fogging options */\n"
  "uniform float      fog_density;\n"
  "uniform float      fog_start;\n"
  "uniform float      fog_end;\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_main_start[] =
  "\n"
  "void\n"
  "main (void)\n"
  "{\n"
  "  vec4 transformed_tex_coord;\n"
  "\n"
  "  /* Calculate the transformed position */\n"
  "  gl_Position = mvp_matrix * vertex_attrib;\n"
  "\n"
  "  /* Calculate the transformed texture coordinate */\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_frag_color_start[] =
  "\n"
  "  /* Pass the interpolated vertex color on to the fragment shader */\n"
  "  frag_color = color_attrib;\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_fog_start[] =
  "\n"
  "  /* Estimate the distance from the eye using just the z-coordinate to\n"
  "     use as the fog coord */\n"
  "  vec4 eye_coord = modelview_matrix * vertex_attrib;\n"
  "  float fog_coord = abs (eye_coord.z / eye_coord.w);\n"
  "\n"
  "  /* Calculate the fog amount per-vertex and interpolate it for the\n"
  "     fragment shader */\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_fog_exp[] =
  "  fog_amount = exp (-fog_density * fog_coord);\n"
  ;
const char cogl_fixed_vertex_shader_fog_exp2[] =
  "  fog_amount = exp (-fog_density * fog_coord\n"
  "		    * fog_density * fog_coord);\n"
  ;
const char cogl_fixed_vertex_shader_fog_linear[] =
  "  fog_amount = (fog_end - fog_coord) / (fog_end - fog_start);\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_fog_end[] =
  "  fog_amount = clamp (fog_amount, 0.0, 1.0);\n"
  "\n"
  ;
const char cogl_fixed_vertex_shader_end[] =
  "}\n"
  ;
