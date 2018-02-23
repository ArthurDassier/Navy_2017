/*
** EPITECH PROJECT, 2017
** first_connection.c
** File description:
** Arthur
*/

#include "navy.h"

int check_first_sig(int code)
{
	static int	value = 0;

	if (code == 1)
		value = 1;
	return (value);
}

void recup_first_sig(int sig, siginfo_t *siginfo, void *context)
{
	(void) sig;
	(void) context;
	(void) siginfo;
	check_first_sig(1);
}

void catch_first_sig(void)
{
	struct sigaction	*act = malloc(sizeof(struct sigaction));

	act->sa_flags = SA_SIGINFO;
	act->sa_sigaction = &recup_first_sig;
	sigaction(SIGUSR1, act, NULL);
	while (check_first_sig(0) == 0);
	free(act);
}
