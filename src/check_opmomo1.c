/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** main
*/

#include "minishell.h"

int limitp(char a, char *limit)
{
    int z = 0;

    while (z != my_strlen(limit)) {
        if (limit[z] == a)
            return (-1);
        z++;
    }
    return (0);
}

int check_operators(char *buffer, char *sep)
{
    int compt = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (limitp(buffer[i], sep) == -1) {
            compt++;
        }
    }
    return compt;
}

char **parse_operators(char *buffer, char *sep)
{
    char **tab = NULL;

    if (check_operators(buffer, sep) > 0)
        tab = str_to_array(buffer, sep);
    return tab;
}

char *creat_parse_line(char *str, char **cmd)
{
    char *buff = malloc(sizeof(char) * 128);

    for (int i = 0; i < 128; buff[i++] = 0);
    for (int i = 0; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], str) == 0)
            return buff;
        if (my_strcmp(cmd[i], str) != 0) {
            f_strcat(buff, cmd[i]);
            f_strcat(buff, " ");
        }
    }
    return buff;
}
