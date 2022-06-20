/*
** EPITECH PROJECT, 2021
** strstr
** File description:
** my
*/

#include <stddef.h>

void my_putchar(char c);
int my_strlen(char const *str);

char *find_str(char *str, char const *to_find, int i)
{
    int size = my_strlen(to_find);
    char stock[size];
    int cpt = 0;

    while (to_find[cpt] != '\0') {
        stock[cpt] = str[i];
        cpt = cpt + 1;
        i = i + 1;
        if (size == cpt)
            stock[cpt] = '\0';
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if (str[i] == 0)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == to_find[j] && str[i + 1] == to_find[j + 1])
            return (find_str(str, to_find, i));
        i = i + 1;
    }
}
