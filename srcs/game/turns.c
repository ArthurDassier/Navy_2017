/*
** EPITECH PROJECT, 2017
** turns.c
** File description:
** Arthur
*/

#include "navy.h"

int check_wn_status(maps *navy_maps)
{
	struct sigaction	*win = malloc(sizeof(struct sigaction));

	win->sa_flags = SA_SIGINFO;
	win->sa_sigaction = &loose;
	sigaction(SIGUSR1, win, NULL);
	sigaction(SIGUSR2, win, NULL);
	while (is_loose(3) == 0) {
		usleep(50000);
	}
	if (is_loose(3) == 1) {
		my_putstr("I win\n");
		free(win);
		return (1);
	}
	is_loose(4);
	free(win);
	return (0);
}

int check_ls_status(maps *navy_maps)
{
	if (is_win(navy_maps->player) == 0) {
		my_putstr("Enemy won\n");
		return (1);
	}
	return (0);
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
	line_col	var;
	int		salut = 0;

	while (1) {
		if (ac == 2) {
			displays_for_p1(navy_maps);
			attack(navy_maps);
			if ((salut = check_wn_status(navy_maps)) > 0)
				return (salut);
			game(navy_maps, &var);
			if ((salut = check_ls_status(navy_maps)) > 0)
				return (salut);
		}
		if (ac == 3) {
			displays_for_p2(navy_maps);
			game(navy_maps, &var);
			if ((salut = check_ls_status(navy_maps)) > 0)
				return (salut);
			my_putstr("\nattack: ");
			attack(navy_maps);
			if ((salut = check_wn_status(navy_maps)) > 0)
				return (salut);
		}
	}
	return (1);
}
