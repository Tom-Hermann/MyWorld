/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** destroy_struct
*/

#include "include.h"

void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    free(button);
}

void destroy_sprite(sprite_t *sprite)
{
    destroy_button(sprite->add_column);
    destroy_button(sprite->add_line);
    destroy_button(sprite->column);
    destroy_button(sprite->down_node);
    destroy_button(sprite->line);
    destroy_button(sprite->move);
    destroy_button(sprite->remove_column);
    destroy_button(sprite->remove_line);
    destroy_button(sprite->restart);
    destroy_button(sprite->up_node);
    destroy_button(sprite->zoom);
    destroy_button(sprite->help_menu);
    destroy_button(sprite->help);
    free(sprite);
}

void destroy_all(map_t *map)
{
    destroy_sprite(map->sprite);
    free(map->view);
    free(map->mdata->map_2D);
    free(map->mdata->map_3D);
    free(map->mdata);
    free(map->tools);
    sfRenderWindow_destroy(map->window);
    free(map);
}