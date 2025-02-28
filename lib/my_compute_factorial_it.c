/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it.c
** File description:
** task01
*/

#include "my.h"

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12)
        return 0;
    else if (nb == 0)
        return 1;
    for (int i = 1; i <= nb; i++)
        result *= i;
    return result;
}
