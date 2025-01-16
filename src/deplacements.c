/*
** EPITECH PROJECT, 2024
** deplacements.c
** File description:
** Deplacements of demons
*/

#include "../includes/my_hunter.h"

void move(global_t *global, int i)
{
    sfTime time = sfClock_getElapsedTime(global->all_demons.clock_move);

    if (time.microseconds > 4) {
        global->all_demons.demon_array[i]->position.x -= global->
            all_demons.demon_array[i]->offset_move.x;
        if (global->all_demons.demon_array[i]->position.x < -50)
            global->all_demons.demon_array[i]->position.x = ORIGIN_X_DEMON;
        if (global->all_demons.demon_array[i]->position.x > ORIGIN_X_DEMON)
            global->all_demons.demon_array[i]->position.x = -50;
        sfClock_restart(global->all_demons.clock_move);
    }
}
