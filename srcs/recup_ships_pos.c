/*
** EPITECH PROJECT, 2017
** recup_ships_pos.c
** File description:
** recup_pos
*/

#include "navy.h"

char **ships_infos(int ac, char **av, char **ships)
{
	int	fd = open(av[ac-1], O_RDONLY);
	int	i = 0;

	while (i != 4) {
		ships[i] = get_next_line(fd);
		++i;
	}
	return (ships);
}
