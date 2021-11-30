/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** creat_map_
*/

#include "include.h"

float **creat_map_3D(void)
{
    float **map = malloc(sizeof(int *) * 12);

    for (int y = 0; y != 12; y++) {
        map[y] = malloc(sizeof(int) * 12);
        for (int x = 0; x != 12; x++)
            map[y][x] = 0;
    }
    return (map);
}