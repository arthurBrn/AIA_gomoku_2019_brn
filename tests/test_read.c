/*
** EPITECH PROJECT, 2019
** test_read.c
** File description:
** test all function in file src/read.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(init_struct, test_initialization_structure)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int size = 0;
    int player = 0;
    int start = 0;
    int end = 0;

    gom->size = size;
    gom->player = player;
    gom->start = start;
    gom->end = end;

    cr_assert_eq(size, gom->size);
    cr_assert_eq(player, gom->player);
    cr_assert_eq(start, gom->start);
    cr_assert_eq(end, gom->end);
    free(gom);
}

Test(readstandard, test_if_end_eq_one)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->end = 1;
    res = readstandard(gom);
    cr_assert_eq(res, 0);
}

