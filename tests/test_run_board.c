/*
** EPITECH PROJECT, 2019
** test_run_board.c
** File description:
** test all function of file run_board.c
*/

#include "global.h"
#include <criterion/criterion.h>

Test(run_board, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;

    gom->start = 0;
    res = run_board(gom,str);
    cr_assert_eq(res, ERROR);
}

Test(run_board, str_param_must_be_null)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;

    gom->start = 1;
    res = run_board(gom,str);
    cr_assert_eq(res, ERROR);
}

/*
Test(run_board, feeding_read_empty_str)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;
    int i = 3;
    char tab[4][8] =
        {
            "",
            "2,2,2",
            "3,1,1",
            "1,1,1"
        };

    gom->start = 1;
    for (; i >= 0; i--) {
        res = run_board(gom,tab[i]);
    }
    cr_assert_eq(res, ERROR);
}
*/

Test(run_board, feeling_linked_list_w_data_send_through_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;
    int i = 3;
    char tab[4][8] =
        {
            "DONE",
            "2,2,2",
            "3,1,1",
            "1,1,1"
        };

    gom->start = 1;
    for (; i >= 0; i--) {
        run_board(gom, tab[i]);
        if (i == 0)
            write(1, "DONE", 4);
        else
            write(1, tab[1], 6);
        i--;
    }
    cr_assert_neq(empty_list(head), 0);
    cr_assert_neq(res, ERROR);
    cr_assert_eq(res, 0);
}
