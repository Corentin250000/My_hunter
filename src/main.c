/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main file
*/

#include "../includes/my_hunter.h"

void destroy_global(global_t *global)
{
    if (global->state == MENU)
        return;
    sfTexture_destroy(global->background.t_background);
    sfSprite_destroy(global->background.s_background);
    sfTexture_destroy(global->all_demons.t_demon);
    for (int i = 0; i < NB_DEMON; ++i)
        free(global->all_demons.demon_array[i]);
    free(global->all_demons.demon_array);
    sfClock_destroy(global->all_demons.clock_animation);
    sfSound_destroy(global->quack.sound);
    sfSoundBuffer_destroy(global->quack.sound_buffer);
    sfRenderWindow_destroy(global->window);
    for (int i = 0; global->music.timecode[i] != NULL; ++i)
        free(global->music.timecode[i]);
    free(global->music.timecode);
    free(global);
}

// new demon after 400 ms
void all_draw(global_t *global)
{
    sfTime time = sfClock_getElapsedTime(global->all_demons.clock_spawn);
    static int limit = 1;

    sfRenderWindow_clear(global->window, sfBlack);
    draw_background(global);
    if ((time.microseconds / 1000) >= 400) {
        limit++;
        sfClock_restart(global->all_demons.clock_spawn);
    }
    for (int i = 0; i < NB_DEMON && i < limit; ++i) {
        if (global->all_demons.demon_array[i]->is_dead == 0)
            draw_spritesheet(global, i);
        click_demons(global, i);
    }
}

// To debug
static void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        mini_printf("%d FPS\n", fps);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

static void game(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    change_offset_move(global);
    all_draw(global);
    sfRenderWindow_display(global->window);
}

static void differents_phases(global_t *global)
{
    switch (global->state) {
        case MENU:
            create_all_menu(global);
            break;
        case GAME:
            game(global);
            break;
        case SCORE:
            print_score(global);
            break;
        default:
            sfRenderWindow_close(global->window);
            break;
    }
}

void play_music(char const *path, global_t *global)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (!music)
        return;
    sfMusic_setVolume(music, 50.0f);
    sfMusic_stop(global->menu_music);
    sfMusic_play(music);
    sfClock_restart(global->music.clock_music);
}

int main(int ac, char **av)
{
    sfEvent event;
    global_t *global = init_global(81, NB_DEMON);
    int game_music = 0;

    if (ac > 2 || !global)
        return 84;
    if (ac == 2)
        return print_help(av);
    sfRenderWindow_setKeyRepeatEnabled(global->window, sfFalse);
    sfRenderWindow_setFramerateLimit(global->window, 60);
    while (sfRenderWindow_isOpen(global->window)) {
        if (global->state == GAME && game_music == 0) {
            play_music(MUSIC, global);
            game_music = 1;
        }
        check_close(global->window, &event, global);
        differents_phases(global);
    }
    destroy_global(global);
    return 0;
}
