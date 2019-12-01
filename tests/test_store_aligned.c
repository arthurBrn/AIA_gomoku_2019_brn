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
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    gom->size = 20;
    initialize_block(1,1,1);
    cr_assert_eq(aligned->len, 0);
    set_len_horizontal(5, gom);
    cr_assert_eq(aligned->len, 5);
}

Test(initialize_block, test_block_init_with_set_len)
{
    int player = 1;
    int i = 0;
    int j = 4;
    aligned_t *al = malloc(sizeof(aligned_t));
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    gom->size = 20;
    for (i; i <= 4; i++) {
        initialize_block(player, i, i);
        set_len_horizontal(i, gom);
    }
    cr_assert_eq(aligned_length(aligned), 5);
    al = aligned;
    for (j; j != 0; j--) {
        cr_assert_eq(al->start_x, j);
        cr_assert_eq(al->start_y, j);
        cr_assert_eq(al->player, player);
        if (al->start_x == 1)
            cr_assert_eq(al->end_x, al->start_x);
        else
            cr_assert_eq(al->end_x, ((al->start_x + al->len) - 1));
        cr_assert_eq(al->end_y, al->start_y);
        cr_assert_eq(al->len, j);
        al = al->next;
    }
}

Test(set_final_x_y, init_block_end_x_end_y_values)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    gom->size = 20;
    initialize_block(1, 1, 1);
    set_len_horizontal(4, gom);
    set_final_x_y_horizontal();
    cr_assert_eq(aligned->end_x, 4);
    cr_assert_eq(aligned->end_y, 1);
    cr_assert_eq(aligned->end_x, ((aligned->start_x + aligned->len) -1 ));
    cr_assert_eq(aligned->end_y, aligned->start_y);
}

Test(set_final_x_y, init_block_end_x_end_y_values_several_times)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    gom->size = 20;
    initialize_block(1, 1, 1);
    set_len_horizontal(4, gom);
    set_final_x_y_horizontal();
    cr_assert_eq(aligned->end_x, 4);
    cr_assert_eq(aligned->end_y, 1);
    cr_assert_eq(aligned->end_x, ((aligned->start_x + aligned->len) -1 ));
    cr_assert_eq(aligned->end_y, aligned->start_y);

    initialize_block(1, 3, 7);
    set_len_horizontal(3, gom);
    set_final_x_y_horizontal();
    cr_assert_eq(aligned->end_x, 5);
    cr_assert_eq(aligned->end_y, 7);
    cr_assert_not_null(aligned);
}

Test(aligned_length, test_length_count_same_player)
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

Test(aligned_length, test_align_player_x_surrounding_player_y_stones)
{
    int i = 4;
    char str[5][6] = {"2,1,1","3,1,2","4,1,2","5,1,2","6,1,1"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    int res = 0;

    gom->size = 10;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 5);
    res = check_horizontal(gom, 1,1);
    al = aligned;
    cr_assert_eq(aligned_length(), 3);
    cr_assert_eq(al->start_x, 6);
    cr_assert_eq(al->start_y, 1);
    cr_assert_eq(al->end_x, 6);
    cr_assert_eq(al->end_y, 1);
    al = al->next;
    cr_assert_eq(al->start_x, 3);
    cr_assert_eq(al->start_y, 1);
    cr_assert_eq(al->end_x, 5);
    cr_assert_eq(al->end_y, 1);
    al = al->next;
    cr_assert_eq(al->start_x, 2);
    cr_assert_eq(al->start_y, 1);
    cr_assert_eq(al->end_x, 2);
    cr_assert_eq(al->end_y, 1);    
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

Test(set_open_horizontal, open_position_value_three_list_size_three_one_combinaison)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    char str[3][6] = {"2,2,1","3,2,1","4,2,1"};
    int i = 2;

    gom->size = 5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 3);
    check_horizontal(gom, 1, 1);
    al = aligned;
    cr_assert_eq(aligned_length(), 1);
    cr_assert_eq(al->open, 3);
    cr_assert_eq(al->start_x, 2);
    cr_assert_eq(al->end_x, 4);
}

Test(set_open_horizontal, open_position_value_three_list_size_three_several_combinaison)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    char str[4][6] = {"2,2,1","3,2,1","4,2,1", "4,4,1"};
    int i = 3;
    int res = 0;

    gom->size = 10;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = check_horizontal(gom, 1, 1);
    cr_assert_eq(res, 0);
    al = aligned;
    cr_assert_not_null(head);
    cr_assert_eq(gom->size, 10);
    cr_assert_eq(aligned_length(), 2);
    cr_assert_eq(al->start_x, 4);
    cr_assert_eq(al->end_x, 4);
    cr_assert_eq(al->end_x, 4);
    cr_assert_eq(al->end_y, 4);
    cr_assert_eq(al->len, 1);
    cr_assert_eq(al->open, 3);
    al = al->next;
    cr_assert_eq(al->start_x, 2);
    cr_assert_eq(al->end_x, 4);
    cr_assert_eq(al->open, 3);
}

Test(set_open_horizontal, one_opened_position_horizontal_at_right_value_two)
{
    int res = 0;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    char str[5][6] = {"1,2,2","2,2,1","3,2,1","4,2,1", "5,2,2"};
    int i = 4;

    gom->size = 10;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 5);
    res = check_horizontal(gom, 1, 1);
    cr_assert_eq(list_length(head), 5);
    cr_assert_eq(res, 0);
    cr_assert_not_null(aligned);
    cr_assert_eq(aligned_length(), 3);
    al = aligned;
    cr_assert_eq(al->start_x, 5);
    cr_assert_eq(al->end_x, 5);
    cr_assert_eq(al->start_y, 2);
    cr_assert_eq(al->end_y, 2);
    cr_assert_eq(al->open, 2);
    al = al->next;
    cr_assert_eq(al->start_x, 2);
    cr_assert_eq(al->end_x, 4);
    cr_assert_eq(al->start_y, 2);
    cr_assert_eq(al->end_y, 2);
    cr_assert_eq(al->open, 0);
    al = al->next;
    cr_assert_eq(al->start_x, 1);
    cr_assert_eq(al->end_x, 1);
    cr_assert_eq(al->start_y, 2);
    cr_assert_eq(al->end_y, 2);
    cr_assert_eq(al->open, 0);
}


Test(set_open_vertical, vertical_test_one)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    char str[4][6] = {"2,2,1","2,3,1","2,4,1", "2,5,1"};
    int i = 3;

    gom->size = 5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    check_vertical(gom, 1, 1);
    al = aligned;
    cr_assert_eq(aligned_length(), 1);
    cr_assert_eq(al->open, 1);
    cr_assert_eq(al->start_x, 2);
    cr_assert_eq(al->end_x, 2);
    cr_assert_eq(al->start_y, 2);
    cr_assert_eq(al->end_y, 5);
}

Test(set_open_vertical, vertical_test_two)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    char str[2][6] = {"4,2,1","4,3,1"};
    int i = 3;
    int res = 0;

    gom->size = 5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 2);
    res = check_vertical(gom, 1, 1);
    cr_assert_eq(res, 0);
    al = aligned;
    cr_assert_not_null(head);
    cr_assert_eq(aligned_length(), 1);
    cr_assert_eq(al->start_x, 4);
    cr_assert_eq(al->end_x, 4);
    cr_assert_eq(al->start_y, 2);
    cr_assert_eq(al->end_y, 3);
    cr_assert_eq(al->len, 2);
    cr_assert_eq(al->open, 3);
}

Test(set_open_vertical, vertical_test_three)
{
    int res = 0;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    char str[4][6] = {"3,1,1","3,2,2","3,3,2","3,4,1"};
    int i = 3;

    gom->size = 5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    print_the_board(gom);
    res = check_vertical(gom, 1, 1);
    cr_assert_eq(res, 0);
    cr_assert_not_null(aligned);
    //cr_assert_eq(aligned_length(), 3);
    al = aligned;
    cr_assert_eq(al->start_x, 3);
    cr_assert_eq(al->end_x, 3);
    cr_assert_eq(al->start_y, 4);
    cr_assert_eq(al->end_y, 4);
    cr_assert_eq(al->len, 1);
    cr_assert_eq(al->open, 2);
    al = aligned->next;
    cr_assert_eq(al->start_x, 3);
    cr_assert_eq(al->end_x, 3);
    cr_assert_eq(al->start_y, 2);
    cr_assert_eq(al->end_y, 3);
    cr_assert_eq(al->len, 2);
    cr_assert_eq(al->open, 0);
}