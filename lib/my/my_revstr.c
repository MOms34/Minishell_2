/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char stock[j];

    while (str[i] != '\0') {
        stock[i] = str[i];
        i = i + 1;
    }
    i = 0;

    while (j >= 0) {
        str[i] = stock[j];
        j = j - 1;
        i = i + 1;
    }
}
