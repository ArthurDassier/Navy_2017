/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** Arthur
*/

#include "navy.h"

int main(int ac, char **av)
{
	char	**enemys_map = malloc(sizeof(char*) * 11);
	char	**my_map = malloc(sizeof(char*) * 11);
	char	**ships = malloc(sizeof(char*) * 4);
	int	i = 0;

	ships_infos(ac, av, ships);
	while (ships[i] != NULL)
		printf("%s\n", ships[i++]);
	i = 0;
	empty_map(enemys_map);
	ships_map(my_map, ships);
	printf("\nmy position:\n");
	while (my_map[i] != NULL)
		printf("%s\n", my_map[i++]);
	i = 0;
	printf("\nenemy's position:\n");
	while (enemys_map[i] != NULL)
		printf("%s\n", enemys_map[i++]);
	free(my_map);
	free(enemys_map);
	return(0);
}
