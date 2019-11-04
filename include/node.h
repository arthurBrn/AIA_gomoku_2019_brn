/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** Contains typedef of linked list
*/

typedef struct linked_list
{
    void *data_x;
    void *data_y;
    void *player;
    struct linked_list *next;
} linked_list_t;
