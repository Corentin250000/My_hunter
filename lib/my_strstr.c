/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** task05
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int size = my_strlen(to_find);

    if (!size)
        return str;
    for (; str[i] != '\0'; i++) {
        if (!my_strncmp(&str[i], to_find, size))
            break;
    }
    if (!my_strncmp(&str[i], to_find, size))
        return &str[i];
    return NULL;
}
