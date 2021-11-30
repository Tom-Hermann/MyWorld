/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** 3d_to_2d
*/

#include "include.h"

sfVector2f project_iso_point(int x , int y , float z, view_t *angle)
{
    sfVector2f vector_2d;

    vector_2d.x = cosf(angle->angle_x * RADIANT) * x;
    vector_2d.x -= cosf(angle->angle_x * RADIANT) * y;
    vector_2d.y = sinf(angle->angle_y * RADIANT) * y;
    vector_2d.y += sinf(angle->angle_y * RADIANT) * x - z;
    return (vector_2d);
}

float cancel_iso(int x, int y, sfVector2f pos, view_t *angle)
{
    float z_3D = 0;

    z_3D = sinf(angle->angle_y * RADIANT) * y;
    z_3D += sinf(angle->angle_y * RADIANT) * x - pos.y;
    return (z_3D);
}

sfVector2f change_pov(sfVector2f vector, view_t *view)
{
    vector.x *= view->zoom;
    vector.y *= view->zoom;
    vector.x += view->centre_x;
    vector.y += view->centre_y;
    return (vector);
}

sfVertexArray *create_line(sfVector2f point1 , sfVector2f point2, view_t *view)
{
    sfVertexArray * vertex_array = sfVertexArray_create ();
    sfVertex vertex1 = {.position = change_pov(point1, view), .color = sfWhite};
    sfVertex vertex2 = {.position = change_pov(point2, view), .color = sfWhite};
    sfVertexArray_append (vertex_array , vertex1);
    sfVertexArray_append (vertex_array , vertex2);
    sfVertexArray_setPrimitiveType (vertex_array , sfLinesStrip);
    return (vertex_array);
}