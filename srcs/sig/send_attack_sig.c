/*
** EPITECH PROJECT, 2017
** send_attack_sig.c
** File description:
** Arthur
*/

#include "navy.h"

void send_attack_sig(maps *navy_maps, char *attack, int col, int line)
{
	for (int sg1 = 0; sg1 != col; ++sg1)
	{
		usleep(50000);
		kill(keep_pid(4, 0), SIGUSR1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
	for (int sg1 = 0; sg1 != line; ++sg1)
	{
		usleep(50000);
		kill(keep_pid(4, 0), SIGUSR1);
	}
	kill(keep_pid(4, 0), SIGUSR2);
	my_printf("%s: ", attack);
	hit_or_miss();
	replace_enemy_map(navy_maps, col, line);
	h_m(3);
}
