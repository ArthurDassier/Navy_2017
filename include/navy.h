/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** navy_h_
*/

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
