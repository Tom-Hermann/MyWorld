/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** open_window
*/

#include "include.h"

sfRenderWindow *open_window(void)
{
    sfVideoMode mod = {1920, 1080, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mod, "My_world",
                                sfResize | sfClose, NULL);
    return (window);
}