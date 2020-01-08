/*
** EPITECH PROJECT, 2019
** run_turn.c
** File description:
** gomoku
*/

#include "gomoku.h"

void check_horizontal(t_gomoku *gomoku) {
    int compteur = 1;
    int start = 0;
    t_move *prev_move = NULL;
    t_move *new_node = init_move_struct();
    t_board *save = gomoku->board;
    t_board *previous = NULL;
    
    while (save != NULL) {
        compteur = 1;
        start = 0;
        while ((save->next != NULL && (save->x + 1 == save->next->x) && (save->y == save->next->y) &&
                save->player == save->next->player)) {

            if (prev_move != NULL) {
                new_node = malloc(sizeof(t_move));
                new_node->next = prev_move;
            }
            start++;
            if (start == 1) {
                if (previous->x == save->x - 1)
                    new_node->open1 = false;
                else
                    new_node->open1 = true;
                new_node->start_y = save->y;
                new_node->start_x = save->x;
            }
            prev_move = new_node;       
            save = save->next;
        }
        if (start == 1) {
            if (save->x + 1 == save->next->x)
                new_node->open2 = false;
            else
                new_node->open2 = true;
            new_node->end_x = save->x;
            new_node->end_y = save->y;
            new_node->len = compteur;
            new_node = new_node->next;
        }
        previous = save;
        save = save->next;
    }
}

int check_vertical(t_gomoku *gomoku) {
    int compteur = 1;
    t_board *save = gomoku->board;

    while (save != NULL) {
        compteur = 1;
        while (save->next != NULL && (save->x == save->next->x) && (save->y + 1 == save->next->y) &&
                save->player == save->next->player) {
            compteur++;
            save = save->next;
        }
	save = save->next;
	
    }
    return (compteur);
}

int run_turn(char *str, t_gomoku *gomoku) {
    str = strcat(str, ",2");
    if (storing_error(str, gomoku, ",") != 84) {
        gomoku->board = store_board(gomoku->board, str, ",");
    } else
        return (84);
    sort_board_per_x(gomoku->board, "h");
    sort_board_per_y(gomoku->board, "h");
    check_horizontal(gomoku);
    return 0;
}
