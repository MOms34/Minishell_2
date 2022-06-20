/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** main
*/

#include "minishell.h"

void exec_op(char **tab, linked_list_l *my_env, char c)
{
    char *str = NULL;

    if (c == ';')
        str = "|&<>";
    for (int i = 0; tab[i] != NULL; i++) {
        if (check_operators(tab[i], str) == 0) {
            my_command(tab[i], my_env);
        }
        if (check_operators(tab[i], ">") == 1) {
            separator_cmd(tab[i], my_env);
        }
    }
}

char *exec_simple_redi(char **tab, char c)
{
    char *str = NULL;
    if (tab[1] == NULL || tab[0] == NULL || c == '1')
        perror("Command redirections.");
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i + 1] == NULL) {
            return tab[i];
        }
    }
    return str;

}

void exec_simple_r(char **tab, char c, linked_list_l *my_env)
{
    pid_t pid = fork();
    int fd;
    int b = 0;
    char *str = exec_simple_redi(tab, c);
    int dubcopy = dup(1);
    char *myline = creat_parse_line(str, tab);

    if (pid == -1) {
        my_putstr("Command failed");
        exit(EXIT_FAILURE);
        }
    if (pid == 0 && b == 0 && my_env != NULL) {
        fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        dup2(fd, 1);
        close(fd);
        my_command(myline, my_env);
        }
    wait(NULL);
    dup2(dubcopy, 1);
    return;
}

int checkmyredi(char *line)
{
    char **tab = str_to_array(line, ">");
    char **temp = NULL;

    if (tab[1][0] == 0) {
            my_putstr("Error in your redirection\n");
            return -1;
        }
    for (int i = 0; tab[i] != NULL; i++) {
        if (i == 0 && tab[i + 1] == NULL) {
            my_putstr("Error in your redirection\n");
            return -1;
        }
        if (tab[i +  1] == NULL)
            temp = str_to_array(tab[i], " \n\t");
    }
    if (temp[1] != NULL) {
        my_putstr("To many arg in your redirection\n");
        return -1;
    }
    return 0;
}

void separator_cmd(char *line, linked_list_l *my_env)
{
    char **tab = NULL;

    if (check_operators(line, ";") > 0) {
        tab = parse_operators(line, ";");
        exec_op(tab, my_env, ';');
    } else if (check_operators(line, ">") == 1 && checkmyredi(line) == -1)
        return;
    else if (check_operators(line, ">") == 1) {
        tab = str_to_array(line, " \t>");
        exec_simple_r(tab, '>', my_env);
    } else
        return;
}
