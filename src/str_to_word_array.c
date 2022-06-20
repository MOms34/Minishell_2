/*
** EPITECH PROJECT, 2021
** main_lib
** File description:
** main
*/

#include "minishell.h"

char *my_strcat_sec(char *dest, char const *src)
{
    int size_f = my_strlen(src) + my_strlen(dest);
    int dest_size = my_strlen(dest);
    int i;
    char *temp = malloc(sizeof(char) * (dest_size) + 1);

    my_strcpy(temp, dest);
    dest = malloc(sizeof(char) * (size_f + 2));
    for (i = 0; temp[i] != '\0'; i++)
        dest[i] = temp[i];
    for (int j = 0; src[j] != '\0'; i++, j++) {
        if (src[j] == ' ')
            break;
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return dest;
}

char *parse_line(char const *l)
{
    char *line = malloc(sizeof(char) * (my_strlen(l) + 1));
    int i = 0;

    while (l[i] != '\0') {
        if (l[i] == ' ')
            break;
        line[i] = l[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

int my_len_tab(char const *line, char c)
{
    int i = 0;
    int nb_space = 0;

    while (line[i] != '\0') {
        if (line[i] == c || line[i] == '\t')
            nb_space++;
        i++;
    }
    return (nb_space);
}

char **str_to_tab(linked_list_l *env)
{
    char **tab = malloc(sizeof(char *) * (env->nodes + 1));
    linked_list_l *cpy = env;
    int i = 0;

    while (cpy != NULL) {
        tab[i] = malloc(sizeof(char) * (my_strlen(cpy->env) + 1));
        tab[i] = cpy->env;
        cpy = cpy->next;
        i++;
    }
    return (tab);
}

char **str_to_word_tab(char const *line)
{
    int y = 0;
    int len_tab = my_len_tab(line, ' ') + 1;
    char **tab = malloc(sizeof(char *) * (len_tab + 1));

    tab[y] = malloc(sizeof(char) * my_strlen(line));
    for (int i = 0, x = 0; line[i] != '\0'; i++, x++) {
        if (line[i] == ' ' || line[i] == '\t') {
            tab[y][x] = '\0';
            x = 0;
            y++;
            tab[y] = malloc(sizeof(char) * my_strlen(line));
            i = without_space(line, i);
        }
        tab[y][x] = line[i];
    }
    if (tab[y][0] == '\0')
        tab[y] = NULL;
    return (tab);
}
