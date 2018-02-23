/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** navy_h_
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"
#include "printf.h"
#include "get_next_line.h"

typedef struct maps
{
	char	**player;
	char	**enemy;
} maps;

typedef struct line_col
{
	int	line;
	int	col;
	int	touch;
} line_col;

int checker(int code);
char itm(int maj);
int mti(char maj);
char **empty_map(char **enemys_map);
char **ships_map(char **my_map, char **ships);
char **malloc_map(char **map);
int ship_hori(char *ship, int size);
int ship_verti(char *ship, int size);
char **remp_with_nb(char **map, int hori, int verti, char *ship);
char **ships_infos(char *av, char **ships);
int server(int ac, char **av, maps *navy_maps);
char **remp_lines_for_hori(char **map, int hori, char *ship, int j);
maps *init_maps(maps *navy_maps, int ac, char **av);
maps *replace_maps(maps *navy_maps, line_col *var);
int is_win(char **maps);
int col_line(int code);
int save_col(int col, int code);
void incr_usr1(int sig, siginfo_t *siginfo, void *context);
void incr_usr2(int sig, siginfo_t *siginfo, void *context);
int count_sig2(int code);
void recup_sig(void);
maps *init_maps(maps *navy_maps, int ac, char **av);
pid_t keep_pid(int usr, pid_t pid);
void attack(maps *navy_maps);
int game(maps *navy_maps, line_col *var);
int play(int ac, maps *navy_maps);
void display_maps(maps *navy_maps);
void displays_for_p1(maps *navy_maps);
void displays_for_p2(maps *navy_maps);
void hit_or_miss(void);
int h_m(int code);
maps *replace_enemy_map(maps *navy_maps, int col, int line);
void loose(int sig, siginfo_t *siginfo, void *context);
int is_loose(int code);
void catch_first_sig(void);
int check_first_sig(int code);

#endif
