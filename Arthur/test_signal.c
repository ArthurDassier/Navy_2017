/*
** EPITECH PROJECT, 2017
** test_signal.c
** File description:
** Arthur
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void catch_sigint(int sig, siginfo_t *siginfo, void *context)
{
	printf("ennemy connected\n");
}

void ouaite()
{
	struct sigaction act;
	printf("pid : %d\n", getpid());
	printf("Waiting for the ennemy to connect ...\n");
	act.sa_sigaction = &catch_sigint;
	while (1) {
		if (sigaction(SIGUSR1, &act, NULL))
			break;
	}
	return;
}

int main(int argc, char const *argv[])
{
	if (argc == 2) {
		ouaite();
	}
	if (argc == 3) {
		kill(atoi(argv[1]), SIGUSR1);
		printf("connected to server\n");
	}
	printf("programm ended\n");
	return (0);
}
