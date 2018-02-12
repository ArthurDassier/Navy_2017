/*
** EPITECH PROJECT, 2017
** init_maps.c
** File description:
** inti_maps
*/

#include "navy.h"

maps *init_maps(maps *navy_maps, int ac, char **av)
{
	char	**ships_p1 = malloc(sizeof(char *) * 4);
	char	**ships_p2 = malloc(sizeof(char *) * 4);

	navy_maps->p1 = malloc(sizeof(char *) * 11);
	navy_maps->p2 = malloc(sizeof(char *) * 11);
	navy_maps->enemy_p1 = malloc(sizeof(char *) * 11);
	navy_maps->enemy_p2 = malloc(sizeof(char *) * 11);

	ships_infos(av[ac - 1], ships_p1);
	ships_infos(av[ac - 2], ships_p2);

	my_show_tab(ships_p1);
	my_show_tab(ships_p2);
	ships_map(navy_maps->p1, ships_p1);
	ships_map(navy_maps->p2, ships_p2);

	empty_map(navy_maps->enemy_p1);
	empty_map(navy_maps->enemy_p2);

	return (navy_maps);
}
