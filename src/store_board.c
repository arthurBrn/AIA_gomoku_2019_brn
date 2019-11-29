/*
** EPITECH PROJECT, 2019
** store_board.c
** File description:
** linked list to store board input
*/

#include "global.h"

int list_length(node_t *node_head)
{
    int i = 0;

    node_t *node = node_head;
    for (; node != NULL; i++)
        node = node->next;
    return (i);
}

int matching_node(char *str, node_t *node)
{
    node_t *node_head = node;
    char **tab = my_str_to_word_array(str, ",");
    int x = atoi(tab[0]);
    int y = atoi(tab[1]);
    int p = atoi(tab[2]);

    while (node_head != NULL) {
        if (x == node_head->x && y == node_head->y && p == node_head->player)
            return (84);
        if (x == node_head->x && y == node_head->y)
            return (84);
        node_head = node_head->next;
    }
    return (1);
}

node_t *add_node(char *str, node_t *node_head)
{
    node_t *temp = malloc(sizeof(node_t));
    char **tab = my_str_to_word_array(str, ",");

    if (node_head == NULL) {
        temp->x = atoi(tab[0]);
        temp->y = atoi(tab[1]);
        temp->player = atoi(tab[2]);
        temp->next = NULL;
    }
    if (node_head != NULL) {
        temp->x = atoi(tab[0]);
        temp->y = atoi(tab[1]);
        temp->player = atoi(tab[2]);
        temp->next = node_head;
    }
    return (temp);
}

int store_board(char *str, t_gomoku *gom)
{
    node_t *node = NULL;

    if (check_string(str, gom) != 84 && matching_node(str, head) != 84) {
        node = add_node(str, head);
        head = node;
    } else
        return (MY_EXIT_FAILURE);
    return (0);
}
