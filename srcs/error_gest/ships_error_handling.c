/*
** EPITECH PROJECT, 2017
** ships_error_handling.c
** File description:
** ships_error_handling
*/

#include "navy.h"

int add_hori(char *map, char *ship, int hori, int j)
{
	if (hori % 2 != 0) {
		map[j + 1 + hori] = ship[0];
	} else {
		map[j + 2 + hori] = ship[0];
	}
	return (0);
}

int ships_nb_handling(char **ships)
{
	int	i = 0;

	while (ships[i]) {
		if (ships[i][0] != '2' && ships[i][0] != '3'
		&& ships[i][0] != '4' && ships[i][0] != '5')
			return (-1);
		++i;
	}
	if (cti(ships[0][0]) + cti(ships[1][0]) + cti(ships[2][0]) +
	cti(ships[3][0]) != 14)
		return (-1);
	return (0);
}

int ships_error_handling(char **ships)
{
	if (ships_nb_handling(ships) != 0)
		return (-1);
	return (0);
}
