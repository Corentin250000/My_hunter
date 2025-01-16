/*
** EPITECH PROJECT, 2024
** play_sound.c
** File description:
** Play a special sound when a mystery key is pressed
*/

#include "../includes/my_hunter.h"

void define_sound(global_t *global)
{
    global->quack.sound_buffer = sfSoundBuffer_createFromFile(QUACK);
    global->quack.sound = sfSound_create();
    sfSound_setBuffer(global->quack.sound, global->quack.sound_buffer);
    sfSound_setLoop(global->quack.sound, sfFalse);
    sfSound_setVolume(global->quack.sound, 100);
}
