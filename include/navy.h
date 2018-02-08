/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** navy_h_
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "printf.h"
#include "get_next_line.h"

char **empty_map(char **enemys_map);
char **ships_map(char **my_map, char **ships);
char **malloc_map(char **map);
int ship_hori(char *ship, int size);
int ship_verti(char *ship, int size);
char **remp_with_nb(char **map, int hori, int verti, char *ship);
char **ships_infos(int ac, char **av, char **ships);
int server(int ac, char *av[]);
void play(int ac, char **av);

#endif
