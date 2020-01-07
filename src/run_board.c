/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** run_board.c
*/

#include "gomoku.h"
#include "board.h"

// void sort(t_board *board)
// {
//     t_board *holder = board;
//     t_board *swap = board;
//     t_board *next = NULL;
//     printf("%d", list_length(holder));

//     while (holder != NULL) {
//         next = holder->next;
//         print_node(board);
//         if (holder->x > next->x) {
//             swap = holder;
//             holder->next = next->next;
//             next->next = holder;
//             holder = next;
//             next = swap;
//         }
//         holder = holder->next;
//     }
// }

int storing_error(char *coordonate, t_gomoku *gom, char *delim)
{
    t_board *board_holder = gom->board;
    char **split_coordonate;
    int x = 0;
    int y = 0;

    if (check_string(coordonate, gom) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    split_coordonate = my_str_to_word_array(coordonate, delim);
    x = atoi(split_coordonate[0]);
    y = atoi(split_coordonate[1]);
    while (gom->board != NULL)
    {
        if (gom->board->x == x && gom->board->y == y)
            return (MY_EXIT_FAILURE);
        gom->board = gom->board->next;
    }
    gom->board = board_holder;
    return (0);
}

int error_board(t_gomoku *gomoku, char *s1)
{
    if (gomoku->start == 0 || gomoku->board == NULL)
        return (write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED)), MY_EXIT_FAILURE);
    if (strcmp(s1, "") != 0)
        return (write(2, ERROR_MSG, strlen(ERROR_MSG)), MY_EXIT_FAILURE);
    return (0);
}

void set_node(t_board *board, char *coordonate, char *delim)
{
    char **split_coordonate = my_str_to_word_array(coordonate, delim);

    board->x = atoi(split_coordonate[0]);
    board->y = atoi(split_coordonate[1]);
    board->player = atoi(split_coordonate[2]);
}

t_board *store_move(t_board *board, char *coordonate, char *delim)
{
    t_board *new_node = NULL;

    printf("%s", "store move");
    if (board->next == NULL && board->x == -1)
    {
        set_node(board, coordonate, delim);
        print_node(board);
        return (board);
    }
    else
    {
        new_node = malloc(sizeof(t_board));
        set_node(new_node, coordonate, delim);
        new_node->next = board;
    }
    print_node(new_node);
    return (new_node);
}

int run_board(char *s1, t_gomoku *gomoku)
{
    ssize_t size = 0;
    char *coordonate = "";

    if (error_board(gomoku, s1) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    while (strcmp(coordonate, "DONE") != 0)
    {
        if ((coordonate = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
            return (MY_EXIT_FAILURE);
        if ((size = read(0, coordonate, BUFF_SIZE)) < 0)
            return (MY_EXIT_FAILURE);
        coordonate[size - 1] = '\0';
        if (storing_error(coordonate, gomoku, ",") != 84)
        {
            gomoku->board = store_move(gomoku->board, coordonate, ",");
            print_list(gomoku->board);
            print_the_board(gomoku, gomoku->board);
        }
        else
            return (write(1, ERROR_SIZE, strlen(ERROR_SIZE)), MY_EXIT_FAILURE);
        free(coordonate);
    }
    return (0);
}