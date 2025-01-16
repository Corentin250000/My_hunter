/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** task06
*/

#include "my.h"

int verify_sort(int *array, int size)
{
    for (int i = 1; i < size; i++) {
        if (array[i - 1] > array[i])
            return 0;
    }
    return 1;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 1; !verify_sort(array, size); i++) {
        if (i >= size)
            i = 1;
        if (array[i - 1] > array[i])
            my_swap(&array[i - 1], &array[i]);
    }
}
