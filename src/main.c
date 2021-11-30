/*
** EPITECH PROJECT, 2020
** Dossier modèle
** File description:
** main
*/

#include "include.h"

int main(void)
{
    map_t *map = malloc(sizeof(map_t));
    init_struct(map);
    world(map);
    destroy_all(map);
}