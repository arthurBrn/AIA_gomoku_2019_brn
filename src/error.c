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
    int j = 0;

    if (str[0] == ',' || str[strlen(str + 1)] == ',')
        return (84);
    while (i < strlen(str)) {
        if (str[i] == ',')
            j++;
        if (str[i] == ',' && (str[i + 1] == ',' || str[i - 1] == ','))
            return (84);
        i++;
    }
    if (j != 2)
        return (84);
    return (1);
}

int only_digit_str(char *str)
{
    int i = 0;
    int coma = nbr_coma(str);

    if (coma != 1)
        return (84);
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',')
            i++;
        else
            return (84);
    }
    return (1);
}

int check_players(char *str)
{
    int last_char = strlen(str) - 1;

    if (str[last_char] != '1' && str[last_char] != '2')
        return (84);
    return (1);
}

int check_coordinate(char *str)
{
    char **tab = my_str_to_word_array(str, ",");
    int x = atoi(tab[0]);
    int y = atoi(tab[1]);
    int flag = 1;

    if ((x < 0 || x > 20) || (y < 0 || y > 20))
        flag = 84;
    return (flag);
}

int check_string(char *str)
{
    if (nbr_coma(str) == 84 || only_digit_str(str) == 84)
        invalid_string();
    if (check_players(str) == 84)
        invalid_string();
    if (check_coordinate(str) == 84)
        invalid_string();

    return (1);
}
