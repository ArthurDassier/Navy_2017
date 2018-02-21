/*
** EPITECH PROJECT, 2017
** is_win.c
** File description:
** is_a_winnner
*/

#include "navy.h"

int is_loose(int code)
{
	static int	check = 0;

	if (code == 1)
		check = 1;
	if (code == 2)
		check = 2;
	if (code == 3)
		return (check);
	if (code == 4)
		check = 0;
	return (check);
}

void loose(int sig, siginfo_t *siginfo, void *context)
{
	(void) sig;
	(void) siginfo;
	(void) context;
	if (sig == SIGUSR1)
		is_loose(2);
	if (sig == SIGUSR2)
		is_loose(1);
}

int is_win(char **maps)
{
	int	i = 2;
	int	j = 2;

	usleep(50000);
	while (maps[i] != NULL) {
		if (maps[i][j] >= 48 && maps[i][j] <= 57) {
			kill(keep_pid(4, 0), SIGUSR1);
			return (1);
		}
		++j;
		if (maps[i][j] == '\0') {
			j = 2;
			++i;
		}
	}
	kill(keep_pid(4, 0), SIGUSR2);
	return (0);
}
