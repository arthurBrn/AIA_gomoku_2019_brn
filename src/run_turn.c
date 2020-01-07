/*
** EPITECH PROJECT, 2019
** run_turn.c
** File description:
** gomoku
*/

#include "gomoku.h"
/*
void check_horizontal(t_gomoku *gomoku)
{
  int i = 0;
  int j = 0;

  for (j =j; j < gomoku->size; j++) {
    for (i = i; i < gomoku->size; i++) {
      check_one(i, j, gomoku);
    }
    i = 0;
  }
}

void find_next(t_gomoku *gomoku, t_board *board)
{
  t_board *search = gomoku->board;

  while (search != NULL) {
    if (search->y == board->y && search->x == board->x + 1)
      printf("xy : %d,%d\n", board->x, board->y);
    search = search->next;
  }
}
*/

int is_consecutive(t_board *search, t_board *board, int i)
{
  printf("[SEARCH] xy : %d,%d\n", search->x, search->y);
  printf("[BOARD] xy : %d,%d\n", board->x + i, board->y);
  if (board->x + i + 1 == search->x && board->y == search->y && board->player == search->player) {
    printf("find\n");
    return 1;
  }
  else
    return 0;
  
}

int count_consecutives_token(t_gomoku *gomoku, t_board *board)
{
  int found = 1;
  int nb = 0;
  int i = 0;
  t_board *search = gomoku->board;

  for (i = i; i < 5 && board->x + i <= gomoku->size && found != 0; i++) {
    //printf ("=== %d,%d ===\n", board->x, board->y);
    found = 0;
    while (search != NULL) {
      found += is_consecutive(search, board, i);
      search = search->next;
    }
    printf("found : %d\n", found);
  }
  nb = (i - 1);
  //printf("nb : %d\n", nb);
}

void find_token(t_gomoku *gomoku)
{
  t_board *board = gomoku->board;
  t_board *save = gomoku->board;

  while (board != NULL) {
    printf ("=== %d,%d ===\n", board->x, board->y);
    count_consecutives_token(gomoku, board);
    board = board->next;
  }  
}

int run_turn(char *str, t_gomoku *gomoku)
{
  str = strcat(str, ",2");
  if (storing_error(str, gomoku, ",") != 84)
    gomoku->board = store_move(gomoku->board, str, ",");
  else
    return (84);
  print_the_board(gomoku, gomoku->board);
  //  check_horizontal(gomoku);
  find_token(gomoku);
  return 0;
}
