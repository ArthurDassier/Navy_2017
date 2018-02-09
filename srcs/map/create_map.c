/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** creating_map_functions
*/

#include "navy.h"

void play(int ac, char **av)
{
	char	**enemys_map = malloc(sizeof(char*) * 11);
	char	**my_map = malloc(sizeof(char*) * 11);
	char	**ships = malloc(sizeof(char*) * 4);
	int	i = 0;

	ships_infos(ac, av, ships);
	while (ships[i] != NULL)
		my_printf("%s\n", ships[i++]);
	i = 0;
	empty_map(enemys_map);
	ships_map(my_map, ships);
	my_printf("\nmy position:\n");
	while (my_map[i] != NULL)
		my_printf("%s\n", my_map[i++]);
	i = 0;
	my_printf("\nenemy's position:\n");
	while (enemys_map[i] != NULL)
		my_printf("%s\n", enemys_map[i++]);
	free(my_map);
	free(enemys_map);
}

char **ships_map(char **my_map, char **ships)
{
	int	nb = 0;
	int	horizo = 0;
	int	vertica = 0;

	malloc_map(my_map);
	empty_map(my_map);
	while (ships[nb] != NULL) {
		horizo = ship_hori(ships[nb], (ships[nb][0] - 48));
		vertica = ship_verti(ships[nb], (ships[nb][0] - 48));
		remp_with_nb(my_map, horizo, vertica, ships[nb]);
		++nb;
	}
	return (my_map);
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