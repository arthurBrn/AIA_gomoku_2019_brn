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
    run_end(gomoku, str);
    run_turn(gomoku, str);
    if (run_board(str) == 84)
        return (84);
    return (0);
}
