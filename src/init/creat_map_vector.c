/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** creat_map_vector
*/

#include "include.h"

sfVector2f **creat_map_2D(view_t *view)
{
    sfVector2f **map = malloc(sizeof(sfVector2f *) * 12);

    for (int y = 0; y != 12; y++) {
        map[y] = malloc(sizeof(sfVector2f) * 12);
        for (int x = 0; x != 12; x++) {
            map[y][x] = project_iso_point(x, y, 0, view);
        }
    }
    return (map);
}