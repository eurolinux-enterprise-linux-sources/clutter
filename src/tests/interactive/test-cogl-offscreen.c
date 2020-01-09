#include <config.h>
#include <glib.h>
#include <gmodule.h>
#include <stdlib.h>
#include <clutter/clutter.h>
#include <cogl/cogl.h>

/* Coglbox declaration
 *--------------------------------------------------*/

G_BEGIN_DECLS

#define TEST_TYPE_COGLBOX test_coglbox_get_type()

#define TEST_COGLBOX(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  TEST_TYPE_COGLBOX, TestCoglboxClass))

#define TEST_COGLBOX_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  TEST_TYPE_COGLBOX, TestCoglboxClass))

#define TEST_IS_COGLBOX(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
  TEST_TYPE_COGLBOX))

#define TEST_IS_COGLBOX_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
  TEST_TYPE_COGLBOX))

#define TEST_COGLBOX_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  TEST_TYPE_COGLBOX, TestCoglboxClass))

typedef struct _TestCoglbox        TestCoglbox;
typedef struct _TestCoglboxClass   TestCoglboxClass;
typedef struct _TestCoglboxPrivate TestCoglboxPrivate;

struct _TestCoglbox
{
  ClutterActor           parent;

  /*< private >*/
  TestCoglboxPrivate *priv;
};

struct _TestCoglboxClass
{
  ClutterActorClass parent_class;

  /* padding for future expansion */
  void (*_test_coglbox1) (void);
  void (*_test_coglbox2) (void);
  void (*_test_coglbox3) (void);
  void (*_test_coglbox4) (void);
};

static GType test_coglbox_get_type (void) G_GNUC_CONST;

G_END_DECLS

/* Coglbox private declaration
 *--------------------------------------------------*/

G_DEFINE_TYPE (TestCoglbox, test_coglbox, CLUTTER_TYPE_ACTOR);

#define TEST_COGLBOX_GET_PRIVATE(obj) \
(G_TYPE_INSTANCE_GET_PRIVATE ((obj), TEST_TYPE_COGLBOX, TestCoglboxPrivate))

struct _TestCoglboxPrivate
{
  CoglHandle texhand_id;
  CoglHandle texture_id;
  CoglHandle offscreen_id;
};

/* Coglbox implementation
 *--------------------------------------------------*/

static void
test_coglbox_paint(ClutterActor *self)
{
  TestCoglboxPrivate *priv = TEST_COGLBOX_GET_PRIVATE (self);
  gfloat texcoords[4] = { 0, 0, 1, 1 };
  CoglHandle material;

  priv = TEST_COGLBOX_GET_PRIVATE (self);

  cogl_set_source_color4ub (0x66, 0x66, 0xdd, 0xff);
  cogl_rectangle (0, 0, 400, 400);

  cogl_set_source_texture (priv->texhand_id);
  cogl_rectangle_with_texture_coords (0, 0,
                                      400, 400,
                                      0, 0,
                                      6, 6);

  cogl_set_draw_buffer (COGL_OFFSCREEN_BUFFER, priv->offscreen_id);

  cogl_set_source_color4ub (0xff, 0, 0, 0xff);
  cogl_rectangle (20, 20, 20 + 100, 20 + 100);

  cogl_set_source_color4ub (0, 0xff, 0, 0xff);
  cogl_rectangle (80, 80, 80 + 100, 80 + 100);

  cogl_set_draw_buffer (COGL_WINDOW_BUFFER, 0);

  material = cogl_material_new ();
  cogl_material_set_color4ub (material, 0x88, 0x88, 0x88, 0x88);
  cogl_material_set_layer (material, 0, priv->texture_id);
  cogl_set_source (material);
  cogl_rectangle_with_texture_coords (100, 100,
                                      300, 300,
                                      texcoords[0],
                                      texcoords[1],
                                      texcoords[2],
                                      texcoords[3]);
}

static void
test_coglbox_finalize (GObject *object)
{
  G_OBJECT_CLASS (test_coglbox_parent_class)->finalize (object);
}

static void
test_coglbox_dispose (GObject *object)
{
  TestCoglboxPrivate *priv;

  priv = TEST_COGLBOX_GET_PRIVATE (object);

  cogl_handle_unref (priv->texture_id);
  cogl_handle_unref (priv->offscreen_id);

  G_OBJECT_CLASS (test_coglbox_parent_class)->dispose (object);
}

static void
test_coglbox_init (TestCoglbox *self)
{
  TestCoglboxPrivate *priv;
  self->priv = priv = TEST_COGLBOX_GET_PRIVATE(self);

  printf ("Loading redhand.png\n");
  priv->texhand_id = cogl_texture_new_from_file ("redhand.png",
                                                 COGL_TEXTURE_NONE,
						 COGL_PIXEL_FORMAT_ANY,
                                                 NULL);

  printf ("Creating texture with size\n");
  priv->texture_id = cogl_texture_new_with_size (200, 200,
                                                 COGL_TEXTURE_NONE,
						 COGL_PIXEL_FORMAT_RGB_888);

  if (priv->texture_id == COGL_INVALID_HANDLE)
    printf ("Failed creating texture with size!\n");

  printf ("Creating offscreen\n");
  priv->offscreen_id = cogl_offscreen_new_to_texture (priv->texture_id);

  if (priv->offscreen_id == COGL_INVALID_HANDLE)
    printf ("Failed creating offscreen to texture!\n");
}

static void
test_coglbox_class_init (TestCoglboxClass *klass)
{
  GObjectClass      *gobject_class = G_OBJECT_CLASS (klass);
  ClutterActorClass *actor_class   = CLUTTER_ACTOR_CLASS (klass);

  gobject_class->finalize     = test_coglbox_finalize;
  gobject_class->dispose      = test_coglbox_dispose;
  actor_class->paint          = test_coglbox_paint;

  g_type_class_add_private (gobject_class, sizeof (TestCoglboxPrivate));
}

static ClutterActor*
test_coglbox_new (void)
{
  return g_object_new (TEST_TYPE_COGLBOX, NULL);
}

G_MODULE_EXPORT int
test_cogl_offscreen_main (int argc, char *argv[])
{
  ClutterActor     *stage;
  ClutterActor     *coglbox;

  clutter_init(&argc, &argv);

  /* Stage */
  stage = clutter_stage_get_default ();
  clutter_actor_set_size (stage, 400, 400);
  clutter_stage_set_title (CLUTTER_STAGE (stage), "Cogl Test");

  /* Cogl Box */
  coglbox = test_coglbox_new ();
  clutter_container_add_actor (CLUTTER_CONTAINER (stage), coglbox);

  clutter_actor_show_all (stage);

  clutter_main ();

  return 0;
}
