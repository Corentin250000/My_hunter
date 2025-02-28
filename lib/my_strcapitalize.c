/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** task10
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    str = my_strupcase(str);
    for (int i = 1; str[i] != '\0'; i++) {
        if (((str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
            (str[i - 1] >= '0' && str[i - 1] <= '9') ||
            (str[i - 1] >= 'a' && str[i - 1] <= 'z')) &&
            (str[i] >= 'A' && str[i] <= 'Z'))
                str[i] += 32;
    }
    return str;
}
