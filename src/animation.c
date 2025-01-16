/*
** EPITECH PROJECT, 2024
** animation.c
** File description:
** Animation of spritesheets
*/

#include "../includes/my_hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void draw_spritesheet(global_t *global, int i)
{
    sfSprite *sprite = sfSprite_create();

    if (global->all_demons.t_demon == NULL || sprite == NULL)
        return;
    sfSprite_setTexture(sprite, global->all_demons.t_demon, sfFalse);
    sfSprite_setPosition(sprite, global->all_demons.demon_array[i]->position);
    move(global, i);
    if (check_clock_animation(global))
        move_rect(&global->all_demons.rect, 81, 324);
    sfSprite_setTextureRect(sprite, global->all_demons.rect);
    global->all_demons.demon_array[i]->s_demon = sprite;
    sfRenderWindow_drawSprite(global->window, global->
        all_demons.demon_array[i]->s_demon, NULL);
}

void draw_background(global_t *global)
{
    sfSprite *sprite = sfSprite_create();

    if (global->background.t_background == NULL)
        return;
    sfSprite_setTexture(sprite, global->background.t_background, sfTrue);
    if (sprite == NULL)
        return;
    global->background.s_background = sprite;
    sfRenderWindow_drawSprite(global->window,
        global->background.s_background, NULL);
}
