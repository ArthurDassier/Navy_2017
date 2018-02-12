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

	if (ac < 2) {
		my_puterror("You need two folders as argument\n");
		return (84);
	}
	if (ac > 3) {
		my_puterror("You must give only one folder as argument\n");
		return (84);
	}
	init_maps(navy_maps, ac, av);
	server(ac, av, navy_maps);
	return (0);
}
