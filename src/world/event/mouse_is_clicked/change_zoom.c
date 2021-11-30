/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** change_zoom
*/

#include "include.h"

void change_zoom(sfRenderWindow *window, view_t *view)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        view->zoom += 1;
    else if (sfMouse_isButtonPressed(sfMouseRight))
        view->zoom -= 1;
    if (view->zoom == 0)
        view->zoom = 1;
}