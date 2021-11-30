/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_sprite
*/

#include "include.h"

sfIntRect check_mouse(sfRenderWindow *window, sfSprite *sprite,
                        button_t *button, int state)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect pos = sfSprite_getGlobalBounds(sprite);

    button->states = 0;
    if (sfFloatRect_contains(&pos, pos_mouse.x, pos_mouse.y) && !state) {
        button->hit_box.top += button->hit_box.width;
        button->states = 1;
    }
    else if (state)
        button->hit_box.top += button->hit_box.width * 2;
    return (button->hit_box);
}

void draw_button(sfRenderWindow *window, button_t *data, int tool)
{
    data->hit_box.top = 0;
    check_mouse(window, data->sprite, data, tool);
    sfSprite_setTextureRect(data->sprite, data->hit_box);
    sfSprite_setPosition(data->sprite, data->pos);
    sfRenderWindow_drawSprite(window, data->sprite, 0);
}

void draw_png(sfRenderWindow *window, button_t *data)
{
    sfSprite_setTextureRect(data->sprite, data->hit_box);
    sfSprite_setPosition(data->sprite, data->pos);
    sfRenderWindow_drawSprite(window, data->sprite, 0);
}

void draw_sprite(sfRenderWindow *window, sprite_t *sprite, tools_t *tool)
{
    draw_button(window, sprite->down_node, tool->down_node);
    draw_button(window, sprite->up_node, tool->up_node);
    draw_button(window, sprite->restart, 0);
    draw_button(window, sprite->move, tool->view);
    draw_button(window, sprite->zoom, tool->zoom);
    draw_png(window, sprite->line);
    draw_png(window, sprite->column);
    draw_button(window, sprite->add_column, 0);
    draw_button(window, sprite->remove_column, 0);
    draw_button(window, sprite->remove_line, 0);
    draw_button(window, sprite->add_line, 0);
    draw_button(window, sprite->help, tool->help);
    if (sprite->help->states)
        draw_png(window, sprite->help_menu);
}