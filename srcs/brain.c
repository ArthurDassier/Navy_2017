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

	if (ac > 3 || ac < 2) {
		my_puterror("bad argument\n");
		return (84);
	}
	init_maps(navy_maps, ac, av);
	return (server(ac, av, navy_maps));
}
