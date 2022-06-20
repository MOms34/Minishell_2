/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** check_parsing
*/

#include "minishell.h"

char *parse_left_env(char const *str)
{
    int i = 0;
    char *cpy = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '=') {
        if (str[i] == '\0')
            return (NULL);
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

void remove_node(linked_list_l **list, char *data)
{
    linked_list_l *node = *list;
    linked_list_l *prev = NULL;

    while (node != NULL) {
        if (my_strcmp(parse_left_env(node->env), data) == 0) {
            if (prev == NULL)
                *list = node->next;
            else
                prev->next = node->next;
            free(node->env);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

char *fill_line_env(char **params)
{
    char *env_line;

    if (params[2] != NULL) {
        env_line = malloc(sizeof(char) * (my_strlen(params[1]) +
        my_strlen(params[2]) + 2));
        env_line = my_strcpy(env_line, params[1]);
        env_line = my_strcat(env_line, "=");
        env_line = my_strcat(env_line, params[2]);
    } else {
        env_line = malloc(sizeof(char) * (my_strlen(params[1]) + 2));
        env_line = my_strcpy(env_line, params[1]);
        env_line = my_strcat(env_line, "=");
    }
    return (env_line);
}

int cpt_params(char **params)
{
    int i = 0;

    while (params[i] != NULL)
        i++;
    return (i);
}

void display_error(int nb)
{
    if (nb == 1) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return;
    }
    if (nb == 2) {
        my_printf("setenv: Variable name must contain \
        alphanumeric characters.\n");
        return;
    }
    if (nb == 3) {
        my_printf("setenv: Too many arguments.\n");
        return;
    }
}
