/*
** EPITECH PROJECT, 2019
** turn.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

int get_coord_x(char *str)
{
    int i;
    int x = 0;

    for (i = 0; isdigit(str[i]) != 0; i++)  {
	x *= 10;
        x += str[i] - 48;
    }
    return (x);
}

int get_coord_y(char *str)
{
    int i = 0;
    int x = get_coord_x(str);
    int y = 0;

    i = my_intlen(x) + 1;
    for (i = i; isdigit(str[i]) != 0; i++) {
        y *= 10;
        y += str[i] - 48;
    }
    return (y);
}

void init_begin(t_gomoku *gomoku)
{
    if (gomoku->player == 0)
        gomoku->player = 2;
}

int run_turn(t_gomoku *gomoku, char *str)
{
    int *tab;
    char *new_str;
    int index = strlen(str) + 1;

    if (gomoku->start == 0)
        return (puts(GAME_NOT_STARTED), 84);
    if (check_turn_errors(gomoku, str) != 0)
        return (84);
    tab = malloc(sizeof(int) * (strlen(str)) + 4);
    init_begin(gomoku);
    new_str = malloc(sizeof(char) + 10);
    new_str = strcat(str, ",");
    new_str[index] = gomoku->player + 48;
    tab[0] = get_coord_x(str);
    tab[1] = get_coord_y(str);
    free(new_str);
    free(tab);
    return (0);
}
