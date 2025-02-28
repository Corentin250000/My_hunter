/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** task07
*/

#include "my.h"

/*
Special case for my_put_nbr (not an integer when it's positive)
Print -2147483648
*/
int special_case(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return 11;
}

/*
Print the number in argument and return the number of digits of number
*/
int my_put_nbr(int nb)
{
    int zeros = 1;
    int nb_digits = 0;

    if (nb == -2147483648)
        return special_case();
    else if (nb < 0) {
        nb_digits += my_putchar('-');
        nb = - nb;
    }
    for (int div = 1000000000; div != 0; div /= 10) {
        if (nb / div == 0 && zeros == 1 && div != 1) {
            nb %= div;
            continue;
        }
        nb_digits += my_putchar(48 + (nb / div));
        zeros = 0;
        nb %= div;
    }
    return nb_digits;
}
