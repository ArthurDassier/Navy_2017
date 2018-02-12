/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** Arthur
*/

#include "navy.h"

int main(int ac, char **av)
{
	maps	*navy_maps = malloc(sizeof(maps));

	init_maps(navy_maps, ac, av);
	my_show_tab(navy_maps->p1);
	my_show_tab(navy_maps->p2);
//	if (ac < 3) {
//		my_puterror("You need two folders as argument\n");
//		return (84);
//	}
//	if (ac > 5) {
//		my_puterror("You must give only one folder as argument\n");
//		return (84);
//	}
//	server(ac, av);
	return (0);
}
