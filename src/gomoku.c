/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "gomoku.h"
#include "board.h"

t_board *init_board()
{
    t_board *board = malloc(sizeof(t_board));
    board->x = -1;
    board->y = -1;
    board->player = -1;
    board->next = NULL;
    return (board);
}

void init_struct(t_gomoku *gomoku)
{
    gomoku->start = 0;
    gomoku->player = 0;
    gomoku->end = 0;
    gomoku->size = 0;
    gomoku->begin = 0;
    gomoku->board = init_board();
}

int check_cmd(char *str, int (*tab_cmd[5])(), t_gomoku *gomoku)
{
    char *tab[6] = {"START", "END", "BEGIN", "BOARD", "TURN", '\0'};
    char **newtab = my_str_to_word_array(str, " ");
    int compteur = 0;

    if (newtab[0] == NULL)
        return (100);
    if (newtab[1] == NULL) {
        newtab[1] = "\0";
        newtab[0][strlen(newtab[0]) - 1] = '\0';
    }
    else
        newtab[1][strlen(newtab[1]) - 1] = '\0';
    for (int i = 0; tab[i]; i++) {
        if (strcmp(newtab[0], tab[i]) == 0) {
            if ((*tab_cmd[i])(newtab[1], gomoku) == MY_EXIT_FAILURE)
                return (MY_EXIT_FAILURE);
            compteur = 1;
        }
    }
    if (compteur == 0)
        return (1);
    return (0);
}

int loop_read(t_gomoku *gomoku, int (*tab_cmd[5])(char *, t_gomoku *gomoku))
{
    char *line = NULL;
    size_t len = 0;
    int return_value;
    ssize_t read;

    while (gomoku->end != 1)
    {
        while ((read = getline(&line, &len, stdin)) != -1) {
            return_value = check_cmd(line, tab_cmd, gomoku);
            if (return_value == MY_EXIT_FAILURE)
                return (MY_EXIT_FAILURE);
            if (return_value == 1)
                write(1, UNKNOWN, strlen(UNKNOWN));
            if (return_value == 100)
                return (0);
            if (gomoku->end == 1)
                break;
        }
        if (line)
            free(line);
    }
    return (0);
}

int gomoku()
{
    t_gomoku *gomoku = malloc(sizeof(*gomoku));
    int (*tab_cmd[5])(char *, t_gomoku *);

    init_struct(gomoku);
    run_cmd(tab_cmd);
    if (loop_read(gomoku, tab_cmd) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    return (0);
}
