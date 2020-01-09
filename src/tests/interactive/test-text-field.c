#include <stdlib.h>
#include <gmodule.h>
#include <clutter/clutter.h>

#define FONT "Mono Bold 14px"

static void
on_entry_paint (ClutterActor *actor,
                gpointer      data)
{
  ClutterActorBox allocation = { 0, };
  gfloat width, height;

  clutter_actor_get_allocation_box (actor, &allocation);
  width = allocation.x2 - allocation.x1;
  height = allocation.y2 - allocation.y1;

  cogl_set_source_color4ub (255, 255, 255, 255);
  cogl_path_round_rectangle (0, 0, width, height, 4.0, 1.0);
  cogl_path_stroke ();
}

static void
on_entry_activate (ClutterText *text,
                   gpointer     data)
{
  g_print ("Text activated: %s (cursor: %d, selection at: %d)\n",
           clutter_text_get_text (text),
           clutter_text_get_cursor_position (text),
           clutter_text_get_selection_bound (text));
}

static ClutterActor *
create_label (const ClutterColor *color,
              const gchar        *text)
{
  ClutterActor *retval = clutter_text_new ();

  clutter_actor_set_width (retval, 200);

  clutter_text_set_font_name (CLUTTER_TEXT (retval), FONT);
  clutter_text_set_color (CLUTTER_TEXT (retval), color);
  clutter_text_set_markup (CLUTTER_TEXT (retval), text);
  clutter_text_set_editable (CLUTTER_TEXT (retval), FALSE);
  clutter_text_set_selectable (CLUTTER_TEXT (retval), FALSE);
  clutter_text_set_single_line_mode (CLUTTER_TEXT (retval), TRUE);
  clutter_text_set_ellipsize (CLUTTER_TEXT (retval), PANGO_ELLIPSIZE_END);

  return retval;
}

static ClutterActor *
create_entry (const ClutterColor *color,
              const gchar        *text,
              gunichar            password_char,
              gint                max_length)
{
  ClutterActor *retval = clutter_text_new_full (FONT, text, color);
  ClutterColor selection = { 0, };

  clutter_actor_set_width (retval, 200);
  clutter_actor_set_reactive (retval, TRUE);

  clutter_color_darken (color, &selection);

  clutter_text_set_editable (CLUTTER_TEXT (retval), TRUE);
  clutter_text_set_selectable (CLUTTER_TEXT (retval), TRUE);
  clutter_text_set_activatable (CLUTTER_TEXT (retval), TRUE);
  clutter_text_set_single_line_mode (CLUTTER_TEXT (retval), TRUE);
  clutter_text_set_password_char (CLUTTER_TEXT (retval), password_char);
  clutter_text_set_cursor_color (CLUTTER_TEXT (retval), &selection);
  clutter_text_set_max_length (CLUTTER_TEXT (retval), max_length);

  g_signal_connect (retval, "activate",
                    G_CALLBACK (on_entry_activate),
                    NULL);
  g_signal_connect (retval, "paint",
                    G_CALLBACK (on_entry_paint),
                    NULL);

  return retval;
}

G_MODULE_EXPORT gint
test_text_field_main (gint    argc,
                      gchar **argv)
{
  ClutterActor *stage;
  ClutterActor *text;
  ClutterColor  entry_color       = {0x33, 0xff, 0x33, 0xff};
  ClutterColor  label_color       = {0xff, 0xff, 0xff, 0xff};
  ClutterColor  background_color  = {0x00, 0x00, 0x00, 0xff};
  ClutterUnits  h_padding, v_padding;
  gfloat        width, height;

  clutter_init (&argc, &argv);

  stage = clutter_stage_get_default ();
  clutter_stage_set_color (CLUTTER_STAGE (stage), &background_color);

  clutter_units_em_for_font (&h_padding, FONT, 2.0); /* 2em */
  clutter_units_em_for_font (&v_padding, FONT, 3.0); /* 3em */

  g_print ("padding: h:%.2f px, v:%.2f px\n",
           clutter_units_to_pixels (&h_padding),
           clutter_units_to_pixels (&v_padding));

  text = create_label (&label_color, "<b>Input field:</b>    ");
  clutter_actor_set_position (text, 10, 10);
  clutter_container_add_actor (CLUTTER_CONTAINER (stage), text);

  width = clutter_actor_get_width (text);
  height = clutter_actor_get_height (text);

  text = create_entry (&entry_color, "<i>some</i> text", 0, 0);
  clutter_actor_set_position (text,
                              width + 10 + clutter_units_to_pixels (&h_padding),
                              10);
  clutter_container_add_actor (CLUTTER_CONTAINER (stage), text);

  text = create_label (&label_color, "<i>A very long password field</i>: ");
  clutter_actor_set_position (text,
                              10,
                              height + 10 + clutter_units_to_pixels (&v_padding));
  clutter_container_add_actor (CLUTTER_CONTAINER (stage), text);

  text = create_entry (&entry_color, "password", '*', 8);
  clutter_actor_set_position (text,
                              width + 10 + clutter_units_to_pixels (&h_padding),
                              height + 10 + clutter_units_to_pixels (&v_padding));
  clutter_container_add_actor (CLUTTER_CONTAINER (stage), text);

  clutter_actor_show (stage);

  clutter_main ();

  return EXIT_SUCCESS;
}
