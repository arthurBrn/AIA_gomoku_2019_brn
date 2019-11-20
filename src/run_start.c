/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "gomoku.h"

int run_start(t_gomoku *gomoku, char *str)
{
    char **tab = my_str_to_word_array(str, " ");

    if (strcmp("START", tab[0]) == 0) {
        if (tab[1] == NULL)
            return (puts("ERROR message - unsupported size or other error"), 84);
        if (gomoku->start == 0 && isnum(tab[1]) != 84) {
            gomoku->size = atoi(tab[1]);
	    if (gomoku->size == 0)
                return (puts("ERROR message - unsupported size or other error"), 84);
	    puts("OK - everything is good");
            gomoku->start = 1;
            return (0);
        }
        else
            return (puts("ERROR message - unsupported size or other error"), 1);
    }
    return (2);
}
