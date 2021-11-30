/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** restart
*/

#include "include.h"

void restart(view_t *view, map_data_t *data)
{
    for (int y = 0; y != data->size_y; y++) {
        for (int x = 0; x != data->size_x; x++) {
            data->map_3D[y][x] = 0;
            data->map_2D[y][x] = project_iso_point(x, y, 0, view);
        }
    }
}