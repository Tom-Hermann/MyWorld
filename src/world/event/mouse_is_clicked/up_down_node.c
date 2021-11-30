/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** up_down_node
*/

#include "include.h"

void change_h_node(sfRenderWindow *window, view_t *view,
                    map_data_t *mdata, int change)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    pos_mouse.x -= view->centre_x;
    pos_mouse.y -= view->centre_y;
    pos_mouse.x /= view->zoom;
    pos_mouse.y /= view->zoom;
    for (int y = 0; y != mdata->size_y; y++) {
        for (int x = 0; x != mdata->size_x; x++) {
            if (pos_mouse.x <= mdata->map_2D[y][x].x + 0.5 &&
                pos_mouse.x >= mdata->map_2D[y][x].x - 0.5 &&
                pos_mouse.y <= mdata->map_2D[y][x].y + 0.5 &&
                pos_mouse.y >= mdata->map_2D[y][x].y - 0.5) {
                    mdata->map_2D[y][x].y += change;
                    return;
                }
        }
    }
}