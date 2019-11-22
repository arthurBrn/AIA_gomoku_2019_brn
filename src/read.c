/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "gomoku.h"

void init_struct(t_gomoku *gomoku) {
    gomoku->start = 0;
    gomoku->player = 0;
    gomoku->end = 0;
    gomoku->size = 20;
}

int check_cmd(char *str, int (*tab_cmd[5])(), t_gomoku *gomoku) {
    char *tab[6] = {"START", "BEGIN", "END", "TURN", "BOARD", '\0'};
    char **newtab = my_str_to_word_array(str, " ");
    int compteur = 0;

    for (int i = 0; tab[i]; i++) {
        if (strcmp(newtab[0], tab[i]) == 0) {
            (newtab[1] == NULL) ? newtab[1] = "" : 0;
            if ((*tab_cmd[i])(gomoku, newtab[1]) == ERROR)
                return (ERROR);
            compteur = 1;
        }
    }
    if (compteur == 0)
        return (1);
    return (0);
}

int readstandard(t_gomoku *gomoku) {
    char *str = NULL;
    ssize_t size;
    int (*tab_cmd[5])(t_gomoku *, char *);
    int return_value = 0;

    run_cmd(tab_cmd);
    while (gomoku->end != 1) {
        if ((str = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
            return (ERROR);
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (ERROR);
        str[size - 1] = '\0';
        return_value = check_cmd(str, tab_cmd, gomoku);
        if (return_value == 1)
            write(2, UNKNOWN, strlen(UNKNOWN));
        if (return_value == ERROR)
            return (ERROR);
        free(str);
    }
    return (0);
}
