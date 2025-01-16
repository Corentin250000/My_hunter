/*
** EPITECH PROJECT, 2024
** structs.h
** File description:
** All structures
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

typedef struct background_s {
    sfTexture *t_background;
    sfSprite *s_background;
} background_t;

typedef struct demon_s {
    sfVector2f position;
    sfVector2f offset_move;
    sfSprite *s_demon;
    int is_dead;
} demon_t;

typedef struct all_demons_s {
    sfIntRect rect;
    sfClock *clock_animation;
    sfClock *clock_spawn;
    sfClock *clock_move;
    sfTexture *t_demon;
    demon_t **demon_array;
} all_demons_t;

typedef struct quack_s {
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
} quack_t;

typedef struct music_s {
    sfClock *clock_music;
    char **timecode;
    int time;
    int index_time;
    double coefficient;
} music_t;

typedef struct buttons_s {
    sfTexture *t_quit;
    sfSprite *s_quit;
    sfTexture *t_quit_col;
    sfSprite *s_quit_col;
    sfTexture *t_start;
    sfSprite *s_start;
    sfTexture *t_start_col;
    sfSprite *s_start_col;
} buttons_t;

typedef struct start_menu_s {
    sfTexture *t_menu;
    sfSprite *s_menu;
    sfFont *font;
    sfText *title;
    buttons_t buttons;
} start_menu_t;

typedef struct score_menu_s {
    sfText *sentence_score;
    sfSprite *s_quit;
    sfSprite *s_quit_col;
} score_menu_t;

typedef enum game_state_s {
    MENU,
    GAME,
    SCORE
} game_state_t;

typedef struct global_s {
    sfRenderWindow *window;
    game_state_t state;
    start_menu_t menu;
    background_t background;
    all_demons_t all_demons;
    quack_t quack;
    music_t music;
    sfMusic *menu_music;
    score_menu_t score;
} global_t;

#endif
