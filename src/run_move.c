/*
** EPITECH PROJECT, 2020
** run_move.c
** File description:
** make move
*/

#include "gomoku.h"
#include "board.h"
#include "move.h"

/*
t_move *init_move_struct() {
    t_move *initialiazed = malloc(sizeof(t_move));
    initialiazed->x = -1;
    initialiazed->y = -1;
    initialiazed->value_pattern_found = -1;
    return (initialiazed);
}
*/
void play(t_gomoku *gomoku) {

    t_board *board_holder = gomoku->board;
    char *str = malloc(sizeof(char) * 5);
    char *x;
    char *y;

    while (board_holder != NULL) {
        if (board_holder->player == 2) {


        }
        board_holder = board_holder->next;
    }

}
/*
t_move *best_line(t_gomoku *gomoku) {
    t_move *move = init_move_struct();

    // move = horizontal_search(gom, move);
    // move = vertical_search(gom, board, move);
    // move = right_diagonal_search(gom, board, move);
    // move = left_diagonal_search(gom, board, move);

    // if (move->value_pattern_found == 10000000)
    // print_winner(gomoku);
    // else {
    //play(board, move);
    //}
}*/