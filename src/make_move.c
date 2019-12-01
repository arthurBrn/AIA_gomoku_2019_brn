
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
    char *s1 = malloc(sizeof(char) * 2);
    char *s2 = malloc(sizeof(char) * 2);
    node_t *all = head;
    
    printf("move-open = %d\n", move->open);
    if (move->open == 1) {
	x = move->start_x - 1;
	y = move->start_y;
    }
    else if (move->open == 2 || move->open == 3) {
        printf("%d\n", move->end_x);
	x = move->end_x + 1;
	y = move->end_y;
    }
    while (all != NULL) {
        if (all->x == x && all->y == y) {
            y++;
            x++;
        }
        all = all->next;
    }
    s1 = itoa(x, s1, 2);
    s1 = check_zero(s1);
    s2 = itoa(y, s2, 2);
    s2 = check_zero(s2);
    str = malloc(sizeof(char) * (strlen(s1) * strlen(s2)) + 2);
    str = strcat(str, s1);
    str = strcat(str, ",");
    str = strcat(str, s2);
    str[strlen(str)] = '\0';
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
    aligned_t *best = malloc(sizeof(aligned_t));
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

/*aligned_t *try_it()
{

}*/

void make_move(t_gomoku *gomoku)
{
    aligned_t *move = NULL;
    char *str;
    char *new_str;
    char *cpy;

    move = find_best_combinaison();
    str = get_coord_to_play(move);
    cpy = malloc(sizeof(char) * strlen(str));
    cpy = strcpy(cpy, str);
    new_str = malloc(sizeof(char) * strlen(str) + 3);
    new_str = strcat(str, ",");
    new_str[strlen(new_str)] = gomoku->player + 48;
    store_board(new_str, gomoku);
    cpy = strcat(cpy, "\n");
    write(1, cpy, strlen(cpy));
}

