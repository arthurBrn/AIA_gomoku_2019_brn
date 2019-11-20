/*
** EPITECH PROJECT, 2019
** turn.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

int get_nb_1(char *str)
{
    int i;
    int nb = 0;

    for (i = 5; isdigit(str[i]) != 0; i++) {
        nb *= 10;
        nb += str[i] - 48;
    }
    return (nb);
}

int get_nb_2(char *str)
{
    int i = 5;
    int nb_1 = get_nb_1(str);
    int nb_2 = 0;

    i += my_intlen(nb_1) + 1;
    for (i = i; isdigit(str[i]) != 0; i++) {
        nb_2 *= 10;
        nb_2 += str[i] - 48;
    }
    return (nb_2);
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
    if (get_nb_1(str) > size || get_nb_2(str) > size)
        return (84);
    for (int i = 5; str[i] != '\0'; i++)
        if (!(isdigit(str[i]) != 0 || str[i] == ','))
            return (84);
    if (strlen(str) <= 5)
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

    if (strncmp("TURN", str, 4) == 0) {
        if (gomoku->start == 0)
            return (puts("ERROR: The game didn't start."), 0);
        if (check_error(gomoku, str) != 84) {
            tab = malloc(sizeof(int) * (strlen(str) - 5));
            init_begin(gomoku);
            tab[0] = get_nb_1(str);
            tab[1] = get_nb_2(str);
            free(tab);
            return (0);
        } else
            return (puts("ERROR message - unsupported size or other error"), 1);
    }
    return (2);
}
