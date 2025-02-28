/*
** EPITECH PROJECT, 2024
** my_hunter.h
** File description:
** Header file my_hunter
*/

#include "../lib/my.h"
#include "macros.h"
#include "structs.h"

#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

// help.c

int print_help(char **av);

// init_structs.c

int random_pos_y_demon(int i);
global_t *init_global(int size, int nb_demons);

// create_window.c

void check_close(sfRenderWindow *window, sfEvent *event, global_t *global);
sfRenderWindow *create_window(sfVideoMode mode, char const *title);

// clock_animation.c

void create_clock_animation(global_t *global);
int check_clock_animation(global_t *global);

// animation.c

void move_rect(sfIntRect *rect, int offset, int max_value);
void draw_spritesheet(global_t *global, int i);
void draw_background(global_t *global);

// deplacements.c

void move(global_t *global, int i);

// play_special_sound.c

void define_sound(global_t *global);

// timecode_speed.c

char *read_timecode(void);
char **parsing_timecode(void);
void get_infos_timecode(global_t *global);
void change_offset_move(global_t *global);

// check_interaction_mouse_demon.c

sfVector2f convert_position_mouse(global_t *global);
void click_demons(global_t *global, int i);

// start_menu.c

void define_all_buttons(global_t *global);
void set_title_background(global_t *global);
void create_all_menu(global_t *global);

// swap.c

void my_swap_char(char *a, char *b);
char *my_revstr(char *str);

// score_window.c

char *my_nbr_to_str(int nb);
void define_quit_button(global_t *global);
void set_score_background(global_t *global);
void print_score(global_t *global);

#endif
