/*
** EPITECH PROJECT, 2019
** turn.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

int only_numbers(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(isdigit(str[i]) != 0 || str[i] == ',')) {
	    write (2,ERROR_MSG, strlen(ERROR_MSG));
            return (ERROR);
	}
    return (0);
}

int len_str(char *str)
{
    if (get_coord_x(str) == 0 || get_coord_y(str) == 0) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
	return (ERROR);
    }
    return (0);
}

int xy_invalid(t_gomoku *gomoku, char *str)
{
    int size = gomoku->size;

    if (get_coord_x(str) > size || get_coord_y(str) > size) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
        return (ERROR);
    }
    if (get_coord_x(str) == 0 || get_coord_y(str) == 0) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
        return (ERROR);
    }
    return (0);
}

int count_comma(char *str)
{
    int comma = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            comma++;
    if (comma >= 2) {
	write (2,ERROR_MSG, strlen(ERROR_MSG));
        return (ERROR);
    }
    return (0);
}

int check_turn_errors(t_gomoku *gomoku, char *str)
{
    if (count_comma(str) == 84)
        return (ERROR);
    if (xy_invalid(gomoku, str) == 84)
        return (ERROR);
    if (len_str(str) == 84 || only_numbers(str) == 84)
        return (ERROR);
    return (0);
}
