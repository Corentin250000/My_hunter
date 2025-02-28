/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task01
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int size = my_strlen(src);
    char *str = malloc(sizeof(char) * (size + 1));

    for (; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
