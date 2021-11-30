/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#include "include.h"

void close_window_window(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void event(map_t *map)
{
    close_window_window(map->event, map->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) ||
        sfMouse_isButtonPressed(sfMouseRight))
        mouse_is_click(map);
    else {
        map->view->pos_mouse.x = 0;
        map->view->pos_mouse.y = 0;
    }
}