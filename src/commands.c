/*
** EPITECH PROJECT, 2019
** cmd.c
** File description:
** ..
*/

#include "gomoku.h"

void    run_cmd(int (**tab_cmd)(char *, t_gomoku *))
{
    tab_cmd[0] = run_start;
    tab_cmd[1] = run_end;
    tab_cmd[2] = run_begin;
}

