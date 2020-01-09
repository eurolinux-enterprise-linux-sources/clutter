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

/**
 * SECTION:clutter-group
 * @short_description: Actor class containing multiple children.
 * actors.
 *
 * A #ClutterGroup is an Actor which contains multiple child actors positioned
 * relative to the #ClutterGroup position. Other operations such as scaling,
 * rotating and clipping of the group will apply to the child actors.
 *
 * A #ClutterGroup's size is defined by the size and position of its children.
 * Resize requests via the #ClutterActor API will be ignored.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdarg.h>

#include "clutter-group.h"

#include "clutter-container.h"
#include "clutter-main.h"
#include "clutter-private.h"
#include "clutter-debug.h"
#include "clutter-marshal.h"
#include "clutter-enum-types.h"

#include "cogl/cogl.h"

enum
{
  ADD,
  REMOVE,

  LAST_SIGNAL
};

static void clutter_container_iface_init (ClutterContainerIface *iface);

G_DEFINE_TYPE_WITH_CODE (ClutterGroup,
                         clutter_group,
                         CLUTTER_TYPE_ACTOR,
                         G_IMPLEMENT_INTERFACE (CLUTTER_TYPE_CONTAINER,
                                                clutter_container_iface_init));

#define CLUTTER_GROUP_GET_PRIVATE(obj) \
(G_TYPE_INSTANCE_GET_PRIVATE ((obj), CLUTTER_TYPE_GROUP, ClutterGroupPrivate))

struct _ClutterGroupPrivate
{
  GList *children;
};


static void
clutter_group_paint (ClutterActor *actor)
{
  ClutterGroupPrivate *priv = CLUTTER_GROUP (actor)->priv;
  GList               *child_item;

  CLUTTER_NOTE (PAINT, "ClutterGroup paint enter '%s'",
                clutter_actor_get_name (actor) ? clutter_actor_get_name (actor)
                                               : "unknown");

  for (child_item = priv->children;
       child_item != NULL;
       child_item = child_item->next)
    {
      ClutterActor *child = child_item->data;

      g_assert (child != NULL);

      clutter_actor_paint (child);
    }

  CLUTTER_NOTE (PAINT, "ClutterGroup paint leave '%s'",
                clutter_actor_get_name (actor) ? clutter_actor_get_name (actor)
                                               : "unknown");
}

static void
clutter_group_pick (ClutterActor       *actor,
		    const ClutterColor *color)
{
  ClutterGroupPrivate *priv = CLUTTER_GROUP (actor)->priv;
  GList               *child_item;

  /* Chain up so we get a bounding box pained (if we are reactive) */
  CLUTTER_ACTOR_CLASS (clutter_group_parent_class)->pick (actor, color);

  for (child_item = priv->children;
       child_item != NULL;
       child_item = child_item->next)
    {
      ClutterActor *child = child_item->data;

      g_assert (child != NULL);

      clutter_actor_paint (child);
    }
}

static void
clutter_fixed_layout_get_preferred_width (GList  *children,
                                          gfloat *min_width_p,
                                          gfloat *natural_width_p)
{
  GList *l;
  gdouble min_left, min_right;
  gdouble natural_left, natural_right;

  min_left = 0;
  min_right = 0;
  natural_left = 0;
  natural_right = 0;

  for (l = children; l != NULL; l = l->next)
    {
      ClutterActor *child = l->data;
      gfloat child_x, child_min, child_natural;

      child_x = clutter_actor_get_x (child);

      clutter_actor_get_preferred_size (child,
                                        &child_min, NULL,
                                        &child_natural, NULL);

      if (l == children)
        {
          /* First child */
          min_left = child_x;
          natural_left = child_x;
          min_right = min_left + child_min;
          natural_right = natural_left + child_natural;
        }
      else
        {
          /* Union of extents with previous children */
          if (child_x < min_left)
            min_left = child_x;

          if (child_x < natural_left)
            natural_left = child_x;

          if (child_x + child_min > min_right)
            min_right = child_x + child_min;

          if (child_x + child_natural > natural_right)
            natural_right = child_x + child_natural;
        }
    }

  /* The preferred size is defined as the width and height we want starting
   * from our origin, since our allocation will set the origin; so we now
   * need to remove any part of the request that is to the left of the origin.
   */
  if (min_left < 0)
    min_left = 0;

  if (natural_left < 0)
    natural_left = 0;

  if (min_right < 0)
    min_right = 0;

  if (natural_right < 0)
    natural_right = 0;

  g_assert (min_right >= min_left);
  g_assert (natural_right >= natural_left);

  if (min_width_p)
    *min_width_p = min_right - min_left;

  if (natural_width_p)
    *natural_width_p = natural_right - min_left;
}

static void
clutter_fixed_layout_get_preferred_height (GList  *children,
                                           gfloat *min_height_p,
                                           gfloat *natural_height_p)
{
  GList *l;
  gdouble min_top, min_bottom;
  gdouble natural_top, natural_bottom;

  min_top = 0;
  min_bottom = 0;
  natural_top = 0;
  natural_bottom = 0;

  for (l = children; l != NULL; l = l->next)
    {
      ClutterActor *child = l->data;
      gfloat child_y, child_min, child_natural;

      child_y = clutter_actor_get_y (child);

      clutter_actor_get_preferred_size (child,
                                        NULL, &child_min,
                                        NULL, &child_natural);

      if (l == children)
        {
          /* First child */
          min_top = child_y;
          natural_top = child_y;
          min_bottom = min_top + child_min;
          natural_bottom = natural_top + child_natural;
        }
      else
        {
          /* Union of extents with previous children */
          if (child_y < min_top)
            min_top = child_y;

          if (child_y < natural_top)
            natural_top = child_y;

          if (child_y + child_min > min_bottom)
            min_bottom = child_y + child_min;

          if (child_y + child_natural > natural_bottom)
            natural_bottom = child_y + child_natural;
        }
    }

  /* The preferred size is defined as the width and height we want starting
   * from our origin, since our allocation will set the origin; so we now
   * need to remove any part of the request that is above the origin.
   */
  if (min_top < 0)
    min_top = 0;

  if (natural_top < 0)
    natural_top = 0;

  if (min_bottom < 0)
    min_bottom = 0;

  if (natural_bottom < 0)
    natural_bottom = 0;

  g_assert (min_bottom >= min_top);
  g_assert (natural_bottom >= natural_top);

  if (min_height_p)
    *min_height_p = min_bottom - min_top;

  if (natural_height_p)
    *natural_height_p = natural_bottom - min_top;
}

static void
clutter_fixed_layout_allocate (GList                  *children,
                               ClutterAllocationFlags  flags)
{
  GList *l;

  for (l = children; l != NULL; l = l->next)
    {
      ClutterActor *child = l->data;
      clutter_actor_allocate_preferred_size (child, flags);
    }
}

static void
clutter_group_get_preferred_width (ClutterActor *self,
                                   gfloat        for_height,
                                   gfloat       *min_width_p,
                                   gfloat       *natural_width_p)
{
  ClutterGroupPrivate *priv = CLUTTER_GROUP (self)->priv;

  /* for_height is irrelevant to the fixed layout, so it's not used */
  clutter_fixed_layout_get_preferred_width (priv->children,
                                            min_width_p,
                                            natural_width_p);
}

static void
clutter_group_get_preferred_height (ClutterActor *self,
                                    gfloat        for_width,
                                    gfloat       *min_height_p,
                                    gfloat       *natural_height_p)
{
  ClutterGroupPrivate *priv = CLUTTER_GROUP (self)->priv;

  /* for_width is irrelevant to the fixed layout, so it's not used */
  clutter_fixed_layout_get_preferred_height (priv->children,
                                             min_height_p,
                                             natural_height_p);
}

static void
clutter_group_allocate (ClutterActor           *self,
                        const ClutterActorBox  *box,
                        ClutterAllocationFlags  flags)
{
  ClutterGroupPrivate *priv = CLUTTER_GROUP (self)->priv;

  /* chain up to set actor->allocation */
  CLUTTER_ACTOR_CLASS (clutter_group_parent_class)->allocate (self, box, flags);

  /* Note that fixed-layout allocation of children does not care what
   * allocation the container received, so "box" is not passed in
   * here. We do not require that children's allocations are completely
   * contained by our own.
   */
  clutter_fixed_layout_allocate (priv->children, flags);
}

static void
clutter_group_dispose (GObject *object)
{
  ClutterGroup *self = CLUTTER_GROUP (object);
  ClutterGroupPrivate *priv = self->priv;

  if (priv->children)
    {
      g_list_foreach (priv->children, (GFunc) clutter_actor_destroy, NULL);
      g_list_free (priv->children);

      priv->children = NULL;
    }

  G_OBJECT_CLASS (clutter_group_parent_class)->dispose (object);
}

static void
clutter_group_real_show_all (ClutterActor *actor)
{
  clutter_container_foreach (CLUTTER_CONTAINER (actor),
                             CLUTTER_CALLBACK (clutter_actor_show),
                             NULL);
  clutter_actor_show (actor);
}

static void
clutter_group_real_hide_all (ClutterActor *actor)
{
  clutter_actor_hide (actor);
  clutter_container_foreach (CLUTTER_CONTAINER (actor),
                             CLUTTER_CALLBACK (clutter_actor_hide),
                             NULL);
}

static void
clutter_group_real_add (ClutterContainer *container,
                        ClutterActor     *actor)
{
  ClutterGroup *group = CLUTTER_GROUP (container);
  ClutterGroupPrivate *priv = group->priv;

  g_object_ref (actor);

  priv->children = g_list_append (priv->children, actor);
  clutter_actor_set_parent (actor, CLUTTER_ACTOR (group));

  /* queue a relayout, to get the correct positioning inside
   * the ::actor-added signal handlers
   */
  clutter_actor_queue_relayout (CLUTTER_ACTOR (group));

  g_signal_emit_by_name (container, "actor-added", actor);

  clutter_container_sort_depth_order (container);

  g_object_unref (actor);
}

static void
clutter_group_real_remove (ClutterContainer *container,
                           ClutterActor     *actor)
{
  ClutterGroup *group = CLUTTER_GROUP (container);
  ClutterGroupPrivate *priv = group->priv;

  g_object_ref (actor);

  priv->children = g_list_remove (priv->children, actor);
  clutter_actor_unparent (actor);

  /* queue a relayout, to get the correct positioning inside
   * the ::actor-removed signal handlers
   */
  clutter_actor_queue_relayout (CLUTTER_ACTOR (group));

  /* at this point, the actor passed to the "actor-removed" signal
   * handlers is not parented anymore to the container but since we
   * are holding a reference on it, it's still valid
   */
  g_signal_emit_by_name (container, "actor-removed", actor);

  if (CLUTTER_ACTOR_IS_VISIBLE (CLUTTER_ACTOR (group)))
    clutter_actor_queue_redraw (CLUTTER_ACTOR (group));

  g_object_unref (actor);
}

static void
clutter_group_real_foreach (ClutterContainer *container,
                            ClutterCallback   callback,
                            gpointer          user_data)
{
  ClutterGroup *group = CLUTTER_GROUP (container);
  ClutterGroupPrivate *priv = group->priv;
  GList *l;

  for (l = priv->children; l; l = l->next)
    (* callback) (CLUTTER_ACTOR (l->data), user_data);
}

static void
clutter_group_real_raise (ClutterContainer *container,
                          ClutterActor     *actor,
                          ClutterActor     *sibling)
{
  ClutterGroup *self = CLUTTER_GROUP (container);
  ClutterGroupPrivate *priv = self->priv;

  priv->children = g_list_remove (priv->children, actor);

  /* Raise at the top */
  if (!sibling)
    {
      GList *last_item;

      last_item = g_list_last (priv->children);

      if (last_item)
	sibling = last_item->data;

      priv->children = g_list_append (priv->children, actor);
    }
  else
    {
      gint pos;

      pos = g_list_index (priv->children, sibling) + 1;

      priv->children = g_list_insert (priv->children, actor, pos);
    }

  /* set Z ordering a value below, this will then call sort
   * as values are equal ordering shouldn't change but Z
   * values will be correct.
   *
   * FIXME: optimise
   */
  if (sibling &&
      clutter_actor_get_depth (sibling) != clutter_actor_get_depth (actor))
    {
      clutter_actor_set_depth (actor, clutter_actor_get_depth (sibling));
    }

  if (CLUTTER_ACTOR_IS_VISIBLE (container))
    clutter_actor_queue_redraw (CLUTTER_ACTOR (container));
}

static void
clutter_group_real_lower (ClutterContainer *container,
                          ClutterActor     *actor,
                          ClutterActor     *sibling)
{
  ClutterGroup *self = CLUTTER_GROUP (container);
  ClutterGroupPrivate *priv = self->priv;

  priv->children = g_list_remove (priv->children, actor);

  /* Push to bottom */
  if (!sibling)
    {
      GList *last_item;

      last_item = g_list_first (priv->children);

      if (last_item)
	sibling = last_item->data;

      priv->children = g_list_prepend (priv->children, actor);
    }
  else
    {
      gint pos;

      pos = g_list_index (priv->children, sibling);

      priv->children = g_list_insert (priv->children, actor, pos);
    }

  /* See comment in group_raise for this */
  if (sibling &&
      clutter_actor_get_depth (sibling) != clutter_actor_get_depth (actor))
    {
      clutter_actor_set_depth (actor, clutter_actor_get_depth (sibling));
    }

  if (CLUTTER_ACTOR_IS_VISIBLE (container))
    clutter_actor_queue_redraw (CLUTTER_ACTOR (container));
}

static gint
sort_z_order (gconstpointer a,
              gconstpointer b)
{
  float depth_a, depth_b;

  depth_a = clutter_actor_get_depth (CLUTTER_ACTOR(a));
  depth_b = clutter_actor_get_depth (CLUTTER_ACTOR(b));

  if (depth_a < depth_b)
    return -1;
  if (depth_a > depth_b)
    return 1;
  return 0;
}

static void
clutter_group_real_sort_depth_order (ClutterContainer *container)
{
  ClutterGroup *self = CLUTTER_GROUP (container);
  ClutterGroupPrivate *priv = self->priv;

  priv->children = g_list_sort (priv->children, sort_z_order);

  if (CLUTTER_ACTOR_IS_VISIBLE (self))
    clutter_actor_queue_redraw (CLUTTER_ACTOR (self));

}

static void
clutter_container_iface_init (ClutterContainerIface *iface)
{
  iface->add = clutter_group_real_add;
  iface->remove = clutter_group_real_remove;
  iface->foreach = clutter_group_real_foreach;
  iface->raise = clutter_group_real_raise;
  iface->lower = clutter_group_real_lower;
  iface->sort_depth_order = clutter_group_real_sort_depth_order;
}

static void
clutter_group_class_init (ClutterGroupClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  ClutterActorClass *actor_class = CLUTTER_ACTOR_CLASS (klass);

  g_type_class_add_private (object_class, sizeof (ClutterGroupPrivate));

  object_class->dispose = clutter_group_dispose;

  actor_class->paint           = clutter_group_paint;
  actor_class->pick            = clutter_group_pick;
  actor_class->show_all        = clutter_group_real_show_all;
  actor_class->hide_all        = clutter_group_real_hide_all;

  actor_class->get_preferred_width  = clutter_group_get_preferred_width;
  actor_class->get_preferred_height = clutter_group_get_preferred_height;
  actor_class->allocate             = clutter_group_allocate;
}

static void
clutter_group_init (ClutterGroup *self)
{
  self->priv = CLUTTER_GROUP_GET_PRIVATE (self);
}

/**
 * clutter_group_new:
 *
 * Create a new  #ClutterGroup.
 *
 * Return value: the newly created #ClutterGroup actor
 */
ClutterActor *
clutter_group_new (void)
{
  return g_object_new (CLUTTER_TYPE_GROUP, NULL);
}

/**
 * clutter_group_remove_all:
 * @group: A #ClutterGroup
 *
 * Removes all children actors from the #ClutterGroup.
 */
void
clutter_group_remove_all (ClutterGroup *group)
{
  GList *children;

  g_return_if_fail (CLUTTER_IS_GROUP (group));

  children = group->priv->children;
  while (children)
    {
      ClutterActor *child = children->data;
      children = children->next;

      clutter_container_remove_actor (CLUTTER_CONTAINER (group), child);
    }
}

/**
 * clutter_group_get_n_children:
 * @self: A #ClutterGroup
 *
 * Gets the number of actors held in the group.
 *
 * Return value: The number of child actors held in the group.
 *
 * Since: 0.2
 */
gint
clutter_group_get_n_children (ClutterGroup *self)
{
  g_return_val_if_fail (CLUTTER_IS_GROUP (self), 0);

  return g_list_length (self->priv->children);
}

/**
 * clutter_group_get_nth_child:
 * @self: A #ClutterGroup
 * @index_: the position of the requested actor.
 *
 * Gets a groups child held at @index_ in stack.
 *
 * Return value: (transfer none): A Clutter actor, or %NULL if
 *   @index_ is invalid.
 *
 * Since: 0.2
 */
ClutterActor *
clutter_group_get_nth_child (ClutterGroup *self,
			     gint          index_)
{
  g_return_val_if_fail (CLUTTER_IS_GROUP (self), NULL);

  return g_list_nth_data (self->priv->children, index_);
}
