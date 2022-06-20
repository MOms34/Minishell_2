/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** other_commands
*/

#include "minishell.h"

char *add_equal(char *params)
{
    int i = 0;
    char *cpy = malloc(sizeof(char) * (my_strlen(params) + 1));

    while (params[i] != '\0') {
        cpy[i] = params[i];
        i++;
    }
    if (params[i - 1] != '=') {
        cpy[i] = '=';
        cpy[i + 1] = '\0';
    } else {
        cpy[i] = '\0';
    }
    return (cpy);
}

void set_env(char const *line, linked_list_l **list)
{
    char **params = str_to_word_tab(line);
    linked_list_l *menv = *list;

    if (cpt_params(params) == 1)
        return (print_linked_list(menv));
    if (cpt_params(params) > 3)
        return (display_error(3));
    if ((my_isalpha(params[1][0])) == 0)
        return (display_error(1));
    while (menv != NULL) {
        if (my_strcmp(parse_left_env(menv->env), params[1]) == 0) {
            free(menv->env);
            menv->env = fill_line_env(params);
            return;
        }
        menv = menv->next;
    }
    add_node_at_back(list, fill_line_env(params), 0);
}

void unset_env(char const *line, linked_list_l *menv)
{
    char **params = str_to_word_tab(line);

    if (params[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; params[i] != NULL; i++) {
        remove_node(&menv, params[i]);
    }
}

void set_or_unset_env(char const *line, linked_list_l *menv)
{
    if (my_strncmp(line, "setenv", 6) == 0)
        set_env(line, &menv);
    else if (my_strncmp(line, "unsetenv", 8) == 0)
        unset_env(line, menv);
}

void other_command(char const *line, linked_list_l *menv)
{
    char **params = str_to_word_tab(line);

    if (my_strncmp(line, "cd", 2) == 0) {
        if (my_strncmp(line, "cd -", 4) != 0)
            change_old_pwd(&menv, getcwd(NULL, 0));
        my_cd(line, str_to_tab(menv), menv);
    } else if (my_strncmp(line, "setenv", 6) == 0 || \
            my_strncmp(line, "unsetenv", 8) == 0 || \
            my_strncmp(line, "env", 3) == 0) {
            set_or_unset_env(line, menv);
    } else
        my_printf("%s: Command not found.\n", params[0]);
}
