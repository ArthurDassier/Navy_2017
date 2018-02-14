/*
** EPITECH PROJECT, 2017
** print_maps.c
** File description:
** print_maps
*/

#include "navy.h"

void display_maps(maps *navy_maps)
{
	my_putstr("\nmy_positions:\n");
	my_show_tab(navy_maps->player);
	my_putstr("\nenemy's positions:\n");
	my_show_tab(navy_maps->enemy);
}

void displays_for_p1(maps *navy_maps)
{
	display_maps(navy_maps);
	my_putstr("\nattack: ");
}

void displays_for_p2(maps *navy_maps)
{
	display_maps(navy_maps);
	my_putstr("\nwaiting for enemy's attack...\n");
}
