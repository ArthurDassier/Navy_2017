/*
** EPITECH PROJECT, 2017
** is_win.c
** File description:
** is_a_winnner
*/

#include "navy.h"

int loose()

int is_win(char **maps)
{
	int	i = 2;
	int	j = 2;

	while (maps[i] != NULL) {
		if (maps[i][j] >= 48 && maps[i][j] <= 57) {
			return (1);
		}
		++j;
		if (maps[i][j] == '\0') {
			j = 2;
			++i;
		}
	}
	return (0);
}
