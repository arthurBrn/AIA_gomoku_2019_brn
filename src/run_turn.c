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
  if (storing_error(str, gomoku, ",") == 84)
    return (84);
  if (store_move(gomoku->board, str, ",") == 84)
    return (84);
  else
    gomoku->board = store_move(gomoku->board, str, ",");
  print_the_board(gomoku, gomoku->board);
  print_list(gomoku->board);
  return 0;
}
