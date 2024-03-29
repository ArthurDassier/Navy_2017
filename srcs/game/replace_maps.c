/*
** EPITECH PROJECT, 2017
** replace_maps.c
** File description:
** replace_with_col_line
*/

#include "navy.h"

int h_m(int code)
{
	static int check = 0;

	if (code == 0)
		return (check);
	if (code == 1)
		check = 1;
	if (code == 2)
		check = 2;
	if (code == 3)
		check = 0;
	return (check);
}

int checker(int code)
{
	static int check = 0;

	if (code == 0)
		return (check);
	if (code == 1)
		check = 1;
	if (code == 2)
		check = 0;
	return (0);
}

void displayer(int sig, siginfo_t *siginfo, void *context)
{
	(void) sig;
	(void) siginfo;
	(void) context;
	if (sig == SIGUSR1) {
		my_printf("hit\n");
		checker(1);
		h_m(1);
	}
	if (sig == SIGUSR2) {
		my_printf("missed\n");
		checker(1);
		h_m(2);
	}
}

void hit_or_miss(void)
{
	struct sigaction	*hitormiss = malloc(sizeof(struct sigaction));

	sigemptyset(&hitormiss->sa_mask);
	hitormiss->sa_flags = SA_SIGINFO;
	hitormiss->sa_sigaction = &displayer;
	sigaction(SIGUSR1, hitormiss, NULL);
	sigaction(SIGUSR2, hitormiss, NULL);
	while (checker(0) == 0)
		usleep(50000);
	checker(2);
	free(hitormiss);
}

maps *replace_maps(maps *navy_maps, line_col *var)
{
	usleep(50000);
	my_printf("%c%d: ", itm(var->line), var->col);
	var->col += 1;
	var->line *= 2;
	if (navy_maps->player[var->col][var->line] == 'x') {
		my_putstr("missed\n");
		kill(keep_pid(4, 0), SIGUSR2);
		return (navy_maps);
	}
	if (navy_maps->player[var->col][var->line] >= 48 &&
			navy_maps->player[var->col][var->line] <= 57) {
		navy_maps->player[var->col][var->line] = 'x';
		my_putstr("hit\n");
		kill(keep_pid(4, 0), SIGUSR1);
	} else {
		navy_maps->player[var->col][var->line] = 'o';
		my_putstr("missed\n");
		kill(keep_pid(4, 0), SIGUSR2);
	}
	return (navy_maps);
}
