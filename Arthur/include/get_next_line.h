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

char *init_str(char *buff, int fd);
char *my_memset(char *str, char remp, int nb);
char *realloc_str(char *buff);
char *eject_buff(char *buff);
char *get_next_line(int fd);

#ifndef READ_SIZE
#	define READ_SIZE (1)
#endif

#endif
