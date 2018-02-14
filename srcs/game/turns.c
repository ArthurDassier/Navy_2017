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


void attack()
{
	char	*attack;
	int	col;
	int	line;

	attack = get_next_line(0);
	col = mti(attack[0]);
	line = cti(attack[1]);
	for (int sg1 = 0; sg1 != col; ++sg1)
	{
		sleep(1);
		kill(keep_pid(4, 0), SIGUSR1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
	for (int sg1 = 0; sg1 != line; ++sg1)
	{
		sleep(1);
		kill(keep_pid(4, 0), SIGUSR1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
}

int game(maps *navy_maps)
{
	static int	oui = 0;
	line_col	var;

	recup_sig();
	var.line = save_col(0,2);
	var.col = col_line(1) - 2;
	oui = 1;
	save_col(0, 3);
	col_line(2);
	replace_maps(navy_maps, var);
	return (0);
}

int play(int ac, char **av, maps *navy_maps)
{
	while (1) {
		if (ac == 2) {
			displays_for_p1(navy_maps);
			attack();
			game(navy_maps);
		}
		if (ac == 3) {
			displays_for_p2(navy_maps);
			game(navy_maps);
			attack();
		}
	}
}
