/*
** EPITECH PROJECT, 2024
** score_window.c
** File description:
** ...
*/

#include "../includes/my_hunter.h"

char *my_nbr_to_str(int nb)
{
    int i = 0;
    int div = 10;
    char *str = malloc(sizeof(char) * (15 + 1));

    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    for (; nb != 0; i++) {
        str[i] = (char) (48 + nb % div);
        nb /= div;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}

static int count_killed_demons(global_t *global)
{
    int nb_dead_demons = 0;

    for (int i = 0; i < NB_DEMON; ++i)
        nb_dead_demons += global->all_demons.demon_array[i]->is_dead == 1;
    return nb_dead_demons;
}

static char *percent_dead_demons(global_t *global)
{
    int nb_dead_demons = count_killed_demons(global);
    char *str_nbr;
    char *dest;
    char *sentence = my_strdup("You have killed ");
    char *sentence_part2 = my_strdup(" out of 1000 demons");

    str_nbr = my_nbr_to_str(nb_dead_demons);
    dest = malloc(sizeof(char) * (my_strlen(sentence) + 20));
    if (!dest)
        return NULL;
    dest = my_strcpy(dest, sentence);
    dest = my_strcat(dest, str_nbr);
    dest = my_strcat(dest, sentence_part2);
    free(str_nbr);
    free(sentence);
    free(sentence_part2);
    return dest;
}

static void place_quit_button(global_t *global)
{
    sfVector2u size = sfRenderWindow_getSize(global->window);
    sfVector2f pos_quit = {size.x / 2 - 300, size.y / 2};

    sfSprite_setPosition(global->score.s_quit, pos_quit);
    sfSprite_setPosition(global->score.s_quit_col, pos_quit);
}

void define_quit_button(global_t *global)
{
    global->score.s_quit = sfSprite_create();
    global->score.s_quit_col = sfSprite_create();
    global->score.s_quit = sfSprite_copy(global->menu.buttons.s_quit);
    global->score.s_quit_col = sfSprite_copy(global->menu.buttons.s_quit_col);
    if (!global->score.s_quit || !global->score.s_quit_col)
            return;
    place_quit_button(global);
}

static void action_quit(global_t *global)
{
    sfFloatRect pos_quit = sfSprite_getGlobalBounds(global->score.s_quit_col);
    sfVector2f mouse = convert_position_mouse(global);

    if (sfFloatRect_contains(&pos_quit, mouse.x, mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(global->window);
}

static void click_quit(global_t *global)
{
    sfFloatRect pos_quit = sfSprite_getGlobalBounds(global->score.s_quit_col);
    sfVector2f mouse = convert_position_mouse(global);

    if (sfFloatRect_contains(&pos_quit, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(global->window, global->score.s_quit, NULL);
    else
        sfRenderWindow_drawSprite(global->window, global->score.s_quit_col,
            NULL);
    action_quit(global);
}

void set_score_background(global_t *global)
{
    sfVector2f pos_score = {1, 0};

    global->score.sentence_score = sfText_create();
    global->menu.font = sfFont_createFromFile(FONT);
    if (!global->score.sentence_score || !global->menu.font ||
        !global->menu.t_menu || !global->menu.s_menu)
            return;
    sfText_setFont(global->score.sentence_score, global->menu.font);
    sfText_setColor(global->score.sentence_score, sfWhite);
    sfText_setCharacterSize(global->score.sentence_score, 136);
    sfText_setPosition(global->score.sentence_score, pos_score);
}

void print_score(global_t *global)
{
    static int score_music = 1;
    char *score = percent_dead_demons(global);

    if (!score)
        return;
    if (score_music) {
        sfMusic_play(global->menu_music);
        score_music = 0;
    }
    sfText_setString(global->score.sentence_score, score);
    free(score);
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->menu.s_menu, NULL);
    sfRenderWindow_drawText(global->window,
        global->score.sentence_score, NULL);
    click_quit(global);
    sfRenderWindow_display(global->window);
}
