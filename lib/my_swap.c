/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** task01
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp_a = *a;

    *a = *b;
    *b = temp_a;
}
