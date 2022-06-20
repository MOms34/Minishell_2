/*
** EPITECH PROJECT, 2021
** 42SH
** File description:
** Tree traversals
*/

#include "minishell.h"

int get_tree_depth(tree_t **tree)
{
    tree_t *head = *tree;

    if (head == NULL) {
        return 0;
    }
    return 1 + (get_tree_depth(&head->left) || get_tree_depth(&head->right));
}

void display_node(char *data, int layer)
{
    for (int i = layer; i > 0; i--) {
        my_printf("  ");
    }
    my_printf("%s\n", (char *) data);
}

void in_order_browsing(tree_t **tree, int layer)
{
    tree_t *head = *tree;

    if (head->left != NULL) {
        in_order_browsing(&head->left, layer + 1);
    }
    display_node(head->data, layer);
    if (head->right != NULL) {
        in_order_browsing(&head->right, layer + 1);
    }
}

void pre_order_browsing(tree_t **tree, int layer)
{
    tree_t *head = *tree;

    display_node(head->data, layer);
    if (head->left != NULL) {
        pre_order_browsing(&head->left, layer + 1);
    }
    if (head->right != NULL) {
        pre_order_browsing(&head->right, layer + 1);
    }
}

void post_order_browsing(tree_t **tree, int layer)
{
    tree_t *head = *tree;

    if (head->left != NULL) {
        post_order_browsing(&head->left, layer + 1);
    }
    if (head->right != NULL) {
        post_order_browsing(&head->right, layer + 1);
    }
    display_node(head->data, layer);
}
