/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** task02
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    int j = 0;

    for (; j < size_src; j++)
        dest[size_dest + j] = src[j];
    dest[size_dest + j] = '\0';
    return dest;
}
