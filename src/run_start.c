/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "gomoku.h"



int    run_start(t_gomoku *gomoku, char *str)
{
    char   **tab = my_str_to_word_array(str, " ");

    if (tab[1] == NULL)
        return (84);
    if (strcmp("START", tab[0]) == 0) {
        if (gomoku->start == 0 && isnum(tab[1]) != 84) {
            gomoku->size = atoi(tab[1]);
            printf("OK - everything is good\n");
            gomoku->start = 1;
        }
	else
            printf("ERROR message - unsupported size or other error\n");
    }
    return (0);
}
