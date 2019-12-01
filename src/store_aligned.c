/*
** EPITECH PROJECT, 2019
** store_aligned.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"


void initialize_block(int player, int initial_x, int initial_y)
{
    aligned_t *al = malloc(sizeof(aligned_t));

    al->start_x = initial_x;
    al->start_y = initial_y;
    al->player = player;
    al->end_x = 0;
    al->end_y = 0;
    al->len = 0;
    if (aligned == NULL)
        al->next = NULL;
    else
        al->next = aligned;
    aligned = al;
}

void set_len(int length)
{
    aligned->len = length;
}

void set_final_x_y()
{
    if (aligned->len == 1)
        aligned->end_x = aligned->start_x;
    else 
        aligned->end_x = ((aligned->start_x + aligned->len) - 1);
    aligned->end_y = aligned->start_y;
}

/*
void set_open(t_gomoku *gom)
{
    int left = 1;
    int right = 2;
    if (aligned->start_x == 1)
        left = 0;
    if (aligned->start_x)
    if (aligned->end_x == gom->size)
        right = 0;
    

}
*/

int aligned_length()
{
    aligned_t *al = aligned;
    int count = 0;

    if (al == NULL)
        return (0);
    while (al != NULL) {
        count++;
        al = al->next;
    }
    return (count);
}

void aligned_list_free()
{
    aligned_t *current = NULL;

    while (aligned != NULL) {
        current = aligned;
        aligned = aligned->next;
        free(current);
    }
    aligned = NULL;
}

void print_aligned()
{
    aligned_t *al = aligned;
    if (al == NULL)
        write(1, "nothing to print", 16);
    else {
        while (al != NULL) {
            write(1, "==========", 10);
            putchar('\n');
            printf("al->start_x : %d\n", al->start_x);
            printf("al->start_y : %d\n", al->start_y);
            printf("al->end_x : %d\n", al->end_x);
            printf("al->end_y : %d\n", al->end_y);
            printf("al->len : %d\n", al->len);
            printf("al->player : %d\n", al->player);
            al = al->next;
        }
    }
}

// Define open or not
/**
 * Define if we can play before or after that combinaison, or not at all
 * void open_or_not()
 * {
 *  // Go through the aligned list
 *  // use initial_x of first item of aligned list
 *  // Go through board_list
 *  // Find the coordonate x,y matching initial_x initial_y
 *  // Check in the list if there is something before or after
 *  // If both set the current node of aligned list to 3
 *  // If left only set to 1
 *  // If right only set to 2
 *  // else set to 0
 *  // Do the same with next item
 * }
 * */
