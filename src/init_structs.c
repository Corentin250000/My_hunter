/*
** EPITECH PROJECT, 2024
** init_structs.c
** File description:
** Initialisation of all structures
*/

#include "../includes/my_hunter.h"

int random_pos_y_demon(int i)
{
    int position = 0;

    srand((unsigned int) i);
    position = rand();
    position %= 875;
    return position;
}

static void define_start_score(global_t *global)
{
    define_all_buttons(global);
    set_title_background(global);
    define_quit_button(global);
    set_score_background(global);
}

static void init_global_part2(global_t *global)
{
    sfVector2f initial_position;
    sfVector2f offset_move;

    for (int i = 0; i < NB_DEMON; ++i) {
        initial_position.x = ORIGIN_X_DEMON;
        initial_position.y = random_pos_y_demon(i);
        global->all_demons.demon_array[i]->position = initial_position;
        offset_move.x = OFFSET_DEMON * COEFFICIENT;
        offset_move.y = 0;
        global->all_demons.demon_array[i]->offset_move = offset_move;
    }
    create_clock_animation(global);
    global->all_demons.clock_spawn = sfClock_create();
    global->all_demons.clock_move = sfClock_create();
    define_sound(global);
    define_start_score(global);
}

static void init_demon_array(global_t *global, int nb_demons)
{
    int i = 0;

    global->all_demons.demon_array = malloc(sizeof(demon_t *) *
        (nb_demons + 1));
    for (; i < nb_demons; ++i) {
        global->all_demons.demon_array[i] = malloc(sizeof(demon_t));
        global->all_demons.demon_array[i]->is_dead = 0;
    }
    global->all_demons.demon_array[i] = NULL;
}

static void set_menu_music(global_t *global)
{
    global->music.clock_music = sfClock_create();
    global->menu_music = sfMusic_createFromFile(MUSIC_MENU);
    if (!global->menu_music)
        return;
    sfMusic_setVolume(global->menu_music, 50.0f);
    sfMusic_setLoop(global->menu_music, sfTrue);
    sfMusic_play(global->menu_music);
}

global_t *init_global(int size, int nb_demons)
{
    global_t *global = malloc(sizeof(global_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (!global)
        return NULL;
    global->window = create_window(mode, NAME);
    global->state = MENU;
    global->all_demons.rect.top = 0;
    global->all_demons.rect.left = 0;
    global->all_demons.rect.width = size;
    global->all_demons.rect.height = 71;
    global->all_demons.t_demon = sfTexture_createFromFile(DEMON, NULL);
    global->background.t_background = sfTexture_createFromFile(BACKGROUND,
        NULL);
    init_demon_array(global, nb_demons);
    global->music.timecode = parsing_timecode();
    global->music.index_time = 0;
    init_global_part2(global);
    set_menu_music(global);
    return global;
}
