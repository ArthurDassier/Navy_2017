/*
** EPITECH PROJECT, 2017
** connections.c
** File description:
** Arthur
*/

#include "navy.h"

void catch_sigint(int sig, siginfo_t *siginfo, void *context)
{
	my_printf("ennemy connected\n");
}

void wait_connection(int ac, char *av[])
{
	struct sigaction act;

	my_printf("my_pid:\t%d\n", getpid());
	my_printf("waiting for enemy connection...\n");
	act.sa_sigaction = &catch_sigint;
	while (1) {
		if (sigaction(SIGUSR1, &act, NULL))
			break;
	}
	return;
}

int server(int ac, char *av[])
{
	if (ac == 2)
		wait_connection(ac, av);
	if (ac == 3) {
		kill(my_getnbr(av[1]), SIGUSR1);
		my_printf("my_pid:\t%d\n", getpid());
		my_printf("successfully connected\n");
		av[1] = av[2];
	}
	play(ac, av);
}
