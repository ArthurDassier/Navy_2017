/*
** EPITECH PROJECT, 2017
** replace_enemy_map.c
** File description:
** replace_enemy_map.c
*/

#include "navy.h"

maps *replace_enemy_map(maps *navy_maps, int col, int line)
{
	printf("== col ==> %d\n", col);
	printf("== lin ==> %d\n", line);
	line += 1;
	col *= 2;
	col -= 2;
	if (h_m(0) == 1)
		navy_maps->enemy[line][col] = 'x';
	else
		navy_maps->enemy[line][col] = 'o';
	return (navy_maps);
}
