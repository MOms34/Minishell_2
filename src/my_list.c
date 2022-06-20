/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_linked_list
*/

#include "minishell.h"

int without_space(char const *line, int i)
{
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    return (i);
}

char *my_strcopy(char *str)
{
    int len = my_strlen(str) + 1;
    char *copy = malloc(len);

    if (copy == NULL)
        return (NULL);
    copy = my_strcpy(copy, str);
    copy[len - 1] = '\0';
    return (copy);
}

void add_node_at_back(linked_list_l **env_in_list, char *env, int args)
{
    linked_list_l *node = malloc(sizeof(linked_list_l));

    node->env = my_strcopy(env);
    node->nodes = args;
    node->next = NULL;
    while ((*env_in_list)->next != NULL)
        env_in_list = &(*env_in_list)->next;
    (*env_in_list)->next = node;
}

void print_linked_list(linked_list_l *n_node)
{
    linked_list_l *node = n_node;

    while (node != NULL) {
        my_printf("%s\n", node->env, node->nodes);
        node = node->next;
    }
}

linked_list_l *create_list(char **env)
{
    int nb_args;
    int i = 1;
    linked_list_l *env_in_list = malloc(sizeof(linked_list_l));

    env_in_list->env = my_strcopy(env[0]);
    for (nb_args = 0; env[nb_args] != NULL; nb_args++) {}
    env_in_list->nodes = nb_args;
    env_in_list->next = NULL;
    while (env[i] != NULL) {
        add_node_at_back(&env_in_list, env[i], nb_args);
        i++;
    }
    return (env_in_list);
}
