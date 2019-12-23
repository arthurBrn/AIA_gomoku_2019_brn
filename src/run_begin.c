/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** gomoku
*/

#include "gomoku.h"
#include "board.h"

// add "t_board *board" here
int error_begin(t_gomoku *gomoku)
{
    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (gomoku->begin == 1)
        return (MY_EXIT_FAILURE);
    //vérifier si notre tableau est deja remplie
    /* 
    // Si le board n'a pas été initialisé == erreur
    if (board == NULL)
        return (MY_EXIT_FAILURE);
    // Si le board à été initialiser mais que les valeurs d'init ont été modifiés
    if (board->x != -1)
        return (MY_EXIT_FAILURE);
    */
    return (0);
}

int run_begin(char *str, t_gomoku *gomoku)
{
    (void) str;
    if (error_begin(gomoku) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    else {
        gomoku->begin = 1;
        //jouer le premier coup au milieu et l'enregistrer
        // Call store move here
        return (0);
    }
}
