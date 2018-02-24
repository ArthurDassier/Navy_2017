/*
** EPITECH PROJECT, 2017
** init_maps.c
** File description:
** inti_maps
*/

#include "navy.h"

int init_maps(maps *navy_maps, int ac, char **av)
{
	char	**ships = malloc(sizeof(char *) * 5);

	navy_maps->player = malloc(sizeof(char *) * 11);
	navy_maps->enemy = malloc(sizeof(char *) * 11);
	if (ships_infos(av[ac - 1], ships) == NULL)
		return (-1);
	if (ships_map(navy_maps->player, ships) != 0)
		return (-1);
	empty_map(navy_maps->enemy);
	return (0);
}
