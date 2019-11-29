/*
** EPITECH PROJECT, 2019
** test_run_turn.c
** File description:
** test all function of file src/run_turn.c
*/

#include "global.h"
#include <criterion/criterion.h>
#include <criterion/parameterized.h>

Test(init_begin, no_player)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    init_begin(gom);
    cr_assert_eq(gom->player, 2);
}

Test(init_begin, player_one_defined)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    gom->player = 1;
    init_begin(gom);
    cr_assert_eq(gom->player, 1);
}

Test(init_begin, player_two_defined)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    gom->player = 2;
    init_begin(gom);
    cr_assert_eq(gom->player, 2);
}

Test(run_turn, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "TURN 10,10";
    int res = 0;

    gom->start = 0;
    res = run_turn(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_turn, game_started_check_error_pos)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "10,,10";
    int res = 0;

    gom->start = 1;
    gom->size = 11;
    res = run_turn(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_turn, game_started_coordonate_out_of_grid)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "10,10";
    int res = 0;

    gom->start = 1;
    gom->size = 9;
    res = run_turn(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_turn, insertion_in_global_linked_list)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int i = 3;
    int res = 0;
    char **str;
    char tab[4][4] =
        {
            "1,1",
            "2,2",
            "3,2",
            "5,1"
        };

    gom->size = 20;
    gom->start = 1;
    for (; i >=0; i--)
        run_turn(gom, tab[i]);
    cr_assert_eq(list_length(head), 4);
    i = 0;
    for (; head != NULL; i++) {
        str = my_str_to_word_array(tab[i], ",");
        cr_assert_eq(head->x, atoi(str[0]));
        cr_assert_eq(head->y, atoi(str[1]));
        head = head->next;
    }
}
