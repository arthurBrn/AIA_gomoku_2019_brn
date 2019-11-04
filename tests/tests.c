/*
** EPITECH PROJECT, 2019
** tests.c
** File description:
** AIA_gomoku_2019
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(board, basic_test)
{
    cr_assert_str_eq("0", "0");
}
