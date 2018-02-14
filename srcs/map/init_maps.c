/*
** EPITECH PROJECT, 2017
** init_maps.c
** File description:
** inti_maps
*/

#include "navy.h"

maps *init_maps(maps *navy_maps, int ac, char **av)
{
	char	**ships = malloc(sizeof(char *) * 5);

	navy_maps->player = malloc(sizeof(char *) * 11);
	navy_maps->enemy = malloc(sizeof(char *) * 11);
	ships_infos(av[ac - 1], ships);
	ships_map(navy_maps->player, ships);
	empty_map(navy_maps->enemy);
	return (navy_maps);
}
