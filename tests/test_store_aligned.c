/*
** EPITECH PROJECT, 2019
** test_store_aligned.c
** File description:
** Test all function from file store_aligned.c
*/

#include "global.h"
#include <criterion/criterion.h>

Test(initialize_block, test_proper_block_init_size_one)
{
    int player = 1;
    int x = 1;
    int y = 1;

    initialize_block(player, x, y);
    cr_assert_not_null(aligned);
    cr_assert_eq(aligned->start_x, x);
    cr_assert_eq(aligned->start_y, y);
    cr_assert_eq(aligned->player, player);
    cr_assert_eq(aligned->end_x, 0);
    cr_assert_eq(aligned->end_y, 0);
    cr_assert_eq(aligned->len, 0);
    cr_assert_null(aligned->next);
}

Test(initialize_block, test_proper_block_init_size_four)
{
    int player = 1;
    int i = 0;
    int j = 4;
    aligned_t *al = malloc(sizeof(aligned_t));
 
    for (i; i <= 4; i ++)
        initialize_block(player, i, i);    
    cr_assert_not_null(aligned);
    cr_assert_eq(aligned_length(aligned), 5);
    al = aligned;
    for (j; j != 0; j--) {
        cr_assert_eq(aligned->start_x, j);
        cr_assert_eq(aligned->start_y, j);
        cr_assert_eq(aligned->player, player);
        cr_assert_eq(aligned->end_x, 0);
        cr_assert_eq(aligned->end_y, 0);
        cr_assert_eq(aligned->len, 0);
        aligned = aligned->next;
    }
    aligned = al;
}

Test(set_len, test_len_init)
{
    initialize_block(1,1,1);
    cr_assert_eq(aligned->len, 0);
    set_len(5);
    cr_assert_eq(aligned->len, 5);
}

Test(initialize_block, test_block_init_with_set_len)
{
    int player = 1;
    int i = 0;
    int j = 4;
    aligned_t *al = malloc(sizeof(aligned_t));

    for (i; i <= 4; i++) {
        initialize_block(player, i, i);
        set_len(i);
    }
    cr_assert_eq(aligned_length(aligned), 5);
    al = aligned;
    for (j; j != 0; j--) {
        cr_assert_eq(al->start_x, j);
        cr_assert_eq(al->start_y, j);
        cr_assert_eq(al->player, player);
        cr_assert_eq(al->end_x, 0);
        cr_assert_eq(al->end_y, 0);
        cr_assert_eq(al->len, j);
        al = al->next;
    }
}

Test(set_final_x_y, init_block_end_x_end_y_values)
{
    initialize_block(1, 1, 1);
    set_len(4);
    set_final_x_y();
    cr_assert_eq(aligned->end_x, 4);
    cr_assert_eq(aligned->end_y, 1);
    cr_assert_eq(aligned->end_x, ((aligned->start_x + aligned->len) -1 ));
    cr_assert_eq(aligned->end_y, aligned->start_y);
}

Test(set_final_x_y, init_block_end_x_end_y_values_several_times)
{
    initialize_block(1, 1, 1);
    set_len(4);
    set_final_x_y();
    cr_assert_eq(aligned->end_x, 4);
    cr_assert_eq(aligned->end_y, 1);
    cr_assert_eq(aligned->end_x, ((aligned->start_x + aligned->len) -1 ));
    cr_assert_eq(aligned->end_y, aligned->start_y);

    initialize_block(1, 3, 7);
    set_len(3);
    set_final_x_y();
    cr_assert_eq(aligned->end_x, 5);
    cr_assert_eq(aligned->end_y, 7);
    cr_assert_not_null(aligned);
}

Test(aligned_length, test_proper_length_count)
{
    int player = 1;
    int i = 0;
    
    for (i; i <= 4; i++)
        initialize_block(1, i, i);
    cr_assert_not_null(aligned);
    cr_assert_eq(aligned_length(aligned), 5);
}

Test(aligned_length, test_aligned_null)
{
    aligned_t *al = NULL;

    aligned = al;
    cr_assert_null(aligned);
    cr_assert_eq(aligned_length(), 0);
}

Test(aligned_list_free, proper_free_of_aligned_linked_list)
{
    int player = 1;

    for (int i = 0; i <= 4; i++)
        initialize_block(player, i, i);
    cr_assert_eq(aligned_length(), 5);
    cr_assert_not_null(aligned);
    aligned_list_free();
    cr_assert_null(aligned);
}