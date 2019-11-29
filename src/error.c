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
        return (MY_EXIT_FAILURE);
    for (; i < len; i++) {
        if (str[i] == ',')
            flag++;
        if (str[i] == ',' && (str[i + 1] == ',' || str[i - 1] == ','))
            return (MY_EXIT_FAILURE);
    }
    if (flag != 2)
        return (MY_EXIT_FAILURE);
    return (1);
}

int only_digit_str(char *str)
{
    int i = 0;
    int coma = nbr_coma(str);

    if (coma != 1)
        return (MY_EXIT_FAILURE);
    while (str[i] != '\0') {
        if (isdigit(str[i]) || str[i] == ',')
            i++;
        else
            return (MY_EXIT_FAILURE);
    }
    return (1);
}

int check_players(char c)
{
    if (!isdigit(c))
        return (MY_EXIT_FAILURE);
    if (c != '1' && c != '2' && c != '3')
        return (MY_EXIT_FAILURE);
    return (1);
}

int check_coordinate(char *str, t_gomoku *gom)
{
    char **tab = my_str_to_word_array(str, ",");
    int x = 0;
    int y = 0;
    int flag = 1;

    if (only_digit_str(str) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    x = atoi(tab[0]);
    y = atoi(tab[1]);
    if (x <= 0 || x > gom->size)
        return (MY_EXIT_FAILURE);
    if (y <= 0 || y > gom->size)
        return (MY_EXIT_FAILURE);
    return (flag);
}

int check_string(char *str, t_gomoku *gom)
{
    if (nbr_coma(str) == MY_EXIT_FAILURE ||  only_digit_str(str) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    if (check_players(str[strlen(str) - 1]) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    if (check_coordinate(str, gom) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    return (1);
}
