/*
** EPITECH PROJECT, 2017
** turns.c
** File description:
** Arthur
*/

#include "navy.h"

int mti(char maj)
{
	return (maj - 15 - 48);
}

char itm(int maj)
{
	return (maj + 16 + 48);
}

void attack(local_attack *local)
{
	char	*attack;
	int	col = 0;
	int	line = 0;

	attack = get_next_line(0);
	col = mti(attack[0]);
	line = cti(attack[1]);
	local->l_col = line;
	local->l_line = col;
	for (int sg1 = 0; sg1 != col; ++sg1)
	{
		usleep(50000);
		kill(keep_pid(4, 0), SIGUSR1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
	for (int sg1 = 0; sg1 != line; ++sg1)
	{
		usleep(50000);
		kill(keep_pid(4, 0), SIGUSR1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
	hit_or_miss(attack);
}

int game(maps *navy_maps, line_col *var, local_attack *local)
{
	recup_sig();
	var->line = save_col(0,2);
	var->col = col_line(1) - 2;
	save_col(0, 3);
	col_line(2);
	replace_maps(navy_maps, var);
	return (0);
}

int play(int ac, maps *navy_maps)
{
	local_attack	local;
	line_col	var;

	local.turn = 0;
	local.l_line = 0;
	local.l_col = 0;
	while (1) {
		local.turn = 0;
		if (ac == 2) {
			++local.turn;
			displays_for_p1(navy_maps);
			attack(&local);
			game(navy_maps, &var, &local);
		}
		if (ac == 3) {
			displays_for_p2(navy_maps);
			game(navy_maps, &var, &local);
			my_putstr("\nattack: ");
			attack(&local);
			replace_maps(navy_maps, &var);
		}
	}
}
