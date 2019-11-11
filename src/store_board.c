/*
** EPITECH PROJECT, 2019
** store_board.c
** File description:
** linked list to store board input
*/

#include "global.h"

int list_length(node_t *head)
{
    int i = 0;

    for (i; head != NULL; i++)
        head = head->next;
    return (i);
}

int matching_node(char *str, node_t *node)
{
    char **tab = my_str_to_word_array(str, ",");
    int x = atoi(tab[0]);
    int y = atoi(tab[1]);
    int p = atoi(tab[2]);
    int flag = 0;

    if (node == NULL)
        return (0);
    while (node != NULL) {
        if (x == node->x && y == node->y && p == node->player)
            flag = 1;
        node = node->next;
    }
    return (flag);
}

node_t *add_node(char *str, node_t *node)
{
    node_t *temp = malloc(sizeof(node_t));
    char **tab = my_str_to_word_array(str, ",");

    if (node == NULL) {
        temp->x = atoi(tab[0]);
        temp->y = atoi(tab[1]);
        temp->player = atoi(tab[2]);
        temp->next = NULL;
    }
    if (node != NULL) {
        temp->x = atoi(tab[0]);
        temp->y = atoi(tab[1]);
        temp->player = atoi(tab[2]);
        temp->next = node;
    }
    return (temp);
}

void store_board(char *str)
{
    node_t *node = NULL;

    if (check_string(str) != 1)
        invalid_string();
    node = add_node(str, head);
    head = node;
}
