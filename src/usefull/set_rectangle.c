/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** set_rectangle
*/

#include "include.h"

sfIntRect def_rect_i(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfFloatRect def_rect_f(float top, float left, float width, float height)
{
    sfFloatRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfFloatRect int_to_float_rect(sfIntRect rect_i)
{
    sfFloatRect rect_f;

    rect_f.left = rect_i.left;
    rect_f.top = rect_i.top;
    rect_f.height = rect_i.height;
    rect_f.width = rect_i.width;
    return (rect_f);
}