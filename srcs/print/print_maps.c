/*
** EPITECH PROJECT, 2017
** print_maps.c
** File description:
** print_maps
*/

#include "navy.h"

void display_maps(maps *navy_maps)
{
	my_putstr("my_positions:\n");
	my_show_tab(navy_maps->player);
	my_putstr("\nenemy's positions:\n");
	my_show_tab(navy_maps->enemy);
	my_putstr("\nwaiting for enemy's attack...\n");
}

void displays_for_p1(maps *navy_maps, int touch)
{
	display_maps(navy_maps);
	my_putstr("attack: ");
}

void displays_for_p2(maps *navy_maps, int touch)
{
	display_maps(navy_maps);
	my_putstr("waiting for enemy's attack...\n");
}
