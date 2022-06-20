/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** function for cd
*/

#include "minishell.h"

int tabaloc(char **tab)
{
    int i = 0;

    for (int y = 0; tab[y] != NULL; y++) {
        for (int x = 0; tab[y][x] != '\0'; x++) {
            i++;
        }
        i++;
    }
    return (i);
}

char *delete_first_space(char *str)
{
    int i = 0;
    int j = 0;
    char *to_return = malloc(sizeof(char) * (my_strlen(str)));

    while (str[j] == ' ' || str[j] == '\t')
        j++;
    while (str[j] != '\0') {
        to_return[i] = str[j];
        j++;
        i++;
    }
    to_return[i] = '\0';
    return (to_return);
}

char *parse_my_line(char const *line)
{
    int i = 0;
    char **tab = str_to_word_tab(line);
    int t = tabaloc(tab);
    char *str = malloc(sizeof(char) * (t + 1));

    for (int y = 0; tab[y] != NULL; y++) {
        for (int x = 0; tab[y][x] != '\0'; x++) {
            str[i] = tab[y][x];
            i++;
        }
        if (tab[y + 1] != NULL) {
            str[i] = ' ';
            i++;
        }
    }
    str[i] = '\0';
    return (delete_first_space(str));
}

void change_old_pwd(linked_list_l **menv, char *my_pwd)
{
    linked_list_l *node = *menv;

    while (node != NULL) {
        if (my_strcmp(parse_left_env(node->env), "OLDPWD") == 0) {
            free(node->env);
            node->env = my_strcat(my_strcat("OLDPWD=", my_pwd), "\0");
            return;
        }
        node = node->next;
    }
}
