/*
** EPITECH PROJECT, 2019
** split_it.c
** File description:
** Split a string
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node_proto.h"

char **split_it(char *str)
{
    int i = 0;
    int j = 0;
    int n = 0;
    char **main_buffer = malloc(sizeof(char *) * 3);

    for (i; i < 3; i++)
        main_buffer[i] = malloc(sizeof(char) * 3);
    i = 0;
    while (i < 3) {
        if (str[n] == '\0')
            i = 3;
        if (str[n] != ',' && i < 3) {
            main_buffer[i][j] = str[n];
            j++;
            n++;
        }
        if (str[n] == ',' && i < 3) {
            j = 0;
            n++;
            i++;
        }
    }
    return (main_buffer);
}

int main()
{
    char *str = "10,10,1";
    char **hold = split_it(str);
    int i = 0;
    int j = 0;

    putchar('\n');
    puts(hold[0]);
    putchar('\n');

    putchar('\n');
    puts(hold[1]);
    putchar('\n');

    putchar('\n');
    puts(hold[2]);
    putchar('\n');

    return (0);
}
