/*
** EPITECH PROJECT, 2019
** test_error_coordinate.c
** File description:
** Check if the corrdinate send are correct
*/

#include <criterion/criterion.h>
#include "node.h"

Test(test_coordinate, valid_coordinate)
{
    char *str = "10,10,1";
    char *delimiter = ",";
    char **array = my_str_to_word_array(str, delimiter);
    int res = check_coordinate(array);

    res = check_coordinate(array);
    cr_assert_eq(res, 1);
}

Test(test_coordinate, invalid_first_coordinate)
{
    char *str = "25,10,1";
    char *delimiter = ",";
    char **array = my_str_to_word_array(str, delimiter);
    int res = check_coordinate(array);

    res = check_coordinate(array);
    cr_assert_eq(res, 84);
}
