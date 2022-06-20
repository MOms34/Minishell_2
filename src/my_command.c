/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_execommand
*/

#include "minishell.h"

char *parse_path_commands(char *path)
{
    int i = 0;
    int j = 0;
    char *cpy = malloc(sizeof(char) * my_strlen(path) - 4);

    while (path[i] != '/')
        i++;
    while (path[i] != '\0') {
        if (path[i] == ':') {
            cpy[j] = '\n';
            i++;
            j++;
        } else {
            cpy[j] = path[i];
            i++;
            j++;
        }
    }
    cpy[j] = '\n';
    cpy[j + 1] = '\0';
    return (cpy);
}

bool good_or_not(char *path, char const *line)
{
    if (access(my_strcat(path, my_strcat("/", line)), R_OK) != -1)
        return (true);
    else
        return (false);
}

void check_command(path_command_t *p_command, char const *l)
{
    char *tmp = malloc(sizeof(char) * my_strlen(p_command->path));
    int j = 0;
    char *re_tm = tmp;
    char *line = parse_line(l);

    for (int i = 0; p_command->path[i] != '\0'; i++, j++) {
        if (p_command->path[i] == '\n') {
            tmp[j] = '\0';
            re_tm = tmp;
            p_command->command = good_or_not(tmp, line);
            j = 0;
            i++;
            tmp = malloc(sizeof(char) * my_strlen(p_command->path));
        }
        if (p_command->command == true)
            break;
        tmp[j] = p_command->path[i];
    }
    p_command->good_path = malloc(sizeof(char) * (my_strlen(re_tm) + 1));
    p_command->good_path = re_tm;
}

void execute_command(linked_list_l *menv, char const *line, char *p)
{
    pid_t pid = 0;
    int status = 0;
    char *full_path = malloc(sizeof(char) *\
    (my_strlen(line) + my_strlen(p) + 2));
    char **my_env = str_to_tab(menv);
    char **arg = str_to_word_tab(line);

    full_path = my_strcat_sec(p, my_strcat("/", line));
    pid = fork();
    if (pid == -1)
        perror("fork");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
}   else {
        if (execve(full_path, arg, my_env) == -1)
                perror("execve");
        exit(EXIT_FAILURE);
    }
}

char *search_command(char **env, char *line_env, int to_cmp)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], line_env, to_cmp) == 0)
            return (parse_path_commands(env[i]));
    }
    return (NULL);
}
