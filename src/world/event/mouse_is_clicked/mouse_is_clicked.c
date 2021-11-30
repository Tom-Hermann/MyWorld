/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** mouse_is_clicked
*/

#include "include.h"

void do_something(map_t *map)
{
    if (map->tools->view)
        change_view(map->window, map->view, map->mdata);
    if (map->tools->zoom)
        change_zoom(map->window, map->view);
    if (map->tools->up_node)
        change_h_node(map->window, map->view, map->mdata, -2);
    if (map->tools->down_node)
        change_h_node(map->window, map->view, map->mdata, 2);
}

int set_tool(tools_t *tool)
{
    tool->view = 0;
    tool->zoom = 0;
    tool->up_node = 0;
    tool->down_node = 0;
    tool->manual = 0;
    tool->move = 0;
    return (1);
}

int click_sprite(sprite_t *sprite, tools_t *tool,
                map_data_t *data, view_t *view)
{
    if (sprite->down_node->states)
        return (tool->down_node = set_tool(tool));
    if (sprite->up_node->states)
        return ((tool->up_node = set_tool(tool)));
    if (sprite->restart->states)
        restart(view, data);
    if (sprite->move->states)
        return ((tool->view = set_tool(tool)));
    if (sprite->zoom->states)
        return ((tool->zoom = set_tool(tool)));
    if (sprite->add_line->states)
        add_line(data, view);
    if (sprite->remove_line->states)
        less_line(data, view);
    if (sprite->add_column->states)
        add_column(data, view);
    if (sprite->remove_column->states)
        less_column(data, view);
}

void mouse_is_click(map_t *map)
{
    if (click_sprite(map->sprite, map->tools, map->mdata, map->view));
    else
        do_something(map);
}