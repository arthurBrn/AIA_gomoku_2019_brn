/*
** EPITECH PROJECT, 2019
** run_turn.c
** File description:
** gomoku
*/

#include "gomoku.h"

int run_turn(char *str, t_gomoku *gomoku)
{ 
  str = concat_player(str);
  storing_error(str, gomoku, ',');
  return 0;
}
