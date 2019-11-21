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

    gom->start = 15;
    gom->player = 22;
    gom->end = 3;
    gom->size = 12;
    init_struct(gom);
    cr_assert_eq(gom->start, 0);
    cr_assert_eq(gom->player, 0);
    cr_assert_eq(gom->end, 0);
    cr_assert_eq(gom->size, 20);
    free(gom);
}

/*Test(check_cmd, valid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "START";
    char *str = "START 20";
    int (*tab_cmd[5])(t_gomoku *, char *);
    int res = 0;

    res = check_cmd(s1, str, tab_cmd, gom);
    cr_assert_eq(res, 0);
    free(gom);
}

Test(check_cmd, invalid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "START ";
    char *str = "START 20";
    int res = 0;

    cr_assert_eq(res, 1);
    free(gom);
}
*/
Test(readstandard, test_if_end_eq_one)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->end = 1;
    res = readstandard(gom);
    cr_assert_eq(res, 0);
    free(gom);
}

