/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** Arthur
*/

#include "navy.h"

int main(int ac, char **av)
{
	if (ac < 2) {
		my_puterror("You need a folder as argument\n");
		return (84);
	}
	if (ac > 3) {
		my_puterror("You must give only one folder as argument\n");
		return (84);
	}
	return (server(ac, av));
	return (0);
}
