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
	if (sig == SIGUSR1) {
		printf("1\n");
		col_line(1);
	}
	else if (sig == SIGUSR2) {
		printf("2\n");
		incr_usr2(sig, siginfo, context);
	}

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
	if (code == 1) {
		printf("OUI\n" );
		++count;
	}
	if (code == 2) {
		return (count);
	} else
		count = 0;
	printf(">>> %d\n", count);
	return (count);
}

void recup_sig(void)
{
	struct sigaction	*action_usr1 = malloc(sizeof(struct sigaction));

	action_usr1->sa_flags = SA_SIGINFO;
	action_usr1->sa_sigaction = &incr_usr1;
	sigaction(SIGUSR1, action_usr1, NULL);
	sigaction(SIGUSR2, action_usr1, NULL);
	while (count_sig2(2) != 2) {
		sleep(1);
	}
	//count_sig2(3);
	free(action_usr1);
}
