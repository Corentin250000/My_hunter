/*
** EPITECH PROJECT, 2024
** swap.c
** File description:
** ...
*/

#include "../includes/my_hunter.h"

void my_swap_char(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    for (int i = 0; i < my_strlen(str) / 2; i++)
        my_swap_char(&str[i], &str[my_strlen(str) - 1 - i]);
    return str;
}
