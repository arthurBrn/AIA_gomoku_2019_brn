/*
** EPITECH PROJECT, 2019
** test_store_diagonal
** File description:
** Test all functions from file store_diagonal.c
*/

#include "global.h"
#include <criterion/criterion.h>

Test(initialize_block, test_init_block_diag)
{
    int player = 1;
    
}

Test(set_len_diagonal, test_len_init)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    gom->size = 20;
    initialize_block(1,1,1);
    cr_assert_eq(aligned->len, 0);
    set_len_horizontal(5, gom);
    cr_assert_eq(aligned->len, 5);
}


