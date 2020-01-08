/*
** EPITECH PROJECT, 2019
** moves.h
** File description:
** structure declaration for moves
*/

#include <stdbool.h>

#ifndef _NODE_H_
#define _NODE_H_

typedef struct move {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int len;
    bool open1;
    bool open2;
} t_move;

#endif
