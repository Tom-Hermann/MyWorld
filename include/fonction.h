/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** fonction
*/

#ifndef FONCTION_H_
#define FONCTION_H_

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>

//init
sfRenderWindow *open_window(void);
void init_struct(map_t *map);
float **creat_map_3D(void);
sfVector2f **creat_map_2D(view_t *view);
void recreat_map(map_data_t *data, view_t *view, sfVector2f *angle);
void init_sprite(sprite_t *sprite);
void init_restart(button_t *sprite);

//rect
sfIntRect def_rect_i(int top, int left, int width, int height);
sfFloatRect def_rect_f(float top, float left, float width, float height);
sfFloatRect int_to_float_rect(sfIntRect rect_i);



//change dim
sfVector2f project_iso_point (int x , int y , float z, view_t *angle);
sfVertexArray *create_line(sfVector2f point1 , sfVector2f point2, view_t *view);
sfVector2f change_pov(sfVector2f vector, view_t *view);
float cancel_iso(int x, int y, sfVector2f pos, view_t *angle);


//destroy
void destroy_all(map_t *map);

//usefull
int my_strlen(char *str);

//world
void world(map_t *map);
void draw_sprite(sfRenderWindow *window, sprite_t *sprite, tools_t *tool);
void restart(view_t *view, map_data_t *data);
void draw_png(sfRenderWindow *window, button_t *data);
sfVector2f creat_pos(float x, float y);


//event
void event(map_t *map);
void mouse_is_click(map_t *map);
void change_view(sfRenderWindow *window, view_t *view, map_data_t *mdata);
void change_zoom(sfRenderWindow *window, view_t *view);
void change_h_node(sfRenderWindow *window, view_t *view,
                    map_data_t *mdata, int change);

//change map
void add_line(map_data_t *mdata, view_t *view);
void less_line(map_data_t *mdata, view_t *view);
void add_column(map_data_t *mdata, view_t *view);
void less_column(map_data_t *mdata, view_t *view);


#endif /* !FONCTION_H_ */
