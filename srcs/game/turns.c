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
		display_maps(navy_maps);
		my_putstr("\nI win\n");
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
		display_maps(navy_maps);
		my_putstr("\nEnemy won\n");
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
	while (attack_err(attack) != 0) {
		my_putstr("\nattack: ");
		attack = get_next_line(0);
		col = mti(attack[0]);
		line = cti(attack[1]);
	}
	send_attack_sig(navy_maps, attack, col, line);
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
		if (ac == 2 && (salut = order_p1(var, navy_maps)) != 2) {
			return (salut);
		}
		if (ac == 3 && (salut = order_p2(var, navy_maps)) != 2) {
			return (salut);
		}
	}
	return (1);
}
