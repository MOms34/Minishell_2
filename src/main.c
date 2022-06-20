/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** main
*/

#include "minishell.h"

void my_command(char const *l, linked_list_l *menv)
{
    path_command_t *p_command = malloc(sizeof(path_command_t));
    char const *line = parse_my_line(l);
    char **params = str_to_word_tab(line);

    if (params[0][my_strlen(params[0]) - 1] == '\n')
            params[0][my_strlen(params[0]) - 1] = '\0';
    if ( l[0] == 0)
        return;
    p_command->path = search_command(str_to_tab(menv), "PATH", 4);
    p_command->command = false;
    p_command->good_path = NULL;
    check_command(p_command, line);
    if (p_command->command == true && my_strcmp(params[0], "cd") != 0)
        execute_command(menv, line, p_command->good_path);
    else
        other_command(line, menv);
}

void simple_mysh(linked_list_l *my_env)
{
    char *line = NULL;
    size_t len = 0;

    my_printf("==> ");
    while (getline(&line, &len, stdin) != -1) {
        if (my_strncmp(line, "exit", 4) == 0)
            break;
        if (line != NULL && check_operators(line, ">;") == 0 && line[0] != 0) {
            line[my_strlen(line) - 1] = '\0';
            my_command(line, my_env);
        }
        if (line != NULL && check_operators(line, ">;") > 0) {
            line[my_strlen(line) - 1] = '\0';
            separator_cmd(line, my_env);
        }

        wait(NULL);
        my_printf("==> ");
    }
}

void without_prompt(linked_list_l *my_env)
{
    char *line = NULL;
    size_t len = 0;
    char **params = NULL;

    while (getline(&line, &len, stdin) != -1) {
        params = str_to_word_tab(line);
        if (params[0][my_strlen(params[0]) - 1] == '\n')
            params[0][my_strlen(params[0]) - 1] = '\0';
        if (my_strcmp(params[0], "exit") == 0)
            break;
        if (line != NULL && check_operators(line, ";") == 0 && line[0] != 0) {
            line[my_strlen(line) - 1] = '\0';
            my_command(line, my_env);
        }
        if (line != NULL && check_operators(line, ";") > 0) {
            line[my_strlen(line) - 1] = '\0';
            separator_cmd(line, my_env);
        }

        wait(NULL);
    }
}

char *my_parthpwd(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PWD", 3) == 0)
            return (parse_path(env[i]));
    }
    return (NULL);
}

int main(int argc, char **argv, char **env)
{
    linked_list_l *my_env = create_list(env);

    (void) argc;
    (void) argv;
    if (isatty(STDIN_FILENO) == 0)
        without_prompt(my_env);
    else
        simple_mysh(my_env);
    free(my_env);
    return (0);
}
