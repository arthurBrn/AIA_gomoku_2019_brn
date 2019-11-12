/*
** EPITECH PROJECT, 2019
** store_board.c
** File description:
** linked list to store board input
*/

#include "global.h"

void free_list(node_t *head)
{
    node_t *temp = NULL;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

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
    int flag = 1;

    if (node == NULL)
        return (1);
    while (node != NULL) {
        if (x == node->x && y == node->y && p == node->player)
            flag = 0;
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

void store_board(char *str, t_gomoku *gom)
{
    node_t *node = NULL;
    int valid_str = check_string(str, gom);
    int matching = matching_node(str, head);

    if (valid_str == 1 && matching == 1) {
        node = add_node(str, head);
        head = node;
    } else
        puts(ERROR_MSG);
}
