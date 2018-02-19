/*
** EPITECH PROJECT, 2017
** converter.c
** File description:
** Arthur
*/

#include "navy.h"

int mti(char maj)
{
	return (maj - 15 - 48);
}

char itm(int maj)
{
	return (maj + 16 + 48);
}
