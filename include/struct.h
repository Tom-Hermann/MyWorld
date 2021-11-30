/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_button{
    int states;
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect hit_box;
} button_t;

typedef struct s_sprite {
    button_t *up_node;
    button_t *down_node;
    button_t *restart;
    button_t *move;
    button_t *add_column;
    button_t *remove_column;
    button_t *add_line;
    button_t *remove_line;
    button_t *zoom;
    button_t *line;
    button_t *column;
    button_t *help;
    button_t *help_menu;
} sprite_t;

typedef struct s_view {
    float angle_x;
    float angle_y;
    int centre_x;
    int centre_y;
    float zoom;
    sfVector2i pos_mouse;
} view_t;

typedef struct s_tools {
    int view;
    int manual;
    int up_node;
    int down_node;
    int move;
    int zoom;
    int help;
} tools_t;

typedef struct s_map_data {
    int size_x;
    int size_y;
    float **map_3D;
    sfVector2f **map_2D;
} map_data_t;

typedef struct s_map {
    view_t *view;
    sprite_t *sprite;
    tools_t *tools;
    map_data_t *mdata;
    sfRenderWindow *window;
    sfEvent event;
} map_t;

#endif /* !STRUCT_H_ */