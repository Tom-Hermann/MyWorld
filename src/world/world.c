/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** world
*/

#include "include.h"
#define cancel_iso_point cancel_iso(pos.x, pos.y, map[pos.y][pos.x], view)

void draw_convex(sfRenderWindow *window, sfVector2f **map,
                sfVector2i pos, view_t *view)
{
    float x = ((cancel_iso_point * 2.5 >= 200)? 200 :
                (cancel_iso_point * 2.5 <= -40)? -40:
                cancel_iso_point * 2.5);
    sfColor grey = sfColor_fromRGB(200 - x, 200 - x, 200 - x);
    sfConvexShape *square = sfConvexShape_create();

    sfConvexShape_setPointCount(square, 4);
    sfConvexShape_setFillColor(square, grey);
    sfConvexShape_setPoint(square, 0, change_pov(map[pos.y][pos.x], view));
    sfConvexShape_setPoint(square, 1,
                            change_pov(map[pos.y][pos.x + 1], view));
    sfConvexShape_setPoint(square, 2,
                            change_pov(map[pos.y + 1][pos.x + 1], view));
    sfConvexShape_setPoint(square, 3, change_pov(map[pos.y + 1][pos.x], view));
    sfRenderWindow_drawConvexShape(window, square, NULL);
    sfConvexShape_destroy(square);
}

void draw_map(sfRenderWindow *window, map_data_t *data,
                sfVector2f **map, view_t *view)
{
    sfVertexArray *node = sfVertexArray_create();
    sfVector2i pos;

    for (int y = 0; y != data->size_y; y++) {
        for (int x = 0; x != data->size_x; x++) {
            if (y != data->size_y - 1 && x != data->size_x - 1) {
                pos.x = x;
                pos.y = y;
                draw_convex(window, map, pos, view);
            }
            if (y != data->size_y - 1)
                node = create_line(map[y][x], map[y + 1][x], view);
            sfRenderWindow_drawVertexArray(window, node, NULL);
            if (x != data->size_x - 1)
                node = create_line(map[y][x], map[y][x + 1], view);
            sfRenderWindow_drawVertexArray(window, node, NULL);
        }
    }
    sfVertexArray_destroy(node);
}

void world(map_t *map)
{
    while (sfRenderWindow_isOpen(map->window)) {
        sfRenderWindow_clear(map->window, sfBlack);
        draw_map(map->window, map->mdata, map->mdata->map_2D, map->view);
        draw_sprite(map->window, map->sprite, map->tools);
        if (sfRenderWindow_pollEvent(map->window, &map->event))
            event(map);
        sfRenderWindow_display(map->window);
    }
}