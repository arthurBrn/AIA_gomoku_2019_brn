/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** Will contain every function related to rooted tree
*/

#include "global.h"

tree_node_t *init_regular_node(tree_node_t *parent, tree_node_t *reg, int value, int depth_size)
{
    reg->parent = parent;
    reg->x = value;
    reg->y = value;
    reg->points = value;
    reg->children = NULL;
    return (reg);
}

//root_t *adding_one_depth(tree_node_t *parent, t_gomoku *gom, int count_children, int depth_size)
void adding_one_depth(tree_node_t *parent, t_gomoku *gom, int count_children, int depth_size)
{
    tree_node_t *reg_node = NULL;
    int value = 0;

    for (int i = 0; i < count_children; i++) {
        reg_node = malloc(sizeof(tree_node_t));
        reg_node = init_regular_node(parent, reg_node, value, depth_size);
        parent->children[i] = reg_node;
        value++;
    }
}

root_t *init_root_node(root_t *root_node, t_gomoku *gom)
{
    root_node->size = ((gom->size * gom->size) - list_length(head));
    root_node->node = malloc(sizeof(tree_node_t));
    root_node->node->parent = NULL;
    root_node->node->x = 0;
    root_node->node->y = 0;
    root_node->node->points = 0;
    root_node->node->children = (tree_node_t **)malloc(sizeof(tree_node_t *) * root_node->size);
    return (root_node);
}

void initialize_depth_of_one(root_t *temp_root, t_gomoku *gom, int depth_size)
{
    tree_node_t *parent = NULL;
    tree_node_t *parent_holder = NULL;
    int count_children = temp_root->size;

    parent = temp_root->node;
    adding_one_depth(parent, gom, count_children, depth_size);

}

void initialize_several_depth(tree_node_t *parent, t_gomoku *gom, int depth_size, int count_children)
{
    for (int j = 0; j < (count_children); j++) {
        parent->children[j]->children = (tree_node_t **)malloc(sizeof(tree_node_t *) * (count_children - 1));
        for (int k = 0; k < (count_children - 1); k++)
            adding_one_depth(parent->children[j], gom, (count_children - 1), depth_size);
    }
}

int initialize_tree(t_gomoku *gom, int depth_size)
{
    tree_node_t *parent = NULL;
    tree_node_t *parent_holder = NULL;
    root_t *temp_root = malloc(sizeof(root_t));
    int count_children = 0;

    temp_root = init_root_node(temp_root, gom);
    count_children = temp_root->size;
    if (depth_size <= 0)
        return (84);
    if (depth_size == 1)
        initialize_depth_of_one(temp_root, gom, depth_size);
    else {
        initialize_depth_of_one(temp_root, gom, depth_size);
        parent = temp_root->node;
        while ((depth_size - 1) > 0) {
            initialize_several_depth(parent, gom, depth_size, count_children);
            depth_size--;
        }
    }
    root = temp_root;
    return (0);
}
