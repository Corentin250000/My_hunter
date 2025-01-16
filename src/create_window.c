/*
** EPITECH PROJECT, 2024
** create_window.c
** File description:
** Create the window
*/

#include "../includes/my_hunter.h"

void check_close(sfRenderWindow *window, sfEvent *event, global_t *global)
{
    while (sfRenderWindow_pollEvent(window, event)) {
    if (sfKeyboard_isKeyPressed(SP_SOUND)) {
        sfSound_stop(global->quack.sound);
        sfSound_play(global->quack.sound);
    }
    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(ESCAPE))
        sfRenderWindow_close(window);
    }
}

sfRenderWindow *create_window(sfVideoMode mode, char const *title)
{
    return sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
}
