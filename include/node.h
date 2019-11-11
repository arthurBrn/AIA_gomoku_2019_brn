/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** Contains typedef of linked list
*/

#ifndef _NODE_H_
#define _NODE_H_

#define EXIT_USAGE 84
#define ERROR_MSG "error"
#define SYNTAX_ERROR_MSG "Syntax error."

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int x;
    int y;
    int player;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
} list_t;

void invalid_string(void);
int only_digit_str(char *str);
int nbr_coma(char *str);
int check_players(char *str);
int check_string(char *str);
int check_coordinate(char *str);
char **my_str_to_word_array(char *str, char *delimiter);
int list_length(node_t *head);
int matching_node(char *str, node_t *head);
node_t *add_node(char *str, node_t *head);
node_t *store_board(char *str);

#endif
