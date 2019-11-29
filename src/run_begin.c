/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

char *check_zero(char *str) {
    int i = 0;
    char *save = malloc(sizeof(char) * strlen(str));

    if (str[0] == '0')
        while (str[i] == '0')
            i++;
    for (int y = 0;str[i]; y++)
        save[y] = str[i++];
    return (save);
}

char *itoa(int nb, char *str, int size) {
    str[size] = '\0';
    while (size--) {
        str[size] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (str);
}


int begin_ia(t_gomoku *gomoku, char *str) {
    (void) str;
    int middle = gomoku->size / 2;
    char *s1 = malloc(sizeof(char) * 2);

    s1 = itoa(middle, s1, 2);
    s1 = check_zero(s1);
    write(1, s1, strlen(s1));
    write(1, ",", 1);
    write(1, s1, strlen(s1));
    write(1, "\n", 1);
    return (0);
}

int run_begin(t_gomoku *gomoku, char *str) {
    if (gomoku->player == 1) {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (strcmp(str, "") != 0) {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    gomoku->player = 1;
    begin_ia(gomoku, str);
    return (0);
}
