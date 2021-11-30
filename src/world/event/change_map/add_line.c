/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** add_line
*/

#include "include.h"

float **add_line_3D(int size_y, int size_x, float **map_3D)
{
    float **new_map_3D = malloc(sizeof(float *) * (size_y + 1));

    for (int i = 0; i != size_y + 1; i++)
        new_map_3D[i] = malloc(sizeof(float) * size_x);

    for (int y = 0; y != size_y; y++) {
        for (int x = 0; x != size_x; x++)
            new_map_3D[y][x] = map_3D[y][x];
    }
    for (int x = 0; x != size_x; x++)
        new_map_3D[size_y][x] = 0;
    return (new_map_3D);
}

sfVector2f **add_line_2D(int size_y, int size_x, sfVector2f **map_2D,
                        view_t *view)
{
    sfVector2f **new_map_2D = malloc(sizeof(sfVector2f *) * (size_y + 1));

    for (int i = 0; i != size_y + 1; i++)
        new_map_2D[i] = malloc(sizeof(sfVector2f) * size_x);

    for (int y = 0; y != size_y; y++) {
        for (int x = 0; x != size_x; x++)
            new_map_2D[y][x] = map_2D[y][x];
    }
    for (int x = 0; x != size_x; x++)
        new_map_2D[size_y][x] = project_iso_point(x, size_y, 0, view);
    return (new_map_2D);
}

void add_line(map_data_t *mdata, view_t *view)
{
    if (mdata->size_y >= 40)
        return;
    mdata->map_3D = add_line_3D(mdata->size_y, mdata->size_x, mdata->map_3D);
    mdata->map_2D = add_line_2D(mdata->size_y, mdata->size_x,
                                        mdata->map_2D, view);
    mdata->size_y += 1;
}