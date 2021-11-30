/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_sprite
*/

#include "include.h"

void init_button(button_t *button, sfIntRect hit_box, char *name,
                sfVector2f pos)
{
    button->hit_box = hit_box;
    button->texture = sfTexture_createFromFile(name, 0);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, 0);
    button->states = 0;
    button->pos.x = pos.x;
    button->pos.y = pos.y;
}

void malloc_sprite(sprite_t *sprite)
{
    sprite->down_node = malloc(sizeof(button_t));
    sprite->up_node = malloc(sizeof(button_t));
    sprite->restart = malloc(sizeof(button_t));
    sprite->move = malloc(sizeof(button_t));
    sprite->zoom = malloc(sizeof(button_t));
    sprite->add_line = malloc(sizeof(button_t));
    sprite->add_column = malloc(sizeof(button_t));
    sprite->remove_column = malloc(sizeof(button_t));
    sprite->remove_line = malloc(sizeof(button_t));
    sprite->line = malloc(sizeof(button_t));
    sprite->column = malloc(sizeof(button_t));
    sprite->help = malloc(sizeof(button_t));
    sprite->help_menu = malloc(sizeof(button_t));
}

sfVector2f creat_pos(float x, float y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

void continue_init_sprite(sprite_t *sprite)
{
    init_button(sprite->line, def_rect_i(0, 0, 142, 250), "jpg/line.png",
                creat_pos(1700 + 80, 200));
    init_button(sprite->add_line, def_rect_i(0, 0, 112, 112), "jpg/add.png",
                creat_pos(1700 + 80 + 10, 200 + 10 + 20 + 10));
    init_button(sprite->remove_line, def_rect_i(0, 0, 112, 112),
                "jpg/remove.png", creat_pos(1700 + 80 + 5, 200 + 150));
    init_button(sprite->column, def_rect_i(0, 0, 142, 250), "jpg/column.png",
                creat_pos(1700 + 80, 200 + 250 + 10));
    init_button(sprite->add_column, def_rect_i(0, 0, 112, 112), "jpg/add.png",
                creat_pos(1700 + 80 + 10, 200 + 250 + 10 + 20 + 10));
    init_button(sprite->remove_column, def_rect_i(0, 0, 112, 112),
                "jpg/remove.png",   creat_pos(1700 + 80 + 5, 450 + 150));
}

void init_sprite(sprite_t *sprite)
{
    malloc_sprite(sprite);
    init_button(sprite->zoom, def_rect_i(0, 0, 114, 114), "jpg/loupe.png",
                creat_pos(1700, 2));
    init_button(sprite->down_node, def_rect_i(0, 0, 126, 126), "jpg/arrow.png",
                creat_pos(10 + 1300, 2));
    init_button(sprite->up_node, def_rect_i(0, 126, 126, 126), "jpg/arrow.png",
                creat_pos(1440, 2));
    init_button(sprite->restart, def_rect_i(0, 0, 112, 112), "jpg/restart.png",
                creat_pos(2, 2));
    init_button(sprite->move, def_rect_i(0, 0, 112, 112), "jpg/move.png",
                creat_pos(1440 + 130, 2));
    init_button(sprite->help, def_rect_i(0, 0, 126, 67), "jpg/help.png",
                creat_pos(2, 1011 - 100));
    init_button(sprite->help_menu, def_rect_i(0, 0, 1920, 1009),
                "jpg/menu_help.png", creat_pos(0, 0));
    continue_init_sprite(sprite);
}