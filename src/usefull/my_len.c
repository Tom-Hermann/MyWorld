/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_len
*/

#include "include.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}