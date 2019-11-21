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

int check_error(t_gomoku *gomoku, char *str)
{
    int size = gomoku->size;
    int comma = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            comma++;
    if (comma >= 2)
        return (84);
    if (get_coord_x(str) > size || get_coord_y(str) > size)
        return (84);
    for (int i = 0; str[i] != '\0'; i++)
        if (!(isdigit(str[i]) != 0 || str[i] == ','))
            return (84);
    if (strlen(str) < 3)
        return (84);
    if (get_coord_x(str) == 0 || get_coord_y(str) == 0)
        return (84);
    return (0);
}

void init_begin(t_gomoku *gomoku)
{
    if (gomoku->player == 0)
        gomoku->player = 2;
}

int run_turn(t_gomoku *gomoku, char *str)
{
    int *tab;

    if (gomoku->start == 0)
        return (puts(GAME_NOT_STARTED));
    if (check_error(gomoku, str) != 84) {
        tab = malloc(sizeof(int) * (strlen(str)));
        init_begin(gomoku);
        tab[0] = get_coord_x(str);
        tab[1] = get_coord_y(str);
        free(tab);
        return (0);
    } else
        return (puts(ERROR_MSG));
    return (2);
}
