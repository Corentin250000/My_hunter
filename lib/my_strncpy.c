/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** task02
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (n > i)
        dest[i] = '\0';
    return dest;
}
