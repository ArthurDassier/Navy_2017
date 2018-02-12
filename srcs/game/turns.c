/*
** EPITECH PROJECT, 2017
** turns.c
** File description:
** Arthur
*/

#include "navy.h"

int mti(char maj)
{
	return (maj - 16);
}


void attack(char **my_map, char **enemys_map)
{
	char	*attack = get_next_line(0);
	int	col = mti(attack[0]);
	int	line = cti(attack[1]);

	for (int sg1; sg1 != col; ++sg1)
	{
		kill(keep_pid(3, 0), SIGUSR1);
	}
	kill(keep_pid(3, 0), SIGUSR2);
	for (int sg1; sg1 != col; ++sg1)
	{
		kill(keep_pid(3, 0), SIGUSR1);
	}
	kill(keep_pid(3, 0), SIGUSR2);
}

int game(char **my_map, char **enemys_map)
{
	int col = 0;
	int line = 0;
	recup_sig();
	//col = my_getnbr(save_col(0,2));
	//line = my_getnbr(col_line(1) - 1);
	//save_col(0, 3);
	//col_line(2);
	return (col);
}
