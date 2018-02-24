/*
** EPITECH PROJECT, 2017
** ships_position.c
** File description:
** ship_pos
*/

#include "navy.h"

int remp_with_nb(char **map, int hori, int verti, char *ship)
{
	int	i = 0;
	int	j = 0;

	while (map[i][j] != ship[2])
		++j;
	i = (ship[3] - 48) + 1;
	if (hori != 0) {
		if (remp_lines_for_hori(map, hori, ship, j) != 0)
			return (-1);
	}
	while (verti != 0) {
		if (map[i - 1 + verti][j] >= 49 &&
				map[i - 1 + verti][j] <= 57)
			return (-1);
		map[i - 1 + verti][j] = ship[0];
		--verti;
	}
	return (0);
}

int remp_lines_for_hori(char **map, int hori, char *ship, int j)
{
	int	i = 0;

	i = ship[3] - 48 + 1;
	map[i][j] = ship[0];
	map[i][j - 2 + (hori * 2)] = ship[0];
	while (hori != 0) {
		if (hori % 2 != 0) {
			if (map[i][j + 1 + hori] >= 49 &&
					map[i][j + 1 + hori] <= 57)
				return (-1);
			map[i][j + 1 + hori] = ship[0];
		} else {
			if (map[i][j + 1 + hori] >= 49 &&
					map[i][j + 1 + hori] <= 57)
				return (-1);
			map[i][j + 2 + hori] = ship[0];
		}
		--hori;
	}
	return (0);
}
char **ships_infos(char *av, char **ships)
{
	int	fd = open(av, O_RDONLY);
	int	i = 0;

	if (fd == -1)
		return (NULL);
	while (i != 4) {
		ships[i] = malloc(sizeof(char) * 8);
		if (read(fd, ships[i], 8) == -1)
			return (NULL);
		ships[i++][7] = '\0';
	}
	ships[i] = '\0';
	if (ships_error_handling(ships) != 0)
		return (NULL);
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
