/*
** EPITECH PROJECT, 2017
** gnl_part_two.c
** File description:
** gnl_part_two
*/

#include "navy.h"

char *buff_cpy(char *buff, char *tmp, int j, int i)
{
	if (j == (READ_SIZE - 1)) {
		buff[i] = tmp[i];
		buff = realloc_str(buff);
	}
	return (buff);
}

var init_var(void)
{
	var	gnl;

	gnl.i = 0;
	gnl.j = 0;
	gnl.rv = 0;
	gnl.tmp = malloc(sizeof(char) * READ_SIZE + 1);
	return (gnl);
}
