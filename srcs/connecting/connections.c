/*
** EPITECH PROJECT, 2017
** connections.c
** File description:
** Arthur
*/

#include "navy.h"

pid_t keep_pid(int usr, pid_t pid)
{
	static pid_t pid_usr1 = 0;
	static pid_t pid_usr2 = 0;

	if (usr == 1)
		pid_usr1 = pid;
	else if (usr == 2)
		pid_usr2 = pid;
	else if (usr == 3)
		return (pid_usr1);
	else if (usr == 4)
		return (pid_usr2);
	return (-1);
}

void catch_sigint(int sig, siginfo_t *siginfo, void *context)
{
	(void) sig;
	(void) context;
	my_printf("\nenemy connected\n");
	keep_pid(2, siginfo->si_pid);
	check_first_sig(1);
}

void wait_connection(void)
{
	struct sigaction	*act = malloc(sizeof(struct sigaction));

	sigemptyset(&act->sa_mask);
	act->sa_flags = SA_SIGINFO;
	my_printf("my_pid:\t%d\n", getpid());
	keep_pid(1, getpid());
	my_printf("waiting for enemy connection...\n");
	act->sa_sigaction = &catch_sigint;
	sigaction(SIGUSR1, act, NULL);
	while (check_first_sig(0) == 0);
	free(act);
}

int server(int ac, char **av, maps *navy_maps)
{
	if (ac == 2) {
		wait_connection();
	}
	if (ac == 3) {
		if (my_getnbr(av[1]) == 0)
			return (84);
		if (kill(my_getnbr(av[1]), SIGUSR1) == -1) {
			my_puterror("Invalid PID\n");
			return (84);
		}
		keep_pid(2, my_getnbr(av[1]));
		my_printf("my_pid:\t%d", getpid());
		my_printf("\nsuccessfully connected\n");
	}
	return (play(ac, navy_maps));
}
