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
	i = (ship[3] - 48) + 1;
	if (hori != 0)
		remp_lines_for_hori(map, hori, ship, j);
	while (verti != 0) {
		map[i - 1 + verti][j] = ship[0];
		--verti;
	}
	return (map);
}

char **remp_lines_for_hori(char **map, int hori, char *ship, int j)
{
	int	i = 0;

	i = ship[3] - 48 + 1;
	map[i][j] = ship[0];
	map[i][j - 2 + (hori * 2)] = ship[0];
	while (hori != 0) {
		if (hori % 2 != 0)
			map[i][j + 1 + hori] = ship[0];
		else
			map[i][j + 2 + hori] = ship[0];
		--hori;
	}
	return (map);
}
char **ships_infos(char *av, char **ships)
{
	int	fd = open(av, O_RDONLY);
	int	i = 0;

	while (i != 4) {
		ships[i] = malloc(sizeof(char) * 8);
		read(fd, ships[i], 8);
		ships[i++][7] = '\0';
	}
	ships[i] = '\0';
	return (ships);
}

int ship_hori(char *ship, int size)
{
	if (ship[2] != ship[5])
		return (size);
	return (0);
}

int ship_verti(char *ship, int size)
{
	if (ship[2] == ship[5])
		return (size);
	return (0);
}
