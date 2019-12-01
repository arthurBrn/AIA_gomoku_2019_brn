/*
** EPITECH PROJECT, 2019
** turn.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int get_coord_x(char *str)
{
    int i;
    int x = 0;

    for (i = 0; isdigit(str[i]) != 0; i++)  {
	x *= 10;
        x += str[i] - 48;
    }
    return (x);
}

int get_coord_y(char *str)
{
    int i = 0;
    int x = get_coord_x(str);
    int y = 0;

    i = my_intlen(x) + 1;
    for (i = i; isdigit(str[i]) != 0; i++) {
        y *= 10;
        y += str[i] - 48;
    }
    return (y);
}

void init_begin(t_gomoku *gomoku)
{
    if (gomoku->player == 0)
        gomoku->player = 2;
}

int concat_player(t_gomoku *gomoku)
{
    int p = 0;

    if (gomoku->player == 1) {
	    p = 2;
    }
    if (gomoku->player == 2){
        p = 1;
    }
	return (p);
}

int run_turn(t_gomoku *gomoku, char *str)
{
    char *new_str = "";
    int index = strlen(str) + 1;

    if (gomoku->start == 0)
        return (write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED)), MY_EXIT_FAILURE);
    if (check_turn_errors(gomoku, str) != 0)
        return (write(2, ERROR_MSG, strlen(ERROR_MSG)), MY_EXIT_FAILURE);
    init_begin(gomoku);
    new_str = malloc(sizeof(char) * (strlen(str) + 3));
    strcpy(new_str, str);
    strcat(new_str, ",");
    new_str[index] = concat_player(gomoku) + 48;
    new_str[index+1] = '\0';
    if (store_board(new_str, gomoku) == 84)
        return (write(2, ERROR_MSG, strlen(ERROR_MSG)), MY_EXIT_FAILURE);
    free(new_str);    
    check_aligned(gomoku);
    make_move(gomoku);
    print_the_board(gomoku);
    return (0);
}
