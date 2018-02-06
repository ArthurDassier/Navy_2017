/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** get_next_line_c_
*/

#include "get_next_line.h"

char *init_str(char *buff, int fd)
{
	static int	i = 1;

	if (i == 1 || fd == 0) {
		buff = malloc(sizeof(char) * READ_SIZE + 1);
		if (buff == NULL)
			return (NULL);
		--i;
	}
	return (buff);
}

char *my_memset(char *str, char remp, int nb)
{
	int	i = 0;

	while (i != nb) {
		str[i] = remp;
		++i;
	}
	str[i] = '\0';
	return (str);
}

char *realloc_str(char *buff)
{
	static int	i = 2;
	int		j = 0;
	char		*tmp = NULL;

	tmp = malloc(sizeof(char) * (READ_SIZE * i) + 1);
	if (tmp == NULL)
		return (NULL);
	while (buff[j] != '\0') {
		tmp[j] = buff[j];
		++j;
	}
	tmp[j] = '\0';
	j = 0;
	buff = malloc(sizeof(char) * (READ_SIZE * i) + 1);
	if (buff == NULL)
		return (NULL);
	while (tmp[j] != '\0') {
		buff[j] = tmp[j];
		++j;
	}
	buff[j] = '\0';
	++i;
	return (buff);
}

char *eject_buff(char *buff)
{
	static int	i = 0;
	int		j = 0;
	int		size = 0;
	char		*tmp = NULL;

	size = i;
	if (buff[i] == '\0')
		return (NULL);
	while (buff[size] != '\n')
		size++;
	tmp = malloc(sizeof(char) * size + 1);
	if (tmp == NULL)
		return (NULL);
	while (buff[i] != '\n')
		tmp[j++] = buff[i++];
	tmp[j]= '\0';
	++i;
	return (tmp);
}

char *get_next_line(int fd)
{
	static char	*buff = NULL;
	int		rv = 0;
	char		*tmp = malloc(sizeof(char) * READ_SIZE + 1);
	int		i = 0;
	int		j = 0;

	if (fd < 0)
		return (NULL);
	buff = init_str(buff, fd);
	while ((rv = read(fd, tmp, READ_SIZE)) != 0) {
		if (rv < 0)
			return (NULL);
		while (j < rv) {
			if (j == (READ_SIZE - 1)) {
				buff[i] = tmp[j];
				buff = realloc_str(buff);
			}
			buff[i++] = tmp[j++];
		}
		if (fd == 0 && tmp[rv-1] == '\n') {
			buff[i-1] = '\0';
			return (buff);
		}
		j = 0;
		my_memset(tmp, '\0', READ_SIZE);
	}
	return (eject_buff(buff));
}
