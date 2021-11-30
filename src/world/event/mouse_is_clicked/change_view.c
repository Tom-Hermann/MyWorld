/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** change_view
*/

#include "include.h"

void change_center(sfRenderWindow *window, view_t *view)
{
    sfVector2i new_pos = sfMouse_getPositionRenderWindow(window);

    view->centre_x += new_pos.x - view->pos_mouse.x;
    view->centre_y += new_pos.y - view->pos_mouse.y;
    view->pos_mouse = new_pos;
}

void change_angle(sfRenderWindow *window, view_t *view, map_data_t *mdata)
{
    sfVector2i new_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f *angle = malloc(sizeof(sfVector2f) * 2);

    angle[0].x = view->angle_x;
    angle[0].y = view->angle_y;
    view->angle_x += (new_pos.x - view->pos_mouse.x) / 3;
    view->angle_y += (new_pos.y - view->pos_mouse.y) / 3;
    angle[1].x = view->angle_x;
    angle[1].y = view->angle_y;
    recreat_map(mdata, view, angle);
    while (view->angle_y >= 180)
        view->angle_y -= 180;
    while (view->angle_x >= 180)
        view->angle_x -= 180;
    view->pos_mouse = new_pos;
}

void change_view(sfRenderWindow *window, view_t *view, map_data_t *mdata)
{
    if (view->pos_mouse.x == 0 && view->pos_mouse.y == 0) {
        view->pos_mouse = sfMouse_getPositionRenderWindow(window);
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        change_center(window, view);
    else if (sfMouse_isButtonPressed(sfMouseRight))
        change_angle(window, view, mdata);
}