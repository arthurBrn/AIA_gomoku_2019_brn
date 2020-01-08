/*
** EPITECH PROJECT, 2019
** moves.c
** File description:
** Contains struct that will store the board
*/

#include "gomoku.h"

char *if_all_open_are_true(char *res) {
    char *x = malloc(sizeof(char) * 2);
    char *y = malloc(sizeof(char) * 2);

    if (save->start_x == save->end_x) {
        x = itoa(save->start_x - 1, x, 2);
        y = itoa(save->start_y, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    } else {
        x = itoa(save->start_x, x, 2);
        y = itoa(save->start_y - 1, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    }
    return (res);
}

char *if_only_second_open_are_true(char *res) {
    char *x = malloc(sizeof(char) * 2);
    char *y = malloc(sizeof(char) * 2);

    if (save->start_x == save->end_x) {
        x = itoa(save->end_x + 1, x, 2);
        y = itoa(save->end_y, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    } else {
        x = itoa(save->end_x, x, 2);
        y = itoa(save->end_y + 1, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    }
    return (res);
}


char *where_play(t_gomoku *gomoku) {
    char *res = malloc(sizeof(char) * 5);

    if ((save->first_open == true && save->second_open == true) ||
        (save->first_open == true && save->second_open == false)) {
        res = if_all_open_are_true(res);
    } else if (save->first_open == false && save->second_open == true) {
        res = if_only_second_open_are_true(res);
    }
    res[strlen(res) + 1] = '\0';
    return (res);
}

void makes_moves(t_gomoku *gomoku) {
    t_board *save = gomoku->board;

    while (save != NULL) {
        if (save->len == 4)
            return (write(1, where_play(), strlen(where_play(gomoku))));
        else if (save->len == 3)
            return (write(1, where_play(), strlen(where_play(gomoku))));
        else if (save->len == 2)
            return (write(1, where_play(), strlen(where_play(gomoku))));
        else if (save->len == 1)
            return (write(1, where_play(), strlen(where_play(gomoku))));
        save = save->next;
    }
}