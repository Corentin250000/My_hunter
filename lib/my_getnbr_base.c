/*
** EPITECH PROJECT, 2024
** my_getnbr_base.c
** File description:
** task19
*/

#include "my.h"
#include <limits.h>

int nbr_is_negative(char const *str)
{
    int nb_minus = 0;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            nb_minus++;
    }
    return nb_minus % 2 == 0 ? 0 : 1;
}

int nb_plus_minus(char const *str)
{
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++);
    return i;
}

int verify_overflow_base(long long nb, int is_neg)
{
    if (is_neg)
        nb *= -1;
    if (nb < (long long) INT_MIN || nb > (long long) INT_MAX)
        return 1;
    return 0;
}

int my_getnbr_base(char const *str, char const *base)
{
    int base_int = my_getnbr(base);
    long long result = 0;
    int is_neg = nbr_is_negative(str);
    int size = my_strlen(str) - nb_plus_minus(str);
    int power_max = size - 1;

    if (base_int < 2 || base_int > 16)
        return 0;
    if (is_neg)
        power_max--;
    for (int i = nb_plus_minus(str); i < size; i++) {
        result += value_to_add(base_int, str[i], power_max);
        power_max--;
    }
    if (verify_overflow_base(result, is_neg))
        return 0;
    return is_neg ? (int) - result : (int) result;
}
