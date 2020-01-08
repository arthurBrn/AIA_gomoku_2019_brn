/*
** EPITECH PROJECT, 2019
** moves.c
** File description:
** Contains struct that will store the board
*/

#include "gomoku.h"

void free_move_list(t_move *move)
{
    t_move *current = NULL;
    t_move *next = NULL;
    t_move *head_holder = move;

    while (move != NULL)
    {
        current = move;
        next = move->next;
        move = next;
        free(current);
    }
    free(next);
    free(head_holder);
    move = NULL;
}

t_move *init_move_struct() {
    t_move *head = malloc(sizeof(t_move));
    head->start_x = -1;
    head->start_y = -1;
    head->end_x = -1;
    head->end_y = -1;
    head->len = -1;
    head->open1 = 0;
    head->open2 = 0;
    head->next = NULL;
    
    return (head);
}

char *if_all_open_are_true(char *res, t_move *move) {
    char *x = malloc(sizeof(char) * 2);
    char *y = malloc(sizeof(char) * 2);

    if (move->start_x == move->end_x) {
        x = itoa(move->start_x - 1, x, 2);
        y = itoa(move->start_y, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    } else {
        x = itoa(move->start_x, x, 2);
        y = itoa(move->start_y - 1, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    }
    return (res);
}

char *if_only_second_open_are_true(char *res, t_move *move) {
    char *x = malloc(sizeof(char) * 2);
    char *y = malloc(sizeof(char) * 2);

    if (move->start_x == move->end_x) {
        x = itoa(move->end_x + 1, x, 2);
        y = itoa(move->end_y, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    } else {
        x = itoa(move->end_x, x, 2);
        y = itoa(move->end_y + 1, y, 2);
        strcat(res, x);
        strcat(res, ",");
        strcat(res, y);
    }
    return (res);
}


char *where_play(t_move *move) {
    char *res = malloc(sizeof(char) * 5);

    if ((move->open1 == true && move->open2 == true) ||
        (move->open1 == true && move->open2 == false)) {
        res = if_all_open_are_true(res, move);
    } else if (move->open1 == false && move->open2 == true) {
        res = if_only_second_open_are_true(res, move);
    }
    res[strlen(res) + 1] = '\0';
    return (res);
}

void make_moves(t_move *move) {
    t_move *save = move;

    while (save != NULL) {
        if (save->len == 4) {
            write(1, where_play(move), strlen(where_play(move)));
            break;
        } else if (save->len == 3) {
            write(1, where_play(move), strlen(where_play(move)));
            break;
        } else if (save->len == 2) {
            write(1, where_play(move), strlen(where_play(move)));
            break;
        } else if (save->len == 1) {
            write(1, where_play(move), strlen(where_play(move)));
            break;
        }
        save = save->next;
    }
}