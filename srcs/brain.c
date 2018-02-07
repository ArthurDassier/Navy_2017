/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** Arthur
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
	printf("%s\n", my_map[i++]);
	i = 0;
	my_printf("\nenemy's position:\n");
	while (enemys_map[i] != NULL)
	my_printf("%s\n", enemys_map[i++]);
	free(my_map);
	free(enemys_map);
}

int main(int ac, char **av)
{
	if (ac < 2) {
		my_puterror("You need a folder as argument\n");
		return (84);
	}
	if (ac > 2) {
		my_puterror("You must give only one folder as argument\n");
		return (84);
	}
	play(ac, av);
	return(0);
}
