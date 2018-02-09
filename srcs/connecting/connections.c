/*
** EPITECH PROJECT, 2017
** connections.c
** File description:
** Arthur
*/

#include "navy.h"

static int global = 0;

int keep_pid(int usr, int pid)
{
	static int pid_usr1 = 0;
	static int pid_usr2 = 0;

	if (usr == 1)
		pid_usr1 = pid;
	else if (usr == 2)
		pid_usr2 = pid;
	else if (usr == 3)
		return (pid_usr1);
	else
		return (pid_usr2);
	return (-1);
}

void catch_sigint(int sig, siginfo_t *siginfo, void *context)
{
	my_printf("\nennemy connected\n");
	global = 1;
}

void wait_connection()
{
	struct sigaction act;

	my_printf("my_pid:\t%d\n", getpid());
	keep_pid(1, getpid());
	my_printf("waiting for enemy connection...\n");
	act.sa_sigaction = &catch_sigint;
	sigaction(SIGUSR1, &act, NULL);
	while (global == 0);
}

int server(int ac, char *av[])
{
	if (ac == 2)
		wait_connection();
	if (ac == 3) {
		kill(my_getnbr(av[1]), SIGUSR1);
		my_printf("my_pid:\t%d\n", getpid());
		keep_pid(2, getpid());
		my_printf("successfully connected\n");
		av[1] = av[2];
	}
	play(ac, av);
	return (0);
}
