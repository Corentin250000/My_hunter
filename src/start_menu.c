/*
** EPITECH PROJECT, 2024
** start_menu.c
** File description:
** All functions to create and display the start menu
*/

#include "../includes/my_hunter.h"

static void define_all_buttons_part2(global_t *global)
{
    global->menu.buttons.t_quit = sfTexture_createFromFile(QUIT, NULL);
    global->menu.buttons.t_quit_col = sfTexture_createFromFile(QUIT_COL, NULL);
    global->menu.buttons.t_start = sfTexture_createFromFile(START, NULL);
    global->menu.buttons.t_start_col = sfTexture_createFromFile(START_COL,
        NULL);
    global->menu.buttons.s_quit = sfSprite_create();
    global->menu.buttons.s_quit_col = sfSprite_create();
    global->menu.buttons.s_start = sfSprite_create();
    global->menu.buttons.s_start_col = sfSprite_create();
}

static void place_all_buttons(global_t *global)
{
    sfVector2u size = sfRenderWindow_getSize(global->window);
    sfVector2f pos_start = {size.x / 2 - 300, size.y / 2 + 250};
    sfVector2f pos_quit = {size.x / 2 - 300, size.y / 2};

    sfSprite_setPosition(global->menu.buttons.s_quit, pos_start);
    sfSprite_setPosition(global->menu.buttons.s_quit_col, pos_start);
    sfSprite_setPosition(global->menu.buttons.s_start, pos_quit);
    sfSprite_setPosition(global->menu.buttons.s_start_col, pos_quit);
}

void define_all_buttons(global_t *global)
{
    define_all_buttons_part2(global);
    if (!global->menu.buttons.t_quit || !global->menu.buttons.t_quit_col ||
        !global->menu.buttons.t_start || !global->menu.buttons.t_start_col ||
        !global->menu.buttons.t_quit || !global->menu.buttons.t_quit_col ||
        !global->menu.buttons.t_start || !global->menu.buttons.t_start_col)
            return;
    sfSprite_setTexture(global->menu.buttons.s_quit,
        global->menu.buttons.t_quit, sfTrue);
    sfSprite_setTexture(global->menu.buttons.s_quit_col,
        global->menu.buttons.t_quit_col, sfTrue);
    sfSprite_setTexture(global->menu.buttons.s_start,
        global->menu.buttons.t_start, sfTrue);
    sfSprite_setTexture(global->menu.buttons.s_start_col,
        global->menu.buttons.t_start_col, sfTrue);
    place_all_buttons(global);
}

void set_title_background(global_t *global)
{
    sfVector2f scale = {1.3, 1.3};
    sfVector2f pos_title = {425, 0};

    global->menu.title = sfText_create();
    global->menu.font = sfFont_createFromFile(FONT);
    global->menu.t_menu = sfTexture_createFromFile(BACKGROUND_MENU, NULL);
    global->menu.s_menu = sfSprite_create();
    if (!global->menu.title || !global->menu.font || !global->menu.t_menu ||
        !global->menu.s_menu)
            return;
    sfText_setString(global->menu.title, NAME);
    sfText_setFont(global->menu.title, global->menu.font);
    sfText_setColor(global->menu.title, sfWhite);
    sfText_setCharacterSize(global->menu.title, 175);
    sfText_setPosition(global->menu.title, pos_title);
    sfSprite_setTexture(global->menu.s_menu, global->menu.t_menu, sfFalse);
    sfSprite_scale(global->menu.s_menu, scale);
}

static void action_button(global_t *global)
{
    sfFloatRect pos_start = sfSprite_getGlobalBounds(global->
        menu.buttons.s_start_col);
    sfFloatRect pos_quit = sfSprite_getGlobalBounds(global->
        menu.buttons.s_quit_col);
    sfVector2f mouse = convert_position_mouse(global);

    if (sfFloatRect_contains(&pos_start, mouse.x, mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
            global->state = GAME;
    if (sfFloatRect_contains(&pos_quit, mouse.x, mouse.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(global->window);
}

static void click_button(global_t *global)
{
    sfFloatRect pos_start = sfSprite_getGlobalBounds(global->
        menu.buttons.s_start_col);
    sfFloatRect pos_quit = sfSprite_getGlobalBounds(global->
        menu.buttons.s_quit_col);
    sfVector2f mouse = convert_position_mouse(global);

    if (sfFloatRect_contains(&pos_start, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(global->window,
            global->menu.buttons.s_start, NULL);
    else
        sfRenderWindow_drawSprite(global->window, global->
            menu.buttons.s_start_col, NULL);
    if (sfFloatRect_contains(&pos_quit, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(global->window,
            global->menu.buttons.s_quit, NULL);
    else
        sfRenderWindow_drawSprite(global->window, global->
            menu.buttons.s_quit_col, NULL);
    action_button(global);
}

void create_all_menu(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->menu.s_menu, NULL);
    sfRenderWindow_drawText(global->window, global->menu.title, NULL);
    click_button(global);
    sfRenderWindow_display(global->window);
}
