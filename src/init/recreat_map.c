/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** recreat_map
*/

#include "include.h"

sfVector2f reload_node(view_t *view, sfVector2f *angle, sfVector2i pos,
                        sfVector2f pos_2d)
{
    float z = 0;

    view->angle_x = angle[0].x;
    view->angle_y = angle[0].y;
    z = cancel_iso(pos.x, pos.y, pos_2d, view);
    view->angle_x = angle[1].x;
    view->angle_y = angle[1].y;
    return (project_iso_point(pos.x, pos.y, z, view));
}

void recreat_map(map_data_t *data, view_t *view, sfVector2f *angle)
{
    sfVector2i coord = {0, 0};

    for (int y = 0; y != data->size_y; y++) {
        coord.y = y;
        coord.x = 0;
        for (int x = 0; x != data->size_x; x++) {
            coord.x = x;
            data->map_2D[y][x] = reload_node(view, angle, coord,
                                            data->map_2D[y][x]);
        }
    }
}
