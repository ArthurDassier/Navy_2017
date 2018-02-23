/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** Arthur
*/

#include "navy.h"

void helper(void)
{
	my_printf("USAGE\n\t");
	my_printf("./navy [first_player_pid] navy_positions\n");
	my_printf("DESCRIPTION\n\t");
	my_printf("first_player_pid:  only for the 2nd player.");
	my_printf(" pid of the first player.\n");
	my_printf("\tnavy_positions:  file representing ");
	my_printf("the positions of the ships.\n");
}

int main(int ac, char **av)
{
	maps	*navy_maps = malloc(sizeof(maps));

	if (ac > 3 || ac < 2) {
		my_puterror("bad argument\n");
		return (84);
	}
	if (av[1][0] == '-' && av[1][1] == 'h') {
		helper();
		return (0);
	}
	init_maps(navy_maps, ac, av);
	return (server(ac, av, navy_maps));
}
