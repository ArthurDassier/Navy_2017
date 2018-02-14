/*
** EPITECH PROJECT, 2017
** count_sig.c
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
	if (sig == SIGUSR1)
		col_line(1);
	if (sig == SIGUSR2)
		incr_usr2(sig, siginfo, context);
}

void incr_usr2(int sig, siginfo_t *siginfo, void *context)
{
	static int	check = 0;

	(void) sig;
	(void) siginfo;
	(void) context;
	count_sig2(1);
	if (check == 0) {
		save_col(col_line(1) - 1, 1);
		++check;
		col_line(2);
	} else {
		check = 0;
		return;
	}
}

int count_sig2(int code)
{
	static int	count = 0;

	if (code == 1)
		++count;
	if (code == 2)
		return (count);
	if (code == 3)
		count = 0;
	return (count);
}
