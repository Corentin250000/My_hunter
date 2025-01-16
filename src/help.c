/*
** EPITECH PROJECT, 2024
** help.c
** File description:
** print help when -h or --help appears
*/

#include "../includes/my_hunter.h"

int print_help(char **av)
{
    if (!my_strcmp(av[1], "-h") || !my_strcmp(av[1], "--help")) {
        my_putstr("USAGE\n\t./my_hunter <-h / --help>\n\nDESCRIPTION\n\t"
            "-h / --help\tDisplay this help\n\tPress escape key to quit.\n"
            "\tPress a mystery key to play a special sound.\n"
            "\nINSTRUCTIONS BEFORE PLAYING\n"
            "\tPut your PC in performance mode.\n"
            "\tI highly recommand to play with a mouse, not with the trackpad."
            "\n\tTo display your score, you must finish the level.\n"
            "\nLICENSES/SOURCES\n"
            "\tMenu's music: Conflict (instrumental) -- Slaughter of Prevail\n"
            "\tMusic: Psalm of Agony (instrumental) -- Entreprise Earth\n"
            "\tDemons: Mattz Art (itch.io)\n"
            "\tBackgrounds: fr.wallpaper.mob.org\n"
            "\tFonts: fontspace.com\n");
        return 0;
    } else
        return 84;
}
