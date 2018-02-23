/*
** EPITECH PROJECT, 2017
** orders.c
** File description:
** Arthur
*/

#include "navy.h"

int order_p1(line_col var, maps *navy_maps)
{
	int	salut = 0;

	displays_for_p1(navy_maps);
	attack(navy_maps);
	if ((salut = check_wn_status(navy_maps)) > 0)
		return (salut - 1);
	game(navy_maps, &var);
	if ((salut = check_ls_status(navy_maps)) > 0)
		return (salut);
	return (2);
}

int order_p2(line_col var, maps *navy_maps)
{
	int	salut = 0;

	displays_for_p2(navy_maps);
	game(navy_maps, &var);
	if ((salut = check_ls_status(navy_maps)) > 0)
		return (salut);
	my_putstr("\nattack: ");
	attack(navy_maps);
	if ((salut = check_wn_status(navy_maps)) > 0)
		return (salut - 1);
	return (2);
}
