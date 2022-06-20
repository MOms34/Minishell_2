/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** tree_creation
*/

#include "minishell.h"

void add_branch_further(tree_t **tree, tree_t *branch)
{
    tree_t *head = *tree;

    if (get_tree_depth(&head->left) >= get_tree_depth(&head->right)) {
        add_branch(&head->left, branch);
    } else {
        add_branch(&head->right, branch);
    }
}

void add_branch(tree_t **tree, tree_t *branch)
{
    tree_t *head = *tree;

    if (head == NULL) {
        head = branch;
        return;
    }
    if (head->left == NULL) {
        head->left = branch;
    } else if (head->right == NULL) {
        head->right = branch;
    } else {
        add_branch_further(&head, branch);
    }
}

tree_t *create_tree(void *data)
{
    tree_t *new_tree = malloc(sizeof(tree_t));

    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->data = data;
    return new_tree;
}
