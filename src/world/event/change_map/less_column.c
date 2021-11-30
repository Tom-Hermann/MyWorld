/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** less_column
*/

#include "include.h"

float **less_column_3D(int size_y, int size_x, float **map_3D)
{
    float **new_map_3D = malloc(sizeof(float *) * size_y);

    for (int i = 0; i != size_y; i++)
        new_map_3D[i] = malloc(sizeof(float) * (size_x - 1));

    for (int y = 0; y != size_y; y++) {
        for (int x = 0; x != size_x - 1; x++)
            new_map_3D[y][x] = map_3D[y][x];
    }
    return (new_map_3D);
}

sfVector2f **less_column_2D(int size_y, int size_x, sfVector2f **map_2D,
                        view_t *view)
{
    sfVector2f **new_map_2D = malloc(sizeof(sfVector2f *) * size_y);

    for (int i = 0; i != size_y; i++)
        new_map_2D[i] = malloc(sizeof(sfVector2f) * (size_x - 1));

    for (int y = 0; y != size_y; y++) {
        for (int x = 0; x != size_x - 1; x++)
            new_map_2D[y][x] = map_2D[y][x];
    }
    return (new_map_2D);
}

void less_column(map_data_t *mdata, view_t *view)
{
    if (mdata->size_x <= 2)
        return;
    mdata->map_3D = less_column_3D(mdata->size_y, mdata->size_x, mdata->map_3D);
    mdata->map_2D = less_column_2D(mdata->size_y, mdata->size_x,
                                        mdata->map_2D, view);
    mdata->size_x -= 1;
}