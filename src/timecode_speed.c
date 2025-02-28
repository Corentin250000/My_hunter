/*
** EPITECH PROJECT, 2024
** timecode_speed.c
** File description:
** Change the coefficient of speed according to the timecode of music
*/

#include "../includes/my_hunter.h"

char *read_timecode(void)
{
    int fd = open(TIMECODE, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 500);

    if (fd == -1 || !buffer)
        return NULL;
    if (read(fd, buffer, 500) == -1) {
        free(buffer);
        return NULL;
    }
    close(fd);
    return buffer;
}

char **parsing_timecode(void)
{
    char *timecode = read_timecode();
    char **result;

    if (!timecode)
        return NULL;
    result = my_str_to_word_array(timecode);
    free(timecode);
    if (!result)
        return NULL;
    return result;
}

void get_infos_timecode(global_t *global)
{
    int temp = 0;
    double float_temp = 0.f;

    global->music.time = my_getnbr(global->music.timecode[global->
        music.index_time]);
    temp = my_getnbr(global->music.timecode[global->
        music.index_time + 1]);
    float_temp = (double) temp;
    global->music.coefficient = float_temp / 100;
}

void change_offset_move(global_t *global)
{
    sfTime time = sfClock_getElapsedTime(global->music.clock_music);

    if ((time.microseconds / 1000) > 405000)
        global->state++;
    if (global->music.index_time > 49)
        return;
    get_infos_timecode(global);
    if ((time.microseconds / 1000) >= global->music.time) {
        global->music.index_time += 2;
        for (int i = 0; i < NB_DEMON; ++i) {
            global->all_demons.demon_array[i]->offset_move.x = OFFSET_DEMON *
                global->music.coefficient;
        }
    }
}
