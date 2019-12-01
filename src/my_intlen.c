/*
** EPITECH PROJECT, 2019
** my_intlen.c
** File description:
** return the len of an int
*/

int my_intlen(int nb)
{
    int count = 0;

    for (count; nb > 9; count ++) {
        nb /= 10;
    }
    count++;
    return count;
}
