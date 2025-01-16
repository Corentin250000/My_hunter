/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** task04
*/

#include "my.h"

int is_alphanum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') || (c == '-'))
        return 1;
    return 0;
}

int nb_words(char const *str)
{
    int nb = 0;
    int is_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) && !is_word) {
            nb++;
            is_word++;
        }
        if (!is_alphanum(str[i]))
            is_word = 0;
    }
    return nb;
}

int size_word(char const *str, int index)
{
    int size = 0;

    for (int i = index; is_alphanum(str[i]); i++)
        size++;
    return size;
}

int size_not_word(char const *str, int index)
{
    int size = 0;

    for (int i = index; str[i] != '\0' && !is_alphanum(str[i]); i++)
        size++;
    return size;
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (nb_words(str) + sizeof(NULL)));
    int index = 0;
    int word_size = 0;
    int j = 0;

    for (int i = 0; i < nb_words(str); i++) {
        index += size_not_word(str, index);
        array[i] = malloc(sizeof(char) * (size_word(str, index) + 1));
        word_size = size_word(str, index);
        for (j = 0; j < word_size; j++) {
            array[i][j] = str[index];
            index++;
        }
        array[i][j] = '\0';
    }
    array[nb_words(str)] = NULL;
    return array;
}
