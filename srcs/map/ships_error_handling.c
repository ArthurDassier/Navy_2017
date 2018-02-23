/*
** EPITECH PROJECT, 2017
** ships_error_handling.c
** File description:
** ships_error_handling
*/

#include "navy.h"

int ships_nb_handling(char **ships)
{
	int	i = 0;

	while (ships[i] != '\0') {
		if (ships[i][0] != '2' && ships[i][0] != '3' &&
				ships[i][0] != '4' && ships[i][0] != '5')
			return (-1);
		++i;
	}
	return (0);
}

int sihps_size_handling(char **ships)
{
	if (ships[0][0] == ships[1][0] || ships[0][0] == ships[2][0] ||
			ships[0][0] == ships[3][0])
		return (-1);
	else if (ships[1][0] == ships[2][0] || ships[1][0] == ships[3][0])
		return (-1);
	if (ships[2][0] == ships[3][0])
		return (-1);
	return (0);
}

int ships_error_handling(char **ships)
{
	if (ships_nb_handling(ships) != 0)
		return (-1);
	else if (ships_size_handling(ships) != 0)
		return (-1);
}
