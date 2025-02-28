/*
** EPITECH PROJECT, 2024
** check_interaction_mouse_demon.c
** File description:
** To check if mouse click on a demon
*/

#include "../includes/my_hunter.h"

sfVector2f convert_position_mouse(global_t *global)
{
    sfVector2f float_pos;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *) global->window);

    float_pos.x = (float) mouse_pos.x;
    float_pos.y = (float) mouse_pos.y;
    return float_pos;
}

void click_demons(global_t *global, int i)
{
    sfVector2f pos_mouse = convert_position_mouse(global);
    sfFloatRect pos_demon = sfSprite_getGlobalBounds
        (global->all_demons.demon_array[i]->s_demon);
    sfBool clicked = sfFloatRect_contains(&pos_demon,
        pos_mouse.x, pos_mouse.y);

    if (clicked == sfTrue && sfMouse_isButtonPressed(sfMouseLeft))
        global->all_demons.demon_array[i]->is_dead = 1;
}
