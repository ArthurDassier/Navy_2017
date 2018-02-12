/*
** EPITECH PROJECT, 2017
** turns.c
** File description:
** Arthur
*/

#include "navy.h"

int mti(char maj)
{
	return (maj - 16 - 48);
}


void attack()
{
	char	*attack = get_next_line(0);
	int	col = mti(attack[0]);
	int	line = cti(attack[1]);

	for (int sg1 = 0; sg1 != col; ++sg1)
	{
		kill(keep_pid(4, 0), SIGUSR1);
		sleep(1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
	for (int sg1 = 0; sg1 != line; ++sg1)
	{
		kill(keep_pid(4, 0), SIGUSR1);
		sleep(1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
}

int game()
{
	static int oui = 0;

	recup_sig();
	printf("%d\n", save_col(0,2));
	printf("%d\n", col_line(1) - 1);
	oui = 1;
	return (0);
	//save_col(0, 3);
	//col_line(2);
}
