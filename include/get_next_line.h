/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct variables
{
	int	i;
	int	j;
	int	rv;
	char	*tmp;
} var;

char *init_str(char *buff, int fd);
char *my_memset(char *str, char remp, int nb);
char *realloc_str(char *buff);
char *eject_buff(char *buff);
char *get_next_line(int fd);
char *buff_cpy(char *buff, char *tmp, int j, int i);
var init_var(void);

#ifndef READ_SIZE
#	define READ_SIZE (1)
#endif

#endif
