/*
** EPITECH PROJECT, 2019
** run_turn.c
** File description:
** gomoku
*/

#include "gomoku.h"

int run_turn(char *str, t_gomoku *gomoku)
{
  str = strcat(str, ",2");
  if (storing_error(str, gomoku, ",") != 84)
    gomoku->board = store_move(gomoku->board, str, ",");
  else
    return (84);
  print_the_board(gomoku, gomoku->board);
  print_list(gomoku->board);
  return 0;
}
