/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** File for error handling
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"
#include "node_proto.h"

int nbr_coma(char *str)
{
    int j = 0;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ',')
            j++;
    if (j != 2)
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
    if (str[strlen(str)] != "1" || str[strlen(str)] != "2")
        return (84);
    return (1);
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
