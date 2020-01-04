/*
** EPITECH PROJECT, 2020
** run_move.c
** File description:
** make move
*/

#include "gomoku.h"
#include "board.h"
#include "move.h"

t_move *init_move_struct()
{
    t_move *initialiazed = malloc(sizeof(t_move));
    initialiazed->x = -1;
    initialiazed->y = -1;
    initialiazed->value_pattern_found = -1;
    return (initialiazed);
}

t_move *best_line(t_gomoku *gomoku, t_board *board)
{
    t_move *move = init_move_struct();

    // move = horizontal_search(t_gomoku *gom, t_board *board, )
}