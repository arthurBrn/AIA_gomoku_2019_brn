/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** File for error handling
*/

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"
#include "node_proto.h"

int nbr_coma(char *str)
{
    int i = 0;
    int j = 0;
    int flag = 0;

    while (i < strlen(str)) {
        if (str[i] == ',')
            j++;
        if (str[i] == ',' && (str[i + 1] == ',' || str[i - 1] == ','))
            flag = 1;
        i++;
    }
    if (j != 2 || flag != 0)
        return (84);
    return (1);
}

int valid_str(char *str)
{
    int i = 0;
    int coma = nbr_coma(str);

    if (coma != 1)
        return (84);
    while (str[i] != '\0')
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',')
            i++;
        else
            return (84);
    return (1);
}

int check_players(char *str)
{
    int last_char = strlen(str) - 1;

    if (str[last_char] != '1' && str[last_char] != '2')
        return (84);
    return (1);
}

int check_coordinate(char **array)
{
    int x = atoi(array[0]);
    int y = atoi(array[1]);
    int flag = 0;

    if ((x >= 0 && x <= 20) && (y >= 0 && y <= 20))
        flag = 1;
    else
        flag = 84;
    return (flag);
}

void invalid_string(void)
{
    puts(ERROR_MSG);
    exit(EXIT_USAGE);
}

int check_string(char *str)
{
    if (nbr_coma(str) == 84)
        invalid_string();
    if (valid_str(str) == 84)
        invalid_string();
    if (check_players(str) == 84)
        invalid_string();
    return (1);
}
