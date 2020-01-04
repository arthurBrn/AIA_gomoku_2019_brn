/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** ..
*/

#include "gomoku.h"

int isnum(char *str)
{
    for (int i = 0; (str[i]); i++)
        if (isdigit(str[i]) == 0 || str[i] == ' ')
            return (MY_EXIT_FAILURE);
    return (0);
}

char *itoa(int nb, char *str, int size) {
    str[size] = '\0';
    while (size--) {
        str[size] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (str);
}

int play_len(char *play)
{
    int i = 0;  
    int len = 0;

    for (i = i; play[i] != '\0' && play[i] == '0'; i++);
    for (i = i; play[i] != '\0'; i++)
        len++;
    return (len);
}

char *delete_zero(char *play)
{
    int len = play_len(play);
    int i = 0;
    int j = 0;
    char *new_play = malloc(sizeof(char) * len + 1);

    for (i = i; play[i] != '\0' && play[i] == '0'; i++);
    for (i = i; play[i] != '\0'; i++) {
	new_play[j] = play[i];
	j++;
    }
    return (new_play);
}

char *concat_coordonate(t_gomoku *gomoku, char *xy)
{
    char *move_coordonate = malloc(sizeof(char) * 5);

    move_coordonate[0] = *xy;
    move_coordonate[1] = ',';
    move_coordonate[2] = *xy;
    move_coordonate[3] = ',';
    move_coordonate[4] = (gomoku->player + '0');
    move_coordonate[5] = '\0';
    return (move_coordonate);
}
