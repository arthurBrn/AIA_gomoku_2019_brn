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
        while (save->next != NULL && (save->x + 1 == save->next->x) && (save->y == save->next->y))
        {
            compteur++;
            save = save->next;
        }
        printf("%d\n", compteur);
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
        while (save->next != NULL && (save->x == save->next->x) && (save->y + 1 == save->next->y))
        {
            compteur++;
            save = save->next;
        }
        if (compteur2 < compteur)
            compteur2 = compteur;
        printf("%d\n", compteur2);
        save = save->next;
    }
    return (compteur2);
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
    check_horizontal(gomoku);
    check_vertical(gomoku);
    return 0;
}
