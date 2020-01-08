/*
** EPITECH PROJECT, 2019
** run_turn.c
** File description:
** gomoku
*/

#include "gomoku.h"

t_move *check_horizontal(t_gomoku *gomoku, t_move *move) {
    int compteur = 1;
    int start = 0;
    t_board *save = gomoku->board;
    t_board *previous;
    t_move *hold = move;
    t_move *new_node = NULL;

    while (save != NULL) {
        compteur = 1;
<<<<<<< HEAD
        start = 0;
        while ((save->next != NULL && (save->x + 1 == save->next->x) && (save->y == save->next->y) &&
               save->player == save->next->player)) {
            new_node = malloc(sizeof(t_move) + 1);
            start++;
            if (start == 1) {
                if (previous->x == save->x - 1)
                    new_node->open1 = false;
                else
                    new_node->open1 = true;
                new_node->start_y = save->y;
                new_node->start_x = save->x;
            }
=======
        while (save->next != NULL && (save->x + 1 == save->next->x) && (save->y == save->next->y) &&
                save->player == save->next->player) {
>>>>>>> 053d5425b5efbdc1fef9d7682e93fc75142264f7
            compteur++;
            previous = save;
            save = save->next;

<<<<<<< HEAD
        }
        if (start == 1) {
            if (save->x + 1== save->next->x)
                move->open2 = false;
            else
                move->open2 = true;
            move->end_x = save->x;
            move->end_y = save->y;
            move->len = compteur;
            move = move->next;
        }
        previous = save;
        save = save->next;
=======
	printf("[xy] => %d,%d, p : %d -> %d\n", save->x, save->y, save->player, compteur);
	
	save = save->next;
>>>>>>> 053d5425b5efbdc1fef9d7682e93fc75142264f7
    }
    return (move);
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
<<<<<<< HEAD
        printf("[xy] => %d,%d, p : %d -> %d\n", save->x, save->y, save->player, compteur);
        save = save->next;

=======
	printf("[xy] => %d,%d, p : %d -> %d\n", save->x, save->y, save->player, compteur);
	save = save->next;
	
>>>>>>> 053d5425b5efbdc1fef9d7682e93fc75142264f7
    }
    return (compteur);
}

int run_turn(char *str, t_gomoku *gomoku) {
    t_move *move = malloc(sizeof(t_move) + 1);

    str = strcat(str, ",2");
    if (storing_error(str, gomoku, ",") != 84) {
        gomoku->board = store_board(gomoku->board, str, ",");
    } else
        return (84);
    print_the_board(gomoku, gomoku->board);
<<<<<<< HEAD
    sort_board_per_x(gomoku->board, 'h');
    sort_board_per_y(gomoku->board, 'h');
    // printf("===vertical===\n");
    // sort_board_per_x(gomoku->board, 'v');    
    // sort_board_per_y(gomoku->board, 'v');
    //print_list(gomoku->board);
    // printf("===horizontal===\n");
    move = check_horizontal(gomoku, move);
    make_moves(move);
    //    printf("===vertical===\n");
    //check_vertical(gomoku);
=======
    printf("===horizontal===\n");
    sort_board_per_x(gomoku->board, "h");
    sort_board_per_y(gomoku->board, "h");
    printf("===horizontal===\n");
    check_horizontal(gomoku);
    printf("===vertical===\n");
    sort_board_per_x(gomoku->board, "v");    
    sort_board_per_y(gomoku->board, "v");
    print_list(gomoku->board);
    // printf("===horizontal===\n");
    printf("===vertical===\n");
    check_vertical(gomoku);
>>>>>>> 053d5425b5efbdc1fef9d7682e93fc75142264f7
    return 0;
}
