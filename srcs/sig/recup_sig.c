/*
** EPITECH PROJECT, 2017
** recup_sig.c
** File description:
** Arthur
*/

#include "navy.h"

void recup_sig(void)
{
	struct sigaction	*action_usr1 = malloc(sizeof(struct sigaction));

	action_usr1->sa_flags = SA_SIGINFO;
	action_usr1->sa_sigaction = &incr_usr1;
	sigaction(SIGUSR1, action_usr1, NULL);
	sigaction(SIGUSR2, action_usr1, NULL);
	while (count_sig2(2) != 2) {
		usleep(50000);
	}
	count_sig2(3);
	free(action_usr1);
}
