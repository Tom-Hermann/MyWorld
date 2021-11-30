/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_struct
*/

#include "include.h"

void init_tool(tools_t *tool)
{
    tool->up_node = 0;
    tool->down_node = 0;
    tool->move = 0;
    tool->manual = 0;
    tool->view = 0;
    tool->zoom = 0;
    tool->help = 0;
}

void init_view(view_t *view)
{
    view->angle_x = 35;
    view->angle_y = 35;
    view->centre_x = 940;
    view->centre_y = 300;
    view->zoom = 30;
}

void init_map_data(map_data_t *mdata, view_t *view)
{
    mdata->size_x = 12;
    mdata->size_y = 12;
    mdata->map_3D = creat_map_3D();
    mdata->map_2D = creat_map_2D(view);
}

void init_struct(map_t *map)
{
    sfEvent event;

    map->tools = malloc(sizeof(tools_t));
    map->view = malloc(sizeof(view_t));
    map->mdata = malloc(sizeof(map_data_t));
    map->sprite = malloc(sizeof(sprite_t));
    map->window = open_window();
    init_sprite(map->sprite);
    init_tool(map->tools);
    init_view(map->view);
    init_map_data(map->mdata, map->view);
    map->event = event;
}