/*
** EPITECH PROJECT, 2017
** ships_position.c
** File description:
** ship_pos
*/

#include "navy.h"

char **remp_with_nb(char **map, int hori, int verti, char *ship)
{
	int	i = 0;
	int	j = 0;

	while (map[i][j] != ship[2])
		++j;
	while (i != ship[3])
		++i;
	while (hori != 0 && verti != 0) {
		map[i + verti][j + hori] = ship[0];
		if (hori > 0)
			--hori;
		if (verti > 0)
			--verti;
	}
	return (map);
}

int ship_hori(char *ship, int size)
{
	if (ship[2] == ship[5]) {
		if ((ship[3] - 48) > (ship[6] - 48))
			return (size);
		else
			return (size * -1);
	}
	return (0);
}

int ship_verti(char *ship, int size)
{
	if (ship[2] != ship[5]) {
		if (ship[2] > ship[5])
			return (size);
		else
			return (size * -1);
	}
	return (0);
}
