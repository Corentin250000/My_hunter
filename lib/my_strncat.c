/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** task03
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);

    for (int j = 0; j < size_src && j < nb; j++)
        dest[size_dest + j] = src[j];
    return dest;
}
