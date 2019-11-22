/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** File for error handling
*/

#include "gomoku.h"

int nbr_coma(char *str)
{
    int i = 0;
    int flag = 0;
    int len = strlen(str);

    if (str[0] == ',' || str[strlen(str + 1)] == ',')
        return (ERROR);
    for (; i < len; i++) {
        if (str[i] == ',')
            flag++;
        if (str[i] == ',' && (str[i + 1] == ',' || str[i - 1] == ','))
            return (ERROR);
    }
    if (flag != 2)
        return (ERROR);
    return (1);
}

int only_digit_str(char *str)
{
    int i = 0;
    int coma = nbr_coma(str);

    if (coma != 1)
        return (ERROR);
    while (str[i] != '\0') {
        if (isdigit(str[i]) || str[i] == ',')
            i++;
        else
            return (ERROR);
    }
    return (1);
}

int check_players(char c)
{
    if (!isdigit(c))
        return (ERROR);
    if (c != '1' && c != '2' && c != '3')
        return (ERROR);
    return (1);
}

int check_coordinate(char *str, t_gomoku *gom)
{
    char **tab = my_str_to_word_array(str, ",");
    int x = 0;
    int y = 0;
    int flag = 1;

    if (only_digit_str(str) == ERROR)
        return (ERROR);
    x = atoi(tab[0]);
    y = atoi(tab[0]);
    if ((x < 0 || x > gom->size) || (y < 0 || y > gom->size))
        return (ERROR);
    return (flag);
}

int check_string(char *str, t_gomoku *gom)
{
    if (nbr_coma(str) == ERROR ||  only_digit_str(str) == ERROR)
        return (ERROR);
    if (check_players(str[strlen(str) - 1]) == ERROR)
        return (ERROR);
    if (check_coordinate(str, gom) == ERROR)
        return (ERROR);
    return (1);
}
