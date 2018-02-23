/*
** EPITECH PROJECT, 2017
** attack_err.c
** File description:
** Arthur
*/

#include "navy.h"

int attack_err(char *atk)
{
	if (my_strlen(atk) > 2) {
		my_putstr("wrong position");
		return (84);
	}
	if (atk[0] > 72 || atk [0] < 65 || atk[1] > 56 || atk[1] < 49) {
		my_putstr("wrong position");
		return (84);
	}
	return (0);
}
