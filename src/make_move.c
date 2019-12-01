/*
** EPITECH PROJECT, 2019
** make_move.c
** File description:
** Used to make a move
*/

#include "global.h"

char *get_coord_to_play(aligned_t *move)
{
    int x = 0;
    int y = 0;
    char *str;

    if (move->open == 1) {
	x = move->start_x - 1;
	y = move->start_y;
    }
    else if (move->open == 2 || move->open == 3) {
	x = move->end_x + 1;
	y = move->end_y;
    }
    str = malloc(sizeof(char) * (my_intlen(x) + my_intlen(y)) + 2);
    str = strcat(str, my_itoa(x));
    str = strcat(str, ",");
    str = strcat(str, my_itoa(y));
    str = strcat(str, "\n");
    return (str);
}

aligned_t *choose_open(aligned_t *best, aligned_t *list)
{
    if (list->open == 0)
	return (best);
    if (best->open == 0)
	return (best);
    if (list->open > best->open)
	return (list);
    else if (list->open < best->open)
	return (best);
    else
	return (list);
}

aligned_t *find_best_combinaison()
{
    aligned_t *list = aligned;
    aligned_t *best = NULL;
    int cpt = 0;

    while (list != NULL) {
	if (list->len > cpt) {
	    cpt = list->len;
	    best = list;
	}
	else if (list->len == cpt) {
	    best = choose_open(best, list);
	}
	list = list->next;
    }
    return best;
}

void make_move(t_gomoku *gomoku)
{
    aligned_t *move = NULL;
    char *str;
    char *new_str;
    int player = 0;
    char *cpy;

    printf("player : %d\n", gomoku->player);
    if (gomoku->player == 1)
	player = 2;
    else
	player = 1;
    move = find_best_combinaison();
    str = get_coord_to_play(move);
    cpy = malloc(sizeof(char) * strlen(str));
    cpy = strcpy(cpy, str);
    str[strlen(str) - 1] = '\0';
    new_str = malloc(sizeof(char) * strlen(str) + 3);
    new_str = strcat(str, ",");
    new_str[strlen(new_str)] = gomoku->player + 48;
    store_board(new_str, gomoku);
    write(1, cpy, strlen(cpy));    
}

