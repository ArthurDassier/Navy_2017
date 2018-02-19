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

void attack(maps *navy_maps)
{
	char	*attack;
	int	col = 0;
	int	line = 0;

	attack = get_next_line(0);
	col = mti(attack[0]);
	line = cti(attack[1]);
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
	my_printf("%s: ", attack);
	hit_or_miss();
	replace_enemy_map(navy_maps, col, line);
	h_m(3);
}

int game(maps *navy_maps, line_col *var)
{
	my_putstr("\nwaiting for enemy's attack...\n");
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
	struct sigaction	*win = malloc(sizeof(struct sigaction));
	line_col		var;

	win->sa_flags = SA_SIGINFO;
	win->sa_sigaction = &loose;
	while (is_win(navy_maps->player) == 1) {
		sigaction(SIGUSR2, win, NULL);
		if (ac == 2) {
			displays_for_p1(navy_maps);
			attack(navy_maps);
			game(navy_maps, &var);
		}
		if (ac == 3) {
			displays_for_p2(navy_maps);
			game(navy_maps, &var);
			my_putstr("\nattack: ");
			attack(navy_maps);
		}
	}
	my_putstr("I won\n");
	return (0);
}
