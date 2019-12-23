/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** run_board.c
*/

#include "gomoku.h"
#include "board.h"

int error_board(t_gomoku *gomoku, t_board *board)
{
    // 
    return (0);
}

int store_move(t_gomoku *gomoku, t_board *board, char *coord)
{
    // We would already have made all the string verification

    // call sort_board here
    return (0);
}

/*
t_board *sort_board(t_board *board, int x, int y)
{
    t_board *keep_the_head = board;
    t_board *board_holder = NULL;

    while (board != NULL) {
        if (y > board->y)
            board = board->next;
        if (y == board->y || y < board->y)
            
    }
}*/

int run_board(t_gomoku *gomoku, t_board *board)
{
    char *board_line = NULL;
    int cpt = 0;
    size_t size = 0;
    char *coordonate = "";

    //while (strcmp(coordonate, "DONE") != 0) {
    while (cpt != 1) {
        getline(&board_line, &size, stdin);
        coordonate = board_line;
        if (strcmp(coordonate, "DONE") == 0)
            cpt = 1;
        printf("%d", cpt);
        printf("%s", coordonate);
    }

    return (0);
}

/*int main()
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    t_board *board = malloc(sizeof(t_board));

    gom->size=20;
    gom->start=1;
    run_board(gom, board);
}*/