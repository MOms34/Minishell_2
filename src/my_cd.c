/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** my_cd
*/

#include "minishell.h"

char *after_path(const char *path)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * my_strlen(path));

    while (path[i] != ' ' && path[i] != '\0')
        i = i + 1;
    if (i >= my_strlen(path))
        return NULL;
    else {
        i++;
        while (path[i] != '\0') {
            temp[j] = path[i];
            j++;
            i++;
        }
        temp[j] = '\0';
        return (temp);
    }
}

char *parse_path(char *path)
{
    int i = 0;
    int j =0;
    char *cpy = malloc(sizeof(char) * my_strlen(path) - 4);

    while (path[i] != '/')
        i++;
    while (path[i] != '\0') {
        cpy[j] = path[i];
        i++;
        j++;
    }
    cpy[j] = '\0';
    return (cpy);
}

char *my_oldpwd(linked_list_l *menv)
{
    linked_list_l *node = menv;
    char *oldpwd = NULL;

    while (node != NULL) {
        if (my_strncmp(node->env, "OLDPWD", 6) == 0) {
            oldpwd = my_strcopy(node->env);
            change_old_pwd(&menv, getcwd(NULL, 0));
            return (parse_path(oldpwd));
        }
        node = node->next;
    }
    return (NULL);
}

char *home(char **env)
{
    int i = 0;

    while (my_strncmp(env[i], "HOME", 4) != 0)
        i++;
    return (parse_path(env[i]));
}

void my_cd(const char *path, char **env, linked_list_l *menv)
{
    char *new = NULL;

    if (my_strlen(path) >= 3){
        new = after_path(path);
    }
    else if (my_strlen(path) <= 1)
        return;
    if (my_strcmp(path, "cd") == 0)
        chdir(home(env));
    else if (my_strcmp(new, "-") == 0) {
        chdir(my_oldpwd(menv));
        return;
    } else if (new[0] == '/')
        chdir(new);
    else
        chdir(new);
}
