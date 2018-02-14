/*
** EPITECH PROJECT, 2017
** replace_maps.c
** File description:
** replace_with_col_line
*/

#include "navy.h"

maps *replace_maps(maps *navy_maps, line_col *var)
{
	var->col += 1;
	var->line *= 2;
	printf("== col ==> %d\n", var->col);
	printf("== lin ==> %d\n", var->line);
	if (navy_maps->player[var->col][var->line] >= 48 &&
			navy_maps->player[var->col][var->line] <= 57) {
		navy_maps->player[var->col][var->line] = 'x';
		navy_maps->enemy[var->col][var->line] = 'x';
	} else {
		navy_maps->player[var->col][var->line] = 'o';
		navy_maps->enemy[var->col][var->line] = 'o';
	}
	return (navy_maps);
}
