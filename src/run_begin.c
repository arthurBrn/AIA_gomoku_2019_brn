/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** gomoku
*/

#include "gomoku.h"
#include "board.h"

int error_begin(t_gomoku *gomoku)
{
    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (gomoku->begin == 1)
        return (MY_EXIT_FAILURE);
    return (0);
}

int store_begin_move(t_gomoku *gomoku, char *xy)
{
    char *move_coordonate = malloc(sizeof(char) * 5);

    move_coordonate[0] = *xy;
    move_coordonate[1] = ',';
    move_coordonate[2] = *xy;
    move_coordonate[3] = ',';
    move_coordonate[4] = (gomoku->player + '0');
    move_coordonate[5] = '\0';
    //printf("%s", move_coordonate);
    printf("%d", gomoku->start);
    if (storing_error(move_coordonate, gomoku, ",") == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    if (error_board(gomoku, "") == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    gomoku->board = store_move(gomoku->board, move_coordonate, ",");
    return (0);
}

int run_begin(char *str, t_gomoku *gomoku)
{
    (void) str;
    char *play;
    char *new_play;

    if (error_begin(gomoku) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    else {
        gomoku->begin = 1;
        play = malloc(sizeof(char) * 4);
        play = itoa(gomoku->size / 2, play, 2);
	    new_play = delete_zero(play);
        write(1, new_play, strlen(new_play));
        write(1, ",", 1);
        write(1, new_play, strlen(new_play));
        write(1, "\n", 1);
        if (store_begin_move(gomoku, new_play) == MY_EXIT_FAILURE)
            return (MY_EXIT_FAILURE);
        return (0);
    }
}
