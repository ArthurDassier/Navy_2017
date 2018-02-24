/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** creating_map_functions
*/

#include "navy.h"

int ships_map(char **my_map, char **ships)
{
	int	nb = 0;
	int	horizon = 0;
	int	vertical = 0;

	malloc_map(my_map);
	empty_map(my_map);
	while (ships[nb] != NULL) {
		horizon = ship_hori(ships[nb], (ships[nb][0] - 48));
		vertical = ship_verti(ships[nb], (ships[nb][0] - 48));
		if (remp_with_nb(my_map, horizon, vertical, ships[nb]) != 0)
			return (-1);
		++nb;
	}
	return (0);
}

char **empty_map(char **enemys_map)
{
	int	i = 0;
	int	j = 0;

	malloc_map(enemys_map);
	enemys_map[i++] = " |A B C D E F G H";
	enemys_map[i++] = "-+---------------";
	while (i != 10) {
		enemys_map[i][j++] = (i - 1) + 48;
		enemys_map[i][j++] = '|';
		while (j != 18) {
			enemys_map[i][j++] = '.';
			enemys_map[i][j++] = ' ';
		}
		enemys_map[i][--j] = '\0';
		j = 0;
		++i;
	}
	return (enemys_map);
}

char **malloc_map(char **map)
{
	int	i = 0;

	while (i != 10)
		map[i++] = malloc(sizeof(char) * 18);
	map[i] = NULL;
	return (map);
}
