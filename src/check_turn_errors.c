/*
** EPITECH PROJECT, 2019
** turn.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

void only_numbers(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(isdigit(str[i]) != 0 || str[i] == ',')) {
	    write (2,ERROR_MSG, strlen(ERROR_MSG));
            exit(ERROR);
	}
}

void len_str(char *str)
{
    if (get_coord_x(str) == 0 || get_coord_y(str) == 0) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
	exit(ERROR);
    }
}

void xy_invalid(t_gomoku *gomoku, char *str)
{
    int size = gomoku->size;

    if (get_coord_x(str) > size || get_coord_y(str) > size) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
        exit(ERROR);
    }
    if (get_coord_x(str) == 0 || get_coord_y(str) == 0) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
        exit(ERROR);
    }
}

void count_comma(char *str)
{
    int comma = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            comma++;
    if (comma >= 2) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
        exit(ERROR);
    }
}

void check_turn_errors(t_gomoku *gomoku, char *str)
{
    count_comma(str);
    xy_invalid(gomoku, str);
    len_str(str);
    only_numbers(str);
}
