/*
** EPITECH PROJECT, 2017
** recup_sig.c
** File description:
** Arthur
*/

#include "navy.h"

int col_line(int code)
{
	static int	i = 0;

	if (code == 1) {
		++i;
		return (i);
	}
	if (code == 2)
		i = 0;
	return (0);
}

int save_col(int col, int code)
{
	static int	save_col = 0;

	if (code == 1)
		save_col = col;
	if (code == 2)
		return (save_col);
	if (code == 3)
		save_col = 0;
	return (0);
}

void incr_usr1(int sig, siginfo_t *siginfo, void *context)
{
	(void) sig;
	(void) siginfo;
	(void) context;
	col_line(1);
}

void incr_usr2(int sig, siginfo_t *siginfo, void *context)
{
	static int	check = 0;

	(void) sig;
	(void) siginfo;
	(void) context;
	if (check == 0) {
		save_col(col_line(1) - 1, 1);
		++check;
	} else
		check = 0;
	col_line(2);
	count_sig2(1);
}

int count_sig2(int code)
{
	static int	count = 0;

	if (code == 1)
		++count;
	if (code == 2)
		return (count);
	else
		count = 0;
	return (count);
}

void recup_sig(void)
{
	struct sigaction	action_usr1;
	struct sigaction	action_usr2;

	action_usr1.sa_sigaction = &incr_usr1;
	action_usr2.sa_sigaction = &incr_usr2;
	sigaction(SIGUSR1, &action_usr1, NULL);
	sigaction(SIGUSR2, &action_usr2, NULL);
	while (count_sig2(2) != 2);
	count_sig2(3);
}
