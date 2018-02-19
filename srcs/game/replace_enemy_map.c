/*
** EPITECH PROJECT, 2017
** replace_enemy_map.c
** File description:
** replace_enemy_map.c
*/

#include "navy.h"

maps *replace_enemy_map(maps *navy_maps, line_col *var)
{
	if (var->touch == 1)
		navy_maps->enemy[var->col][var->line] = 'x';
	else
		navy_maps->enemy[var->col][var->line] = 'o';
	return (navy_maps);
}
