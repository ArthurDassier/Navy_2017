/*
** EPITECH PROJECT, 2017
** replace_maps.c
** File description:
** replace_with_col_line
*/

#include "navy.h"

maps *replace_maps(maps *navy_maps, line_col *var, local_attack *local)
{
	if (local->turn == 0) {
		++local->turn;
		return (navy_maps);
	}
	var->col += 1;
	var->line *= 2;
	local->l_col += 1;
	local->l_line -= 1;
	local->l_line *= 2;
	if (navy_maps->player[var->col][var->line] >= 48 &&
			navy_maps->player[var->col][var->line] <= 57) {
		navy_maps->player[var->col][var->line] = 'x';
		navy_maps->enemy[local->l_col][local->l_line] = 'x';
		my_printf("%c%d: hit\n\n", itm((local->l_line / 2)), local->l_col - 1);
	} else {
		navy_maps->player[var->col][var->line] = 'o';
		navy_maps->enemy[local->l_col][local->l_line] = 'o';
		my_printf("%c%d: missed\n\n", itm((local->l_line / 2)), local->l_col - 1);
	}
	return (navy_maps);
}
