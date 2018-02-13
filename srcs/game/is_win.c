/*
** EPITECH PROJECT, 2017
** is_win.c
** File description:
** is_a_winnner
*/

#include "navy.h"

int is_win(char **maps)
{
	int	i = 0;
	int	j = 0;

	while (maps[i] != NULL) {
		if (maps[i][j] == '\0') {
			j = 0;
			++i;
		}
		if (maps[i][j] >= 48 && maps[i][j] <= 57)
			return (1);
		++j;
	}
	return (0);
}
