/*
** EPITECH PROJECT, 2019
** cmd.c
** File description:
** ..
*/

#include "gomoku.h"

void    run_cmd(int (**tab_cmd)(t_gomoku *, char *))
{
    tab_cmd[0] = run_start;
    tab_cmd[1] = run_begin;
    tab_cmd[2] = run_end;
    tab_cmd[3] = run_turn;
    tab_cmd[4] = run_board;
}
