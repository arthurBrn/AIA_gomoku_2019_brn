/*
** EPITECH PROJECT, 2019
** test_tree.c
** File description:
** test all function related to the tree
*/

#include <criterion/criterion.h>
#include "tree.h"
#include "global.h"

Test(init_regular_node, reg_node_init_w_fix_value_x_and_0)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    root_t *temp_root = malloc(sizeof(root_t));
    tree_node_t *node_x = malloc(sizeof(tree_node_t));
    tree_node_t *node_z = malloc(sizeof(tree_node_t));
    int i = 1;
    int z = 0;
    int depth_size = 1;

    gom->size = 3;
    temp_root = init_root_node(temp_root, gom);
    node_x = init_regular_node(temp_root->node, node_x, i, depth_size);
    node_z = init_regular_node(temp_root->node, node_z, z, depth_size);
    cr_assert_eq(node_x->parent, temp_root->node);
    cr_assert_eq(node_x->x, i);
    cr_assert_eq(node_x->y, i);
    cr_assert_eq(node_x->points, i);
    cr_assert_eq(node_z->parent, temp_root->node);
    cr_assert_eq(node_z->x, z);
    cr_assert_eq(node_z->y, z);
    cr_assert_eq(node_z->points, z);
    cr_assert_null(node_x->children);
    cr_assert_null(node_z->children);
}

Test(init_regular_node, reg_node_init_w_random_value_through_loop)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    root_t *temp_root = malloc(sizeof(root_t));
    tree_node_t *node = malloc(sizeof(tree_node_t));
    int tab[5] = {0,1,2,3,4};
    int depth_size = 1;

    gom->size = 3;
    temp_root = init_root_node(temp_root, gom);
    for (int cpt = 0; cpt < 5; cpt++) {
        node = init_regular_node(temp_root->node, node, cpt, depth_size);
        cr_assert_eq(node->parent, temp_root->node);
        cr_assert_eq(node->x, tab[cpt]);
        cr_assert_eq(node->y, tab[cpt]);
        cr_assert_eq(node->points, tab[cpt]);
        cr_assert_null(node->children);
        cr_assert_not_null(node->parent);
        cr_assert_eq(node->parent->x, 0);
        cr_assert_eq(node->parent->y, 0);
        cr_assert_eq(node->parent->points, 0);
    }
    cr_assert_eq(temp_root->size, ((gom->size * gom->size) - list_length(head)));
}

Test(init_root_node, proper_root_initiailzation)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    root_t *temp_root = malloc(sizeof(root_t));

    gom->size = 3;
    temp_root = init_root_node(temp_root, gom);
    cr_assert_eq(temp_root->size, ((gom->size*gom->size) - list_length(head)));
    cr_assert_null(temp_root->node->parent);
    cr_assert_not_null(temp_root->node);
    cr_assert_eq(temp_root->node->x, 0);
    cr_assert_eq(temp_root->node->y, 0);
    cr_assert_eq(temp_root->node->points, 0);
    cr_assert_not_null(temp_root->node->children);
}

Test(adding_one_depth, multiple_reg_node_init_depth_one)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    root_t *temp_root = malloc(sizeof(root_t));
    int tab[9] = {0,1,2,3,4,5,6,7,8};
    int depth_size = 1;

    gom->size = 3;
    temp_root = init_root_node(temp_root, gom);
    cr_assert_not_null(temp_root->node->children);
    cr_assert_null(temp_root->node->parent);
    cr_assert_eq(temp_root->node->x, 0);
    cr_assert_eq(temp_root->node->y, 0);
    cr_assert_eq(temp_root->node->points, 0);
    cr_assert_eq(temp_root->size, ((gom->size * gom->size) - list_length(head)));
    cr_assert_eq(temp_root->size, 9);
    adding_one_depth(temp_root->node, gom, temp_root->size, depth_size);
    for (int i = 0; i < temp_root->size; i++) {
        cr_assert_not_null(temp_root->node->children[i]);
        cr_assert_not_null(temp_root->node->children[i]->parent);
        cr_assert_null(temp_root->node->children[i]->children);
        cr_assert_eq(temp_root->node->children[i]->parent, temp_root->node);
        cr_assert_eq(temp_root->node->children[i]->x, i);
        cr_assert_eq(temp_root->node->children[i]->y, i);
        cr_assert_eq(temp_root->node->children[i]->points, i);
    }
}

Test(initialize_tree, valid_tree_initialization_depth_one)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;
    int depth_size = 1;

    gom->size = 3;
    res = initialize_tree(gom, depth_size);
    cr_assert_eq(res, 0);
    cr_assert_eq(root->size, ((gom->size*gom->size) - list_length(head)));
    cr_assert_not_null(root->node);
    cr_assert_eq(root->node->x, 0);
    cr_assert_eq(root->node->y, 0);
    cr_assert_eq(root->node->points, 0);
    cr_assert_null(root->node->parent);
    cr_assert_not_null(root->node->children);
}

Test(initialize_tree, valid_tree_initialization_depth_two)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;
    int depth_size = 2;

    gom->size = 3;
    res = initialize_tree(gom, depth_size);
    cr_assert_eq(root->size, ((gom->size*gom->size) - list_length(head)));
    cr_assert_not_null(root->node->children);
    cr_assert_not_null(root->node->children[0]->children);
    cr_assert_not_null(root->node->children[0]->children[0]);
    cr_assert_eq(root->node->children[0]->children[0]->x, 0);
}
