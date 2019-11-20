/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "gomoku.h"

void    init_struct(t_gomoku *gomoku)
{
    gomoku->start = 0;
    gomoku->player  = 0;
    gomoku->end = 0;
    gomoku->size = 20;
}

int check_cmd(char  *s1, char *str, int (*tab_cmd[5])(), t_gomoku *gomoku)
{
    char *tab[6] = {"START", "BEGIN", "END", "TURN", "BOARD", '\0'};
    int i = 0;
    
    while (tab[i]) {
        if (strcmp(s1, tab[i]) == 0) {
            (*tab_cmd[i])(gomoku, str);
            return (0);
        }
        i++;
    }
    return (1);
}

int readstandard(t_gomoku * gomoku)
{
    char    *str = NULL;
    ssize_t size;
    int (*tab_cmd[5])(t_gomoku *, char *);
    char    **tab;
    
    run_cmd(tab_cmd);
    while (gomoku->end != 1) {
        str = malloc(sizeof(char) * BUFF_SIZE);
        puts("The manager sends:");
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (84);
        str[size - 1] = '\0';
        tab = my_str_to_word_array(str, " ");
        if (check_cmd(tab[0], str, tab_cmd, gomoku) == 1)
            puts("Invalid command");
        free(str);
    }
    return (0);
}
