/*
** EPITECH PROJECT, 2024
** clock_animation.c
** File description:
** Handling animations with a clock
*/

#include "../includes/my_hunter.h"

void create_clock_animation(global_t *global)
{
    global->all_demons.clock_animation = sfClock_create();
}

int check_clock_animation(global_t *global)
{
    sfTime time = sfClock_getElapsedTime(global->all_demons.clock_animation);

    if ((time.microseconds / 1000) > 130) {
        sfClock_restart(global->all_demons.clock_animation);
        return 1;
    }
    return 0;
}
