/*
** EPITECH PROJECT, 2019
** cmd.c
** File description:
** ..
*/

#include "gomoku.h"

int    run_cmd(t_gomoku *gomoku, char *str)
{
    run_start(gomoku, str);
    run_begin(gomoku, str);
    run_end(gomoku, str);
    run_turn(gomoku, str);
    run_board(gomoku, str);
    return (0);
}
