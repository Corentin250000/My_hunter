/*
** EPITECH PROJECT, 2024
** my_sort_word_array.c
** File description:
** day10
*/

#include "my.h"

void swap_str(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

int verify_sort_char(char **tab)
{
    for (int i = 1; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i - 1], tab[i]) > 0)
            return 0;
    }
    return 1;
}

int my_sort_word_array(char **tab)
{
    for (int i = 1; !verify_sort_char(tab); i++) {
        if (tab[i] == NULL)
            i = 1;
        if (my_strcmp(tab[i - 1], tab[i]) > 0)
            swap_str(&tab[i - 1], &tab[i]);
    }
    return 0;
}
