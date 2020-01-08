/*
** EPITECH PROJECT, 2019
** run_turn.c
** File description:
** gomoku
*/

#include "gomoku.h"

int check_horizontal(t_gomoku *gomoku)
{
    int compteur = 1;
    t_board *save = gomoku->board;

    while (save != NULL)
    {
        compteur = 1;
        while (save->next != NULL && (save->x + 1 == save->next->x) && (save->y == save->next->y) && save->player == save->next->player)
        {
            compteur++;
            save = save->next;
        }
        printf("[xy] => %d,%d, p : %d -> %d\n", save->x, save->y, save->player, compteur);
        save = save->next;
    }
    return (compteur);
}
int check_vertical(t_gomoku *gomoku)
{
    int compteur = 1;
    int compteur2 = 0;
    t_board *save = gomoku->board;

    while (save != NULL)
    {
        compteur = 1;
        while (save->next != NULL && (save->x == save->next->x) && (save->y + 1 == save->next->y) && save->player == save->next->player)
        {
            compteur++;
            save = save->next;
        }
        printf("[xy] => %d,%d, p : %d -> %d\n", save->x, save->y, save->player, compteur);
        save = save->next;
    }
    return (compteur);
}

int run_turn(char *str, t_gomoku *gomoku)
{
    str = strcat(str, ",2");
    if (storing_error(str, gomoku, ",") != 84)
    {
        gomoku->board = store_move(gomoku->board, str, ",");
    }
    else
        return (84);
    print_the_board(gomoku, gomoku->board);
    sort_board_per_x(gomoku->board);
    sort_board_per_y(gomoku->board);
    print_list(gomoku->board);
    // printf("===horizontal===\n");
    printf("===horizontal===\n");
    check_horizontal(gomoku);
    printf("===vertical===\n");
    check_vertical(gomoku);
    return 0;
}
