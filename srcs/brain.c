/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** Arthur
*/

#include "navy.h"

int main(int ac, char **av)
{
	maps	*navy_maps = malloc(sizeof(maps));

<<<<<<< HEAD
	init_maps(navy_maps, ac, av);
	if (ac < 3) {
		my_puterror("You need two folders as argument\n");
		return (84);
	}
	if (ac > 5) {
		my_puterror("You must give only one folder as argument\n");
=======
	if (ac != 2) {
		my_puterror("bad argument\n");
>>>>>>> origin
		return (84);
	}
	init_maps(navy_maps, ac, av);
	my_show_tab(navy_maps->player);
	my_putchar('\n');
	my_show_tab(navy_maps->enemy);
//	server(ac, av);
	return (0);
}
