/*
** EPITECH PROJECT, 2019
** board.h
** File description:
** Contains struct that will store the board
*/

#ifndef _BOARD_H_
#define _BOARD_H_

typedef struct board {
    int x;
    int y;
    int player;
    struct board *next;
} t_board;

#endif
